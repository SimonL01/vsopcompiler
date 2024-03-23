/* This code was inspired from
 * the parser.y provided by 
 * the teacher and the assistant
 * as an example of a calculator program
 */

%skeleton "lalr1.cc" // -*- C++ -*-
%language "c++"
%require "3.7.5"
%locations

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

//%define api.location.type {CustomSourceLocation}

// C++ code put inside header file
%code requires {
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
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
    //#include "driver.hpp"
    using namespace std;
    #include <memory>
    #include "SyntaxAnalyzer.hpp"
    #include "../LexicalAnalyzer/LexicalAnalyzer.hpp"
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
    //ERROR "error" 
;

%token <int> INTEGER_LITERAL "integer-literal" 

%define parse.error verbose


%nterm <Class<void>*> list_class class class_body class_body_repetition
%nterm <Field<void>*> field
%nterm <Method<void>*> method
%nterm <std::string> type class_optional
%nterm <std::vector<Formal<void>*>*> formals formals_repetition  
%nterm <Formal<void>*> formal
%nterm <std::vector<Expr<void>*>*> block block_repetition args args_repetition
%nterm <Expr<void>*> expr par conditional while let assign unop binop call new literal field_optional let_optional                    
%nterm <std::vector<Class<void>*>*> class_declaration_list                                         

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

program:    list_class class_declaration_list {$2->push_back($1); std::reverse($2->begin(), $2->end()); synAnalysis.program = new Program<void>($2);};
            //|error class_declaration_list {std::cout<<"Expected class definition"<<std::endl; driver.parseError = 1;};

class_declaration_list : /*empty*/ {$$ = new std::vector<Class<void>*>();}
                    | list_class class_declaration_list {$2->push_back($1); $$ = $2;};

list_class:     class {$$=$1;}; // $1->line = @1.begin.line; $1->column = @1.begin.column;

class: CLASS TYPE_IDENTIFIER class_optional class_body {std::reverse($4->getMethods()->begin(), $4->getMethods()->end()); std::reverse($4->getFields()->begin(), $4->getFields()->end()); $$ = new Class<void>($2, $4->getMethods(), $4->getFields(), $3);};// new std::vector<Class*>()
        | error {cerr << "Syntax error: Unexpected token or invalid class definition.\n";};

class_optional: /* empty */ {$$ = "";}
                | EXTENDS TYPE_IDENTIFIER {$$ = $2;};

class_body: LBRACE class_body_repetition RBRACE {$$ = $2;};

class_body_repetition: /* empty */ {std::vector<Method<void>*>* ptr_m = new std::vector<Method<void>*>(); std::vector<Field<void>*>* ptr_f = new std::vector<Field<void>*>(); $$ = new Class("", ptr_m, ptr_f, "");}
                        |field class_body_repetition {$2->AddField($1); $$ = $2;}
                        |method class_body_repetition {$2->AddMethod($1); $$ = $2;}

field: OBJECT_IDENTIFIER COLON type field_optional SEMICOLON   {$$ = new Field<void>($1,$3,$4);}  //Field(const std::string name, Type type, Expr* init_expr = nullptr)

field_optional: /* empty */ {$$ = nullptr;}
                |ASSIGN expr {$$ = $2;};

method: OBJECT_IDENTIFIER LPAR formals RPAR COLON type block {std::reverse($3->begin(), $3->end()); std::reverse($7->begin(), $7->end()); Block<void>* b = new Block<void>($7); $$ = new Method<void>($1, $3, $6, b);}; //std::reverse($3->begin(), $3->end()); std::reverse($7->getExpr_list()->begin(), $7->getExpr_list()->end());$$ = new Method($1, $3, $6, $7);

type: TYPE_IDENTIFIER | INT32 | BOOL | STRING | UNIT ;

formals: /* empty */ {$$ = new std::vector<Formal<void>*>();}
        |formal formals_repetition {$2->push_back($1); $$ = $2;};

formals_repetition : /* empty */ {$$ = new std::vector<Formal<void>*>();}
                    |COMMA formal formals_repetition {$3->push_back($2); $$ = $3;};

formal: OBJECT_IDENTIFIER COLON type {$$ = new Formal<void>($1, $3);}; 

block: LBRACE expr block_repetition RBRACE{$3->push_back($2); $$ = $3;};

block_repetition: /* empty */ {$$ = new std::vector<Expr<void>*>();}
                |SEMICOLON expr block_repetition {$3->push_back($2); $$=$3;}; 

expr: conditional
     | while 
     | let  
     | assign
     | unop
     | binop   
     | call
     | new
     | OBJECT_IDENTIFIER      { $$ = new ObjectIdentifier<void>($1);} // ObjectIdentifier(const std::string name)
     | SELF                { $$ = new Self<void>($1);}  //Self(const std::string self = "self")
     | literal 
     | par                 
     | LPAR expr RPAR      { $$ = $2; }
     | block               {std::reverse($1->begin(), $1->end()); $$ = new Block<void>($1);};

conditional: IF expr THEN expr  {$$ = new Conditional<void>($2, $4,nullptr);}   // Conditional(Expr* cond_expr, Expr* then_expr, Expr* else_expr = nullptr)
   |IF expr THEN expr ELSE expr { $$ = new Conditional<void>($2, $4,$6);};

while: WHILE expr DO expr {$$ = new While<void>($2, $4);};

let: LET OBJECT_IDENTIFIER COLON type let_optional IN expr {$$ = new Let<void>($2, $4, $7, $5); }; //Let(const std::string name, Type type, Expr* scope_expr, Expr* init_expr = nullptr)

let_optional: /* empty */       { $$ = nullptr; }
            | ASSIGN expr       { $$ = $2;};                //Assign(const std::string name, Expr* expr) 

assign: OBJECT_IDENTIFIER ASSIGN expr {$$= new Assign<void>($1, $3);} ; //Assign(const std::string name, Expr* expr)

unop: NOT expr  {$$= new UnOp<void>($1,$2);} //UnOp(const std::string op, Expr* expr)
     |MINUS expr  {$$= new UnOp<void>($1,$2);}
     |ISNULL expr {$$= new UnOp<void>($1,$2);};

binop:  expr EQUAL expr      {$$= new BinOp<void>($2,$1,$3);}      //BinOp(const std::string op, Expr* left_expr, Expr* right_expr)
      | expr LOWER expr      {$$= new BinOp<void>($2,$1,$3);}
      | expr LOWER_EQUAL expr     {$$= new BinOp<void>($2,$1,$3);}
      | expr PLUS expr       {$$= new BinOp<void>($2,$1,$3);}
      | expr MINUS expr      {$$= new BinOp<void>($2,$1,$3);}
      | expr TIMES expr      {$$= new BinOp<void>($2,$1,$3);}
      | expr DIVIDE expr     {$$= new BinOp<void>($2,$1,$3);}
      | expr POWER expr      {$$= new BinOp<void>($2,$1,$3);}
      | expr AND expr        {$$= new BinOp<void>($2,$1,$3);};

call:  OBJECT_IDENTIFIER LPAR args RPAR      {$$ = new Call<void>($1, $3, nullptr);}           // Call(const std::string method_name, std::vector<Expr*> expr_list,Expr* obj_expr = nullptr)
     | expr DOT OBJECT_IDENTIFIER LPAR args RPAR {$$ =  new Call<void>($3, $5, $1);};

args: /* empty */ {$$ = new std::vector<Expr<void>*>;}
    | expr args_repetition {$2->push_back($1); std::reverse($2->begin(), $2->end()); $$ = $2;};

args_repetition: /* empty */ {$$ = new std::vector<Expr<void>*>;}
                |COMMA expr args_repetition {$3->push_back($2); $$ = $3;};

new: NEW TYPE_IDENTIFIER    {$$= new New<void>($2);};      //New(const std::string type_name)s

literal: INTEGER_LITERAL           { $$ = new IntegerLiteral<void>($1);}      //IntegerLiteral(int value)
        |STRING_LITERAL        { $$ = new StringLiteral<void>($1);}              //StringLiteral(const std::string STRING_LITERAL)
        |TRUE             { $$ = new BooleanLiteral<void>($1);}        //BooleanLiteral(bool val)
        |FALSE            { $$ = new BooleanLiteral<void>($1);};   

par : LPAR RPAR {$$ = new Par<void>();};

%%
// User code
void Compilers::Parsers::Parser::error(const location_type& l, const std::string& m)
{
    const position &pos = l.begin;

    cerr << *(pos.filename) << ":"
         << pos.line << ":" 
         << pos.column << ": "
         << m
         << endl;
}