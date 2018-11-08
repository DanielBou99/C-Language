#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Escreva um programa que recebe o nome de dois arquivos do tipo texto via argumentos da
fun��o main(). O programa deve gerar uma c�pia o primeiro arquivo no segundo, entretanto,
todos os caracteres do segundo arquivo devem estar em letras mai�sculas. Use a fun��o
toupper() do ctype.h para converter todos os caracteres para mai�sculo e grav�-los no segundo
arquivo.
*/

int main(int argc, char * argv[])
{

    if (argc != 3) {
        return 1;
    }

    FILE *origem, *destino;
    char ch;

    if ((origem = fopen(argv[1], "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", argv[1]);
        return 2;
    }

    if ((destino = fopen(argv[2], "w")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", argv[2]);
        return 3;
    }

    while ( (ch = fgetc(origem)) != EOF ) {

        ch = toupper(ch);
        fputc(ch,destino);

    }

    fclose(origem);
    fclose(destino);


    return 0;
}
