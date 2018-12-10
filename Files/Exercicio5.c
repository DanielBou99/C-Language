#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[1000], palavra[100], aux;
    int i,j=0,i2,k,total=0;
    FILE *arquivo;

    printf("Digite o nome do arquivo: ");
    scanf("%s", string);
    fflush(stdin);

    arquivo= fopen(string, "r");

    if (arquivo == NULL) {
        printf("Nao foi possivel ler o arquivo.\n");
        return 1;
    }

    printf("Digite a palavra: ");
    scanf("%s", palavra);
    fflush(stdin);

     while(fgets(string, 1000, arquivo) != NULL) {

                 k = 0;
                 j = 0;

        for (i=0; string[i] != 0; i++) {

            if (string[i] == palavra[j]) {
                    printf("%s\n", string);
                i2 = i;

                for (j=0; palavra [j] != '\0'; j++) {

                if (palavra[j] == string[i2]) {
                    k += 1;
                    if (k == strlen(palavra)) {
                        total += 1;
                    }
                }

                i2 += 1;

                }

            }

        }
     }

printf("Total de vezes = %d\n", total);


    fclose(arquivo);


    return 0;
}
