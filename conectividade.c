#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int visited[100];


int main(){
	
	int num_vertices = 7;
	int num_arestas = 8;
	
	for(int i=0; i<num_vertices; i++){
		visited[i] = 0;
	}
	
	Grafo* g1 = iniciaGrafo(num_vertices, num_arestas);
	adjacencia(g1, 5, 6, 1);
	adjacencia(g1, 0, 2, 1);
	adjacencia(g1, 0, 1, 4);
	adjacencia(g1, 3, 5, 7);	
	adjacencia(g1, 3, 4, 1);
	adjacencia(g1, 1, 3, 1);
	adjacencia(g1, 2, 3, 1);
	adjacencia(g1, 4, 6, 1);

	printf("\n %d %d \n", g1->numVertice, g1->numAresta);
	exibe(g1);
	
	BP(g1, 0);
	
	
    return 0;
	
}

void BP(Grafo* g, int inicio){
	int j;
	printf(" %d-> ", inicio);
	visited[inicio] = 1;
	
	for(j=0; j<g->numVertice; j++){
		if(!visited[j]&&g->matrix[inicio][j]!=-1){
			BP(g, j);
		}
	}
}
