/* 1.	Faça um programa em Linguagem C que receba do usuário um arquivo texto,
e mostre na tela quantas linhas esse arquivo possui. Considere o ‘\n’ como terminador de linha;
*/

#include<stdio.h>

int main()
{
    int cont = 1;
    char aux;
    FILE *arquivo;

    arquivo = fopen("texto.txt" , "r");

    while (feof(arquivo)==0){
        aux = fgetc(arquivo);
        if(aux == '\n'){
            cont++;
        }

    }

    printf("%d", cont);

    return 0;
}
