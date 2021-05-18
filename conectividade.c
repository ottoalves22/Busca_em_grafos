#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int main(){
	int num_vertices = 3;
	int num_arestas = 3;
	
	Grafo* g1 = iniciaGrafo(num_vertices, num_arestas);
	exibe(g1);
	
	
    return 0;
	
	
}
