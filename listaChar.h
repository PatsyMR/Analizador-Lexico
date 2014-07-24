#include<string.h>
#include<stdio.h>
#include<stdlib.h>


typedef char tipoDato;


typedef struct nodoEtiqueta
{
		
		struct nodoEtiqueta * siguiente;
		int tamano;
		tipoDato * valor;
		char tagInicio[10];
		char tagFinal [10];
		
}tipoNodo;


typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

int listaVacia(Lista lista);
void insertar(Lista *lista, tipoDato * v,  char * tagInicio, char *tagFinal);
void mostrarLista(Lista lista);
int Busqueda(Lista *lista, tipoDato *h);
