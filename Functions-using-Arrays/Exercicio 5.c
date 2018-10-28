/* 5. Escreva uma fun��o que receba como par�metro uma matriz quadrada de ordem n de
inteiros e devolve verdadeiro se ela � uma matriz triangular superior, ou falso, caso
contr�rio. Matriz triangular superior � uma matriz onde todos os elementos de posi��es
acima da diagonal principal s�o diferentes de 0 e os demais elementos s�o iguais a 0. */

#include <stdio.h>

int check(int,int[][*]);

int main()
 {
     int t,i,j;

     printf("Digite o tamanho da matriz: ");
     scanf("%d", &t);

     int matriz[t][t];

     printf("Informe os valores da matriz: ");

     for (i=0; i < t; i++) {
        for (j=0; j < t; j++) {
            scanf("%d", &matriz[i][j]);
        }
     }

     int resultado = check(t,matriz);

     if (resultado == 0) {
        printf("A matriz nao eh triangular superior");
     } else {
     printf("A matriz eh triangular superior");
     }

     return 0;
 }

 int check(int t,int matriz[][t]) {

 int i,j,aux=1;

    for (i=0; i < (t-1); i++) {
        for (j=aux; j < t; j++) {
            if (matriz[i][j] == 0) {
                return 0;
            }
        }
        aux += 1;
    }

    aux = 1;

    for (i=0; i < t; i++) {
        for (j=0; j < aux; j++) {
            if (matriz[i][j] != 0) {
                return 0;
            }
        }
        aux += 1;
        if (aux == (t+1)) {
            return 1;
        }
    }

 }
