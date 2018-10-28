/* Escreva uma fun��o que recebe uma string e um caractere como par�metros e devolve a
posi��o da 1� ocorr�ncia do caractere na string. Caso o caractere n�o esteja contido na
string, a fun��o deve devolver -1.
 */

#include <stdio.h>
#include <string.h>

int check(char, char[]);

int main()
{

    char s[10],c;

    printf("Informe a string: ");
    scanf("%9[^\n]", s);
    fflush(stdin);

    printf("Informe o caractere: ");
    scanf("%c", &c);

    int resultado =  check(c, s);

    if (resultado == -1)
    {
        printf("O caractere nao esta na string.");
    }
    else
    {
        printf("A posicao do caractere eh %d", resultado);
    }

    return 0;
}

int check(char c, char s[])
{

    int i;

    for (i=0; s[i] != '\0'; i++)
    {

        if (s[i] == c)
        {
            return i;
        }

    }

    return -1;

}
