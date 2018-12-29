#include <stdio.h>
#include <string.h>

/*
*
* main.c
*
* Esse projeto foi desenvolvido com o intuito de automatizar a
* tarefa de fechamento de caixa no meu emprego atual.
*
* Sistemas operacionais testados: Windows 10 / Windows 7.
*
* Autor: Daniel Bou de Souza.
* 29/12/2018.
*
*/

int criarArquivos();
int juntar();

int main()
{

    int c;

    do
    {

        printf("<0> Sair.\n");
        printf("<1> Criar arquivo.\n");
        printf("<2> Juntar valores.\n");
        printf("<3> Funcionalidade do programa.\n");
        scanf("%d", &c);
        fflush(stdin);

        switch (c)
        {

        case 0:
            break;
        case 1:
            criarArquivos();
            break;
        case 2:
            juntar();
            break;
        case 3:
            printf("-------------------------------------------------------------------\n");
            printf("Funcionalidade: Esse programa ira somar valores que estao atrelados\n");
            printf("a mesma referencia e criara dois arquivos contendo os resultados.\n");
            printf("Exemplo:\n");
            printf("    *****ENTRADA*****\n");
            printf("    A = 3\n");
            printf("    B = 4\n");
            printf("    A = 2\n");
            printf("    C = 2\n");
            printf("    *****RESULTADO*****\n");
            printf("    A = 5\n");
            printf("    B = 4\n");
            printf("    C = 2\n");
            printf("    *******************\n");
            printf("Explicacao: Note que o programa somou os valores atrelados a 'A'\n");
            printf("e unificou em apenas uma variavel 'A'.\n");
            printf("-------------------------------------------------------------------\n\n");
            break;
        default:
            printf("Opcao nao existe.\n");
            break;
        }
        printf("Digite qualquer tecla para continuar.\n");
        getchar();
        fflush(stdin);
        printf("-------------------------------------------------------------------\n");
    }
    while (c != 0);

    return 0;

}

int criarArquivos()
{

    FILE * arq;

    if ((arq = fopen("primario.txt","w")) == NULL )
    {
        printf("Error: Nao foi possivel criar o arquivo primario.txt.\n");
    }
    else
    {
        printf("Arquivo primario.txt criado com sucesso.\n");
    }
    fclose(arq);

}

int juntar()
{

    FILE * arq;
    int klinhas=0;
    char aux[100];

    if ((arq = fopen("primario.txt", "r")) == NULL)
    {
        printf("Error: Nao foi possivel ler o arquivo primario.txt.\n");
    }
    else
    {

        while(fgets(aux,100,arq) != NULL)
        {
            klinhas +=1;
        }

        int valores[klinhas], resultadoValores[klinhas],i=0,j=0, finalValores[klinhas];
        char containers[klinhas][100], resultadoContainers[klinhas][100], finalContainers[klinhas][100];

        rewind(arq);

        for (i=0; i < klinhas; i++)
        {
            fscanf(arq, "%s %d", containers[i], &valores[i]);
        }

        fclose(arq);

        for (i=0; i < klinhas; i++)
        {

            strcpy(resultadoContainers[i], containers[i]);
            resultadoValores[i] = 0;

            for (j=0; j < klinhas; j++)
            {
                if ( (strcmp(resultadoContainers[i],containers[j])) == 0)
                {
                    resultadoValores[i] += valores[j];
                }
            }
        }

        int MAX = 0,kfinal=0;
        char c;

        for (i=0; i < klinhas; i++)
        {

            if ( ((strcmp(resultadoContainers[i],"---")) == 0) )
            {
            }
            else
            {
                strcpy(finalContainers[kfinal], resultadoContainers[i]);
                finalValores[kfinal] = resultadoValores[i];
                MAX +=1;

                for (j=0; j < klinhas; j++)
                {
                    if ( (strcmp(finalContainers[kfinal], resultadoContainers[j])) == 0 )
                    {
                        strcpy(resultadoContainers[j], "---");
                    }
                }

                kfinal +=1;

            }

        }


        if ( ( arq = fopen("resultadoBls.txt","w")) == NULL )
        {
            printf("Nao foi possivel escrever no arquivo resultadoBls.txt.\n");
        }
        else
        {
            for (i=0; i < MAX; i++)
            {
                fprintf(arq, "%s\n", finalContainers[i]);
            }
            fclose(arq);

            if ( ( arq = fopen("resultadoValores.txt","w")) == NULL )
            {
                printf("Nao foi possivel escrever no arquivo resultadoValores.txt.\n");
            }
            else
            {
                for (i=0; i < MAX; i++)
                {
                    fprintf(arq, "%d\n", finalValores[i]);
                }
                fclose(arq);

                printf("Resultado impresso nos arquivos resultadoBls.txt e resultadoValores.txt.\n");
            }
        }

    }
}
