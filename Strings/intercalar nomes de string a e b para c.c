#include <stdio.h>
#include <string.h>


/* Escreva um programa para ler 8 nomes em cada um dos vetores de strings A e B.
Construir um vetor de strings C, que será formada por um elemento do vetor A e por um
elemento do vetor B, intercaladamente.. */

int main() {

char a[50],b[50],c[100];
int ia=1,ib=0,i=0,ic=0,j=0;
char controlea='c';

scanf("%49[^\n]", a);
    fflush(stdin);
scanf("%49[^\n]", b);
    fflush(stdin);

while (controlea=='c') {
    controlea = 's';

    if (ia > ib) {
ib += 2;
        for (i=i;(i < strlen(a)); i++) {

            if (a[i] != ' ') {
                controlea = 'c';
                c[ic] = a[i];
                a[i] = '0';
                c[ic+1] = '\0';
                ic += 1;
            } else{
                c[ic] = a[i];
                ic += 1;
                i += 1;
                break;
            }
            if (a[i+1] == '\0') {
                c[ic] = ' ';
                c[ic+1] = '\0';
                ic += 1;
            }
        }
    }

    if (ib > ia) {
ia += 2;
        for (j=j;(j < strlen(b)); j++) {

            if (b[j] != ' ') {
                controlea = 'c';
                c[ic] = b[j];
                b[j] = '0';
                c[ic+1] = '\0';
                ic += 1;

            } else{
                c[ic] = b[j];
                ic += 1;
                j += 1;
                break;
            }

            if (b[j+1] == '\0') {
                c[ic] = ' ';
                c[ic+1] = '\0';
                ic += 1;
            }
        }
    }



}

puts(c);





    return 0;


}

