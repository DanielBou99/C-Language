/* Escreva uma função que receba um vetor de inteiros de n elementos e troque o 1º
elemento pelo último, o 2º pelo penúltimo, o 3º pelo antepenúltimo, e assim
sucessivamente. Escreva um programa que leia um vetor de inteiros de n elementos,
utilize a função para inverter a ordem dos elementos do vetor e depois mostre o vetor  */

#include <stdio.h>

void troca(int,int[]);

int main()
{

    int n;

    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n],i;

    printf("Escreva o vetor: \n");

    for (i=0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    troca(n,v);

    for (i=0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

void troca(int t,int v[])
{

    int i,aux[t],j;

    for (i=0,j=t-1; i < t; i++,j--)
    {

        aux[i] = v[j];

    }

    for (i=0; i < t; i++)
    {
        v[i] = aux[i];
    }

}
