#include <stdio.h>

int main() {

    int v[5] = {5,3,10,1,6};
    int aux,i,j;

    for (i=1; i < 5; i++) {

        aux = v[i];
        j = i - 1;

        while ((j >= 0) && (aux < v[j])) {

            v[j+1] = v[j];
            j--;
        }

        v[j+1] = aux;
    }


    printf("Vetor ordenado:\n");

    for (i=0; i < 5; i++) {
        printf("Posicao %d = %d\n", i, v[i]);
    }

    return 0;

}
