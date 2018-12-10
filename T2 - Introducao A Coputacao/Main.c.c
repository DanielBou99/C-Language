#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/* Main.c
*
* Programa para fazer o levantamento de preços
* de produtos em diferentes lojas.
*
* Sistema Operacional: Linux
*
* Daniel Bou de Souza (Ciência da Computação)
* Mauricio Freire (Sistema de Informação)
*
* Disciplina: Introdução  à Computação ­II
*
* 04/12/2018
*/

/*
O sistema deve possuir as seguintes funcionalidades, todas elas implementadas através
de funções:
a) Cadastrar produtos: através dessa opção é possível cadastrar um ou mais produtos. A
chave primária da tabela onde os produtos serão cadastrados é o código do produto
(membro cod da estrutura tproduto) que é um número sequencial gerado
automaticamente, sendo assim, o código do primeiro produto será igual a 1, o do
segundo igual a 2, e assim por diante. Os produtos possuem apenas uma descrição
(membro descricao da estrutura tproduto);
b) Alterar um produto: através dessa opção o usuário pode alterar a descrição de um
produto, dado seu código. O sistema deverá solicitar o código do produto a ser
alterado, mostrar sua descrição atual e solicitar a nova descrição do produto. Se o
código informado pelo usuário for inválido, mostrar uma mensagem de erro;
c) Listar os produtos cadastrados: através dessa opção o usuário obtém uma listagem em
formato de tabela contendo o código e a descrição dos produtos cadastrados. Essa
listagem deverá estar ordenada em ordem alfabética ascendente pela descrição do
produto;
d) Cadastrar lojas: através dessa opção o usuário pode cadastrar uma ou mais lojas. A
chave primária da tabela onde as lojas serão cadastrados é o código da loja (membro
cod da estrutura tloja) que é um número sequencial gerado automaticamente, sendo
assim, o código da primeira loja será igual a 1, o da segunda igual a 2, e assim por
diante. As lojas possuem um nome e site (membros nome e site, respectivamente, da
estrutura tloja);
e) Listar as lojas cadastradas: através dessa opção o usuário obtém uma listagem em
formato de tabela contendo o código, nome e site das lojas cadastradas. Essa listagem
deverá estar ordenada em ordem alfabética ascendente pelo nome da loja;
f) Cadastrar preços: através desta opção o usuário poderá cadastrar o preço de um
produto em uma ou mais lojas. O sistema deverá solicitar o código do produto, o
código de uma ou mais lojas e cadastrar o preço do produto nessas lojas (membros
cod_produto, cod_loja e preco da estrutura tpreco, respectivamente). Se o código do
produto ou o código da loja forem inválidos, o sistema deverá exibir uma mensagem
de erro. Não deve ser permitido cadastrar o preço de um produto na mesma loja mais
de uma vez;
g) Listar preços cadastrados: através dessa opção o usuário obtém uma listagem em
formato de tabela contendo o nome do produto, o nome da loja e preço do produto de
todos os preços cadastrados. Essa listagem deverá estar ordenada em ordem alfabética
ascendente pelo nome da loja e pelo preço do produto em ordem descendente;
h) Consultar o preço de um produto: através dessa opção o usuário poderá consultar os
preços de um produto. O sistema deverá solicitar o código de um produto, mostrar seu
nome e o preço desse produto em todas as lojas onde ele foi cadastrado. Se o código
do produto for inválido ou seu preço não foi cadastrado, exibir uma mensagem.
*/

typedef struct
{
    int cod;
    char descricao[51];
} tproduto;
typedef struct
{
    int cod;
    char nome[41];
    char site[81];
} tloja;
typedef struct
{
    int cod_produto;
    int cod_loja;
    float preco;
} tpreco;
typedef struct
{
    char produto[51];
    char loja[41];
    float preco;
} tlista;

#define aproduto "produtos.bin"
#define aloja "lojas.bin"
#define apreco "precos.bin"

void cadastrarProdutos();
void alterarProdutos();
void listarProdutos();
void ordenarProdutoDescricao(tproduto[],int);
void cadastrarLoja();
void listarLojas();
void ordenarLojaNome(tloja[], int);
int cadastrarPrecos();
bool validarPreco(int);
bool validarLoja(int);
bool validarPreco2(tpreco);
int listarPrecos();
void ordenarLista(tlista[], int);
void consultarproduto();

int main()
{

    int c;

    do
    {
        setbuf(stdin,NULL);
        printf("\e[H\e[2J");
        printf("<0> Sair.\n");
        printf("<1> Cadastrar produto.\n");
        printf("<2> Alterar produto.\n");
        printf("<3> Listar produtos.\n");
        printf("<4> Cadastrar loja.\n");
        printf("<5> Listar lojas.\n");
        printf("<6> Cadastrar preços.\n");
        printf("<7> Listar preços.\n");
        printf("<8> Consultar produto.\n");
        printf(">>>");
        scanf("%d", &c);
        printf("\e[H\e[2J");
        setbuf(stdin,NULL);
        switch(c)
        {

        case 0:
            printf("Programa finalizado.\n");
            break;
        case 1:
            cadastrarProdutos();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 2:
            alterarProdutos();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 3:
            listarProdutos();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 4:
            cadastrarLoja();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 5:
            listarLojas();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 6:
            cadastrarPrecos();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 7:
            listarPrecos();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        case 8:
            consultarproduto();
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        default:
            printf("Opcao nao existe.\n");
            printf("Entre com qualquer caractere para continuar o programa.\n");
            getchar();
            break;
        }


    }
    while(c != 0);



    return 0;
}

/* função não recebe variaveis como argumento */

void cadastrarProdutos()
{

    /* a função cadastra um novo produto (utiizando a struct tproduto) e
    * salva no arquivo aproduto (definido antes da main)*/

    tproduto produto;

    printf("Digite a descrição do produto: ");
    scanf("%50[^\n]", produto.descricao);
    setbuf(stdin,NULL);

    FILE * arq;
    if ( (arq = fopen(aproduto,"ab")) == NULL )
    {
        printf("Erro ao gravar no arquivo.\n");
    }
    else
    {
        fseek(arq, 0, SEEK_END);
        produto.cod = ftell(arq) / sizeof(tproduto) + 1;
        fwrite(&produto,sizeof(tproduto),1,arq);
        fclose(arq);
        printf("Codigo do produto cadastrado: %d\n", produto.cod);
    }

    setbuf(stdin,NULL);
}

/* função não recebe variaveis como argumento */

void alterarProdutos()
{

    /* a função altera umas das structs tproduto do arquivo aproduto*/

    tproduto produto;
    int codigo;
    char descricao[51];

    FILE * arq;
    if ((arq = fopen(aproduto,"r+b")) == NULL)
    {
        printf("Erro ao ler ou gravar no arquivo.\n");
    }
    else
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);
        setbuf(stdin,NULL);

        fseek(arq, (codigo-1) * sizeof(tproduto), SEEK_SET);
        fread(&produto, sizeof(tproduto), 1, arq);
        if (codigo <= 0 || feof(arq))
        {
            printf("Error: Código não existe.\n");
        }
        else
        {
            printf("Codigo: %d\n", produto.cod);
            printf("Descrição: %s\n", produto.descricao);
            printf("Digite a nova descrição: ");
            scanf("%50[^\n]", descricao);
            setbuf(stdin,NULL);
            strcpy(produto.descricao,descricao);
            fseek(arq, -sizeof(tproduto), SEEK_CUR);
            fwrite(&produto, sizeof(tproduto), 1, arq);
            printf("Descrição alterada com sucesso.\n");
            fclose(arq);
        }
    }


}

/* função não recebe variaveis como argumento */

void listarProdutos()
{

    /*função que lê todos os dados do arquivo qproduto e exibe
    * na tela em ordem alfabetica (considerando a string descricao da
    * struct tproduto */

    FILE * arq;


    if ((arq = fopen(aproduto, "rb")) == NULL)
    {
        printf("\nErro: não há nenhum cliente cadastrado!\n");
    }
    else
    {
        int n, i;
        fseek(arq, 0, SEEK_END);
        n = ftell(arq) / sizeof(tproduto);
        tproduto produto[n];
        rewind(arq);
        fread(produto, sizeof(tproduto), n, arq);

        ordenarProdutoDescricao(produto, n);

        printf("\n\n\tProdutos Cadastrados\n");
        printf("--------------------------------------\n");
        printf("#Código Descrição\n");
        printf("--------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%06d %s\n", produto[i].cod, produto[i].descricao);
        }

        fclose(arq);
    }

}

/* função recebe uma struct tproduto e uma variavel int (tamanho da struct tproduto) */

void ordenarProdutoDescricao(tproduto produto[], int MAX)
{

    /*a função irá ordenar a struct tproduto em ordem alfabetica, considerando
    * a string descricao da struct tproduto*/

    int i,j;
    tproduto aux;

    for (i=1; i < MAX; i++)
    {

        aux = produto[i];
        j = i - 1;

        while ((j >= 0) && (strcmp(aux.descricao,produto[j].descricao) < 0))
        {

            produto[j+1] = produto[j];
            j--;
        }

        produto[j+1] = aux;

    }

}

/* função não recebe variaveis como argumento */

void cadastrarLoja()
{

    /* a função cadastra uma nova loja (utiizando a struct tloja) e
    * salva no arquivo aloja (definido antes da main)*/

    tloja loja;

    printf("Digite o nome da loja: ");
    scanf("%40[^\n]", loja.nome);
    setbuf(stdin,NULL);
    printf("Digite o site: ");
    scanf("%80[^\n]", loja.site);
    setbuf(stdin,NULL);

    FILE * arq;
    if ( (arq = fopen(aloja,"ab")) == NULL )
    {
        printf("Erro ao gravar no arquivo.\n");
    }
    else
    {
        fseek(arq, 0, SEEK_END);
        loja.cod = ftell(arq) / sizeof(tloja) + 1;
        fwrite(&loja,sizeof(tloja),1,arq);
        fclose(arq);
        printf("Codigo da loja cadastrada: %d\n", loja.cod);
    }

    setbuf(stdin,NULL);

}

/* função não recebe variaveis como argumento */

void listarLojas()
{


    /*função que lê todos os dados do arquivo aloja e exibe
    * na tela em ordem alfabetica (considerando a string nome da
    * struct tloja */

    FILE * arq;
    int n,i;
    if ((arq = fopen(aloja, "rb")) == NULL)
    {
        printf("Error: Impossivel ler o arquivo.\n");
    }
    else
    {
        fseek(arq, 0, SEEK_END);
        n = ftell(arq) / sizeof(tloja);
        tloja loja[n];
        rewind(arq);
        fread(loja, sizeof(tloja), n, arq);
        ordenarLojaNome(loja, n);

        printf("\n\n\tProdutos Cadastrados\n");
        printf("--------------------------------------------------\n");
        printf("#Código Nome da loja\t    Site\n");
        printf("--------------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%06d  %-20s %-10s\n", loja[i].cod, loja[i].nome, loja[i].site);
        }
        fclose(arq);

    }



}

/* função recebe uma struct tloja e uma variavel int (tamanho da struct tloja) */

void ordenarLojaNome(tloja loja[], int MAX)
{

    /*a função irá ordenar a struct tloja em ordem alfabetica, considerando
    * a string nome da struct tloja*/

    int i,j;
    tloja aux;

    for (i=1; i < MAX; i++)
    {

        aux = loja[i];
        j = i - 1;

        while ((j >= 0) && (strcmp(aux.nome,loja[j].nome) < 0))
        {

            loja[j+1] = loja[j];
            j--;
        }

        loja[j+1] = aux;

    }

}

/* função não recebe variaveis como argumento */

int cadastrarPrecos()
{

    /* a função cadastra um novo preço (utiizando a struct tpreco) e
    * salva no arquivo apreco (definido antes da main)*/

    FILE * arq = fopen(apreco,"ab");
    fclose(arq);

    tpreco cadastro;

    do
    {

        printf("Digite o código do produto: ");
        scanf("%d", &cadastro.cod_produto);
        setbuf(stdin,NULL);

    }
    while (validarPreco(cadastro.cod_produto));

    do
    {

        printf("Digite o código da loja: ");
        scanf("%d", &cadastro.cod_loja);
        setbuf(stdin,NULL);

    }
    while (validarLoja(cadastro.cod_loja));

    printf("Digite o valor do produto: ");
    scanf("%f", &cadastro.preco);
    cadastro.preco *= 1.0;
    setbuf(stdin,NULL);

    if (validarPreco2(cadastro))
    {
        if ((arq = fopen(apreco,"ab")) == NULL)
        {
            printf("Error: Não foi possivel abrir o arquivo Precos.\n");
        }
        else
        {
            fwrite(&cadastro,sizeof(tpreco),1,arq);
            fclose(arq);
        }
    }



    do
    {
        printf("Digite o codigo de outra loja para cadastrar o mesmo valor ou digite 0 para voltar ao menu.\n>>> ");
        scanf("%d", &cadastro.cod_loja);
        setbuf(stdin,NULL);

        if (cadastro.cod_loja == 0)
        {
            return false;
        }
        else
        {
            if (validarLoja(cadastro.cod_loja))
            {
                printf("Error: Codigo incorreto.\n");
            }
            else
            {
                if (validarPreco2(cadastro))
                {
                    if ((arq = fopen(apreco,"ab")) == NULL)
                    {
                        printf("Error: Não foi possivel abrir o arquivo Precos.\n");
                    }
                    else
                    {
                        fwrite(&cadastro,sizeof(tpreco),1,arq);
                        fclose(arq);
                        printf("Produto cadastrado.\n");
                    }
                }
            }
        }


    }
    while(cadastro.cod_loja != 0);

}

/* a função recebe uma variavel int - essa variavel é o codigo do produto
* informado pelo usuario */

bool validarPreco(int produto)
{

    /* a função ira checar se a variavel int produto é igual a alguma
    * variavel cod da struct tproduto, dados esses localizados no arquivo aproduto.
    * Ela devolve true se o código não for encontrado e false se o contrario acontecer*/

    FILE * arq;

    if ( (arq = fopen(aproduto,"rb")) == NULL )
    {
        printf("\nError: Impossivel abrir o arquivo Produto.\n");
        printf("Entre com qualquer caractere para continuar o programa.\n");
        getchar();
        return true;
    }
    else
    {
        int n,i;
        fseek(arq, 0, SEEK_END);
        n = ftell(arq) / sizeof(tproduto);
        tproduto produtos[n];
        rewind(arq);
        fread(produtos, sizeof(tproduto), n, arq);
        fclose(arq);
        for (i=0; i<n; i++)
        {
            if (produto == produtos[i].cod)
            {
                return false;
            }
        }

    }

    printf("Error: Codigo não encontrado.\n");
    return true;
}

/* a função recebe uma variavel int - essa variavel é o codigo da loja
* informado pelo usuario */

bool validarLoja(int loja)
{

    /* a função ira checar se a variavel int loja é igual a alguma
    * variavel cod da struct tloja, localizadas no arquivo aloja.
    * Ela devolve true se o codigo não for encontrado e false se o contrario acontecer*/

    FILE * arq;

    if ( (arq = fopen(aloja,"rb")) == NULL )
    {
        printf("\nError: Impossivel abrir o arquivo Loja.\n");
        printf("Entre com qualquer caractere para continuar o programa.\n");
        getchar();
        return true;
    }
    else
    {
        int n,i;
        fseek(arq, 0, SEEK_END);
        n = ftell(arq) / sizeof(tloja);
        tloja lojas[n];
        rewind(arq);
        fread(lojas, sizeof(tloja), n, arq);
        fclose(arq);
        for (i=0; i<n; i++)
        {
            if (loja == lojas[i].cod)
            {
                return false;
            }
        }

    }

    printf("Error: Codigo não encontrado.\n");
    return true;

}

/* a função recebe uma struct tpreco informada pelo usuario*/

bool validarPreco2(tpreco cadastro)
{

    /* a funço ira checar se não há outra struct igual no arquivo apreco.
    * Ela devolve true se não tiver cadastro e false se o contrario acontecer.*/

    int i;
    FILE * arq;

    if ((arq = fopen(apreco,"rb")) == NULL)
    {
        printf("\nError: Impossivel abrir o arquivo Preço.\n");
    }
    else
    {
        int n,i;
        fseek(arq, 0, SEEK_END);
        n = ftell(arq) / sizeof(tpreco);
        tpreco precos[n];
        rewind(arq);
        fread(precos, sizeof(tpreco), n, arq);
        fclose(arq);

        for (i=0; i < n; i++)
        {
            if ( (precos[i].cod_loja == cadastro.cod_loja) && (precos[i].cod_produto == cadastro.cod_produto) && (precos[i].preco == cadastro.preco))
            {
                printf("Error: Produto já cadastrado.\n");
                return false;
            }
        }
    }

    return true;
}

/* função não recebe variaveis como argumento */

int listarPrecos()
{

    /* a funçao lista todos os precos gravados no arquivo apreco.
    * Ela tambem ira informar a loja e o nome do produto (dados adquiridos dos
    * arquivos aloja e aproduto, respectivamente.
    * os dados sao exibidos em ordem alfabetica ascendente pelo nome da loja e
    * ordem descendente pelo preço do produto. */

    int m,n,o,i,j;
    FILE * arq;

    if ((arq = fopen(aproduto,"rb")) == NULL)
    {
        printf("\nError: Impossivel abrir o arquivo Produto.\n");
        return 1;
    }
    fseek(arq, 0, SEEK_END);
    m = ftell(arq) / sizeof(tproduto);
    tproduto produtos[m];
    rewind(arq);
    fread(produtos, sizeof(tproduto), m, arq);
    fclose(arq);


    if ((arq = fopen(aloja,"rb")) == NULL)
    {
        printf("\nError: Impossivel abrir o arquivo Loja.\n");
        return 2;
    }
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(tloja);
    tloja lojas[n];
    rewind(arq);
    fread(lojas, sizeof(tloja), n, arq);
    fclose(arq);


    if ((arq = fopen(apreco,"rb")) == NULL)
    {
        printf("\nError: Impossivel abrir o arquivo Preço.\n");
        return 3;
    }
    fseek(arq, 0, SEEK_END);
    o = ftell(arq) / sizeof(tpreco);
    tpreco precos[o];
    tlista lista[o];
    rewind(arq);
    fread(precos, sizeof(tpreco), o, arq);
    fclose(arq);


    for (i=0; i < o; i++)
    {
        lista[i].preco = precos[i].preco;

        for (j=0; j < m; j++)
        {
            if (precos[i].cod_produto == produtos[j].cod)
            {
                strcpy(lista[i].produto,produtos[j].descricao);
                //break;
            }
        }

        for (j=0; j < n; j++)
        {
            if (precos[i].cod_loja == lojas[j].cod)
            {
                strcpy(lista[i].loja, lojas[j].nome);
                //break;
            }
        }

    }

    ordenarLista(lista,o);

    printf("\n\n\tProdutos Cadastrados\n");
    printf("--------------------------------------------------\n");
    printf("Produto\t\tLoja\t\tPreço\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < o; i++)
    {
        if (strlen(lista[i].produto) > 10)
        {
            lista[i].produto[10] = '\0';
        }
        printf("%-15.10s %-15.10s %.2f\n", lista[i].produto, lista[i].loja, lista[i].preco);
    }

}

/* a funçao recebe uma struct tlista e um int (com o valor do tamanho da struct)*/

void ordenarLista(tlista lista[], int MAX)
{

    /* a funcao ira ordenar a struct alfabetica ascendente pela string loja e
    * descendente pela variavel preco */

    int i,j;
    tlista aux;



    for (i=1; i < MAX; i++)
    {

        aux = lista[i];
        j = i - 1;

        while ((j >= 0) && (strcmp(aux.loja,lista[j].loja) < 0))
        {

            lista[j+1] = lista[j];
            j--;
        }

        lista[j+1] = aux;

    }



    for (i=1; i < MAX; i++)
    {

        aux = lista[i];
        j = i - 1;

        while ((j >= 0) && (aux.preco > lista[j].preco) && (strcmp(aux.loja,lista[j].loja) == 0))
        {

            lista[j+1] = lista[j];
            j--;
        }

        lista[j+1] = aux;
    }


}

/* função não recebe variaveis como argumento */

void consultarproduto()
{

    /* a funcao ira scannear o codigo de um produto do usuario e
    * mostrara todos os valores e lojas em que esta cadastrado. */

    int codigo, k=0,o,i,j,n;

    tproduto produto;

    FILE * arq;
    if ((arq = fopen(aproduto,"rb")) == NULL)
    {
        printf("Erro ao ler o arquivo.\n");
    }
    else
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);
        setbuf(stdin,NULL);

        fseek(arq, (codigo-1) * sizeof(tproduto), SEEK_SET);
        fread(&produto, sizeof(tproduto), 1, arq);
        if (codigo <= 0 || feof(arq))
        {
            fclose(arq);
            printf("Error: Código não existe.\n");
        }
        else
        {
            fclose(arq);

            if ((arq = fopen(apreco,"rb")) == NULL)
            {
                printf("\nError: Impossivel abrir o arquivo Preço.\n");
            }
            fseek(arq, 0, SEEK_END);
            o = ftell(arq) / sizeof(tpreco);
            tpreco precos[o];
            tlista lista[o];
            rewind(arq);
            fread(precos, sizeof(tpreco), o, arq);
            fclose(arq);

            if ((arq = fopen(aloja,"rb")) == NULL)
            {
                printf("\nError: Impossivel abrir o arquivo Loja.\n");
            }
            fseek(arq, 0, SEEK_END);
            n = ftell(arq) / sizeof(tloja);
            tloja lojas[n];
            rewind(arq);
            fread(lojas, sizeof(tloja), n, arq);
            fclose(arq);



            printf("\n\n\tConsulta de produto\n");
            printf("Codigo: %d\n", produto.cod);
            printf("Produto: %s\n", produto.descricao);
            printf("--------------------------------------------------\n");
            printf("Loja\t\tPreço\n");
            printf("--------------------------------------------------\n");
            for (i=0; i < o; i ++)
            {
                if (codigo == precos[i].cod_produto)
                {
                    for (j=0; j < n; j++)
                    {
                        if (precos[i].cod_loja == lojas[j].cod)
                        {
                            printf("%-15.15s %.2f\n", lojas[j].nome, precos[i].preco);
                            k+=1;
                        }
                    }
                }
            }

            if (k == 0)
            {
                printf("Nenhum valor cadastrado.\n");
            }
        }
    }



}
