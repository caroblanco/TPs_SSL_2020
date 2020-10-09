
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 86 "AnalizadorSintactico.y"

    int entero;
    char* texto;
    char caracter;
    float real;



/* Line 1676 of yacc.c  */
#line 116 "AnalizadorSintactico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


