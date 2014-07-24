#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define A1 2
#define A2 3
#define ERROR -1

//id_identificador
//id_reservadas
//#define ID_PALABRA 1011 //Se va poder omitr
#define ID_PALABRA 1011 //Se va poder omitr

#define ID_COMMENT 1003
#define ID_STRING 1004
#define ID_NUMBER_FLO 1005
#define ID_NUMBER_INT 1006
#define ID_OPE 1007
#define ID_OPERAGRU 1008 // operador_agrupacion
#define ID_KEYWORD 1009 //PALABRA RESERVADA
#define ID_IDENTIFICATOR 1010 // IDENTIFICADORES
//id_operadorLogico
#define ID_UKNOWN 1010

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
token *isUknown(FILE *fp);
token *isPalabra(FILE *fp);
void guardarDiccionario(char * nombre);


/*int isLetter(char c);
int isalPhanum(char c);
int isHex(char c);
int isInteger(FILE *pf);
token *is_number(FILE *pf);
void tokenfree(token *t);
void tokenSetLex(token *t,char *lexema);
*/



