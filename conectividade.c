#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
	FILE *file;
	file = fopen("entrada.txt", "r");
	FILE* file_out;
    file_out= fopen("saida.txt", "w");
    int j=0;
    int i;
    int string_auxiliar[200];
    if(file!=NULL){
	    fscanf(file, "%d", &i);
		while(!feof(file)){
            string_auxiliar[j] = i;
			fscanf (file, "%d", &i);
			j++;
			string_auxiliar[j] = i;
		}
  	fclose(file);
  }
  int num_vertices = string_auxiliar[0];
  int num_arestas = string_auxiliar[1];

    //declaracao do grafo
	Grafo* g1 = cria_grafo(num_vertices, num_arestas);

    // insercao das arestas
  for(int y=2; y<j; y+=3){
  	adiciona_aresta(g1, string_auxiliar[y], string_auxiliar[y+1], string_auxiliar[y+2]);
  }

	printf("%d %d \n", g1->numVertice, g1->numAresta);
	fprintf(file_out, "%d %d  \n", g1->numVertice, g1->numAresta);

  //exibe grafico de acordo com a entrada
	exibe_grafo(g1, file_out);

  printf("\nBL:\n");
	fprintf(file_out, "\nBL:\n");

	printf("\n\nCaminhos BL:");
	fprintf(file_out, "\n\nCaminhos BL:");

	printf("\n\nBP:\n");
	fprintf(file_out, "\n\nBP:\n");

	BP(g1, 0, file_out);

  printf("\n\nCaminhos BP:");
	fprintf(file_out, "\n\nCaminhos BP:");

  printf("\nComponentes Conectados:");
	fprintf(file_out, "\nComponentes Conectados:");

	componentes_conextos(g1, file_out);

  printf("\n\nVertices de articulacao:");
	fprintf(file_out, "\n\nVertices de articulacao:");

    return 0;
}
