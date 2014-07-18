#include "lex.h"
#define BUFLEN 30
   
int main(int argc, char *argv[])
{
     
     /////////////// PRUEBAS DE LO HECHO EN CLASE 
   /* char a = '\\';
    char b = 'a';
    char c = '!';
    char d = 'F';
    printf("%d \n",isLetter(a));
    printf("%d \n",isNumber(b));
    printf("%d \n",isalPhanum(c));
    printf("%d \n",isHex(d));   
    printf("%d \n",isInteger(fp));
    printf("%f \n",is_number(fp)); 
    */
    
    //Creacion del archivo de lectura
    char filename[15]="archivo.txt";
    FILE *fp=NULL;
    char buf[BUFLEN];    
    fp=CrearArchivo(filename,"r");  

   // token *t;  
   // t=is_number(fp);
    //printf("lexema %s\n",t->lexema); 
    //printf("lid %d\n",t->id); 
    
      
    token *t; //Creación del token que almacena resultados 

    
//////////////////////////////// PRUEBAS YULI
  //  printf("****** COMENTARIOS ******\n\n");
    while(!feof(fp))
    {
        t=isComment(fp); //Comentarios
       //t=isString(fp);  //Cadenas 
        //t=isOpe(fp);  
       //printf("\n"); 
    }
    fclose(fp);
/////////////////////////////// HASTA AQUI HAGO MIS PRUEBAS
      
  

 

 // printf("\n");

  system("PAUSE");	
  return 0;

}

