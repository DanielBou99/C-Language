#include <stdio.h>
#include <string.h>

int main ()
{
    char nome[40];
    int qtd, i, j;

    scanf("%39[^\n]", nome);

    qtd = strlen(nome) - 1;

    for (i=qtd; nome[i] != ' '; i--) {


    }

    for (j=i; nome[j] != '\0';j++) {
        printf("%c", nome[j]);
    }

    printf(", ");

    for (i=0; nome[i] != ' ';i++) {
        printf("%c", nome[i]);
    }


    return 0;
}
