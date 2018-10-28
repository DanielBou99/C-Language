#include <stdio.h>

/*Esse programa calcula quantos R% você precisa economizar por mês para conquistar um valor final desejado*/

void entradaesaida(float*,float*,float*,int*);
void calculo(float*,float*,float*,int*);
void rendadisponivel(float*,float*);

int main()
{

    float e,s,vf;
    int m;
    char c;

    do
    {
        printf("Calcular a sua renda para economizar mensal = TECLE 'A'\n");
        printf("Calcular considerando um valor final = TECLE 'B'\n");
        printf("Para finalizar = TECLE 'S'\n");
        scanf("%c", &c);
        system("cls");

        switch (c)
        {
        case 'A':
            rendadisponivel(&e,&s);
            system("pause");
            system("cls");
            break;
        case 'B':
            entradaesaida(&e,&s,&vf,&m);
            printf("\n\n");
            calculo(&e,&s,&vf,&m);
            system("pause");
            system("cls");
            break;
        }

    }
    while (c!='S');

    return 0;
}

void entradaesaida(float * e, float * s, float * vf, int * m)   // Ler as entradas
{

    printf("Digite o valor da sua entrada mensal: R$");
    scanf("%f", &*e);
    printf("Digite o valor da sua saida obrigatoria mensal: R$");
    scanf("%f", &*s);
    printf("Digite o valor que voce deseja economizar no final: R$");
    scanf("%f", &*vf);
    printf("Em quantos meses voce deseja juntar esse valor?: R$");
    scanf("%d", &*m);

}

void calculo(float * e, float * s, float * vf, int * m)
{

    float em= *vf / *m;

    if (em > (*e - *s))
    {
        printf("O tempo estimado nao eh suficiente para economizar R$ %.2f! \n", *vf);
        printf("Sua renda mensal para economizar eh de R$ %.2f \nA renda mensal necessaria eh R$ %.2f\n", *e-*s, em);
    }
    else
    {
        printf("Minimo necessario que voce precisa economizar por mes eh R$ %.2f \n", em);
    }

}

void rendadisponivel(float * e,float * s) {

printf("Digite a sua entrada mensal: R$ ");
scanf("%f", &*e);
printf("Digite a sua saida mensal: R$ ");
scanf("%f", &*s);

if (*e - *s > 0) {
    printf("Voce possui R$ %.2f disponivel para economizar!\n", *e - *s);
} else {
    printf("Voce nao possui dinheiro para economizar no momento.\n");
}

}
