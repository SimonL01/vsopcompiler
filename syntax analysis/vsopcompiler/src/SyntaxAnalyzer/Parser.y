%skeleton "lalr1.cc" // -*- C++ -*-
%language "c++"
%require "3.7.5"

%defines

// Put parser inside a namespace
%define api.namespace {Compilers::Parsers}

// Give the name of the parser class
%define api.parser.class {Parser}

// Force the token kind enum (used by the lexer) and the symbol kind enum
// (used by the parser) to use the same value for the tokens.
// (e.g. '+' will be represented by the same integer value in both enums.)
%define api.token.raw

// Tokens contain their type, value and location
// Also allow to use the make_TOKEN functions
%define api.token.constructor

// Allow to use C++ objects as semantic values
%define api.value.type variant

// Add some assertions.
%define parse.assert

%locations

// C++ code put inside header file
%code requires {
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include "AST.hpp"

    namespace Compilers::Parsers
    {
        class SyntaxAnalyzer;
    }
}

// Add an argument to the parser constructor
%parse-param {Compilers::Parsers::SyntaxAnalyzer &synAnalysis}
%lex-param {Compilers::Parsers::SyntaxAnalyzer &synAnalysis}

%code {
    #include <memory>
    #include "SyntaxAnalyzer.hpp"
    #include "../LexicalAnalyzer/LexicalAnalyzer.hpp"

    using std::cerr;
    using std::endl;
}

// Token and symbols definitions
%token<std::string>
    AND         "and"
    BOOL        "bool"
    CLASS       "class"
    DO          "do"
    ELSE        "else"
    EXTENDS     "extends"
    FALSE       "false"
    IF          "if"
    IN          "in"
    INT32       "int32"
    ISNULL      "isnull"
    LET         "let"
    NEW         "new"
    NOT         "not"
    SELF        "self"
    STRING      "string"
    THEN        "then"
    TRUE        "true"
    UNIT        "unit"
    WHILE       "while"
    TYPE_IDENTIFIER "type-identifier"
    OBJECT_IDENTIFIER "object-identifier"
    STRING_LITERAL "string-literal"
    LBRACE      "{"
    RBRACE      "}"
    LPAR        "("
    RPAR        ")"
    COLON       ":"
    SEMICOLON   ";"
    COMMA       ","
    PLUS        "+"
    MINUS       "-"
    TIMES       "*"
    DIVIDE      "/"
    POWER       "^"
    DOT         "."
    EQUAL       "="
    LOWER       "<"
    LOWER_EQUAL "<="
    ASSIGN      "<-"
;

%token <int> INTEGER_LITERAL "integer-literal" 

%nterm <Class<void>*> class_declaration class_body
%nterm <Field<void>*> field
%nterm <Method<void>*> method
%nterm <std::string> type class_inheritance
%nterm <std::vector<Formal<void>*>*> formals
%nterm <Formal<void>*> formal
%nterm <std::vector<Expr<void>*>*> block block_body args args_repetition
%nterm <Expr<void>*> expr par conditional while_loop let assign unop binop call new literal field_assignment let_optional                    
%nterm <std::vector<Class<void>*>*> several_classes                                         

%precedence IF THEN WHILE DO LET IN
%precedence ELSE 

// Precedence
%right "<-"
%left "and"
%right "not"
%nonassoc "<" "<=" "="
%left "+" "-"
%left "*" "/"
%right "unary-" "isnull"
%right "^"
%left "."

%%
// Grammar rules
%start program;

program:    several_classes {std::reverse($1->begin(), $1->end()); synAnalysis.program = new Program<void>($1);};

several_classes : /*empty*/ {$$ = new std::vector<Class<void>*>();}
                | class_declaration several_classes {$2->push_back($1); $$ = $2;};

class_declaration: CLASS TYPE_IDENTIFIER class_inheritance LBRACE class_body RBRACE {std::reverse($5->getMethods()->begin(), $5->getMethods()->end()); std::reverse($5->getFields()->begin(), $5->getFields()->end()); $$ = new Class<void>($2, $3, $5->getFields(), $5->getMethods());};

class_inheritance: /* empty */ {}
                | EXTENDS TYPE_IDENTIFIER {$$ = $2;};

class_body: /* empty */ {std::vector<Method<void>*>* methods = new std::vector<Method<void>*>(); std::vector<Field<void>*>* fields = new std::vector<Field<void>*>(); $$ = new Class("", "", fields, methods);}
            |field class_body {$2->AddField($1); $$ = $2;}
            |method class_body {$2->AddMethod($1); $$ = $2;}

field: OBJECT_IDENTIFIER COLON type field_assignment SEMICOLON   {$$ = new Field<void>($1,$3,$4);}

field_assignment: /* empty */ {$$ = nullptr;}
                |ASSIGN expr {$$ = $2;};

method: OBJECT_IDENTIFIER LPAR formals RPAR COLON type block {std::reverse($7->begin(), $7->end()); Block<void>* block = new Block<void>($7); $$ = new Method<void>($1, $3, $6, block);};
        | OBJECT_IDENTIFIER LPAR formals RPAR COLON type {error(@1, "method without implementation"); return 1;}
        | OBJECT_IDENTIFIER LPAR formals COLON type block {error(@2, "unclosed argument list of a method"); return 1;}

type: TYPE_IDENTIFIER | INT32 | BOOL | STRING | UNIT | {error(@0, "unvalid type"); return 1;};

formals: /* empty */ {$$ = new std::vector<Formal<void>*>();}
       | formal { $$ = new std::vector<Formal<void>*>(); $$->push_back($1); }
       | formals COMMA formal { $$ = $1; $1->push_back($3); };

formal: OBJECT_IDENTIFIER COLON type {$$ = new Formal<void>($1, $3);}; 
        //| OBJECT_IDENTIFIER type {error(@1, "missing colon on formal definition"); return 1;};

block: LBRACE expr block_body RBRACE{$3->push_back($2); $$ = $3;};
        //| LBRACE expr block_body {error(@1, "unclose block"); return 1;};


block_body: /* empty */ {$$ = new std::vector<Expr<void>*>();}
            |SEMICOLON expr block_body {$3->push_back($2); $$=$3;};
            //|expr block_body {error(@0, "missing semi-colon"); return 1;};

unop: NOT expr      {$$= new UnOp<void>($1,$2);}
     |MINUS expr    {$$= new UnOp<void>($1,$2);}
     |ISNULL expr   {$$= new UnOp<void>($1,$2);};

binop:  expr EQUAL expr         {$$= new BinOp<void>($2,$1,$3);}
      | expr LOWER expr         {$$= new BinOp<void>($2,$1,$3);}
      | expr LOWER_EQUAL expr   {$$= new BinOp<void>($2,$1,$3);}
      | expr PLUS expr          {$$= new BinOp<void>($2,$1,$3);}
      | expr MINUS expr         {$$= new BinOp<void>($2,$1,$3);}
      | expr TIMES expr         {$$= new BinOp<void>($2,$1,$3);}
      | expr DIVIDE expr        {$$= new BinOp<void>($2,$1,$3);}
      | expr POWER expr         {$$= new BinOp<void>($2,$1,$3);}
      | expr AND expr           {$$= new BinOp<void>($2,$1,$3);};

expr: conditional
    | while_loop
    | let
    | assign
    | unop
    | binop
    | call
    | new
    | OBJECT_IDENTIFIER   { $$ = new ObjectIdentifier<void>($1);}
    | SELF                { $$ = new Self<void>($1);}
    | literal 
    | par                 
    | LPAR expr RPAR      { $$ = $2; }
    | block               {std::reverse($1->begin(), $1->end()); $$ = new Block<void>($1);};

conditional: IF expr THEN expr  {$$ = new Conditional<void>($2, $4,nullptr);}
            |IF expr THEN expr ELSE expr { $$ = new Conditional<void>($2, $4,$6);};

while_loop: WHILE expr DO expr {$$ = new WhileLoop<void>($2, $4);};

let: LET OBJECT_IDENTIFIER COLON type let_optional IN expr {$$ = new Let<void>($2, $4, $7, $5); };

let_optional: /* empty */   { $$ = nullptr; }
            | ASSIGN expr   { $$ = $2;};

assign: OBJECT_IDENTIFIER ASSIGN expr {$$= new Assign<void>($1, $3);};

call:  OBJECT_IDENTIFIER LPAR args RPAR             {$$ = new Call<void>($1, $3, nullptr);}
     | expr DOT OBJECT_IDENTIFIER LPAR args RPAR    {$$ =  new Call<void>($3, $5, $1);};

args: /* empty */ {$$ = new std::vector<Expr<void>*>;}
    | expr args_repetition {$2->push_back($1); std::reverse($2->begin(), $2->end()); $$ = $2;};

args_repetition: /* empty */ {$$ = new std::vector<Expr<void>*>;}
                |COMMA expr args_repetition {$3->push_back($2); $$ = $3;};

new: NEW TYPE_IDENTIFIER    {$$= new New<void>($2);};

literal: INTEGER_LITERAL    { $$ = new IntegerLiteral<void>($1);}
        |STRING_LITERAL     { $$ = new StringLiteral<void>($1);}
        |TRUE               { $$ = new BooleanLiteral<void>($1);}
        |FALSE              { $$ = new BooleanLiteral<void>($1);};

par : LPAR RPAR {$$ = new Par<void>();};

%%

/* return 1 because of a parsing error */
void Compilers::Parsers::Parser::error(const location_type& location, const std::string& message)
{
    cerr << FILE_NAME << ":" << location.begin.line << ":" << location.begin.column << ": syntax error: " << message << endl;
}