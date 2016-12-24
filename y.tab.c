/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "new.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<stdlib.h>
    #include<string.h>
    int counter=0;
   

	int localbind=1;
	int argbind=-3;

  #include "abstracttree.h"
	#include "symboltable.h"
	#include "codegen.h"
  #include "abstracttree.c"
	#include "symboltable.c"
  #include "codegen.c"

   
    struct Typetable *tt,*decl_ftype,*decl_argtype,*decl_ltype,*decl_stype,*newtype;         
    extern FILE * yyin;


#line 89 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 24 "new.y" /* yacc.c:355  */

	int integer;
	char* string;
	struct ArgStruct *Arg;
	struct ASTNode *nptr;
	struct Gsymbol *gptr;
	struct Lsymbol *lptr;

#line 232 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
      58,    59,    51,    49,    55,    50,     6,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
       5,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    60,    61,    66,    67,    73,    74,    77,
      90,    96,    98,    99,   106,   109,   110,   113,   118,   122,
     131,   140,   156,   158,   159,   161,   168,   174,   178,   185,
     186,   188,   208,   209,   211,   213,   217,   226,   229,   234,
     240,   248,   255,   256,   259,   264,   268,   291,   313,   330,
     335,   341,   345,   350,   356,   360,   365,   370,   374,   380,
     386,   390,   403,   408,   421,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   446,
     447,   465,   472,   478,   482,   485,   491,   492,   495,   504,
     513,   524,   525,   528,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "INTEGER", "AND", "'.'", "NUL",
  "FST", "SND", "PAIR", "ALLOC", "FREE", "TYPEDEF", "DELIM", "DCR",
  "INITIALIZE", "INR", "MOD", "OR", "TRUE", "FALSE", "RETURN", "MAIN",
  "DECL", "ENDDECL", "BOOLEAN", "NUM", "BEGINE", "ID", "IF", "LT", "decl",
  "Enddecl", "GT", "LE", "GE", "EQ", "NE", "END", "THEN", "ELSE", "READ",
  "WRITE", "ENDIF", "ENDWHILE", "endif", "WHILE", "DO", "'+'", "'-'",
  "'*'", "'/'", "'{'", "'}'", "','", "'['", "']'", "'('", "')'", "'&'",
  "'='", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "FieldDeclList", "type", "stype", "GDeclBlock", "GDecList", "GDecL",
  "idlist", "var", "argtype", "Arg", "argtail", "arglist", "FdefList",
  "Fdef", "LDefblock", "Ldeflist", "ltype", "LDecL", "lidlist",
  "Mainblock", "Body", "slist", "stmt", "Retstmt", "expr", "FIELD",
  "Exprlist", "Exphead", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,    46,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    43,
      45,    42,    47,   123,   125,    44,    91,    93,    40,    41,
      38,    61
};
# endif

#define YYPACT_NINF -202

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-202)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -16,    29,    10,    39,  -202,    23,  -202,    58,  -202,
     -16,    58,  -202,    60,   -18,  -202,    80,    42,    44,    81,
     -30,    -2,  -202,  -202,  -202,    71,    94,  -202,  -202,    58,
    -202,   100,   116,   105,   104,  -202,    60,    78,    79,    77,
     121,  -202,    91,  -202,    48,    95,  -202,    96,   104,  -202,
    -202,  -202,  -202,   137,    41,  -202,   119,   114,  -202,   104,
      62,  -202,   150,   124,  -202,  -202,   156,   157,   163,   150,
    -202,  -202,    63,   169,  -202,  -202,   138,   163,  -202,  -202,
    -202,    65,   498,  -202,   145,  -202,   175,   142,   152,    92,
      -5,   154,   155,   158,   159,  -202,   179,    -4,  -202,  -202,
     190,   170,  -202,  -202,  -202,  -202,    68,   207,    92,   369,
     227,   210,    92,   326,    92,   216,    92,    92,  -202,   217,
     341,     4,     0,   221,    92,    92,  -202,    66,    92,  -202,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,  -202,   233,   178,   191,   192,    92,   408,   109,
      16,     2,   144,   171,  -202,   195,   418,    92,   234,   240,
    -202,   242,   467,   200,   208,  -202,   495,   495,   495,   279,
     279,   279,   279,   279,   279,   495,   495,   358,   358,    -3,
     237,   243,   203,    31,  -202,   235,    92,   267,   272,   275,
     247,   238,  -202,   269,  -202,  -202,   290,  -202,    92,   273,
     352,   249,   250,   287,    92,  -202,   293,  -202,  -202,  -202,
    -202,   308,    11,   467,  -202,   265,   457,   311,   318,  -202,
     206,   185,    19,   122,  -202,   322,   280,  -202,  -202,  -202,
     324,  -202,   327,   337,   343,  -202,   344,  -202,   141,  -202,
    -202,  -202,  -202,   346,  -202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     3,    10,     0,     1,     0,    29,
       0,     0,     9,     0,     0,    13,     0,     0,     0,     0,
      18,     0,    16,    11,    12,     9,     0,    30,     2,     0,
       6,     0,     0,     0,    22,    14,     0,     0,     0,     0,
       0,     7,     0,    20,     0,     0,    15,     0,    22,     5,
       8,    17,    27,     0,    24,    19,     0,     0,    28,    22,
       0,    21,    33,     0,    23,    25,     0,     0,     0,    33,
      26,    36,     0,     0,    35,    43,     0,     0,    32,    34,
      39,     0,     0,    40,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    31,    38,
       0,     0,    84,    86,    87,    83,    81,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,    91,    85,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
      60,     0,    94,     0,    92,    78,    72,    71,    73,    70,
      69,    77,    74,    75,    76,    65,    66,    67,    68,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,    62,     0,    52,    54,    82,    80,     0,     0,
       0,     0,     0,     0,     0,    43,     0,    56,    57,    59,
      43,     0,     0,    93,    89,     0,     0,     0,     0,    49,
       0,     0,     0,     0,    51,     0,     0,    63,    46,    47,
       0,    43,     0,     0,     0,    53,     0,    48,     0,    45,
      58,    55,    50,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,   335,   338,   330,  -202,  -202,   351,
    -202,   333,  -202,   -43,  -202,  -202,  -202,  -202,   297,  -202,
    -202,   299,  -202,  -202,   298,  -201,  -202,  -202,   -93,   -82,
    -202,  -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    18,    13,     6,     9,    14,    15,
      21,    22,    44,    45,    61,    54,    16,    27,    68,    72,
      73,    74,    81,    28,    76,    82,    95,    96,   109,   110,
     163,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   111,   119,   199,   221,    57,   119,    23,   119,   223,
     111,    12,    35,     5,     1,   127,    64,   199,   122,   143,
     148,   149,   111,   152,   153,   199,    33,   156,    34,     7,
     238,   161,   162,   151,     8,   166,   128,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   130,
     131,   112,    10,    36,   183,    59,   113,   120,   200,   159,
     157,   188,   132,   158,   193,   133,   134,   135,   136,   137,
     225,   128,   186,    12,   111,   187,    11,    52,   233,    85,
     138,   139,   140,   141,   130,   131,   204,    12,    78,    20,
     165,    65,    71,   206,    37,    29,    60,   132,    30,   102,
     133,   134,   135,   136,   137,   213,    12,   216,    53,    25,
      32,   220,   103,   104,   128,   138,   139,   140,   141,   105,
      86,   106,    66,    38,   124,   165,   125,   130,   131,    40,
      41,    49,    42,    43,    87,    50,    47,    48,    88,    97,
     132,    97,   107,   133,   134,   135,   136,   137,    51,   128,
     108,    90,    91,    87,    55,    56,    97,    88,   138,   139,
     140,   141,   130,   131,    92,    93,    58,   234,   185,    94,
      90,    91,    62,    63,    67,   132,   128,    69,   133,   134,
     135,   136,   137,    92,    93,    70,    71,   243,    94,   130,
     131,    75,    83,   138,   139,   140,   141,    87,    80,    98,
     100,    88,   132,   189,    99,   133,   134,   135,   136,   137,
     101,   128,   114,   115,    90,    91,   116,   117,   118,   121,
     138,   139,   140,   141,   130,   131,   231,    92,    93,   123,
     190,   232,    94,   119,   126,   160,   180,   132,   128,   142,
     133,   134,   135,   136,   137,   150,   154,   128,   194,   181,
     182,   130,   131,   191,   195,   138,   139,   140,   141,   197,
     130,   131,   203,   198,   132,   230,   201,   133,   134,   135,
     136,   137,   202,   132,   128,   205,   133,   134,   135,   136,
     137,   207,   138,   139,   140,   141,   208,   130,   131,   209,
     179,   138,   139,   140,   141,   210,   199,   211,   128,   196,
     132,   219,   214,   133,   134,   135,   136,   137,   217,   218,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   224,   226,   132,   228,   212,   133,   134,   135,
     136,   137,   229,   102,   144,   145,   235,   146,   237,   236,
      17,   239,   138,   139,   140,   141,   103,   104,   102,    19,
     222,   240,   155,   105,    26,   106,    31,   241,   242,   102,
     244,   103,   104,   215,    39,    24,    77,    19,   105,    46,
     106,    79,   103,   104,   128,    84,   107,    31,     0,   105,
       0,   106,     0,   129,   147,     0,     0,   130,   131,   132,
       0,   107,   133,   134,   135,   136,   137,     0,     0,   108,
     132,     0,   107,   133,   134,   135,   136,   137,     0,     0,
     108,     0,     0,   128,     0,     0,     0,     0,   138,   139,
     140,   141,   184,   128,     0,     0,   130,   131,     0,     0,
       0,     0,   192,     0,     0,     0,   130,   131,     0,   132,
       0,     0,   133,   134,   135,   136,   137,     0,     0,   132,
       0,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,   128,     0,     0,     0,     0,   138,   139,   140,
     141,   227,   128,     0,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,   132,     0,
       0,   133,   134,   135,   136,   137,     0,     0,   132,     0,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      87,     0,     0,     0,    88,     0,   138,   139,   140,   141,
      89,     0,     0,     0,     0,     0,   132,    90,    91,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
      92,    93,     0,     0,     0,    94,   140,   141
};

static const yytype_int16 yycheck[] =
{
      82,     6,     6,     6,   205,    48,     6,    25,     6,   210,
       6,    29,    14,    29,    13,   108,    59,     6,   100,   112,
     113,   114,     6,   116,   117,     6,    56,   120,    58,     0,
     231,   124,   125,   115,    24,   128,     5,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    18,
      19,    56,    13,    55,   147,    14,    61,    61,    61,    59,
      56,    59,    31,    59,   157,    34,    35,    36,    37,    38,
      59,     5,    56,    29,     6,    59,    53,    29,    59,    14,
      49,    50,    51,    52,    18,    19,    55,    29,    25,    29,
      59,    29,    29,   186,    23,    53,    55,    31,    54,     7,
      34,    35,    36,    37,    38,   198,    29,   200,    60,    29,
      29,   204,    20,    21,     5,    49,    50,    51,    52,    27,
      55,    29,    60,    29,    56,    59,    58,    18,    19,    29,
      14,    54,    27,    29,    12,    14,    58,    58,    16,   221,
      31,   223,    50,    34,    35,    36,    37,    38,    57,     5,
      58,    29,    30,    12,    59,    59,   238,    16,    49,    50,
      51,    52,    18,    19,    42,    43,    29,    45,    59,    47,
      29,    30,    53,    59,    24,    31,     5,    53,    34,    35,
      36,    37,    38,    42,    43,    29,    29,    46,    47,    18,
      19,    28,    54,    49,    50,    51,    52,    12,    29,    54,
      58,    16,    31,    59,    29,    34,    35,    36,    37,    38,
      58,     5,    58,    58,    29,    30,    58,    58,    39,    29,
      49,    50,    51,    52,    18,    19,    41,    42,    43,    59,
      59,    46,    47,     6,    27,    14,    58,    31,     5,    29,
      34,    35,    36,    37,    38,    29,    29,     5,    14,    58,
      58,    18,    19,    58,    14,    49,    50,    51,    52,    59,
      18,    19,    59,    55,    31,    59,    29,    34,    35,    36,
      37,    38,    29,    31,     5,    40,    34,    35,    36,    37,
      38,    14,    49,    50,    51,    52,    14,    18,    19,    14,
      57,    49,    50,    51,    52,    48,     6,    59,     5,    57,
      31,    14,    29,    34,    35,    36,    37,    38,    59,    59,
      31,    18,    19,    34,    35,    36,    37,    38,    49,    50,
      51,    52,    14,    58,    31,    14,    57,    34,    35,    36,
      37,    38,    14,     7,     8,     9,    14,    11,    14,    59,
      10,    14,    49,    50,    51,    52,    20,    21,     7,    11,
      57,    14,    11,    27,    16,    29,    18,    14,    14,     7,
      14,    20,    21,    11,    29,    14,    69,    29,    27,    36,
      29,    72,    20,    21,     5,    77,    50,    39,    -1,    27,
      -1,    29,    -1,    14,    58,    -1,    -1,    18,    19,    31,
      -1,    50,    34,    35,    36,    37,    38,    -1,    -1,    58,
      31,    -1,    50,    34,    35,    36,    37,    38,    -1,    -1,
      58,    -1,    -1,     5,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    14,     5,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    19,    -1,    31,
      -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    37,    38,    49,    50,    51,
      52,    -1,     5,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    14,     5,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,    49,    50,    51,    52,
      12,    -1,    -1,    -1,    16,    -1,    49,    50,    51,    52,
      22,    -1,    -1,    -1,    -1,    -1,    31,    29,    30,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    47,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    63,    64,    65,    29,    68,     0,    24,    69,
      13,    53,    29,    67,    70,    71,    78,    68,    66,    67,
      29,    72,    73,    25,    71,    29,    67,    79,    85,    53,
      54,    67,    29,    56,    58,    14,    55,    23,    29,    66,
      29,    14,    27,    29,    74,    75,    73,    58,    58,    54,
      14,    57,    29,    60,    77,    59,    59,    75,    29,    14,
      55,    76,    53,    59,    75,    29,    60,    24,    80,    53,
      29,    29,    81,    82,    83,    28,    86,    80,    25,    83,
      29,    84,    87,    54,    86,    14,    55,    12,    16,    22,
      29,    30,    42,    43,    47,    88,    89,    91,    54,    29,
      58,    58,     7,    20,    21,    27,    29,    50,    58,    90,
      91,     6,    56,    61,    58,    58,    58,    58,    39,     6,
      61,    29,    91,    59,    56,    58,    27,    90,     5,    14,
      18,    19,    31,    34,    35,    36,    37,    38,    49,    50,
      51,    52,    29,    90,     8,     9,    11,    58,    90,    90,
      29,    91,    90,    90,    29,    11,    90,    56,    59,    59,
      14,    90,    90,    92,    93,    59,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    57,
      58,    58,    58,    90,    14,    59,    56,    59,    59,    59,
      59,    58,    14,    90,    14,    14,    57,    59,    55,     6,
      61,    29,    29,    59,    55,    40,    90,    14,    14,    14,
      48,    59,    57,    90,    29,    11,    90,    59,    59,    14,
      90,    87,    57,    87,    14,    59,    58,    14,    14,    14,
      59,    41,    46,    59,    45,    14,    59,    14,    87,    14,
      14,    14,    14,    46,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    80,    80,    81,    81,    82,    83,    84,    84,
      85,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     6,     5,     3,     4,     1,
       1,     3,     2,     1,     3,     3,     1,     4,     1,     4,
       1,     3,     0,     2,     0,     3,     4,     1,     2,     0,
       2,     9,     3,     0,     2,     1,     1,     3,     3,     1,
       8,     4,     2,     0,    10,     8,     7,     7,     8,     6,
       9,     6,     5,     8,     5,     8,     5,     5,     8,     5,
       4,     4,     4,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     1,     4,     1,     1,     2,     1,     1,     3,     6,
       3,     0,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 57 "new.y" /* yacc.c:1646  */
    {}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "new.y" /* yacc.c:1646  */
    {(yyval.gptr)=NULL;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "new.y" /* yacc.c:1646  */
    {(yyval.gptr)=NULL;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "new.y" /* yacc.c:1646  */
    {decl_stype->fields=fieldHead; reset_field_data();}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 67 "new.y" /* yacc.c:1646  */
    {decl_stype->fields=fieldHead; reset_field_data(); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "new.y" /* yacc.c:1646  */
    { createField(decl_ftype->name,(yyvsp[-1].nptr)->name); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "new.y" /* yacc.c:1646  */
    {createField(decl_ftype->name,(yyvsp[-1].nptr)->name);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 77 "new.y" /* yacc.c:1646  */
    {decl_ftype=getType((yyvsp[0].nptr)->name);
                 if(decl_ftype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",(yyvsp[0].nptr)->name);
                  exit(1);
                 }
 
               }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 90 "new.y" /* yacc.c:1646  */
    {createType((yyvsp[0].nptr)->name);
	         decl_stype=getType((yyvsp[0].nptr)->name);
         }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "new.y" /* yacc.c:1646  */
    {}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "new.y" /* yacc.c:1646  */
    {}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 99 "new.y" /* yacc.c:1646  */
    {}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "new.y" /* yacc.c:1646  */
    {}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "new.y" /* yacc.c:1646  */
    {}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "new.y" /* yacc.c:1646  */
    {}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "new.y" /* yacc.c:1646  */
    {             
            GInstall((yyvsp[-3].nptr)->name,decl_ftype,(yyvsp[-1].nptr)->val,NULL);
       
            }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "new.y" /* yacc.c:1646  */
    {  
		           GInstall((yyvsp[0].nptr)->name,decl_ftype,1,NULL);
		         }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "new.y" /* yacc.c:1646  */
    {
        
		      	GInstall((yyvsp[-3].nptr)->name,decl_ftype,0,(yyvsp[-1].Arg));
		        Reinitialise();
		    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "new.y" /* yacc.c:1646  */
    {
               decl_argtype=getType((yyvsp[0].nptr)->name);
                if(decl_argtype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",(yyvsp[0].nptr)->name);
                  exit(1);
                 }
               }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "new.y" /* yacc.c:1646  */
    {

		struct ArgStruct *temp=(yyvsp[0].Arg);
		if(temp) {
			while(temp->next)
			 	temp=temp->next;
		}
		if(temp) {
			temp->next=(yyvsp[-1].Arg);
			(yyval.Arg)=(yyvsp[0].Arg);
		}
		else {
			(yyval.Arg)=(yyvsp[-1].Arg);
		}
  }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 156 "new.y" /* yacc.c:1646  */
    {(yyval.Arg)=NULL;}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 158 "new.y" /* yacc.c:1646  */
    {(yyval.Arg)=(yyvsp[0].Arg);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "new.y" /* yacc.c:1646  */
    {(yyval.Arg)=NULL;}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 162 "new.y" /* yacc.c:1646  */
    { 
      	struct ArgStruct *temp=Arginstall((yyvsp[0].nptr)->name,decl_argtype,1);
          temp->next=(yyvsp[-2].Arg);
          (yyval.Arg)=temp;
       }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 168 "new.y" /* yacc.c:1646  */
    {
     	 struct ArgStruct *temp=Arginstall((yyvsp[0].nptr)->name,decl_argtype,2);
         temp->next=(yyvsp[-3].Arg);
         (yyval.Arg)=temp;
     }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "new.y" /* yacc.c:1646  */
    {
     	       (yyval.Arg)=Arginstall((yyvsp[0].nptr)->name,decl_argtype,1);
          }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 178 "new.y" /* yacc.c:1646  */
    { 
               (yyval.Arg)=Arginstall((yyvsp[0].nptr)->name,decl_argtype,2);
          }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 185 "new.y" /* yacc.c:1646  */
    {}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "new.y" /* yacc.c:1646  */
    {}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 188 "new.y" /* yacc.c:1646  */
    {
                    
  printf("ffefwefwef3\n");
				
	                    validate((yyvsp[-7].nptr)->name,decl_ftype,(yyvsp[-5].Arg),(yyvsp[-1].nptr));
 
                      struct GSymbol *temp=GLookup((yyvsp[-7].nptr)->name);

                      (yyvsp[-7].nptr)->Gentry=temp;
  printf("ffefwefwef4\n");

                                   
                      function_gen((yyvsp[-7].nptr)->name,(yyvsp[-1].nptr));
                     
                      Reinitialise();
                  }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 208 "new.y" /* yacc.c:1646  */
    { }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "new.y" /* yacc.c:1646  */
    {}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 211 "new.y" /* yacc.c:1646  */
    {;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 213 "new.y" /* yacc.c:1646  */
    {}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 217 "new.y" /* yacc.c:1646  */
    {
               decl_ltype=getType((yyvsp[0].nptr)->name);
                if(decl_ltype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",(yyvsp[0].nptr)->name);
                  exit(1);
                 }
               }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 226 "new.y" /* yacc.c:1646  */
    {}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 229 "new.y" /* yacc.c:1646  */
    {

		   (yyval.lptr)=LInstall((yyvsp[0].nptr)->name,decl_ltype,0);
        }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 234 "new.y" /* yacc.c:1646  */
    {  
           (yyval.lptr)=LInstall((yyvsp[0].nptr)->name,decl_ltype,0);
        }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 240 "new.y" /* yacc.c:1646  */
    {
		    fprintf(fp,"\n\n");
		    (yyval.nptr) = TreeCreate("integer",NODETYPE_MAIN,0,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
			code_gen((yyval.nptr));
        printf("ASSEMBLY CODE GENERATED\n");
	        Reinitialise();
       }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 249 "new.y" /* yacc.c:1646  */
    {
       	    (yyval.nptr)=TreeCreate("void",NODETYPE_BODY,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[-1].nptr),NULL);
  

       }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 255 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("void", NODETYPE_SLIST , 0,NULL,NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 256 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 260 "new.y" /* yacc.c:1646  */
    {
             (yyval.nptr)=TreeCreate("void",NODETYPE_IFELSE,0,NULL,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr));
           }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 265 "new.y" /* yacc.c:1646  */
    {
             (yyval.nptr)=TreeCreate("void",NODETYPE_IF,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL);
           }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "new.y" /* yacc.c:1646  */
    {
       				newtype=getType((yyvsp[-2].nptr)->name);
       				 if(LLookup((yyvsp[-6].nptr)->name))
       				   	 {
       				   	 	
       				   	 	(yyvsp[-6].nptr)->Lentry=LLookup((yyvsp[-6].nptr)->name);
       				   	 }
       				   	 else
          				(yyvsp[-6].nptr)->Gentry=GLookup((yyvsp[-6].nptr)->name);
          			if(LLookup((yyvsp[-2].nptr)->name))
       				   	 {
       				   	 	
       				   	 	(yyvsp[-2].nptr)->Lentry=LLookup((yyvsp[-2].nptr)->name);
       				   	 }
       				   	 else
          				(yyvsp[-2].nptr)->Gentry=GLookup((yyvsp[-2].nptr)->name);
       				
       			
            (yyval.nptr)=TreeCreate("void",NODETYPE_FST,0,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);


       		}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 292 "new.y" /* yacc.c:1646  */
    {
       				newtype=getType((yyvsp[-2].nptr)->name);
       				 if(LLookup((yyvsp[-6].nptr)->name))
       				   	 {
       				   	 	
       				   	 	(yyvsp[-6].nptr)->Lentry=LLookup((yyvsp[-6].nptr)->name);
       				   	 }
       				   	 else
          				(yyvsp[-6].nptr)->Gentry=GLookup((yyvsp[-6].nptr)->name);
          			if(LLookup((yyvsp[-2].nptr)->name))
       				   	 {
       				   	 	
       				   	 	(yyvsp[-2].nptr)->Lentry=LLookup((yyvsp[-2].nptr)->name);
       				   	 }
       				   	 else
          				(yyvsp[-2].nptr)->Gentry=GLookup((yyvsp[-2].nptr)->name);
       				
            (yyval.nptr)=TreeCreate("void",NODETYPE_SND,0,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);


       		}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 314 "new.y" /* yacc.c:1646  */
    {
           

       				newtype=getType((yyvsp[-7].nptr)->name);
       				   if(LLookup((yyvsp[-7].nptr)->name))
       				   	 {
       				   	 	
       				   	 	(yyvsp[-7].nptr)->Lentry=LLookup((yyvsp[-7].nptr)->name);
       				   	 }
       				   	 else
          				(yyvsp[-7].nptr)->Gentry=GLookup((yyvsp[-7].nptr)->name);

            (yyval.nptr)=TreeCreate("void",NODETYPE_PAIR,0,NULL,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr));

       		}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 330 "new.y" /* yacc.c:1646  */
    {
            check_type((yyvsp[-5].nptr));
            (yyval.nptr)=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
      }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 335 "new.y" /* yacc.c:1646  */
    {
            check_type_array((yyvsp[-8].nptr));
            (yyvsp[-8].nptr)->ptr1=(yyvsp[-6].nptr);
            (yyval.nptr)=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,(yyvsp[-8].nptr),NULL,NULL);
      }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "new.y" /* yacc.c:1646  */
    {
            (yyval.nptr)=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
      }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 345 "new.y" /* yacc.c:1646  */
    {
          check_type((yyvsp[-2].nptr));
          (yyval.nptr)=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
      }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "new.y" /* yacc.c:1646  */
    {
          check_type_array((yyvsp[-5].nptr));
          (yyvsp[-5].nptr)->ptr1=(yyvsp[-3].nptr);
          (yyval.nptr)=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
      }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 356 "new.y" /* yacc.c:1646  */
    {
          (yyval.nptr)=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
      }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "new.y" /* yacc.c:1646  */
    {
            (yyval.nptr)=TreeCreate("void",NODETYPE_WHILE,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL);
           }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 366 "new.y" /* yacc.c:1646  */
    {
           check_type((yyvsp[-2].nptr));
           (yyval.nptr)=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 370 "new.y" /* yacc.c:1646  */
    {
          (yyval.nptr)=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);        
      }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 374 "new.y" /* yacc.c:1646  */
    {
             check_type_array((yyvsp[-5].nptr));                 
              (yyvsp[-5].nptr)->ptr1=(yyvsp[-3].nptr);
              (yyval.nptr)=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
              }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 380 "new.y" /* yacc.c:1646  */
    {
              (yyval.nptr)=TreeCreate("void",NODETYPE_WRITE,0,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
              }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 386 "new.y" /* yacc.c:1646  */
    {
         (yyval.nptr)=TreeCreate("void",NODETYPE_INITIAL,0,NULL,NULL,NULL,NULL,NULL);
      }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 390 "new.y" /* yacc.c:1646  */
    { 
            printf("hihih\n");
            check_type((yyvsp[-3].nptr));
            printf("hihih\n");

            if(strcmp((yyvsp[-3].nptr)->type->name,"pair")==0 && strcmp((yyvsp[-1].nptr)->type->name,"pair")==0)
            (yyval.nptr)=TreeCreate("void",NODETYPE_ASGN_PAIR,0,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
        	else
            (yyval.nptr)=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
      		
      }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 403 "new.y" /* yacc.c:1646  */
    {
           (yyval.nptr)=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);

      }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "new.y" /* yacc.c:1646  */
    {
            check_type_array((yyvsp[-6].nptr));
            

            if(strcmp((yyvsp[-4].nptr)->type->name,"integer")!=0) {
                printf("Invalid array\n");
                exit(1);
            }
            (yyvsp[-6].nptr)->ptr1=(yyvsp[-4].nptr);
            (yyval.nptr)=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-1].nptr),NULL);
    }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 421 "new.y" /* yacc.c:1646  */
    { 
									printf("ffiiiff\n");
								if(strcmp((yyvsp[-1].nptr)->type->name,"pair")==0)
								 (yyval.nptr) = TreeCreate("void", NODETYPE_RET_PAIR,0,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
								else
								 (yyval.nptr) = TreeCreate("void", NODETYPE_RET,0,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
                          }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 429 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("integer",NODETYPE_PLUS,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 430 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("integer",NODETYPE_MINUS,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 431 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("integer",NODETYPE_MUL,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 432 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("integer",NODETYPE_DIV,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 433 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_GT,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 434 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_LT,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 435 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("integer",NODETYPE_MOD,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 436 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_AND,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 437 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_OR,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 438 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_GE,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 439 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_EQ,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 440 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_NE,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 441 "new.y" /* yacc.c:1646  */
    {(yyval.nptr) = TreeCreate("boolean",NODETYPE_LE,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 442 "new.y" /* yacc.c:1646  */
    { 
               (yyval.nptr)=(yyvsp[-1].nptr);
              }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 446 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 447 "new.y" /* yacc.c:1646  */
    {
            struct Gsymbol *temp=GLookup((yyvsp[-3].nptr)->name);
                    if(temp==NULL) {
                        printf("Undefined function %s\n",(yyvsp[-3].nptr)->name);
                        exit(1);
                    }
                    else if(temp->size!=0) {
                        printf("Invalid references to a variable %s %d\n",temp->name,temp->size);
                        exit(1);
                    }
                    else {
                        
                      (yyval.nptr)=TreeCreate(temp->type->name,NODETYPE_FUNC,0,(yyvsp[-3].nptr)->name,(yyvsp[-1].nptr),NULL,NULL,NULL);
                    }

                 }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 465 "new.y" /* yacc.c:1646  */
    {  
                  
                  check_type((yyvsp[0].nptr)); 
                  (yyval.nptr)=(yyvsp[0].nptr);
                }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 472 "new.y" /* yacc.c:1646  */
    {
              check_type_array((yyvsp[-3].nptr));
              (yyvsp[-3].nptr)->ptr1=(yyvsp[-1].nptr);   
              (yyval.nptr)=(yyvsp[-3].nptr);
              }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 478 "new.y" /* yacc.c:1646  */
    {
                   (yyval.nptr)=(yyvsp[0].nptr);
                  }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 482 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 485 "new.y" /* yacc.c:1646  */
    {
      (yyvsp[0].nptr)->val=(yyvsp[0].nptr)->val*(-1);
      (yyval.nptr)=(yyvsp[0].nptr);
   }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 491 "new.y" /* yacc.c:1646  */
    {  (yyval.nptr)= TreeCreate("boolean",NODETYPE_LEAF,TTRUE,NULL,NULL,NULL,NULL,NULL);}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 492 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=TreeCreate("boolean",NODETYPE_LEAF,TFALSE,NULL,NULL,NULL,NULL,NULL);}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 495 "new.y" /* yacc.c:1646  */
    {
                              check_type((yyvsp[-2].nptr));
                              
                              struct Fieldlist *field=IsField((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->name);
                              tt=field->type;
                              (yyval.nptr)=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);

                            }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 504 "new.y" /* yacc.c:1646  */
    {
                              check_type_array((yyvsp[-5].nptr));
                              (yyvsp[-5].nptr)->ptr1=(yyvsp[-3].nptr);
                              struct Fieldlist *field=IsField((yyvsp[-5].nptr)->type,(yyvsp[0].nptr)->name);
                              tt=field->type;
                              (yyval.nptr)=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[0].nptr),NULL);

                            }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 513 "new.y" /* yacc.c:1646  */
    {
                
                 struct Fieldlist *field=IsField(tt,(yyvsp[0].nptr)->name);
                 (yyvsp[-2].nptr)->node=NODETYPE_FIELD;
                 tt=field->type;
                 (yyval.nptr)=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);

          }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 524 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 525 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 528 "new.y" /* yacc.c:1646  */
    {
	              (yyval.nptr)=TreeCreate("void",NODETYPE_EXPLIST,0,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
						}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 532 "new.y" /* yacc.c:1646  */
    {(yyval.nptr)=TreeCreate("void",NODETYPE_EXPLIST,0,NULL,NULL,NULL,(yyvsp[0].nptr),NULL);}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2361 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 534 "new.y" /* yacc.c:1906  */


int yyerror(char const* msg) {
	printf("%s %s\n",msg,yylval);
  exit(1);
}



int main(int argc,char *argv[]) {
    yyin=fopen(argv[1],"r");
    fp=fopen("assembly","w");
    createType("integer");
    createType("boolean");
    createType("pair");
    createType("void");
    createType("NULL");
    initialise_heap();
    initalise_free();
   
    Reinitialise();
    initialise_alloc();
	  yyparse();
	  fclose(fp);
	  return 1;
}
