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
    
    while(!feof(fp)){ 
       if(t=isComment(fp)){
         printf("\n Comentario --> %d %s",t->id,t->lexema);        
            }
       else if(t=isString(fp)){
         printf("\n Cadena --> %d %s",t->id,t->lexema);        
            }
//Aqui identificador
//Aqui reservada
       else if(t=isIntFloat(fp)){  
             if(t->id==ID_NUMBER_FLO)                         
              printf("\n Flotante --> %d %s",t->id,t->lexema);
             else
              printf("\n Entero --> %d %s",t->id,t->lexema);
         }
       else if(t=isOpe(fp)){
         printf("\n Operador aritmetico--> %d %s",t->id,t->lexema);       
            }
//operadores logicos
       else if(t=isOpeagru(fp)){
         printf("\n Operador de agrupacion --> %d %s",t->id,t->lexema);       
            } 
       else if(t=isPalabra(fp)){   //Esta va hasta arriba
         printf("\n%d Palabra --> %s",t->id,t->lexema); 
            }    
       else if(t=isUknown(fp)){
        // t=isUknown(fp);
         printf("\n Desconocido --> %d %s",t->id,t->lexema);    
            }

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

  printf("\n");
  system("PAUSE");	
  return 0; 

}