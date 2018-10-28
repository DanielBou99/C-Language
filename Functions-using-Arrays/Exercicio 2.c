/*. Escreva uma função de protótipo void init_vetor(int a[], int n, int val);
que inicialize o vetor a com n elementos com o valor de val. */

#include <stdio.h>

void vetor(int a[], int n, int val);

int main() {

int n,val,i;

printf("Escreva o tamanho do vetor: ");
scanf("%d", &n);

int a[n];

printf("Escreva o valor do vetor: ");
scanf("%d", &val);

vetor(a,n,val);

for (i=0; i < n; i++) {
    printf("%d ", a[i]);
}


    return 0;
}

void vetor(int a[], int n, int val) {

int i;

for (i=0; i < n; i++) {
    a[i] = val;
}

}
