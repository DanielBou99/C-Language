/* Escreva um programa que dada um inteiro n e um caractere ch, solicite que o usu�rio
informe n palavras que come�am com a letra ch. Se o usu�rio informar alguma palavra
que n�o comece com a letra ch, o programa deve exibir uma mensagem informando que a
palavra n�o come�a com a letra ch. No final o programa deve exibir as n palavras
digitadas pelo usu�rio que come�am com a letra ch. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main () {

int n;
char ch;

printf("Digite a quantidade de palavras: ");
scanf("%d", &n);
fflush(stdin);
printf("Digite o inicial das palavras: ");
scanf(" %c", &ch);
fflush(stdin);

char palavras[n][20];
int i= 0;

for (i=0; i < n; i++) {

    printf("Digite a palavra %d: ", i+1);
    fgets(palavras[i],19,stdin);
    fflush(stdin);
    printf("");

    if (tolower(ch) != tolower(palavras[i][0])) {
        printf("Palavra incorreta!\n");
    }

}

printf("\nEssas sao as palavras digitadas corretamente:\n");
    for (i=0; i < n; i++) {
        if (tolower(ch) == tolower(palavras[i][0])) {
            printf("%s",palavras[i]);
        }
    }


return 0;
}
