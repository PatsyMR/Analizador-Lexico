#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define A1 2
#define A2 3
#define ERROR -1


#define ID_COMMENT 1003 //IDENTIFICADOR DE COMENTARIO
#define ID_STRING 1004  //IDENTIFICADOR DE CADENA
#define ID_NUMBER_FLO 1005 //IDENTIFICADOR DE NUMERO FLOTANTE
#define ID_NUMBER_INT 1006 //IDENTIFICADOR DE NUMERO ENTERO
#define ID_OPE 1007 // //IDENTIFICADOR DE OPERADORES ARITMETICOS
#define ID_OPERAGRU 1008 // //IDENTIFICADOR DE OPERADORES DE AGRUPACION
#define ID_KEYWORD 1009 ////IDENTIFICADOR DE PALABRA RESERVADA
#define ID_IDENTIFICATOR 1010 // //IDENTIFICADOR DE IDENTIFICADORES
#define ID_OPEREL 1011 //IDENTIFICADOR DE OPERADORES RELACIONALES
#define ID_UKNOWN 1012 //IDENTIFICADOR DE DESCONOCIDO

typedef struct toxen_tag
{
    char *lexema;
    int id;
}token;

int isNumber(char c);
int isLetter(char c);
FILE* CrearArchivo(char filename[], char *tipo);
token *tokenCreate();
token *isComment(FILE *pf);//Comentarios   
token *isString(FILE *fp); //Cadenas
token *isOpe(FILE *fp);  //Detecta Operadores aritmeticos
token *isOpeagru(FILE *fp); //operadores de agrupación
token *isIntFloat(FILE *pf); //Detecta Enteros y Flotantes
token *isUknown(FILE *fp); //Detecta lo desconocido
token *keyWordOIdentificator(FILE *fp); //Detecta palabras reservadas e identificadores
token *isOperel(FILE *fp);//operadores relacionales
void guardarDiccionario(char * nombre); //archivo donde se extraen las palabras reservadas del archivo de texto
token *analizadorLexico(FILE *fp);

/*int isLetter(char c);
int isalPhanum(char c);
int isHex(char c);
int isInteger(FILE *pf);
token *is_number(FILE *pf);
void tokenfree(token *t);
void tokenSetLex(token *t,char *lexema);
*/


