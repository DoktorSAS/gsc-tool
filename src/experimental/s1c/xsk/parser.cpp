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

// "%code top" blocks.
#line 38 "parser.ypp"

#include "stdafx.hpp"
#include "parser.hpp"
#include "lexer.hpp"
using namespace xsk::gsc;
xsk::gsc::s1c::parser::symbol_type S1Clex(xsk::gsc::s1c::lexer& lexer);

#line 47 "parser.cpp"

// Take the name prefix into account.
#define yylex   S1Clex



#include "parser.hpp"




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
#if S1CDEBUG

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

#else // !S1CDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !S1CDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 13 "parser.ypp"
namespace xsk { namespace gsc { namespace s1c {
#line 149 "parser.cpp"

  /// Build a parser object.
  parser::parser (xsk::gsc::s1c::lexer& lexer_yyarg, xsk::gsc::ast::program::ptr& ast_yyarg)
#if S1CDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      lexer (lexer_yyarg),
      ast (ast_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_pointer: // expr_pointer
        value.YY_MOVE_OR_COPY< ast::call > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< ast::decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_constant: // decl_constant
        value.YY_MOVE_OR_COPY< ast::decl_constant::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_thread: // decl_thread
        value.YY_MOVE_OR_COPY< ast::decl_thread::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_usingtree: // decl_usingtree
        value.YY_MOVE_OR_COPY< ast::decl_usingtree::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_or_empty: // expr_or_empty
      case symbol_kind::S_expr_assign: // expr_assign
      case symbol_kind::S_expr_increment: // expr_increment
      case symbol_kind::S_expr_decrement: // expr_decrement
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
      case symbol_kind::S_expr_tuple: // expr_tuple
      case symbol_kind::S_expr_tuple_types: // expr_tuple_types
      case symbol_kind::S_expr_object: // expr_object
        value.YY_MOVE_OR_COPY< ast::expr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_add_array: // expr_add_array
        value.YY_MOVE_OR_COPY< ast::expr_add_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_anim: // expr_anim
        value.YY_MOVE_OR_COPY< ast::expr_anim::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_animation: // expr_animation
        value.YY_MOVE_OR_COPY< ast::expr_animation::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_animtree: // expr_animtree
        value.YY_MOVE_OR_COPY< ast::expr_animtree::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_no_empty: // expr_arguments_no_empty
        value.YY_MOVE_OR_COPY< ast::expr_arguments::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_array: // expr_array
        value.YY_MOVE_OR_COPY< ast::expr_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
        value.YY_MOVE_OR_COPY< ast::expr_call::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_complement: // expr_complement
        value.YY_MOVE_OR_COPY< ast::expr_complement::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_empty_array: // expr_empty_array
        value.YY_MOVE_OR_COPY< ast::expr_empty_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_false: // expr_false
        value.YY_MOVE_OR_COPY< ast::expr_false::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_field: // expr_field
        value.YY_MOVE_OR_COPY< ast::expr_field::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_float: // expr_float
        value.YY_MOVE_OR_COPY< ast::expr_float::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_game: // expr_game
        value.YY_MOVE_OR_COPY< ast::expr_game::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_identifier_nosize: // expr_identifier_nosize
      case symbol_kind::S_expr_identifier: // expr_identifier
        value.YY_MOVE_OR_COPY< ast::expr_identifier::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_integer: // expr_integer
        value.YY_MOVE_OR_COPY< ast::expr_integer::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_istring: // expr_istring
        value.YY_MOVE_OR_COPY< ast::expr_istring::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_level: // expr_level
        value.YY_MOVE_OR_COPY< ast::expr_level::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_method: // expr_method
        value.YY_MOVE_OR_COPY< ast::expr_method::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_negate: // expr_negate
        value.YY_MOVE_OR_COPY< ast::expr_negate::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_not: // expr_not
        value.YY_MOVE_OR_COPY< ast::expr_not::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_parameters: // expr_parameters
        value.YY_MOVE_OR_COPY< ast::expr_parameters::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_paren: // expr_paren
        value.YY_MOVE_OR_COPY< ast::expr_paren::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_path: // expr_path
        value.YY_MOVE_OR_COPY< ast::expr_path::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_reference: // expr_reference
        value.YY_MOVE_OR_COPY< ast::expr_reference::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_self: // expr_self
        value.YY_MOVE_OR_COPY< ast::expr_self::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_size: // expr_size
        value.YY_MOVE_OR_COPY< ast::expr_size::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_string: // expr_string
        value.YY_MOVE_OR_COPY< ast::expr_string::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_thisthread: // expr_thisthread
        value.YY_MOVE_OR_COPY< ast::expr_thisthread::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_true: // expr_true
        value.YY_MOVE_OR_COPY< ast::expr_true::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_tuple_arguments: // expr_tuple_arguments
        value.YY_MOVE_OR_COPY< ast::expr_tuple::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_undefined: // expr_undefined
        value.YY_MOVE_OR_COPY< ast::expr_undefined::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_vector: // expr_vector
        value.YY_MOVE_OR_COPY< ast::expr_vector::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.YY_MOVE_OR_COPY< ast::include::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< ast::program::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_stmt_or_dev: // stmt_or_dev
        value.YY_MOVE_OR_COPY< ast::stmt > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.YY_MOVE_OR_COPY< ast::stmt_assign::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.YY_MOVE_OR_COPY< ast::stmt_break::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_breakpoint: // stmt_breakpoint
        value.YY_MOVE_OR_COPY< ast::stmt_breakpoint::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.YY_MOVE_OR_COPY< ast::stmt_call::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.YY_MOVE_OR_COPY< ast::stmt_case::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.YY_MOVE_OR_COPY< ast::stmt_continue::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.YY_MOVE_OR_COPY< ast::stmt_default::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_dev: // stmt_dev
        value.YY_MOVE_OR_COPY< ast::stmt_dev::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_dowhile: // stmt_dowhile
        value.YY_MOVE_OR_COPY< ast::stmt_dowhile::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.YY_MOVE_OR_COPY< ast::stmt_endon::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_expr: // stmt_expr
        value.YY_MOVE_OR_COPY< ast::stmt_expr::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.YY_MOVE_OR_COPY< ast::stmt_for::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.YY_MOVE_OR_COPY< ast::stmt_foreach::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.YY_MOVE_OR_COPY< ast::stmt_if::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.YY_MOVE_OR_COPY< ast::stmt_ifelse::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_or_dev_list: // stmt_or_dev_list
      case symbol_kind::S_stmt_block: // stmt_block
        value.YY_MOVE_OR_COPY< ast::stmt_list::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.YY_MOVE_OR_COPY< ast::stmt_notify::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_prof_begin: // stmt_prof_begin
        value.YY_MOVE_OR_COPY< ast::stmt_prof_begin::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_prof_end: // stmt_prof_end
        value.YY_MOVE_OR_COPY< ast::stmt_prof_end::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.YY_MOVE_OR_COPY< ast::stmt_return::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.YY_MOVE_OR_COPY< ast::stmt_switch::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.YY_MOVE_OR_COPY< ast::stmt_wait::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.YY_MOVE_OR_COPY< ast::stmt_waitframe::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.YY_MOVE_OR_COPY< ast::stmt_waittill::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.YY_MOVE_OR_COPY< ast::stmt_waittillframeend::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.YY_MOVE_OR_COPY< ast::stmt_waittillmatch::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.YY_MOVE_OR_COPY< ast::stmt_while::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PATH: // "path"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_pointer: // expr_pointer
        value.move< ast::call > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< ast::decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_constant: // decl_constant
        value.move< ast::decl_constant::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_thread: // decl_thread
        value.move< ast::decl_thread::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl_usingtree: // decl_usingtree
        value.move< ast::decl_usingtree::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_or_empty: // expr_or_empty
      case symbol_kind::S_expr_assign: // expr_assign
      case symbol_kind::S_expr_increment: // expr_increment
      case symbol_kind::S_expr_decrement: // expr_decrement
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
      case symbol_kind::S_expr_tuple: // expr_tuple
      case symbol_kind::S_expr_tuple_types: // expr_tuple_types
      case symbol_kind::S_expr_object: // expr_object
        value.move< ast::expr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_add_array: // expr_add_array
        value.move< ast::expr_add_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_anim: // expr_anim
        value.move< ast::expr_anim::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_animation: // expr_animation
        value.move< ast::expr_animation::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_animtree: // expr_animtree
        value.move< ast::expr_animtree::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_no_empty: // expr_arguments_no_empty
        value.move< ast::expr_arguments::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_array: // expr_array
        value.move< ast::expr_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
        value.move< ast::expr_call::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_complement: // expr_complement
        value.move< ast::expr_complement::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_empty_array: // expr_empty_array
        value.move< ast::expr_empty_array::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_false: // expr_false
        value.move< ast::expr_false::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_field: // expr_field
        value.move< ast::expr_field::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_float: // expr_float
        value.move< ast::expr_float::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_game: // expr_game
        value.move< ast::expr_game::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_identifier_nosize: // expr_identifier_nosize
      case symbol_kind::S_expr_identifier: // expr_identifier
        value.move< ast::expr_identifier::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_integer: // expr_integer
        value.move< ast::expr_integer::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_istring: // expr_istring
        value.move< ast::expr_istring::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_level: // expr_level
        value.move< ast::expr_level::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_method: // expr_method
        value.move< ast::expr_method::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_negate: // expr_negate
        value.move< ast::expr_negate::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_not: // expr_not
        value.move< ast::expr_not::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_parameters: // expr_parameters
        value.move< ast::expr_parameters::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_paren: // expr_paren
        value.move< ast::expr_paren::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_path: // expr_path
        value.move< ast::expr_path::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_reference: // expr_reference
        value.move< ast::expr_reference::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_self: // expr_self
        value.move< ast::expr_self::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_size: // expr_size
        value.move< ast::expr_size::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_string: // expr_string
        value.move< ast::expr_string::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_thisthread: // expr_thisthread
        value.move< ast::expr_thisthread::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_true: // expr_true
        value.move< ast::expr_true::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_tuple_arguments: // expr_tuple_arguments
        value.move< ast::expr_tuple::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_undefined: // expr_undefined
        value.move< ast::expr_undefined::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_vector: // expr_vector
        value.move< ast::expr_vector::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.move< ast::include::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< ast::program::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_stmt_or_dev: // stmt_or_dev
        value.move< ast::stmt > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< ast::stmt_assign::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< ast::stmt_break::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_breakpoint: // stmt_breakpoint
        value.move< ast::stmt_breakpoint::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< ast::stmt_call::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< ast::stmt_case::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< ast::stmt_continue::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< ast::stmt_default::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_dev: // stmt_dev
        value.move< ast::stmt_dev::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_dowhile: // stmt_dowhile
        value.move< ast::stmt_dowhile::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< ast::stmt_endon::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_expr: // stmt_expr
        value.move< ast::stmt_expr::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< ast::stmt_for::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< ast::stmt_foreach::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< ast::stmt_if::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< ast::stmt_ifelse::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_or_dev_list: // stmt_or_dev_list
      case symbol_kind::S_stmt_block: // stmt_block
        value.move< ast::stmt_list::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< ast::stmt_notify::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_prof_begin: // stmt_prof_begin
        value.move< ast::stmt_prof_begin::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_prof_end: // stmt_prof_end
        value.move< ast::stmt_prof_end::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< ast::stmt_return::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< ast::stmt_switch::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< ast::stmt_wait::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.move< ast::stmt_waitframe::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< ast::stmt_waittill::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< ast::stmt_waittillframeend::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< ast::stmt_waittillmatch::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< ast::stmt_while::ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PATH: // "path"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "integer"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_pointer: // expr_pointer
        value.copy< ast::call > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< ast::decl > (that.value);
        break;

      case symbol_kind::S_decl_constant: // decl_constant
        value.copy< ast::decl_constant::ptr > (that.value);
        break;

      case symbol_kind::S_decl_thread: // decl_thread
        value.copy< ast::decl_thread::ptr > (that.value);
        break;

      case symbol_kind::S_decl_usingtree: // decl_usingtree
        value.copy< ast::decl_usingtree::ptr > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_or_empty: // expr_or_empty
      case symbol_kind::S_expr_assign: // expr_assign
      case symbol_kind::S_expr_increment: // expr_increment
      case symbol_kind::S_expr_decrement: // expr_decrement
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
      case symbol_kind::S_expr_tuple: // expr_tuple
      case symbol_kind::S_expr_tuple_types: // expr_tuple_types
      case symbol_kind::S_expr_object: // expr_object
        value.copy< ast::expr > (that.value);
        break;

      case symbol_kind::S_expr_add_array: // expr_add_array
        value.copy< ast::expr_add_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_anim: // expr_anim
        value.copy< ast::expr_anim::ptr > (that.value);
        break;

      case symbol_kind::S_expr_animation: // expr_animation
        value.copy< ast::expr_animation::ptr > (that.value);
        break;

      case symbol_kind::S_expr_animtree: // expr_animtree
        value.copy< ast::expr_animtree::ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_no_empty: // expr_arguments_no_empty
        value.copy< ast::expr_arguments::ptr > (that.value);
        break;

      case symbol_kind::S_expr_array: // expr_array
        value.copy< ast::expr_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
        value.copy< ast::expr_call::ptr > (that.value);
        break;

      case symbol_kind::S_expr_complement: // expr_complement
        value.copy< ast::expr_complement::ptr > (that.value);
        break;

      case symbol_kind::S_expr_empty_array: // expr_empty_array
        value.copy< ast::expr_empty_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_false: // expr_false
        value.copy< ast::expr_false::ptr > (that.value);
        break;

      case symbol_kind::S_expr_field: // expr_field
        value.copy< ast::expr_field::ptr > (that.value);
        break;

      case symbol_kind::S_expr_float: // expr_float
        value.copy< ast::expr_float::ptr > (that.value);
        break;

      case symbol_kind::S_expr_game: // expr_game
        value.copy< ast::expr_game::ptr > (that.value);
        break;

      case symbol_kind::S_expr_identifier_nosize: // expr_identifier_nosize
      case symbol_kind::S_expr_identifier: // expr_identifier
        value.copy< ast::expr_identifier::ptr > (that.value);
        break;

      case symbol_kind::S_expr_integer: // expr_integer
        value.copy< ast::expr_integer::ptr > (that.value);
        break;

      case symbol_kind::S_expr_istring: // expr_istring
        value.copy< ast::expr_istring::ptr > (that.value);
        break;

      case symbol_kind::S_expr_level: // expr_level
        value.copy< ast::expr_level::ptr > (that.value);
        break;

      case symbol_kind::S_expr_method: // expr_method
        value.copy< ast::expr_method::ptr > (that.value);
        break;

      case symbol_kind::S_expr_negate: // expr_negate
        value.copy< ast::expr_negate::ptr > (that.value);
        break;

      case symbol_kind::S_expr_not: // expr_not
        value.copy< ast::expr_not::ptr > (that.value);
        break;

      case symbol_kind::S_expr_parameters: // expr_parameters
        value.copy< ast::expr_parameters::ptr > (that.value);
        break;

      case symbol_kind::S_expr_paren: // expr_paren
        value.copy< ast::expr_paren::ptr > (that.value);
        break;

      case symbol_kind::S_expr_path: // expr_path
        value.copy< ast::expr_path::ptr > (that.value);
        break;

      case symbol_kind::S_expr_reference: // expr_reference
        value.copy< ast::expr_reference::ptr > (that.value);
        break;

      case symbol_kind::S_expr_self: // expr_self
        value.copy< ast::expr_self::ptr > (that.value);
        break;

      case symbol_kind::S_expr_size: // expr_size
        value.copy< ast::expr_size::ptr > (that.value);
        break;

      case symbol_kind::S_expr_string: // expr_string
        value.copy< ast::expr_string::ptr > (that.value);
        break;

      case symbol_kind::S_expr_thisthread: // expr_thisthread
        value.copy< ast::expr_thisthread::ptr > (that.value);
        break;

      case symbol_kind::S_expr_true: // expr_true
        value.copy< ast::expr_true::ptr > (that.value);
        break;

      case symbol_kind::S_expr_tuple_arguments: // expr_tuple_arguments
        value.copy< ast::expr_tuple::ptr > (that.value);
        break;

      case symbol_kind::S_expr_undefined: // expr_undefined
        value.copy< ast::expr_undefined::ptr > (that.value);
        break;

      case symbol_kind::S_expr_vector: // expr_vector
        value.copy< ast::expr_vector::ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.copy< ast::include::ptr > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< ast::program::ptr > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_stmt_or_dev: // stmt_or_dev
        value.copy< ast::stmt > (that.value);
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.copy< ast::stmt_assign::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.copy< ast::stmt_break::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_breakpoint: // stmt_breakpoint
        value.copy< ast::stmt_breakpoint::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.copy< ast::stmt_call::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.copy< ast::stmt_case::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.copy< ast::stmt_continue::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.copy< ast::stmt_default::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_dev: // stmt_dev
        value.copy< ast::stmt_dev::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_dowhile: // stmt_dowhile
        value.copy< ast::stmt_dowhile::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.copy< ast::stmt_endon::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_expr: // stmt_expr
        value.copy< ast::stmt_expr::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.copy< ast::stmt_for::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.copy< ast::stmt_foreach::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.copy< ast::stmt_if::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.copy< ast::stmt_ifelse::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_or_dev_list: // stmt_or_dev_list
      case symbol_kind::S_stmt_block: // stmt_block
        value.copy< ast::stmt_list::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.copy< ast::stmt_notify::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_prof_begin: // stmt_prof_begin
        value.copy< ast::stmt_prof_begin::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_prof_end: // stmt_prof_end
        value.copy< ast::stmt_prof_end::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.copy< ast::stmt_return::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.copy< ast::stmt_switch::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.copy< ast::stmt_wait::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.copy< ast::stmt_waitframe::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.copy< ast::stmt_waittill::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.copy< ast::stmt_waittillframeend::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.copy< ast::stmt_waittillmatch::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.copy< ast::stmt_while::ptr > (that.value);
        break;

      case symbol_kind::S_PATH: // "path"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "integer"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_pointer: // expr_pointer
        value.move< ast::call > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< ast::decl > (that.value);
        break;

      case symbol_kind::S_decl_constant: // decl_constant
        value.move< ast::decl_constant::ptr > (that.value);
        break;

      case symbol_kind::S_decl_thread: // decl_thread
        value.move< ast::decl_thread::ptr > (that.value);
        break;

      case symbol_kind::S_decl_usingtree: // decl_usingtree
        value.move< ast::decl_usingtree::ptr > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_or_empty: // expr_or_empty
      case symbol_kind::S_expr_assign: // expr_assign
      case symbol_kind::S_expr_increment: // expr_increment
      case symbol_kind::S_expr_decrement: // expr_decrement
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
      case symbol_kind::S_expr_tuple: // expr_tuple
      case symbol_kind::S_expr_tuple_types: // expr_tuple_types
      case symbol_kind::S_expr_object: // expr_object
        value.move< ast::expr > (that.value);
        break;

      case symbol_kind::S_expr_add_array: // expr_add_array
        value.move< ast::expr_add_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_anim: // expr_anim
        value.move< ast::expr_anim::ptr > (that.value);
        break;

      case symbol_kind::S_expr_animation: // expr_animation
        value.move< ast::expr_animation::ptr > (that.value);
        break;

      case symbol_kind::S_expr_animtree: // expr_animtree
        value.move< ast::expr_animtree::ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_no_empty: // expr_arguments_no_empty
        value.move< ast::expr_arguments::ptr > (that.value);
        break;

      case symbol_kind::S_expr_array: // expr_array
        value.move< ast::expr_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
        value.move< ast::expr_call::ptr > (that.value);
        break;

      case symbol_kind::S_expr_complement: // expr_complement
        value.move< ast::expr_complement::ptr > (that.value);
        break;

      case symbol_kind::S_expr_empty_array: // expr_empty_array
        value.move< ast::expr_empty_array::ptr > (that.value);
        break;

      case symbol_kind::S_expr_false: // expr_false
        value.move< ast::expr_false::ptr > (that.value);
        break;

      case symbol_kind::S_expr_field: // expr_field
        value.move< ast::expr_field::ptr > (that.value);
        break;

      case symbol_kind::S_expr_float: // expr_float
        value.move< ast::expr_float::ptr > (that.value);
        break;

      case symbol_kind::S_expr_game: // expr_game
        value.move< ast::expr_game::ptr > (that.value);
        break;

      case symbol_kind::S_expr_identifier_nosize: // expr_identifier_nosize
      case symbol_kind::S_expr_identifier: // expr_identifier
        value.move< ast::expr_identifier::ptr > (that.value);
        break;

      case symbol_kind::S_expr_integer: // expr_integer
        value.move< ast::expr_integer::ptr > (that.value);
        break;

      case symbol_kind::S_expr_istring: // expr_istring
        value.move< ast::expr_istring::ptr > (that.value);
        break;

      case symbol_kind::S_expr_level: // expr_level
        value.move< ast::expr_level::ptr > (that.value);
        break;

      case symbol_kind::S_expr_method: // expr_method
        value.move< ast::expr_method::ptr > (that.value);
        break;

      case symbol_kind::S_expr_negate: // expr_negate
        value.move< ast::expr_negate::ptr > (that.value);
        break;

      case symbol_kind::S_expr_not: // expr_not
        value.move< ast::expr_not::ptr > (that.value);
        break;

      case symbol_kind::S_expr_parameters: // expr_parameters
        value.move< ast::expr_parameters::ptr > (that.value);
        break;

      case symbol_kind::S_expr_paren: // expr_paren
        value.move< ast::expr_paren::ptr > (that.value);
        break;

      case symbol_kind::S_expr_path: // expr_path
        value.move< ast::expr_path::ptr > (that.value);
        break;

      case symbol_kind::S_expr_reference: // expr_reference
        value.move< ast::expr_reference::ptr > (that.value);
        break;

      case symbol_kind::S_expr_self: // expr_self
        value.move< ast::expr_self::ptr > (that.value);
        break;

      case symbol_kind::S_expr_size: // expr_size
        value.move< ast::expr_size::ptr > (that.value);
        break;

      case symbol_kind::S_expr_string: // expr_string
        value.move< ast::expr_string::ptr > (that.value);
        break;

      case symbol_kind::S_expr_thisthread: // expr_thisthread
        value.move< ast::expr_thisthread::ptr > (that.value);
        break;

      case symbol_kind::S_expr_true: // expr_true
        value.move< ast::expr_true::ptr > (that.value);
        break;

      case symbol_kind::S_expr_tuple_arguments: // expr_tuple_arguments
        value.move< ast::expr_tuple::ptr > (that.value);
        break;

      case symbol_kind::S_expr_undefined: // expr_undefined
        value.move< ast::expr_undefined::ptr > (that.value);
        break;

      case symbol_kind::S_expr_vector: // expr_vector
        value.move< ast::expr_vector::ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.move< ast::include::ptr > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< ast::program::ptr > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_stmt_or_dev: // stmt_or_dev
        value.move< ast::stmt > (that.value);
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< ast::stmt_assign::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< ast::stmt_break::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_breakpoint: // stmt_breakpoint
        value.move< ast::stmt_breakpoint::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< ast::stmt_call::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< ast::stmt_case::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< ast::stmt_continue::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< ast::stmt_default::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_dev: // stmt_dev
        value.move< ast::stmt_dev::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_dowhile: // stmt_dowhile
        value.move< ast::stmt_dowhile::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< ast::stmt_endon::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_expr: // stmt_expr
        value.move< ast::stmt_expr::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< ast::stmt_for::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< ast::stmt_foreach::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< ast::stmt_if::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< ast::stmt_ifelse::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_or_dev_list: // stmt_or_dev_list
      case symbol_kind::S_stmt_block: // stmt_block
        value.move< ast::stmt_list::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< ast::stmt_notify::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_prof_begin: // stmt_prof_begin
        value.move< ast::stmt_prof_begin::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_prof_end: // stmt_prof_end
        value.move< ast::stmt_prof_end::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< ast::stmt_return::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< ast::stmt_switch::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< ast::stmt_wait::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.move< ast::stmt_waitframe::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< ast::stmt_waittill::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< ast::stmt_waittillframeend::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< ast::stmt_waittillmatch::ptr > (that.value);
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< ast::stmt_while::ptr > (that.value);
        break;

      case symbol_kind::S_PATH: // "path"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "integer"
        value.move< std::string > (that.value);
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
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if S1CDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if S1CDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // S1CDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (lexer));
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_pointer: // expr_pointer
        yylhs.value.emplace< ast::call > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< ast::decl > ();
        break;

      case symbol_kind::S_decl_constant: // decl_constant
        yylhs.value.emplace< ast::decl_constant::ptr > ();
        break;

      case symbol_kind::S_decl_thread: // decl_thread
        yylhs.value.emplace< ast::decl_thread::ptr > ();
        break;

      case symbol_kind::S_decl_usingtree: // decl_usingtree
        yylhs.value.emplace< ast::decl_usingtree::ptr > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_or_empty: // expr_or_empty
      case symbol_kind::S_expr_assign: // expr_assign
      case symbol_kind::S_expr_increment: // expr_increment
      case symbol_kind::S_expr_decrement: // expr_decrement
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
      case symbol_kind::S_expr_tuple: // expr_tuple
      case symbol_kind::S_expr_tuple_types: // expr_tuple_types
      case symbol_kind::S_expr_object: // expr_object
        yylhs.value.emplace< ast::expr > ();
        break;

      case symbol_kind::S_expr_add_array: // expr_add_array
        yylhs.value.emplace< ast::expr_add_array::ptr > ();
        break;

      case symbol_kind::S_expr_anim: // expr_anim
        yylhs.value.emplace< ast::expr_anim::ptr > ();
        break;

      case symbol_kind::S_expr_animation: // expr_animation
        yylhs.value.emplace< ast::expr_animation::ptr > ();
        break;

      case symbol_kind::S_expr_animtree: // expr_animtree
        yylhs.value.emplace< ast::expr_animtree::ptr > ();
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_no_empty: // expr_arguments_no_empty
        yylhs.value.emplace< ast::expr_arguments::ptr > ();
        break;

      case symbol_kind::S_expr_array: // expr_array
        yylhs.value.emplace< ast::expr_array::ptr > ();
        break;

      case symbol_kind::S_expr_call: // expr_call
        yylhs.value.emplace< ast::expr_call::ptr > ();
        break;

      case symbol_kind::S_expr_complement: // expr_complement
        yylhs.value.emplace< ast::expr_complement::ptr > ();
        break;

      case symbol_kind::S_expr_empty_array: // expr_empty_array
        yylhs.value.emplace< ast::expr_empty_array::ptr > ();
        break;

      case symbol_kind::S_expr_false: // expr_false
        yylhs.value.emplace< ast::expr_false::ptr > ();
        break;

      case symbol_kind::S_expr_field: // expr_field
        yylhs.value.emplace< ast::expr_field::ptr > ();
        break;

      case symbol_kind::S_expr_float: // expr_float
        yylhs.value.emplace< ast::expr_float::ptr > ();
        break;

      case symbol_kind::S_expr_game: // expr_game
        yylhs.value.emplace< ast::expr_game::ptr > ();
        break;

      case symbol_kind::S_expr_identifier_nosize: // expr_identifier_nosize
      case symbol_kind::S_expr_identifier: // expr_identifier
        yylhs.value.emplace< ast::expr_identifier::ptr > ();
        break;

      case symbol_kind::S_expr_integer: // expr_integer
        yylhs.value.emplace< ast::expr_integer::ptr > ();
        break;

      case symbol_kind::S_expr_istring: // expr_istring
        yylhs.value.emplace< ast::expr_istring::ptr > ();
        break;

      case symbol_kind::S_expr_level: // expr_level
        yylhs.value.emplace< ast::expr_level::ptr > ();
        break;

      case symbol_kind::S_expr_method: // expr_method
        yylhs.value.emplace< ast::expr_method::ptr > ();
        break;

      case symbol_kind::S_expr_negate: // expr_negate
        yylhs.value.emplace< ast::expr_negate::ptr > ();
        break;

      case symbol_kind::S_expr_not: // expr_not
        yylhs.value.emplace< ast::expr_not::ptr > ();
        break;

      case symbol_kind::S_expr_parameters: // expr_parameters
        yylhs.value.emplace< ast::expr_parameters::ptr > ();
        break;

      case symbol_kind::S_expr_paren: // expr_paren
        yylhs.value.emplace< ast::expr_paren::ptr > ();
        break;

      case symbol_kind::S_expr_path: // expr_path
        yylhs.value.emplace< ast::expr_path::ptr > ();
        break;

      case symbol_kind::S_expr_reference: // expr_reference
        yylhs.value.emplace< ast::expr_reference::ptr > ();
        break;

      case symbol_kind::S_expr_self: // expr_self
        yylhs.value.emplace< ast::expr_self::ptr > ();
        break;

      case symbol_kind::S_expr_size: // expr_size
        yylhs.value.emplace< ast::expr_size::ptr > ();
        break;

      case symbol_kind::S_expr_string: // expr_string
        yylhs.value.emplace< ast::expr_string::ptr > ();
        break;

      case symbol_kind::S_expr_thisthread: // expr_thisthread
        yylhs.value.emplace< ast::expr_thisthread::ptr > ();
        break;

      case symbol_kind::S_expr_true: // expr_true
        yylhs.value.emplace< ast::expr_true::ptr > ();
        break;

      case symbol_kind::S_expr_tuple_arguments: // expr_tuple_arguments
        yylhs.value.emplace< ast::expr_tuple::ptr > ();
        break;

      case symbol_kind::S_expr_undefined: // expr_undefined
        yylhs.value.emplace< ast::expr_undefined::ptr > ();
        break;

      case symbol_kind::S_expr_vector: // expr_vector
        yylhs.value.emplace< ast::expr_vector::ptr > ();
        break;

      case symbol_kind::S_include: // include
        yylhs.value.emplace< ast::include::ptr > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< ast::program::ptr > ();
        break;

      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_stmt_or_dev: // stmt_or_dev
        yylhs.value.emplace< ast::stmt > ();
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        yylhs.value.emplace< ast::stmt_assign::ptr > ();
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        yylhs.value.emplace< ast::stmt_break::ptr > ();
        break;

      case symbol_kind::S_stmt_breakpoint: // stmt_breakpoint
        yylhs.value.emplace< ast::stmt_breakpoint::ptr > ();
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        yylhs.value.emplace< ast::stmt_call::ptr > ();
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        yylhs.value.emplace< ast::stmt_case::ptr > ();
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        yylhs.value.emplace< ast::stmt_continue::ptr > ();
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        yylhs.value.emplace< ast::stmt_default::ptr > ();
        break;

      case symbol_kind::S_stmt_dev: // stmt_dev
        yylhs.value.emplace< ast::stmt_dev::ptr > ();
        break;

      case symbol_kind::S_stmt_dowhile: // stmt_dowhile
        yylhs.value.emplace< ast::stmt_dowhile::ptr > ();
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        yylhs.value.emplace< ast::stmt_endon::ptr > ();
        break;

      case symbol_kind::S_stmt_expr: // stmt_expr
        yylhs.value.emplace< ast::stmt_expr::ptr > ();
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        yylhs.value.emplace< ast::stmt_for::ptr > ();
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        yylhs.value.emplace< ast::stmt_foreach::ptr > ();
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        yylhs.value.emplace< ast::stmt_if::ptr > ();
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        yylhs.value.emplace< ast::stmt_ifelse::ptr > ();
        break;

      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_or_dev_list: // stmt_or_dev_list
      case symbol_kind::S_stmt_block: // stmt_block
        yylhs.value.emplace< ast::stmt_list::ptr > ();
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        yylhs.value.emplace< ast::stmt_notify::ptr > ();
        break;

      case symbol_kind::S_stmt_prof_begin: // stmt_prof_begin
        yylhs.value.emplace< ast::stmt_prof_begin::ptr > ();
        break;

      case symbol_kind::S_stmt_prof_end: // stmt_prof_end
        yylhs.value.emplace< ast::stmt_prof_end::ptr > ();
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        yylhs.value.emplace< ast::stmt_return::ptr > ();
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        yylhs.value.emplace< ast::stmt_switch::ptr > ();
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        yylhs.value.emplace< ast::stmt_wait::ptr > ();
        break;

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        yylhs.value.emplace< ast::stmt_waitframe::ptr > ();
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        yylhs.value.emplace< ast::stmt_waittill::ptr > ();
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        yylhs.value.emplace< ast::stmt_waittillframeend::ptr > ();
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        yylhs.value.emplace< ast::stmt_waittillmatch::ptr > ();
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        yylhs.value.emplace< ast::stmt_while::ptr > ();
        break;

      case symbol_kind::S_PATH: // "path"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< std::string > ();
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
  case 2: // root: program
#line 263 "parser.ypp"
              { ast = std::move(yystack_[0].value.as < ast::program::ptr > ()); }
#line 2040 "parser.cpp"
    break;

  case 3: // root: %empty
#line 264 "parser.ypp"
              { ast = std::make_unique<ast::program>(yylhs.location); }
#line 2046 "parser.cpp"
    break;

  case 4: // program: program inline
#line 269 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::move(yystack_[1].value.as < ast::program::ptr > ()); }
#line 2052 "parser.cpp"
    break;

  case 5: // program: program include
#line 271 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::move(yystack_[1].value.as < ast::program::ptr > ()); yylhs.value.as < ast::program::ptr > ()->includes.push_back(std::move(yystack_[0].value.as < ast::include::ptr > ())); }
#line 2058 "parser.cpp"
    break;

  case 6: // program: program declaration
#line 273 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::move(yystack_[1].value.as < ast::program::ptr > ()); yylhs.value.as < ast::program::ptr > ()->declarations.push_back(std::move(yystack_[0].value.as < ast::decl > ())); }
#line 2064 "parser.cpp"
    break;

  case 7: // program: inline
#line 275 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::make_unique<ast::program>(yylhs.location); }
#line 2070 "parser.cpp"
    break;

  case 8: // program: include
#line 277 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::make_unique<ast::program>(yylhs.location); yylhs.value.as < ast::program::ptr > ()->includes.push_back(std::move(yystack_[0].value.as < ast::include::ptr > ())); }
#line 2076 "parser.cpp"
    break;

  case 9: // program: declaration
#line 279 "parser.ypp"
        { yylhs.value.as < ast::program::ptr > () = std::make_unique<ast::program>(yylhs.location); yylhs.value.as < ast::program::ptr > ()->declarations.push_back(std::move(yystack_[0].value.as < ast::decl > ())); }
#line 2082 "parser.cpp"
    break;

  case 10: // inline: "#inline" expr_path ";"
#line 283 "parser.ypp"
                                 { lexer.push_header(yystack_[1].value.as < ast::expr_path::ptr > ()->value); }
#line 2088 "parser.cpp"
    break;

  case 11: // include: "#include" expr_path ";"
#line 288 "parser.ypp"
        { yylhs.value.as < ast::include::ptr > () = std::make_unique<ast::include>(yylhs.location, std::move(yystack_[1].value.as < ast::expr_path::ptr > ())); }
#line 2094 "parser.cpp"
    break;

  case 12: // declaration: "/#"
#line 292 "parser.ypp"
                        { yylhs.value.as < ast::decl > ().as_dev_begin = std::make_unique<ast::decl_dev_begin>(yylhs.location); }
#line 2100 "parser.cpp"
    break;

  case 13: // declaration: "#/"
#line 293 "parser.ypp"
                        { yylhs.value.as < ast::decl > ().as_dev_end = std::make_unique<ast::decl_dev_end>(yylhs.location); }
#line 2106 "parser.cpp"
    break;

  case 14: // declaration: decl_usingtree
#line 294 "parser.ypp"
                        { yylhs.value.as < ast::decl > ().as_usingtree = std::move(yystack_[0].value.as < ast::decl_usingtree::ptr > ()); }
#line 2112 "parser.cpp"
    break;

  case 15: // declaration: decl_constant
#line 295 "parser.ypp"
                        { yylhs.value.as < ast::decl > ().as_constant = std::move(yystack_[0].value.as < ast::decl_constant::ptr > ()); }
#line 2118 "parser.cpp"
    break;

  case 16: // declaration: decl_thread
#line 296 "parser.ypp"
                        { yylhs.value.as < ast::decl > ().as_thread = std::move(yystack_[0].value.as < ast::decl_thread::ptr > ()); }
#line 2124 "parser.cpp"
    break;

  case 17: // decl_usingtree: "#using_animtree" "(" expr_string ")" ";"
#line 301 "parser.ypp"
        { lexer.ban_header(yylhs.location); yylhs.value.as < ast::decl_usingtree::ptr > () = std::make_unique<ast::decl_usingtree>(yylhs.location, std::move(yystack_[2].value.as < ast::expr_string::ptr > ())); }
#line 2130 "parser.cpp"
    break;

  case 18: // decl_constant: expr_identifier "=" expr ";"
#line 306 "parser.ypp"
        { yylhs.value.as < ast::decl_constant::ptr > () = std::make_unique<ast::decl_constant>(yylhs.location, std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2136 "parser.cpp"
    break;

  case 19: // decl_thread: expr_identifier "(" expr_parameters ")" stmt_block
#line 311 "parser.ypp"
        { lexer.ban_header(yylhs.location); yylhs.value.as < ast::decl_thread::ptr > () = std::make_unique<ast::decl_thread>(yylhs.location, std::move(yystack_[4].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[2].value.as < ast::expr_parameters::ptr > ()), std::move(yystack_[0].value.as < ast::stmt_list::ptr > ())); }
#line 2142 "parser.cpp"
    break;

  case 20: // stmt: stmt_block
#line 315 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_list = std::move(yystack_[0].value.as < ast::stmt_list::ptr > ()); }
#line 2148 "parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 316 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_call = std::move(yystack_[0].value.as < ast::stmt_call::ptr > ()); }
#line 2154 "parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 317 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_assign = std::move(yystack_[0].value.as < ast::stmt_assign::ptr > ()); }
#line 2160 "parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 318 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_endon = std::move(yystack_[0].value.as < ast::stmt_endon::ptr > ()); }
#line 2166 "parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 319 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_notify = std::move(yystack_[0].value.as < ast::stmt_notify::ptr > ()); }
#line 2172 "parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 320 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_wait = std::move(yystack_[0].value.as < ast::stmt_wait::ptr > ()); }
#line 2178 "parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 321 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_waittill = std::move(yystack_[0].value.as < ast::stmt_waittill::ptr > ()); }
#line 2184 "parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 322 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_waittillmatch = std::move(yystack_[0].value.as < ast::stmt_waittillmatch::ptr > ()); }
#line 2190 "parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 323 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_waittillframeend = std::move(yystack_[0].value.as < ast::stmt_waittillframeend::ptr > ()); }
#line 2196 "parser.cpp"
    break;

  case 29: // stmt: stmt_waitframe
#line 324 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_waitframe = std::move(yystack_[0].value.as < ast::stmt_waitframe::ptr > ()); }
#line 2202 "parser.cpp"
    break;

  case 30: // stmt: stmt_if
#line 325 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_if = std::move(yystack_[0].value.as < ast::stmt_if::ptr > ()); }
#line 2208 "parser.cpp"
    break;

  case 31: // stmt: stmt_ifelse
#line 326 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_ifelse = std::move(yystack_[0].value.as < ast::stmt_ifelse::ptr > ()); }
#line 2214 "parser.cpp"
    break;

  case 32: // stmt: stmt_while
#line 327 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_while = std::move(yystack_[0].value.as < ast::stmt_while::ptr > ()); }
#line 2220 "parser.cpp"
    break;

  case 33: // stmt: stmt_dowhile
#line 328 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_dowhile = std::move(yystack_[0].value.as < ast::stmt_dowhile::ptr > ()); }
#line 2226 "parser.cpp"
    break;

  case 34: // stmt: stmt_for
#line 329 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_for = std::move(yystack_[0].value.as < ast::stmt_for::ptr > ()); }
#line 2232 "parser.cpp"
    break;

  case 35: // stmt: stmt_foreach
#line 330 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_foreach = std::move(yystack_[0].value.as < ast::stmt_foreach::ptr > ()); }
#line 2238 "parser.cpp"
    break;

  case 36: // stmt: stmt_switch
#line 331 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_switch = std::move(yystack_[0].value.as < ast::stmt_switch::ptr > ()); }
#line 2244 "parser.cpp"
    break;

  case 37: // stmt: stmt_case
#line 332 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_case = std::move(yystack_[0].value.as < ast::stmt_case::ptr > ()); }
#line 2250 "parser.cpp"
    break;

  case 38: // stmt: stmt_default
#line 333 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_default = std::move(yystack_[0].value.as < ast::stmt_default::ptr > ()); }
#line 2256 "parser.cpp"
    break;

  case 39: // stmt: stmt_break
#line 334 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_break = std::move(yystack_[0].value.as < ast::stmt_break::ptr > ()); }
#line 2262 "parser.cpp"
    break;

  case 40: // stmt: stmt_continue
#line 335 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_continue = std::move(yystack_[0].value.as < ast::stmt_continue::ptr > ()); }
#line 2268 "parser.cpp"
    break;

  case 41: // stmt: stmt_return
#line 336 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_return = std::move(yystack_[0].value.as < ast::stmt_return::ptr > ()); }
#line 2274 "parser.cpp"
    break;

  case 42: // stmt: stmt_breakpoint
#line 337 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_breakpoint = std::move(yystack_[0].value.as < ast::stmt_breakpoint::ptr > ()); }
#line 2280 "parser.cpp"
    break;

  case 43: // stmt: stmt_prof_begin
#line 338 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_prof_begin = std::move(yystack_[0].value.as < ast::stmt_prof_begin::ptr > ()); }
#line 2286 "parser.cpp"
    break;

  case 44: // stmt: stmt_prof_end
#line 339 "parser.ypp"
                             { yylhs.value.as < ast::stmt > ().as_prof_end = std::move(yystack_[0].value.as < ast::stmt_prof_end::ptr > ()); }
#line 2292 "parser.cpp"
    break;

  case 45: // stmt_or_dev: stmt
#line 343 "parser.ypp"
               { yylhs.value.as < ast::stmt > () = std::move(yystack_[0].value.as < ast::stmt > ()); }
#line 2298 "parser.cpp"
    break;

  case 46: // stmt_or_dev: stmt_dev
#line 344 "parser.ypp"
               { yylhs.value.as < ast::stmt > ().as_dev = std::move(yystack_[0].value.as < ast::stmt_dev::ptr > ()); }
#line 2304 "parser.cpp"
    break;

  case 47: // stmt_list: stmt_list stmt
#line 349 "parser.ypp"
        { yylhs.value.as < ast::stmt_list::ptr > () = std::move(yystack_[1].value.as < ast::stmt_list::ptr > ()); yylhs.value.as < ast::stmt_list::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2310 "parser.cpp"
    break;

  case 48: // stmt_list: stmt
#line 351 "parser.ypp"
        { yylhs.value.as < ast::stmt_list::ptr > () = std::make_unique<ast::stmt_list>(yylhs.location); yylhs.value.as < ast::stmt_list::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2316 "parser.cpp"
    break;

  case 49: // stmt_or_dev_list: stmt_or_dev_list stmt_or_dev
#line 356 "parser.ypp"
        { yylhs.value.as < ast::stmt_list::ptr > () = std::move(yystack_[1].value.as < ast::stmt_list::ptr > ()); yylhs.value.as < ast::stmt_list::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2322 "parser.cpp"
    break;

  case 50: // stmt_or_dev_list: stmt_or_dev
#line 358 "parser.ypp"
        { yylhs.value.as < ast::stmt_list::ptr > () = std::make_unique<ast::stmt_list>(yylhs.location); yylhs.value.as < ast::stmt_list::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2328 "parser.cpp"
    break;

  case 51: // stmt_dev: "/#" stmt_list "#/"
#line 362 "parser.ypp"
                                { yylhs.value.as < ast::stmt_dev::ptr > () = std::make_unique<ast::stmt_dev>(yylhs.location, std::move(yystack_[1].value.as < ast::stmt_list::ptr > ())); }
#line 2334 "parser.cpp"
    break;

  case 52: // stmt_dev: "/#" "#/"
#line 363 "parser.ypp"
                      { yylhs.value.as < ast::stmt_dev::ptr > () = std::make_unique<ast::stmt_dev>(yylhs.location, std::make_unique<ast::stmt_list>(yylhs.location)); }
#line 2340 "parser.cpp"
    break;

  case 53: // stmt_block: "{" stmt_or_dev_list "}"
#line 367 "parser.ypp"
                                     { yylhs.value.as < ast::stmt_list::ptr > () = std::move(yystack_[1].value.as < ast::stmt_list::ptr > ()); }
#line 2346 "parser.cpp"
    break;

  case 54: // stmt_block: "{" "}"
#line 368 "parser.ypp"
                    { yylhs.value.as < ast::stmt_list::ptr > () = std::make_unique<ast::stmt_list>(yylhs.location); }
#line 2352 "parser.cpp"
    break;

  case 55: // stmt_expr: expr_assign
#line 373 "parser.ypp"
        { yylhs.value.as < ast::stmt_expr::ptr > () = std::make_unique<ast::stmt_expr>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2358 "parser.cpp"
    break;

  case 56: // stmt_expr: expr_increment
#line 375 "parser.ypp"
        { yylhs.value.as < ast::stmt_expr::ptr > () = std::make_unique<ast::stmt_expr>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2364 "parser.cpp"
    break;

  case 57: // stmt_expr: expr_decrement
#line 377 "parser.ypp"
        { yylhs.value.as < ast::stmt_expr::ptr > () = std::make_unique<ast::stmt_expr>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2370 "parser.cpp"
    break;

  case 58: // stmt_expr: %empty
#line 379 "parser.ypp"
        { yylhs.value.as < ast::stmt_expr::ptr > () = std::make_unique<ast::stmt_expr>(yylhs.location, std::make_unique<ast::node>(yylhs.location)); }
#line 2376 "parser.cpp"
    break;

  case 59: // stmt_call: expr_call ";"
#line 384 "parser.ypp"
        { yylhs.value.as < ast::stmt_call::ptr > () = std::make_unique<ast::stmt_call>(yylhs.location, ast::expr(std::move(yystack_[1].value.as < ast::expr_call::ptr > ()))); }
#line 2382 "parser.cpp"
    break;

  case 60: // stmt_call: expr_method ";"
#line 386 "parser.ypp"
        { yylhs.value.as < ast::stmt_call::ptr > () = std::make_unique<ast::stmt_call>(yylhs.location, ast::expr(std::move(yystack_[1].value.as < ast::expr_method::ptr > ()))); }
#line 2388 "parser.cpp"
    break;

  case 61: // stmt_assign: expr_assign ";"
#line 391 "parser.ypp"
        { yylhs.value.as < ast::stmt_assign::ptr > () = std::make_unique<ast::stmt_assign>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2394 "parser.cpp"
    break;

  case 62: // stmt_assign: expr_increment ";"
#line 393 "parser.ypp"
        { yylhs.value.as < ast::stmt_assign::ptr > () = std::make_unique<ast::stmt_assign>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2400 "parser.cpp"
    break;

  case 63: // stmt_assign: expr_decrement ";"
#line 395 "parser.ypp"
        { yylhs.value.as < ast::stmt_assign::ptr > () = std::make_unique<ast::stmt_assign>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2406 "parser.cpp"
    break;

  case 64: // stmt_endon: expr_object "endon" "(" expr ")" ";"
#line 400 "parser.ypp"
        { yylhs.value.as < ast::stmt_endon::ptr > () = std::make_unique<ast::stmt_endon>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr > ())); }
#line 2412 "parser.cpp"
    break;

  case 65: // stmt_notify: expr_object "notify" "(" expr "," expr_arguments_no_empty ")" ";"
#line 405 "parser.ypp"
        { yylhs.value.as < ast::stmt_notify::ptr > () = std::make_unique<ast::stmt_notify>(yylhs.location, std::move(yystack_[7].value.as < ast::expr > ()), std::move(yystack_[4].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ())); }
#line 2418 "parser.cpp"
    break;

  case 66: // stmt_notify: expr_object "notify" "(" expr ")" ";"
#line 407 "parser.ypp"
        { yylhs.value.as < ast::stmt_notify::ptr > () = std::make_unique<ast::stmt_notify>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr > ()), std::make_unique<ast::expr_arguments>(yylhs.location)); }
#line 2424 "parser.cpp"
    break;

  case 67: // stmt_wait: "wait" expr ";"
#line 412 "parser.ypp"
        { yylhs.value.as < ast::stmt_wait::ptr > () = std::make_unique<ast::stmt_wait>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2430 "parser.cpp"
    break;

  case 68: // stmt_waittill: expr_object "waittill" "(" expr "," expr_arguments_no_empty ")" ";"
#line 417 "parser.ypp"
        { yylhs.value.as < ast::stmt_waittill::ptr > () = std::make_unique<ast::stmt_waittill>(yylhs.location, std::move(yystack_[7].value.as < ast::expr > ()), std::move(yystack_[4].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ())); }
#line 2436 "parser.cpp"
    break;

  case 69: // stmt_waittill: expr_object "waittill" "(" expr ")" ";"
#line 419 "parser.ypp"
        { yylhs.value.as < ast::stmt_waittill::ptr > () = std::make_unique<ast::stmt_waittill>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr > ()), std::make_unique<ast::expr_arguments>(yylhs.location)); }
#line 2442 "parser.cpp"
    break;

  case 70: // stmt_waittillmatch: expr_object "waittillmatch" "(" expr "," expr_arguments_no_empty ")" ";"
#line 424 "parser.ypp"
        { yylhs.value.as < ast::stmt_waittillmatch::ptr > () = std::make_unique<ast::stmt_waittillmatch>(yylhs.location, std::move(yystack_[7].value.as < ast::expr > ()), std::move(yystack_[4].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ())); }
#line 2448 "parser.cpp"
    break;

  case 71: // stmt_waittillmatch: expr_object "waittillmatch" "(" expr ")" ";"
#line 426 "parser.ypp"
        { yylhs.value.as < ast::stmt_waittillmatch::ptr > () = std::make_unique<ast::stmt_waittillmatch>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr > ()), std::make_unique<ast::expr_arguments>(yylhs.location)); }
#line 2454 "parser.cpp"
    break;

  case 72: // stmt_waittillframeend: "waittillframeend" ";"
#line 431 "parser.ypp"
        { yylhs.value.as < ast::stmt_waittillframeend::ptr > () = std::make_unique<ast::stmt_waittillframeend>(yylhs.location); }
#line 2460 "parser.cpp"
    break;

  case 73: // stmt_waitframe: "waitframe" ";"
#line 436 "parser.ypp"
        { yylhs.value.as < ast::stmt_waitframe::ptr > () = std::make_unique<ast::stmt_waitframe>(yylhs.location); }
#line 2466 "parser.cpp"
    break;

  case 74: // stmt_waitframe: "waitframe" "(" ")" ";"
#line 438 "parser.ypp"
        { yylhs.value.as < ast::stmt_waitframe::ptr > () = std::make_unique<ast::stmt_waitframe>(yylhs.location); }
#line 2472 "parser.cpp"
    break;

  case 75: // stmt_if: "if" "(" expr ")" stmt
#line 443 "parser.ypp"
        { yylhs.value.as < ast::stmt_if::ptr > () = std::make_unique<ast::stmt_if>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2478 "parser.cpp"
    break;

  case 76: // stmt_ifelse: "if" "(" expr ")" stmt "else" stmt
#line 448 "parser.ypp"
        { yylhs.value.as < ast::stmt_ifelse::ptr > () = std::make_unique<ast::stmt_ifelse>(yylhs.location, std::move(yystack_[4].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::stmt > ()), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2484 "parser.cpp"
    break;

  case 77: // stmt_while: "while" "(" expr ")" stmt
#line 453 "parser.ypp"
        { yylhs.value.as < ast::stmt_while::ptr > () = std::make_unique<ast::stmt_while>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2490 "parser.cpp"
    break;

  case 78: // stmt_dowhile: "do" stmt "while" "(" expr ")" ";"
#line 458 "parser.ypp"
        { yylhs.value.as < ast::stmt_dowhile::ptr > () = std::make_unique<ast::stmt_dowhile>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[5].value.as < ast::stmt > ())); }
#line 2496 "parser.cpp"
    break;

  case 79: // stmt_for: "for" "(" stmt_expr ";" expr_or_empty ";" stmt_expr ")" stmt
#line 463 "parser.ypp"
        { yylhs.value.as < ast::stmt_for::ptr > () = std::make_unique<ast::stmt_for>(yylhs.location, ast::stmt(std::move(yystack_[6].value.as < ast::stmt_expr::ptr > ())), std::move(yystack_[4].value.as < ast::expr > ()), ast::stmt(std::move(yystack_[2].value.as < ast::stmt_expr::ptr > ())), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2502 "parser.cpp"
    break;

  case 80: // stmt_foreach: "foreach" "(" expr_identifier "in" expr ")" stmt
#line 468 "parser.ypp"
        { yylhs.value.as < ast::stmt_foreach::ptr > () = std::make_unique<ast::stmt_foreach>(yylhs.location, ast::expr(std::move(yystack_[4].value.as < ast::expr_identifier::ptr > ())), std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2508 "parser.cpp"
    break;

  case 81: // stmt_foreach: "foreach" "(" expr_identifier "," expr_identifier "in" expr ")" stmt
#line 470 "parser.ypp"
        { yylhs.value.as < ast::stmt_foreach::ptr > () = std::make_unique<ast::stmt_foreach>(yylhs.location, ast::expr(std::move(yystack_[6].value.as < ast::expr_identifier::ptr > ())), ast::expr(std::move(yystack_[4].value.as < ast::expr_identifier::ptr > ())), std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::stmt > ())); }
#line 2514 "parser.cpp"
    break;

  case 82: // stmt_switch: "switch" "(" expr ")" stmt_block
#line 475 "parser.ypp"
        { yylhs.value.as < ast::stmt_switch::ptr > () = std::make_unique<ast::stmt_switch>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::stmt_list::ptr > ())); }
#line 2520 "parser.cpp"
    break;

  case 83: // stmt_case: "case" expr_integer ":"
#line 480 "parser.ypp"
        { yylhs.value.as < ast::stmt_case::ptr > () = std::make_unique<ast::stmt_case>(yylhs.location, ast::expr(std::move(yystack_[1].value.as < ast::expr_integer::ptr > ())), std::make_unique<ast::stmt_list>(yylhs.location)); }
#line 2526 "parser.cpp"
    break;

  case 84: // stmt_case: "case" expr_string ":"
#line 482 "parser.ypp"
        { yylhs.value.as < ast::stmt_case::ptr > () = std::make_unique<ast::stmt_case>(yylhs.location, ast::expr(std::move(yystack_[1].value.as < ast::expr_string::ptr > ())), std::make_unique<ast::stmt_list>(yylhs.location)); }
#line 2532 "parser.cpp"
    break;

  case 85: // stmt_default: "default" ":"
#line 487 "parser.ypp"
        { yylhs.value.as < ast::stmt_default::ptr > () = std::make_unique<ast::stmt_default>(yylhs.location, std::make_unique<ast::stmt_list>(yylhs.location)); }
#line 2538 "parser.cpp"
    break;

  case 86: // stmt_break: "break" ";"
#line 492 "parser.ypp"
        { yylhs.value.as < ast::stmt_break::ptr > () = std::make_unique<ast::stmt_break>(yylhs.location); }
#line 2544 "parser.cpp"
    break;

  case 87: // stmt_continue: "continue" ";"
#line 497 "parser.ypp"
        { yylhs.value.as < ast::stmt_continue::ptr > () = std::make_unique<ast::stmt_continue>(yylhs.location); }
#line 2550 "parser.cpp"
    break;

  case 88: // stmt_return: "return" expr ";"
#line 502 "parser.ypp"
        { yylhs.value.as < ast::stmt_return::ptr > () = std::make_unique<ast::stmt_return>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 2556 "parser.cpp"
    break;

  case 89: // stmt_return: "return" ";"
#line 504 "parser.ypp"
        { yylhs.value.as < ast::stmt_return::ptr > () = std::make_unique<ast::stmt_return>(yylhs.location, std::make_unique<ast::node>(yylhs.location)); }
#line 2562 "parser.cpp"
    break;

  case 90: // stmt_breakpoint: "breakpoint" ";"
#line 509 "parser.ypp"
        { yylhs.value.as < ast::stmt_breakpoint::ptr > () = std::make_unique<ast::stmt_breakpoint>(yylhs.location); }
#line 2568 "parser.cpp"
    break;

  case 91: // stmt_prof_begin: "prof_begin" "(" expr_arguments ")" ";"
#line 514 "parser.ypp"
        { yylhs.value.as < ast::stmt_prof_begin::ptr > () = std::make_unique<ast::stmt_prof_begin>(yylhs.location, std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ())); }
#line 2574 "parser.cpp"
    break;

  case 92: // stmt_prof_end: "prof_end" "(" expr_arguments ")" ";"
#line 519 "parser.ypp"
        { yylhs.value.as < ast::stmt_prof_end::ptr > () = std::make_unique<ast::stmt_prof_end>(yylhs.location, std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ())); }
#line 2580 "parser.cpp"
    break;

  case 93: // expr: expr_ternary
#line 523 "parser.ypp"
                     { yylhs.value.as < ast::expr > () = std::move(yystack_[0].value.as < ast::expr > ()); }
#line 2586 "parser.cpp"
    break;

  case 94: // expr: expr_binary
#line 524 "parser.ypp"
                     { yylhs.value.as < ast::expr > () = std::move(yystack_[0].value.as < ast::expr > ()); }
#line 2592 "parser.cpp"
    break;

  case 95: // expr: expr_primitive
#line 525 "parser.ypp"
                     { yylhs.value.as < ast::expr > () = std::move(yystack_[0].value.as < ast::expr > ()); }
#line 2598 "parser.cpp"
    break;

  case 96: // expr_or_empty: expr
#line 529 "parser.ypp"
                     { yylhs.value.as < ast::expr > () = std::move(yystack_[0].value.as < ast::expr > ()); }
#line 2604 "parser.cpp"
    break;

  case 97: // expr_or_empty: %empty
#line 530 "parser.ypp"
                     { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::node>(yylhs.location); }
#line 2610 "parser.cpp"
    break;

  case 98: // expr_assign: expr_tuple "=" expr
#line 535 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_equal>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2616 "parser.cpp"
    break;

  case 99: // expr_assign: expr_object "=" expr
#line 537 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_equal>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2622 "parser.cpp"
    break;

  case 100: // expr_assign: expr_object "|=" expr
#line 539 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2628 "parser.cpp"
    break;

  case 101: // expr_assign: expr_object "&=" expr
#line 541 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2634 "parser.cpp"
    break;

  case 102: // expr_assign: expr_object "^=" expr
#line 543 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2640 "parser.cpp"
    break;

  case 103: // expr_assign: expr_object "<<=" expr
#line 545 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_shift_left>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()),std::move( yystack_[0].value.as < ast::expr > ())); }
#line 2646 "parser.cpp"
    break;

  case 104: // expr_assign: expr_object ">>=" expr
#line 547 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_shift_right>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2652 "parser.cpp"
    break;

  case 105: // expr_assign: expr_object "+=" expr
#line 549 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_add>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2658 "parser.cpp"
    break;

  case 106: // expr_assign: expr_object "-=" expr
#line 551 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_sub>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2664 "parser.cpp"
    break;

  case 107: // expr_assign: expr_object "*=" expr
#line 553 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_mul>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2670 "parser.cpp"
    break;

  case 108: // expr_assign: expr_object "/=" expr
#line 555 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_div>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2676 "parser.cpp"
    break;

  case 109: // expr_assign: expr_object "%=" expr
#line 557 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_assign_mod>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2682 "parser.cpp"
    break;

  case 110: // expr_increment: "++" expr_object
#line 562 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_increment>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ()), true); }
#line 2688 "parser.cpp"
    break;

  case 111: // expr_increment: expr_object "++"
#line 564 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_increment>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ()), false); }
#line 2694 "parser.cpp"
    break;

  case 112: // expr_decrement: "--" expr_object
#line 569 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_decrement>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ()), true); }
#line 2700 "parser.cpp"
    break;

  case 113: // expr_decrement: expr_object "--"
#line 571 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_decrement>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ()), false); }
#line 2706 "parser.cpp"
    break;

  case 114: // expr_ternary: expr "?" expr ":" expr
#line 576 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_ternary>(yylhs.location, std::move(yystack_[4].value.as < ast::expr > ()), std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2712 "parser.cpp"
    break;

  case 115: // expr_binary: expr "||" expr
#line 581 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_or>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2718 "parser.cpp"
    break;

  case 116: // expr_binary: expr "&&" expr
#line 583 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_and>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2724 "parser.cpp"
    break;

  case 117: // expr_binary: expr "==" expr
#line 585 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_equality>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2730 "parser.cpp"
    break;

  case 118: // expr_binary: expr "!=" expr
#line 587 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_inequality>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2736 "parser.cpp"
    break;

  case 119: // expr_binary: expr "<=" expr
#line 589 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_less_equal>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2742 "parser.cpp"
    break;

  case 120: // expr_binary: expr ">=" expr
#line 591 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_greater_equal>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2748 "parser.cpp"
    break;

  case 121: // expr_binary: expr "<" expr
#line 593 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_less>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2754 "parser.cpp"
    break;

  case 122: // expr_binary: expr ">" expr
#line 595 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_greater>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2760 "parser.cpp"
    break;

  case 123: // expr_binary: expr "|" expr
#line 597 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2766 "parser.cpp"
    break;

  case 124: // expr_binary: expr "&" expr
#line 599 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2772 "parser.cpp"
    break;

  case 125: // expr_binary: expr "^" expr
#line 601 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2778 "parser.cpp"
    break;

  case 126: // expr_binary: expr "<<" expr
#line 603 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_shift_left>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2784 "parser.cpp"
    break;

  case 127: // expr_binary: expr ">>" expr
#line 605 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_shift_right>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2790 "parser.cpp"
    break;

  case 128: // expr_binary: expr "+" expr
#line 607 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_add>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2796 "parser.cpp"
    break;

  case 129: // expr_binary: expr "-" expr
#line 609 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_sub>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2802 "parser.cpp"
    break;

  case 130: // expr_binary: expr "*" expr
#line 611 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_mul>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2808 "parser.cpp"
    break;

  case 131: // expr_binary: expr "/" expr
#line 613 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_div>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2814 "parser.cpp"
    break;

  case 132: // expr_binary: expr "%" expr
#line 615 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::make_unique<ast::expr_mod>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2820 "parser.cpp"
    break;

  case 133: // expr_primitive: expr_complement
#line 619 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_complement::ptr > ()); }
#line 2826 "parser.cpp"
    break;

  case 134: // expr_primitive: expr_negate
#line 620 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_negate::ptr > ()); }
#line 2832 "parser.cpp"
    break;

  case 135: // expr_primitive: expr_not
#line 621 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_not::ptr > ()); }
#line 2838 "parser.cpp"
    break;

  case 136: // expr_primitive: expr_call
#line 622 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_call::ptr > ()); }
#line 2844 "parser.cpp"
    break;

  case 137: // expr_primitive: expr_method
#line 623 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_method::ptr > ()); }
#line 2850 "parser.cpp"
    break;

  case 138: // expr_primitive: expr_add_array
#line 624 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_add_array::ptr > ()); }
#line 2856 "parser.cpp"
    break;

  case 139: // expr_primitive: expr_reference
#line 625 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_reference::ptr > ()); }
#line 2862 "parser.cpp"
    break;

  case 140: // expr_primitive: expr_array
#line 626 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_array::ptr > ()); }
#line 2868 "parser.cpp"
    break;

  case 141: // expr_primitive: expr_field
#line 627 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_field::ptr > ()); }
#line 2874 "parser.cpp"
    break;

  case 142: // expr_primitive: expr_size
#line 628 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_size::ptr > ()); }
#line 2880 "parser.cpp"
    break;

  case 143: // expr_primitive: expr_paren
#line 629 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_paren::ptr > ()); }
#line 2886 "parser.cpp"
    break;

  case 144: // expr_primitive: expr_thisthread
#line 630 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_thisthread::ptr > ()); }
#line 2892 "parser.cpp"
    break;

  case 145: // expr_primitive: expr_empty_array
#line 631 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_empty_array::ptr > ()); }
#line 2898 "parser.cpp"
    break;

  case 146: // expr_primitive: expr_undefined
#line 632 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_undefined::ptr > ()); }
#line 2904 "parser.cpp"
    break;

  case 147: // expr_primitive: expr_game
#line 633 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_game::ptr > ()); }
#line 2910 "parser.cpp"
    break;

  case 148: // expr_primitive: expr_self
#line 634 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_self::ptr > ()); }
#line 2916 "parser.cpp"
    break;

  case 149: // expr_primitive: expr_anim
#line 635 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_anim::ptr > ()); }
#line 2922 "parser.cpp"
    break;

  case 150: // expr_primitive: expr_level
#line 636 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_level::ptr > ()); }
#line 2928 "parser.cpp"
    break;

  case 151: // expr_primitive: expr_animation
#line 637 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_animation::ptr > ()); }
#line 2934 "parser.cpp"
    break;

  case 152: // expr_primitive: expr_animtree
#line 638 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_animtree::ptr > ()); }
#line 2940 "parser.cpp"
    break;

  case 153: // expr_primitive: expr_identifier
#line 639 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ()); }
#line 2946 "parser.cpp"
    break;

  case 154: // expr_primitive: expr_istring
#line 640 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_istring::ptr > ()); }
#line 2952 "parser.cpp"
    break;

  case 155: // expr_primitive: expr_string
#line 641 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_string::ptr > ()); }
#line 2958 "parser.cpp"
    break;

  case 156: // expr_primitive: expr_vector
#line 642 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_vector::ptr > ()); }
#line 2964 "parser.cpp"
    break;

  case 157: // expr_primitive: expr_float
#line 643 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_float::ptr > ()); }
#line 2970 "parser.cpp"
    break;

  case 158: // expr_primitive: expr_integer
#line 644 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_integer::ptr > ()); }
#line 2976 "parser.cpp"
    break;

  case 159: // expr_primitive: expr_false
#line 645 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_false::ptr > ()); }
#line 2982 "parser.cpp"
    break;

  case 160: // expr_primitive: expr_true
#line 646 "parser.ypp"
                            { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_true::ptr > ()); }
#line 2988 "parser.cpp"
    break;

  case 161: // expr_complement: "~" expr
#line 651 "parser.ypp"
        { yylhs.value.as < ast::expr_complement::ptr > () = std::make_unique<ast::expr_complement>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ())); }
#line 2994 "parser.cpp"
    break;

  case 162: // expr_negate: "-" expr_identifier
#line 656 "parser.ypp"
        { yylhs.value.as < ast::expr_negate::ptr > () = std::make_unique<ast::expr_negate>(yylhs.location, ast::expr(std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ()))); }
#line 3000 "parser.cpp"
    break;

  case 163: // expr_negate: "-" expr_paren
#line 658 "parser.ypp"
        { yylhs.value.as < ast::expr_negate::ptr > () = std::make_unique<ast::expr_negate>(yylhs.location, ast::expr(std::move(yystack_[0].value.as < ast::expr_paren::ptr > ()))); }
#line 3006 "parser.cpp"
    break;

  case 164: // expr_negate: "-" expr_array
#line 660 "parser.ypp"
        { yylhs.value.as < ast::expr_negate::ptr > () = std::make_unique<ast::expr_negate>(yylhs.location, ast::expr(std::move(yystack_[0].value.as < ast::expr_array::ptr > ()))); }
#line 3012 "parser.cpp"
    break;

  case 165: // expr_negate: "-" expr_field
#line 662 "parser.ypp"
        { yylhs.value.as < ast::expr_negate::ptr > () = std::make_unique<ast::expr_negate>(yylhs.location, ast::expr(std::move(yystack_[0].value.as < ast::expr_field::ptr > ()))); }
#line 3018 "parser.cpp"
    break;

  case 166: // expr_not: "!" expr
#line 667 "parser.ypp"
        { yylhs.value.as < ast::expr_not::ptr > () = std::make_unique<ast::expr_not>(yylhs.location, std::move(yystack_[0].value.as < ast::expr > ())); }
#line 3024 "parser.cpp"
    break;

  case 167: // expr_call: expr_function
#line 671 "parser.ypp"
                                   { yylhs.value.as < ast::expr_call::ptr > () = std::make_unique<ast::expr_call>(yylhs.location, std::move(yystack_[0].value.as < ast::call > ())); }
#line 3030 "parser.cpp"
    break;

  case 168: // expr_call: expr_pointer
#line 672 "parser.ypp"
                                   { yylhs.value.as < ast::expr_call::ptr > () = std::make_unique<ast::expr_call>(yylhs.location, std::move(yystack_[0].value.as < ast::call > ())); }
#line 3036 "parser.cpp"
    break;

  case 169: // expr_method: expr_object expr_function
#line 675 "parser.ypp"
                                   { yylhs.value.as < ast::expr_method::ptr > () = std::make_unique<ast::expr_method>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::call > ())); }
#line 3042 "parser.cpp"
    break;

  case 170: // expr_method: expr_object expr_pointer
#line 676 "parser.ypp"
                                   { yylhs.value.as < ast::expr_method::ptr > () = std::make_unique<ast::expr_method>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::call > ())); }
#line 3048 "parser.cpp"
    break;

  case 171: // expr_function: expr_identifier "(" expr_arguments ")"
#line 681 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::make_unique<ast::expr_path>(yylhs.location), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::normal); }
#line 3054 "parser.cpp"
    break;

  case 172: // expr_function: expr_path "::" expr_identifier "(" expr_arguments ")"
#line 683 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::move(yystack_[5].value.as < ast::expr_path::ptr > ()), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::normal); }
#line 3060 "parser.cpp"
    break;

  case 173: // expr_function: "thread" expr_identifier "(" expr_arguments ")"
#line 685 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::make_unique<ast::expr_path>(yylhs.location), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::thread); }
#line 3066 "parser.cpp"
    break;

  case 174: // expr_function: "thread" expr_path "::" expr_identifier "(" expr_arguments ")"
#line 687 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::move(yystack_[5].value.as < ast::expr_path::ptr > ()), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::thread); }
#line 3072 "parser.cpp"
    break;

  case 175: // expr_function: "childthread" expr_identifier "(" expr_arguments ")"
#line 689 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::make_unique<ast::expr_path>(yylhs.location), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::childthread); }
#line 3078 "parser.cpp"
    break;

  case 176: // expr_function: "childthread" expr_path "::" expr_identifier "(" expr_arguments ")"
#line 691 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_function = std::make_unique<ast::expr_function>(yylhs.location, std::move(yystack_[5].value.as < ast::expr_path::ptr > ()), std::move(yystack_[3].value.as < ast::expr_identifier::ptr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::childthread); }
#line 3084 "parser.cpp"
    break;

  case 177: // expr_pointer: "[" "[" expr "]" "]" "(" expr_arguments ")"
#line 696 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_pointer = std::make_unique<ast::expr_pointer>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::normal); }
#line 3090 "parser.cpp"
    break;

  case 178: // expr_pointer: "thread" "[" "[" expr "]" "]" "(" expr_arguments ")"
#line 698 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_pointer = std::make_unique<ast::expr_pointer>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::thread); }
#line 3096 "parser.cpp"
    break;

  case 179: // expr_pointer: "childthread" "[" "[" expr "]" "]" "(" expr_arguments ")"
#line 700 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_pointer = std::make_unique<ast::expr_pointer>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::childthread); }
#line 3102 "parser.cpp"
    break;

  case 180: // expr_pointer: "call" "[" "[" expr "]" "]" "(" expr_arguments ")"
#line 702 "parser.ypp"
        { yylhs.value.as < ast::call > ().as_pointer = std::make_unique<ast::expr_pointer>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ()), ast::call::mode::builtin); }
#line 3108 "parser.cpp"
    break;

  case 181: // expr_add_array: "[" expr_arguments_no_empty "]"
#line 707 "parser.ypp"
        { yylhs.value.as < ast::expr_add_array::ptr > () = std::make_unique<ast::expr_add_array>(yylhs.location, std::move(yystack_[1].value.as < ast::expr_arguments::ptr > ())); }
#line 3114 "parser.cpp"
    break;

  case 182: // expr_parameters: expr_parameters "," expr_identifier
#line 712 "parser.ypp"
        { yylhs.value.as < ast::expr_parameters::ptr > () = std::move(yystack_[2].value.as < ast::expr_parameters::ptr > ()); yylhs.value.as < ast::expr_parameters::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ())); }
#line 3120 "parser.cpp"
    break;

  case 183: // expr_parameters: expr_identifier
#line 714 "parser.ypp"
        { yylhs.value.as < ast::expr_parameters::ptr > () = std::make_unique<ast::expr_parameters>(yylhs.location); yylhs.value.as < ast::expr_parameters::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ())); }
#line 3126 "parser.cpp"
    break;

  case 184: // expr_parameters: %empty
#line 716 "parser.ypp"
        { yylhs.value.as < ast::expr_parameters::ptr > () = std::make_unique<ast::expr_parameters>(yylhs.location); }
#line 3132 "parser.cpp"
    break;

  case 185: // expr_arguments: expr_arguments_no_empty
#line 721 "parser.ypp"
        { yylhs.value.as < ast::expr_arguments::ptr > () = std::move(yystack_[0].value.as < ast::expr_arguments::ptr > ()); }
#line 3138 "parser.cpp"
    break;

  case 186: // expr_arguments: %empty
#line 723 "parser.ypp"
        { yylhs.value.as < ast::expr_arguments::ptr > () = std::make_unique<ast::expr_arguments>(yylhs.location); }
#line 3144 "parser.cpp"
    break;

  case 187: // expr_arguments_no_empty: expr_arguments "," expr
#line 728 "parser.ypp"
        { yylhs.value.as < ast::expr_arguments::ptr > () = std::move(yystack_[2].value.as < ast::expr_arguments::ptr > ()); yylhs.value.as < ast::expr_arguments::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr > ())); }
#line 3150 "parser.cpp"
    break;

  case 188: // expr_arguments_no_empty: expr
#line 730 "parser.ypp"
        { yylhs.value.as < ast::expr_arguments::ptr > () = std::make_unique<ast::expr_arguments>(yylhs.location); yylhs.value.as < ast::expr_arguments::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr > ())); }
#line 3156 "parser.cpp"
    break;

  case 189: // expr_reference: "::" expr_identifier
#line 735 "parser.ypp"
        { yylhs.value.as < ast::expr_reference::ptr > () = std::make_unique<ast::expr_reference>(yylhs.location, std::make_unique<ast::expr_path>(yylhs.location), std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ())); }
#line 3162 "parser.cpp"
    break;

  case 190: // expr_reference: expr_path "::" expr_identifier
#line 737 "parser.ypp"
        { yylhs.value.as < ast::expr_reference::ptr > () = std::make_unique<ast::expr_reference>(yylhs.location, std::move(yystack_[2].value.as < ast::expr_path::ptr > ()), std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ())); }
#line 3168 "parser.cpp"
    break;

  case 191: // expr_tuple: "[" expr_tuple_arguments "]"
#line 742 "parser.ypp"
        { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[1].value.as < ast::expr_tuple::ptr > ()); }
#line 3174 "parser.cpp"
    break;

  case 192: // expr_tuple_arguments: expr_tuple_arguments "," expr_tuple_types
#line 747 "parser.ypp"
        { yylhs.value.as < ast::expr_tuple::ptr > () = std::move(yystack_[2].value.as < ast::expr_tuple::ptr > ()); yylhs.value.as < ast::expr_tuple::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr > ())); }
#line 3180 "parser.cpp"
    break;

  case 193: // expr_tuple_arguments: expr_tuple_types
#line 749 "parser.ypp"
        { yylhs.value.as < ast::expr_tuple::ptr > () = std::make_unique<ast::expr_tuple>(yylhs.location); yylhs.value.as < ast::expr_tuple::ptr > ()->list.push_back(std::move(yystack_[0].value.as < ast::expr > ())); }
#line 3186 "parser.cpp"
    break;

  case 194: // expr_tuple_types: expr_array
#line 753 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_array::ptr > ()); }
#line 3192 "parser.cpp"
    break;

  case 195: // expr_tuple_types: expr_field
#line 754 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_field::ptr > ()); }
#line 3198 "parser.cpp"
    break;

  case 196: // expr_tuple_types: expr_identifier
#line 755 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ()); }
#line 3204 "parser.cpp"
    break;

  case 197: // expr_array: expr_object "[" expr "]"
#line 760 "parser.ypp"
        { yylhs.value.as < ast::expr_array::ptr > () = std::make_unique<ast::expr_array>(yylhs.location, std::move(yystack_[3].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr > ())); }
#line 3210 "parser.cpp"
    break;

  case 198: // expr_field: expr_object "." expr_identifier_nosize
#line 765 "parser.ypp"
        { yylhs.value.as < ast::expr_field::ptr > () = std::make_unique<ast::expr_field>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ()), std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ())); }
#line 3216 "parser.cpp"
    break;

  case 199: // expr_size: expr_object "." "size"
#line 770 "parser.ypp"
        { yylhs.value.as < ast::expr_size::ptr > () = std::make_unique<ast::expr_size>(yylhs.location, std::move(yystack_[2].value.as < ast::expr > ())); }
#line 3222 "parser.cpp"
    break;

  case 200: // expr_paren: "(" expr ")"
#line 775 "parser.ypp"
        { yylhs.value.as < ast::expr_paren::ptr > () = std::make_unique<ast::expr_paren>(yylhs.location, std::move(yystack_[1].value.as < ast::expr > ())); }
#line 3228 "parser.cpp"
    break;

  case 201: // expr_object: expr_call
#line 779 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_call::ptr > ()); }
#line 3234 "parser.cpp"
    break;

  case 202: // expr_object: expr_method
#line 780 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_method::ptr > ()); }
#line 3240 "parser.cpp"
    break;

  case 203: // expr_object: expr_array
#line 781 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_array::ptr > ()); }
#line 3246 "parser.cpp"
    break;

  case 204: // expr_object: expr_field
#line 782 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_field::ptr > ()); }
#line 3252 "parser.cpp"
    break;

  case 205: // expr_object: expr_game
#line 783 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_game::ptr > ()); }
#line 3258 "parser.cpp"
    break;

  case 206: // expr_object: expr_self
#line 784 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_self::ptr > ()); }
#line 3264 "parser.cpp"
    break;

  case 207: // expr_object: expr_anim
#line 785 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_anim::ptr > ()); }
#line 3270 "parser.cpp"
    break;

  case 208: // expr_object: expr_level
#line 786 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_level::ptr > ()); }
#line 3276 "parser.cpp"
    break;

  case 209: // expr_object: expr_identifier
#line 787 "parser.ypp"
                      { yylhs.value.as < ast::expr > ().as_node = std::move(yystack_[0].value.as < ast::expr_identifier::ptr > ()); }
#line 3282 "parser.cpp"
    break;

  case 210: // expr_thisthread: "thisthread"
#line 792 "parser.ypp"
        { yylhs.value.as < ast::expr_thisthread::ptr > () = std::make_unique<ast::expr_thisthread>(yylhs.location); }
#line 3288 "parser.cpp"
    break;

  case 211: // expr_empty_array: "[" "]"
#line 797 "parser.ypp"
        { yylhs.value.as < ast::expr_empty_array::ptr > () = std::make_unique<ast::expr_empty_array>(yylhs.location); }
#line 3294 "parser.cpp"
    break;

  case 212: // expr_undefined: "undefined"
#line 802 "parser.ypp"
        { yylhs.value.as < ast::expr_undefined::ptr > () = std::make_unique<ast::expr_undefined>(yylhs.location); }
#line 3300 "parser.cpp"
    break;

  case 213: // expr_game: "game"
#line 807 "parser.ypp"
        { yylhs.value.as < ast::expr_game::ptr > () = std::make_unique<ast::expr_game>(yylhs.location); }
#line 3306 "parser.cpp"
    break;

  case 214: // expr_self: "self"
#line 812 "parser.ypp"
        { yylhs.value.as < ast::expr_self::ptr > () = std::make_unique<ast::expr_self>(yylhs.location); }
#line 3312 "parser.cpp"
    break;

  case 215: // expr_anim: "anim"
#line 817 "parser.ypp"
        { yylhs.value.as < ast::expr_anim::ptr > () = std::make_unique<ast::expr_anim>(yylhs.location); }
#line 3318 "parser.cpp"
    break;

  case 216: // expr_level: "level"
#line 822 "parser.ypp"
        { yylhs.value.as < ast::expr_level::ptr > () = std::make_unique<ast::expr_level>(yylhs.location); }
#line 3324 "parser.cpp"
    break;

  case 217: // expr_animation: "%" "identifier"
#line 827 "parser.ypp"
        { yylhs.value.as < ast::expr_animation::ptr > () = std::make_unique<ast::expr_animation>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3330 "parser.cpp"
    break;

  case 218: // expr_animtree: "#animtree"
#line 832 "parser.ypp"
        { yylhs.value.as < ast::expr_animtree::ptr > () = std::make_unique<ast::expr_animtree>(yylhs.location); }
#line 3336 "parser.cpp"
    break;

  case 219: // expr_identifier_nosize: "identifier"
#line 837 "parser.ypp"
        { yylhs.value.as < ast::expr_identifier::ptr > () = std::make_unique<ast::expr_identifier>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3342 "parser.cpp"
    break;

  case 220: // expr_identifier: "identifier"
#line 842 "parser.ypp"
        { yylhs.value.as < ast::expr_identifier::ptr > () = std::make_unique<ast::expr_identifier>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3348 "parser.cpp"
    break;

  case 221: // expr_identifier: "size"
#line 844 "parser.ypp"
        { yylhs.value.as < ast::expr_identifier::ptr > () = std::make_unique<ast::expr_identifier>(yylhs.location, "size"); }
#line 3354 "parser.cpp"
    break;

  case 222: // expr_path: "identifier"
#line 849 "parser.ypp"
        { yylhs.value.as < ast::expr_path::ptr > () = std::make_unique<ast::expr_path>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3360 "parser.cpp"
    break;

  case 223: // expr_path: "path"
#line 851 "parser.ypp"
        { yylhs.value.as < ast::expr_path::ptr > () = std::make_unique<ast::expr_path>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3366 "parser.cpp"
    break;

  case 224: // expr_istring: "localized string"
#line 856 "parser.ypp"
        { yylhs.value.as < ast::expr_istring::ptr > () = std::make_unique<ast::expr_istring>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3372 "parser.cpp"
    break;

  case 225: // expr_string: "string literal"
#line 861 "parser.ypp"
        { yylhs.value.as < ast::expr_string::ptr > () = std::make_unique<ast::expr_string>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3378 "parser.cpp"
    break;

  case 226: // expr_vector: "(" expr "," expr "," expr ")"
#line 866 "parser.ypp"
        { yylhs.value.as < ast::expr_vector::ptr > () = std::make_unique<ast::expr_vector>(yylhs.location, std::move(yystack_[5].value.as < ast::expr > ()), std::move(yystack_[3].value.as < ast::expr > ()), std::move(yystack_[1].value.as < ast::expr > ())); }
#line 3384 "parser.cpp"
    break;

  case 227: // expr_float: "-" "float"
#line 871 "parser.ypp"
        { yylhs.value.as < ast::expr_float::ptr > () = std::make_unique<ast::expr_float>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 3390 "parser.cpp"
    break;

  case 228: // expr_float: "float"
#line 873 "parser.ypp"
        { yylhs.value.as < ast::expr_float::ptr > () = std::make_unique<ast::expr_float>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3396 "parser.cpp"
    break;

  case 229: // expr_integer: "-" "integer"
#line 878 "parser.ypp"
        { yylhs.value.as < ast::expr_integer::ptr > () = std::make_unique<ast::expr_integer>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 3402 "parser.cpp"
    break;

  case 230: // expr_integer: "integer"
#line 880 "parser.ypp"
        { yylhs.value.as < ast::expr_integer::ptr > () = std::make_unique<ast::expr_integer>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 3408 "parser.cpp"
    break;

  case 231: // expr_false: "false"
#line 885 "parser.ypp"
        { yylhs.value.as < ast::expr_false::ptr > () = std::make_unique<ast::expr_false>(yylhs.location); }
#line 3414 "parser.cpp"
    break;

  case 232: // expr_true: "true"
#line 890 "parser.ypp"
        { yylhs.value.as < ast::expr_true::ptr > () = std::make_unique<ast::expr_true>(yylhs.location); }
#line 3420 "parser.cpp"
    break;


#line 3424 "parser.cpp"

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
      yy_lac_discard_ ("error recovery");
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "#define", "#undef", "#ifdef",
  "#ifndef", "#if", "#elif", "#else", "#endif", "/#", "#/", "#inline",
  "#include", "#using_animtree", "#animtree", "endon", "notify", "wait",
  "waittill", "waittillmatch", "waittillframeend", "waitframe", "if",
  "else", "do", "while", "for", "foreach", "in", "switch", "case",
  "default", "break", "continue", "return", "breakpoint", "prof_begin",
  "prof_end", "thread", "childthread", "thisthread", "call", "true",
  "false", "undefined", "size", "game", "self", "anim", "level", "(", ")",
  "{", "}", "[", "]", ",", ".", "::", ":", ";", "?", "++", "--", "<<",
  ">>", "||", "&&", "==", "!=", "<=", ">=", "<", ">", "!", "~", "=", "+=",
  "-=", "*=", "/=", "%=", "|=", "&=", "^=", ">>=", "<<=", "|", "&", "^",
  "+", "-", "*", "/", "%", "path", "identifier", "string literal",
  "localized string", "float", "integer", "SIZEOF", "ADD_ARRAY", "THEN",
  "TERN", "NEG", "ANIMREF", "PREINC", "PREDEC", "POSTINC", "POSTDEC",
  "$accept", "root", "program", "inline", "include", "declaration",
  "decl_usingtree", "decl_constant", "decl_thread", "stmt", "stmt_or_dev",
  "stmt_list", "stmt_or_dev_list", "stmt_dev", "stmt_block", "stmt_expr",
  "stmt_call", "stmt_assign", "stmt_endon", "stmt_notify", "stmt_wait",
  "stmt_waittill", "stmt_waittillmatch", "stmt_waittillframeend",
  "stmt_waitframe", "stmt_if", "stmt_ifelse", "stmt_while", "stmt_dowhile",
  "stmt_for", "stmt_foreach", "stmt_switch", "stmt_case", "stmt_default",
  "stmt_break", "stmt_continue", "stmt_return", "stmt_breakpoint",
  "stmt_prof_begin", "stmt_prof_end", "expr", "expr_or_empty",
  "expr_assign", "expr_increment", "expr_decrement", "expr_ternary",
  "expr_binary", "expr_primitive", "expr_complement", "expr_negate",
  "expr_not", "expr_call", "expr_method", "expr_function", "expr_pointer",
  "expr_add_array", "expr_parameters", "expr_arguments",
  "expr_arguments_no_empty", "expr_reference", "expr_tuple",
  "expr_tuple_arguments", "expr_tuple_types", "expr_array", "expr_field",
  "expr_size", "expr_paren", "expr_object", "expr_thisthread",
  "expr_empty_array", "expr_undefined", "expr_game", "expr_self",
  "expr_anim", "expr_level", "expr_animation", "expr_animtree",
  "expr_identifier_nosize", "expr_identifier", "expr_path", "expr_istring",
  "expr_string", "expr_vector", "expr_float", "expr_integer", "expr_false",
  "expr_true", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if S1CDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if S1CDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if S1CDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
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
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
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
  parser::yysyntax_error_ (const context& yyctx) const
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


  const short parser::yypact_ninf_ = -287;

  const short parser::yytable_ninf_ = -223;

  const short
  parser::yypact_[] =
  {
       6,  -287,  -287,     5,     5,   -24,  -287,  -287,    37,     6,
    -287,  -287,  -287,  -287,  -287,  -287,    -8,  -287,  -287,   -13,
     -10,   -54,  -287,  -287,  -287,  -287,   -23,  1223,  -287,  -287,
    -287,    11,   -12,  -287,  -287,   -42,     3,  -287,    17,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  1223,   821,   -23,  1223,
    1223,   -18,   -36,    26,  -287,  -287,  -287,  2187,  -287,  -287,
    -287,  -287,  -287,  -287,   413,   667,  -287,  -287,  -287,  -287,
     699,   729,  -287,  -287,  1012,  -287,  -287,  -287,  1089,  1187,
    1247,  1317,  -287,  -287,   574,    39,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,    15,    96,   -23,    49,    75,    81,   114,
     100,   124,   129,  1439,   821,  -287,  2270,   134,   136,  -287,
    -287,  -287,  1223,   142,  -287,  -287,  -287,  -287,   699,   729,
    -287,  1406,  -287,  -287,  -287,  -287,   574,   140,  -287,  -287,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1286,
     -20,  -287,  -287,   152,  1223,   -23,  -287,   928,  -287,  -287,
    1223,  1223,   -23,  1223,  1223,   -23,  1223,  -287,  1223,  1917,
    1223,  -287,  1605,  1223,   107,   -23,  2152,   179,   179,  2301,
    2311,  2383,  2383,    30,    30,    30,    30,  2342,   728,  2352,
      73,    73,  -287,  -287,  -287,  1957,  -287,  -287,  -287,    35,
    -287,   154,  1057,  1223,   146,    -5,   161,  1370,   165,   166,
     167,   168,   -17,   163,   169,   172,  1160,   183,   173,   175,
    -287,   139,   548,   548,  -287,  -287,   980,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,   184,   185,   188,   191,   192,   177,  -287,
    -287,    51,   152,  1997,    53,   205,  2037,    56,   206,  2077,
    2116,   203,  2270,  1917,   154,  1223,  -287,  -287,  1223,  -287,
    -287,  1134,  2222,  -287,   209,  -287,  1223,   236,  1223,   639,
     -23,  1223,   164,   208,   215,  -287,  -287,  -287,  -287,  2257,
    -287,  1223,  1223,  1286,    32,  -287,    62,    86,     8,  1406,
    1406,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  1223,   225,
     227,   228,   230,  -287,  -287,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,   210,  -287,  1223,   226,
    -287,  1223,   229,  1223,   232,  2270,    59,  -287,  -287,  -287,
     223,  1639,   235,  1673,   233,  -287,  -287,  -287,  1396,     9,
    1707,  -287,  -287,  -287,    60,    87,  -287,   548,  2270,  1223,
    1223,  1223,  1223,  2270,  2270,  2270,  2270,  2270,  2270,  2270,
    2270,  2270,  2270,  2270,   240,    89,   242,   101,   245,  1741,
    1223,  -287,  -287,  1370,  1223,  1370,  1223,  1223,   -23,    96,
     237,   241,  -287,  1775,  1483,  1527,  1571,  1223,  -287,  1223,
    -287,  1223,  -287,   103,   273,  1809,  -287,  2270,   243,  1843,
     272,  -287,  -287,  -287,   246,   249,  1223,   250,  1223,   251,
    1223,   113,   123,   125,  -287,  1370,   252,   639,  1370,  1223,
    -287,  -287,   254,  -287,   262,  -287,   286,  -287,  -287,  -287,
    -287,  -287,   287,  -287,  1877,   279,   280,   281,  1370,  1370,
    -287,  -287,  -287,  -287,  -287
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,    12,    13,     0,     0,     0,   221,   220,     0,     2,
       7,     8,     9,    14,    15,    16,     0,   223,   222,     0,
       0,     0,     1,     4,     5,     6,   184,     0,    10,    11,
     225,     0,     0,   183,   218,     0,     0,   210,     0,   232,
     231,   212,   213,   214,   215,   216,     0,   186,     0,     0,
       0,     0,     0,   220,   224,   228,   230,     0,    93,    94,
      95,   133,   134,   135,   136,   137,   167,   168,   138,   139,
     140,   141,   142,   143,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   211,   188,     0,   185,   189,
     166,   161,     0,     0,   227,   229,   201,   202,   164,   165,
     163,     0,   205,   206,   207,   208,   162,     0,   217,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,     0,   186,     0,    17,     0,    19,   182,
       0,   186,     0,     0,   186,     0,     0,   200,     0,   188,
       0,   181,     0,     0,     0,     0,     0,   126,   127,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     128,   129,   130,   131,   132,     0,   199,   219,   198,     0,
     185,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    45,    50,     0,    46,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,     0,     0,   201,   202,     0,   203,
     204,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   197,   171,   186,    52,
      48,     0,     0,    72,     0,    73,     0,     0,     0,    58,
       0,     0,     0,     0,     0,    85,    86,    87,    89,     0,
      90,   186,   186,     0,     0,   193,   203,   204,   209,   110,
     112,    53,    49,    61,    62,    63,    59,    60,     0,     0,
       0,     0,     0,   111,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   186,     0,
     175,   186,     0,     0,     0,   114,     0,    51,    47,    67,
       0,     0,     0,     0,     0,    55,    56,    57,     0,     0,
       0,    84,    83,    88,     0,     0,   191,     0,    98,     0,
       0,     0,     0,    99,   105,   106,   107,   108,   109,   100,
     101,   102,   104,   103,     0,     0,     0,     0,     0,     0,
     186,   172,    74,     0,     0,     0,    97,     0,     0,     0,
       0,     0,   192,     0,     0,     0,     0,   186,   174,   186,
     176,   186,   226,     0,    75,     0,    77,    96,     0,     0,
       0,    82,    91,    92,     0,     0,   186,     0,   186,     0,
     186,     0,     0,     0,   177,     0,     0,    58,     0,     0,
      64,    66,   185,    69,   185,    71,   185,   178,   179,   180,
      76,    78,     0,    80,     0,     0,     0,     0,     0,     0,
      65,    68,    70,    79,    81
  };

  const short
  parser::yypgoto_[] =
  {
    -287,  -287,  -287,   295,   336,   338,  -287,  -287,  -287,  -194,
     122,  -287,  -287,  -287,   -93,   -87,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
     189,  -287,  -286,  -277,  -274,  -287,  -287,  -287,  -287,  -287,
    -287,   -49,   -11,   -67,   -58,  -287,  -287,    95,   -43,  -287,
    -287,  -287,   -16,   197,   324,  -287,   302,   355,  -287,  -287,
    -287,   380,   417,   452,   490,  -287,  -287,  -287,     0,     7,
    -287,   -15,  -287,  -287,   148,  -287,  -287
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     8,     9,    10,    11,    12,    13,    14,    15,   224,
     225,   281,   226,   227,   228,   354,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     106,   418,   253,   254,   255,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    32,   107,   200,    69,
     258,   304,   305,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   198,    84,    85,
      86,    87,    88,    89,    90,    91,    92
  };

  const short
  parser::yytable_[] =
  {
      16,   158,   116,   355,   108,     6,    31,   151,   280,    16,
      19,    20,   356,   287,    96,   357,   152,     1,     2,     3,
       4,     5,    35,    36,     6,    38,    33,   196,    21,     6,
      42,    43,    44,    45,   112,    97,   100,    22,   113,   397,
     117,    94,    98,   101,    26,    30,    95,   284,   109,    28,
       6,   126,    29,     6,   151,    17,    53,   285,   127,    99,
     154,   108,   128,   152,    93,  -196,  -196,   398,   319,   320,
      27,   321,   322,   102,   153,     7,   292,   156,   197,    17,
      53,   127,    30,   114,   115,    56,  -222,   348,   277,   366,
     367,    35,    36,   170,    38,   159,   131,   132,     6,   155,
      17,    53,    17,    18,     7,   160,   337,   149,   256,   340,
     174,   170,   391,   400,   170,   323,   324,   170,   170,  -194,
    -194,   153,   144,   145,   146,   147,   148,   161,   127,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     401,   162,   408,  -195,  -195,   170,   257,   170,    17,    53,
     157,   355,   164,   256,   410,   201,   434,   262,   256,   170,
     356,   170,   265,   357,   127,   268,   447,   146,   147,   148,
     163,   170,   116,   116,   116,   274,   448,   256,   449,    35,
      36,   170,    38,   170,   165,   166,     6,    42,    43,    44,
      45,   257,   170,   171,   151,   303,   257,   293,   173,   414,
     175,   416,   262,   152,   154,   197,   278,   262,   283,   127,
     117,   117,   117,   286,   127,   257,    57,   288,   289,   290,
     291,   308,   262,   262,   295,   301,   262,   302,   127,   127,
     127,   296,   256,   127,   297,   103,    17,    53,   110,   111,
     116,   450,   151,   151,   453,   300,   313,   314,   118,   199,
     315,   152,   152,   316,   317,   318,   264,   338,   341,   267,
     344,   153,   350,   352,   463,   464,   115,   384,   127,   361,
     257,   144,   145,   146,   147,   148,   362,   369,   117,   370,
     371,   262,   372,   386,   390,   392,   388,   394,   127,   262,
     359,   151,   407,   169,   409,   396,   127,   411,   435,   422,
     152,   172,   439,   423,    23,   437,   421,   455,   440,   153,
     153,   441,   443,   445,   451,   456,   127,   127,   116,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   457,
     458,   460,   461,   462,   256,    24,   256,    25,   312,   263,
     452,   402,   266,   120,   259,   269,   117,   270,   153,   272,
     294,     0,   273,     0,     0,   127,     0,   308,     0,     0,
       0,     0,     0,   346,   127,   119,     0,     0,     0,     0,
       0,     0,   257,   442,   257,   444,   256,   446,   116,   256,
       0,     0,   282,   262,     0,   262,   364,   365,   420,   259,
     127,     0,   127,     0,   259,   299,   121,     0,     0,   256,
     256,     0,     0,     0,     0,     0,     0,     0,   306,   259,
     259,     0,     0,   259,   257,     0,   117,   257,     0,     0,
       0,   122,     0,   385,     0,   262,   387,   262,   262,     0,
       0,     0,   127,     0,   127,   127,     0,   257,   257,     0,
       0,     0,     0,  -201,  -201,     0,  -201,     0,   262,   262,
    -201,     0,     0,     0,   345,   127,   127,     0,   123,  -201,
       0,     0,  -201,     0,     0,   351,     0,   353,   259,     0,
     360,   260,     0,     0,     0,   413,   259,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   431,   124,   432,     0,   433,   368,     0,     0,
    -201,  -201,   261,     0,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,     0,   260,     0,     0,     0,
       0,   260,   389,     0,     0,     0,     0,   122,     0,     0,
       0,   125,     0,     0,     0,   307,   260,   260,     0,     0,
     260,     0,     0,     0,     0,     0,     0,   261,   403,   404,
     405,   406,   261,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,   121,   309,   310,     0,
       0,   261,   122,   415,     0,   417,   419,   122,    35,    36,
     259,    38,   259,     0,     0,     6,    42,    43,    44,    45,
       0,   122,   122,   122,   113,   260,   122,     0,     0,   124,
       0,     0,     0,   260,  -209,  -209,     0,  -209,     0,   123,
       0,  -209,     0,     0,   123,     0,   154,     0,   454,     0,
    -209,     0,   259,  -209,   259,   259,   261,     0,   123,   123,
     123,     0,     0,   123,   358,    17,    53,   125,     0,     0,
       0,     0,     0,     0,   124,   259,   259,     0,     0,   124,
       0,   122,     0,     0,     0,     0,     0,     0,     0,   122,
       0,  -209,  -209,   124,   124,   124,     0,     0,   124,    35,
      36,     0,    38,     0,     0,     0,     6,    42,    43,    44,
      45,   307,   125,     0,     0,   221,     0,   125,   123,     0,
       0,     0,     0,   222,   223,     0,   123,  -202,  -202,     0,
    -202,   125,   125,   125,  -202,     0,   125,   260,     0,   260,
       0,     0,   121,  -202,     0,     0,  -202,     0,     0,     0,
       0,     0,     0,   124,     0,     0,    17,    53,     0,  -203,
    -203,   124,  -203,     0,     0,     0,  -203,   122,   261,     0,
     261,     0,     0,     0,     0,  -203,     0,     0,  -203,   260,
       0,   260,   260,     0,  -202,  -202,     0,     0,     0,  -204,
    -204,   125,  -204,   122,     0,   122,  -204,     0,     0,   125,
       0,     0,   260,   260,   123,  -204,     0,     0,  -204,     0,
     261,     0,   358,   261,   131,   132,  -203,  -203,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
     123,     0,   123,   261,   261,   122,     0,   122,   122,   124,
     144,   145,   146,   147,   148,     0,  -204,  -204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,   122,   122,
       0,     0,     0,     0,     0,   124,     0,   124,     0,     0,
       0,     0,   123,     0,   123,   123,     0,   125,     0,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     6,    42,
      43,    44,    45,    46,     0,   123,   123,   104,   105,     0,
       0,    48,     0,   125,     0,   125,     0,   124,     0,   124,
     124,     0,     0,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   124,     0,     0,    51,     0,     0,    52,    17,    53,
      30,    54,    55,    56,     0,   125,     0,   125,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,   203,   125,   125,
     204,   205,   206,     0,   207,   208,   209,   210,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    35,    36,
       0,    38,     0,     0,     0,     6,    42,    43,    44,    45,
       0,     0,   157,   220,   221,     0,     0,     0,     0,     0,
       0,   202,   222,   223,     0,     0,     0,     0,     0,   203,
       0,     0,   204,   205,   206,     0,   207,   208,   209,   210,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      35,    36,     0,    38,     0,    17,    53,     6,    42,    43,
      44,    45,     0,     0,   157,   311,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,     0,     0,     0,     0,
       0,     0,    35,    36,     0,    38,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   279,
       0,   150,     0,     0,     0,     0,   203,    17,    53,   204,
     205,   206,     0,   207,   208,   209,   210,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    35,    36,     0,
      38,     0,     0,     0,     6,    42,    43,    44,    45,    17,
      53,   157,     0,   221,     0,     0,     0,     0,     0,     0,
       0,   222,   223,     0,     0,     0,     0,     0,     0,  -205,
    -205,     0,  -205,     0,     0,     0,  -205,     0,     0,     0,
       0,     0,     0,     0,     0,  -205,   347,     0,  -205,     0,
       0,     0,     0,   203,    17,    53,   204,   205,   206,     0,
     207,   208,   209,   210,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    35,    36,    34,    38,     0,     0,
       0,     6,    42,    43,    44,    45,  -205,  -205,   157,     0,
     221,     0,     0,     0,     0,     0,     0,     0,   222,   223,
      35,    36,    37,    38,    39,    40,    41,     6,    42,    43,
      44,    45,    46,     0,     0,     0,    47,     0,     0,     0,
      48,     0,   298,     0,     0,     0,     0,  -206,  -206,     0,
    -206,    17,    53,     0,  -206,     0,    49,    50,     0,    34,
       0,     0,     0,  -206,     0,     0,  -206,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    52,    17,    53,    30,
      54,    55,    56,    35,    36,    37,    38,    39,    40,    41,
       6,    42,    43,    44,    45,    46,     0,     0,     0,    47,
       0,     0,     0,    48,  -206,  -206,     0,  -207,  -207,     0,
    -207,     0,     0,     0,  -207,     0,     0,     0,     0,    49,
      50,     0,    34,  -207,     0,     0,  -207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
      17,    53,    30,    54,    55,    56,    35,    36,    37,    38,
      39,    40,    41,     6,    42,    43,    44,    45,    46,     0,
       0,     0,   104,     0,  -207,  -207,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -208,  -208,     0,
    -208,     0,    49,    50,  -208,     0,     0,     0,     0,     0,
       0,     0,     0,  -208,     0,     0,  -208,     0,     0,    51,
       0,     0,    52,    17,    53,    30,    54,    55,    56,   203,
       0,     0,   204,   205,   206,     0,   207,   208,   209,   210,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      35,    36,     0,    38,  -208,  -208,     0,     6,    42,    43,
      44,    45,     0,     0,   157,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,    35,    36,     0,    38,
       0,     0,     0,     6,     0,     0,    35,    36,     0,    38,
       0,     0,   149,     6,     0,   174,     0,     0,     0,     0,
     323,   324,   149,     0,     0,   174,     0,    17,    53,     0,
       0,     0,     0,     0,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,     0,     0,     0,     0,     0,
       0,     0,   167,    17,    53,     0,     0,   168,     0,     0,
       0,     0,   130,    17,    53,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     427,     0,     0,     0,     0,   428,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,   130,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   130,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     399,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   130,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   436,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   130,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   438,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   271,     0,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   276,     0,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   336,     0,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   339,     0,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   342,     0,     0,     0,     0,     0,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   343,     0,     0,     0,     0,   130,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   275,     0,   130,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   129,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   349,   130,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   363,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   130,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   131,   132,     0,
     134,   135,   136,   137,   138,   139,   140,   131,   132,     0,
       0,   135,   136,   137,   138,   139,   140,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   131,   132,
       0,     0,   135,   136,   137,   138,   139,   140,   131,   132,
       0,     0,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,   142,     0,   144,   145,   146,   147,   148,   131,
     132,     0,     0,     0,     0,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148
  };

  const short
  parser::yycheck_[] =
  {
       0,    94,    51,   289,    47,    47,    21,    74,   202,     9,
       3,     4,   289,   207,    56,   289,    74,    11,    12,    13,
      14,    15,    40,    41,    47,    43,    26,    47,    52,    47,
      48,    49,    50,    51,    52,    35,    36,     0,    56,    30,
      51,    53,    35,    36,    52,    99,    58,    52,    48,    62,
      47,    51,    62,    47,   121,    97,    98,    62,    51,    56,
      52,   104,    98,   121,    53,    57,    58,    58,    17,    18,
      78,    20,    21,    56,    74,    98,    93,    62,    98,    97,
      98,    74,    99,   101,   102,   102,    60,   281,    53,    57,
      58,    40,    41,    58,    43,    95,    66,    67,    47,    60,
      97,    98,    97,    98,    98,    56,    53,    56,   157,    53,
      59,    58,    53,    53,    58,    64,    65,    58,    58,    57,
      58,   121,    92,    93,    94,    95,    96,    52,   121,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      53,    60,    53,    57,    58,    58,   157,    58,    97,    98,
      54,   437,    52,   202,    53,   155,    53,   157,   207,    58,
     437,    58,   162,   437,   157,   165,    53,    94,    95,    96,
      56,    58,   221,   222,   223,   175,    53,   226,    53,    40,
      41,    58,    43,    58,    60,    56,    47,    48,    49,    50,
      51,   202,    58,    57,   261,    56,   207,   212,    56,   393,
      60,   395,   202,   261,    52,    98,    52,   207,    62,   202,
     221,   222,   223,    52,   207,   226,    27,    52,    52,    52,
      52,   221,   222,   223,    61,    52,   226,    52,   221,   222,
     223,    62,   281,   226,    62,    46,    97,    98,    49,    50,
     289,   435,   309,   310,   438,    62,    62,    62,    51,   154,
      62,   309,   310,    62,    62,    78,   161,    52,    52,   164,
      57,   261,    53,    27,   458,   459,   102,    57,   261,    61,
     281,    92,    93,    94,    95,    96,    61,    52,   289,    52,
      52,   281,    52,    57,    52,    62,    57,    52,   281,   289,
     290,   358,    52,   104,    52,    62,   289,    52,    25,    62,
     358,   112,    30,    62,     9,    62,   399,    53,    62,   309,
     310,    62,    62,    62,    62,    53,   309,   310,   367,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    53,
      53,    62,    62,    62,   393,     9,   395,     9,   226,   160,
     437,   367,   163,    51,   157,   166,   367,   168,   358,   170,
     212,    -1,   173,    -1,    -1,   358,    -1,   367,    -1,    -1,
      -1,    -1,    -1,   278,   367,    51,    -1,    -1,    -1,    -1,
      -1,    -1,   393,   426,   395,   428,   435,   430,   437,   438,
      -1,    -1,   203,   393,    -1,   395,   301,   302,   398,   202,
     393,    -1,   395,    -1,   207,   216,    51,    -1,    -1,   458,
     459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,    -1,   226,   435,    -1,   437,   438,    -1,    -1,
      -1,    51,    -1,   338,    -1,   435,   341,   437,   438,    -1,
      -1,    -1,   435,    -1,   437,   438,    -1,   458,   459,    -1,
      -1,    -1,    -1,    40,    41,    -1,    43,    -1,   458,   459,
      47,    -1,    -1,    -1,   275,   458,   459,    -1,    51,    56,
      -1,    -1,    59,    -1,    -1,   286,    -1,   288,   281,    -1,
     291,   157,    -1,    -1,    -1,   390,   289,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   407,    51,   409,    -1,   411,   318,    -1,    -1,
      97,    98,   157,    -1,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,    -1,   202,    -1,    -1,    -1,
      -1,   207,   343,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,    51,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   202,   369,   370,
     371,   372,   207,    -1,   367,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   221,   222,   223,    -1,
      -1,   226,   202,   394,    -1,   396,   397,   207,    40,    41,
     393,    43,   395,    -1,    -1,    47,    48,    49,    50,    51,
      -1,   221,   222,   223,    56,   281,   226,    -1,    -1,   157,
      -1,    -1,    -1,   289,    40,    41,    -1,    43,    -1,   202,
      -1,    47,    -1,    -1,   207,    -1,    52,    -1,   439,    -1,
      56,    -1,   435,    59,   437,   438,   281,    -1,   221,   222,
     223,    -1,    -1,   226,   289,    97,    98,   157,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   458,   459,    -1,    -1,   207,
      -1,   281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,
      -1,    97,    98,   221,   222,   223,    -1,    -1,   226,    40,
      41,    -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      51,   367,   202,    -1,    -1,    56,    -1,   207,   281,    -1,
      -1,    -1,    -1,    64,    65,    -1,   289,    40,    41,    -1,
      43,   221,   222,   223,    47,    -1,   226,   393,    -1,   395,
      -1,    -1,   367,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,   281,    -1,    -1,    97,    98,    -1,    40,
      41,   289,    43,    -1,    -1,    -1,    47,   367,   393,    -1,
     395,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,   435,
      -1,   437,   438,    -1,    97,    98,    -1,    -1,    -1,    40,
      41,   281,    43,   393,    -1,   395,    47,    -1,    -1,   289,
      -1,    -1,   458,   459,   367,    56,    -1,    -1,    59,    -1,
     435,    -1,   437,   438,    66,    67,    97,    98,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
     393,    -1,   395,   458,   459,   435,    -1,   437,   438,   367,
      92,    93,    94,    95,    96,    -1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,   458,   459,
      -1,    -1,    -1,    -1,    -1,   393,    -1,   395,    -1,    -1,
      -1,    -1,   435,    -1,   437,   438,    -1,   367,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,   458,   459,    56,    57,    -1,
      -1,    60,    -1,   393,    -1,   395,    -1,   435,    -1,   437,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,   459,    -1,    -1,    93,    -1,    -1,    96,    97,    98,
      99,   100,   101,   102,    -1,   435,    -1,   437,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   458,   459,
      22,    23,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    64,    65,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    97,    98,    47,    48,    49,
      50,    51,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    12,
      -1,    59,    -1,    -1,    -1,    -1,    19,    97,    98,    22,
      23,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    97,
      98,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    12,    -1,    59,    -1,
      -1,    -1,    -1,    19,    97,    98,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    16,    43,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    97,    98,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    97,    98,    -1,    47,    -1,    76,    77,    -1,    16,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    97,    98,    -1,    40,    41,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    76,
      77,    -1,    16,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    -1,    97,    98,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    -1,    76,    77,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    93,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,    19,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    97,    98,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    40,    41,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,    40,    41,    -1,    43,
      -1,    -1,    56,    47,    -1,    59,    -1,    -1,    -1,    -1,
      64,    65,    56,    -1,    -1,    59,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    97,    98,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    97,    98,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    53,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    53,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    61,    -1,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    66,    67,    -1,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    75,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    96,    66,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    11,    12,    13,    14,    15,    47,    98,   114,   115,
     116,   117,   118,   119,   120,   121,   191,    97,    98,   192,
     192,    52,     0,   116,   117,   118,    52,    78,    62,    62,
      99,   194,   169,   191,    16,    40,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    51,    52,    56,    60,    76,
      77,    93,    96,    98,   100,   101,   102,   153,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   172,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    53,    53,    58,    56,   191,   192,    56,
     191,   192,    56,   153,    56,    57,   153,   170,   171,   191,
     153,   153,    52,    56,   101,   102,   164,   165,   176,   177,
     179,   180,   184,   185,   186,   187,   191,   192,    98,    62,
      63,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    89,    90,    91,    92,    93,    94,    95,    96,    56,
      59,   166,   167,   191,    52,    60,    62,    54,   127,   191,
      56,    52,    60,    56,    52,    60,    56,    53,    58,   153,
      58,    57,   153,    56,    59,    60,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,    47,    98,   190,   170,
     171,   191,    11,    19,    22,    23,    24,    26,    27,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      55,    56,    64,    65,   122,   123,   125,   126,   127,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   155,   156,   157,   164,   165,   173,   176,
     177,   180,   191,   153,   170,   191,   153,   170,   191,   153,
     153,    57,   153,   153,   191,    61,    57,    53,    52,    12,
     122,   124,   153,    62,    52,    62,    52,   122,    52,    52,
      52,    52,    93,   194,   197,    61,    62,    62,    62,   153,
      62,    52,    52,    56,   174,   175,   176,   177,   191,   180,
     180,    55,   123,    62,    62,    62,    62,    62,    78,    17,
      18,    20,    21,    64,    65,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    57,    53,    52,    57,
      53,    52,    57,    58,    57,   153,   170,    12,   122,    62,
      53,   153,    27,   153,   128,   155,   156,   157,   180,   191,
     153,    61,    61,    62,   170,   170,    57,    58,   153,    52,
      52,    52,    52,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,    57,   170,    57,   170,    57,   153,
      52,    53,    62,    53,    52,    53,    62,    30,    58,    53,
      53,    53,   175,   153,   153,   153,   153,    52,    53,    52,
      53,    52,    53,   170,   122,   153,   122,   153,   154,   153,
     191,   127,    62,    62,    53,    53,    58,    53,    58,    53,
      58,   170,   170,   170,    53,    25,    53,    62,    53,    30,
      62,    62,   171,    62,   171,    62,   171,    53,    53,    53,
     122,    62,   128,   122,   153,    53,    53,    53,    53,    53,
      62,    62,    62,   122,   122
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     116,   117,   118,   118,   118,   118,   118,   119,   120,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   131,   132,   132,   133,   134,   134,
     135,   135,   136,   137,   137,   138,   139,   140,   141,   142,
     143,   143,   144,   145,   145,   146,   147,   148,   149,   149,
     150,   151,   152,   153,   153,   153,   154,   154,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   156,   157,   157,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   162,   162,   162,   162,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   167,   167,   167,
     167,   168,   169,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   174,   174,   175,   175,   175,   176,   177,   178,
     179,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   191,   192,   192,   193,   194,   195,   196,   196,   197,
     197,   198,   199
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     5,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     2,     3,     2,     1,     1,     1,     0,     2,
       2,     2,     2,     2,     6,     8,     6,     3,     8,     6,
       8,     6,     2,     2,     4,     5,     7,     5,     7,     9,
       7,     9,     5,     3,     3,     2,     2,     2,     3,     2,
       2,     5,     5,     1,     1,     1,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     2,
       2,     4,     6,     5,     7,     5,     7,     8,     9,     9,
       9,     3,     3,     1,     0,     1,     0,     3,     1,     2,
       3,     3,     3,     1,     1,     1,     1,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     2,     1,     2,
       1,     1,     1
  };




#if S1CDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   263,   263,   264,   268,   270,   272,   274,   276,   278,
     283,   287,   292,   293,   294,   295,   296,   300,   305,   310,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   343,   344,   348,   350,   355,
     357,   362,   363,   367,   368,   372,   374,   376,   379,   383,
     385,   390,   392,   394,   399,   404,   406,   411,   416,   418,
     423,   425,   430,   435,   437,   442,   447,   452,   457,   462,
     467,   469,   474,   479,   481,   486,   491,   496,   501,   503,
     508,   513,   518,   523,   524,   525,   529,   530,   534,   536,
     538,   540,   542,   544,   546,   548,   550,   552,   554,   556,
     561,   563,   568,   570,   575,   580,   582,   584,   586,   588,
     590,   592,   594,   596,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   650,   655,   657,   659,   661,   666,   671,   672,   675,
     676,   680,   682,   684,   686,   688,   690,   695,   697,   699,
     701,   706,   711,   713,   716,   720,   723,   727,   729,   734,
     736,   741,   746,   748,   753,   754,   755,   759,   764,   769,
     774,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     791,   796,   801,   806,   811,   816,   821,   826,   831,   836,
     841,   843,   848,   850,   855,   860,   865,   870,   872,   877,
     879,   884,   889
  };

  void
  parser::yy_stack_print_ () const
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
  parser::yy_reduce_print_ (int yyrule) const
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
#endif // S1CDEBUG


#line 13 "parser.ypp"
} } } // xsk::gsc::s1c
#line 4726 "parser.cpp"

#line 893 "parser.ypp"


void xsk::gsc::s1c::parser::error(const xsk::gsc::location& loc, const std::string& msg)
{
    throw xsk::gsc::comp_error(loc, msg);
}
