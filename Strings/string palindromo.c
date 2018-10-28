#include <stdio.h>
#include <string.h>

int main ()
{
    char nome[20],c='c';
    int i,j,q=0;

    scanf("%19[^\n]", nome);

while (c=='c') {
    c='s';

        for (i=0; nome[i] != '\0'; i++) {

            if (nome[i] == ' ') {
                    c='c';
            for (j=i; nome[j] != '\0'; j++) {
                    nome[j] = nome[j+1];
            }
        nome[j]='\0';
        }
    }
}

j = strlen(nome) - 1;

for (i=0; nome[i] != '\0'; i++) {

    if (nome[j] == nome[i]) {
        q += 1;
    }

j -= 1;

}


if (q == strlen(nome)) {
    printf("A string EH palindromo.");
} else {
    printf("A string NAO eh palindromo.");
}


    return 0;
}
