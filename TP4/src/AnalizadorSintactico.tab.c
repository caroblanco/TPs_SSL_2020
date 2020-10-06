
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "AnalizadorSintactico.y"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YYDEBUG 1

int flag_error = 0; 

int yylex();

int yywrap()
{
    return(1);
}

void yyerror (char *smth) {
   fprintf ("encontre: %s\n", smth);
}

FILE* yyin;
FILE* yyout;



/* Line 189 of yacc.c  */
#line 99 "AnalizadorSintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMERO_ENTERO = 258,
     NUMERO_REAL = 259,
     TIPO_DATO = 260,
     IDENTIFICADOR = 261,
     LITERALCADENA = 262,
     CARACTER = 263,
     PALABRA_RESERVADA = 264,
     P_INC = 265,
     P_DEC = 266,
     DISTINTO = 267,
     IGUAL = 268,
     AND = 269,
     OR = 270,
     DIV_IGUAL = 271,
     POR_IGUAL = 272,
     MENOS_IGUAL = 273,
     MAS_IGUAL = 274,
     MENOR_IGUAL = 275,
     MAYOR_IGUAL = 276,
     MOD_IGUAL = 277,
     BIT_SHIFT_L = 278,
     BIT_SHIFT_R = 279,
     FLECHITA = 280,
     SIZEOF = 281,
     ENUM = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 62 "AnalizadorSintactico.y"

    int entero;
    char* texto;
    char caracter;
    float real;



/* Line 214 of yacc.c  */
#line 171 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 183 "AnalizadorSintactico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNRULES -- Number of states.  */
#define YYNSTATES  327

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    41,    34,     2,
      42,    43,    40,    37,    49,    38,    48,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    29,
      36,    30,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    32,    54,    45,     2,     2,     2,
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
      25,    26,    27,    50,    51,    52,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      23,    27,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    54,    56,    60,    61,    63,    65,    69,    71,
      75,    77,    81,    83,    87,    89,    93,    97,    99,   103,
     107,   111,   115,   117,   121,   125,   127,   131,   135,   139,
     141,   146,   148,   151,   154,   157,   160,   162,   164,   166,
     168,   170,   172,   174,   176,   178,   183,   188,   192,   196,
     199,   202,   204,   208,   210,   212,   214,   216,   220,   222,
     224,   226,   228,   230,   232,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   257,   262,   266,   270,   273,
     274,   276,   277,   279,   282,   284,   286,   289,   295,   302,
     308,   314,   321,   331,   336,   340,   344,   348,   351,   354,
     358,   359,   361,   366,   370,   371,   373,   376,   379,   382,
     383,   385,   387,   389,   391,   393,   395,   397,   399,   401,
     403,   405,   407,   413,   416,   417,   419,   421,   423,   425,
     428,   432,   435,   438,   439,   441,   443,   447,   448,   450,
     453,   454,   456,   459,   463,   464,   466,   468,   471,   473,
     477,   482,   487,   492,   493,   495,   497,   503,   505,   509,
     512,   515,   517,   521,   527,   530,   532,   536,   538,   542,
     544,   546,   547,   549,   551,   554,   556,   557,   559,   563,
     568,   573,   574,   576,   577,   579,   581,   584,   586,   588
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      74,     0,    -1,    -1,    74,    75,    -1,    28,    -1,    76,
      28,    -1,    99,    28,    -1,   112,    28,    -1,   151,    28,
      -1,    77,    -1,    76,    29,    77,    -1,    91,    78,    77,
      -1,    79,    -1,     1,    -1,    30,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    22,    -1,    80,    -1,    81,
      76,    31,    79,    -1,    82,    -1,    80,    15,    82,    -1,
      -1,    80,    -1,    83,    -1,    82,    14,    83,    -1,    84,
      -1,    83,    32,    84,    -1,    85,    -1,    84,    33,    85,
      -1,    86,    -1,    85,    34,    86,    -1,    87,    -1,    86,
      13,    87,    -1,    86,    12,    87,    -1,    88,    -1,    87,
      21,    88,    -1,    87,    35,    88,    -1,    87,    20,    88,
      -1,    87,    36,    88,    -1,    89,    -1,    88,    37,    89,
      -1,    88,    38,    89,    -1,    90,    -1,    89,    39,    90,
      -1,    89,    40,    90,    -1,    89,    41,    90,    -1,    91,
      -1,    42,    97,    43,    90,    -1,    94,    -1,    92,    91,
      -1,    93,    90,    -1,    91,    92,    -1,    26,    91,    -1,
      10,    -1,    11,    -1,    34,    -1,    40,    -1,    38,    -1,
      44,    -1,    37,    -1,    45,    -1,    96,    -1,    94,    46,
      76,    47,    -1,    94,    42,    95,    43,    -1,    94,    48,
      98,    -1,    94,    25,    98,    -1,    94,    10,    -1,    94,
      11,    -1,    77,    -1,    95,    49,    77,    -1,    98,    -1,
       3,    -1,     4,    -1,     7,    -1,    42,    76,    43,    -1,
       5,    -1,    50,    -1,    51,    -1,    52,    -1,    27,    -1,
       6,    -1,     6,    30,    76,    -1,     1,    -1,   100,    -1,
     101,    -1,   111,    -1,   106,    -1,   107,    -1,   108,    -1,
     109,    -1,     1,    -1,   110,    29,    -1,    53,   103,   102,
      54,    -1,    53,   104,    54,    -1,    53,   105,    54,    -1,
      53,    54,    -1,    -1,   105,    -1,    -1,   104,    -1,   104,
     112,    -1,   112,    -1,    99,    -1,   105,    99,    -1,    55,
      42,    76,    43,    99,    -1,    55,    42,    76,    43,    56,
      99,    -1,    57,    42,    76,    43,    99,    -1,    58,    42,
      76,    43,    99,    -1,    59,    99,    58,    42,    76,    43,
      -1,    60,    42,   110,    29,   110,    29,   110,    43,    99,
      -1,    61,   146,    31,    99,    -1,    62,    31,    99,    -1,
       6,    31,    99,    -1,    63,   110,    29,    -1,    64,    29,
      -1,    65,    29,    -1,    66,     6,    29,    -1,    -1,    76,
      -1,     6,    30,    76,    29,    -1,   114,   113,    29,    -1,
      -1,   122,    -1,   116,   115,    -1,   117,   115,    -1,   118,
     115,    -1,    -1,   114,    -1,    51,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    97,    -1,   119,    -1,   139,
      -1,   143,    -1,    71,    -1,    72,    -1,   121,   120,    53,
     122,    54,    -1,   121,     6,    -1,    -1,     6,    -1,    50,
      -1,    52,    -1,   123,    -1,   122,   123,    -1,   124,   126,
      29,    -1,   117,   125,    -1,   118,   125,    -1,    -1,   124,
      -1,   126,    -1,   127,    31,   146,    -1,    -1,   128,    -1,
     129,   133,    -1,    -1,   130,    -1,    40,   131,    -1,    40,
     131,   130,    -1,    -1,   132,    -1,   118,    -1,   132,   118,
      -1,     6,    -1,    42,   128,    43,    -1,   133,    46,   147,
      47,    -1,   133,    42,   135,    43,    -1,   133,    42,   134,
      43,    -1,    -1,   138,    -1,   136,    -1,   136,    49,    48,
      48,    48,    -1,   137,    -1,   136,    49,   137,    -1,   114,
     128,    -1,   114,   144,    -1,     6,    -1,   138,    49,     6,
      -1,    27,   120,    53,   140,    54,    -1,    27,     6,    -1,
     141,    -1,   140,    49,   141,    -1,   142,    -1,   142,    30,
     146,    -1,     6,    -1,     6,    -1,    -1,   145,    -1,   130,
      -1,   129,   148,    -1,    79,    -1,    -1,   146,    -1,    42,
     145,    43,    -1,   150,    46,   147,    47,    -1,   150,    42,
     149,    43,    -1,    -1,   135,    -1,    -1,   148,    -1,   152,
      -1,   151,   152,    -1,   153,    -1,   112,    -1,   115,   128,
     103,   101,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    74,    77,    78,    79,    80,    81,    86,
      87,    90,    91,    92,    95,    95,    95,    95,    95,    95,
      98,    99,   102,   103,   106,   107,   110,   111,   114,   115,
     118,   119,   122,   123,   126,   127,   128,   130,   131,   132,
     133,   134,   142,   143,   144,   147,   148,   149,   150,   153,
     154,   157,   158,   159,   160,   161,   164,   165,   168,   168,
     168,   168,   168,   168,   171,   172,   173,   174,   175,   176,
     177,   180,   181,   184,   185,   186,   187,   188,   191,   191,
     191,   191,   191,   194,   195,   196,   201,   202,   203,   204,
     205,   206,   207,   208,   211,   214,   215,   216,   217,   220,
     221,   224,   225,   228,   229,   232,   233,   236,   237,   238,
     241,   242,   243,   246,   247,   248,   251,   252,   253,   254,
     257,   258,   261,   267,   270,   271,   274,   275,   276,   279,
     280,   304,   304,   304,   304,   304,   307,   308,   309,   310,
     313,   313,   316,   317,   320,   321,   324,   325,   328,   329,
     332,   335,   336,   339,   340,   347,   348,   351,   352,   355,
     358,   359,   362,   363,   366,   367,   370,   371,   374,   375,
     376,   377,   378,   381,   382,   385,   386,   389,   390,   393,
     394,   397,   398,   401,   402,   405,   406,   409,   410,   413,
     416,   422,   423,   425,   426,   429,   432,   433,   436,   437,
     438,   441,   442,   445,   446,   450,   451,   454,   455,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO_ENTERO", "NUMERO_REAL",
  "TIPO_DATO", "IDENTIFICADOR", "LITERALCADENA", "CARACTER",
  "PALABRA_RESERVADA", "P_INC", "P_DEC", "DISTINTO", "IGUAL", "AND", "OR",
  "DIV_IGUAL", "POR_IGUAL", "MENOS_IGUAL", "MAS_IGUAL", "MENOR_IGUAL",
  "MAYOR_IGUAL", "MOD_IGUAL", "BIT_SHIFT_L", "BIT_SHIFT_R", "FLECHITA",
  "SIZEOF", "ENUM", "'\\n'", "';'", "'='", "':'", "'|'", "'^'", "'&'",
  "'>'", "'<'", "'+'", "'-'", "'/'", "'*'", "'%'", "'('", "')'", "'!'",
  "'~'", "'['", "']'", "'.'", "','", "\"struct\"", "\"typedef\"",
  "\"union\"", "'{'", "'}'", "\"if\"", "\"else\"", "\"switch\"",
  "\"while\"", "\"do\"", "\"for\"", "\"case\"", "\"default\"",
  "\"return\"", "\"continue\"", "\"break\"", "\"goto\"", "\"static\"",
  "\"auto\"", "\"register\"", "\"extern\"", "\"const\"", "\"volatile\"",
  "$accept", "input", "line", "expresion", "expresionAs", "operadorAs",
  "expCondicional", "expOr", "expOrOP", "expAnd", "expOInclusivo",
  "expOExcluyente", "expY", "expIgualdad", "expRelacional", "expAditiva",
  "expMultiplicativa", "expConversion", "expUnaria", "incremento",
  "operUnario", "expSufijo", "listaArgumentos", "expPrimaria",
  "nombreTipo", "ID", "sentencia", "sentExp", "sentCompuesta",
  "listaSentenciasOP", "listaDeclaracionesOP", "listaDeclaraciones",
  "listaSentencias", "sentSeleccion", "sentIteracion", "sentEtiquetada",
  "sentSalto", "expresionOP", "sentAsignacion", "declaracion",
  "listaDecOP", "espeDec", "espeDecOP", "espeClasAlma", "espeTipo",
  "caliTipo", "especificadorSU", "IDENTIFICADOROP", "SU", "listaDecS",
  "declaracionS", "listCali", "listCaliOP", "declaS", "declaOP", "decla",
  "punteroOP", "puntero", "listCaliTiposOP", "listCaliTipos", "decDirec",
  "listIdenOP", "listTipoPar", "listParam", "decParam", "listIden",
  "especificadorE", "listEnum", "enumerador", "constEnum", "nombreTypedef",
  "decAbstractOP", "decAbstract", "expConst", "expConstOP", "decAbstDirec",
  "listTipoParOP", "decAbstDirecOP", "unidadDeTraduccion", "decExterna",
  "defFuncion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    10,    59,
      61,    58,   124,    94,    38,    62,    60,    43,    45,    47,
      42,    37,    40,    41,    33,   126,    91,    93,    46,    44,
     283,   284,   285,   123,   125,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    74,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   101,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   111,   112,   113,   113,   114,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   117,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     143,   144,   144,   145,   145,   146,   147,   147,   148,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     0,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     2,
       2,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     3,     3,     2,     0,
       1,     0,     1,     2,     1,     1,     2,     5,     6,     5,
       5,     6,     9,     4,     3,     3,     3,     2,     2,     3,
       0,     1,     4,     3,     0,     1,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     0,     1,     1,     1,     1,     2,
       3,     2,     2,     0,     1,     1,     3,     0,     1,     2,
       0,     1,     2,     3,     0,     1,     1,     2,     1,     3,
       4,     4,     4,     0,     1,     1,     5,     1,     3,     2,
       2,     1,     3,     5,     2,     1,     3,     1,     3,     1,
       1,     0,     1,     1,     2,     1,     0,     1,     3,     4,
       4,     0,     1,     0,     1,     1,     2,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    85,    74,    75,    78,    83,    76,    56,
      57,     0,    82,     4,    58,    62,    60,    59,     0,    61,
      63,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   133,   134,   135,
     140,   141,     3,     0,     9,    12,    20,     0,    22,    26,
      28,    30,    32,    34,    37,    42,    45,    49,     0,     0,
      51,    64,   136,    73,     0,    86,    87,    89,    90,    91,
      92,     0,    88,   208,   130,   160,   129,   129,   129,   137,
     144,   138,   139,   129,   205,   207,     0,     0,    85,    83,
       0,    55,   184,     0,    13,    82,    79,    80,    81,     0,
       0,    98,   121,   105,     0,   102,     0,   104,   124,     0,
       0,     0,    83,     0,     0,   195,    49,     0,     0,     0,
     117,   118,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    14,     0,    54,
      52,    53,    69,    70,     0,     0,     0,     0,     6,    94,
       7,   190,     0,   153,   153,   125,   148,   160,   164,   101,
       0,   161,   130,   126,   127,   128,   143,     0,     8,   208,
     206,    84,   115,     0,     0,    77,     0,     0,     0,    96,
     103,    97,   106,     0,     0,     0,     0,     0,     0,   114,
     116,   119,    10,    23,     0,    27,    29,    31,    33,    36,
      35,    40,    38,    39,    41,    43,    44,    46,    47,    48,
      11,    68,    71,     0,     0,    67,   123,   154,   151,   152,
     149,     0,     0,   158,   166,   162,   165,     0,   102,   168,
     160,   159,     0,     0,    84,   189,     0,   185,   187,    50,
      95,     0,     0,     0,     0,     0,   113,    21,    66,     0,
      65,   150,     0,   163,   167,   209,     0,   173,     0,     0,
       0,   183,     0,     0,   107,   109,   110,     0,     0,    72,
     156,   169,   190,   160,     0,     0,   175,   177,   174,   197,
       0,   142,   186,   188,   108,   111,     0,   179,   203,   161,
     180,   192,   172,   171,     0,     0,   170,     0,   160,   194,
       0,     0,   178,   182,     0,     0,   201,     0,     0,   112,
     198,   202,     0,     0,   176,   200,   199
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    42,   102,    44,   148,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,   223,    61,    62,    63,   103,    65,    66,   187,
     104,   105,   106,    67,    68,    69,    70,    71,    72,   107,
     162,   108,    75,    76,    77,    78,    79,    93,    80,   165,
     166,   167,   228,   231,   232,   266,   170,   171,   235,   236,
     241,   284,   285,   286,   287,   288,    81,   246,   247,   248,
      82,   300,   301,   289,   290,   309,   322,   310,    83,    84,
      85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -274
static const yytype_int16 yypact[] =
{
    -274,   290,  -274,  1128,  -274,  -274,  -274,   153,  -274,  -274,
    -274,  1076,     7,  -274,  -274,  -274,  -274,  -274,   949,  -274,
    -274,    15,  -274,    21,   362,    -3,    74,   104,   883,   112,
    1121,    23,  1018,    81,   138,   166,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,   128,  -274,  -274,   162,  1134,   168,   163,
     154,   173,     8,    43,    47,    56,  -274,   133,  1076,  1121,
     232,  -274,  -274,  -274,   169,  -274,  -274,  -274,  -274,  -274,
    -274,   190,  -274,   200,   517,   191,   443,   443,   443,  -274,
     224,  -274,  -274,   142,  -274,  -274,  1134,   883,  -274,   202,
    1134,   164,   180,   182,  -274,  -274,  -274,  -274,  -274,   -14,
     193,  -274,   210,  -274,   619,   430,   685,  -274,    19,  1134,
    1134,  1134,   155,   187,  1018,  -274,   164,   215,   883,   219,
    -274,  -274,   220,  -274,  1134,  1121,   111,  1121,  1121,  1121,
    1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,
    1121,  1121,  -274,  -274,  -274,  -274,  -274,  -274,  1134,  -274,
     164,  -274,  -274,  -274,    97,  1134,  1134,    97,  -274,  -274,
    -274,  -274,   221,    19,    19,    19,  -274,    27,   118,   443,
      10,  -274,  -274,  -274,  -274,  -274,   180,   203,  -274,  -274,
    -274,   226,  -274,  1134,   252,  -274,  1121,   205,   751,  -274,
    -274,  -274,  -274,   -10,     1,    12,   225,   239,   883,  -274,
    -274,  -274,  -274,   168,  1121,   163,   154,   173,     8,    43,
      43,    47,    47,    47,    47,    56,    56,  -274,  -274,  -274,
    -274,  -274,  -274,   -12,   -20,  -274,  -274,  -274,  -274,  -274,
    -274,   240,   241,  -274,  -274,   191,   118,   218,   443,  -274,
     191,    -6,    19,   553,   210,  -274,    55,  -274,   245,  -274,
    -274,   817,   883,   883,  1134,  1018,  -274,  -274,  -274,  1134,
    -274,  -274,  1121,  -274,  -274,  -274,   233,   469,  1001,   211,
     252,  -274,  1121,   883,  -274,  -274,  -274,    18,   248,  -274,
    -274,  -274,   -11,    40,   238,   242,   235,  -274,   237,  -274,
     251,  -274,  -274,  -274,  -274,  -274,  1063,  -274,    11,    16,
    -274,  -274,  -274,  -274,   437,   281,  -274,   249,   191,    20,
      99,   254,  -274,  -274,   883,   256,   443,  1001,   257,  -274,
    -274,  -274,   261,   259,  -274,  -274,  -274
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -274,  -274,  -274,    25,  -106,  -274,   -28,  -274,  -274,   183,
     161,   179,   181,   192,    68,    26,    64,   -47,    -8,   -43,
    -274,  -274,  -274,  -274,   293,    14,     0,  -274,    75,  -274,
     144,   151,   217,  -274,  -274,  -274,  -274,   -26,  -274,     3,
    -274,    -1,    88,  -274,   -51,   -63,  -274,   243,  -274,    83,
    -131,    63,   165,  -274,  -274,   -68,  -273,  -227,  -274,  -274,
    -274,  -274,    17,  -274,    22,  -274,  -274,  -274,    61,  -274,
    -274,  -274,    28,   -25,    29,  -274,  -274,  -274,  -274,   255,
    -274
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -205
static const yytype_int16 yytable[] =
{
      74,    64,   115,    91,    73,   117,   119,   169,   263,   124,
     298,   164,   151,    92,   149,   124,   239,   239,   202,   124,
     131,   132,   116,   163,     6,   161,    43,   260,   113,   185,
     124,   258,  -181,   251,   230,   298,   267,   259,  -181,   109,
     268,   124,   220,    99,   252,   164,    12,   124,   149,   222,
     150,   116,   240,   308,   118,   253,   299,   163,  -157,  -193,
    -144,   295,  -204,   133,   134,  -193,  -204,   168,  -146,    21,
      97,    23,   126,   149,  -147,   172,   172,   172,   135,   136,
     168,   299,    74,  -191,   137,   138,   179,   182,   197,  -191,
      40,    41,   217,   218,   219,   139,   140,   141,    88,   233,
     164,   164,   164,    89,   270,   234,   192,   149,   190,   271,
     120,   181,   163,   163,   163,    99,   110,   116,   199,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   193,   194,   195,   202,   230,   249,
     124,   316,   204,     9,    10,   317,   111,     6,   161,   142,
     143,   144,   145,   279,   114,   146,   123,   124,  -190,   211,
     212,   213,   214,   147,   173,   174,   175,   121,   221,    12,
     178,   225,   122,   264,     9,    10,   257,   125,   116,   164,
    -190,   224,   127,    86,    87,    86,    87,   129,   192,    40,
      41,   163,    21,    22,    23,   128,   116,   158,   256,   209,
     210,   215,   216,  -190,  -190,  -190,   164,   130,   244,    36,
      37,    38,    39,    40,    41,   297,     6,   161,   163,   159,
    -190,  -190,  -190,  -190,  -190,  -190,   227,   227,   160,   278,
     176,   168,   183,  -145,   115,   184,   186,   280,    12,   124,
     115,   190,   152,   153,   115,   196,   198,   293,   200,   201,
     226,   274,   275,   276,   116,   243,   242,   154,   245,   250,
     116,    21,    97,    23,   116,   291,   283,   254,   255,   261,
     307,    24,   262,   294,   155,   272,   281,   296,   156,   277,
     157,   302,    40,    41,   304,   303,   305,   313,   205,   115,
       2,     3,   314,     4,     5,     6,     7,     8,   306,   320,
       9,    10,   318,   283,   325,   324,   326,   206,   203,   116,
     207,   100,   265,   237,   319,   283,    11,    12,    13,  -120,
     238,   188,   208,   177,    14,   269,   312,    15,    16,   229,
      17,   292,    18,   321,    19,    20,   315,     0,   180,     0,
      21,    22,    23,    24,     0,    25,   323,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     3,     0,     4,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,  -101,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,    17,     0,    18,     0,    19,    20,     0,     0,
       0,     0,    21,    22,    23,    24,   101,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     6,   161,     0,     0,     0,
       0,     0,     6,   161,     0,     0,     0,     0,     6,   161,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     6,   282,     0,     0,     0,     0,
      21,    22,    23,     0,   189,   311,     0,    21,    22,    23,
       0,     0,     0,    21,    22,    23,    12,    36,    37,    38,
      39,    40,    41,     0,    36,    37,    38,    39,    40,    41,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    21,
      22,    23,     6,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,     0,     0,    12,     0,  -124,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     4,     5,     0,    89,
       8,     0,     0,     9,    10,     0,     0,    21,    97,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,  -122,  -122,     0,     0,     0,     0,    14,    40,    41,
      15,    16,     0,    17,     0,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,  -122,  -122,  -122,     0,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
       3,     0,     4,     5,     0,   112,     8,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,  -120,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,    17,
       0,    18,     0,    19,    20,     0,     0,     0,     0,     0,
       0,     0,    24,   -99,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     3,     0,     4,     5,
       0,   112,     8,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,  -120,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,     0,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,    24,   191,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     3,     0,     4,     5,     0,   112,     8,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
    -120,     0,     0,     0,     0,    14,     0,     0,    15,    16,
       0,    17,     0,    18,     0,    19,    20,     0,     0,     0,
       0,     0,     0,     0,    24,  -100,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     3,     0,
       4,     5,     0,   112,     8,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,  -120,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,    17,     0,    18,
       0,    19,    20,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    25,   273,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     3,     0,     4,     5,     0,   112,
       8,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,  -120,     0,     0,     0,     0,    14,     0,     0,
      15,    16,     0,    17,     0,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,    24,     0,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      94,     0,     4,     5,     6,    89,     8,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    95,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,    17,
       0,    18,     0,    19,    20,     0,     0,     0,     0,    96,
      97,    98,    88,     0,     4,     5,     0,    89,     8,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,    94,
       0,     4,     5,     0,    89,     8,     0,    11,     9,    10,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
       0,    17,     0,    18,    11,    19,    20,  -120,  -196,     0,
       0,     0,    14,     0,     0,    15,    16,     0,    17,     0,
      18,     0,    19,    20,    94,     0,     4,     5,     0,    89,
       8,     0,     0,     9,    10,     0,     0,    88,     0,     4,
       5,     0,    89,     8,     0,     0,     9,    10,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,    11,    17,     0,    18,  -120,    19,    20,     0,
      14,     0,     0,    15,    16,     0,    17,     0,    90,     0,
      19,    20,    88,     0,     4,     5,     0,    89,     8,     0,
       0,     9,    10,     0,     0,    94,     0,     4,     5,     0,
      89,     8,     0,     0,     9,    10,     0,    11,     0,     0,
       0,     0,     0,     0,     0,    14,   -13,   -13,    15,    16,
      11,    17,     0,    18,     0,    19,    20,     0,    14,     0,
       0,    15,    16,     0,    17,     0,    18,     0,    19,    20,
       0,   -93,   -93,   -93,     0,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93
};

static const yytype_int16 yycheck[] =
{
       1,     1,    30,    11,     1,    30,    32,    75,   235,    29,
     283,    74,    59,     6,    57,    29,     6,     6,   124,    29,
      12,    13,    30,    74,     5,     6,     1,    47,    28,    43,
      29,    43,    43,    43,   165,   308,    42,    49,    49,    42,
      46,    29,   148,    18,    43,   108,    27,    29,    91,   155,
      58,    59,    42,    42,    31,    43,   283,   108,    31,    43,
      53,    43,    42,    20,    21,    49,    46,    40,    53,    50,
      51,    52,    47,   116,    53,    76,    77,    78,    35,    36,
      40,   308,    83,    43,    37,    38,    83,    87,   114,    49,
      71,    72,   139,   140,   141,    39,    40,    41,     1,   167,
     163,   164,   165,     6,    49,   168,   106,   150,   105,    54,
      29,    86,   163,   164,   165,    90,    42,   125,   118,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   109,   110,   111,   243,   269,   186,
      29,    42,    31,    10,    11,    46,    42,     5,     6,    16,
      17,    18,    19,   259,    42,    22,    28,    29,     5,   133,
     134,   135,   136,    30,    76,    77,    78,    29,   154,    27,
      28,   157,     6,   236,    10,    11,   204,    15,   186,   242,
      27,   156,    14,    30,    31,    30,    31,    33,   188,    71,
      72,   242,    50,    51,    52,    32,   204,    28,   198,   131,
     132,   137,   138,    50,    51,    52,   269,    34,   183,    67,
      68,    69,    70,    71,    72,   283,     5,     6,   269,    29,
      67,    68,    69,    70,    71,    72,   163,   164,    28,   255,
       6,    40,    30,    53,   262,    53,    43,   262,    27,    29,
     268,   238,    10,    11,   272,    58,    31,   272,    29,    29,
      29,   251,   252,   253,   262,    29,    53,    25,     6,    54,
     268,    50,    51,    52,   272,    54,   267,    42,    29,    29,
     296,    53,    31,   273,    42,    30,    43,    29,    46,   254,
      48,    43,    71,    72,    49,    43,    49,     6,   127,   317,
       0,     1,    43,     3,     4,     5,     6,     7,    47,    43,
      10,    11,    48,   304,    43,    48,    47,   128,   125,   317,
     129,    18,   237,   169,   314,   316,    26,    27,    28,    29,
     169,   104,   130,    80,    34,   242,   304,    37,    38,   164,
      40,   270,    42,   316,    44,    45,   308,    -1,    83,    -1,
      50,    51,    52,    53,    -1,    55,   317,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     5,     6,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    54,    48,    -1,    50,    51,    52,
      -1,    -1,    -1,    50,    51,    52,    27,    67,    68,    69,
      70,    71,    72,    -1,    67,    68,    69,    70,    71,    72,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    50,
      51,    52,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,     6,
       7,    -1,    -1,    10,    11,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    71,    72,
      37,    38,    -1,    40,    -1,    42,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       1,    -1,     3,     4,    -1,     6,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     1,    -1,     3,     4,
      -1,     6,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     1,    -1,     3,     4,    -1,     6,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     1,    -1,
       3,     4,    -1,     6,     7,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     1,    -1,     3,     4,    -1,     6,
       7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,     1,    -1,     3,     4,    -1,     6,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    -1,     6,     7,    -1,    26,    10,    11,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    26,    44,    45,    29,    47,    -1,
      -1,    -1,    34,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    45,     1,    -1,     3,     4,    -1,     6,
       7,    -1,    -1,    10,    11,    -1,    -1,     1,    -1,     3,
       4,    -1,     6,     7,    -1,    -1,    10,    11,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    26,    40,    -1,    42,    43,    44,    45,    -1,
      34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,    -1,
      44,    45,     1,    -1,     3,     4,    -1,     6,     7,    -1,
      -1,    10,    11,    -1,    -1,     1,    -1,     3,     4,    -1,
       6,     7,    -1,    -1,    10,    11,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    28,    29,    37,    38,
      26,    40,    -1,    42,    -1,    44,    45,    -1,    34,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,    45,
      -1,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,     0,     1,     3,     4,     5,     6,     7,    10,
      11,    26,    27,    28,    34,    37,    38,    40,    42,    44,
      45,    50,    51,    52,    53,    55,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    77,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    97,    98,    99,   100,   101,   106,   107,   108,
     109,   110,   111,   112,   114,   115,   116,   117,   118,   119,
     121,   139,   143,   151,   152,   153,    30,    31,     1,     6,
      42,    91,     6,   120,     1,    27,    50,    51,    52,    76,
      97,    54,    76,    99,   103,   104,   105,   112,   114,    42,
      42,    42,     6,    99,    42,    79,    91,   146,    31,   110,
      29,    29,     6,    28,    29,    15,    76,    14,    32,    33,
      34,    12,    13,    20,    21,    35,    36,    37,    38,    39,
      40,    41,    16,    17,    18,    19,    22,    30,    78,    92,
      91,    90,    10,    11,    25,    42,    46,    48,    28,    29,
      28,     6,   113,   117,   118,   122,   123,   124,    40,   128,
     129,   130,   114,   115,   115,   115,     6,   120,    28,   112,
     152,    76,    99,    30,    53,    43,    43,   102,   105,    54,
     112,    54,    99,    76,    76,    76,    58,   110,    31,    99,
      29,    29,    77,    82,    31,    83,    84,    85,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    90,    90,    90,
      77,    98,    77,    95,    76,    98,    29,   124,   125,   125,
     123,   126,   127,   128,   118,   131,   132,   103,   104,     6,
      42,   133,    53,    29,    76,     6,   140,   141,   142,    90,
      54,    43,    43,    43,    42,    29,    99,    79,    43,    49,
      47,    29,    31,   130,   118,   101,   128,    42,    46,   122,
      49,    54,    30,    56,    99,    99,    99,    76,   110,    77,
     146,    43,     6,   114,   134,   135,   136,   137,   138,   146,
     147,    54,   141,   146,    99,    43,    29,   128,   129,   130,
     144,   145,    43,    43,    49,    49,    47,   110,    42,   148,
     150,    48,   137,     6,    43,   145,    42,    46,    48,    99,
      43,   135,   149,   147,    48,    43,    47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 77 "AnalizadorSintactico.y"
    {fprintf(yyout,"\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 78 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------EXPRESION--------");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 79 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------SENTENCIA--------");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 80 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------DECLARACION--------");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 81 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------FUNCION--------");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ; \n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "AnalizadorSintactico.y"
    {printf("ERROR al declarar la expresion asignacion \n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 99 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un : \n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 103 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un || \n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 111 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un && \n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un | \n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 119 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ^ \n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 123 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un & \n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 127 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un == \n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 128 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un != \n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 131 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un >= \n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un > \n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 133 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un <= \n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 134 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un >= \n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 143 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un + \n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 144 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un - \n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 148 "AnalizadorSintactico.y"
    { if((yyvsp[(3) - (3)].real) == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real); fprintf(yyout,"se encontro un / \n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 149 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un * \n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 150 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un % \n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 164 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ++ \n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 165 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -- \n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 172 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro [ y ] \n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 173 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ( y un )\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 174 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un . \n"); fprintf(yyout, "Identificador = %s \n", (yyvsp[(3) - (3)].texto));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 175 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -> \n"); fprintf(yyout, "Identificador = %s /n", (yyvsp[(3) - (3)].texto));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 176 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ++ \n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 177 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -- \n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 184 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 185 "AnalizadorSintactico.y"
    {fprintf(yyout, "Num entero = %d \n",(yyvsp[(1) - (1)].entero));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 186 "AnalizadorSintactico.y"
    {fprintf(yyout, "Num real = %f \n",(yyvsp[(1) - (1)].real));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 187 "AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 188 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ( y un ) \n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 196 "AnalizadorSintactico.y"
    {printf("ERROR: falta ID \n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 202 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia compuesta");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 203 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de asignacion");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 204 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de seleccion");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 205 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de iteracion");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 206 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia etiquetada");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 207 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de salto");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 208 "AnalizadorSintactico.y"
    {printf("ERROR AL DECLARAR LA SENTENCIA \n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 236 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el If \n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 237 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el If Else \n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 238 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Switch \n");}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 241 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el While \n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 242 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el Do While \n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 243 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el for \n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 246 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza un Case \n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 247 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Default \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 248 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (3)].texto)); fprintf(yyout, "se utiliza el : \n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 251 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el return \n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 252 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el Continue \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 253 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Break \n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 254 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Goto\n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 261 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (4)].texto));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 317 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(2) - (2)].texto));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 321 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 324 "AnalizadorSintactico.y"
    {fprintf(yyout, "se utiliza un struct \n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 325 "AnalizadorSintactico.y"
    {fprintf(yyout, "se utiliza un union \n");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 359 "AnalizadorSintactico.y"
    {fprinf(yyout, "Se declaro un Puntero \n");;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 374 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 397 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 413 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 416 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 454 "AnalizadorSintactico.y"
    {fprintf(yyout, "se declaro a la funcion %s \n",(yyvsp[(1) - (1)].texto));;}
    break;



/* Line 1455 of yacc.c  */
#line 2372 "AnalizadorSintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 461 "AnalizadorSintactico.y"


int main (){

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  yyparse ();
  fclose(yyin);
  fclose(yyout);
}

