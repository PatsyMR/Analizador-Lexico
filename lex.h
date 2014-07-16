#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define A1 2
#define A2 3


#define ERROR -1

#define ID_NUMBER 1001
#define cadena 10002     //identificar cadenas
#define comentario 1000  //Identificador de comentarios


typedef struct toxen_tag
{
    char *lexema;
    int id;
}token;

int isNumber(char c);
int isLetter(char c);
int isalPhanum(char c);
int isHex(char c);
int isInteger(FILE *pf);

token *isComment(FILE *pf);  //Para comentarios
token *isString(FILE *fp);  //Para Cadenas

token *is_number(FILE *pf);
FILE* CrearArchivo(char filename[], char *tipo);

token *tokenCreate();
void tokenfree(token *t);
void tokenSetLex(token *t,char *lexema);
