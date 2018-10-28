/*. Para cada uma das sentenças seguintes escreva uma instrução que realize a tarefa
indicada. Admita que as variáveis do tipo float, numero1 e numero2, foram declaradas e
numero1 foi inicializada com o valor 7.3.
a) Declare a variável fptr como ponteiro para uma variável do tipo float;
b) Atribua o endereço da variável numero1 ao ponteiro fptr;
c) Imprima o valor da variável apontada por fptr usando o ponteiro;
d) Atribua o valor da variável apontada por fptr à variável numero2;
e) Imprima o valor de numero2;
f) Imprima o endereço de numero1;
g) Imprima o endereço armazenado em fptr. */

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
