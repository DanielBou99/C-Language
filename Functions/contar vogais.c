#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 2. Implemente uma fun��o que receba uma string como par�metro e retorne como resultado o n�mero de vogais encontradas.
int conta vogais(char* str);
Aten��o: devem ser contadas vogais em min�sculo ou mai�sculo. */

int contavogais(char* str);

int main() {

    char string[20];
    int n;

    scanf("%[^\n]", string);
    fflush(stdin);

    n = contavogais(string);

    printf("Quantidade de vogais = %d", n);

    return 0;
}

int contavogais(char* str) {

    strupr(str);

    int i,k=0;

    for (i=0; str[i] != '\0'; i++) {
        if ((str[i] == 65) || (str[i] == 69) || (str[i] == 73) || (str[i] == 79) || (str[i]) == 85) {
            k += 1;
        }
    }

    return k;

}
