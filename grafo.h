#include <stdbool.h>

#define vertice_ausente NULL
#define aresta_nula -1


typedef struct Grafo{ 
    int numVertice; 
    int numAresta; 
    int matriz[100][100];
}Grafo;

typedef struct lista {
    int chave;
    struct lista * prox;
} Lista;