#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file;

void gravar(void);
void exibirListagem(void);

int main() {

int controle;

do {
    printf("1- Gravar Pessoa;\n2- Exibir Listagem;\n3- Sair\n");
    scanf("%d", &controle);

    if (controle == 1) {
        gravar();
    } else {
    if (controle == 2) {
        exibirListagem();
    }
    }


}   while(controle != 3);

getchar();
    return 0;
}

void gravar(void) {

char nome[100];
char ano[10];
int i;

file = fopen("gravar.txt", "a");

if (file == NULL) {
    printf("Nao foi possivel gravar no arquivo.\n");
    getchar();
    exit(0);
}

printf("Informe o nome:\n");
scanf("%s", nome);
fflush(stdin);

for (i=strlen(nome); i < 46; i++) {
    nome[i] = '.';
}

nome[46] = '\0';

printf("Digite o ano de nascimento:\n");
scanf("%s", ano);
fflush(stdin);

strcat(nome,ano);

fprintf(file, "%s", nome);
fprintf(file, "\n");

fclose(file);

system("cls");

}

void exibirListagem(void){

char nome[100];
int i,a=0,j,aux=1000;

file = fopen("gravar.txt", "r");

if (file == NULL) {
    printf("Nao foi possivel ler o arquivo.\n");
    getchar();
    exit(0);
}

    while(fgets(nome, 51, file) != NULL) {

        j = 46;
        a=0;
        aux=1000;

            for (i=0; i < 4; i ++) {
                a += (nome[j] - '0') * aux;
                aux = aux / 10;
                j = j + 1;
            }

      printf("%s ", nome);

            if ((2018 - a > 18) && (strlen(nome) == 50)) {
                printf("OK\n");

            } else {
                if (strlen(nome) == 50){
                printf("<18\n");
                }
            }


    }

    fclose(file);

    system("pause");
    system("cls");
}
