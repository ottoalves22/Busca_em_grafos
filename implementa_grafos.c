#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"

Grafo* iniciaGrafo(int nV, int nA){ //recebe número de nós
    if(nV<0) return NULL;
    Grafo* g =(Grafo *) malloc(sizeof(Grafo)); 
    g->numVertice = nV; 
    g->numAresta = nA; 
    g->matrix[nV][nV];
    int x, y;
    for(x=0; x<nV; x++){
        for(y=0; y<nV; y++){
            g->matrix[x][y] = -1; 
        }
    }
    return g;
}

void adjacencia(Grafo* g, int v1, int v2, int peso){
    g->matrix[v1][v2] = peso;
    g->matrix[v2][v1] = 1616;
}

void exibe(Grafo* g, FILE* file_out){ //exibe no terminal todos os pesos, sendo os INT_MAX as arestas não existentes
    int x, y;
    for(x=0; x<g->numVertice; x++){
        printf("\n");
        for(y=0; y<g->numVertice; y++){
		if(g->matrix[x][y]!=-1 && g->matrix[x][y] != 1616){
				printf("%d %d %d\n", x, y, g->matrix[x][y]);
				fprintf(file_out, "%d %d %d\n", x, y, g->matrix[x][y]);
			}
            //printf ("%i\t ", g->matrix[x][y]);     
        }
    }
}
