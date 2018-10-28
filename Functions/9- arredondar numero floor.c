#include <stdio.h>
#include <math.h>
/*Esse programa arredonda um numero floor para cima. ex: Input> 1.6 / Output> 2.0*/
int arredondarParaInt(double);

int main () {
int n,i;

printf("Quantidade de num que serao lidos: ");
scanf("%d", &n);

double m;

for (i=0; i<n; i++) {
    scanf("%lf", &m);
    m = arredondarParaInt(m);
    printf("Numero arredondado = %.2lf \n", m);
}

    return 0;
}

int arredondarParaInt(double n) {

floor(n);
n += 1;

return n;
}
