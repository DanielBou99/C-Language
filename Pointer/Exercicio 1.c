/*. Para cada uma das senten�as seguintes escreva uma instru��o que realize a tarefa
indicada. Admita que as vari�veis do tipo float, numero1 e numero2, foram declaradas e
numero1 foi inicializada com o valor 7.3.
a) Declare a vari�vel fptr como ponteiro para uma vari�vel do tipo float;
b) Atribua o endere�o da vari�vel numero1 ao ponteiro fptr;
c) Imprima o valor da vari�vel apontada por fptr usando o ponteiro;
d) Atribua o valor da vari�vel apontada por fptr � vari�vel numero2;
e) Imprima o valor de numero2;
f) Imprima o endere�o de numero1;
g) Imprima o endere�o armazenado em fptr. */

#include <stdio.h>

int main() {

float numero1=7.3,numero2;

float * fptr; // a

fptr = &numero1; // b

printf("%.2f \n", *fptr); // c

numero2 = *fptr; // d

printf("%.2f \n", numero2); // e

printf("Endereco do numero1 = %p\n", &numero1); //f

printf("Endereco armazenado no ponteiro>> %p", fptr); //g

    return 0;
}
