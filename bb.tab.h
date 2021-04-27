/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BB_BB_TAB_H_INCLUDED
# define YY_BB_BB_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int bbdebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_STATIC = 258,                /* T_STATIC  */
    T_TYPE = 259,                  /* T_TYPE  */
    T_UNSIGNED = 260,              /* T_UNSIGNED  */
    T_SIGNED = 261,                /* T_SIGNED  */
    T_VOID = 262,                  /* T_VOID  */
    T_STRING = 263,                /* T_STRING  */
    T_IDENTIFIER = 264,            /* T_IDENTIFIER  */
    T_RETURN = 265,                /* T_RETURN  */
    T_NUMBER = 266,                /* T_NUMBER  */
    T_OPEN_BRACE = 267,            /* T_OPEN_BRACE  */
    T_CLOSE_BRACE = 268,           /* T_CLOSE_BRACE  */
    T_IF = 269,                    /* T_IF  */
    T_WHILE = 270,                 /* T_WHILE  */
    T_ELSE = 271,                  /* T_ELSE  */
    T_GOTO = 272,                  /* T_GOTO  */
    T_LABEL = 273,                 /* T_LABEL  */
    T_BREAK = 274,                 /* T_BREAK  */
    T_CONTINUE = 275,              /* T_CONTINUE  */
    T_LSHIFT = 276,                /* T_LSHIFT  */
    T_RSHIFT = 277,                /* T_RSHIFT  */
    T_LOGICAL_OR = 278,            /* T_LOGICAL_OR  */
    T_LOGICAL_AND = 279,           /* T_LOGICAL_AND  */
    T_LESS_OR_EQUAL = 280,         /* T_LESS_OR_EQUAL  */
    T_EQUAL = 281,                 /* T_EQUAL  */
    T_NEQUAL = 282,                /* T_NEQUAL  */
    T_LARGER_OR_EQUAL = 283,       /* T_LARGER_OR_EQUAL  */
    T_INCREMENT = 284,             /* T_INCREMENT  */
    T_DECREMENT = 285,             /* T_DECREMENT  */
    T_SIZEOF = 286,                /* T_SIZEOF  */
    T_PLUS_EQ = 287,               /* T_PLUS_EQ  */
    T_MINUS_EQ = 288,              /* T_MINUS_EQ  */
    T_MUL_EQ = 289,                /* T_MUL_EQ  */
    T_DIV_EQ = 290,                /* T_DIV_EQ  */
    T_MOD_EQ = 291,                /* T_MOD_EQ  */
    T_OR_EQ = 292,                 /* T_OR_EQ  */
    T_AND_EQ = 293,                /* T_AND_EQ  */
    T_XOR_EQ = 294,                /* T_XOR_EQ  */
    T_RSHIFT_EQ = 295,             /* T_RSHIFT_EQ  */
    T_LSHIFT_EQ = 296,             /* T_LSHIFT_EQ  */
    T_DICREMENT = 297,             /* T_DICREMENT  */
    T_MINUS = 298,                 /* T_MINUS  */
    T_PLUS = 299,                  /* T_PLUS  */
    T_ADDRESS = 300                /* T_ADDRESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE bblval;

int bbparse (void);

#endif /* !YY_BB_BB_TAB_H_INCLUDED  */
