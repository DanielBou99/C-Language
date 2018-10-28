#include <stdio.h>
#include <string.h>

/*Printar 2 strings em ordem alfabética*/

int main() {

char nome1[20],nome2[20];

printf("Digite o primeiro nome: \n");
scanf("%19[^\n]", nome1);
fflush(stdin);

printf("Digite o segundo nome: \n");
scanf("%19[^\n]", nome2);
fflush(stdin);

if (strcmp(nome1,nome2) == 0 ) {
    printf("%s\n%s", nome1,nome2);
} else {
        if (strcmp(nome1,nome2) < 0) {
            printf("%s\n%s", nome1, nome2);
        }
        else {
            printf("%s\n%s",nome2,nome1);
        }
}

return 0;

}
