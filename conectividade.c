#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int main(){
	int num_vertices = 3;
	int num_arestas = 3;
	
	Grafo* g1 = iniciaGrafo(num_vertices, num_arestas);
	adjacencia(g1, 0, 0, 0);
	adjacencia(g1, 1, 2, 1);
	adjacencia(g1, 2, 1, 1);
	printf("\n %d %d \n", g1->numVertice, g1->numAresta);
	exibe(g1);
	
	
    return 0;
	
	
}
