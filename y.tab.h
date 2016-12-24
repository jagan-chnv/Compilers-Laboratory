/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    INTEGER = 259,
    AND = 260,
    NUL = 261,
    FST = 262,
    SND = 263,
    PAIR = 264,
    ALLOC = 265,
    FREE = 266,
    TYPEDEF = 267,
    DELIM = 268,
    DCR = 269,
    INITIALIZE = 270,
    INR = 271,
    MOD = 272,
    OR = 273,
    TRUE = 274,
    FALSE = 275,
    RETURN = 276,
    MAIN = 277,
    DECL = 278,
    ENDDECL = 279,
    BOOLEAN = 280,
    NUM = 281,
    BEGINE = 282,
    ID = 283,
    IF = 284,
    LT = 285,
    decl = 286,
    Enddecl = 287,
    GT = 288,
    LE = 289,
    GE = 290,
    EQ = 291,
    NE = 292,
    END = 293,
    THEN = 294,
    ELSE = 295,
    READ = 296,
    WRITE = 297,
    ENDIF = 298,
    ENDWHILE = 299,
    endif = 300,
    WHILE = 301,
    DO = 302
  };
#endif
/* Tokens.  */
#define BOOL 258
#define INTEGER 259
#define AND 260
#define NUL 261
#define FST 262
#define SND 263
#define PAIR 264
#define ALLOC 265
#define FREE 266
#define TYPEDEF 267
#define DELIM 268
#define DCR 269
#define INITIALIZE 270
#define INR 271
#define MOD 272
#define OR 273
#define TRUE 274
#define FALSE 275
#define RETURN 276
#define MAIN 277
#define DECL 278
#define ENDDECL 279
#define BOOLEAN 280
#define NUM 281
#define BEGINE 282
#define ID 283
#define IF 284
#define LT 285
#define decl 286
#define Enddecl 287
#define GT 288
#define LE 289
#define GE 290
#define EQ 291
#define NE 292
#define END 293
#define THEN 294
#define ELSE 295
#define READ 296
#define WRITE 297
#define ENDIF 298
#define ENDWHILE 299
#define endif 300
#define WHILE 301
#define DO 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "new.y" /* yacc.c:1909  */

	int integer;
	char* string;
	struct ArgStruct *Arg;
	struct ASTNode *nptr;
	struct Gsymbol *gptr;
	struct Lsymbol *lptr;

#line 157 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
