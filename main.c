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
    
<<<<<<< HEAD
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
    
=======
    token *t; //Creación del token que almacena resultados 
>>>>>>> d319683e6dec3900f488c132a1636d90cbdcb343
    
//////////////////////////////// PRUEBAS YULI
  //  printf("****** COMENTARIOS ******\n\n");
    while(!feof(fp))
    {
        t=isComment(fp); //Comentarios
       // t=isString(fp);  //Cadenas  
    }
    fclose(fp);
/////////////////////////////// HASTA AQUI HAGO MIS PRUEBAS
      
  
<<<<<<< HEAD
 
=======
  printf("\n");
>>>>>>> d319683e6dec3900f488c132a1636d90cbdcb343
  system("PAUSE");	
  return 0;

}
