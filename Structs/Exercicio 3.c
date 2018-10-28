#include <stdio.h>
#include <string.h>

/*Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo os
seguintes campos: 
◦ marca: string de tamanho 15 
◦ ano: inteiro 
◦ cor: string de tamanho 10 
◦ preço: real
a) Escrever a definição da estrutura carro. 
b) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20.
Crie um menu para: 
c) Cadastrar um carro no vetor vetcarros (verificando se há espaço disponível); 
d) Listar todos os carros com preço menor ou igual a um valor fornecido pelo usuário;
e) Listar todos os carros de uma determinada marca fornecida pelo usuário.
*/

struct carro {

char marca[15];
int ano;
char cor[10];
float preco;

};

int main() {

struct carro vetcarros[20];
int i = 0,j;
float precou;
char marcau[15];


char c;

do {
    printf("Menu: \n");
    printf("'a' = Cadastrar um carro.\n");
    printf("'b' = Listar todos os carros com preco menor ou igual.\n");
    printf("'c' = Listar todos os carros de uma determinada marca.\n");
    printf("'s' = Sair.\n");
    scanf(" %c", &c);
    fflush(stdin);


    switch(c) {
        case 'a':

            if (i < 15) {

                printf("Informe a marca do carro:\n");
                scanf("%14[^\n]", vetcarros[i].marca);
                fflush(stdin);

                printf("Informe o ano do carro:\n");
                scanf("%d", &vetcarros[i].ano);
                fflush(stdin);

                printf("Informe a cor do carro:\n");
                scanf("%9[^\n]", vetcarros[i].cor);
                fflush(stdin);

                printf("Informe o preco do carro:\n");
                scanf("%f", &vetcarros[i].preco);
                fflush(stdin);
                 i += 1;

            } else {
                printf("Limite atingido!");
            }
  
            system("pause");
            system("cls");
            break;

        case 'b':

            printf("Informe o valor:\n");
            scanf("%f", &precou);
            fflush(stdin);
            for (j=0; j < i; j++) {

                if (precou >= vetcarros[j].preco) {
                    printf("\nMarca = %s\n", vetcarros[j].marca);
                    printf("Ano = %d\n", vetcarros[j].ano);
                    printf("Cor = %s\n", vetcarros[j].cor);
                    printf("Preco = %.2f\n", vetcarros[j].preco);
                }

            }



            system("pause");
            system("cls");
            break;

        case 'c':

            printf("Informe a marca:\n");
            scanf("%14[^\n]", marcau);
            fflush(stdin);

            for (j=0; j < i; j++) {

                if (strcmp(marcau,vetcarros[j].marca) == 0) {
                    printf("\nMarca = %s\n", vetcarros[j].marca);
                    printf("Ano = %d\n", vetcarros[j].ano);
                    printf("Cor = %s\n", vetcarros[j].cor);
                    printf("Preco = %.2f\n", vetcarros[j].preco);
                }

            }

            system("pause");
            system("cls");
            break;

        case 's':

            system("pause");
            system("cls");
            break;

        default:
            printf("Opcao invalida!\n");
            system("pause");
            system("cls");
            break;

    }









} while ( c != 's');


    return 0;
}
