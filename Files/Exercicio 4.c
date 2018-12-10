#include <stdio.h>
#include <stdlib.h>

void copiarconteido(FILE *origem, FILE *destino);

int main() {

FILE *arquivo1 = fopen("arquivo1.txt", "r");
FILE *arquivo2 = fopen("arquivo2.txt", "r");
FILE *arquivo3 = fopen("arquivo3.txt", "a");

if (arquivo1 == NULL) {
    printf("Nao foi possivel ler no arquivo1.\n");
    exit(0);
}
if (arquivo2 == NULL) {
    printf("Nao foi possivel ler no arquivo2.\n");
    exit(0);
}
if (arquivo3 == NULL) {
    printf("Nao foi possivel gravar no arquivo3.\n");
    exit(0);
}

copiarconteido(arquivo1, arquivo3);
copiarconteido(arquivo2, arquivo3);

fclose(arquivo1);
fclose(arquivo2);
fclose(arquivo3);


    return 0;
}

void copiarconteido(FILE *origem, FILE *destino) {

    char string[1000];

    while(fgets(string,1000,origem) != NULL) {
        fputs(string,destino);
    }

}
