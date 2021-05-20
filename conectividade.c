#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int visited[100];


int main(){
	FILE *file;
	file = fopen("entrada.txt", "r");
   int j=0;
   int i;
   int string_auxiliar[200];
   if(file!=NULL){   
	    fscanf(file, "%d", &i);
		while(!feof(file)){  
            string_auxiliar[j] = i;
			(file, "%d", &i);
			fscanf (file, "%d", &i);
			j++;      
		}
      fclose(file);
   }
   
   int num_vertices = string_auxiliar[0];
	int num_arestas = string_auxiliar[1];
	
	for(int aux=0; aux<num_vertices; aux++){
		visited[aux] = 0;
	}

	Grafo* g1 = iniciaGrafo(num_vertices, num_arestas);

    for(int y=2; y<j; y+=3){
        adjacencia(g1, string_auxiliar[y], string_auxiliar[y+1], string_auxiliar[y+2]);
    }
	
	printf("%d %d \n", g1->numVertice, g1->numAresta);
	exibe(g1);
	printf("\nBP:\n");
	BP(g1, 0);
	printf("\n\nCaminhos BP:\n");
	
	
    return 0;
	
}


//busca em profundidade
void BP(Grafo* g, int inicio){
	int j;
	printf("%d ", inicio);
	visited[inicio] = 1;
	
	for(j=0; j<g->numVertice; j++){
		if(!visited[j]&&g->matrix[inicio][j]!=-1){
			BP(g, j);
		}
	}
}


//busca em largura
void BL(Grafo* g, int inicio){
	visited[inicio] = 1;
	int arr_auxiliar[g->numVertice];
	arr_auxiliar[inicio] = 1;
	
}
