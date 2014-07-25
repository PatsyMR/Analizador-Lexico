#include "lex.h"
#include "listaChar.h"
Lista listaDiccionarioAux= NULL;
Lista listaDiccionario = NULL;

//Checa que si la palabra es Reservada o identificador
token *keyWordOIdentificator(FILE *fp)
{
      int k=0;
      int flot = 0;
      token *t=0;
      //char *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      listaDiccionarioAux=listaDiccionario;
      do{
          switch(state)
          {          
          case 0:
          c=fgetc(fp);
          
          if(isLetter(c))
          {
             state = A1;
             count++;
          }
           else
           {
               state=ERROR;
           }
           break;
           
           case A1:
           c=fgetc(fp);
          
          if(isNumber(c)  || isLetter(c)) //?????????????????????????
          {
             state = A1;
             count++;
          }         
           else
           {
               state=ERROR;
               is_token=TRUE;
           }
           break;           
         }
         }while(state != ERROR);          


if(is_token)
{
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
			int banderaIndentificador=0;
			
			
                       for(k=0; k<count; k++)
						  {
							  t->lexema[k]=fgetc(fp);               
						  }
						  is_token=FALSE; 
						  flot=0;
						  state=0; 
						t->lexema[count]='\0'; //la \n para fin de comentario
								
//char *cade;
//cade=(char*)malloc(sizeof(char)*10);
//strcpy(cade,t->lexema);
						
//printf("%d %d\n",strlen(t->lexema),strlen(listaDiccionario->valor) );
//printf("%s %s",cade,listaDiccionario->valor );	

				while(!listaVacia(listaDiccionario) )
						{			
				
							if(strcmp(listaDiccionario->valor,t->lexema)==0)
							  {
											   
											  t->id=ID_KEYWORD; 
											  listaDiccionario=listaDiccionarioAux;
											  banderaIndentificador=1;											  
											  return t;							  
											  
										  
							  
							  }
				
							 else if(!listaVacia(listaDiccionario))
							{
								listaDiccionario=listaDiccionario->siguiente;
							}
							 
						}	



						if(banderaIndentificador==0)
						{
						listaDiccionario=listaDiccionarioAux;
						 t->id=ID_IDENTIFICATOR;
						}
}//if
	
else
{
	  fseek(fp,pos,SEEK_SET);
                return NULL;
}
           return t;           
}//fin de funcion

//Operador Relacional
token *isOperel(FILE *fp)
{
      int k=0;
      token *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      
      do{
          switch(state)
          {          
 case 0:
          c=fgetc(fp);

          if (c== '<' || c== '>'){
             state = A1;
             count++;
             }

         else if(c== '!' || '=')       
           {               
             state = 1;
             count++;
           }
           
  case A1: ////igual 1
      c=fgetc(fp);
        if (c == '=')
           {               
             state = A2;
             count++;
           }
        else
           {
             state=ERROR;
             is_token=TRUE;
           }
        break;

   case 1:
               c=fgetc(fp);
               if (c == '=')
           {               
             state = A2;
             count++;
           }
            else{
             state=ERROR;
             } // printf("token true\n\n");
           
           break;
         
    case A2:
               state=ERROR; // printf("token true\n\n");
               is_token=TRUE;
              break;          
          }
          
     }while(state != ERROR);      
           
           
           if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              t->id = ID_OPEREL;  
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);                 
              }
              is_token=FALSE; 
              state=0;             
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
 
           return t;
    
}


//para ver si esta entre [a-z A-Z]
int isLetter(char c)
{
    if((c>='A' && c<='Z') || (c>='a' && c<='z'))
    {
        return TRUE;
    }
    return FALSE;
}



////////********Detecta cadenas*************/////////////
token *isString(FILE *fp){
      int k=0;
      token *t=NULL;
      char c=0;
      int state =0, is_token=FALSE, count=0;
      long int pos;
      pos = ftell(fp);
     
      do{
          switch(state)
          {          
     case 0:
          c=fgetc(fp);
          
          if(c == '"') 
          {
             state = 1; 
             count++;
          }
           else
           {
               state=ERROR; 
           }
           break;
   
      case 1:
          c=fgetc(fp);          
          if(c != '"')
          {
             state = 1; 
             count++;
          }
           else
          {
               state =A1; 
               count++;
           }
           break;
     
                
      case A1:
               state=ERROR; 
               is_token=TRUE;
           break;     
         
          }//Fin switch
      }while(state != ERROR);      
           
           
           if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              t->id = ID_STRING;  
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);               
              }
              is_token=FALSE; 
              state=0;  
              
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
 
           return t;
    
}



/////////****Detecta comentarios definidos por ("", $)****/////////////
token *isComment(FILE *fp){
      int k=0;
      token *t=NULL;
      char c=0;
      int state =0, is_token=FALSE, count=0;
      long int pos;
      pos = ftell(fp);
     
      do{
          switch(state)
          {          
     case 0:
          c=fgetc(fp);
          
          if(c == '/') 
          {
             state = 1; //printf("%c, ",c);
             count++;
          }
          else if(c=='$')
          {
               state = A1; // printf("%c, ",c);
               count++;
           }
           else
           {
               state=ERROR; // printf("Error");
           }
           break;
           
      case 1:
          c=fgetc(fp);          
          if(c == '/')
          {
             state = A1; // printf("%c, ",c);
             count++;
          }         
           else
           {
               state=ERROR; // printf("Error");
           }
           break;
           
     
      case A1:
          c=fgetc(fp);          
          if(c != '\n')
          {
             state = A1; // printf("%c, ",c);
             count++;
          }
           else
          {
               state =A2; // printf("%c, ",c);
               count++;
           }
           break;
     
                
      case A2:
               state=ERROR; // printf("token true\n\n");
               is_token=TRUE;
           break;     
         
          }//Fin switch
      }while(state != ERROR);      
           
           
           if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));             
              t->id = ID_COMMENT;  
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);                 
              }
              is_token=FALSE; 
              state=0;             
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
 
           return t;    
}



///////**********Checa que sea número Entero o Flotante*********////////
token *isIntFloat(FILE *fp)
{
      int k=0;
      int flot = 0;
      token *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      
      do{
          switch(state)
          {          
          case 0:
          c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A1;
             count++;
          }
          else if(c=='+' || c=='-')
          {
               state =1;
               count++;
           }
           else
           {
               state=ERROR;
           }
           break;
           
           case 1:
           c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A1;
             count++;
          }         
           else
           {
               state=ERROR;
           }
           break;           
                
           case A1:
           c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A1; 
             count++;
          }
          else if(c=='.')
          {
               state =A2;
               count++;
               flot = 1; //Bandera para identificar q es número flotante
           }
           else
           {
               state=ERROR;
               is_token=TRUE;
           }
           break;             
           
         case A2:    //es igual que un caso 3
           c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A2;
             count++;
          }
           else
           {
               state=ERROR;
               is_token=TRUE;
           }
           break;
          
          }
         }while(state != ERROR);          


            if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              if(flot==1)
              t->id=ID_NUMBER_FLO; 
              else
              t->id=ID_NUMBER_INT; 
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);               
              }
              is_token=FALSE; 
              flot=0;
              state=0;  
              
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET); 
                return NULL;  
                } 
                 
           return t;           
}


///////////*****Detecta Operadores aritméticos******/////////////
token *isOpe(FILE *fp)
{
      int k=0;
      token *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      
      do{
          switch(state)
          {          
 case 0:
          c=fgetc(fp);
          
    if(c=='+' )
           //if(c>='a' && c<='h' || c>='j' && c<='z')
         {
             state = A1;
             count++;
         }
    else if (c=='*')
           {              
             state = A1;
             count++;
           }
    else if (c=='-')
           {               
             state = A1;
             count++;
           }

   else if (c=='/')
           {               
             state = A1;
             count++;
           }

   else if (c=='%')
           {               
             state = A1;
             count++;
           }

   else
           {
               state=ERROR; // printf("Error");
           }

           break;
           
  case A1:
               state=ERROR; // printf("token true\n\n");
               is_token=TRUE;
           break;
                    
          }
          }while(state != ERROR);      
           
           
           if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              t->id = ID_OPE;  
    
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);                
              }
              is_token=FALSE; 
              state=0;  
              
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
 
           return t;    
}


///////////*****Detecta Operadores de agrupacion******/////////////
token *isOpeagru(FILE *fp)
{
      int k=0;
      token *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      
      do{
          switch(state)
          {          
 case 0:
          c=fgetc(fp);
          
    if(c=='(' )
          
         {
             state = A1;
             count++;
         }
    else if (c=='{')
           {              
             state = A1;
             count++;
           }
    else if (c=='[')
           {               
             state = A1;
             count++;
           }
    else if (c==')')
           {               
             state = A1;
             count++;
           }
   else if (c=='}')
           {               
             state = A1;
             count++;
           }
  else if (c==']')
           {               
             state = A1;
             count++;
           }         
                   
  else
           {
               state=ERROR; // printf("Error");
           }

           break;
           
 
  case A1:
               state=ERROR; // printf("token true\n\n");
               is_token=TRUE;
           break;
                    
          }
          }while(state != ERROR);      
           
           
           if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              t->id = 1008;  
    
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);                
              }
              is_token=FALSE; 
              state=0;  
              
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
 
           return t;    
}



//Clasifica el tpken como desconocido(no entra en ninguna otra clasificacion)
token *isUknown(FILE *fp){
      int k=0;
      token *t=NULL;
      char c=0;
      int state =0, is_token=FALSE, count=1;
      long int pos;
      pos = ftell(fp);
      
      c=fgetc(fp);

          if(c != '\n' && c!=32){
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
                  t->id = ID_UKNOWN;               
                  t->lexema[0]=fgetc(fp);                           
              t->lexema[1]='\0'; //la \n para fin de comentario                        
           }           
           else
           {
             //  fseek(fp,pos,SEEK_SET);
               return NULL;
           }  
           return t;  
}


int isNumber(char c){//para ver si octiene un numero [0-9]

    if(c>='0' && c<='9')
    {
        return TRUE;
    }
    return FALSE;

}

      
FILE* CrearArchivo(char filename[], char *tipo)
{
      FILE *fp;
      if((fp=fopen(filename,tipo))==NULL)
      {
         fprintf(stderr,"Error opening file.");
         exit(1);
      }      
     
     return fp;      
 }



token *tokenCreate()
{
       token *retVal;
       retVal = (token*)malloc(sizeof(token));
       retVal->lexema = NULL;
       retVal->id=0;

       return retVal;      
}





//funcion que abre el archivo de palabras reservadas 
void guardarDiccionario(char * nombre)
{

FILE *archivo;
 
	
 	char caracteres[512];
	char *str;
	str=(char*)malloc(sizeof(char)*512);
 	char lim[4] = " \n\t";
	
	
 	if (archivo == NULL)
 		exit(1);
 
 	printf("\nEl contenido del archivo de prueba es \n\n");
 	
archivo = fopen(nombre,"r");
 		
					while (!feof(archivo))
					{
						if(archivo!='\0')
						{
							
								fgets(caracteres,512,archivo);
								//printf("%s\n",caracteres);
								str=strtok(caracteres,lim);
								
								while(str !=NULL)
								{
								//printf(">>>%s\n",str);
								insertar(&listaDiccionario,str," "," ");
								str = strtok(NULL, lim);								
								}					
								
						}		
					}
					
						fclose(archivo);
						
						//mostrarLista(listaDiccionario);
							
		
}



token *analizadorLexico(FILE *fp)
{
    token *t;
	
    while(!feof(fp))
	{ 
						if(t=keyWordOIdentificator(fp))
						{   
							if(t->id==ID_KEYWORD)
								{
										//printf("\n Palabra Reservada %d --> %s\n",t->id,t->lexema);
									printf("\n Palabra Reservada\n");
										return t;
								}
							else
								{ 
									//printf("\n Indetificador %d--> %s\n",t->id,t->lexema);
									printf("\n Identificador\n");
									return t;
								}
						} 
					   else if(t=isComment(fp))
					   {
							//printf("\n Comentario --> %d %s\n",t->id,t->lexema);
						    printf("\nComentario\n");
							return t;						   
					   }
					   else if(t=isString(fp))
					   {
							//printf("\n Cadena --> %d %s\n",t->id,t->lexema);
						    printf("\n Cadena\n");
							return t;
					   }
					   else if(t=isIntFloat(fp))
					   {  
							if(t->id==ID_NUMBER_FLO)
							{
								//printf("\n Flotante --> %d %s\n",t->id,t->lexema);
								printf(" \nFlotante\n");
								return t;
							}							
							else
							{
								printf("\n Entero\n");
								//printf("\n Entero --> %d %s\n",t->id,t->lexema);
								return t;
							}
					   }
					   else if(t=isOpe(fp))
					   {
							//printf("\n Operador aritmetico--> %d %s\n",t->id,t->lexema);
							printf("\nOperador aritmetico\n");						   
							return t;
					   }
					  //operadores logicos
					   else if(t=isOpeagru(fp))
					   {
							//printf("\n Operador de agrupacion --> %d %s\n",t->id,t->lexema);
							printf("\nOperador de agrupacion\n");
						    return t;
					   } 
					   //Palabras Reservadas e Idetificadores
					   
					else if(t=isUknown(fp))
					{
						  //printf("\n Desconocido --> %d %s\n",t->id,t->lexema);
						    printf("\nDesconocido\n");
							return t;
					}

	}
    
     return ERROR;
    }


////////////////////////////////////// NO SE NECESITAN 
/*
void tokenfree(token *t)
{
     if(t->lexema != NULL);
     free(t->lexema);
     t->id=0;     
}


void tokenSetLex(token *t,char *lexema)
{
     int k;
     int l = strlen(lexema);
     t->lexema=(char*)malloc(sizeof(char)*(l+1));
     
     for(k=0; k<l; k++)
     {
        t->lexema[k]=lexema[k];
     }     
        t->lexema[l]='\0';
}
*/




/*

//Detecta numeros Enteros
token *isInteger(FILE *pf){

    int k, count=0, is_token=FALSE, state =0;
    char c,*str;
    long int pos;
    pos = ftell(pf);
    token *t=0;
    
    c=fgetc(pf);
    if(isNumber(c)){
    do
    {
        count ++;
        c = fgetc(pf);
        is_token=TRUE;
     }while(isNumber(c));
        str = (char*)malloc(sizeof(char)*(count+1));
       // fseek(pf,pos,SEEK_SET);
        for(k=0;k<Count;k++)
        {
            str[k]=fgetc(pf);
        }
        str[k]='\0';

    return atoi(str);
    }
    else
        return 0;       
}


int isalPhanum(char c) //para ver si [a-z A-Z 0-9]
{
    //if((c>='A' && c<='z') || (c>='0' && c<='9'))
    if(isNumber(c) || isLetter(c))
    {
        return TRUE;
    }
    return FALSE;
}


int isHex(char c)
{
    if(isNumber(c) || c>='A' && c<='F')
    {
        return TRUE;
    }
    return FALSE;
}


int isLetter(char c)//para ver si esta entre [a-z A-Z]
{
    if((c>='A' && c<='Z') || (c>='a' && c<='z'))
    {
        return TRUE;
    }
    return FALSE;
}


//Checa que sea número (0 - 9)
token *isInteger(FILE *fp)
{
      int k=0;
      int flot = 0;
      token *t=0;
      //char *t=0;
      char c;
      int state =0, is_token=FALSE,count=0;
      long int pos;
      pos = ftell(fp);
      
      do{
          switch(state)
          {          
          case 0:
          c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A1;
             count++;
          }
          else if(c=='+' || c=='-')
          {
               state =1;
               count++;
           }
           else
           {
               state=ERROR;
           }
           break;
           
           case 1:
           c=fgetc(fp);
          
          if(isNumber(c))
          {
             state = A1;
             count++;
          }         
           else
           {
               state=ERROR;
           }
           break;           
                
           case A1:
           c=fgetc(fp);
          // t->id=ID_NUMBER_INT;
          
          if(isNumber(c))
          {
             state = A1; 
             count++;
          }
          else if(c=='.')
          {
               state =A2;
               count++;
               flot = 1; //Bandera para identificar q es número flotante
           }
           else
           {
               state=ERROR;
               is_token=TRUE;
           }
           break;             
           
         case A2:    //es igual que un caso 3
           c=fgetc(fp);
         //  t->id=ID_NUMBER_FLO;
          
          if(isNumber(c))
          {
             state = A2;
             count++;
          }
           else
           {
               state=ERROR;
               is_token=TRUE;
           }
           break;
          
          }
         }while(state != ERROR);          


            if(is_token)
           {
              fseek(fp,pos,SEEK_SET);
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              if(flot==1)
              t->id=ID_NUMBER_FLO; 
              else
              t->id=ID_NUMBER_INT; 
          //    printf("%d  ",t->id); //Solo imprimir identificador
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);
          //        printf("%c",t->lexema[k]); //Imprimir caracter a caracter del comentario                  
              }
          //    printf("\n");
              is_token=FALSE; 
              flot=0;
              state=0;  
              
              t->lexema[count]='\0'; //la \n para fin de comentario             
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } 
                 
           return t;           
}//fin de funcion

*/