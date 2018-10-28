#include <stdio.h>
#include <string.h>

void MenuAdm();
void CriarConta(FILE* Arquivo);
void pontos();
void HabilitarSaldo();
void LogInAdm();

int main() {

int o;

do {
    pontos();
    printf("Bem-vindo ao Sistema Internet Banking do 'Bou Bank'\n\n");
    printf("Opcoes: \n\n");
    printf("0 - Sair\n");
    printf("9 - Administrador\n");
    pontos();
    printf("\nInforme a opcao desejada:\n>>>>");
    scanf("%d", &o);

    switch(o) {
        case 0:
            break;
        case 9:
            system("cls");
            MenuAdm();
            system("cls");
            break;
    }


} while(o != 0);



    return 0;
}

    /*funcao que mostra o menu para o administrador*/

void MenuAdm() {

    FILE * Arquivo;

    int o;

    do {
    pontos();
    printf("****AREA RESTRITA AO ADMINISTRADOR****\n\n");
    printf("Opcoes:\n\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("1 - Criar nova conta Administradora\n");
    printf("2 - Criar nova conta Usuario\n");
    printf("3 - Habilitar saldo para conta Usuario\n");
    pontos();

    printf("\nInforme a opcao desejada:\n>>>>");
    scanf("%d", &o);

    switch(o) {
        case 0:
            break;
        case 1:
            system("cls");
         
            Arquivo = fopen("ContaAdm.txt","w");

            if (Arquivo == NULL) {
                printf("Nao foi possivel abrir o arquivo ContaAdm!\n");
            }

            CriarConta(Arquivo);
            system("cls");
        break;

        case 2:
            system("cls");

            Arquivo = fopen("ContaUser.txt","a");

            if (Arquivo == NULL) {
                printf("Nao foi possivel abrir o arquivo User!\n");
            }

            CriarConta(Arquivo);
            system("cls");
            break;
        case 3:
            system("cls");
            HabilitarSaldo();
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcao invalida!\n");
            system("pause");
            system("cls");
    }

    } while(o != 0);

}

void CriarConta(FILE *Arquivo) {

char usuario[100],senha[100],c;
int i;

do {

c = 's';
/* SCANEAR O USUARIO */
    printf("Informe o usuario: \n(Minimo 6 caracteres e Maximo 10 caracteres e nao pode conter o simbolo %%)\n>>>>");
    scanf("%s", usuario);
    fflush(stdin);

    if ((strlen(usuario) > 10) || (strlen(usuario) < 6)) {
        c = 'c';
        printf("\n\n****ERROR: QUANTIDADE DE CARACTERES****\n");
        system("pause");
        system("cls");
    } else {
    for (i=0; usuario[i] != '\0'; i++) {
        if (usuario[i] == '%') {
            c = 'c';
            printf("****ERROR: CARACTERE INVALIDO****\n");
            system("pause");
            system("cls");
            i = strlen(usuario);
        }
    }

    }

} while(c == 'c');

printf("\n");

/* SCANEAR A SENHA */

do {

c = 's';

    printf("Informe a senha: \n(Minimo 6 caracteres e Maximo 10 caracteres e nao pode conter o simbolo %%)\n>>>>");
    scanf("%s", senha);
    fflush(stdin);

    if ((strlen(senha) > 10) || (strlen(senha) < 6)) {
        c = 'c';
        printf("\n\n****ERROR: QUANTIDADE DE CARACTERES****\n");
        system("pause");
        system("cls");
    } else {
    for (i=0; senha[i] != '\0'; i++) {
        if (senha[i] == '%') {
            c = 'c';
            printf("****ERROR: CARACTERE INVALIDO****\n");
            system("pause");
            system("cls");
            i = strlen(senha);
        }
    }

    }

} while(c == 'c');

/* Gravar no arquivo*/

char aux[100];

strcpy(aux, usuario);

if (strlen(aux) != 10) {

        for (i=strlen(aux); i < 10; i++ ) {
            aux[i] = '.';
        }

        aux[i+1] = '\0';
}

strcat(aux, senha);

fprintf(Arquivo, "%s\n", aux);

fclose(Arquivo);

system("pause");

}

void pontos() {
    /* funcao que imprime "underlines" para o menu*/

    int i;

    for (i=0; i < 51; i++) {
        printf("_");
    }

    printf("\n");

}

void HabilitarSaldo() {

LogInAdm();



}

void LogInAdm() {

char usuario[100],senha[100],c;
int i;

do {

c = 's';
/* SCANEAR O USUARIO */
    printf("Informe o usuario: \n(Minimo 6 caracteres e Maximo 10 caracteres e nao pode conter o simbolo %%)\n>>>>");
    scanf("%s", usuario);
    fflush(stdin);

    if ((strlen(usuario) > 10) || (strlen(usuario) < 6)) {
        c = 'c';
        printf("\n\n****ERROR: QUANTIDADE DE CARACTERES****\n");
        system("pause");
        system("cls");
    } else {
    for (i=0; usuario[i] != '\0'; i++) {
        if (usuario[i] == '%') {
            c = 'c';
            printf("****ERROR: CARACTERE INVALIDO****\n");
            system("pause");
            system("cls");
            i = strlen(usuario);
        }
    }

    }

} while(c == 'c');

printf("\n");

/* SCANEAR A SENHA */

do {

c = 's';

    printf("Informe a senha: \n(Minimo 6 caracteres e Maximo 10 caracteres e nao pode conter o simbolo %%)\n>>>>");
    scanf("%s", senha);
    fflush(stdin);

    if ((strlen(senha) > 10) || (strlen(senha) < 6)) {
        c = 'c';
        printf("\n\n****ERROR: QUANTIDADE DE CARACTERES****\n");
        system("pause");
        system("cls");
    } else {
    for (i=0; senha[i] != '\0'; i++) {
        if (senha[i] == '%') {
            c = 'c';
            printf("****ERROR: CARACTERE INVALIDO****\n");
            system("pause");
            system("cls");
            i = strlen(senha);
        }
    }

    }

} while(c == 'c');

char aux[100];

strcpy(aux, usuario);

if (strlen(aux) != 10) {

        for (i=strlen(aux); i < 10; i++ ) {
            aux[i] = '.';
        }

        aux[i] = '\0';
}

strcat(aux, senha);

printf("RESULTADO = %s\n", aux);




}
