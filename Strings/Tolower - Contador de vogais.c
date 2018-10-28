#include <stdio.h>
#include <ctype.h>

int main ()

{

    int cont[5]= {0}, i, j;
    char nome[15],v[5]= {'a','e','i','o','u'}, ch;

    printf("Informe a entrada do texto: \n");
    scanf("%14[^\n]", nome);

    for (i=0; nome[i] != '\0'; i++) {
        ch= tolower(nome[i]);
        for (j=0; j<5; j++) {
            if(ch == v[j]) {
                cont[j] += 1;
            }
        }
    }
        printf("Histograma: \n a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", cont[0],cont[1],cont[2],cont[3],cont[4]);



    return 0;
}
