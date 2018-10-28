
/* Criar uma função em C que receba um número binário e converta-o para decimal. Obs.:
O parâmetro passado na chamada à função deve ser alterado para decimal. */

#include <stdio.h>
#include <string.h>

void conversao(int*);

int main() {

int num;

printf("binaria>>>>> ");
scanf("%d", &num);

conversao(&num);

printf("Decimal>> %d", num);

}

void conversao(int *n) {

int t=0,m=1;

while (*n>0) {

if ((*n % 10) == 1) {
    t = t + (*n % 10) * m;
    *n = *n / 10;
    m = m * 2;
} else {
    *n = *n / 10;
    m = m * 2;
}

}

*n = t;

}
