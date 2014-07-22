#include "lex.h"

#define BUFLEN 30
   
int main(int argc, char *argv[])
{
        //Creacion del archivo de lectura
    char filename[15]="archivo2.txt";
    FILE *fp=NULL;
    char buf[BUFLEN];    
    fp=CrearArchivo(filename,"r");  
    
    token *t; //Creación del token que almacena resultados     
    
    while(!feof(fp)){
//Aqui identificador
//Aqui reservada 
       if(t=isComment(fp)){
         printf("\n%d Comentario --> %s",t->id,t->lexema);        
            }
       else if(t=isString(fp)){
         printf("\n%d Cadena --> %s",t->id,t->lexema);        
            }
       else if(t=isIntFloat(fp)){  
             if(t->id==ID_NUMBER_FLO)                         
              printf("\n%d Flotante --> %s",t->id,t->lexema);
             else
              printf("\n%d Entero --> %s",t->id,t->lexema);
         }
       else if(t=isOpe(fp)){
         printf("\n%d Operdor --> %s",t->id,t->lexema);       
            }
       else{  //FALTA Q IMPRIMA LOS \n
         t=isUknown(fp);
         printf("\n%d Desconocido --> %s",t->id,t->lexema);    
            }
     
//operadores logicos
//operadores agrupacion          
//Sin clasificacion
           }
    rewind(fp);
    
    
    
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
        
   //////////////////////////////// segundas PRUEBAS 
  /*  printf("****** COMENTARIOS ******\n\n");
    while(!feof(fp))
        t=isComment(fp);  
    rewind(fp); //Regresar al inicio del archivo
    
    printf("\n\n****** CADENAS ******\n\n");
    while(!feof(fp))
      t=isString(fp);       
    rewind(fp);
     
    printf("\n\n****** OPERADORES ******\n\n"); 
    while(!feof(fp))
       t=isOpe(fp);
    rewind(fp); 
    */
  
  printf("\n");
  system("PAUSE");	
  return 0; 

}
