#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LST 100

typedef int lst_info;

typedef struct {
    lst_info itens[MAX_LST];
    int n;
} lista;


/* Fun��o para inicializar uma lista */
void init_lst(lista * l);

/* Implemente uma fun��o de prot�tipo bool lst_inserir_final(lista * l,
lst_info x); que insere x no final da lista l e devolve verdadeiro para indicar o sucesso
da opera��o, ou falso, para indicar a falha (lista cheia). */
bool lst_inserir_final(lista * l, lst_info x);

/*2. Implemente uma fun��o de prot�tipo bool lst_inserir_inicio(lista * l,
lst_info x); que insere x no in�cio da lista l e devolve verdadeiro para indicar o sucesso
da opera��o, ou falso, para indicar a falha (lista cheia). */
bool lst_inserir_inicio(lista * l, lst_info x);

/* fun��o que imprime o conte�do da lista */
void lst_imprimir(lista l);

/*Implemente uma fun��o de prot�tipo bool lst_remover_final(lista * l,
lst_info * x); que remove o valor do final da lista, guarda seu valor em x e devolve
verdadeiro para indicar o sucesso da opera��o, ou falso, para indicar a falha (lista vazia). */
bool lst_remover_final(lista * l, lst_info * x);

/* Implemente uma fun��o de prot�tipo bool lst_remover_inicio(lista * l,
lst_info * x); que remove o valor do in�cio da lista, guarda seu valor em x e devolve
verdadeiro para indicar o sucesso da opera��o, ou falso, para indicar a falha (lista vazia). */
bool lst_remover_inicio(lista * l, lst_info * x);

/* Implemente uma fun��o de prot�tipo bool lst_gerar(lista * l, int n, int
max); que gera aleatoriamente (use a fun��o rand()) o conte�do da lista l com n n�s
contendo valores entre 1 e max e devolve verdadeiro para indicar o sucesso da opera��o, ou
falso, para indicar a falha (n � maior que o tamanho do vetor). Considere que a lista � de
inteiros.*/
bool lst_gerar(lista * l, int n, int max);

/* Implemente uma fun��o de prot�tipo bool lst_ordenada(lista l); que devolve
verdadeiro se a lista l est� em ordem crescente. Considere que a lista � de um tipo num�rico.*/
bool lst_ordenada(lista l);

/*Implemente uma fun��o de prot�tipo int lst_remover_menores(lista * l,
lst_info x); que remove todos os n�s de uma lista l cujo valor for menor que x e
devolve o n�mero de n�s removidos. Considere que a lista � de um tipo num�rico.*/
int lst_remover_menores(lista * l, lst_info x);

#endif // _LISTA_H
