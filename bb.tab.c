/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         bbparse
#define yylex           bblex
#define yyerror         bberror
#define yydebug         bbdebug
#define yynerrs         bbnerrs
#define yylval          bblval
#define yychar          bbchar

/* First part of user prologue.  */
#line 4 "babyc_parse.y"


/* ----------------------------------------------------------------
 * 
 * BabyC Toy compiler for educational purposes
 * 
 * ---------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "syntax.h"
#include "list.h"
#include "bb_type.h"
#include "log_error.h"

#define YYDEBUG 1
#undef YYDEBUG
// int yydebug=1;

extern int bblex(void);

int bberror(char *s)
{
    printf("%s", s);
    return 1;
}

int bbwrap()
{
	return 1;
}

extern FILE *bbin;

static Scope *pscope;
static List *parameters_stack;
static List *labels_stack;

void parser_setup(char *file_name)
{
    pscope = scope_new(0);
    parameters_stack = list_new();
    labels_stack = list_new();
    bbin = fopen(file_name, "rt");
}

Syntax *parser_complete(void)
{
    Syntax *ret = block_new(pscope->parser_stack);
    list_free(parameters_stack);
    list_free(labels_stack);
    fclose(bbin);
    return ret; 
}

Label *search_existing_label(char *name)
{
   for (int i = 0; i < list_length(labels_stack); i++)
   {
       Label *l = list_get(labels_stack, i);
       if (!strcmp(name, l->name))
       {
           return l;
       }
   }
   Label *label = malloc(sizeof(Label));
   label->name = name;
   label->assembler_name = 0;
   list_push(labels_stack, label);
   return label;
}
 
static ObjectType current_object_type = O_INT32;
static ObjectType current_function_type = O_INT32;
static ObjectType current_cast_type = O_INT32;
static ObjectType saved_object_type = O_INT32; 

#line 158 "bb.tab.c"

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

#include "bb.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_STATIC = 3,                   /* T_STATIC  */
  YYSYMBOL_T_TYPE = 4,                     /* T_TYPE  */
  YYSYMBOL_T_UNSIGNED = 5,                 /* T_UNSIGNED  */
  YYSYMBOL_T_SIGNED = 6,                   /* T_SIGNED  */
  YYSYMBOL_T_VOID = 7,                     /* T_VOID  */
  YYSYMBOL_T_STRING = 8,                   /* T_STRING  */
  YYSYMBOL_T_IDENTIFIER = 9,               /* T_IDENTIFIER  */
  YYSYMBOL_T_RETURN = 10,                  /* T_RETURN  */
  YYSYMBOL_T_NUMBER = 11,                  /* T_NUMBER  */
  YYSYMBOL_T_OPEN_BRACE = 12,              /* T_OPEN_BRACE  */
  YYSYMBOL_T_CLOSE_BRACE = 13,             /* T_CLOSE_BRACE  */
  YYSYMBOL_T_IF = 14,                      /* T_IF  */
  YYSYMBOL_T_WHILE = 15,                   /* T_WHILE  */
  YYSYMBOL_T_ELSE = 16,                    /* T_ELSE  */
  YYSYMBOL_T_GOTO = 17,                    /* T_GOTO  */
  YYSYMBOL_T_LABEL = 18,                   /* T_LABEL  */
  YYSYMBOL_T_BREAK = 19,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 20,                /* T_CONTINUE  */
  YYSYMBOL_T_LSHIFT = 21,                  /* T_LSHIFT  */
  YYSYMBOL_T_RSHIFT = 22,                  /* T_RSHIFT  */
  YYSYMBOL_T_LOGICAL_OR = 23,              /* T_LOGICAL_OR  */
  YYSYMBOL_T_LOGICAL_AND = 24,             /* T_LOGICAL_AND  */
  YYSYMBOL_T_LESS_OR_EQUAL = 25,           /* T_LESS_OR_EQUAL  */
  YYSYMBOL_T_EQUAL = 26,                   /* T_EQUAL  */
  YYSYMBOL_T_NEQUAL = 27,                  /* T_NEQUAL  */
  YYSYMBOL_T_LARGER_OR_EQUAL = 28,         /* T_LARGER_OR_EQUAL  */
  YYSYMBOL_T_INCREMENT = 29,               /* T_INCREMENT  */
  YYSYMBOL_T_DECREMENT = 30,               /* T_DECREMENT  */
  YYSYMBOL_T_SIZEOF = 31,                  /* T_SIZEOF  */
  YYSYMBOL_T_PLUS_EQ = 32,                 /* T_PLUS_EQ  */
  YYSYMBOL_T_MINUS_EQ = 33,                /* T_MINUS_EQ  */
  YYSYMBOL_T_MUL_EQ = 34,                  /* T_MUL_EQ  */
  YYSYMBOL_T_DIV_EQ = 35,                  /* T_DIV_EQ  */
  YYSYMBOL_T_MOD_EQ = 36,                  /* T_MOD_EQ  */
  YYSYMBOL_T_OR_EQ = 37,                   /* T_OR_EQ  */
  YYSYMBOL_T_AND_EQ = 38,                  /* T_AND_EQ  */
  YYSYMBOL_T_XOR_EQ = 39,                  /* T_XOR_EQ  */
  YYSYMBOL_T_RSHIFT_EQ = 40,               /* T_RSHIFT_EQ  */
  YYSYMBOL_T_LSHIFT_EQ = 41,               /* T_LSHIFT_EQ  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '&'  */
  YYSYMBOL_44_ = 44,                       /* '|'  */
  YYSYMBOL_45_ = 45,                       /* '^'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_T_DICREMENT = 53,               /* T_DICREMENT  */
  YYSYMBOL_T_MINUS = 54,                   /* T_MINUS  */
  YYSYMBOL_T_PLUS = 55,                    /* T_PLUS  */
  YYSYMBOL_56_ = 56,                       /* '!'  */
  YYSYMBOL_57_ = 57,                       /* '~'  */
  YYSYMBOL_T_ADDRESS = 58,                 /* T_ADDRESS  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* ':'  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_object_type = 68,               /* object_type  */
  YYSYMBOL_basic_object_type = 69,         /* basic_object_type  */
  YYSYMBOL_top_element = 70,               /* top_element  */
  YYSYMBOL_71_1 = 71,                      /* $@1  */
  YYSYMBOL_global_identifier_list = 72,    /* global_identifier_list  */
  YYSYMBOL_global_identifier = 73,         /* global_identifier  */
  YYSYMBOL_automatic_identifier_list = 74, /* automatic_identifier_list  */
  YYSYMBOL_automatic_identifier = 75,      /* automatic_identifier  */
  YYSYMBOL_parameter_list = 76,            /* parameter_list  */
  YYSYMBOL_nonempty_parameter_list = 77,   /* nonempty_parameter_list  */
  YYSYMBOL_parameter = 78,                 /* parameter  */
  YYSYMBOL_argument_list = 79,             /* argument_list  */
  YYSYMBOL_nonempty_argument_list = 80,    /* nonempty_argument_list  */
  YYSYMBOL_argument = 81,                  /* argument  */
  YYSYMBOL_block = 82,                     /* block  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_full_block = 84,                /* full_block  */
  YYSYMBOL_nonempty_statement_list = 85,   /* nonempty_statement_list  */
  YYSYMBOL_statement = 86,                 /* statement  */
  YYSYMBOL_address = 87,                   /* address  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_89_3 = 89,                      /* $@3  */
  YYSYMBOL_90_4 = 90                       /* $@4  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    52,    43,     2,
      59,    60,    50,    48,    62,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    61,
      46,    42,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    53,    54,    55,
      58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   118,   119,   123,   125,   132,   138,   144,
     150,   158,   158,   170,   174,   176,   180,   187,   195,   197,
     201,   208,   215,   216,   220,   222,   225,   233,   234,   238,
     240,   244,   252,   252,   264,   265,   269,   271,   275,   281,
     286,   291,   297,   303,   311,   319,   326,   328,   330,   332,
     336,   341,   348,   353,   359,   365,   372,   379,   386,   393,
     400,   407,   414,   421,   428,   435,   442,   449,   456,   463,
     471,   479,   487,   495,   503,   511,   519,   527,   535,   543,
     551,   559,   565,   571,   577,   582,   589,   596,   603,   610,
     617,   624,   631,   638,   645,   652,   659,   666,   673,   680,
     687,   694,   701,   708,   714,   714,   721,   730,   730,   738,
     740
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_STATIC", "T_TYPE",
  "T_UNSIGNED", "T_SIGNED", "T_VOID", "T_STRING", "T_IDENTIFIER",
  "T_RETURN", "T_NUMBER", "T_OPEN_BRACE", "T_CLOSE_BRACE", "T_IF",
  "T_WHILE", "T_ELSE", "T_GOTO", "T_LABEL", "T_BREAK", "T_CONTINUE",
  "T_LSHIFT", "T_RSHIFT", "T_LOGICAL_OR", "T_LOGICAL_AND",
  "T_LESS_OR_EQUAL", "T_EQUAL", "T_NEQUAL", "T_LARGER_OR_EQUAL",
  "T_INCREMENT", "T_DECREMENT", "T_SIZEOF", "T_PLUS_EQ", "T_MINUS_EQ",
  "T_MUL_EQ", "T_DIV_EQ", "T_MOD_EQ", "T_OR_EQ", "T_AND_EQ", "T_XOR_EQ",
  "T_RSHIFT_EQ", "T_LSHIFT_EQ", "'='", "'&'", "'|'", "'^'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "T_DICREMENT", "T_MINUS", "T_PLUS",
  "'!'", "'~'", "T_ADDRESS", "'('", "')'", "';'", "','", "':'", "'['",
  "']'", "$accept", "program", "object_type", "basic_object_type",
  "top_element", "$@1", "global_identifier_list", "global_identifier",
  "automatic_identifier_list", "automatic_identifier", "parameter_list",
  "nonempty_parameter_list", "parameter", "argument_list",
  "nonempty_argument_list", "argument", "block", "$@2", "full_block",
  "nonempty_statement_list", "statement", "address", "expression", "$@3",
  "$@4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    61,    38,   124,    94,    60,    62,    43,    45,
      42,    47,    37,   297,   298,   299,    33,   126,   300,    40,
      41,    59,    44,    58,    91,    93
};
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,    35,  -173,    10,    31,  -173,    66,     1,    17,    81,
      81,  -173,  -173,  -173,   -41,     8,     9,  -173,  -173,  -173,
      59,  -173,  -173,    71,   433,  -173,    23,    80,    59,    59,
       6,    59,    59,   194,    33,   477,    35,    56,  -173,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    -173,    70,    36,  -173,  -173,  -173,    59,    61,  -173,  -173,
    -173,  -173,    41,   316,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    95,    45,  -173,    44,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,    59,    50,
      51,    59,   356,    59,   165,    52,  -173,    49,   101,    43,
      43,   487,   519,   -18,   559,   559,   -18,   527,   527,   527,
     -18,   -18,   -45,   -45,  -173,  -173,  -173,  -173,   105,    35,
      72,  -173,    57,   477,  -173,  -173,   233,  -173,   477,    35,
      59,    62,    75,   121,    68,    74,    76,   127,  -173,   128,
    -173,   165,   243,    59,   281,   165,  -173,  -173,    59,  -173,
      71,   284,    59,    59,    79,  -173,  -173,  -173,   112,   106,
     116,  -173,  -173,  -173,   477,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,   168,  -173,   125,  -173,
     396,   436,  -173,    59,  -173,   127,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,  -173,  -173,   165,
     165,   477,  -173,   171,  -173,   165,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     7,     0,     0,     8,     0,     0,     5,     4,
       4,    10,     9,     1,    17,     0,    15,     6,     2,     3,
       0,    11,    13,     0,    53,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    23,    17,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,    54,    84,    83,    50,     0,    57,    82,    81,
      32,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    25,    59,    60,    61,
      62,    63,    65,    64,    66,    68,    67,    58,    28,     0,
       0,     0,     0,     0,    35,     0,   110,   109,     0,    94,
      93,    95,    96,   102,    99,   100,   101,    90,    91,    92,
      97,    98,    85,    86,    87,    88,    89,    26,     0,    23,
       0,    27,    30,    31,   106,   103,     0,    51,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
      34,    37,     0,     0,    56,    35,    24,   108,     0,    55,
       0,     0,     0,     0,     0,    41,    39,    40,    21,     0,
      19,    33,    36,    48,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,    42,
       0,     0,    38,     0,    46,     0,    70,    71,    72,    73,
      74,    78,    77,    79,    76,    75,    69,    12,    47,     0,
       0,    20,    18,    43,    45,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,     7,    63,  -173,   187,  -173,   -21,  -173,    -6,  -173,
      64,  -173,  -173,  -173,    32,  -173,   158,  -173,    39,    46,
    -172,   174,   -20,  -173,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,   147,     8,     9,    36,    15,    16,   169,   170,
      84,    85,    86,   130,   131,   132,   148,   104,   149,   150,
     151,    34,   152,   105,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    20,    38,    65,    66,    80,    81,    82,    53,    54,
      14,    58,    59,    63,    11,    55,    18,    19,    21,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      78,    79,    80,    81,    82,    12,   102,   213,   214,     2,
       3,     4,     5,   216,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     7,     7,    56,    13,    17,    24,    22,
      25,    23,     7,     7,     2,     3,     4,     5,   133,    99,
      37,   136,    51,   138,     1,     2,     3,     4,     5,    52,
      26,    78,    79,    80,    81,    82,    61,    64,    20,    83,
     101,   106,    27,   103,   127,   128,   129,    28,    29,    30,
     134,   135,   153,   -51,   100,    31,    32,   155,    33,   158,
     161,   162,    65,    66,    67,    68,    69,    70,    71,    72,
     164,   165,   157,   174,   163,   166,   168,   167,   133,   188,
     192,   171,   190,   191,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   193,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   154,   194,   139,     2,
       3,     4,     5,   211,    24,   140,    25,    60,   195,   141,
     142,   207,   143,   144,   145,   146,   208,   215,    10,   212,
     187,    62,    83,   156,   186,     0,    26,   172,     2,     3,
       4,     5,   160,    24,    57,    25,    60,     0,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,    31,    32,     0,    33,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,    28,    29,    30,     0,     0,     0,     0,     0,
      31,    32,     0,    33,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,   159,     0,
       0,     0,     0,     0,   173,    65,    66,    67,    68,    69,
      70,    71,    72,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    65,    66,    67,
      68,    69,    70,    71,    72,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,   107,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,   137,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,   209,    65,    66,    67,
      68,    69,    70,    71,    72,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    50,     0,     0,     0,   210,   -50,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    65,    66,
       0,    68,    69,    70,    71,    72,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      65,    66,     0,     0,    69,    70,    71,    72,    65,    66,
       0,     0,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    76,    77,    78,    79,    80,    81,    82,
      65,    66,     0,     0,    69,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82
};

static const yytype_int16 yycheck[] =
{
      20,    42,    23,    21,    22,    50,    51,    52,    28,    29,
       9,    31,    32,    33,     4,     9,     9,    10,    59,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      48,    49,    50,    51,    52,     4,    56,   209,   210,     4,
       5,     6,     7,   215,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     1,    59,     0,    50,     9,    61,
      11,    62,     9,    10,     4,     5,     6,     7,    98,     9,
       9,   101,    59,   103,     3,     4,     5,     6,     7,     9,
      31,    48,    49,    50,    51,    52,    33,    64,    42,    36,
      64,    60,    43,    42,     9,    60,    62,    48,    49,    50,
      60,    60,    60,    64,    51,    56,    57,    12,    59,    62,
     140,    59,    21,    22,    23,    24,    25,    26,    27,    28,
       9,    63,    60,   153,    59,    61,     9,    61,   158,   160,
      61,    13,   162,   163,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    42,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    65,    61,     3,     4,
       5,     6,     7,   193,     9,    10,    11,    12,    62,    14,
      15,    13,    17,    18,    19,    20,    61,    16,     1,   195,
     158,    33,   129,   129,   155,    -1,    31,   151,     4,     5,
       6,     7,   139,     9,    30,    11,    12,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    59,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    59,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    61,    21,    22,    23,    24,    25,
      26,    27,    28,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    21,    22,    23,
      24,    25,    26,    27,    28,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    21,    22,    23,
      24,    25,    26,    27,    28,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    60,    64,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      21,    22,    -1,    -1,    25,    26,    27,    28,    21,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    46,    47,    48,    49,    50,    51,    52,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    67,    68,    69,    70,
      70,     4,     4,     0,     9,    72,    73,    50,    67,    67,
      42,    59,    61,    62,     9,    11,    31,    43,    48,    49,
      50,    56,    57,    59,    87,    88,    71,     9,    72,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      59,    59,     9,    88,    88,     9,    59,    87,    88,    88,
      12,    68,    82,    88,    64,    21,    22,    23,    24,    25,
      26,    27,    28,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    68,    76,    77,    78,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    90,     9,
      68,    64,    88,    42,    83,    89,    60,    60,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,     9,    60,    62,
      79,    80,    81,    88,    60,    60,    88,    60,    88,     3,
      10,    14,    15,    17,    18,    19,    20,    68,    82,    84,
      85,    86,    88,    60,    65,    12,    76,    60,    62,    65,
      68,    88,    59,    59,     9,    63,    61,    61,     9,    74,
      75,    13,    85,    61,    88,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    84,    80,    72,    61,
      88,    88,    61,    42,    61,    62,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    13,    61,    60,
      60,    88,    74,    86,    86,    16,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    71,    70,    70,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    81,    83,    82,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    88,    88,    90,    88,    88,
      88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     2,     1,     1,     2,
       2,     0,     9,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     0,     3,     1,     2,     1,     0,     3,
       1,     1,     0,     4,     1,     0,     2,     1,     3,     2,
       2,     2,     3,     5,     7,     5,     3,     4,     2,     1,
       1,     3,     1,     1,     2,     5,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       4,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     0,     5,     4,     0,     5,     3,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* object_type: basic_object_type '*'  */
#line 126 "babyc_parse.y"
        {
            current_object_type = current_object_type | O_ADDRESS;
        }
#line 1467 "bb.tab.c"
    break;

  case 7: /* basic_object_type: T_TYPE  */
#line 133 "babyc_parse.y"
        {
            saved_object_type = current_object_type;
            current_object_type = convert_type(yyvsp[0].symbol);
        }
#line 1476 "bb.tab.c"
    break;

  case 8: /* basic_object_type: T_VOID  */
#line 139 "babyc_parse.y"
        {
            saved_object_type = current_object_type;
            current_object_type = O_VOID;
        }
#line 1485 "bb.tab.c"
    break;

  case 9: /* basic_object_type: T_SIGNED T_TYPE  */
#line 145 "babyc_parse.y"
        {
            saved_object_type = current_object_type;
            current_object_type = convert_type(yyvsp[0].symbol) & ~O_UNSIGNED;   
        }
#line 1494 "bb.tab.c"
    break;

  case 10: /* basic_object_type: T_UNSIGNED T_TYPE  */
#line 151 "babyc_parse.y"
        {
            saved_object_type = current_object_type;
            current_object_type = convert_type(yyvsp[0].symbol) | O_UNSIGNED;   
        }
#line 1503 "bb.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 158 "babyc_parse.y"
                                          { current_function_type = current_object_type; pscope = scope_new(pscope); }
#line 1509 "bb.tab.c"
    break;

  case 12: /* top_element: object_type T_IDENTIFIER '(' $@1 parameter_list ')' T_OPEN_BRACE full_block T_CLOSE_BRACE  */
#line 160 "babyc_parse.y"
        {
            Syntax *block = block_new(pscope->parser_stack);
            Syntax *syntax = function_definition_new(yyvsp[-7].symbol, current_function_type, parameters_stack, labels_stack, block);
            pscope->parser_stack = list_new();
            parameters_stack = list_new();
            labels_stack = list_new();
            pscope = scope_del(pscope);   
            list_push(pscope->parser_stack, syntax);
        }
#line 1523 "bb.tab.c"
    break;

  case 16: /* global_identifier: T_IDENTIFIER '=' expression  */
#line 181 "babyc_parse.y"
        {
            Syntax *init = list_pop(pscope->parser_stack);
            Variable *v = scope_add_var(pscope, yyvsp[-2].symbol, current_object_type, GLOBAL);
            list_push(pscope->parser_stack, assignment_static_new(v, init));
        }
#line 1533 "bb.tab.c"
    break;

  case 17: /* global_identifier: T_IDENTIFIER  */
#line 188 "babyc_parse.y"
        {
            Variable *v = scope_add_var(pscope, yyvsp[0].symbol, current_object_type, GLOBAL);
            list_push(pscope->parser_stack, assignment_static_new(v, 0));
        }
#line 1542 "bb.tab.c"
    break;

  case 20: /* automatic_identifier: T_IDENTIFIER '=' expression  */
#line 202 "babyc_parse.y"
        {
            Syntax *init = list_pop(pscope->parser_stack);
            Variable *v = scope_add_var(pscope, yyvsp[-2].symbol, current_object_type, AUTOMATIC);
            list_push(pscope->parser_stack, assignment_new(v, init));
        }
#line 1552 "bb.tab.c"
    break;

  case 21: /* automatic_identifier: T_IDENTIFIER  */
#line 209 "babyc_parse.y"
        {
            scope_add_var(pscope, yyvsp[0].symbol, current_object_type, AUTOMATIC);
        }
#line 1560 "bb.tab.c"
    break;

  case 26: /* parameter: object_type T_IDENTIFIER  */
#line 226 "babyc_parse.y"
        {
            Variable *v = scope_add_var(pscope, yyvsp[0].symbol, current_object_type, PARAMETER);
            list_push(parameters_stack, function_parameter_new(v));
        }
#line 1569 "bb.tab.c"
    break;

  case 31: /* argument: expression  */
#line 245 "babyc_parse.y"
        {
            Syntax *argument = list_pop(pscope->parser_stack);
            list_push(pscope->arguments_stack, function_argument_new(argument));
        }
#line 1578 "bb.tab.c"
    break;

  case 32: /* $@2: %empty  */
#line 252 "babyc_parse.y"
                     { pscope = scope_new(pscope); }
#line 1584 "bb.tab.c"
    break;

  case 33: /* block: T_OPEN_BRACE $@2 full_block T_CLOSE_BRACE  */
#line 255 "babyc_parse.y"
        { 
            Syntax *syntax = block_new(pscope->parser_stack);
            pscope->parser_stack = list_new();
            pscope = scope_del(pscope);   
            list_push(pscope->parser_stack, syntax);
        }
#line 1595 "bb.tab.c"
    break;

  case 38: /* statement: T_GOTO T_IDENTIFIER ';'  */
#line 276 "babyc_parse.y"
        {
            Label *label = search_existing_label(yyvsp[-1].symbol);
            list_push(pscope->parser_stack, goto_statement_new(label));
        }
#line 1604 "bb.tab.c"
    break;

  case 39: /* statement: T_BREAK ';'  */
#line 282 "babyc_parse.y"
        {
            list_push(pscope->parser_stack, break_statement_new());
        }
#line 1612 "bb.tab.c"
    break;

  case 40: /* statement: T_CONTINUE ';'  */
#line 287 "babyc_parse.y"
        {
            list_push(pscope->parser_stack, continue_statement_new());
        }
#line 1620 "bb.tab.c"
    break;

  case 41: /* statement: T_LABEL ':'  */
#line 292 "babyc_parse.y"
        {
            Label *label = search_existing_label(yyvsp[-1].symbol);
            list_push(pscope->parser_stack, label_statement_new(label));
        }
#line 1629 "bb.tab.c"
    break;

  case 42: /* statement: T_RETURN expression ';'  */
#line 298 "babyc_parse.y"
        {
            Syntax *current_syntax = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, return_statement_new(current_syntax, current_function_type));
        }
#line 1638 "bb.tab.c"
    break;

  case 43: /* statement: T_IF '(' expression ')' statement  */
#line 304 "babyc_parse.y"
        {
            Syntax *if_else = nop_new();
            Syntax *if_then = list_pop(pscope->parser_stack);
            Syntax *condition = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, if_new(condition, if_then, if_else));
        }
#line 1649 "bb.tab.c"
    break;

  case 44: /* statement: T_IF '(' expression ')' statement T_ELSE statement  */
#line 312 "babyc_parse.y"
        {
            Syntax *if_else = list_pop(pscope->parser_stack);
            Syntax *if_then = list_pop(pscope->parser_stack);
            Syntax *condition = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, if_new(condition, if_then, if_else));
        }
#line 1660 "bb.tab.c"
    break;

  case 45: /* statement: T_WHILE '(' expression ')' statement  */
#line 320 "babyc_parse.y"
        {
            Syntax *body = list_pop(pscope->parser_stack);
            Syntax *condition = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, while_new(condition, body));
        }
#line 1670 "bb.tab.c"
    break;

  case 50: /* address: T_IDENTIFIER  */
#line 337 "babyc_parse.y"
        {
            Variable *v = scope_get_var(pscope, yyvsp[0].symbol);
            list_push(pscope->parser_stack, variable_new(v));            
        }
#line 1679 "bb.tab.c"
    break;

  case 51: /* address: '(' expression ')'  */
#line 342 "babyc_parse.y"
        {
            
        }
#line 1687 "bb.tab.c"
    break;

  case 52: /* expression: T_NUMBER  */
#line 349 "babyc_parse.y"
        {
            list_push(pscope->parser_stack, immediate_new(yyvsp[0].symbol));
        }
#line 1695 "bb.tab.c"
    break;

  case 53: /* expression: T_IDENTIFIER  */
#line 354 "babyc_parse.y"
        {
            Variable *v = scope_get_var(pscope, yyvsp[0].symbol);
            list_push(pscope->parser_stack, variable_new(v));
        }
#line 1704 "bb.tab.c"
    break;

  case 54: /* expression: '&' T_IDENTIFIER  */
#line 360 "babyc_parse.y"
        {
            Variable *v = scope_get_var(pscope, yyvsp[0].symbol);
            list_push(pscope->parser_stack, address_new(variable_new(v), immediate_new("0")));
        }
#line 1713 "bb.tab.c"
    break;

  case 55: /* expression: '&' T_IDENTIFIER '[' expression ']'  */
#line 366 "babyc_parse.y"
        {
            Variable *v = scope_get_var(pscope, yyvsp[-3].symbol);
            Syntax *offset = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, address_new(variable_new(v), offset));
        }
#line 1723 "bb.tab.c"
    break;

  case 56: /* expression: address '[' expression ']'  */
#line 373 "babyc_parse.y"
        {
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, read_pointer_new(address, offset));
        }
#line 1733 "bb.tab.c"
    break;

  case 57: /* expression: '*' address  */
#line 380 "babyc_parse.y"
        {
            Syntax *offset = immediate_new("0");
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, read_pointer_new(address, offset));
        }
#line 1743 "bb.tab.c"
    break;

  case 58: /* expression: T_IDENTIFIER '=' expression  */
#line 387 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, expression));
        }
#line 1753 "bb.tab.c"
    break;

  case 59: /* expression: T_IDENTIFIER T_PLUS_EQ expression  */
#line 394 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, addition_new(variable_new(v), expression)));
        }
#line 1763 "bb.tab.c"
    break;

  case 60: /* expression: T_IDENTIFIER T_MINUS_EQ expression  */
#line 401 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, subtraction_new(variable_new(v), expression)));
        }
#line 1773 "bb.tab.c"
    break;

  case 61: /* expression: T_IDENTIFIER T_MUL_EQ expression  */
#line 408 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, multiplication_new(variable_new(v), expression)));
        }
#line 1783 "bb.tab.c"
    break;

  case 62: /* expression: T_IDENTIFIER T_DIV_EQ expression  */
#line 415 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, division_new(variable_new(v), expression)));
        }
#line 1793 "bb.tab.c"
    break;

  case 63: /* expression: T_IDENTIFIER T_MOD_EQ expression  */
#line 422 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, modulus_new(variable_new(v), expression)));
        }
#line 1803 "bb.tab.c"
    break;

  case 64: /* expression: T_IDENTIFIER T_AND_EQ expression  */
#line 429 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, bitwise_and_new(variable_new(v), expression)));
        }
#line 1813 "bb.tab.c"
    break;

  case 65: /* expression: T_IDENTIFIER T_OR_EQ expression  */
#line 436 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, bitwise_or_new(variable_new(v), expression)));
        }
#line 1823 "bb.tab.c"
    break;

  case 66: /* expression: T_IDENTIFIER T_XOR_EQ expression  */
#line 443 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, bitwise_xor_new(variable_new(v), expression)));
        }
#line 1833 "bb.tab.c"
    break;

  case 67: /* expression: T_IDENTIFIER T_LSHIFT_EQ expression  */
#line 450 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, lshift_new(variable_new(v), expression)));
        }
#line 1843 "bb.tab.c"
    break;

  case 68: /* expression: T_IDENTIFIER T_RSHIFT_EQ expression  */
#line 457 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Variable *v = scope_get_var(pscope, yyvsp[-2].symbol);
            list_push(pscope->parser_stack, assignment_new(v, rshift_new(variable_new(v), expression)));
        }
#line 1853 "bb.tab.c"
    break;

  case 69: /* expression: address '[' expression ']' '=' expression  */
#line 464 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, expression));
        }
#line 1864 "bb.tab.c"
    break;

  case 70: /* expression: address '[' expression ']' T_PLUS_EQ expression  */
#line 472 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, addition_new(read_pointer_new(address, offset), expression)));
        }
#line 1875 "bb.tab.c"
    break;

  case 71: /* expression: address '[' expression ']' T_MINUS_EQ expression  */
#line 480 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, subtraction_new(read_pointer_new(address, offset), expression)));
        }
#line 1886 "bb.tab.c"
    break;

  case 72: /* expression: address '[' expression ']' T_MUL_EQ expression  */
#line 488 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, multiplication_new(read_pointer_new(address, offset), expression)));
        }
#line 1897 "bb.tab.c"
    break;

  case 73: /* expression: address '[' expression ']' T_DIV_EQ expression  */
#line 496 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, division_new(read_pointer_new(address, offset), expression)));
        }
#line 1908 "bb.tab.c"
    break;

  case 74: /* expression: address '[' expression ']' T_MOD_EQ expression  */
#line 504 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, modulus_new(read_pointer_new(address, offset), expression)));
        }
#line 1919 "bb.tab.c"
    break;

  case 75: /* expression: address '[' expression ']' T_LSHIFT_EQ expression  */
#line 512 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, lshift_new(read_pointer_new(address, offset), expression)));
        }
#line 1930 "bb.tab.c"
    break;

  case 76: /* expression: address '[' expression ']' T_RSHIFT_EQ expression  */
#line 520 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, rshift_new(read_pointer_new(address, offset), expression)));
        }
#line 1941 "bb.tab.c"
    break;

  case 77: /* expression: address '[' expression ']' T_AND_EQ expression  */
#line 528 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, bitwise_and_new(read_pointer_new(address, offset), expression)));
        }
#line 1952 "bb.tab.c"
    break;

  case 78: /* expression: address '[' expression ']' T_OR_EQ expression  */
#line 536 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, bitwise_or_new(read_pointer_new(address, offset), expression)));
        }
#line 1963 "bb.tab.c"
    break;

  case 79: /* expression: address '[' expression ']' T_XOR_EQ expression  */
#line 544 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = list_pop(pscope->parser_stack);
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, bitwise_xor_new(read_pointer_new(address, offset), expression)));
        }
#line 1974 "bb.tab.c"
    break;

  case 80: /* expression: '*' address '=' expression  */
#line 552 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            Syntax *offset = immediate_new("0");
            Syntax *address = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, write_pointer_new(address, offset, expression));
        }
#line 1985 "bb.tab.c"
    break;

  case 81: /* expression: '~' expression  */
#line 560 "babyc_parse.y"
        {
            Syntax *current_syntax = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, bitwise_negation_new(current_syntax));
        }
#line 1994 "bb.tab.c"
    break;

  case 82: /* expression: '!' expression  */
#line 566 "babyc_parse.y"
        {
            Syntax *current_syntax = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, logical_negation_new(current_syntax));
        }
#line 2003 "bb.tab.c"
    break;

  case 83: /* expression: '-' expression  */
#line 572 "babyc_parse.y"
        {
            Syntax *current_syntax = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, arithmetic_negation_new(current_syntax));
        }
#line 2012 "bb.tab.c"
    break;

  case 84: /* expression: '+' expression  */
#line 578 "babyc_parse.y"
        {
            /* already in AST */
        }
#line 2020 "bb.tab.c"
    break;

  case 85: /* expression: expression '+' expression  */
#line 583 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, addition_new(left, right));
        }
#line 2030 "bb.tab.c"
    break;

  case 86: /* expression: expression '-' expression  */
#line 590 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, subtraction_new(left, right));
        }
#line 2040 "bb.tab.c"
    break;

  case 87: /* expression: expression '*' expression  */
#line 597 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, multiplication_new(left, right));
        }
#line 2050 "bb.tab.c"
    break;

  case 88: /* expression: expression '/' expression  */
#line 604 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, division_new(left, right));
        }
#line 2060 "bb.tab.c"
    break;

  case 89: /* expression: expression '%' expression  */
#line 611 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, modulus_new(left, right));
        }
#line 2070 "bb.tab.c"
    break;

  case 90: /* expression: expression '&' expression  */
#line 618 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, bitwise_and_new(left, right));
        }
#line 2080 "bb.tab.c"
    break;

  case 91: /* expression: expression '|' expression  */
#line 625 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, bitwise_or_new(left, right));
        }
#line 2090 "bb.tab.c"
    break;

  case 92: /* expression: expression '^' expression  */
#line 632 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, bitwise_xor_new(left, right));
        }
#line 2100 "bb.tab.c"
    break;

  case 93: /* expression: expression T_RSHIFT expression  */
#line 639 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, rshift_new(left, right));
        }
#line 2110 "bb.tab.c"
    break;

  case 94: /* expression: expression T_LSHIFT expression  */
#line 646 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, lshift_new(left, right));
        }
#line 2120 "bb.tab.c"
    break;

  case 95: /* expression: expression T_LOGICAL_OR expression  */
#line 653 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, logical_or_new(left, right));
        }
#line 2130 "bb.tab.c"
    break;

  case 96: /* expression: expression T_LOGICAL_AND expression  */
#line 660 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, logical_and_new(left, right));
        }
#line 2140 "bb.tab.c"
    break;

  case 97: /* expression: expression '<' expression  */
#line 667 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, less_than_new(left, right));
        }
#line 2150 "bb.tab.c"
    break;

  case 98: /* expression: expression '>' expression  */
#line 674 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, larger_than_new(left, right));
        }
#line 2160 "bb.tab.c"
    break;

  case 99: /* expression: expression T_EQUAL expression  */
#line 681 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, equal_new(left, right));
        }
#line 2170 "bb.tab.c"
    break;

  case 100: /* expression: expression T_NEQUAL expression  */
#line 688 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, nequal_new(left, right));
        }
#line 2180 "bb.tab.c"
    break;

  case 101: /* expression: expression T_LARGER_OR_EQUAL expression  */
#line 695 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, larger_or_equal_new(left, right));
        }
#line 2190 "bb.tab.c"
    break;

  case 102: /* expression: expression T_LESS_OR_EQUAL expression  */
#line 702 "babyc_parse.y"
        {
            Syntax *right = list_pop(pscope->parser_stack);
            Syntax *left = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, less_or_equal_new(left, right));
        }
#line 2200 "bb.tab.c"
    break;

  case 103: /* expression: T_SIZEOF '(' object_type ')'  */
#line 709 "babyc_parse.y"
        {
            list_push(pscope->parser_stack, object_type_size_syntax(current_object_type));
            current_object_type = saved_object_type;
        }
#line 2209 "bb.tab.c"
    break;

  case 104: /* $@3: %empty  */
#line 714 "babyc_parse.y"
                        { current_cast_type = current_object_type;  current_object_type = saved_object_type; }
#line 2215 "bb.tab.c"
    break;

  case 105: /* expression: '(' object_type $@3 ')' expression  */
#line 715 "babyc_parse.y"
        {
            Syntax *expression = list_pop(pscope->parser_stack);
            list_push(pscope->parser_stack, cast_new(current_cast_type, expression));
           
        }
#line 2225 "bb.tab.c"
    break;

  case 106: /* expression: T_SIZEOF '(' T_IDENTIFIER ')'  */
#line 722 "babyc_parse.y"
        {
            Variable *v = scope_get_var(pscope, yyvsp[-1].symbol);
            if (!v) {
                log_error("Should only get sizeof(%s) from valid variables", yyvsp[-1].symbol);
            }
            list_push(pscope->parser_stack, object_type_size_syntax(v->objectType));
        }
#line 2237 "bb.tab.c"
    break;

  case 107: /* $@4: %empty  */
#line 730 "babyc_parse.y"
                         { pscope = scope_new(pscope); }
#line 2243 "bb.tab.c"
    break;

  case 108: /* expression: T_IDENTIFIER '(' $@4 argument_list ')'  */
#line 731 "babyc_parse.y"
        {
            List *l = list_swap(pscope->arguments_stack);
            pscope->arguments_stack = list_new();
            pscope = scope_del(pscope);   
            list_push(pscope->parser_stack, function_call_new(yyvsp[-4].symbol, l));
        }
#line 2254 "bb.tab.c"
    break;


#line 2258 "bb.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

