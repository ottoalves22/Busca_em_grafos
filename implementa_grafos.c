#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#define retorno 12261616 //define aresta 1,3 a partir da aresta 3,1, por exemplo

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
    g->matrix[v2][v1] = retorno;
}

void exibe(Grafo* g, FILE* file_out){ //exibe no terminal todos os pesos, sendo os INT_MAX as arestas não existentes
    int x, y;
    for(x=0; x<g->numVertice; x++){
        printf("\n");
        for(y=0; y<g->numVertice; y++){
		if(g->matrix[x][y]!=-1 && g->matrix[x][y] != retorno){
				printf("%d %d %d\n", x, y, g->matrix[x][y]);
				fprintf(file_out, "%d %d %d\n", x, y, g->matrix[x][y]);
			}
        }
    }
}

Lista* inicia_lista(){
    Lista* head = NULL;
    head = (Lista*) malloc(sizeof(Lista));
    if (head == NULL) {
        return NULL;
    }

    //sentinela com chave invalida
    head->chave = retorno; // a lista começa com um sentinela de chave 12261616 (variavel retorno)
    head->prox = NULL;
    return head;
}

bool lista_vazia(Lista* l){
    if(l->chave==retorno && l->prox==NULL){
        return true;
    } else {
        return false;
    }
}

//adiciona ao fim da lista
void push(Lista* l, int chave){
    Lista* atual = l;

    while(atual->prox !=NULL){
        atual = atual->prox;
    }
    atual->prox = (Lista*) malloc(sizeof(Lista));
    atual->prox->chave = chave;
    atual->prox->prox = NULL;
}


int topo(Lista* l){
    Lista * atual = l;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    return atual->chave;
}


//remove vertice do fim da lista
void pop(Lista ** l) {
    Lista * atual = l;
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    free(atual->prox);
    atual->prox = NULL;
}


void exibe_lista(Lista* l, FILE* file_out){
    Lista* atual = l;
    atual = atual->prox;
    while (atual != NULL) {
        printf("%d  ", atual->chave);
        fprintf(file_out, "%d ", atual->chave);
        atual = atual->prox;
    }
}