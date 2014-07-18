#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define A1 2
#define A2 3


#define ERROR -1



#define ID_OPE 1003

#define ID_COMMENTT 1001
    //identificar cadenas
#define ID_NUMBER 1000  //Identificador de comentarios
#define ID_STRING 1002


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


token *isOpe(FILE *fp);
