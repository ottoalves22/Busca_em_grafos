#include "grafo.h"
#include <stdio.h>
#include <string.h>

#define LSIZ 128 
#define RSIZ 10 


int main(){
	Grafo g1;
	int num_vertices;
	int i = 0;
	int t = 0;
	
    char linha[RSIZ][LSIZ];
	FILE *file;
	
	file = fopen("entrada.txt", "r");
	while(fgets(linha[i], LSIZ, file)){
		linha[i][strlen(linha[i]) - 1] = '\0';
        i++;
	}
	
	t = i;
    for(i = 0; i < t; ++i)
    {
        printf(" %s\n", linha[i]);
    }
    printf("\n");
    return 0;
	
	
}
