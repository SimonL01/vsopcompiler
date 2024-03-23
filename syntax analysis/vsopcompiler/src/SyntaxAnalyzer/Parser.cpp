// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hpp"


// Unqualified %code blocks.
#line 51 "src/SyntaxAnalyzer/Parser.y"

    //#include "driver.hpp"
    using namespace std;
    #include <memory>
    #include "SyntaxAnalyzer.hpp"
    #include "../LexicalAnalyzer/LexicalAnalyzer.hpp"

#line 54 "src/SyntaxAnalyzer/Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 11 "src/SyntaxAnalyzer/Parser.y"
namespace Compilers { namespace Parsers {
#line 147 "src/SyntaxAnalyzer/Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Compilers::Parsers::SyntaxAnalyzer &synAnalysis_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      synAnalysis (synAnalysis_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.YY_MOVE_OR_COPY< Class<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_optional: // field_optional
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_while: // while
      case symbol_kind::S_let: // let
      case symbol_kind::S_let_optional: // let_optional
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_unop: // unop
      case symbol_kind::S_binop: // binop
      case symbol_kind::S_call: // call
      case symbol_kind::S_new: // new
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_par: // par
        value.YY_MOVE_OR_COPY< Expr<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< Field<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal: // formal
        value.YY_MOVE_OR_COPY< Formal<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.YY_MOVE_OR_COPY< Method<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AND: // "and"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_EXTENDS: // "extends"
      case symbol_kind::S_FALSE: // "false"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_INT32: // "int32"
      case symbol_kind::S_ISNULL: // "isnull"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_NEW: // "new"
      case symbol_kind::S_NOT: // "not"
      case symbol_kind::S_SELF: // "self"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_TRUE: // "true"
      case symbol_kind::S_UNIT: // "unit"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_TYPE_IDENTIFIER: // "type-identifier"
      case symbol_kind::S_OBJECT_IDENTIFIER: // "object-identifier"
      case symbol_kind::S_STRING_LITERAL: // "string-literal"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_LPAR: // "("
      case symbol_kind::S_RPAR: // ")"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_TIMES: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_POWER: // "^"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_LOWER: // "<"
      case symbol_kind::S_LOWER_EQUAL: // "<="
      case symbol_kind::S_ASSIGN: // "<-"
      case symbol_kind::S_class_optional: // class_optional
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.YY_MOVE_OR_COPY< std::vector<Class<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.YY_MOVE_OR_COPY< std::vector<Expr<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.YY_MOVE_OR_COPY< std::vector<Formal<void>*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.move< Class<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_optional: // field_optional
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_while: // while
      case symbol_kind::S_let: // let
      case symbol_kind::S_let_optional: // let_optional
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_unop: // unop
      case symbol_kind::S_binop: // binop
      case symbol_kind::S_call: // call
      case symbol_kind::S_new: // new
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_par: // par
        value.move< Expr<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< Field<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal: // formal
        value.move< Formal<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.move< Method<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AND: // "and"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_EXTENDS: // "extends"
      case symbol_kind::S_FALSE: // "false"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_INT32: // "int32"
      case symbol_kind::S_ISNULL: // "isnull"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_NEW: // "new"
      case symbol_kind::S_NOT: // "not"
      case symbol_kind::S_SELF: // "self"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_TRUE: // "true"
      case symbol_kind::S_UNIT: // "unit"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_TYPE_IDENTIFIER: // "type-identifier"
      case symbol_kind::S_OBJECT_IDENTIFIER: // "object-identifier"
      case symbol_kind::S_STRING_LITERAL: // "string-literal"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_LPAR: // "("
      case symbol_kind::S_RPAR: // ")"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_TIMES: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_POWER: // "^"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_LOWER: // "<"
      case symbol_kind::S_LOWER_EQUAL: // "<="
      case symbol_kind::S_ASSIGN: // "<-"
      case symbol_kind::S_class_optional: // class_optional
      case symbol_kind::S_type: // type
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.move< std::vector<Class<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.move< std::vector<Expr<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.move< std::vector<Formal<void>*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.copy< Class<void>* > (that.value);
        break;

      case symbol_kind::S_field_optional: // field_optional
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_while: // while
      case symbol_kind::S_let: // let
      case symbol_kind::S_let_optional: // let_optional
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_unop: // unop
      case symbol_kind::S_binop: // binop
      case symbol_kind::S_call: // call
      case symbol_kind::S_new: // new
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_par: // par
        value.copy< Expr<void>* > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< Field<void>* > (that.value);
        break;

      case symbol_kind::S_formal: // formal
        value.copy< Formal<void>* > (that.value);
        break;

      case symbol_kind::S_method: // method
        value.copy< Method<void>* > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_AND: // "and"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_EXTENDS: // "extends"
      case symbol_kind::S_FALSE: // "false"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_INT32: // "int32"
      case symbol_kind::S_ISNULL: // "isnull"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_NEW: // "new"
      case symbol_kind::S_NOT: // "not"
      case symbol_kind::S_SELF: // "self"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_TRUE: // "true"
      case symbol_kind::S_UNIT: // "unit"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_TYPE_IDENTIFIER: // "type-identifier"
      case symbol_kind::S_OBJECT_IDENTIFIER: // "object-identifier"
      case symbol_kind::S_STRING_LITERAL: // "string-literal"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_LPAR: // "("
      case symbol_kind::S_RPAR: // ")"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_TIMES: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_POWER: // "^"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_LOWER: // "<"
      case symbol_kind::S_LOWER_EQUAL: // "<="
      case symbol_kind::S_ASSIGN: // "<-"
      case symbol_kind::S_class_optional: // class_optional
      case symbol_kind::S_type: // type
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.copy< std::vector<Class<void>*>* > (that.value);
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.copy< std::vector<Expr<void>*>* > (that.value);
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.copy< std::vector<Formal<void>*>* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.move< Class<void>* > (that.value);
        break;

      case symbol_kind::S_field_optional: // field_optional
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_while: // while
      case symbol_kind::S_let: // let
      case symbol_kind::S_let_optional: // let_optional
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_unop: // unop
      case symbol_kind::S_binop: // binop
      case symbol_kind::S_call: // call
      case symbol_kind::S_new: // new
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_par: // par
        value.move< Expr<void>* > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< Field<void>* > (that.value);
        break;

      case symbol_kind::S_formal: // formal
        value.move< Formal<void>* > (that.value);
        break;

      case symbol_kind::S_method: // method
        value.move< Method<void>* > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_AND: // "and"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_EXTENDS: // "extends"
      case symbol_kind::S_FALSE: // "false"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_INT32: // "int32"
      case symbol_kind::S_ISNULL: // "isnull"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_NEW: // "new"
      case symbol_kind::S_NOT: // "not"
      case symbol_kind::S_SELF: // "self"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_TRUE: // "true"
      case symbol_kind::S_UNIT: // "unit"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_TYPE_IDENTIFIER: // "type-identifier"
      case symbol_kind::S_OBJECT_IDENTIFIER: // "object-identifier"
      case symbol_kind::S_STRING_LITERAL: // "string-literal"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_LPAR: // "("
      case symbol_kind::S_RPAR: // ")"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_TIMES: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_POWER: // "^"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_LOWER: // "<"
      case symbol_kind::S_LOWER_EQUAL: // "<="
      case symbol_kind::S_ASSIGN: // "<-"
      case symbol_kind::S_class_optional: // class_optional
      case symbol_kind::S_type: // type
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.move< std::vector<Class<void>*>* > (that.value);
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.move< std::vector<Expr<void>*>* > (that.value);
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.move< std::vector<Formal<void>*>* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (synAnalysis));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        yylhs.value.emplace< Class<void>* > ();
        break;

      case symbol_kind::S_field_optional: // field_optional
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_while: // while
      case symbol_kind::S_let: // let
      case symbol_kind::S_let_optional: // let_optional
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_unop: // unop
      case symbol_kind::S_binop: // binop
      case symbol_kind::S_call: // call
      case symbol_kind::S_new: // new
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_par: // par
        yylhs.value.emplace< Expr<void>* > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< Field<void>* > ();
        break;

      case symbol_kind::S_formal: // formal
        yylhs.value.emplace< Formal<void>* > ();
        break;

      case symbol_kind::S_method: // method
        yylhs.value.emplace< Method<void>* > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_AND: // "and"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_EXTENDS: // "extends"
      case symbol_kind::S_FALSE: // "false"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_INT32: // "int32"
      case symbol_kind::S_ISNULL: // "isnull"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_NEW: // "new"
      case symbol_kind::S_NOT: // "not"
      case symbol_kind::S_SELF: // "self"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_TRUE: // "true"
      case symbol_kind::S_UNIT: // "unit"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_TYPE_IDENTIFIER: // "type-identifier"
      case symbol_kind::S_OBJECT_IDENTIFIER: // "object-identifier"
      case symbol_kind::S_STRING_LITERAL: // "string-literal"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_LPAR: // "("
      case symbol_kind::S_RPAR: // ")"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_TIMES: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_POWER: // "^"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_LOWER: // "<"
      case symbol_kind::S_LOWER_EQUAL: // "<="
      case symbol_kind::S_ASSIGN: // "<-"
      case symbol_kind::S_class_optional: // class_optional
      case symbol_kind::S_type: // type
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        yylhs.value.emplace< std::vector<Class<void>*>* > ();
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        yylhs.value.emplace< std::vector<Expr<void>*>* > ();
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        yylhs.value.emplace< std::vector<Formal<void>*>* > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: list_class class_declaration_list
#line 137 "src/SyntaxAnalyzer/Parser.y"
                                              {yystack_[0].value.as < std::vector<Class<void>*>* > ()->push_back(yystack_[1].value.as < Class<void>* > ()); std::reverse(yystack_[0].value.as < std::vector<Class<void>*>* > ()->begin(), yystack_[0].value.as < std::vector<Class<void>*>* > ()->end()); synAnalysis.program = new Program<void>(yystack_[0].value.as < std::vector<Class<void>*>* > ());}
#line 1041 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 3: // program: error
#line 138 "src/SyntaxAnalyzer/Parser.y"
                    {cerr << "Syntax error: Unexpected token or invalid class definition.\n";}
#line 1047 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 4: // class_declaration_list: %empty
#line 141 "src/SyntaxAnalyzer/Parser.y"
                                   {yylhs.value.as < std::vector<Class<void>*>* > () = new std::vector<Class<void>*>();}
#line 1053 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 5: // class_declaration_list: list_class class_declaration_list
#line 142 "src/SyntaxAnalyzer/Parser.y"
                                                        {yystack_[0].value.as < std::vector<Class<void>*>* > ()->push_back(yystack_[1].value.as < Class<void>* > ()); yylhs.value.as < std::vector<Class<void>*>* > () = yystack_[0].value.as < std::vector<Class<void>*>* > ();}
#line 1059 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 6: // list_class: class
#line 144 "src/SyntaxAnalyzer/Parser.y"
                      {yylhs.value.as < Class<void>* > ()=yystack_[0].value.as < Class<void>* > ();}
#line 1065 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 7: // class: "class" "type-identifier" class_optional class_body
#line 146 "src/SyntaxAnalyzer/Parser.y"
                                                       {std::reverse(yystack_[0].value.as < Class<void>* > ()->getMethods()->begin(), yystack_[0].value.as < Class<void>* > ()->getMethods()->end()); std::reverse(yystack_[0].value.as < Class<void>* > ()->getFields()->begin(), yystack_[0].value.as < Class<void>* > ()->getFields()->end()); yylhs.value.as < Class<void>* > () = new Class<void>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Class<void>* > ()->getMethods(), yystack_[0].value.as < Class<void>* > ()->getFields(), yystack_[1].value.as < std::string > ());}
#line 1071 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 8: // class: error
#line 147 "src/SyntaxAnalyzer/Parser.y"
                {cerr << "Syntax error: Unexpected token or invalid class definition.\n";}
#line 1077 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 9: // class_optional: %empty
#line 149 "src/SyntaxAnalyzer/Parser.y"
                            {yylhs.value.as < std::string > () = "";}
#line 1083 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 10: // class_optional: "extends" "type-identifier"
#line 150 "src/SyntaxAnalyzer/Parser.y"
                                          {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1089 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 11: // class_body: "{" class_body_repetition "}"
#line 152 "src/SyntaxAnalyzer/Parser.y"
                                                {yylhs.value.as < Class<void>* > () = yystack_[1].value.as < Class<void>* > ();}
#line 1095 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 12: // class_body_repetition: %empty
#line 154 "src/SyntaxAnalyzer/Parser.y"
                                   {std::vector<Method<void>*>* ptr_m = new std::vector<Method<void>*>(); std::vector<Field<void>*>* ptr_f = new std::vector<Field<void>*>(); yylhs.value.as < Class<void>* > () = new Class("", ptr_m, ptr_f, "");}
#line 1101 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 13: // class_body_repetition: field class_body_repetition
#line 155 "src/SyntaxAnalyzer/Parser.y"
                                                     {yystack_[0].value.as < Class<void>* > ()->AddField(yystack_[1].value.as < Field<void>* > ()); yylhs.value.as < Class<void>* > () = yystack_[0].value.as < Class<void>* > ();}
#line 1107 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 14: // class_body_repetition: method class_body_repetition
#line 156 "src/SyntaxAnalyzer/Parser.y"
                                                      {yystack_[0].value.as < Class<void>* > ()->AddMethod(yystack_[1].value.as < Method<void>* > ()); yylhs.value.as < Class<void>* > () = yystack_[0].value.as < Class<void>* > ();}
#line 1113 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 15: // field: "object-identifier" ":" type field_optional ";"
#line 158 "src/SyntaxAnalyzer/Parser.y"
                                                               {yylhs.value.as < Field<void>* > () = new Field<void>(yystack_[4].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[1].value.as < Expr<void>* > ());}
#line 1119 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 16: // field_optional: %empty
#line 160 "src/SyntaxAnalyzer/Parser.y"
                            {yylhs.value.as < Expr<void>* > () = nullptr;}
#line 1125 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 17: // field_optional: "<-" expr
#line 161 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > ();}
#line 1131 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 18: // method: "object-identifier" "(" formals ")" ":" type block
#line 163 "src/SyntaxAnalyzer/Parser.y"
                                                             {std::reverse(yystack_[4].value.as < std::vector<Formal<void>*>* > ()->begin(), yystack_[4].value.as < std::vector<Formal<void>*>* > ()->end()); std::reverse(yystack_[0].value.as < std::vector<Expr<void>*>* > ()->begin(), yystack_[0].value.as < std::vector<Expr<void>*>* > ()->end()); Block<void>* b = new Block<void>(yystack_[0].value.as < std::vector<Expr<void>*>* > ()); yylhs.value.as < Method<void>* > () = new Method<void>(yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<Formal<void>*>* > (), yystack_[1].value.as < std::string > (), b);}
#line 1137 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 19: // type: "type-identifier"
#line 165 "src/SyntaxAnalyzer/Parser.y"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1143 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 20: // type: "int32"
#line 165 "src/SyntaxAnalyzer/Parser.y"
                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1149 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 21: // type: "bool"
#line 165 "src/SyntaxAnalyzer/Parser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1155 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 22: // type: "string"
#line 165 "src/SyntaxAnalyzer/Parser.y"
                                       { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1161 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 23: // type: "unit"
#line 165 "src/SyntaxAnalyzer/Parser.y"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1167 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 24: // formals: %empty
#line 167 "src/SyntaxAnalyzer/Parser.y"
                     {yylhs.value.as < std::vector<Formal<void>*>* > () = new std::vector<Formal<void>*>();}
#line 1173 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 25: // formals: formal formals_repetition
#line 168 "src/SyntaxAnalyzer/Parser.y"
                                   {yystack_[0].value.as < std::vector<Formal<void>*>* > ()->push_back(yystack_[1].value.as < Formal<void>* > ()); yylhs.value.as < std::vector<Formal<void>*>* > () = yystack_[0].value.as < std::vector<Formal<void>*>* > ();}
#line 1179 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 26: // formals_repetition: %empty
#line 170 "src/SyntaxAnalyzer/Parser.y"
                                 {yylhs.value.as < std::vector<Formal<void>*>* > () = new std::vector<Formal<void>*>();}
#line 1185 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 27: // formals_repetition: "," formal formals_repetition
#line 171 "src/SyntaxAnalyzer/Parser.y"
                                                     {yystack_[0].value.as < std::vector<Formal<void>*>* > ()->push_back(yystack_[1].value.as < Formal<void>* > ()); yylhs.value.as < std::vector<Formal<void>*>* > () = yystack_[0].value.as < std::vector<Formal<void>*>* > ();}
#line 1191 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 28: // formal: "object-identifier" ":" type
#line 173 "src/SyntaxAnalyzer/Parser.y"
                                     {yylhs.value.as < Formal<void>* > () = new Formal<void>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());}
#line 1197 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 29: // block: "{" expr block_repetition "}"
#line 175 "src/SyntaxAnalyzer/Parser.y"
                                          {yystack_[1].value.as < std::vector<Expr<void>*>* > ()->push_back(yystack_[2].value.as < Expr<void>* > ()); yylhs.value.as < std::vector<Expr<void>*>* > () = yystack_[1].value.as < std::vector<Expr<void>*>* > ();}
#line 1203 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 30: // block_repetition: %empty
#line 177 "src/SyntaxAnalyzer/Parser.y"
                              {yylhs.value.as < std::vector<Expr<void>*>* > () = new std::vector<Expr<void>*>();}
#line 1209 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 31: // block_repetition: ";" expr block_repetition
#line 178 "src/SyntaxAnalyzer/Parser.y"
                                                 {yystack_[0].value.as < std::vector<Expr<void>*>* > ()->push_back(yystack_[1].value.as < Expr<void>* > ()); yylhs.value.as < std::vector<Expr<void>*>* > ()=yystack_[0].value.as < std::vector<Expr<void>*>* > ();}
#line 1215 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 32: // expr: conditional
#line 180 "src/SyntaxAnalyzer/Parser.y"
      { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1221 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 33: // expr: while
#line 181 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1227 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 34: // expr: let
#line 182 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1233 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 35: // expr: assign
#line 183 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1239 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 36: // expr: unop
#line 184 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1245 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 37: // expr: binop
#line 185 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1251 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 38: // expr: call
#line 186 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1257 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 39: // expr: new
#line 187 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1263 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 40: // expr: "object-identifier"
#line 188 "src/SyntaxAnalyzer/Parser.y"
                              { yylhs.value.as < Expr<void>* > () = new ObjectIdentifier<void>(yystack_[0].value.as < std::string > ());}
#line 1269 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 41: // expr: "self"
#line 189 "src/SyntaxAnalyzer/Parser.y"
                           { yylhs.value.as < Expr<void>* > () = new Self<void>(yystack_[0].value.as < std::string > ());}
#line 1275 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 42: // expr: literal
#line 190 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1281 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 43: // expr: par
#line 191 "src/SyntaxAnalyzer/Parser.y"
       { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > (); }
#line 1287 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 44: // expr: "(" expr ")"
#line 192 "src/SyntaxAnalyzer/Parser.y"
                           { yylhs.value.as < Expr<void>* > () = yystack_[1].value.as < Expr<void>* > (); }
#line 1293 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 45: // expr: block
#line 193 "src/SyntaxAnalyzer/Parser.y"
                           {std::reverse(yystack_[0].value.as < std::vector<Expr<void>*>* > ()->begin(), yystack_[0].value.as < std::vector<Expr<void>*>* > ()->end()); yylhs.value.as < Expr<void>* > () = new Block<void>(yystack_[0].value.as < std::vector<Expr<void>*>* > ());}
#line 1299 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 46: // conditional: "if" expr "then" expr
#line 195 "src/SyntaxAnalyzer/Parser.y"
                                {yylhs.value.as < Expr<void>* > () = new Conditional<void>(yystack_[2].value.as < Expr<void>* > (), yystack_[0].value.as < Expr<void>* > (),nullptr);}
#line 1305 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 47: // conditional: "if" expr "then" expr "else" expr
#line 196 "src/SyntaxAnalyzer/Parser.y"
                                { yylhs.value.as < Expr<void>* > () = new Conditional<void>(yystack_[4].value.as < Expr<void>* > (), yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1311 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 48: // while: "while" expr "do" expr
#line 198 "src/SyntaxAnalyzer/Parser.y"
                          {yylhs.value.as < Expr<void>* > () = new While<void>(yystack_[2].value.as < Expr<void>* > (), yystack_[0].value.as < Expr<void>* > ());}
#line 1317 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 49: // let: "let" "object-identifier" ":" type let_optional "in" expr
#line 200 "src/SyntaxAnalyzer/Parser.y"
                                                           {yylhs.value.as < Expr<void>* > () = new Let<void>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[0].value.as < Expr<void>* > (), yystack_[2].value.as < Expr<void>* > ()); }
#line 1323 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 50: // let_optional: %empty
#line 202 "src/SyntaxAnalyzer/Parser.y"
                                { yylhs.value.as < Expr<void>* > () = nullptr; }
#line 1329 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 51: // let_optional: "<-" expr
#line 203 "src/SyntaxAnalyzer/Parser.y"
                                { yylhs.value.as < Expr<void>* > () = yystack_[0].value.as < Expr<void>* > ();}
#line 1335 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 52: // assign: "object-identifier" "<-" expr
#line 205 "src/SyntaxAnalyzer/Parser.y"
                                      {yylhs.value.as < Expr<void>* > ()= new Assign<void>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Expr<void>* > ());}
#line 1341 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 53: // unop: "not" expr
#line 207 "src/SyntaxAnalyzer/Parser.y"
                {yylhs.value.as < Expr<void>* > ()= new UnOp<void>(yystack_[1].value.as < std::string > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1347 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 54: // unop: "-" expr
#line 208 "src/SyntaxAnalyzer/Parser.y"
                  {yylhs.value.as < Expr<void>* > ()= new UnOp<void>(yystack_[1].value.as < std::string > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1353 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 55: // unop: "isnull" expr
#line 209 "src/SyntaxAnalyzer/Parser.y"
                  {yylhs.value.as < Expr<void>* > ()= new UnOp<void>(yystack_[1].value.as < std::string > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1359 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 56: // binop: expr "=" expr
#line 211 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1365 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 57: // binop: expr "<" expr
#line 212 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1371 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 58: // binop: expr "<=" expr
#line 213 "src/SyntaxAnalyzer/Parser.y"
                                  {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1377 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 59: // binop: expr "+" expr
#line 214 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1383 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 60: // binop: expr "-" expr
#line 215 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1389 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 61: // binop: expr "*" expr
#line 216 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1395 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 62: // binop: expr "/" expr
#line 217 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1401 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 63: // binop: expr "^" expr
#line 218 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1407 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 64: // binop: expr "and" expr
#line 219 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < Expr<void>* > ()= new BinOp<void>(yystack_[1].value.as < std::string > (),yystack_[2].value.as < Expr<void>* > (),yystack_[0].value.as < Expr<void>* > ());}
#line 1413 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 65: // call: "object-identifier" "(" args ")"
#line 221 "src/SyntaxAnalyzer/Parser.y"
                                             {yylhs.value.as < Expr<void>* > () = new Call<void>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Expr<void>*>* > (), nullptr);}
#line 1419 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 66: // call: expr "." "object-identifier" "(" args ")"
#line 222 "src/SyntaxAnalyzer/Parser.y"
                                                 {yylhs.value.as < Expr<void>* > () =  new Call<void>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Expr<void>*>* > (), yystack_[5].value.as < Expr<void>* > ());}
#line 1425 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 67: // args: %empty
#line 224 "src/SyntaxAnalyzer/Parser.y"
                  {yylhs.value.as < std::vector<Expr<void>*>* > () = new std::vector<Expr<void>*>;}
#line 1431 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 68: // args: expr args_repetition
#line 225 "src/SyntaxAnalyzer/Parser.y"
                           {yystack_[0].value.as < std::vector<Expr<void>*>* > ()->push_back(yystack_[1].value.as < Expr<void>* > ()); std::reverse(yystack_[0].value.as < std::vector<Expr<void>*>* > ()->begin(), yystack_[0].value.as < std::vector<Expr<void>*>* > ()->end()); yylhs.value.as < std::vector<Expr<void>*>* > () = yystack_[0].value.as < std::vector<Expr<void>*>* > ();}
#line 1437 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 69: // args_repetition: %empty
#line 227 "src/SyntaxAnalyzer/Parser.y"
                             {yylhs.value.as < std::vector<Expr<void>*>* > () = new std::vector<Expr<void>*>;}
#line 1443 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 70: // args_repetition: "," expr args_repetition
#line 228 "src/SyntaxAnalyzer/Parser.y"
                                            {yystack_[0].value.as < std::vector<Expr<void>*>* > ()->push_back(yystack_[1].value.as < Expr<void>* > ()); yylhs.value.as < std::vector<Expr<void>*>* > () = yystack_[0].value.as < std::vector<Expr<void>*>* > ();}
#line 1449 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 71: // new: "new" "type-identifier"
#line 230 "src/SyntaxAnalyzer/Parser.y"
                            {yylhs.value.as < Expr<void>* > ()= new New<void>(yystack_[0].value.as < std::string > ());}
#line 1455 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 72: // literal: "integer-literal"
#line 232 "src/SyntaxAnalyzer/Parser.y"
                                   { yylhs.value.as < Expr<void>* > () = new IntegerLiteral<void>(yystack_[0].value.as < int > ());}
#line 1461 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 73: // literal: "string-literal"
#line 233 "src/SyntaxAnalyzer/Parser.y"
                               { yylhs.value.as < Expr<void>* > () = new StringLiteral<void>(yystack_[0].value.as < std::string > ());}
#line 1467 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 74: // literal: "true"
#line 234 "src/SyntaxAnalyzer/Parser.y"
                          { yylhs.value.as < Expr<void>* > () = new BooleanLiteral<void>(yystack_[0].value.as < std::string > ());}
#line 1473 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 75: // literal: "false"
#line 235 "src/SyntaxAnalyzer/Parser.y"
                          { yylhs.value.as < Expr<void>* > () = new BooleanLiteral<void>(yystack_[0].value.as < std::string > ());}
#line 1479 "src/SyntaxAnalyzer/Parser.cpp"
    break;

  case 76: // par: "(" ")"
#line 237 "src/SyntaxAnalyzer/Parser.y"
                {yylhs.value.as < Expr<void>* > () = new Par<void>();}
#line 1485 "src/SyntaxAnalyzer/Parser.cpp"
    break;


#line 1489 "src/SyntaxAnalyzer/Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -40;

  const signed char Parser::yytable_ninf_ = -5;

  const short
  Parser::yypact_[] =
  {
       3,     5,   -12,    14,    22,   -40,    13,   -40,   -40,   -40,
      22,    23,    19,   -40,   -40,     4,   -40,     2,    26,     4,
       4,    33,     8,   -40,   -40,   -40,    29,    32,    30,   -40,
     -40,   -40,   -40,   -40,    21,     8,    37,    33,   -40,   181,
      43,   -40,     8,    30,   -40,   181,   181,    44,    52,   181,
     -40,   -40,   181,   -27,   -40,   181,   159,   181,   -40,   -40,
     114,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,    50,   -40,     0,   -13,    48,   -40,   192,    63,
     181,   181,    74,   -40,    87,    35,   181,   181,   181,   181,
     181,   181,    55,   181,   181,   181,   -40,   181,     8,   181,
     103,    53,   114,   181,    54,   -40,   192,    35,    35,   -13,
     -13,   -13,    56,   201,   201,   201,   126,    41,   114,   181,
     -40,   -40,    74,   -40,   181,   181,   181,    77,   103,   -40,
      60,   114,   114,   181,   -40,   -40,   114
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     8,     0,     0,     0,     6,     9,     1,     8,     2,
       0,     0,     0,     5,    10,    12,     7,     0,     0,    12,
      12,    24,     0,    11,    13,    14,     0,     0,    26,    21,
      20,    22,    23,    19,    16,     0,     0,     0,    25,     0,
       0,    28,     0,    26,    75,     0,     0,     0,     0,     0,
      41,    74,     0,    40,    73,     0,     0,     0,    72,    45,
      17,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      43,    15,     0,    27,     0,    55,     0,    71,    53,     0,
      67,     0,    30,    76,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
      69,     0,    52,     0,     0,    44,    64,    59,    60,    61,
      62,    63,     0,    56,    57,    58,    46,    50,    48,     0,
      68,    65,    30,    29,    67,     0,     0,     0,    69,    31,
       0,    47,    51,     0,    70,    66,    49
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -40,   -40,    75,    91,   -40,   -40,   -40,    24,   -40,   -40,
     -40,   -33,   -40,    49,    58,    46,   -29,   -39,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,    -5,     6,   -40,   -40,
     -40
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     3,     9,    10,     5,    12,    16,    18,    19,    40,
      20,    34,    27,    38,    28,    59,   104,   100,    61,    62,
      63,   127,    64,    65,    66,    67,   101,   120,    68,    69,
      70
  };

  const short
  Parser::yytable_[] =
  {
      60,    80,    41,    86,     1,    -3,    74,    75,     2,    72,
      78,     6,    29,    79,     7,    81,    82,    84,    85,    97,
      30,    11,    -4,     8,    91,    92,    31,     2,    17,    32,
      21,    33,    22,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   102,    24,    25,    15,    14,   106,   107,   108,
     109,   110,   111,    23,   113,   114,   115,    26,   116,    35,
     118,    36,    37,    39,   122,   117,    86,    42,    76,    99,
      89,    90,    91,    92,    71,    77,    55,    86,    98,   112,
     128,   123,   121,   126,   124,    13,   131,   132,   133,   135,
      86,     4,    73,   129,   136,    43,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   103,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   105,    86,    96,   130,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    86,
       0,     0,     0,   125,   134,   119,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    44,    45,
       0,     0,    46,    47,    48,    49,    50,     0,     0,    51,
       0,    52,     0,    53,    54,    55,     0,    56,    83,     0,
      44,    45,     0,    57,    46,    47,    48,    49,    50,     0,
       0,    51,    58,    52,     0,    53,    54,    55,     0,    56,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    87,    88,    89,    90,    91,    92,
      -5,    -5,    -5
  };

  const short
  Parser::yycheck_[] =
  {
      39,    28,    35,     3,     1,     0,    45,    46,     5,    42,
      49,    23,     4,    52,     0,    42,    55,    56,    57,    19,
      12,     8,     0,     1,    37,    38,    18,     5,    24,    21,
      28,    23,    30,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    81,    19,    20,    26,    23,    86,    87,    88,
      89,    90,    91,    27,    93,    94,    95,    24,    97,    30,
      99,    29,    32,    42,   103,    98,     3,    30,    24,     6,
      35,    36,    37,    38,    31,    23,    26,     3,    30,    24,
     119,    27,    29,    42,    28,    10,   125,   126,    11,    29,
       3,     0,    43,   122,   133,    37,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    31,     3,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    29,     3,    72,   124,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     3,
      -1,    -1,    -1,     7,   128,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     9,    10,
      -1,    -1,    13,    14,    15,    16,    17,    -1,    -1,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    28,    29,    -1,
       9,    10,    -1,    34,    13,    14,    15,    16,    17,    -1,
      -1,    20,    43,    22,    -1,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    33,    34,    35,    36,    37,    38,
      39,    40,    41
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     5,    46,    48,    49,    23,     0,     1,    47,
      48,     8,    50,    47,    23,    26,    51,    24,    52,    53,
      55,    28,    30,    27,    52,    52,    24,    57,    59,     4,
      12,    18,    21,    23,    56,    30,    29,    32,    58,    42,
      54,    56,    30,    59,     9,    10,    13,    14,    15,    16,
      17,    20,    22,    24,    25,    26,    28,    34,    43,    60,
      62,    63,    64,    65,    67,    68,    69,    70,    73,    74,
      75,    31,    56,    58,    62,    62,    24,    23,    62,    62,
      28,    42,    62,    29,    62,    62,     3,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    60,    19,    30,     6,
      62,    71,    62,    31,    61,    29,    62,    62,    62,    62,
      62,    62,    24,    62,    62,    62,    62,    56,    62,    32,
      72,    29,    62,    27,    28,     7,    42,    66,    62,    61,
      71,    62,    62,    11,    72,    29,    62
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    51,    52,    52,    52,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    65,
      66,    66,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    74,    74,    75
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     1,     0,     2,     1,     4,     1,     0,
       2,     3,     0,     2,     2,     5,     0,     2,     7,     1,
       1,     1,     1,     1,     0,     2,     0,     3,     3,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     6,     4,     7,
       0,     2,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     6,     0,     2,     0,
       3,     2,     1,     1,     1,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"and\"", "\"bool\"",
  "\"class\"", "\"do\"", "\"else\"", "\"extends\"", "\"false\"", "\"if\"",
  "\"in\"", "\"int32\"", "\"isnull\"", "\"let\"", "\"new\"", "\"not\"",
  "\"self\"", "\"string\"", "\"then\"", "\"true\"", "\"unit\"",
  "\"while\"", "\"type-identifier\"", "\"object-identifier\"",
  "\"string-literal\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\":\"",
  "\";\"", "\",\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"^\"", "\".\"",
  "\"=\"", "\"<\"", "\"<=\"", "\"<-\"", "\"integer-literal\"",
  "\"unary-\"", "$accept", "program", "class_declaration_list",
  "list_class", "class", "class_optional", "class_body",
  "class_body_repetition", "field", "field_optional", "method", "type",
  "formals", "formals_repetition", "formal", "block", "block_repetition",
  "expr", "conditional", "while", "let", "let_optional", "assign", "unop",
  "binop", "call", "args", "args_repetition", "new", "literal", "par", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   137,   137,   138,   141,   142,   144,   146,   147,   149,
     150,   152,   154,   155,   156,   158,   160,   161,   163,   165,
     165,   165,   165,   165,   167,   168,   170,   171,   173,   175,
     177,   178,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   195,   196,   198,   200,
     202,   203,   205,   207,   208,   209,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   221,   222,   224,   225,   227,
     228,   230,   232,   233,   234,   235,   237
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 11 "src/SyntaxAnalyzer/Parser.y"
} } // Compilers::Parsers
#line 2075 "src/SyntaxAnalyzer/Parser.cpp"

#line 239 "src/SyntaxAnalyzer/Parser.y"

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
