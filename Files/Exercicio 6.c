#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void criar(FILE * matriz, FILE * senha);
void girar(FILE *matriz, FILE * senha);

int main() {

int controle ;

FILE *matriz;
FILE *senha;

do {
printf("Menu: \n");
printf("0 - Sair\n");
printf("1 - Criar\n");
printf("2 - Girar\n");
scanf("%d", &controle);
fflush(stdin);

    switch (controle) {

        case 0:
        break;

        case 1:
        criar(matriz,senha);
        break;

        case 2:
        girar(matriz,senha);
        break;

        default:
        printf("Opcao invalida.\n");
    }

} while (controle != 0);


    return 0;
}

void criar(FILE * matriz, FILE * senha){

matriz = fopen("matriz","wb");
senha = fopen("pwd", "wb");

if (matriz == NULL) {
    printf("O arquivo nao pode ser aberto\n");
    exit(0);
}
if (senha == NULL) {
    printf("O arquivo nao pode ser aberto\n");
    exit(0);
}

int m[2][2], i, j;

printf("Informe os numeros da matriz 2x2:\n");

for (i=0; i < 2; i++) {
    for (j=0; j < 2; j ++) {
        scanf("%d", &m[i][j]);
        fprintf(matriz, "%d ", m[i][j]);
    }
}
fflush(stdin);

char s[9];

printf("Digite a senha do arquivo:");

scanf("%9[^\n]", s);
fflush(stdin);
fprintf(senha, "%s", s);

fclose(matriz);
fclose(senha);

}

void girar(FILE *matriz, FILE * senha) {

matriz = fopen("matriz","rb");
senha = fopen("pwd", "rb");

if (matriz == NULL) {
    printf("O arquivo nao pode ser aberto\n");
    exit(0);
}
if (senha == NULL) {
    printf("O arquivo nao pode ser aberto\n");
    exit(0);
}


int m[2][2],i,j,mn[2][2];
char s[9],sarquivo[9];

fscanf(senha, "%s", sarquivo);

fscanf(matriz, "%d %d %d %d", &m[0][0], &m[0][1], &m[1][0], &m[1][1]);

printf("Digite a senha do arquivo: ");
scanf("%8[^\n]", s);
fflush(stdin);

if (strcmp(s,sarquivo) == 0) {

printf("Matriz antiga: \n");
for (i=0; i < 2; i++) {
    for (j=0; j < 2; j++) {
        printf("%d ", m[i][j]);
    }
    printf("\n");
}

mn[0][0] = m[1][0];
mn[0][1] = m[0][0];
mn[1][0] = m[1][1];
mn[1][1] = m[0][1];

printf("Matriz nova: \n");
for (i=0; i < 2; i++) {
    for (j=0; j < 2; j++) {
        printf("%d ", mn[i][j]);
    }
    printf("\n");
}

fclose(matriz);

matriz = fopen("matriz", "wb");

if (matriz == NULL) {
    printf("Nao foi possivel abrir o arquivo.\n");
    exit(0);
}

fprintf(matriz,"%d %d %d %d", mn[0][0],mn[0][1], mn[1][0], mn[1][1]);



} else{
printf("Senha invalida.\n");
}

fclose(senha);
fclose(matriz);
}
