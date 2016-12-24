void createType(char *name) {
	struct Typetable *temp=getType(name);
	if(temp==NULL)
		temp=(struct Typetable *)malloc(sizeof(struct Typetable));
	else {
		printf("Error:User defined type %s \n is already declared\n",name);
		exit(1);
	}
    temp->name=(char *)malloc(16);
    strcpy(temp->name,name);
    temp->fields=NULL;
    temp->next=NULL;
    if(typeHead) 
    	temp->next=typeHead;
    typeHead=temp;
}


void createField(char *typename,char *name) {
	struct Fieldlist *temp=(struct Fieldlist * )malloc(sizeof(struct Fieldlist));
	struct Typetable *t=getType(typename);
	if(t==NULL) {
		printf("Error:Reference to an undeclared type %s\n",typename);
		exit(1);
	}
	temp->type=t;
	temp->field_num=field_num;

	field_num++;
	temp->name=(char *)malloc(16);
	strcpy(temp->name,name);
	temp->next=NULL;
	if(fieldHead) {
		temp->next=fieldHead;
	}
	fieldHead=temp;
}

struct Fieldlist * IsField(struct Typetable *t,char *name) {
    struct Fieldlist *temp=t->fields;
    while(temp) {
    	if(strcmp(temp->name,name)==0) {
    	
    		return temp;
    	}
    	temp=temp->next;
    }
    printf("Error:There is field_num variable %s in type %s\n",name,t->name);
    exit(1);
}

struct Typetable * getType(char *name) {
	struct Typetable *t=typeHead;
	while(t) {
		if(strcmp(t->name,name)==0) {
			return t;
		}
		t=t->next;
	}
	return t;
}

void reset_field_data()
{
	field_num=1;
	fieldHead=NULL;
}



	void GInstall(char *name,struct Typetable  *type,int size,struct ArgStruct *arglist) {
		struct Gsymbol *check=GLookup(name);
		if(check) {
			printf("Error: variable %s  redeclared \n",name);
			exit(1);
		}
		struct Gsymbol *temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
			temp->name=malloc(16);
		strcpy(temp->name,name);
		if(size==0) {
			temp->size=0;
			temp->binding=fbinding++;
		}
		else if(strcmp(type->name,"integer")==0 || strcmp(type->name,"boolean")==0) {
	 		
	 		temp->size=size;
	 		temp->binding=gbinding;
	 		gbinding=gbinding+size;
		}
		else if(strcmp(type->name,"pair")==0)
		{
			temp->size=size;
			temp->binding=gbinding;
			gbinding=gbinding+2;

		}
		else {
			temp->size=16*size;
			temp->binding=gbinding;
	 		gbinding=gbinding+size;
		}

		temp->arglist=arglist;
		temp->type=type;
		temp->next=NULL;
		if(GSymbolHead) {
			temp->next=GSymbolHead;
		
		}
			GSymbolHead=temp;
		
	}


struct Gsymbol* GLookup(char *name) {
	struct Gsymbol *temp=GSymbolHead;
	while(temp) {
		if(strcmp(temp->name,name)==0) {
	
			return temp;
		}
		temp=temp->next;
	}
	return temp;
}



struct Lsymbol * LInstall(char *name,struct Typetable *type,int ref) {
	    struct Lsymbol *temp=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	    if(LLookup(name)) {
	    	printf("Redefined Variable ------%s \n ",name);
	    	exit(1);
	    };
        temp->name=(char *)malloc(16);
	   	strcpy(temp->name,name);
	   	temp->ref=ref;
	    if( strcmp(type->name,"pair")==0)
	    {
	    	if(ref=0)
	    	{
	    		temp->binding=localbind;
	    		localbind=localbind+2;
	    	}
	    	else if(ref=1)
	    	{
	    		temp->binding=argbind;
	    		argbind=argbind-1;
	    	
	    	}
	    }

		if(ref)
		   		temp->binding=argbind--;
		else
				temp->binding=localbind++;
		temp->type=type;
		if(strcmp(type->name,"integer")==0 || strcmp(type->name,"boolean")==0)
			temp->size=1;
		else
			temp->size=16;
		
		temp->next=NULL;

		if(LSymbolHead) {
			temp->next=LSymbolHead;
	    }
	    LSymbolHead=temp;
}





struct Lsymbol* LLookup(char *name) {
	struct Lsymbol *temp=LSymbolHead;
	while(temp) {
		if(strcmp(temp->name,name)==0) {			
			return temp;
		}
		temp=temp->next;
	}
	return temp;
}


struct ArgStruct * Arginstall (char *name,struct Typetable *type,int passtype) {
        struct ArgStruct *temp=(struct ArgStruct *)malloc(sizeof(struct ArgStruct));
        temp->name=(char *)malloc(16);
       
        strcpy(temp->name,name);
        temp->type=type;
        temp->passType=passtype;
        temp->next=NULL;
       
        		
        
        	if(passtype==2) 
        	
        		LInstall(name,type,2);
        	
        	else 

        		LInstall(name,type,1);
        	
        
       
        return temp;
}


void Reinitialise(){   
	struct Lsymbol *temp=LSymbolHead;
	if(LSymbolHead) {
		temp=LSymbolHead->next;
	}

	while(LSymbolHead) {
	
		free(LSymbolHead->name);
		free(LSymbolHead);
		LSymbolHead=temp;
        if(LSymbolHead)
        	temp=temp->next;
	}

    LSymbolHead=NULL;
	localbind = 1;
	argbind = -3;
}

