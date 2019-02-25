#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{

    lista l;

    init_lst(&l); // Inicializar a lista

    lst_inserir_final(&l, 10); // Inserir no final
    lst_inserir_final(&l, 14);
    lst_inserir_final(&l, 12);
    lst_inserir_final(&l, 11);
    lst_imprimir(l);


    lst_inserir_inicio(&l, 1); // Inserir no inicio
    lst_inserir_inicio(&l, 4);
    lst_inserir_inicio(&l, 8);
    lst_inserir_inicio(&l, 6);
    lst_imprimir(l);

    lst_info x;
    lst_remover_final(&l,&x); // Remover o ultimo valor da lista
    printf("Valor removido do final da lista: %d\n", x);
    lst_imprimir(l);
    lst_remover_final(&l,&x);
    printf("Valor removido do final da lista: %d\n", x);
    lst_imprimir(l);


    lst_remover_inicio(&l,&x); // Remover o primeiro valor da lista
    printf("Valor removido do inicio da lista: %d\n", x);
    lst_imprimir(l);
    lst_remover_inicio(&l,&x);
    printf("Valor removido do inicio da lista: %d\n", x);
    lst_imprimir(l);

    lst_gerar(&l, 10, 5); // Gerar lista automaticamente
    lst_imprimir(l);

    lista teste;
    init_lst(&teste);

    lst_inserir_final(&teste,1);
    lst_inserir_final(&teste,2);
    lst_inserir_final(&teste,3);
    lst_inserir_final(&teste,4);
    lst_inserir_final(&teste,5);
    lst_inserir_final(&teste,6);

    lst_imprimir(teste);
    if (lst_ordenada(teste)) { // Verificar se a lista está em ordem crescente
        printf("A lista esta em ordem crescente.\n");
    } else {
        printf("A lista NAO esta em ordem crescente.\n");
    }

    lst_inserir_final(&teste,5);

    lst_imprimir(teste);
    if (lst_ordenada(teste)) { // Verificar se a lista está em ordem crescente
        printf("A lista esta em ordem crescente.\n");
    } else {
        printf("A lista NAO esta em ordem crescente.\n");
    }

    lst_imprimir(teste);
    x = lst_remover_menores(&teste, 6); // Remover todos os numero menores que o segundo argumento
    printf("Total de itens removidos: %d\n", x);
    lst_imprimir(teste);

    return 0;
}
