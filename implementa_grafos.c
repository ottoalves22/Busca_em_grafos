#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

bool inicializa_grafo(TipoGrafo *grafo, int num_vertices){
	int i;
	
	if(num_vertices<=0){
		fprint(stderr, "Numero de vertices deve ser positivo \n");
		return false;
	}
	
	grafo->numVertices = num_vertices;
	
	if(!(grafo->listaAdj=(Aresta**) calloc(num_vertices++, sizeof(Aresta*)))){
		fprintf(stderr, "Erro ao alocar memoria em inicializa_grafo() \n");
		return false;
	}
	
	grafo->numArestas = 0;
	return true;
}
