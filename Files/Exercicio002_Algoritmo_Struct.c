#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
UNISANTOS - Ciência da Computação.
Algoritmo II - 2018.
Autor: Daniel Bou de Souza.

Data: 21/11/2018.
*/

/*
2) Seja um sistema destinado a controlar despesas e dados de um condomínio de apartamentos. 
Os dados de cada apartamento são armazenados em um vetor de estruturas. Para cada apartamento tem-se os seguintes dados: 
•	nome (do responsável) 
•	número (do apartamento) 
•	área (em m2 ) 
•	número de moradores 
•	valor (a ser pago no mês) 

a)	Definir a estrutura acima e considere que os dados devem ser gravados em arquivo binário;
b)	Declarar um vetor de estruturas (global), suponde que o condomínio tem 40 apartamentos. 
c)	Crie um menu para:
d)	 Escrever um bloco de instruções responsável por ler o vetor acima, exceto o campo valor. 
e)	Escrever um bloco de instruções que retorne a área total do condomínio. 
f)	Escrever um bloco de instruções que receba a área total do condomínio; leia o total de despesas 
do mesmo e calcule para cada apartamento o valor a ser pago no mês. Esse valor é proporcional à área do apartamento. 
g)	Fazer um bloco de instruções para imprimir os dados do apartamento que tem o maior número de moradores. 
Em caso de haver mais de um, imprimir todos. 
h)	Escrever um bloco de instruções para listar em ordem decrescente os aptos com maior condomínio;
i)	Escrever um bloco de instruções para sair do programa.
*/

typedef struct
{

    char nome[51];
    int numero;
    int area;
    int moradores;
    float valor;

} informacoes;

#define MAX 40
informacoes condominio[MAX];

void pontos();
void cadastrar();
void guardar();
void ler();
int areatotal();
void valorDoCondominio();
void maiorNumeroDeMoradores();
void decrescentecondominio();

int main()
{

    int c;

    do
    {

        pontos();
        printf("<0> Sair.\n");
        printf("<1> Cadastrar %d apartamentos.\n", MAX);
        printf("<2> Calcular o valor do condominio de cada apartamento.\n");
        printf("<3> Listar os apartamentos com maior numero de moradores.\n");
        printf("<4> Listar em ordem decrescente os apartamentos com maior condominio.\n");
        scanf("%d", &c);
        fflush(stdin);

        switch(c)
        {

        case 0:
            break;

        case 1:
            cadastrar();
            system("pause");
            system("cls");
            break;

        case 2:
            valorDoCondominio();
            system("pause");
            system("cls");
            break;

        case 3:
            maiorNumeroDeMoradores();
            system("pause");
            system("cls");
            break;

        case 4:
            decrescentecondominio();
            system("pause");
            system("cls");
            break;

        default:
            printf("Opcao nao existe.\n");
            system("pause");
            system("cls");
            break;

        }

    }
    while (c != 0);


}


void pontos()
{
    /*FUNCTION TO PRINT DASHES*/

    printf("-----------------------------\n");

}

void cadastrar()
{
    /*FUNCTION TO SCAN STRUCT GLOBAL CONDOMINIO (EXCEPT VALOR)*/

    int i;

    for (i=0; i < MAX; i ++)
    {

        pontos();
        printf("APARTAMENTO %d\n", i+1);
        printf("Nome do responsavel: ");
        scanf("%50[^\n]", condominio[i].nome);
        fflush(stdin);
        printf("Numero do apartamento: ");
        scanf("%d", &condominio[i].numero);
        fflush(stdin);
        printf("Area (em m2): ");
        scanf("%d", &condominio[i].area);
        fflush(stdin);
        printf("Numero de moradores: ");
        scanf("%d", &condominio[i].moradores);
        fflush(stdin);
    }
    pontos();

    guardar();

}

void guardar()
{
    /*FUNCTION TO SAVE GLOBAL STRUCT CONDOMINIO IN FILE "INFOS.BIN"*/

    FILE * arq;

    if ( (arq = fopen("infos.bin", "wb")) == NULL)
    {

        printf("Erro: Impossivel criar ou escrever no arquivo infos.bin.\n");

    }
    else
    {

        fwrite(condominio, sizeof(informacoes), MAX, arq);

        fclose(arq);
    }

}

void ler()
{
    /*FUNCTION TO READ FILE "INFOS.BIN" AND SAVE IN GLOBAL STRUCT CONDOMINIOS*/

    FILE * arq;

    if ((arq = fopen("infos.bin", "rb")) == NULL)
    {
        printf("Erro: Impossivel ler o arquivo infos.bin.\n");
    }
    else
    {

        fread(&condominio, sizeof(informacoes), MAX, arq);
        fclose(arq);
    }

}

int areatotal()
{
    /*FUNCTION THAT RETURNS THE SUM OF ALL VARIABLE AREA FROM
    *STRUCT GLOBAL ARRAY CONDOMINIO*/

    ler();

    int i,total=0;
    for (i=0; i < MAX; i++)
        total += condominio[i].area;

    return total;

}

void valorDoCondominio()
{
    /*FUNCTION THAT SHOWS HOW MUCH FEE THE APARTMENTS MUST PAY*/

    float TotalDeDespesa,ValorPorM2;
    int i;

    printf("Total de despesa: ");
    scanf("%f", &TotalDeDespesa);
    TotalDeDespesa = TotalDeDespesa * 1.0;
    fflush(stdin);

    ValorPorM2 = TotalDeDespesa / areatotal();

    for (i=0; i < MAX; i++)
    {
        pontos();
        printf("Nome: %s.\n", condominio[i].nome);
        printf("Numero do apartamento: %d.\n", condominio[i].numero);
        printf("Area em m2: %d\n", condominio[i].area);
        condominio[i].valor = condominio[i].area * ValorPorM2;
        printf("Valor do condominio: R$%.2f\n", condominio[i].valor);
    }
    pontos();

    guardar();
}

void maiorNumeroDeMoradores()
{
    /*FUNCTION THAT SHOWS THE APARTMENTS WITH MORE RESIDENTS*/

    int maior,i;

    ler();

    maior = condominio[0].moradores;

    for (i=1; i < MAX; i++)
    {
        if (condominio[i].moradores > maior)
            maior = condominio[i].moradores;
    }

    for (i=0; i < MAX; i++)
    {
        if (maior == condominio[i].moradores)
        {
            pontos();
            printf("Numero de moradores: %d\n", condominio[i].moradores);
            printf("Nome: %s.\n", condominio[i].nome);
            printf("Numero do apartamento: %d.\n", condominio[i].numero);
            printf("Area em m2: %d\n", condominio[i].area);
        }
    }
    pontos();
}

void decrescentecondominio()
{
    /*FUNCTION THAT SHOWS ALL APARTMENTS IN DESCENDING ORDER CONSIDERING VARIABLE
    *"VALOR" FROM GLOBAL STRUCT CONDOMINIO.*/

    ler();

    informacoes aux;
    char c;
    int i;


    do
    {
        c = 's';

        for (i=0; i < MAX-1; i++)
        {
            if (condominio[i].valor < condominio[i+1].valor)
            {
                aux = condominio[i];
                condominio[i] = condominio[i+1];
                condominio[i+1] = aux;
                c = 'c';
            }
        }


    }
    while(c=='c');

    for (i=0; i < MAX; i++)
    {
        pontos();
        printf("Valor do condominio: R$ %.2f.\n", condominio[i].valor);
        printf("Nome do responsavel: %s.\n", condominio[i].nome);
        printf("Numero do apartamento: %d.\n", condominio[i].numero);
        printf("Area em m2: %d.\n", condominio[i].area);
        printf("Numero de moradores: %d.\n", condominio[i].moradores);
    }

    pontos();

}
