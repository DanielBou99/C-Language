#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Avance as Letras2
. É dado na entrada uma string A e outra B. Em uma operação você pode
escolher uma letra da primeira string e avançar esta letra. Avançar uma letra significa
transformá-la na próxima letra do alfabeto, veja que a próxima letra depois de z vem a
letra a novamente!
Por exemplo, podemos transformar a string ab em bd em no mínimo 3 operações: ab → bb
→ bc → bd. Podemos aplicar operações nas letras em qualquer ordem, outra possibilidade
seria: ab → ac → bc → bd.
Dadas as duas strings, calcule o mínimo número de operações necessárias para
transformar a primeira na segunda.
Entrada
Na primeira linha terá um inteiro T (T ≤ 100) indicando o número de casos de teste. Para
cada caso, na única linha teremos as duas strings A (1 ≤ |A| ≤ 100 ou 1 ≤ |A| ≤ 104
 - sendo
que |A| significa o tamanho da string A) e B (|B| = |A| ou |B| = |A|) separadas por um
espaço. Ambas as strings são compostas por letras do alfabeto minúsculas apenas e são do
mesmo tamanho.
Saída
Para cada caso imprima o número mínimo de operações.*/

int main() {

int iff;

do {
printf("Digite o numero de tentativas: ");
scanf("%d", &iff);
} while(iff < 1 || iff > 100);

char s[100];
int in,i,aux,aux2,aux3=0,j,r=0;


for (in=0; in <= iff; in++) {

scanf(" %99[^\n]", s);

j = strlen(s);
j = (j / 2) +1;



for (i=0; s[i] != ' '; i++) {

    if (s[i] == 'z') {
        aux = 96;
    }
    if (s[j] == 'z') {
        aux2 = 96;
    }

    if (((s[i] != 'z')) && ((s[j] != 'z'))) {
        aux = s[i]; // c
        aux2 = s[j]; // a

    }

    if (aux2 < aux) {
        aux3 = 122 - aux;
        aux3 = aux3 + (aux2 - 96);
        r = r + aux3;
    } else{
        r = r + (aux2 - aux);
    }



    j += 1;
    aux3 = 0;


}

printf("Total de alteracoes: = %d \n", r);

r = 0;

}








    return 0;
    }
