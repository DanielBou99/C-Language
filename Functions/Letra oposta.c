/* 7. Implemente uma função que receba uma string como parâmetro
e substitua as ocorrências de uma letra pelo seu oposto no alfabeto,
isto e, ‘a’ para ‘z’, ‘b’ para ‘y’, ‘c’ para ‘x’, etc.
Caracteres que não forem letras devem permanecer inalterados.
void string oposta (char* str); */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void oposta(char* str);

int main () {

char string[100];

scanf("%99[^\n]", string);
fflush(stdin);

oposta(string);

printf("Nova string = %s", string);

    return 0;
}

void oposta(char* str) {


    int i,aux;

    strlwr(str);



    for (i=0; str[i] != '\0'; i++) {

        if ((str[i] >= 97) && (str[i] <= 122)) {
            aux = str[i] - 96;
            str[i] = 123 - aux;
        }

    }



}
