#include "grafo.h"
#include <stdio.h>

#define CHUNK 1024

int main(){
	Grafo g1;
	int num_vertices;
	
	char buf[CHUNK];
	FILE *file;
	size_t nread;

	file = fopen("entrada_teste.txt", "r");
	if (file) {
    while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
        fwrite(buf, 1, nread, stdout);
    if (ferror(file)) {
        /* deal with error */
    }
    fclose(file);
}
}
