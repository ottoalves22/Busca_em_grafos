#include "implementa_grafos.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
int visitado[200];
int profundidade[200];
int conexao[200];
int antecessor[200];
int nivel[200];
int descoberto[200];
int contador_nivel;


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

	//definindo vetores auxiliares com 0
	for(int aux=0; aux<num_vertices; aux++){
		visitado[aux] = 0;
	}

    //lista de vertices percorridos
	Lista* l1 = inicia_lista();

    //declaracao do grafo
	Grafo* g1 = iniciaGrafo(num_vertices, num_arestas);

    // insercao das arestas
    for(int y=2; y<j; y+=3){
        adjacencia(g1, string_auxiliar[y], string_auxiliar[y+1], string_auxiliar[y+2]);
    }

	printf("%d %d \n", g1->numVertice, g1->numAresta);
	fprintf(file_out, "%d %d  \n", g1->numVertice, g1->numAresta);

    //exibe grafico de acordo com a entrada
	exibe(g1, file_out);

    printf("\nBL:\n");
	fprintf(file_out, "\nBL:\n");
    BL(g1, 0, file_out);

    //resetando vetor de visitados para zero novamente
	for(int aux=0; aux<num_vertices; aux++){
		visitado[aux] = 0;
	}

	printf("\n\nCaminhos BL:");
	fprintf(file_out, "\n\nCaminhos BL:");

    passeioBL(g1, 10, file_out);

	//resetando vetor de visitados para zero novamente
	for(int aux=0; aux<num_vertices; aux++){
		visitado[aux] = 0;
	}

	printf("\n\nBP:\n");
	fprintf(file_out, "\n\nBP:\n");

    //Busca em profundidade
	BP(g1, 0, l1, file_out);

	//resetando vetor de visitados para zero novamente
	for(int aux=0; aux<num_vertices; aux++){
		visitado[aux] = 0;
	}

    printf("\n\nCaminhos BP:");
	fprintf(file_out, "\n\nCaminhos BP:");
    //passeio pelo grafo
	passeioBP(g1, 0, l1, file_out);

    printf("\nComponentes conexos:");
	fprintf(file_out, "\nComponentes conexos:");
	componentes_conexos(g1, file_out);


    printf("\n\nVertices de articulacao:");
	fprintf(file_out, "\n\nVertices de articulacao:");

	//vertices_articulacao(g1);

	for(int aux=0; aux<num_vertices; aux++){
		visitado[aux] = 0;
		profundidade[aux] = 0;
		conexao[aux] = 0;
		antecessor[aux] = -1;
		nivel[aux] = 0;
		descoberto[aux] = -1;
	}

	contador_nivel = 0;

	Lista* lista_aux = inicia_lista();

	bp_aux(g1, 0, lista_aux, file_out);



    return 0;
}


//busca em profundidade
void BP(Grafo* g, int inicio, Lista* l, FILE* file_out){
	int j;
	printf("%d ", inicio);
	fprintf(file_out, "%d ", inicio);
	visitado[inicio] = 1;
	for(j=0; j<g->numVertice; j++){
		if(!visitado[j] && g->matriz[j][inicio]!=-1){
			BP(g, j, l, file_out);
		}
	}
}


//passeio; armazena os visitados numa lista ligada
void passeioBP(Grafo* g, int inicio, Lista* l, FILE* file_out){
	int j;
	visitado[inicio] = 1;
	printf("\n");
	fprintf(file_out, "\n");
	push(l, inicio);
	for(j=0; j<g->numVertice; j++){
			push(l, j);
			if(!visitado[j] && g->matriz[inicio][j]!=-1){
			exibe_lista(l, file_out);
			pop(l);
			passeioBP(g, j, l, file_out);
		}
		pop(l);
	}
}


//busca em largura ta sendo pego em https://pt.wikipedia.org/wiki/Busca_em_largura
void BL(Grafo* g, int inicio, FILE* file_out){
    Lista* l = inicia_lista();
    push(l, inicio);
    printf("%d ", inicio);
	fprintf(file_out, "%d ", inicio);
    while(topo(l)!=retorno){ //enquanto o topo da lista nao for o sentinela
        int aux = topo(l);
        pop(l);
        visitado[aux] = 1;
        for(int i=0; i<g->numVertice; i++){
            if(g->matriz[aux][i]!=-1 && g->matriz[aux][i]!=retorno && !visitado[i]){
                printf("%d ", i);
	            fprintf(file_out, "%d ", i);
                push(l, i);
            }
        }
    }

}


void passeioBL(Grafo* g, int inicio, FILE* file_out){
    Lista* l = inicia_lista();
    push(l, inicio);
    printf("\n%d", inicio);
    fprintf(file_out, "\n%d ", inicio);
    while(topo(l)!=retorno){ //enquanto o topo da lista nao for o sentinela
        int aux = topo(l);

        pop(l);
        visitado[aux] = 1;
        for(int i=0; i<g->numVertice; i++){
            if(g->matriz[aux][i]!=-1 && g->matriz[aux][i]!=retorno && !visitado[i]){
                push(l, i);
            }
        }
        printf("\n%d  ", inicio);
        fprintf(file_out, "\n%d ", inicio);
        exibe_lista(l, file_out);
    }
}


void bp_aux(Grafo* g, int inicio, Lista* l, FILE* file_out){
	int j;
	visitado[inicio] = 1;
	push(l, inicio);
	++contador_nivel;
	nivel[inicio] = contador_nivel;
	descoberto[inicio] = contador_nivel;
	int filho = 0;
	for(j=0; j<g->numVertice; j++){
			push(l, j);
			if(!visitado[j] && g->matriz[inicio][j]!=-1){
				filho++;
				antecessor[j] = inicio;
				bp_aux(g, j, l, file_out);
				nivel[inicio] = MIN(nivel[inicio], nivel[j]);
				if(antecessor[inicio]!=-1 && nivel[j]>=descoberto[inicio]){
					conexao[inicio] = 1;
					printf("%d ", j);
				}
				if(antecessor[inicio]==-1 && filho>1){
					conexao[inicio] = 1;
					printf("%d ", j);
				}
		}
		else if(j!=antecessor[inicio]){
			nivel[inicio] = MIN(nivel[inicio], descoberto[j]);
		}
	}
}
