// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/SyntaxAnalyzer/Parser.hpp
 ** Define the Compilers::Parsers::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_SYNTAXANALYZER_PARSER_HPP_INCLUDED
# define YY_YY_SRC_SYNTAXANALYZER_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 34 "src/SyntaxAnalyzer/Parser.y"

    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include "AST.hpp"

    namespace Compilers::Parsers
    {
        class SyntaxAnalyzer;
    }

#line 62 "src/SyntaxAnalyzer/Parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 11 "src/SyntaxAnalyzer/Parser.y"
namespace Compilers { namespace Parsers {
#line 203 "src/SyntaxAnalyzer/Parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // list_class
      // class
      // class_body
      // class_body_repetition
      char dummy1[sizeof (Class<void>*)];

      // field_optional
      // expr
      // conditional
      // while
      // let
      // let_optional
      // assign
      // unop
      // binop
      // call
      // new
      // literal
      // par
      char dummy2[sizeof (Expr<void>*)];

      // field
      char dummy3[sizeof (Field<void>*)];

      // formal
      char dummy4[sizeof (Formal<void>*)];

      // method
      char dummy5[sizeof (Method<void>*)];

      // "integer-literal"
      char dummy6[sizeof (int)];

      // "and"
      // "bool"
      // "class"
      // "do"
      // "else"
      // "extends"
      // "false"
      // "if"
      // "in"
      // "int32"
      // "isnull"
      // "let"
      // "new"
      // "not"
      // "self"
      // "string"
      // "then"
      // "true"
      // "unit"
      // "while"
      // "type-identifier"
      // "object-identifier"
      // "string-literal"
      // "{"
      // "}"
      // "("
      // ")"
      // ":"
      // ";"
      // ","
      // "+"
      // "-"
      // "*"
      // "/"
      // "^"
      // "."
      // "="
      // "<"
      // "<="
      // "<-"
      // class_optional
      // type
      char dummy7[sizeof (std::string)];

      // class_declaration_list
      char dummy8[sizeof (std::vector<Class<void>*>*)];

      // block
      // block_repetition
      // args
      // args_repetition
      char dummy9[sizeof (std::vector<Expr<void>*>*)];

      // formals
      // formals_repetition
      char dummy10[sizeof (std::vector<Formal<void>*>*)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    AND = 3,                       // "and"
    BOOL = 4,                      // "bool"
    CLASS = 5,                     // "class"
    DO = 6,                        // "do"
    ELSE = 7,                      // "else"
    EXTENDS = 8,                   // "extends"
    FALSE = 9,                     // "false"
    IF = 10,                       // "if"
    IN = 11,                       // "in"
    INT32 = 12,                    // "int32"
    ISNULL = 13,                   // "isnull"
    LET = 14,                      // "let"
    NEW = 15,                      // "new"
    NOT = 16,                      // "not"
    SELF = 17,                     // "self"
    STRING = 18,                   // "string"
    THEN = 19,                     // "then"
    TRUE = 20,                     // "true"
    UNIT = 21,                     // "unit"
    WHILE = 22,                    // "while"
    TYPE_IDENTIFIER = 23,          // "type-identifier"
    OBJECT_IDENTIFIER = 24,        // "object-identifier"
    STRING_LITERAL = 25,           // "string-literal"
    LBRACE = 26,                   // "{"
    RBRACE = 27,                   // "}"
    LPAR = 28,                     // "("
    RPAR = 29,                     // ")"
    COLON = 30,                    // ":"
    SEMICOLON = 31,                // ";"
    COMMA = 32,                    // ","
    PLUS = 33,                     // "+"
    MINUS = 34,                    // "-"
    TIMES = 35,                    // "*"
    DIVIDE = 36,                   // "/"
    POWER = 37,                    // "^"
    DOT = 38,                      // "."
    EQUAL = 39,                    // "="
    LOWER = 40,                    // "<"
    LOWER_EQUAL = 41,              // "<="
    ASSIGN = 42,                   // "<-"
    INTEGER_LITERAL = 43           // "integer-literal"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 45, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_AND = 3,                               // "and"
        S_BOOL = 4,                              // "bool"
        S_CLASS = 5,                             // "class"
        S_DO = 6,                                // "do"
        S_ELSE = 7,                              // "else"
        S_EXTENDS = 8,                           // "extends"
        S_FALSE = 9,                             // "false"
        S_IF = 10,                               // "if"
        S_IN = 11,                               // "in"
        S_INT32 = 12,                            // "int32"
        S_ISNULL = 13,                           // "isnull"
        S_LET = 14,                              // "let"
        S_NEW = 15,                              // "new"
        S_NOT = 16,                              // "not"
        S_SELF = 17,                             // "self"
        S_STRING = 18,                           // "string"
        S_THEN = 19,                             // "then"
        S_TRUE = 20,                             // "true"
        S_UNIT = 21,                             // "unit"
        S_WHILE = 22,                            // "while"
        S_TYPE_IDENTIFIER = 23,                  // "type-identifier"
        S_OBJECT_IDENTIFIER = 24,                // "object-identifier"
        S_STRING_LITERAL = 25,                   // "string-literal"
        S_LBRACE = 26,                           // "{"
        S_RBRACE = 27,                           // "}"
        S_LPAR = 28,                             // "("
        S_RPAR = 29,                             // ")"
        S_COLON = 30,                            // ":"
        S_SEMICOLON = 31,                        // ";"
        S_COMMA = 32,                            // ","
        S_PLUS = 33,                             // "+"
        S_MINUS = 34,                            // "-"
        S_TIMES = 35,                            // "*"
        S_DIVIDE = 36,                           // "/"
        S_POWER = 37,                            // "^"
        S_DOT = 38,                              // "."
        S_EQUAL = 39,                            // "="
        S_LOWER = 40,                            // "<"
        S_LOWER_EQUAL = 41,                      // "<="
        S_ASSIGN = 42,                           // "<-"
        S_INTEGER_LITERAL = 43,                  // "integer-literal"
        S_44_unary_ = 44,                        // "unary-"
        S_YYACCEPT = 45,                         // $accept
        S_program = 46,                          // program
        S_class_declaration_list = 47,           // class_declaration_list
        S_list_class = 48,                       // list_class
        S_class = 49,                            // class
        S_class_optional = 50,                   // class_optional
        S_class_body = 51,                       // class_body
        S_class_body_repetition = 52,            // class_body_repetition
        S_field = 53,                            // field
        S_field_optional = 54,                   // field_optional
        S_method = 55,                           // method
        S_type = 56,                             // type
        S_formals = 57,                          // formals
        S_formals_repetition = 58,               // formals_repetition
        S_formal = 59,                           // formal
        S_block = 60,                            // block
        S_block_repetition = 61,                 // block_repetition
        S_expr = 62,                             // expr
        S_conditional = 63,                      // conditional
        S_while = 64,                            // while
        S_let = 65,                              // let
        S_let_optional = 66,                     // let_optional
        S_assign = 67,                           // assign
        S_unop = 68,                             // unop
        S_binop = 69,                            // binop
        S_call = 70,                             // call
        S_args = 71,                             // args
        S_args_repetition = 72,                  // args_repetition
        S_new = 73,                              // new
        S_literal = 74,                          // literal
        S_par = 75                               // par
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.move< Class<void>* > (std::move (that.value));
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
        value.move< Expr<void>* > (std::move (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< Field<void>* > (std::move (that.value));
        break;

      case symbol_kind::S_formal: // formal
        value.move< Formal<void>* > (std::move (that.value));
        break;

      case symbol_kind::S_method: // method
        value.move< Method<void>* > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.move< int > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.move< std::vector<Class<void>*>* > (std::move (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.move< std::vector<Expr<void>*>* > (std::move (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.move< std::vector<Formal<void>*>* > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Class<void>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Class<void>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expr<void>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expr<void>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Field<void>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Field<void>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Formal<void>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Formal<void>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Method<void>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Method<void>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Class<void>*>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Class<void>*>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Expr<void>*>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Expr<void>*>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Formal<void>*>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Formal<void>*>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.template destroy< Class<void>* > ();
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
        value.template destroy< Expr<void>* > ();
        break;

      case symbol_kind::S_field: // field
        value.template destroy< Field<void>* > ();
        break;

      case symbol_kind::S_formal: // formal
        value.template destroy< Formal<void>* > ();
        break;

      case symbol_kind::S_method: // method
        value.template destroy< Method<void>* > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.template destroy< int > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.template destroy< std::vector<Class<void>*>* > ();
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.template destroy< std::vector<Expr<void>*>* > ();
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.template destroy< std::vector<Formal<void>*>* > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || tok == 299);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::INTEGER_LITERAL);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::AND <= tok && tok <= token::ASSIGN));
#endif
      }
    };

    /// Build a parser object.
    Parser (Compilers::Parsers::SyntaxAnalyzer &synAnalysis_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (std::string v, location_type l)
      {
        return symbol_type (token::BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (std::string v, location_type l)
      {
        return symbol_type (token::CLASS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CLASS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v, location_type l)
      {
        return symbol_type (token::DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (std::string v, location_type l)
      {
        return symbol_type (token::EXTENDS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTENDS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EXTENDS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (std::string v, location_type l)
      {
        return symbol_type (token::FALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (std::string v, location_type l)
      {
        return symbol_type (token::IN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT32 (std::string v, location_type l)
      {
        return symbol_type (token::INT32, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT32 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT32, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ISNULL (std::string v, location_type l)
      {
        return symbol_type (token::ISNULL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ISNULL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ISNULL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (std::string v, location_type l)
      {
        return symbol_type (token::LET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (std::string v, location_type l)
      {
        return symbol_type (token::NEW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NEW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v, location_type l)
      {
        return symbol_type (token::NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELF (std::string v, location_type l)
      {
        return symbol_type (token::SELF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SELF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SELF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (std::string v, location_type l)
      {
        return symbol_type (token::THEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::THEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (std::string v, location_type l)
      {
        return symbol_type (token::TRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIT (std::string v, location_type l)
      {
        return symbol_type (token::UNIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::UNIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TYPE_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TYPE_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OBJECT_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::OBJECT_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OBJECT_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OBJECT_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (std::string v, location_type l)
      {
        return symbol_type (token::LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (std::string v, location_type l)
      {
        return symbol_type (token::RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAR (std::string v, location_type l)
      {
        return symbol_type (token::LPAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LPAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAR (std::string v, location_type l)
      {
        return symbol_type (token::RPAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RPAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (std::string v, location_type l)
      {
        return symbol_type (token::COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (std::string v, location_type l)
      {
        return symbol_type (token::PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (std::string v, location_type l)
      {
        return symbol_type (token::MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMES (std::string v, location_type l)
      {
        return symbol_type (token::TIMES, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIMES (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIMES, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (std::string v, location_type l)
      {
        return symbol_type (token::DIVIDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DIVIDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POWER (std::string v, location_type l)
      {
        return symbol_type (token::POWER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_POWER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::POWER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v, location_type l)
      {
        return symbol_type (token::DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER (std::string v, location_type l)
      {
        return symbol_type (token::LOWER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LOWER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::LOWER_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LOWER_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER_LITERAL (int v, location_type l)
      {
        return symbol_type (token::INTEGER_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER_LITERAL (const int& v, const location_type& l)
      {
        return symbol_type (token::INTEGER_LITERAL, v, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 242,     ///< Last index in yytable_.
      yynnts_ = 31,  ///< Number of nonterminal symbols.
      yyfinal_ = 7 ///< Termination state number.
    };


    // User arguments.
    Compilers::Parsers::SyntaxAnalyzer &synAnalysis;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.copy< Class<void>* > (YY_MOVE (that.value));
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
        value.copy< Expr<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< Field<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal: // formal
        value.copy< Formal<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.copy< Method<void>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.copy< int > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.copy< std::vector<Class<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.copy< std::vector<Expr<void>*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.copy< std::vector<Formal<void>*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_list_class: // list_class
      case symbol_kind::S_class: // class
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_body_repetition: // class_body_repetition
        value.move< Class<void>* > (YY_MOVE (s.value));
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
        value.move< Expr<void>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< Field<void>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formal: // formal
        value.move< Formal<void>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_method: // method
        value.move< Method<void>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // "integer-literal"
        value.move< int > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_declaration_list: // class_declaration_list
        value.move< std::vector<Class<void>*>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_block_repetition: // block_repetition
      case symbol_kind::S_args: // args
      case symbol_kind::S_args_repetition: // args_repetition
        value.move< std::vector<Expr<void>*>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formals_repetition: // formals_repetition
        value.move< std::vector<Formal<void>*>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 11 "src/SyntaxAnalyzer/Parser.y"
} } // Compilers::Parsers
#line 2610 "src/SyntaxAnalyzer/Parser.hpp"




#endif // !YY_YY_SRC_SYNTAXANALYZER_PARSER_HPP_INCLUDED
