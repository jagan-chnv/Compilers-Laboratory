int get_reg() {

  if(reg<7) {
    reg++;
    return reg;
  }
  else {
    printf("Register Memory exceed\n");
    exit(1);
  }
}

void free_all_regs () {
  reg=-1;
}

void free_reg() {
  if(reg==-1) {
    printf("register error\n");
    exit(1);
  }
  
   
  
  reg--;
}

int get_label() {
   label++;
   return label;
}

void GetVal(struct ASTNode *temp,int r) {
  if(temp->node==NODETYPE_FIELD_END) 
          fprintf(fp,"MOV R%d [R%d]\n",r,r);
}


void initialise_heap() {
  

  fprintf(fp,"LL0:\n");
  fprintf(fp,"MOV [0] 1\n\n");
  fprintf(fp,"MOV R0 1\n");

  
  fprintf(fp,"le5:\n");
  fprintf(fp,"MOV R1 1750\n");
  fprintf(fp,"EQ R1 R0\n");
  fprintf(fp,"JNZ R1,loop6\n");
  fprintf(fp,"MOV [R0] -1\n");
  fprintf(fp,"INR R0\n");
  fprintf(fp,"JMP le5\n");
  fprintf(fp,"loop6:\n");

  fprintf(fp,"MOV R0 1\n");
  fprintf(fp,"loop:\n");
  fprintf(fp,"MOV R1 1585\n");
  fprintf(fp,"MOV R2 R0\n");

  fprintf(fp,"LE R0 R1\n");
  fprintf(fp,"JZ R0,outs\n");
  
  fprintf(fp,"MOV R0 R2\n");
  fprintf(fp,"MOV R1 16\n");
  fprintf(fp,"ADD R1 R0\n");
  fprintf(fp,"MOV [R0] R1\n");
  fprintf(fp,"MOV R0 R1\n");

  fprintf(fp,"JMP loop\n");

  fprintf(fp,"outs:\n");
  fprintf(fp,"RET\n\n");
}

void initalise_free() {
  
  fprintf(fp,"LL1:\n");
  fprintf(fp,"MOV R0 SP\n");
  fprintf(fp,"MOV R1 -1\n");
  fprintf(fp,"ADD R0 R1\n");
  
  fprintf(fp,"MOV R1 R0\n");
  fprintf(fp,"DCR R1\n");
  fprintf(fp,"MOV R1 [R1]\n");
  fprintf(fp,"MOV [R1] -1\n");

  fprintf(fp,"MOV R0 [R0]\n");
  fprintf(fp,"MOV [R0] [0]\n");
  fprintf(fp,"MOV [0] R0\n");
  fprintf(fp,"INR R0\n");
  
  fprintf(fp,"MOV R1 0\n");
  fprintf(fp,"MOV R2 15\n");
  fprintf(fp,"LOOP:\n");
  fprintf(fp,"MOV R3 R1\n");
  fprintf(fp,"EQ R3 R2\n");
  fprintf(fp,"JNZ R3,LOOP2\n");
  fprintf(fp,"MOV [R0] -1\n");
  fprintf(fp,"INR R0\n");
  fprintf(fp,"INR R1\n");
  fprintf(fp,"JMP LOOP\n");
  fprintf(fp,"LOOP2:\n");
  
  fprintf(fp,"RET\n\n");
}


void initialise_alloc() {
  
  fprintf(fp,"LL2:\n");
  fprintf(fp,"MOV R0 [0]\n");
  fprintf(fp,"MOV [0] [R0]\n");
  fprintf(fp,"MOV R1 SP\n");
  fprintf(fp,"MOV R2 -4\n");
  fprintf(fp,"ADD R1 R2\n");
  fprintf(fp,"MOV [R1] R0\n");
  fprintf(fp,"RET\n\n");
}

int functioncall_gen(struct ASTNode *root) {

  int r,r1,r2,r3,r4,c=0;
  struct Gsymbol *g=GLookup(root->name);
  struct ArgStruct *list=g->arglist;
  struct ASTNode *templist=root->arglist;

  //Saving the values in the registers;
  
  while(c<=reg) {
    fprintf(fp,"PUSH R%d\n",c);
    c++;
  }

  c--;


  while(templist) {

    if(list->passType==1) {
       
      r=code_gen(templist->ptr2);
      if(templist->ptr2->node==NODETYPE_FIELD_END)
        fprintf(fp,"MOV R%d [R%d]\n",r,r);
      fprintf(fp,"PUSH R%d\n",r);
       
      free_reg();
    }

    else {

      if(templist->ptr2->node==NODETYPE_FIELD_END) {
        r=code_gen(templist->ptr2);

        fprintf(fp,"PUSH R%d\n",r);
       
        free_reg();
      }

      else if(templist->ptr2->Lentry) {
      		if(strcmp(templist->ptr2->type->name,"pair")==0)
      		{
      				   r1=get_reg();
				        r2=get_reg();
				        fprintf(fp,"MOV R%d BP\n",r1);
				        fprintf(fp,"MOV R%d %d\n",r2,templist->ptr2->Lentry->binding);
				        fprintf(fp,"ADD R%d R%d\n",r1,r2);
       					 fprintf(fp,"PUSH R%d\n",r1);


      		}
      		else
      		{
        
        r1=get_reg();
        r2=get_reg();
        fprintf(fp,"MOV R%d BP\n",r1);
        fprintf(fp,"MOV R%d %d\n",r2,templist->ptr2->Lentry->binding);
        fprintf(fp,"ADD R%d R%d\n",r1,r2);
        free_reg();

        if(templist->ptr2->Lentry->ref==2) {
          fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
        }  
        fprintf(fp,"PUSH R%d\n",r1);
        free_reg();
    }
      }
      
      else {    
         r=get_reg();
         fprintf(fp,"MOV R%d %d\n",r,templist->ptr2->Gentry->binding);
         if(templist->ptr2->ptr1) {
         	r2=code_gen(templist->ptr2->ptr1);
         	fprintf(fp,"ADD R%d R%d\n",r,r2);
         	free_reg();
         }
         fprintf(fp,"PUSH R%d\n",r);
         free_reg();
      }
      
    }

    templist=templist->ptr1;
    list=list->next;
  }

 
  r=get_reg();                  
  fprintf(fp,"PUSH R%d\n",r);
  free_reg();

  fprintf(fp,"CALL LL%d\n",g->binding);
  reg=c;
  r=get_reg();
  fprintf(fp,"POP R%d\n",r);  
  r1=get_reg();
  list=g->arglist;
  while(list) {
    fprintf(fp,"POP R%d\n",r1);
    list=list->next;
  }
  free_reg();
  
  
  while(c>=0) {
    fprintf(fp,"POP R%d\n",c);
    c--;
  }

  return r;
}

void function_gen(char *name,struct ASTNode *body) {

  int r1;
  struct Gsymbol *g=GLookup(name);   
  fprintf(fp,"LL%d:\n",g->binding);
  fprintf(fp,"PUSH BP\n");
  fprintf(fp,"MOV BP SP\n");
  struct Lsymbol *temp=LSymbolHead;
  free_all_regs();
  r1=get_reg();
  
  
  while(temp) {
    if(temp->ref==0) {
      fprintf(fp,"PUSH R%d\n",r1);
    }
    temp=temp->next;
  }
  free_reg();
  printf("ffefwefwef1\n");

  code_gen(body);

  
  r1=get_reg();
  temp=LSymbolHead;

  while(temp) {
    if(temp->ref==0) {
      fprintf(fp,"POP R%d\n",r1);
    }
    temp=temp->next;
  }
  free_reg();
  free_all_regs();
  fprintf(fp,"POP BP\n");
  fprintf(fp,"RET\n");

}



int code_gen (struct ASTNode * root) {
  int l1,l2,r,r1,r2,r3,r4,bind;
  struct Fieldlist *field;
    if(!root) 
      return 0;
    
      switch(root->node) {

      
          case NODETYPE_MUL :

                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                 GetVal(root->ptr2,r2);

                fprintf(fp,"MUL R%d R%d\n",r1,r2);
                free_reg();
                return r1;

           case NODETYPE_PLUS :
                r1=code_gen(root->ptr1);
                 GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                 GetVal(root->ptr2,r2);

                fprintf(fp,"ADD R%d R%d\n",r1,r2);
                free_reg();
                return r1;

           
            case NODETYPE_MINUS :
                r1=code_gen(root->ptr1);
              GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);

                fprintf(fp,"SUB R%d R%d\n",r1,r2);
                free_reg();
                return r1;

            case NODETYPE_MOD :
                r1=code_gen(root->ptr1);
                 GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                 GetVal(root->ptr2,r2);

                fprintf(fp,"MOD R%d R%d\n",r1,r2);

                free_reg();
                return r1;    

            case NODETYPE_DIV :
                r1=code_gen(root->ptr1);
                 GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                 GetVal(root->ptr2,r2);

                fprintf(fp,"DIV R%d R%d\n",r1,r2);
                free_reg();
                return r1;
            
            
            case NODETYPE_FIELD_END:
                r1=code_gen(root->ptr1);
                field=IsField(root->ptr1->type,root->ptr2->name);
                r2=get_reg();
                fprintf(fp,"MOV R%d %d\n",r2,field->field_num);
                fprintf(fp,"ADD R%d R%d\n",r1,r2);
               
                free_reg();
                return r1;
               
           case NODETYPE_FIELD:
                r1=code_gen(root->ptr1);
                field=IsField(root->ptr1->type,root->ptr2->name);
                r2=get_reg();
                fprintf(fp,"MOV R%d %d\n",r2,field->field_num);
                fprintf(fp,"ADD R%d R%d\n",r1,r2);
                fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                
      
                free_reg();
                return r1;

           case NODETYPE_ASGN_PAIR:
              printf("frienas");
                if(root->ptr2->node==NODETYPE_FUNC)
                {
                	r1=code_gen(root->ptr2);
                	fprintf(fp, "// im here\n");

                		if(root->ptr1->Lentry)
                		{
                			r2=get_reg();
                   			r3=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r2,root->ptr1->Lentry->binding);
                   			fprintf(fp,"MOV R%d BP\n",r3);
           					fprintf(fp,"ADD R%d R%d\n",r2,r3);
           					fprintf(fp,"MOV [R%d] [R%d]\n",r2,r1);
           					fprintf(fp,"INR R%d\n",r2);
           					fprintf(fp,"INR R%d\n",r1);
           					fprintf(fp,"MOV [R%d] [R%d]\n",r2,r1);

           					free_reg();
           					free_reg();

                		}
                		else
                		{	r2=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r2,root->ptr1->Lentry->binding);
                   				fprintf(fp,"MOV [R%d] [R%d]\n",r2,r1);
           					fprintf(fp,"INR R%d\n",r2);
           					fprintf(fp,"INR R%d\n",r1);
           					fprintf(fp,"MOV [R%d] [R%d]\n",r2,r1);

           					free_reg();

                		}	


                }
                 if(root->ptr1->Lentry && root->ptr2->Lentry)
                   {
                   	printf("sfsf\n");
                   			r1=get_reg();
                   			r2=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Lentry->binding);
                   			fprintf(fp,"MOV R%d BP\n",r2);
           					fprintf(fp,"ADD R%d R%d\n",r1,r2);
           					 r3=get_reg();
           					fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Lentry->binding);
                   			fprintf(fp,"MOV R%d BP\n",r3);
           					fprintf(fp,"ADD R%d R%d\n",r2,r3);
           					free_reg();
                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			fprintf(fp,"INR R%d\n",r1);
                   			fprintf(fp,"INR R%d\n",r2);

                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			free_reg();
                   			free_reg();

           					 
                   }
                  else if(root->ptr1->Gentry && root->ptr2->Lentry)
                  {
                  		r1=get_reg();
                   			r2=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);
           					 r3=get_reg();
           					fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Lentry->binding);
                   			fprintf(fp,"MOV R%d BP\n",r3);
           					fprintf(fp,"ADD R%d R%d\n",r2,r3);
           					free_reg();
                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			fprintf(fp,"INR R%d\n",r1);
                   			fprintf(fp,"INR R%d\n",r2);

                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			free_reg();
                   			free_reg();
                  }
                  else if(root->ptr1->Lentry && root->ptr2->Gentry)
                  {
                   	printf("sfsf44\n");

                  		r1=get_reg();
                   			r2=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Lentry->binding);
                   			fprintf(fp,"MOV R%d BP\n",r2);
           					fprintf(fp,"ADD R%d R%d\n",r1,r2);
           					fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Gentry->binding);
                   			
                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			fprintf(fp,"INR R%d\n",r1);
                   			fprintf(fp,"INR R%d\n",r2);

                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			free_reg();
                   			free_reg();
                  } 
                  else if(root->ptr1->Gentry && root->ptr2->Gentry)
                  {
                  		r1=get_reg();
                   			r2=get_reg();
                   			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);
                   		
           					fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Gentry->binding);
                   			
                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			fprintf(fp,"INR R%d\n",r1);
                   			fprintf(fp,"INR R%d\n",r2);

                   			fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
                   			free_reg();
                   			free_reg();
                  }  
               return 0;  

           case NODETYPE_FST:
           			printf("sfs\n");

              if(root->ptr1->Lentry)
           		{
           				r1=get_reg();
           				r2=get_reg();
           			printf("sfs\n");

           			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Lentry->binding);
           			fprintf(fp,"MOV R%d BP\n",r2);
           			fprintf(fp,"ADD R%d R%d\n",r1,r2);
           			free_reg();
           		}
           		else if(root->ptr1->Gentry)
           		{	r1=get_reg();
           			printf("sfs2\n");
           			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);


           		}	
           			if(root->ptr2->Lentry)
           			{
           				printf("erewr\n");
           				r2=get_reg();
           				r3=get_reg();
           		
           		fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Lentry->binding);
           			fprintf(fp,"MOV R%d BP\n",r3);
           			fprintf(fp,"ADD R%d R%d\n",r2,r3);
           			free_reg();
           			if(root->ptr2->Lentry->ref=1)
           			 {
           			 	fprintf(fp,"MOV R%d [R%d]\n",r2,r2);
           			 }	
           		fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
           			free_reg();
           			free_reg();

           			}

           		else if(root->ptr2->Gentry)

           		{
           				printf("erewr2\n");

           			r2=get_reg();
           		
           		fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Gentry->binding);
           			free_reg();
           		fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
           			free_reg();
           			free_reg();


           		}
           	return 0;

             case NODETYPE_SND:

              if(root->ptr1->Lentry)
           		{
           				r1=get_reg();
           				r2=get_reg();

           			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Lentry->binding);
           			fprintf(fp,"MOV R%d BP\n",r2);
           			fprintf(fp,"ADD R%d R%d\n",r1,r2);
           			free_reg();
           		}
           		else if(root->ptr1->Gentry)
           		{	r1=get_reg();
           			fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);

           		}	
           			if(root->ptr2->Lentry)
           			{
           				r2=get_reg();
           				r3=get_reg();
           		
           		fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Lentry->binding);
           			fprintf(fp,"MOV R%d BP\n",r3);
           			fprintf(fp,"ADD R%d R%d\n",r2,r3);
           			if(root->ptr2->Lentry->ref=1)
           			 {
           			 	fprintf(fp,"MOV R%d [R%d]\n",r2,r2);
           			fprintf(fp, "DCR R%d\n",r2);

           			 }	
           			 else
           			fprintf(fp, "INR R%d\n",r2);
           			free_reg();

           		fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
           			free_reg();
           			free_reg();

           			}

           		else if(root->ptr2->Gentry)

           		{
           			r2=get_reg();
           		
           		fprintf(fp,"MOV R%d %d\n",r2,root->ptr2->Gentry->binding);
           			fprintf(fp, "INR R%d\n",r2);

           			free_reg();
           		fprintf(fp,"MOV [R%d] [R%d]\n",r1,r2);
           			free_reg();
           			free_reg();


           		}
           	return 0; 


           case NODETYPE_PAIR:

           		r1=code_gen(root->ptr2);
           		r2=code_gen(root->ptr3);
           		r3=get_reg();

           		if(root->ptr1->Lentry)
           		{

           				r4=get_reg();

           			fprintf(fp,"MOV R%d %d\n",r3,root->ptr1->Lentry->binding);
           			fprintf(fp,"MOV R%d BP\n",r4);
           			fprintf(fp,"ADD R%d R%d\n",r3,r4);
           			free_reg();

           			fprintf(fp,"MOV [R%d] R%d\n",r3,r1);
           			fprintf(fp,"INR R%d\n",r3);
           			fprintf(fp,"MOV [R%d] R%d\n",r3,r2);
           			   free_reg();
                    free_reg();
                    free_reg();
           		}
           		else if(root->ptr1->Gentry)

           		{

           				fprintf(fp,"MOV R%d %d\n",r3,root->ptr1->Gentry->binding);
           			fprintf(fp,"MOV [R%d] R%d\n",r3,r1);
           			fprintf(fp,"INR R%d\n",r3);
           			fprintf(fp,"MOV [R%d] R%d\n",r3,r2);
           			   free_reg();
                    free_reg();
           		}

           			return 0;

            case NODETYPE_MAIN:
  printf("ffefwefwef\n");

              fprintf(fp,"START\n");
              fprintf(fp,"MOV SP 1750\n");
              fprintf(fp,"MOV BP SP\n");
              r1 = get_reg();
              struct Lsymbol *Ltemp = LSymbolHead;
              while(Ltemp != NULL){
                  if(Ltemp->ref==0){

                    fprintf(fp,"PUSH R%d\n",r1); 
                    Ltemp = Ltemp->next;
                  } 
              }
              fprintf(fp,"MAIN:\n");
              free_reg();

              code_gen(root->ptr1);
              fprintf(fp,"HALT\n");
              return 0;

        
              case NODETYPE_ALLOC:
                
                 if(root->ptr1->node==NODETYPE_FIELD_END) {
                    r1=code_gen(root->ptr1);
                    fprintf(fp,"PUSH R0\n");
                    fprintf(fp,"PUSH R0\nPUSH R1\nPUSH R2\n");
                    fprintf(fp,"CALL LL2\n");
                    fprintf(fp,"POP R2\nPOP R1\nPOP R0\n");  
                    r2=get_reg();
                    fprintf(fp,"POP R%d\n",r2);
                    fprintf(fp,"MOV [R%d] R%d\n",r1,r2);
                    free_reg();
                    free_reg();
                 }
                 else {
                      r1=get_reg();
                      r2=get_reg();
                    if(root->ptr1->Lentry) {
                     
                      fprintf(fp,"MOV R%d BP\n",r1);
                      fprintf(fp,"MOV R%d %d\n",r2,root->ptr1->Lentry->binding);
                      fprintf(fp,"ADD R%d R%d\n",r1,r2);
                      if(root->ptr1->Lentry->ref==2)
                        fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                      
                    }

                    else {

                      fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);
                      if(root->ptr1->ptr1) {
                      r2=code_gen(root->ptr1->ptr1);
                      fprintf(fp,"ADD R%d R%d\n",r1,r2);}

                      
                    }

                      fprintf(fp,"PUSH R0\n");
                      fprintf(fp,"PUSH R0\nPUSH R1\nPUSH R2\n");
                    
                      fprintf(fp,"CALL LL2\n"); 
                      fprintf(fp,"POP R2\nPOP R1\nPOP R0\n");   
              
                      fprintf(fp,"POP R%d\n",r2);
                      fprintf(fp,"MOV [R%d] R%d\n ",r1,r2);
                      free_reg();
                      free_reg();

                 }


              return 0;

              case NODETYPE_INITIAL:
                  fprintf(fp,"PUSH R0\nPUSH R1\nPUSH R2\n");
                  fprintf(fp,"CALL LL0\n");
                  fprintf(fp,"POP R2\nPOP R1\nPOP R0\n");
              return 0;


              case NODETYPE_FREE:
                  if(root->ptr1->node==NODETYPE_FIELD_END) {

                      r1=code_gen(root->ptr1);
                    
                      fprintf(fp,"PUSH R0\n");
                      fprintf(fp,"PUSH R1\nPUSH R2\nPUSH R3\n");
                      fprintf(fp,"PUSH R%d\n",r1);
                      fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                      fprintf(fp,"PUSH R%d\n",r1);
                    
                      fprintf(fp,"CALL LL1\n");
                      fprintf(fp,"POP R%d\n",r1);
                      fprintf(fp,"POP R%d\n",r1);
                      fprintf(fp,"POP R3\nPOP R2\nPOP R1\nPOP R0\n");

                      free_reg();
                    

                  }

                 else {
                      r1=get_reg();
                      r2=get_reg();
                
                    if(root->ptr1->Lentry) {
                    
                      fprintf(fp,"MOV R%d BP\n",r1);
                      fprintf(fp,"MOV R%d %d\n",r2,root->ptr1->Lentry->binding);
                      fprintf(fp,"ADD R%d R%d\n",r1,r2);
                      if(root->ptr1->Lentry->ref==2) {
                        fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                      }

                    }

                    else {
                       
                      fprintf(fp,"MOV R%d %d\n",r1,root->ptr1->Gentry->binding);
                      if(root->ptr1->ptr1) {
                      r2=code_gen(root->ptr1->ptr1);
                      fprintf(fp,"ADD R%d R%d\n",r1,r2);}

                      
                    }

                      fprintf(fp,"PUSH R0\n");
                      fprintf(fp,"PUSH R1\nPUSH R2\nPUSH R3\n");
                      fprintf(fp,"PUSH R%d\n",r1);
                      fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                      fprintf(fp,"PUSH R%d\n",r1);
                    
                      fprintf(fp,"CALL LL1\n");
                      fprintf(fp,"POP R%d\n",r1);
                      fprintf(fp,"POP R%d\n",r1);
                      fprintf(fp,"POP R3\nPOP R2\nPOP R1\nPOP R0\n");

                      free_reg();
                      free_reg();
                 }
                 


              return 0;

              case NODETYPE_LT  :
                r1=code_gen(root->ptr1);
                 GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                 GetVal(root->ptr2,r2);
                fprintf(fp,"LT R%d R%d\n",r1,r2);
                free_reg();
                return r1;


              case NODETYPE_FUNC:
            ;
                fprintf(fp," // Before funtion call\n\n\n");
                r=functioncall_gen(root);
                return r;

              case NODETYPE_LEAF:
                r1=get_reg();
                fprintf(fp,"MOV R%d %d\n",r1,root->val);
                return r1;

            case NODETYPE_LE  :
                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);
                fprintf(fp,"LE R%d R%d\n",r1,r2);
                free_reg();
                return r1;
            
            case NODETYPE_AND:
                r1 = code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2 = code_gen(root->ptr2);
                GetVal(root->ptr2,r2);        
                fprintf(fp,"ADD R%d R%d\n",r1,r2);
                fprintf(fp,"MOV R%d 2\n",r2);
                fprintf(fp,"EQ R%d R%d\n",r1,r2);
                free_reg();
                return r1;                 
                break;

        case NODETYPE_OR:
                r1 = code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2 = code_gen(root->ptr2);
                GetVal(root->ptr2,r2);        
                fprintf(fp,"ADD R%d R%d\n",r1,r2);
                fprintf(fp,"MOV R%d 0\n",r2);
                fprintf(fp,"GE R%d R%d\n",r1,r2);
                free_reg();
                return r1;                 
                break;
                

            case NODETYPE_GE  :
                
                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);
                fprintf(fp,"GE R%d R%d\n",r1,r2);
                free_reg();
                return r1;

             case NODETYPE_EQ :
                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);
                fprintf(fp,"EQ R%d R%d\n",r1,r2);
                free_reg();
                return r1;

            case NODETYPE_NE  :
                
                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
               
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);
                
                fprintf(fp,"NE R%d R%d\n",r1,r2);
                free_reg();
                return r1;

             case NODETYPE_GT :
               
                r1=code_gen(root->ptr1);
                GetVal(root->ptr1,r1);
                r2=code_gen(root->ptr2);
                GetVal(root->ptr2,r2);
                fprintf(fp,"GT R%d R%d\n",r1,r2);
                free_reg();
                return r1; 
            
            case NODETYPE_ID:
                r1=get_reg();     
               if(root->ptr1==NULL) {

                   if(root->Lentry) {
                    bind=root->Lentry->binding;
               
                    r2=get_reg();
                    fprintf(fp,"MOV R%d BP\n",r1);
                    fprintf(fp,"MOV R%d %d\n",r2,bind);
                    fprintf(fp,"ADD R%d R%d\n",r1,r2);
                    
                    
                    fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                
                    if(root->Lentry->ref==2){
                      fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                    } 

                    
                    free_reg();
                    return r1;
                   }
                   else {
                     bind=root->Gentry->binding;
                     
                     r2=get_reg();
                     fprintf(fp,"MOV R%d %d\n",r2,bind);
                     fprintf(fp,"MOV R%d [R%d]\n",r1,r2);
      

                     free_reg();
                     return r1;
                   }

               }

               else {
                     bind=root->Gentry->binding;
                     r2=code_gen(root->ptr1);
                     fprintf(fp,"MOV R%d %d\n",r1,bind);
                     fprintf(fp,"ADD R%d R%d\n",r1,r2);
                     free_reg();
                     fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                     return r1;
               }
              break;



  
            case NODETYPE_BODY:
            printf("hi1\n");
             code_gen(root->ptr1);
            printf("hi2\n");

             code_gen(root->ptr2);
            printf("hi3\n");

             break;


             case NODETYPE_ASGN:
                r2=code_gen(root->ptr2);
                if(root->ptr2->node==NODETYPE_FIELD_END) {
                  fprintf(fp,"MOV R%d [R%d]\n",r2,r2);
                }

              if(root->ptr1->node!=NODETYPE_FIELD_END) {
                if(root->ptr1->ptr1) {
                    bind=root->ptr1->Gentry->binding;
                    r1=code_gen(root->ptr1->ptr1);
                    r3=get_reg();
                    fprintf(fp,"MOV R%d %d\n",r3,bind);
                    fprintf(fp,"ADD R%d R%d\n",r1,r3);
                    fprintf(fp,"MOV [R%d] R%d\n ",r1,r2);
                    free_reg();
                    free_reg();
                    free_reg();
                  
                }else {
                  if(root->ptr1->Lentry) {
                
                     bind=root->ptr1->Lentry->binding;
                     r1=get_reg();
                     r3=get_reg();
                     fprintf(fp,"MOV R%d BP\n",r1);
                     fprintf(fp,"MOV R%d %d\n",r3,bind);
                     fprintf(fp,"ADD R%d R%d\n",r1,r3);
                     if(root->ptr1->Lentry->ref==2)
                     fprintf(fp,"MOV R%d [R%d] \n",r1,r1);
                     free_reg();
                     fprintf(fp,"MOV [R%d] R%d\n",r1,r2);
                     
                     free_reg();
                     free_reg();
                  }
                  else {
                    bind=root->ptr1->Gentry->binding;
                    fprintf(fp,"MOV [%d] R%d\n ",bind,r2);
                    free_reg();
                  }
                }
              }


                else {
                    r1=code_gen(root->ptr1);
                    fprintf(fp,"MOV [R%d] R%d\n  ",r1,r2);
                    free_reg();
                    free_reg();
                }

                return 0;
                break;

          case NODETYPE_READ:
        
              if(root->ptr1->node==NODETYPE_FIELD_END) {
                r1=code_gen(root->ptr1);
                r2=get_reg();
                fprintf(fp,"IN R%d\n",r2);
                fprintf(fp,"MOV [R%d] R%d\n",r1,r2);
                free_reg();
                free_reg();
                return 0;
              }

              if(root->ptr1->Lentry) {
                r1=get_reg();
                r2=get_reg();
              
                fprintf(fp,"MOV R%d BP\n",r1);
                bind=root->ptr1->Lentry->binding;
                fprintf(fp,"MOV R%d %d\n",r2,bind);
                fprintf(fp,"ADD R%d R%d\n",r1,r2);
                fprintf(fp,"IN R%d\n",r2);
                if(root->ptr1->Lentry->ref == 2){
                  fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
                }
                fprintf(fp,"MOV [R%d] R%d\n",r1,r2);
                free_reg();
                free_reg();
              }
              else {
                if(root->ptr1->ptr1) {
                  bind=root->ptr1->Gentry->binding;
                  r3=get_reg();
                  fprintf(fp,"MOV R%d %d\n",r3,bind);
                  r1=code_gen(root->ptr1->ptr1);
                  fprintf(fp,"ADD R%d R%d\n",r3,r1);
                  r2=get_reg();
                  fprintf(fp,"IN R%d\n",r2);
                  fprintf(fp,"MOV [R%d] R%d\n",r3,r2);
                  free_reg();
                  free_reg();
                  free_reg();
                }
                else {
                  bind=root->ptr1->Gentry->binding;
                  r1=get_reg();

                  fprintf(fp,"MOV R%d %d\n",r1,bind);
                  
                  r2=get_reg();
                  fprintf(fp,"IN R%d\n",r2);
                  fprintf(fp,"MOV [R%d] R%d\n",r1,r2);
                  free_reg();
                  free_reg();
                }
              }
              return 0;
              break;

        case NODETYPE_WRITE:
              r1=code_gen(root->ptr1);
              if(root->ptr1->node==NODETYPE_FIELD_END) 
                fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
              
              fprintf(fp,"OUT R%d\n",r1);
              free_reg();
              return 0;
		case NODETYPE_RET_PAIR:

		   printf("//oooopp\n");
                 r1=get_reg();     
             
                 printf("hello\n");
                    bind=root->ptr1->Lentry->binding;
                 printf(fp,"//hell00o\n");
               
                    r2=get_reg();
                    r3=get_reg();
                    fprintf(fp,"MOV R%d BP\n",r2);
                    fprintf(fp,"MOV R%d %d\n",r1,bind);
                    fprintf(fp,"ADD R%d R%d\n",r1,r2);
                    fprintf(fp,"MOV R%d %d\n",r3,2);
                	fprintf(fp,"SUB R%d R%d\n",r2,r3);
               		 fprintf(fp,"MOV [R%d] R%d\n",r2,r1);


                    free_reg();
                    free_reg();
                    free_reg();
                 printf("hello1\n");
                   
                 break;
         case NODETYPE_RET:
                r=code_gen(root->ptr1);
                if(root->ptr1->node==NODETYPE_FIELD_END)
                  fprintf(fp,"MOV R%d [R%d]\n",r,r);
                r1=get_reg();
                fprintf(fp,"MOV R%d BP\n",r1);
                r2=get_reg();
                fprintf(fp,"MOV R%d 2\n",r2);
                fprintf(fp,"SUB R%d R%d\n",r1,r2);
                free_reg();
                fprintf(fp,"MOV [R%d] R%d\n",r1,r);
                free_reg();
                free_reg();
                break;

        case NODETYPE_WHILE :
              l1=get_label();
              l2=get_label();
              fprintf(fp,"\n//while\n");
              fprintf(fp,"label%d:\n",l1);
              r1=code_gen(root->ptr1);              
              fprintf(fp,"JZ R%d,label%d\n",r1,l2);
              free_reg();
              code_gen(root->ptr2);
              fprintf(fp,"JMP label%d\n",l1);
              fprintf(fp,"\n\n");
              fprintf(fp,"label%d:\n",l2);
              break;
              
      case NODETYPE_IF :

              fprintf(fp,"\n\n//if\n");
              l1=get_label();
              r1=code_gen(root->ptr1);
              fprintf(fp,"JZ R%d label%d\n",r1,l1);
              free_reg();
              code_gen(root->ptr2);
              fprintf(fp,"label%d:\n",l1);
              break;

               
         case NODETYPE_IFELSE :
              fprintf(fp, "\n\n //ifelse\n\n");
              l1=get_label();
              l2=get_label();
              r1=code_gen(root->ptr1);

            
              fprintf(fp,"JZ R%d label%d\n",r1,l1);
              free_reg();
              code_gen(root->ptr2);

              fprintf(fp,"JMP label%d\n",l2);
              fprintf(fp,"label%d:\n",l1);

              code_gen(root->ptr3);
              fprintf(fp,"label%d:\n",l2);
              break;

        case NODETYPE_SLIST :
              code_gen(root->ptr1);
              code_gen(root->ptr2);
              break;
          
  }
}
         
      