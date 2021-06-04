#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
# define retorno 12616161

Grafo* cria_grafo(int vertices, int arestas){
  Grafo* g1 = malloc(sizeof(Grafo));
  g1->numVertice = vertices;
  g1->numAresta = arestas;

  g1->lista_adjacencia = malloc(vertices * sizeof(Aresta));
  g1->visitados = malloc(vertices* sizeof(int));

  for(int i=0; i<vertices; i++){
    g1->lista_adjacencia[i] = NULL;
    g1->visitados[i] = 0;
  }

  return g1;
}


void exibe_grafo(Grafo* g1, FILE* file_out){
  for(int i=0; i<g1->numVertice; i++){
        struct Aresta* temp = g1->lista_adjacencia[i];
        while (temp) {
          if(temp->peso!=retorno){
            printf("%d %d %d\n", i, temp->vertice, temp->peso);
            fprintf(file_out, "%d %d %d\n", i, temp->vertice, temp->peso);
          }
          temp = temp->prox;
        }
  }
}


Aresta* cria_aresta(int chave, int peso){
  Aresta* nova_aresta = malloc(sizeof(Aresta));
  nova_aresta->vertice = chave;
  nova_aresta->peso = peso;
  nova_aresta->prox = NULL;
  return nova_aresta;
}


void adiciona_aresta(Grafo* g1, int origem, int destino, int peso){
  //ida
  Aresta* a1 = cria_aresta(destino, peso);
  a1->prox = g1->lista_adjacencia[origem];
  g1->lista_adjacencia[origem] = a1;

  //volta
  a1 = cria_aresta(origem, retorno);
  a1->prox = g1->lista_adjacencia[destino];
  g1->lista_adjacencia[destino] = a1;
}


Fila* cria_fila(){
  Fila* f1 = malloc(sizeof(Fila));
  f1->prox = -1;
  f1->ant = -1;
  return f1;
}


int fila_vazia(Fila* f1){
  if(f1->ant==-1){
    return 1;
  }
  return 0;
}


void push(Fila* f1, int valor){
  if(f1->ant==99){
    printf("\nFila cheia!");
  }
  else {
    if(f1->prox==-1){
      f1->prox = 0;
    }
    f1->ant = f1->ant + 1;
    f1->itens[f1->ant] = valor;
  }
}


int pop(Fila* f1){
  int item;
  if(fila_vazia(f1)){
    item = -1;
  }
  else {
    item = f1->itens[f1->prox];
    f1->prox++;
    if(f1->prox > f1->ant){
      //reseta fila
      f1->prox = f1->ant = -1;
    }
  }
  return item;
}


void exibe_fila(Fila* f1){
  int i = f1->prox;
  if(!fila_vazia(f1)){
    for(i; i<f1->ant++; i++){
      printf("%d ", f1->itens[i]);
    }
  }
}


//Busca em profundidade
void BP(Grafo* g1, int inicio, FILE* file_out){
  Aresta* listaAdjacenciaInicio = g1->lista_adjacencia[inicio];
  Aresta* aux = listaAdjacenciaInicio;

  g1->visitados[inicio] = 1;
  printf("%d ", inicio);
  fprintf(file_out, "%d ", inicio);

  while(aux!=NULL){
    int vertice_conexo = aux->vertice;
    if(g1->visitados[vertice_conexo]==0){
      BP(g1, vertice_conexo, file_out);
    }
    aux = aux->prox;
  }
}

void BP_auxiliar(Grafo* g1, int inicio, int visitados[]){
  Aresta* listaAdjacenciaInicio = g1->lista_adjacencia[inicio];
  Aresta* aux = listaAdjacenciaInicio;

  visitados[inicio] = 1;
  while(aux!=NULL){
    int vertice_conexo = aux->vertice;
    if(visitados[vertice_conexo]==0){
      BP_auxiliar(g1, vertice_conexo, visitados);
    }
    aux = aux->prox;
  }
}

//componentes conectados
void componentes_conextos(Grafo* g1, FILE* file_out){
  int visitados[g1->numVertice];
  printf("\n");
  for(int i=0; i<g1->numVertice; i++){
    visitados[i] = 0;
  }

  for(int i=0; i<g1->numVertice; i++){
    if(visitados[i]==0){
      struct Aresta* temp = g1->lista_adjacencia[i];

      printf("\n");
      BP_auxiliar(g1, i, visitados);
      while (temp) {
          printf("%d ", temp->vertice);

        temp = temp->prox;
      }
    }
  }


}


//Busca em largura
