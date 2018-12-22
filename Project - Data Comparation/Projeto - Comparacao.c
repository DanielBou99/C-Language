#include <stdio.h>
#include <string.h>

/*
    *
    *Autor: Daniel Bou de Souza.
    *
    *Funcionamento: Esse programa ira verificar se todos os dados
    *do arquivo Primario.txt constam no arquivo Secundario.txt
    *e criara um novo arquivo chamado Resultado.txt que informara
    *os dados não encontrados.
    *
    *Data: 21/12/18.
    *
    *Sistema Operacional testado: Windows 10.
    *
*/




void criararquivos();
void apagartela();
void comparar();

int main()
{

    int c;

    do
    {
        printf("**********MENU**********\n");
        printf("<1> Criar arquivos.\n");
        printf("<2> Comparar arquivos.\n");
        printf("<0> Fechar programa.\n");
        printf(">> ");

        scanf("%d", &c);
        fflush(stdin);

        switch(c)
        {

        case 0:
            break;
        case 1:
            criararquivos();
            break;
        case 2:
            comparar();
            break;
        default:
            printf("Opcao invalida.\n");
        }

        printf("Digite qualquer tecla para continuar.\n");
        getchar();
        fflush(stdin);
        apagartela();
    }
    while (c != 0);




}

void criararquivos()
{

    FILE * arq;

    if ( (arq = fopen("Primario.txt", "w"))  == 0)
    {
        printf("Nao foi possivel criar o arquivo Primario.txt.\n");
    }
    {
        printf("Arquivo Primario.txt criado com sucesso.\n");
    }

    fclose(arq);

    if ( (arq = fopen("Secundario.txt", "w"))  == 0)
    {
        printf("Nao foi possivel criar o arquivo Secundario.txt.\n");
    }
    {
        printf("Arquivo Secundario.txt criado com sucesso.\n");
    }

    fclose(arq);

}

void apagartela()
{

    int i;

    for (i=0; i<60; i++)
        printf("*");
    printf("\n");

    for (i=0; i < 10; i++)
        printf("\n");


}

void comparar()
{

    FILE * arq;
    char container[100];
    int kp=0,i=0,ks=0,j,c,total=0;

    printf("Funcionamento: O programa ira comparar se todos os containers\ndo arquivo 'Primario.txt' constam no arquivo 'Secundario.txt'\n");
    printf("Digite qualquer tecla para comecar a comparacao.\n");
    getchar();
    fflush(stdin);

    /*LER TODOS OS CONTAINERS DO ARQUIVO PRIMARIO*/
    if ( (arq = fopen("Primario.txt","r")) == 0)
    {
        printf("Nao foi possivel ler o arquivo Primario.txt.\n");

    }

    while(fgets(container,100,arq) != NULL)
    {
        kp +=1;
    }

    char primario[kp][20];

    rewind(arq);

    i=0;

    while(fgets(container,100,arq) != NULL)
    {
        strcpy(primario[i],container);
        i += 1;
    }
    fclose(arq);

    /*LER TODOS OS CONTAINERS DO ARQUIVO SECUNDARIO*/
    if ( (arq = fopen("Secundario.txt","r")) == 0)
    {
        printf("Nao foi possivel ler o arquivo Secundario.txt.\n");

    }

    while(fgets(container,100,arq) != NULL)
    {
        ks +=1;
    }

    char secundario[ks][20];

    rewind(arq);

    i=0;

    while(fgets(container,100,arq) != NULL)
    {
        strcpy(secundario[i],container);
        i += 1;
    }
    fclose(arq);

    /*COMPARAR OS ARQUIVOS E CRIAR UM NOVO ARQUIVO COM OS CONTAINERS NAO ENCONTRADOS*/
    if ( (arq = fopen("Resultado.txt","w")) == 0)
    {
        printf("Nao foi possivel criar o arquivo Resultado.txt.\n");
    }
    fclose(arq);

    if ( (arq = fopen("Resultado.txt","a+")) == 0)
    {
        printf("Nao foi possivel ler o arquivo Resultado.txt.\n");
    }

    for (i=0; i < kp; i++)
    {
        c = 0;
        for (j=0; j < ks; j++)
        {
            if (strcmp(primario[i],secundario[j]) == 0)
            {
                c = 1;
            }
        }
        if (c==0)
        {
            fprintf(arq, "%s", primario[i]);
            total+=1;
        }
    }

    printf("Total de containers nao encontrados: %d.\n", total);

    fclose(arq);

}
