#include <stdbool.h>

#define vertice_ausente NULL
#define aresta_nula -1


typedef int Peso;


/*Arestas: */
typedef struct str_aresta{
	int vertice_destino;
	Peso peso;
	struct aux_aresta* prox;
}Aresta;


/*Grafo: */
typedef struct{
	Aresta** listaAdj;
	int numVertices;
	int numArestas;
}Grafo;
