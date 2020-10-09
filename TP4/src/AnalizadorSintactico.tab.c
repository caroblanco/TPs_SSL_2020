
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
#line 1 "AnalizadorSintactico.y"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YYDEBUG 1

int flag_error = 0; 
int linea=1;

extern FILE* yyin;
FILE* yyout;


int yylex();

int yywrap()
{
    return(1);
}

void yyerror (char *smth) {
   fprintf (yyout,"error sintactico en la linea: %d = %s\n",linea, smth);
}



/* Line 189 of yacc.c  */
#line 101 "AnalizadorSintactico.tab.c"

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
     IDENTIFICADOR = 260,
     LITERALCADENA = 261,
     CARACTER = 262,
     P_INC = 263,
     P_DEC = 264,
     DISTINTO = 265,
     IGUAL = 266,
     AND = 267,
     OR = 268,
     DIV_IGUAL = 269,
     POR_IGUAL = 270,
     MENOS_IGUAL = 271,
     MAS_IGUAL = 272,
     MENOR_IGUAL = 273,
     MAYOR_IGUAL = 274,
     MOD_IGUAL = 275,
     BIT_SHIFT_L = 276,
     BIT_SHIFT_R = 277,
     FLECHITA = 278,
     DO = 279,
     WHILE = 280,
     IF = 281,
     ELSE = 282,
     FOR = 283,
     RETURN = 284,
     GOTO = 285,
     STATIC = 286,
     EXTERN = 287,
     CONST = 288,
     VOLATILE = 289,
     STRUCT = 290,
     UNION = 291,
     TYPEDEF = 292,
     AUTO = 293,
     REGISTER = 294,
     CHAR = 295,
     INT = 296,
     FLOAT = 297,
     LONG = 298,
     SHORT = 299,
     SIGNED = 300,
     UNSIGNED = 301,
     VOID = 302,
     ENUM = 303,
     DOUBLE = 304,
     SIZEOF = 305,
     SWITCH = 306,
     CASE = 307,
     BREAK = 308,
     DEFAULT = 309,
     CONTINUE = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 86 "AnalizadorSintactico.y"

    int entero;
    char* texto;
    char caracter;
    float real;



/* Line 214 of yacc.c  */
#line 201 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "AnalizadorSintactico.tab.c"

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
#define YYLAST   1325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNRULES -- Number of states.  */
#define YYNSTATES  335

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    66,    69,     2,
      67,    68,    65,    62,    75,    63,    74,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    57,
      61,    58,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,    77,    71,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      24,    26,    30,    34,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    57,    59,    63,    64,    66,    68,    72,
      74,    78,    82,    84,    88,    92,    96,   100,   102,   106,
     110,   112,   116,   120,   124,   126,   131,   133,   136,   139,
     142,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   168,   173,   177,   181,   184,   187,   189,   193,   195,
     197,   199,   201,   205,   207,   209,   211,   213,   215,   217,
     219,   221,   223,   225,   227,   229,   231,   233,   235,   237,
     241,   243,   245,   247,   249,   251,   253,   255,   257,   259,
     262,   264,   270,   275,   280,   284,   285,   287,   288,   290,
     291,   293,   296,   298,   300,   303,   305,   311,   318,   324,
     326,   332,   339,   349,   354,   358,   362,   366,   369,   372,
     376,   377,   379,   384,   388,   389,   391,   394,   397,   400,
     401,   403,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   423,   425,   431,   434,   435,   437,   439,   441,   443,
     446,   450,   453,   456,   457,   459,   461,   465,   466,   468,
     471,   472,   474,   477,   481,   482,   484,   486,   489,   491,
     495,   500,   505,   510,   511,   513,   515,   521,   523,   527,
     530,   533,   535,   539,   545,   548,   550,   554,   556,   560,
     562,   564,   565,   567,   569,   572,   574,   575,   577,   581,
     586,   591,   592,   594,   595,   597,   599,   602,   604,   606
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    -1,    79,    80,    -1,    56,    -1,   102,
      56,    -1,    81,    56,    -1,   116,    56,    -1,   155,    56,
      -1,     1,    56,    -1,    82,    -1,    81,    57,    82,    -1,
      93,    83,    82,    -1,    84,    -1,     1,    -1,    58,    -1,
      14,    -1,    15,    -1,    16,    -1,    17,    -1,    20,    -1,
      85,    -1,    86,    81,    59,    84,    -1,    87,    -1,    85,
      13,    87,    -1,    -1,    85,    -1,    88,    -1,    87,    12,
      88,    -1,    89,    -1,    88,    11,    89,    -1,    88,    10,
      89,    -1,    90,    -1,    89,    19,    90,    -1,    89,    60,
      90,    -1,    89,    18,    90,    -1,    89,    61,    90,    -1,
      91,    -1,    90,    62,    91,    -1,    90,    63,    91,    -1,
      92,    -1,    91,    64,    92,    -1,    91,    65,    92,    -1,
      91,    66,    92,    -1,    93,    -1,    67,    99,    68,    92,
      -1,    96,    -1,    94,    93,    -1,    95,    92,    -1,    93,
      94,    -1,    50,    93,    -1,     8,    -1,     9,    -1,    69,
      -1,    65,    -1,    63,    -1,    70,    -1,    62,    -1,    71,
      -1,    98,    -1,    96,    72,    81,    73,    -1,    96,    67,
      97,    68,    -1,    96,    74,   101,    -1,    96,    23,   101,
      -1,    96,     8,    -1,    96,     9,    -1,    82,    -1,    97,
      75,    82,    -1,   101,    -1,     3,    -1,     4,    -1,     6,
      -1,    67,    81,    68,    -1,   100,    -1,    35,    -1,    37,
      -1,    36,    -1,    48,    -1,    40,    -1,    41,    -1,    42,
      -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,    49,    -1,     5,    -1,     5,    58,    81,
      -1,     1,    -1,   103,    -1,   104,    -1,   115,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,     1,    -1,   114,
      57,    -1,     1,    -1,    76,   107,   106,    77,   105,    -1,
      76,   108,    77,   105,    -1,    76,   109,    77,   105,    -1,
      76,    77,   105,    -1,    -1,    57,    -1,    -1,   109,    -1,
      -1,   108,    -1,   108,   116,    -1,   116,    -1,   102,    -1,
     109,   102,    -1,     1,    -1,    26,    67,    81,    68,   102,
      -1,    26,    67,    81,    68,    27,   102,    -1,    51,    67,
      81,    68,   102,    -1,     1,    -1,    25,    67,    81,    68,
     102,    -1,    24,   102,    25,    67,    81,    68,    -1,    28,
      67,   114,    57,   114,    57,   114,    68,   102,    -1,    52,
     150,    59,   102,    -1,    54,    59,   102,    -1,     5,    59,
     102,    -1,    29,   114,    57,    -1,    55,    57,    -1,    53,
      57,    -1,    30,     5,    57,    -1,    -1,    81,    -1,     5,
      58,    81,    57,    -1,   118,   117,    57,    -1,    -1,   126,
      -1,   120,   119,    -1,   121,   119,    -1,   122,   119,    -1,
      -1,   118,    -1,    37,    -1,    31,    -1,    38,    -1,    39,
      -1,    32,    -1,    99,    -1,   123,    -1,   143,    -1,   147,
      -1,    33,    -1,    34,    -1,   125,   124,    76,   126,    77,
      -1,   125,     5,    -1,    -1,     5,    -1,    35,    -1,    36,
      -1,   127,    -1,   126,   127,    -1,   128,   130,    57,    -1,
     121,   129,    -1,   122,   129,    -1,    -1,   128,    -1,   130,
      -1,   131,    59,   150,    -1,    -1,   132,    -1,   133,   137,
      -1,    -1,   134,    -1,    65,   135,    -1,    65,   135,   134,
      -1,    -1,   136,    -1,   122,    -1,   136,   122,    -1,     5,
      -1,    67,   132,    68,    -1,   137,    72,   151,    73,    -1,
     137,    67,   139,    68,    -1,   137,    67,   138,    68,    -1,
      -1,   142,    -1,   140,    -1,   140,    75,    74,    74,    74,
      -1,   141,    -1,   140,    75,   141,    -1,   118,   132,    -1,
     118,   148,    -1,     5,    -1,   142,    75,     5,    -1,    48,
     124,    76,   144,    77,    -1,    48,     5,    -1,   145,    -1,
     144,    75,   145,    -1,   146,    -1,   146,    58,   150,    -1,
       5,    -1,     5,    -1,    -1,   149,    -1,   134,    -1,   133,
     152,    -1,    84,    -1,    -1,   150,    -1,    67,   149,    68,
      -1,   154,    72,   151,    73,    -1,   154,    67,   153,    68,
      -1,    -1,   139,    -1,    -1,   152,    -1,   156,    -1,   155,
     156,    -1,   157,    -1,   116,    -1,   119,   132,   107,   104,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   100,   101,   102,   103,   104,   105,
     110,   111,   114,   115,   116,   119,   119,   119,   119,   119,
     119,   122,   123,   126,   127,   130,   131,   134,   135,   138,
     139,   140,   142,   143,   144,   145,   146,   154,   155,   156,
     159,   160,   161,   162,   165,   166,   169,   170,   171,   172,
     173,   176,   177,   180,   180,   180,   180,   180,   180,   183,
     184,   185,   186,   187,   188,   189,   192,   193,   196,   197,
     198,   199,   200,   203,   203,   203,   203,   203,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   218,   219,
     220,   225,   226,   227,   228,   229,   230,   231,   232,   236,
     237,   241,   242,   243,   244,   247,   248,   251,   252,   255,
     256,   259,   260,   263,   264,   265,   269,   270,   271,   272,
     276,   277,   278,   282,   283,   284,   288,   289,   290,   291,
     294,   295,   299,   305,   308,   309,   312,   313,   314,   317,
     318,   342,   342,   342,   342,   342,   345,   346,   347,   348,
     351,   351,   354,   355,   358,   359,   362,   363,   366,   367,
     370,   373,   374,   377,   378,   385,   386,   389,   390,   393,
     396,   397,   400,   401,   404,   405,   408,   409,   412,   413,
     414,   415,   416,   419,   420,   423,   424,   427,   428,   431,
     432,   435,   436,   439,   440,   443,   444,   447,   448,   451,
     454,   460,   461,   463,   464,   467,   470,   471,   474,   475,
     476,   479,   480,   483,   484,   488,   489,   492,   493,   496
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO_ENTERO", "NUMERO_REAL",
  "IDENTIFICADOR", "LITERALCADENA", "CARACTER", "P_INC", "P_DEC",
  "DISTINTO", "IGUAL", "AND", "OR", "DIV_IGUAL", "POR_IGUAL",
  "MENOS_IGUAL", "MAS_IGUAL", "MENOR_IGUAL", "MAYOR_IGUAL", "MOD_IGUAL",
  "BIT_SHIFT_L", "BIT_SHIFT_R", "FLECHITA", "DO", "WHILE", "IF", "ELSE",
  "FOR", "RETURN", "GOTO", "STATIC", "EXTERN", "CONST", "VOLATILE",
  "STRUCT", "UNION", "TYPEDEF", "AUTO", "REGISTER", "CHAR", "INT", "FLOAT",
  "LONG", "SHORT", "SIGNED", "UNSIGNED", "VOID", "ENUM", "DOUBLE",
  "SIZEOF", "SWITCH", "CASE", "BREAK", "DEFAULT", "CONTINUE", "'\\n'",
  "';'", "'='", "':'", "'>'", "'<'", "'+'", "'-'", "'/'", "'*'", "'%'",
  "'('", "')'", "'&'", "'!'", "'~'", "'['", "']'", "'.'", "','", "'{'",
  "'}'", "$accept", "input", "line", "expresion", "expresionAs",
  "operadorAs", "expCondicional", "expOr", "expOrOP", "expAnd",
  "expIgualdad", "expRelacional", "expAditiva", "expMultiplicativa",
  "expConversion", "expUnaria", "incremento", "operUnario", "expSufijo",
  "listaArgumentos", "expPrimaria", "nombreTipo", "tipoDato", "ID",
  "sentencia", "sentExp", "sentCompuesta", "PCOp", "listaSentenciasOP",
  "listaDeclaracionesOP", "listaDeclaraciones", "listaSentencias",
  "sentSeleccion", "sentIteracion", "sentEtiquetada", "sentSalto",
  "expresionOP", "sentAsignacion", "declaracion", "listaDecOP", "espeDec",
  "espeDecOP", "espeClasAlma", "espeTipo", "caliTipo", "especificadorSU",
  "IDENTIFICADOROP", "SU", "listaDecS", "declaracionS", "listCali",
  "listCaliOP", "declaS", "declaOP", "decla", "punteroOP", "puntero",
  "listCaliTiposOP", "listCaliTipos", "decDirec", "listIdenOP",
  "listTipoPar", "listParam", "decParam", "listIden", "especificadorE",
  "listEnum", "enumerador", "constEnum", "nombreTypedef", "decAbstractOP",
  "decAbstract", "expConst", "expConstOP", "decAbstDirec", "listTipoParOP",
  "decAbstDirecOP", "unidadDeTraduccion", "decExterna", "defFuncion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    10,    59,    61,    58,
      62,    60,    43,    45,    47,    42,    37,    40,    41,    38,
      33,   126,    91,    93,    46,    44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   109,   110,   110,   110,   110,
     111,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   116,   117,   117,   118,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     0,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     2,     2,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     4,     4,     3,     0,     1,     0,     1,     0,
       1,     2,     1,     1,     2,     1,     5,     6,     5,     1,
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
       2,     0,     1,    90,    69,    70,    88,    71,    51,    52,
       0,     0,     0,     0,     0,     0,   142,   145,   150,   151,
      74,    76,    75,   143,   144,    78,    79,    80,    81,    82,
      83,    84,    85,    77,    87,     0,     0,     0,     0,     0,
       0,     4,    57,    55,    54,     0,    53,    56,    58,     0,
       3,     0,    10,    13,    21,     0,    23,    27,    29,    32,
      37,    40,    44,     0,     0,    46,    59,   146,    73,    68,
       0,    91,    92,    94,    95,    96,    97,     0,    93,   218,
     140,   170,   139,   139,   139,   147,   154,   148,   149,   139,
     215,   217,     9,     0,     0,    90,    88,   131,     0,     0,
       0,     0,    14,    88,     0,     0,   194,     0,    90,     0,
      50,     0,   205,    44,     0,   128,     0,   127,    74,    76,
      75,    77,     0,     0,    90,   105,   113,     0,   110,     0,
     112,   134,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,    20,    15,     0,    49,    47,    48,    64,    65,
       0,     0,     0,     0,     5,    99,     7,   200,     0,   163,
     163,   135,   158,   170,   174,   109,     0,   171,   140,   136,
     137,   138,   153,     0,     8,   218,   216,    89,   125,     0,
       0,     0,     0,     0,   126,   129,     0,     0,     0,   124,
      72,     0,   106,   104,     0,     0,   105,   111,   105,   114,
      11,    24,     0,    28,    31,    30,    35,    33,    34,    36,
      38,    39,    41,    42,    43,    12,    63,    66,     0,     0,
      62,   133,   164,   161,   162,   159,     0,     0,   168,   176,
     172,   175,     0,   110,   178,   170,   169,     0,     0,     0,
       0,     0,     0,    89,   199,     0,   195,   197,     0,   123,
      45,   105,   102,   103,    22,    61,     0,    60,   160,     0,
     173,   177,   219,     0,   183,     0,     0,     0,   120,     0,
     116,     0,     0,   193,     0,   118,   101,    67,   166,   179,
     200,   170,     0,     0,   185,   187,   184,   207,     0,   152,
     121,   117,     0,   196,   198,   189,   213,   171,   190,   202,
     182,   181,     0,     0,   180,     0,   170,   204,     0,     0,
     188,   192,     0,     0,   211,     0,     0,   122,   208,   212,
       0,     0,   186,   210,   209
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    50,    97,    52,   154,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   228,
      66,    67,    68,    69,   126,    71,    72,   203,   204,   127,
     128,   129,    73,    74,    75,    76,    77,    78,   130,   168,
     131,    81,    82,    83,    84,    85,   107,    86,   171,   172,
     173,   233,   236,   237,   273,   176,   177,   240,   241,   246,
     292,   293,   294,   295,   296,    87,   255,   256,   257,    88,
     308,   309,   297,   298,   317,   330,   318,    89,    90,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -270
static const yytype_int16 yypact[] =
{
    -270,   300,  -270,    -6,  -270,  -270,  1266,  -270,  -270,  -270,
     833,   -38,   -25,    -2,   944,    62,  -270,  -270,  -270,  -270,
       1,    17,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,    13,  -270,   983,    68,  1015,    66,    85,
      83,  -270,  -270,  -270,  -270,   933,  -270,  -270,  -270,   374,
    -270,    81,  -270,  -270,   134,  1026,   137,   168,     2,    96,
     110,  -270,    40,   983,  1015,    78,  -270,  -270,  -270,  -270,
      98,  -270,  -270,  -270,  -270,  -270,  -270,   104,  -270,   130,
    1138,   101,  1228,  1228,  1228,  -270,   199,  -270,  -270,  1183,
    -270,  -270,  -270,  1026,   833,  1093,   144,   151,   187,  1026,
    1026,   944,  -270,   158,   163,   166,   155,   165,  -270,  1026,
     198,  1026,  -270,   198,   180,  -270,   833,  -270,  -270,  -270,
    -270,  -270,   -34,   178,  1100,   170,  -270,   528,   884,   605,
    -270,  1156,  -270,  1026,  1015,    33,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  -270,  -270,
    -270,  -270,  -270,  -270,  1026,  -270,   198,  -270,  -270,  -270,
     127,  1026,  1026,   127,  -270,  -270,  -270,  -270,   190,  1156,
    1156,  1156,  -270,    61,   177,  1228,     4,  -270,  -270,  -270,
    -270,  -270,   155,   179,  -270,  -270,  -270,   200,  -270,   189,
     -33,   -29,   202,  1026,  -270,  -270,   255,   -27,   833,  -270,
    -270,  1015,  -270,  -270,   184,   682,   170,  -270,   170,  -270,
    -270,   137,  1015,   168,     2,     2,    96,    96,    96,    96,
     110,   110,  -270,  -270,  -270,  -270,  -270,  -270,   -30,   -46,
    -270,  -270,  -270,  -270,  -270,  -270,   206,   205,  -270,  -270,
     101,   177,   191,  1228,  -270,   101,    -3,  1156,   451,  1026,
     833,   759,   944,   151,  -270,    56,  -270,   207,   833,  -270,
    -270,   170,  -270,  -270,  -270,  -270,  1026,  -270,  -270,  1015,
    -270,  -270,  -270,   201,  1247,   159,   148,   -24,  -270,   833,
    -270,   209,   255,  -270,  1015,  -270,  -270,  -270,  -270,  -270,
     -22,    -7,   203,   204,   193,  -270,   195,  -270,   208,  -270,
    -270,  -270,   843,  -270,  -270,  -270,     8,    10,  -270,  -270,
    -270,  -270,  1067,   270,  -270,   210,   101,     7,    55,   211,
    -270,  -270,   833,   212,  1228,   159,   213,  -270,  -270,  -270,
     214,   215,  -270,  -270,  -270
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,  -270,    25,  -118,  -270,   -35,  -270,  -270,   142,
     141,    77,    31,    92,   -50,   -32,   -37,  -270,  -270,  -270,
    -270,   238,  -270,  -123,     0,  -270,    42,  -189,  -270,   111,
     114,   164,  -270,  -270,  -270,  -270,   -10,  -270,    11,  -270,
      -1,   117,  -270,   -14,   -28,  -270,   216,  -270,    47,  -155,
      75,   125,  -270,  -270,   -74,  -269,  -232,  -270,  -270,  -270,
    -270,   -26,  -270,   -16,  -270,  -270,  -270,    15,  -270,  -270,
    -270,   -17,   -31,   -18,  -270,  -270,  -270,  -270,   221,  -270
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -215
static const yytype_int16 yytable[] =
{
      80,    70,   112,   110,   104,   113,   114,   175,   270,   244,
      98,   133,    79,   244,   157,   210,   235,   262,   106,   263,
     139,   140,   306,   133,   133,   155,    51,   267,   133,    99,
     133,   156,   113,   133,   200,   250,   225,   226,   265,   251,
     230,   258,   100,   227,   300,   266,  -191,   306,     8,     9,
      92,   -14,   170,  -191,   148,   149,   150,   151,   174,   307,
     152,  -201,   141,   142,   274,   101,   169,   105,  -201,   275,
     122,   245,   286,   155,  -214,   316,   155,  -156,  -203,  -214,
     135,   178,   178,   178,   307,  -203,   158,   159,    80,  -154,
     133,   192,   212,  -157,   188,   222,   223,   224,   153,   238,
     185,   160,   113,   170,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   199,   169,   187,   155,
    -167,   235,   324,   115,   190,   191,   174,   325,   108,   209,
     210,   282,   103,   283,   122,   111,   197,   132,   133,   207,
     117,   170,   170,   170,   116,   161,   239,   134,   287,   136,
     162,   260,   163,   167,   164,   169,   169,   169,   143,   144,
     108,   165,     4,     5,   103,     7,   174,     8,     9,   113,
     216,   217,   218,   219,   145,   146,   147,   264,   137,   138,
     113,    18,    19,    20,    21,   120,   166,   229,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   259,   179,
     180,   181,    93,    94,   182,   209,     8,     9,   133,    35,
      18,    19,   189,   271,   214,   215,   193,   305,   253,   170,
     194,    42,    43,   195,    44,   299,    45,   202,    46,    47,
      48,  -155,  -206,   169,   112,   220,   221,   113,   288,   198,
     112,   196,   281,   113,   232,   232,   201,   231,   170,   112,
     278,   280,   113,   304,   207,   247,   249,   248,   285,   252,
     254,   261,   169,   268,   269,   284,   302,    49,   312,   289,
     313,   310,   311,   291,   277,   321,   211,   213,   322,   301,
     328,   314,   333,   123,   272,   326,   242,   332,   334,   243,
     112,   205,   315,   113,   276,   234,   320,   303,   329,   323,
       2,     3,   183,     4,     5,     6,     7,   331,     8,     9,
     186,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   291,    10,    11,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,  -130,     0,     0,
       0,     0,    42,    43,     0,    44,     0,    45,     0,    46,
      47,    48,     0,     0,     0,   124,    49,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,  -109,     0,     0,     0,     0,    42,    43,     0,    44,
       0,    45,     0,    46,    47,    48,     0,     0,     0,     0,
      49,   125,   102,     0,     4,     5,   103,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -132,  -132,  -132,     0,  -132,
    -132,  -132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,
       0,     0,     0,    42,    43,     0,    44,     0,    45,     0,
      46,    47,    48,     0,     0,     0,     0,  -132,  -132,   124,
       0,     4,     5,    96,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
      37,    38,    39,    40,     0,  -130,     0,     0,     0,     0,
      42,    43,     0,    44,     0,    45,     0,    46,    47,    48,
       0,     0,     0,     0,    49,  -107,    95,     0,     4,     5,
      96,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,     0,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,    38,    39,
      40,     0,  -130,     0,     0,     0,     0,    42,    43,     0,
      44,     0,    45,     0,    46,    47,    48,     0,     0,     0,
       0,    49,   208,    95,     0,     4,     5,    96,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,     0,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,    38,    39,    40,     0,  -130,
       0,     0,     0,     0,    42,    43,     0,    44,     0,    45,
       0,    46,    47,    48,     0,     0,     0,     0,    49,  -108,
      95,     0,     4,     5,    96,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,   279,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,    38,    39,    40,     0,  -130,     0,     0,     0,
       0,    42,    43,     0,    44,     0,    45,     0,    46,    47,
      48,     0,     0,     0,    95,    49,     4,     5,    96,     7,
       0,     8,     9,     0,   102,     0,     4,     5,   103,     7,
       0,     8,     9,     0,     0,     0,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,    37,    38,    39,    40,   167,
    -130,     0,     0,    35,     0,    42,    43,     0,    44,     0,
      45,     0,    46,    47,    48,    42,    43,     0,    44,    49,
      45,  -130,    46,    47,    48,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   102,     0,     4,     5,   103,     7,
       0,     8,     9,     0,     0,   102,     0,     4,     5,   103,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,   118,   119,
     120,     0,     0,    25,    26,    27,    28,    29,    30,    31,
      32,   121,    34,    35,   108,     0,     4,     5,   103,     7,
       0,     8,     9,     0,    35,    42,    43,     0,    44,     0,
      45,  -130,    46,    47,    48,     0,    42,    43,     0,    44,
       0,    45,     0,    46,    47,    48,   108,     0,     4,     5,
     103,     7,     0,     8,     9,     0,     0,   102,     0,     4,
       5,   103,     7,    35,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,     0,    44,     0,
     109,     0,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,   167,     0,     0,     0,    35,    42,    43,     0,
      44,     0,    45,     0,    46,    47,    48,     0,    42,    43,
       0,    44,     0,    45,     0,    46,    47,    48,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   -98,   -98,   -98,
       0,   -98,   -98,   -98,   -98,   -98,   -98,     0,   -98,   -98,
     -98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   167,   -98,   -98,   -98,   -98,   -98,   -98,
     -14,   -98,   -98,   -98,   -98,   -98,     0,   -14,     0,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,   -98,
     -98,    18,    19,    20,    21,   120,   -98,   -98,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   167,    18,
      19,    20,    21,   120,     0,  -134,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   167,     0,     0,     0,     0,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94
};

static const yytype_int16 yycheck[] =
{
       1,     1,    37,    35,    14,    37,    37,    81,   240,     5,
      10,    57,     1,     5,    64,   133,   171,   206,     5,   208,
      18,    19,   291,    57,    57,    62,     1,    73,    57,    67,
      57,    63,    64,    57,    68,    68,   154,   160,    68,    68,
     163,    68,    67,   161,    68,    75,    68,   316,     8,     9,
      56,    57,    80,    75,    14,    15,    16,    17,    65,   291,
      20,    68,    60,    61,    67,    67,    80,     5,    75,    72,
      45,    67,   261,   110,    67,    67,   113,    76,    68,    72,
      55,    82,    83,    84,   316,    75,     8,     9,    89,    76,
      57,   101,    59,    76,    94,   145,   146,   147,    58,   173,
      89,    23,   134,   131,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   116,   131,    93,   156,
      59,   276,    67,    57,    99,   100,    65,    72,     1,   129,
     248,    75,     5,    77,   109,    67,   111,    56,    57,   128,
      57,   169,   170,   171,    59,    67,   174,    13,   266,    12,
      72,   201,    74,     5,    56,   169,   170,   171,    62,    63,
       1,    57,     3,     4,     5,     6,    65,     8,     9,   201,
     139,   140,   141,   142,    64,    65,    66,   212,    10,    11,
     212,    33,    34,    35,    36,    37,    56,   162,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   198,    82,
      83,    84,    58,    59,     5,   205,     8,     9,    57,    50,
      33,    34,    25,   241,   137,   138,    58,   291,   193,   247,
      57,    62,    63,    57,    65,    77,    67,    57,    69,    70,
      71,    76,    73,   247,   269,   143,   144,   269,   269,    59,
     275,    76,   252,   275,   169,   170,    68,    57,   276,   284,
     250,   251,   284,   284,   243,    76,    67,    57,   258,    57,
       5,    77,   276,    57,    59,    58,    57,    76,    75,    68,
      75,    68,    68,   274,   249,     5,   134,   136,    68,   279,
      68,    73,    68,    45,   242,    74,   175,    74,    73,   175,
     325,   127,   302,   325,   247,   170,   312,   282,   324,   316,
       0,     1,    86,     3,     4,     5,     6,   325,     8,     9,
      89,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   324,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    -1,     1,    76,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,
      76,    77,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    77,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    -1,    76,    77,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    76,    77,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,    77,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,     1,    76,     3,     4,     5,     6,
      -1,     8,     9,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,     5,
      57,    -1,    -1,    50,    -1,    62,    63,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    62,    63,    -1,    65,    76,
      67,    68,    69,    70,    71,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    50,    62,    63,    -1,    65,    -1,
      67,    57,    69,    70,    71,    -1,    62,    63,    -1,    65,
      -1,    67,    -1,    69,    70,    71,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    50,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    50,    62,    63,    -1,
      65,    -1,    67,    -1,    69,    70,    71,    -1,    62,    63,
      -1,    65,    -1,    67,    -1,    69,    70,    71,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    24,    25,    26,
      -1,    28,    29,    30,    24,    25,    26,    -1,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,     5,    51,    52,    53,    54,    55,    56,
      57,    51,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    33,    34,    35,    36,    37,    76,    77,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     5,    33,
      34,    35,    36,    37,    -1,    57,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     5,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,     0,     1,     3,     4,     5,     6,     8,     9,
      24,    25,    26,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    62,    63,    65,    67,    69,    70,    71,    76,
      80,    81,    82,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     102,   103,   104,   110,   111,   112,   113,   114,   115,   116,
     118,   119,   120,   121,   122,   123,   125,   143,   147,   155,
     156,   157,    56,    58,    59,     1,     5,    81,   102,    67,
      67,    67,     1,     5,   114,     5,     5,   124,     1,    67,
      93,    67,    84,    93,   150,    57,    59,    57,    35,    36,
      37,    48,    81,    99,     1,    77,   102,   107,   108,   109,
     116,   118,    56,    57,    13,    81,    12,    10,    11,    18,
      19,    60,    61,    62,    63,    64,    65,    66,    14,    15,
      16,    17,    20,    58,    83,    94,    93,    92,     8,     9,
      23,    67,    72,    74,    56,    57,    56,     5,   117,   121,
     122,   126,   127,   128,    65,   132,   133,   134,   118,   119,
     119,   119,     5,   124,    56,   116,   156,    81,   102,    25,
      81,    81,   114,    58,    57,    57,    76,    81,    59,   102,
      68,    68,    57,   105,   106,   109,    77,   116,    77,   102,
      82,    87,    59,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    82,   101,    82,    97,    81,
     101,    57,   128,   129,   129,   127,   130,   131,   132,   122,
     135,   136,   107,   108,     5,    67,   137,    76,    57,    67,
      68,    68,    57,    81,     5,   144,   145,   146,    68,   102,
      92,    77,   105,   105,    84,    68,    75,    73,    57,    59,
     134,   122,   104,   132,    67,    72,   126,    81,   102,    27,
     102,   114,    75,    77,    58,   102,   105,    82,   150,    68,
       5,   118,   138,   139,   140,   141,   142,   150,   151,    77,
      68,   102,    57,   145,   150,   132,   133,   134,   148,   149,
      68,    68,    75,    75,    73,   114,    67,   152,   154,    74,
     141,     5,    68,   149,    67,    72,    74,   102,    68,   139,
     153,   151,    74,    68,    73
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
#line 100 "AnalizadorSintactico.y"
    {fprintf(yyout,"\n"); linea++;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 101 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------SENTENCIA--------");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------EXPRESION--------");linea++;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 103 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------DECLARACION--------");linea++;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 104 "AnalizadorSintactico.y"
    {fprintf(yyout,"--------FUNCION--------");linea++;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 105 "AnalizadorSintactico.y"
    {fprintf(yyout, "\nse detecto un error sintactico en la linea %i", linea); linea++;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 111 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ; \n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 116 "AnalizadorSintactico.y"
    {printf("ERROR al declarar la expresion asignacion \n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 123 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un : \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 127 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un || \n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 135 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un && \n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 139 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un == \n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 140 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un != \n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 143 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un >= \n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 144 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un > \n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 145 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un <= \n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 146 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un >= \n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 155 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un + \n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 156 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un - \n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 160 "AnalizadorSintactico.y"
    { if((yyvsp[(3) - (3)].real) == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real); fprintf(yyout,"se encontro un / \n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 161 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un * \n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 162 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un % \n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 176 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ++ \n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 177 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -- \n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 184 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro [ y ] \n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 185 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ( y un )\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 186 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un . \n"); /*fprintf(yyout, "Identificador = %s \n", $<texto>3);*/;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 187 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -> \n"); /*fprintf(yyout, "Identificador = %s /n", $<texto>3);*/;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 188 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ++ \n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 189 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un -- \n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 196 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 197 "AnalizadorSintactico.y"
    {fprintf(yyout, "Num entero = %d \n",(yyvsp[(1) - (1)].entero));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 198 "AnalizadorSintactico.y"
    {fprintf(yyout, "Num real = %f \n",(yyvsp[(1) - (1)].real));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 199 "AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 200 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro un ( y un ) \n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 207 "AnalizadorSintactico.y"
    {fprintf(yyout, "se encontro tipo de dato int \n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 220 "AnalizadorSintactico.y"
    {printf("ERROR: falta ID \n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 225 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia expresion");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 226 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia compuesta");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 227 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de asignacion");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 228 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de seleccion");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 229 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de iteracion");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 230 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia etiquetada");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 231 "AnalizadorSintactico.y"
    {printf("Se declaro una sentencia de salto");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 232 "AnalizadorSintactico.y"
    {printf("ERROR AL DEFINIR LA SENTENCIA \n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 237 "AnalizadorSintactico.y"
    {printf("ERROR AL DEFINIR LA SENTENCIA \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 265 "AnalizadorSintactico.y"
    {printf("ERROR AL DEFINIR LA SENTENCIA \n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 269 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el If \n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 270 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el If Else \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 271 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Switch \n");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 272 "AnalizadorSintactico.y"
    {printf("ERROR AL DEFINIR LA EXPRESION \n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 276 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el While \n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 277 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el Do While \n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 278 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el for \n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 282 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza un Case \n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 283 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Default \n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 284 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (3)].texto)); fprintf(yyout, "se utiliza el : \n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 288 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el return \n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 289 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el Continue \n");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 290 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Break \n");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 291 "AnalizadorSintactico.y"
    {fprintf(yyout,"Se utiliza el Goto\n");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 299 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (4)].texto));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 355 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(2) - (2)].texto));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 359 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 362 "AnalizadorSintactico.y"
    {fprintf(yyout, "se utiliza un struct \n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 363 "AnalizadorSintactico.y"
    {fprintf(yyout, "se utiliza un union \n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 397 "AnalizadorSintactico.y"
    {fprintf(yyout, "Se declaro un Puntero \n");;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 412 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 435 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 451 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 454 "AnalizadorSintactico.y"
    {fprintf(yyout, "Identificador = %s \n",(yyvsp[(1) - (1)].texto));;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 492 "AnalizadorSintactico.y"
    {fprintf(yyout, "se declaro a la funcion %s \n",(yyvsp[(1) - (1)].texto));;}
    break;



/* Line 1455 of yacc.c  */
#line 2455 "AnalizadorSintactico.tab.c"
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
#line 499 "AnalizadorSintactico.y"


int main (){

  int flag;

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  flag = yyparse ();
  fclose(yyin);
  fclose(yyout);
  return flag;
}
