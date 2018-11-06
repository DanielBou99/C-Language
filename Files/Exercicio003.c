/*Escreva um programa que recebe dois valores via argumentos da função main().
O primeiro é uma string e o segundo o nome de um arquivo do tipo texto.
O programa deve percorrer o arquivo imprimindo no vídeo todas as linhas que
contêm a string. Use a função strstr() para procurar a palavra em uma linha*/

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {

char Lookarq[51];

if (argc != 3) {
    printf("Argumentos da main incorretos.");
    return 2;
}

FILE * arq;

if ((arq = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Erro de abertura do arquivo %s\n", argv[1]);
		return 1;
	}

while (fgets(Lookarq, 51, arq) != NULL) {

    if (strstr(Lookarq,argv[2]) != NULL) {
        printf("%s", Lookarq);
    }

}

fclose(arq);



    return 0;
}
