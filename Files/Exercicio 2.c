/*2.	Faça um programa em Linguagem C que gere 100.000 caracteres aleatórios e grave em um
arquivo texto. Caracteres válidos: A-Z, a-z, 0-9;*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main () {
srand( (unsigned)time(NULL) );

char texto[100000];
char aleatorio[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIOJKLMNOPQRSTUVWXYZ";
int i;


for (i=0; i < 100000; i++) {

texto[i] = aleatorio[rand() % 63];

}

texto[100001] = '\0';

FILE *parquivo;

parquivo = fopen("texto.txt", "w");

fprintf(parquivo,"%s",texto);

    return 0;
}
