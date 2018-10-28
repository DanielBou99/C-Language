#include <stdio.h>
#include <ctype.h>

int main ()
{

    char nome[15];
    int i,c=0;

    scanf("%14[^\n]", nome);

    for (i=0; nome[i] != '\0'; i++) {

        if (isupper(nome[i]) != 0) {
                c += 1;
        }

    }



    printf("Total de letras maiusculas = %d", c);

    return 0;
}
