#include "lex.h"


int isNumber(char c){//para ver si octiene un numero [0-9]

    if(c>='0' && c<='9')
    {
        return TRUE;
    }
    return FALSE;

}

int isLetter(char c){//para ver si esta entre [a-z A-Z]

    if((c>='A' && c<='Z') || (c>='a' && c<='z'))
    {
        return TRUE;
    }
    return FALSE;
}

int isalPhanum(char c){//para ver si [a-z A-Z 0-9]

    //if((c>='A' && c<='z') || (c>='0' && c<='9'))
    if(isNumber(c) || isLetter(c))
    {
        return TRUE;
    }
    return FALSE;

}
int isHex(char c){


    if(isNumber(c) || c>='A' && c<='F')
    {
        return TRUE;
    }
    return FALSE;
}
////////////////////////////////////////////////////////////////////////

int isInteger(FILE *pf){

    int k, Count=0;
    char c,*str;
    long int pos;
    pos = ftell(pf);
    c=fgetc(pf);
    if(isNumber(c)){
    do
    {
        Count ++;
        c = fgetc(pf);
    }while(isNumber(c));
        str = (char*)malloc(sizeof(char)*(Count+1));
        fseek(pf,pos,SEEK_SET);
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






token *is_number(FILE *fp)
{
      int k=0;
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
          
          if(isNumber(c))
          {
             state = A1; 
             count++;
          }
          else if(c=='.')
          {
               state =A2;
               count++;
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
              //t=(char*)malloc(sizeof(char)*(count+1)); //????????????
              t=tokenCreate();
              t->lexema=(char*)malloc(sizeof(char)*(count+1));
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);
                  t->id=ID_NUMBER;
                //t[k]=fgetc(fp);
              }
              t->lexema[count]='\0'; //la diagonal 0 de espacio  
              
           }
           else{
                fseek(fp,pos,SEEK_SET);
                return NULL;  
                } //O -1
           return t;
           //return atof(t);
           
           
   }//fin de funcion
                
      
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


//Funcion para detectar comentarios ( //, $ )
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
              printf("%d  ",t->id); //Solo imprimir identificador
              
              for(k=0; k<count; k++)
              {
                  t->lexema[k]=fgetc(fp);
                  printf("%c",t->lexema[k]); //Imprimir caracter a caracter del comentario                  
              }
              is_token=FALSE; 
              state=0;  
              
              t->lexema[count]='\n'; //la \n para fin de comentario             
           }
           else{
                //fseek(fp,pos,SEEK_SET);
                return NULL;  
                } //O -1
 
           return t;
}
