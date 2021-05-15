#include <stdbool.h>

#define vertice_ausente NULL
#define aresta_nula -1


typedef int Peso;


/*Arestas: */
typedef struct aux_aresta{
	int vertice_destino;
	Peso peso;
	struct aux_aresta* prox;
}Aux_Aresta, * Aresta;


/*Grafo: */
typedef struct{
	Aresta** listaAdj;
	int numVertices;
	int numArestas;
}Aux_Grafo, * Grafo;
