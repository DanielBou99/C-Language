#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
UNISANTOS - Ciência da Computação.
Algoritmo II - 2018.
Autor: Daniel Bou de Souza.

Data: 20/11/2018.
*/

/*1) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda, que tipo de música ela toca,
o número de integrantes e em que posição do ranking essa banda está dentre as suas 5 bandas favoritas.
a) Crie uma função para preencher a estrutura  “bandas”. Após criar e preencher a estrutura, persista em um arquivo binário;
b)  Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu programa deve exibir informações da banda cuja posição no seu ranking
é a que foi solicitada pelo usuário e está gravada no arquivo;
c) Crie uma função em C que peça ao usuário um tipo de música e exiba as bandas com esse tipo de música no seu ranking.
d) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está entre suas bandas favoritas ou não.
e) Crie uma função que liste todas as bandas cadastradas no arquivo e ordene pelo ranking (utilize o algoritmo de ordenação de sua preferencia)
f) Crie uma aplicação única em que exibe um menu com as opções de preencher as estruturas e todas as opções das questões passadas e uma opção para
sair do programa;
*/

typedef struct
{

    char nome[20];
    char genero[20];
    int integrantes;
    int rank;

} bandas;

int rank();
void preencherBandas();
void genero();
void pbandas();
void crank();
void ordenar(bandas *, int);

int main()
{

    int c;

    do
    {

        printf("MENU:\n");
        printf("<0> Sair.\n");
        printf("<1> Inclusao das 5 bandas.\n");
        printf("<2> Procurar por rank.\n");
        printf("<3> Procurar por genero.\n");
        printf("<4> Procurar por banda.\n");
        printf("<5> Listar todas as bandas pelo rank.\n");
        scanf("%d", &c);
        fflush(stdin);

        switch(c)
        {
        case 0:
            break;

        case 1:
            preencherBandas();
            system("pause");
            system("cls");
            break;

        case 2:
            rank();
            system("pause");
            system("cls");
            break;

        case 3:
            genero();
            system("pause");
            system("cls");
            break;

        case 4:
            pbandas();
            system("pause");
            system("cls");
            break;

        case 5:
            crank();
            system("pause");
            system("cls");
            break;

        default:
            printf("Opcao invalida.\n");
        }

    }
    while(c != 0);

    return 0;
}

/* ESSA FUNÇÃO NÃO RECEBE ARGUMENTOS */

void preencherBandas()
{

    /* ESSA FUNÇÃO IRA SCANEAR A STRUCT BANDAS 5X
    * E GUARDARA EM UM ARQUIVO BINARIO */


    int i;
    bandas bandas;

    FILE * arq;

    if ((arq = fopen("bandas.bin", "wb")) == NULL)
    {
        printf("Erro: Nao foi possivel abrir o arquivo!\n");
    }
    else
    {

        for (i=0; i<5; i++)
        {

            printf("Banda[%d]: ", i+1);
            scanf("%19[^\n]", bandas.nome);
            fflush(stdin);

            printf("Genero[%d]: ", i+1);
            scanf("%19[^\n]", bandas.genero);
            fflush(stdin);

            printf("Integrantes[%d]: ", i+1);
            scanf("%d", &bandas.integrantes);
            fflush(stdin);

            printf("Rank[%d]: ", i+1);
            scanf("%d", &bandas.rank);
            fflush(stdin);

            fwrite(&bandas, sizeof(bandas), 1, arq);
        }


        fclose(arq);
    }



}


/* ESSA FUNÇÃO NÃO RECEBE ARGUMENTOS */

int rank()
{

    /*ESSA FUNÇÃO IRA PROCURAR NO ARQUIVO BINARIO
    * A TRUCT QUE POSSUI O RANK INFORMADO PELO USUARIO*/

    int look;

    printf("Informe o rank: ");
    scanf("%d", &look);

    bandas bandas;

    FILE *arq;
    if ((arq = fopen("bandas.bin", "rb")) == NULL)
    {
        printf("Erro: Impossivel abrir bandas.bin para leitura.\n");
    }
    else
    {

        while (fread(&bandas, sizeof(bandas), 1, arq) > 0)
        {
            if (look == bandas.rank)
                printf("Banda: %s\nTipo: %s\nIntegrantes: %d\nRank: %d\n",bandas.nome,bandas.genero,bandas.integrantes,bandas.rank);

        }

        fclose(arq);

    }


}

/* ESSA FUNÇÃO NÃO RECEBE ARGUMENTOS */

void genero()
{

    /*ESSA FUNÇÃO IRA PROCURAR NO ARQUIVO BINARIO
    * A TRUCT QUE POSSUI O GENERO INFORMADO PELO USUARIO*/

    char genero[20];
    bandas bandas;

    printf("Genero: ");
    scanf("%19[^\n]", genero);

    FILE *arq;

    if ((arq = fopen("bandas.bin","rb")) == NULL)
    {
        printf("Error: Arquivo bandas.bin nao encontrado.\n");
    }
    else
    {

        while ( (fread(&bandas, sizeof(bandas), 1, arq)) > 0)
        {
            if (strcmp(genero,bandas.genero) == 0 )
                printf("Banda: %s\nTipo: %s\nIntegrantes: %d\nRank: %d\n",bandas.nome,bandas.genero,bandas.integrantes,bandas.rank);
        }

    }

    fclose(arq);

}

/* ESSA FUNÇÃO NÃO RECEBE ARGUMENTOS */

void pbandas()
{

    /*ESSA FUNÇÃO IRA PROCURAR NO ARQUIVO BINARIO
    * A TRUCT QUE POSSUI A BANDA INFORMADA PELO USUARIO*/

    bandas bandas;
    char look[20];
    FILE * arq;

    printf("Nome da banda: ");
    scanf("%19[^\n]", look);
    fflush(stdin);

    if ( (arq = fopen("bandas.bin","rb")) == NULL )
    {
        printf("Error: Nao foi possivel ler o arquivo bandas.bin.\n");
    }
    else
    {

        while ((fread(&bandas, sizeof(bandas), 1, arq)) > 0)
            if (strcmp(bandas.nome,look) == 0)
                printf("Banda: %s\nTipo: %s\nIntegrantes: %d\nRank: %d\n",bandas.nome,bandas.genero,bandas.integrantes,bandas.rank);

    }

    fclose(arq);

}

/*ESSA FUNÇÃO NÃO RECEBE ARGUMENTOS*/

void crank()
{

    /*ESSA FUNÇÃO IRÁ EXIBIR NA TELA TODAS AS STRUCTS
    * SALVAS NO ARQUIVO, EM ORDEM CRESCENTE*/

    bandas banda;

    int i = 0, j = 0,total;
    FILE * arq;

    if ( (arq = fopen("bandas.bin","rb")) == NULL )
    {
        printf("Error: Nao foi possivel ler o arquivo bandas.bin.\n");
    }
    else
    {

        fseek(arq, 0, SEEK_END);
        total = ftell(arq) / sizeof(bandas);

        bandas b[total];

        rewind(arq);

        fread(&b, sizeof(bandas), total, arq);

        ordenar(b, total);

    }

    fclose(arq);

}

/*ESSA FUNÇÃO RECEBE UM VETOR DE STRUCT 'BANDAS' E
*UMA VARIAVEL INT*/

void ordenar(bandas *b, int MAX)
{

    /*ESSA FUNÇÃO TEM POR FINALIDADE EXIBIR O VETOR STRUCT
    *EM ORDEM CRESCENTE, CONSIDERANDO O VALOR DO RANK*/

    int i,j=1;

    while (j <= MAX)
    {

        for (i=0; i < MAX; i++)
        {

            if (j == b[i].rank)
            {
                printf("-------------------------------------------------------\n");
                printf("Banda: %s\nTipo: %s\nIntegrantes: %d\nRank: %d\n",b[i].nome,b[i].genero,b[i].integrantes,b[i].rank);
                j+=1;
            }

        }

    }

    printf("-------------------------------------------------------\n");

}


