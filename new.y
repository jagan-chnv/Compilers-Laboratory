%{
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

%}

%union {
	int integer;
	char* string;
	struct ArgStruct *Arg;
	struct ASTNode *nptr;
	struct Gsymbol *gptr;
	struct Lsymbol *lptr;
}


%token  BOOL INTEGER AND '.'  NUL FST SND PAIR ALLOC FREE TYPEDEF DELIM DCR INITIALIZE INR MOD OR TRUE FALSE RETURN MAIN DECL ENDDECL BOOLEAN NUM BEGINE ID IF LT decl Enddecl GT LE GE EQ NE END THEN ELSE READ WRITE ENDIF ENDWHILE endif WHILE DO 
%left '+' '-' AND OR MOD
%left '*' '/'
%right '.'
%nonassoc LT GT LE GE EQ NE 
%type <nptr> expr 
%type <nptr> Exprlist FIELD
%type <nptr> Retstmt LDefblock
%type <nptr> Body Mainblock
%type <nptr> Exphead  Fdef
%type <integer> type argtype stype ltype
%type <nptr> FdefList
%type <nptr> stmt
%type <nptr> ID
%type <nptr> NUM NUL
%type <lptr>  lidlist Ldeflist
%type <Arg>  arglist  Arg argtail
%type <nptr> slist
%type <gptr> idlist
%type <gptr> var
%type <gptr> GDecList TypeDefBlock TypeDefList FieldDeclList

%%
Program : TypeDefBlock GDeclBlock FdefList Mainblock  {};

TypeDefBlock :
        TypeDefList {$$=NULL;} 
          | {$$=NULL;}
          ;


TypeDefList :
            TypeDefList TYPEDEF stype '{' FieldDeclList '}' {decl_stype->fields=fieldHead; reset_field_data();}
            |TYPEDEF stype '{' FieldDeclList '}' {decl_stype->fields=fieldHead; reset_field_data(); }
            ;
 


FieldDeclList : 
              type ID DELIM { createField(decl_ftype->name,$2->name); }
              | FieldDeclList type ID DELIM {createField(decl_ftype->name,$3->name);}
              ;

type:  ID      {decl_ftype=getType($1->name);
                 if(decl_ftype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",$1->name);
                  exit(1);
                 }
 
               }
               ;





stype: ID {createType($1->name);
	         decl_stype=getType($1->name);
         };



GDeclBlock : DECL GDecList ENDDECL {}; 

GDecList : GDecList GDecL {} 
          | GDecL {}
          ;


   


GDecL : type idlist DELIM {}


idlist : idlist ',' var {} 
       | var {};


var : ID '[' NUM ']' {             
            GInstall($1->name,decl_ftype,$3->val,NULL);
       
            }

		    | ID {  
		           GInstall($1->name,decl_ftype,1,NULL);
		         }

		    | ID '(' Arg')' {
        
		      	GInstall($1->name,decl_ftype,0,$3);
		        Reinitialise();
		    };




argtype: ID      {
               decl_argtype=getType($1->name);
                if(decl_argtype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",$1->name);
                  exit(1);
                 }
               }


Arg: argtype arglist argtail {

		struct ArgStruct *temp=$3;
		if(temp) {
			while(temp->next)
			 	temp=temp->next;
		}
		if(temp) {
			temp->next=$2;
			$$=$3;
		}
		else {
			$$=$2;
		}
  }

  | {$$=NULL;}
 
argtail : DELIM Arg {$$=$2;}
     | {$$=NULL;}

arglist : arglist ',' ID 
      { 
      	struct ArgStruct *temp=Arginstall($3->name,decl_argtype,1);
          temp->next=$1;
          $$=temp;
       }

     | arglist ',' '&' ID {
     	 struct ArgStruct *temp=Arginstall($4->name,decl_argtype,2);
         temp->next=$1;
         $$=temp;
     }

     | ID {
     	       $$=Arginstall($1->name,decl_argtype,1);
          }

     | '&' ID { 
               $$=Arginstall($2->name,decl_argtype,2);
          }




FdefList : {}
         | FdefList Fdef {};

Fdef     : type ID '(' Arg ')'  '{' LDefblock Body '}' {
                    
  printf("ffefwefwef3\n");
				
	                    validate($2->name,decl_ftype,$4,$8);
 
                      struct GSymbol *temp=GLookup($2->name);

                      $2->Gentry=temp;
  printf("ffefwefwef4\n");

                                   
                      function_gen($2->name,$8);
                     
                      Reinitialise();
                  }

      


LDefblock : DECL Ldeflist ENDDECL 	{ }
          | {};

Ldeflist : Ldeflist LDecL {;} 

           | LDecL {};

           

ltype: ID      {
               decl_ltype=getType($1->name);
                if(decl_ltype==NULL) {
                  printf("Error:Data type %s\n is not declared\n",$1->name);
                  exit(1);
                 }
               }               


LDecL : ltype lidlist DELIM {}

   
lidlist : lidlist ',' ID {

		   $$=LInstall($3->name,decl_ltype,0);
        }

          | ID  {  
           $$=LInstall($1->name,decl_ltype,0);
        };    

   

Mainblock: ID MAIN  '(' ')' '{' LDefblock Body '}' {
		    fprintf(fp,"\n\n");
		    $$ = TreeCreate("integer",NODETYPE_MAIN,0,NULL,NULL,$7,NULL,NULL);
			code_gen($$);
        printf("ASSEMBLY CODE GENERATED\n");
	        Reinitialise();
       }

Body : BEGINE slist Retstmt END 
       {
       	    $$=TreeCreate("void",NODETYPE_BODY,0,NULL,NULL,$2,$3,NULL);
  

       }

slist: slist stmt {$$ = TreeCreate("void", NODETYPE_SLIST , 0,NULL,NULL, $1, $2, NULL);}
      | {$$=NULL;} 
      

stmt :IF '(' expr ')' THEN slist ELSE slist endif DELIM 
           {
             $$=TreeCreate("void",NODETYPE_IFELSE,0,NULL,NULL,$3,$6,$8);
           } 

      | IF '(' expr ')' THEN slist endif DELIM    
           {
             $$=TreeCreate("void",NODETYPE_IF,0,NULL,NULL,$3,$6,NULL);
           }
       |ID '=' FST '(' ID ')' DELIM
       		{
       				newtype=getType($5->name);
       				 if(LLookup($1->name))
       				   	 {
       				   	 	
       				   	 	$1->Lentry=LLookup($1->name);
       				   	 }
       				   	 else
          				$1->Gentry=GLookup($1->name);
          			if(LLookup($5->name))
       				   	 {
       				   	 	
       				   	 	$5->Lentry=LLookup($5->name);
       				   	 }
       				   	 else
          				$5->Gentry=GLookup($5->name);
       				
       			
            $$=TreeCreate("void",NODETYPE_FST,0,NULL,NULL,$1,$5,NULL);


       		}
       |ID '=' SND '(' ID ')' DELIM
       		{
       				newtype=getType($5->name);
       				 if(LLookup($1->name))
       				   	 {
       				   	 	
       				   	 	$1->Lentry=LLookup($1->name);
       				   	 }
       				   	 else
          				$1->Gentry=GLookup($1->name);
          			if(LLookup($5->name))
       				   	 {
       				   	 	
       				   	 	$5->Lentry=LLookup($5->name);
       				   	 }
       				   	 else
          				$5->Gentry=GLookup($5->name);
       				
            $$=TreeCreate("void",NODETYPE_SND,0,NULL,NULL,$1,$5,NULL);


       		}    
       | ID '=' '(' expr ',' expr ')' DELIM 
       		{
           

       				newtype=getType($1->name);
       				   if(LLookup($1->name))
       				   	 {
       				   	 	
       				   	 	$1->Lentry=LLookup($1->name);
       				   	 }
       				   	 else
          				$1->Gentry=GLookup($1->name);

            $$=TreeCreate("void",NODETYPE_PAIR,0,NULL,NULL,$1,$4,$6);

       		}

      | ID '=' ALLOC '(' ')' DELIM {
            check_type($1);
            $$=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,$1,NULL,NULL);
      }   

      | ID '[' expr ']' '=' ALLOC '(' ')' DELIM {
            check_type_array($1);
            $1->ptr1=$3;
            $$=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,$1,NULL,NULL);
      }     

      | FIELD '=' ALLOC '(' ')' DELIM {
            $$=TreeCreate("void",NODETYPE_ALLOC,0,NULL,NULL,$1,NULL,NULL);
      }   

      | FREE '(' ID ')' DELIM {
          check_type($3);
          $$=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,$3,NULL,NULL);
      } 

      | FREE '(' ID '[' expr ']' ')' DELIM {
          check_type_array($3);
          $3->ptr1=$5;
          $$=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,$3,NULL,NULL);
      }           
          
      | FREE '(' FIELD ')' DELIM {
          $$=TreeCreate("void",NODETYPE_FREE,0,NULL,NULL,$3,NULL,NULL);
      }

      | WHILE '(' expr ')' DO slist ENDWHILE DELIM
           {
            $$=TreeCreate("void",NODETYPE_WHILE,0,NULL,NULL,$3,$6,NULL);
           }

      | READ '(' ID ')' DELIM 
        {
           check_type($3);
           $$=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,$3,NULL,NULL);}

      | READ '(' FIELD ')' DELIM {
          $$=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,$3,NULL,NULL);        
      }

      | READ '(' ID '[' expr ']' ')' DELIM {
             check_type_array($3);                 
              $3->ptr1=$5;
              $$=TreeCreate("void",NODETYPE_READ,0,NULL,NULL,$3,NULL,NULL);
              }

      | WRITE '(' expr ')' DELIM{
              $$=TreeCreate("void",NODETYPE_WRITE,0,NULL,NULL,$3,NULL,NULL);
              }

      

      | INITIALIZE '(' ')' DELIM {
         $$=TreeCreate("void",NODETYPE_INITIAL,0,NULL,NULL,NULL,NULL,NULL);
      }

      | ID '=' expr DELIM       { 
            printf("hihih\n");
            check_type($1);
            printf("hihih\n");

            if(strcmp($1->type->name,"pair")==0 && strcmp($3->type->name,"pair")==0)
            $$=TreeCreate("void",NODETYPE_ASGN_PAIR,0,NULL,NULL,$1,$3,NULL);
        	else
            $$=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,$1,$3,NULL);
      		
      }


      | FIELD '=' expr DELIM {
           $$=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,$1,$3,NULL);

      }

      | ID '[' expr ']' '=' expr  DELIM {
            check_type_array($1);
            

            if(strcmp($3->type->name,"integer")!=0) {
                printf("Invalid array\n");
                exit(1);
            }
            $1->ptr1=$3;
            $$=TreeCreate("void",NODETYPE_ASGN,0,NULL,NULL,$1,$6,NULL);
    }; 


Retstmt : RETURN expr DELIM  { 
									printf("ffiiiff\n");
								if(strcmp($2->type->name,"pair")==0)
								 $$ = TreeCreate("void", NODETYPE_RET_PAIR,0,NULL,NULL,$2,NULL,NULL);
								else
								 $$ = TreeCreate("void", NODETYPE_RET,0,NULL,NULL,$2,NULL,NULL);
                          };
 
 expr : expr '+' expr  {$$ = TreeCreate("integer",NODETYPE_PLUS,0,NULL,NULL,$1,$3,NULL);}
   | expr '-' expr {$$ = TreeCreate("integer",NODETYPE_MINUS,0,NULL,NULL,$1,$3,NULL);} 
   | expr '*' expr {$$ = TreeCreate("integer",NODETYPE_MUL,0,NULL,NULL,$1,$3,NULL);} 
   | expr '/' expr {$$ = TreeCreate("integer",NODETYPE_DIV,0,NULL,NULL,$1,$3,NULL);} 
   | expr GT expr  {$$ = TreeCreate("boolean",NODETYPE_GT,0,NULL,NULL,$1,$3,NULL);} 
   | expr LT expr  {$$ = TreeCreate("boolean",NODETYPE_LT,0,NULL,NULL,$1,$3,NULL);} 
   | expr MOD expr  {$$ = TreeCreate("integer",NODETYPE_MOD,0,NULL,NULL,$1,$3,NULL);} 
   | expr AND expr {$$ = TreeCreate("boolean",NODETYPE_AND,0,NULL,NULL,$1,$3,NULL);}
   | expr OR expr {$$ = TreeCreate("boolean",NODETYPE_OR,0,NULL,NULL,$1,$3,NULL);}
   | expr GE expr  {$$ = TreeCreate("boolean",NODETYPE_GE,0,NULL,NULL,$1,$3,NULL);}
   | expr EQ expr  {$$ = TreeCreate("boolean",NODETYPE_EQ,0,NULL,NULL,$1,$3,NULL);}
   | expr NE expr  {$$ = TreeCreate("boolean",NODETYPE_NE,0,NULL,NULL,$1,$3,NULL);}
   | expr LE expr  {$$ = TreeCreate("boolean",NODETYPE_LE,0,NULL,NULL,$1,$3,NULL);} 
   | '(' expr ')' { 
               $$=$2;
              }
   
   | FIELD {$$=$1;}
   |  ID '(' Exprlist ')' {
            struct Gsymbol *temp=GLookup($1->name);
                    if(temp==NULL) {
                        printf("Undefined function %s\n",$1->name);
                        exit(1);
                    }
                    else if(temp->size!=0) {
                        printf("Invalid references to a variable %s %d\n",temp->name,temp->size);
                        exit(1);
                    }
                    else {
                        
                      $$=TreeCreate(temp->type->name,NODETYPE_FUNC,0,$1->name,$3,NULL,NULL,NULL);
                    }

                 }


   | ID         {  
                  
                  check_type($1); 
                  $$=$1;
                } 


   | ID '[' expr ']'  {
              check_type_array($1);
              $1->ptr1=$3;   
              $$=$1;
              }

   | NUM           {
                   $$=$1;
                  }

   | NUL {$$=$1;}


   | '-' NUM     {
      $2->val=$2->val*(-1);
      $$=$2;
   }

   
   | TRUE {  $$= TreeCreate("boolean",NODETYPE_LEAF,TTRUE,NULL,NULL,NULL,NULL,NULL);}
   | FALSE {$$=TreeCreate("boolean",NODETYPE_LEAF,TFALSE,NULL,NULL,NULL,NULL,NULL);}


FIELD     : ID '.'  ID       {
                              check_type($1);
                              
                              struct Fieldlist *field=IsField($1->type,$3->name);
                              tt=field->type;
                              $$=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,$1,$3,NULL);

                            }  

          | ID '[' expr ']' '.'  ID       {
                              check_type_array($1);
                              $1->ptr1=$3;
                              struct Fieldlist *field=IsField($1->type,$6->name);
                              tt=field->type;
                              $$=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,$1,$6,NULL);

                            }  

          | FIELD '.' ID   {
                
                 struct Fieldlist *field=IsField(tt,$3->name);
                 $1->node=NODETYPE_FIELD;
                 tt=field->type;
                 $$=TreeCreate(tt->name,NODETYPE_FIELD_END,0,NULL,NULL,$1,$3,NULL);

          }
          ;


Exprlist : {$$=NULL;}
         | Exphead  {$$=$1;};


Exphead:  Exphead ',' expr {
	              $$=TreeCreate("void",NODETYPE_EXPLIST,0,NULL,NULL,$1,$3,NULL);
						}

        | expr {$$=TreeCreate("void",NODETYPE_EXPLIST,0,NULL,NULL,NULL,$1,NULL);};
  
%%

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
