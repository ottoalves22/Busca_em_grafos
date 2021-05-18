#include <stdbool.h>

#define vertice_ausente NULL
#define aresta_nula -1


typedef struct Grafo{ 
    int numVertice; 
    int numAresta; 
    int matrix[100][100];
}Grafo;
