/* 6. Escreva uma função que receba uma matriz A bidimensional de valores reais e um valor
real x, e multiplique todos os elementos de A por x. */


#include <stdio.h>

void resultado(float,int,int,float[][*]);

int main() {

    int l,c,i,j;

    printf("Informe as linhas e colunas da seguinte forma LINxCOL: ");
    scanf("%dx%d", &l,&c);

    float m[l][c];

    float v;

    printf("Informe o numero real: ");
    scanf("%f", &v);

    printf("Informe os valores da matriz: \n");

    for (i=0;i < l; i++) {
        for (j=0; j < c; j++) {
            scanf("%f", &m[i][j]);
        }
    }

resultado(v,c,l,m);


    return 0;
}

void resultado(float v,int c,int l,float m[][c]) {

    int i,j;

    printf("\n Resultado da matriz: \n");

    for (i=0;i < l; i++) {
        for (j=0; j < c; j++) {
            m[i][j] = m[i][j] * v;
            printf(" %.2f", m[i][j]);
        }
        printf("\n");
    }


}
