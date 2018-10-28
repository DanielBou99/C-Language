#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*Considere   que   exista   uma   estrutura   com   os   seguintes   membros:  codigo_cliente  e
nome_cliente  e   uma   outra   estrutura   com   os   seguintes   membros:  num_compra,
valor_compra, codigo_cliente. Faça um programa que:
a) Inclua clientes, não permitindo que dois clientes possuam o mesmo código;
b) Inclua compras, verificando se o código do cliente informado já está cadastrado. Caso
não esteja, não permita a inclusão. O número da compra deve ser um número sequencial
gerado pelo programa;
c) Liste todos os clientes cadastrados;
d) Liste todas as compras de um determinado cliente, dado seu código;
e) Remova um determinado cliente. Antes de executar a remoção, verifique se o cliente
possui alguma compra. Se possuir, mostrar a mensagem “Exclusão não permitida”. Caso
contrário, proceder a exclusão.*/

struct usuario {

    int codigo_cliente;
    char nome_cliente[50];

};

struct acoes {

    int num_compra;
    float valor_compra;
    int codigo_cliente;

};

void inclua_clientes(int*, struct usuario[]);
void inclua_compras(int*, int*, int*, struct usuario[], struct acoes[]);
void listar_clientes(int *, struct usuario[]);
void listar_compras(int*,int*,struct usuario[],struct acoes[]);
int remover_cliente(int*,int*,struct usuario[],struct acoes[]);
void pontos();

int main() {

struct usuario usuario[10];
struct acoes acoes[10];


int i=0, c, codigo_compra = 1, ia = 0;

do {

    pontos();
    printf("\n\tMENU\n\n");
    printf("0 - Sair.\n");
    printf("1 - Incluir cliente.\n");
    printf("2 - Incluir compras.\n");
    printf("3 - Listar clientes cadastrados.\n");
    printf("4 - Listar compras de um determinado cliente.\n");
    printf("5 - Remover cliente.\n");
    pontos();
    scanf("%d", &c);

    switch(c){

        case 0:
            system("cls");
            printf("Finalizado!\n");
            system("pause");
            break;
        case 1:
            system("cls");
            inclua_clientes(&i, usuario);
            system("cls");
            break;
        case 2:
            system("cls");
            inclua_compras(&ia,&codigo_compra,&i, usuario, acoes);
            system("cls");
            break;
        case 3:
            system("cls");
            listar_clientes(&i, usuario);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            listar_compras(&ia,&i,usuario,acoes);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            remover_cliente(&ia,&i,usuario,acoes);
            system("pause");
            system("cls");
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            system("pause");
            system("cls");
    }



}   while (c != 0);






    return 0;
}


void pontos() {
    /* funcao que imprime "underlines" para o menu*/

    int i;

    for (i=0; i < 51; i++) {
        printf("_");
    }

    printf("\n");

}

/* FUNCAO QUE RECEBE UM PONTEIRO INT, UM VETOR DE STRUCT
* E DEPENDENDO DA SITUACAO SOMA +1 NO PONTEIRO INT*/
void inclua_clientes(int *i, struct usuario usuario[]) {

/* SE O CLIENTE NAO FOR CADASTRADO, SERA SOMADO +1 NO
* PONTEIRO INT E ACRESCENTA INFORMACOES NO VETOR STRUCT USUARIO[I] */

int codigo,j;
char nome[50],c='c';



if (*i < 10) {

do {

    c='c';
    printf("\t CADASTRO DE CLIENTE\n\n");
    printf("Codigo do cliente:\n");
    scanf("%d", &codigo);
    fflush(stdin);

    /*VERIFICAR SE O CLIENTE JA EXISTE*/
    for (j=0; j < *i; j++) {
        if (codigo ==  usuario[j].codigo_cliente) {
            printf("\n***ERROR: Codigo ja cadastrado.\n\n");
            c = 's';
            break;
        }
    }

} while (c=='s');

    printf("Nome do cliente:\n");
    scanf("%49[^\n]", nome);
    fflush(stdin);

strcpy(usuario[*i].nome_cliente, nome);
usuario[*i].codigo_cliente = codigo;
*i += 1;

} else{
    printf("\nENTRE EM CONTATO COM O ADMINISTRADOR!\nNUMERO MAXIMO DE CLIENTES EXCEDIDO\n");
}

}


/* FUNCAO QUE RECEBE UM PONTEIRO INT, E DUAS STRUCTS*/

void inclua_compras(int * ia,int *codigo_compra,int *i, struct usuario usuario[], struct acoes acoes[]) {

/* FUNCAO QUE ACRESCENTA INFORMACOES NO VETOR STRUCT ACOES[I] */

char c;
int j,codigo;
float valor;

if (*i < 10) {

do {

    c='s';
    printf("INCLUIR COMPRAS\n\n");
    printf("Codigo do cliente:\n");
    scanf("%d", &codigo);
    fflush(stdin);

    /*VERIFICAR SE O CLIENTE JA EXISTE*/
    for (j=0; j < *i; j++) {
        if (codigo ==  usuario[j].codigo_cliente) {

            system("cls");
            pontos();
            printf("\nCliente = %s\n", usuario[j].nome_cliente);
            printf("Codigo = %d\n", usuario[j].codigo_cliente);
            pontos();

            printf("Valor da compra: ");
            scanf("%f", &valor);

            acoes[*ia].num_compra = *codigo_compra;
            acoes[*ia].valor_compra = valor;
            acoes[*ia].codigo_cliente = codigo;

            *codigo_compra += 1;
            *ia += 1;
            system("pause");
            c = 'c';
            break;
        }
    }

    if (c=='s') {
        printf("\nERROR: CODIGO NAO ENCONTRADO\n\n");
        system("pause");
        break;
    }

} while (c=='s');

} else {

    printf("\n\nERROR: Numero de compras excedido.\n Contate o Administrador.\n");
        system("pause");
}



}


/*LISTAR TODOS OS CLIENTES CADASTRADOS
* FUNCAO RECEBE UM PONTEIRO INTEIRO E UM VETOR STRUCT*/

void listar_clientes(int * i, struct usuario usuario[]) {

int j;

if (*i == 0) {
    printf("Nenhum cliente cadastrado.\n");
    system("pause");
} else {
printf("\tLISTA DE CLIENTES\n");
pontos();
    for (j=0; j < *i; j++) {
        printf("\tCodigo: %d\n", usuario[j].codigo_cliente);
        printf("\tNome: %s\n", usuario[j].nome_cliente);
        pontos();
    }
}

}

/*FUNCAO QUE RECEBE DOIS PONTEIROS INTEIROS
* E DOIS VETORES STRUCT*/

void listar_compras(int *ia,int *i,struct usuario usuario[],struct acoes acoes[]) {

/*A FUNCAO NAO ALTERA NENHUMA INFORMACAO DAS VARIAVEIS. APENAS PRINTA NA TELA AS COMPRAS DE UM CLIENTE.*/

int j,j2,codigo;
char c='c';

if (*i == 0) {
    printf("Nenhum cliente cadastrado.\n");
    system("pause");
} else {

    printf("Informe o codigo do cliente: ");
    scanf("%d", &codigo);

    for (j=0; j < *i; j++) {

        if (codigo == usuario[j].codigo_cliente) {
            system("cls");
            printf("\tLISTA DE COMPRAS\n");
            printf("\tCliente: %s\n", usuario[j].nome_cliente);
            printf("\tCodigo: %d\n", usuario[j].codigo_cliente);
            pontos();

                for (j2=0; j2 < *ia; j2++) {
                    if (codigo == acoes[j2].codigo_cliente) {
                        printf("Codigo da compra: %d\n", acoes[j2].num_compra);
                        printf("Valor da compra: %.2f\n", acoes[j2].valor_compra);
                        pontos();
                    }
                }

        }

    }

}



}


/*FUNCAO QUE RECEBE 2 PONTEIROS INTEIRO E 2 VETORES STRUCT*/


int remover_cliente(int *ia,int *i,struct usuario usuario[],struct acoes acoes[]) {

/*A FUNCAO IRA REMOVER UM USUARIO CASO O MESMO NAO TENHA COMPRAS EM SEU CADASTRO*/

int codigo,j,j2;

if (*i == 0) {
    printf("Nenhum cliente cadastrado.\n");
    return 0;
} else {

    printf("Informe o codigo do cliente: ");
    scanf("%d", &codigo);

    for (j=0; j < *i; j++) {

        if (codigo == usuario[j].codigo_cliente) {

            for (j2=0; j2 < *ia; j2++) {
                if (codigo == acoes[j2].codigo_cliente) {
                    printf("\nO cliente nao pode ser removido.\n");
                    return 1;
                }
            }

            usuario[j].codigo_cliente = usuario[*i-1].codigo_cliente;
            strcpy(usuario[j].nome_cliente, usuario[*i-1].nome_cliente);
            *i -=1;

            return 2;

        }
    }




}

printf("Codigo nao existe.\n");
return 3;




}
