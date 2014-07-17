#include <stdio.h>
#include <stdlib.h>

#include "lex.h"
#define BUFLEN 30
   
int main(int argc, char *argv[])
{
     
   /* char a = '\\';
    char b = 'a';
    char c = '!';
    char d = 'F';
    printf("%d \n",isLetter(a));
    printf("%d \n",isNumber(b));
    printf("%d \n",isalPhanum(c));
    printf("%d \n",isHex(d));*/
    char filename[15]="archivo.txt";
    FILE *fp=NULL;
    char buf[BUFLEN];    
    fp=CrearArchivo(filename,"r");  
    
    token *t;  
   // t=is_number(fp);
    //printf("lexema %s\n",t->lexema); 
    //printf("lid %d\n",t->id); 
    
    ///////////////
     while(!feof(fp))
    {
        t=isOpe(fp);  
        printf("\n");         
    }
    fclose(fp);
   //////// 
    
    
    //printf("%d \n",isInteger(fp));
   // printf("%f \n",is_number(fp)); 
  
 
  system("PAUSE");	
  return 0;

}
