#include"listaChar.h"

int listaVacia(Lista lista)
{
	return (lista == NULL);
}

void insertar(Lista *lista, tipoDato * v, char * tagInicio, char *tagFinal)
                        {

				
					
                        pNodo nuevo, anterior, ultimo;
                        nuevo = (pNodo)malloc(sizeof(tipoNodo));
						nuevo->valor=(char*)malloc(sizeof(char)*512);
						strcpy(nuevo->valor,v);
						strcpy(nuevo->tagInicio,tagInicio);
						strcpy(nuevo->tagFinal,tagFinal);
					   
					
					
                        if(listaVacia(*lista) ) 
						{
								/* Añadimos la lista a continuación del nuevo nodo */
								nuevo->siguiente = *lista;
								/* Ahora, el comienzo de nuestra lista es en nuevo nodo */
								*lista = nuevo;
								//printf("*%s\n", nuevo->valor);
								ultimo=nuevo;//guardar el pimer elemento
							    //printf("\njjjjj  %s\n", ultimo->valor);
						}

						 else 
					   {
								/* Buscar el nodo de valor menor a v */
								anterior = *lista;
								/* Avanzamos hasta el último elemento o hasta que el
								siguiente tenga un valor mayor que v */
								while(anterior->siguiente )
								anterior = anterior->siguiente;
								/* Insertamos el nuevo nodo después del nodo anterior */
								nuevo->siguiente = anterior->siguiente;
								anterior->siguiente = nuevo;
								//printf("*%s\n", nuevo->valor);
                        }
	                  
}


void mostrarLista(Lista lista)
{
            pNodo nodo = lista;
			
            if(listaVacia(nodo)) printf("Lista vacía\n");
            
			else 
			{
				
				printf("\n\nPalabras dentro de:\t %s y %s  \n", nodo->tagInicio, nodo->tagFinal);
					while(nodo) 
					{
						printf("%s, ", nodo->valor);
						nodo = nodo->siguiente;
						printf("\n");
					}
					
            }
}

int Busqueda(Lista *lista, tipoDato *h)
{
     pNodo indice;
	
	 int contador=0;
	 int i;
	
	
	if(lista==NULL)
    {
			printf("lista vacia\n");
	}
        
	else
         {   
                      
                        indice= *lista;
						 printf("%s \t %s\n",indice->valor, h);
					    i= strcmp(indice->valor, h);
						
					
                  do{
                   
							  if(i==0)
							  {
								   printf("%s\n",indice->valor);
								   contador++; 
								   return contador;
							   }
							
							  else
							  {
							   indice=indice->siguiente; 
							  }
										  
                   }while(indice!=NULL); 
        
        }   
       return 0; 

}