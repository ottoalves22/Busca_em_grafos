#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

//Otto Alves Antonióli - NUSP: 10843361

typedef struct grafo{ //modelo para gráfico ("This is the construct")
    int numVertice; //número de vértices, definido inicialmente para criação da matriz 
    int numAresta; //número de arestas, incrementado a cada inserção de aresta pelo método adjacencia()
    int matrix[200][200];//aponta para matriz onde matrix[v1][v2]=peso para no máximo 200 vértices ("Welcome to the desert of the real")
}grafo;


grafo* iniciaGrafo(int nV, int nA){ //recebe número de nós
    if(nV<0) return NULL;
    grafo* g =(grafo *) malloc(sizeof(grafo)); //aloca espaço pro grafo
    g->numVertice = nV; //registra total de nós
    g->numAresta = nA; //registra total de arestas
    g->matrix[nV][nV];//aloca matriz
    int x, y;
    for(x=0; x<nV; x++){
        for(y=0; y<nV; y++){
            g->matrix[x][y] = -1; //inicia todas adjacencias com valor inválido
        }
    }
    return g;
};

void adjacencia(grafo* g, int v1, int v2, int peso){
    g->matrix[v1][v2] = peso; //adiciona o peso da aresta entre v1 e v2
}

void exibe(grafo* g){ //exibe no terminal todos os pesos, sendo os INT_MAX as arestas não existentes
    int x, y;
    for(x=0; x<g->numVertice; x++){
        printf(" \n ");
        for(y=0; y<g->numVertice; y++){
            printf ("%i\t ", g->matrix[x][y]);     
        }
    }
}

int exibeArvore(int antecessor[], grafo* g, FILE* file_out, int valor) 
{ 
    fprintf(file_out, "%d \n", valor);
    int i;
for (i = 1; i < g->numVertice; i++) 
    printf("%d ==> %d peso: \t%d \n", antecessor[i], i, g->matrix[i][i]);  
    for(i = 1; i < g->numVertice; i++){
        fprintf(file_out, "%d %d  \n", antecessor[i], i);
}
} 

int* prim(grafo* g, FILE* file_out){

    int visitados[g->numVertice];
    int infinito = INT_MAX;
    int aux = 1;
    int custoMinimo = 0;
    int v1, v2, aux1, aux2;
    int custoArvore;


    int i, j;
    for(i=0; i<g->numVertice; i++){
        visitados[i] = -1;
        for(j=0; j<g->numVertice; j++){
            if(g->matrix[i][j] == -1)
            g->matrix[i][j] = infinito;
        }
    }

    visitados[0] = 1;
    while(aux < (g->numVertice)){
        for(i=0; i<=(g->numVertice); i++){
            for(j=0; j<=(g->numVertice); j++){
                if(g->matrix[i][j]<infinito){
                    if(visitados[i] != -1){
                        custoMinimo = g->matrix[i][j];
                        v1 = aux1 = i;
                        v2 = aux2 = j;
                    }
                    if(visitados[v1]==-1 || visitados[v2] == -1){
                        printf("\n Edge %d:(%d %d) cost:%d",aux++,v1,v2,custoMinimo);
                                        if(j>0) fprintf(file_out, "%d %d  \n", v1, v2);

                        custoArvore += custoMinimo;
                        visitados[v2] = 1;
                    }
                }
            }
        }
    }
    	printf("\n Minimun cost= %d",custoArvore);
        fprintf(file_out, "Custo mínimo = %d \n", custoArvore);


}

int main(int argc, char *argv[]){
    
    int j=0;
    int i;
    int stringona[200];
   FILE *file = fopen ( argv[1], "r" );
        FILE* file_out = fopen(argv[2], "w");

   
   if ( file != NULL ){
      fscanf (file, "%d", &i);    
  while (!feof (file)){  
            stringona[j] = i;
      fscanf (file, "%d", &i);
      j++;      
    }
      fclose ( file );
   }

    grafo* g = iniciaGrafo(stringona[0] , stringona[1]);

    int y;
    for(y=2; y<j; y+=3){
        adjacencia(g, stringona[y], stringona[y+1], stringona[y+2]);
    }


    prim(g, file_out);
       

    return 0;
}
