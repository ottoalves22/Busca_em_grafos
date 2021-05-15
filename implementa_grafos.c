#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo inicializa_grafo(int num_vertices){
	int i;
	Grafo grafo = malloc(sizeof(Grafo));
	
	if(num_vertices<=0){
		fprintf(stderr, "Numero de vertices deve ser positivo \n");
		return NULL;
	}
	
	grafo->numVertices = num_vertices;
	
	if(!(grafo->listaAdj=(Aresta**) calloc(num_vertices++, sizeof(Aresta*)))){
		fprintf(stderr, "Erro ao alocar memoria em inicializa_grafo() \n");
		return NULL;
	}
	
	grafo->numArestas = 0;
	return grafo;
}
