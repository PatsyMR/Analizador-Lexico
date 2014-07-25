#include "lex.h"
#include "listaChar.h"

#define BUFLEN 30
   
int main(int argc, char *argv[])
{

	//archivo de palabras reservadas 
	guardarDiccionario("ArchivoReservadas.txt");
	
	//Creacion del archivo de lectura
    char filename[15]="archivo.txt";
    FILE *fp=NULL;
    char buf[BUFLEN];    
    fp=CrearArchivo(filename,"r");
	token *t; //Creación del token que almacena resultados   
	
	while(!feof(fp))
	{
		t=analizadorLexico(fp);
		printf("%s -> %d\n",t->lexema, t->id);
	}
    
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

  printf("\n");
  system("PAUSE");	
  return 0; 

}