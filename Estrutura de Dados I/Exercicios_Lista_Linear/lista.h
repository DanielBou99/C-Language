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


/* Função para inicializar uma lista */
void init_lst(lista * l);

/* Implemente uma função de protótipo bool lst_inserir_final(lista * l,
lst_info x); que insere x no final da lista l e devolve verdadeiro para indicar o sucesso
da operação, ou falso, para indicar a falha (lista cheia). */
bool lst_inserir_final(lista * l, lst_info x);

/*2. Implemente uma função de protótipo bool lst_inserir_inicio(lista * l,
lst_info x); que insere x no início da lista l e devolve verdadeiro para indicar o sucesso
da operação, ou falso, para indicar a falha (lista cheia). */
bool lst_inserir_inicio(lista * l, lst_info x);

/* função que imprime o conteúdo da lista */
void lst_imprimir(lista l);

/*Implemente uma função de protótipo bool lst_remover_final(lista * l,
lst_info * x); que remove o valor do final da lista, guarda seu valor em x e devolve
verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia). */
bool lst_remover_final(lista * l, lst_info * x);

/* Implemente uma função de protótipo bool lst_remover_inicio(lista * l,
lst_info * x); que remove o valor do início da lista, guarda seu valor em x e devolve
verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia). */
bool lst_remover_inicio(lista * l, lst_info * x);

/* Implemente uma função de protótipo bool lst_gerar(lista * l, int n, int
max); que gera aleatoriamente (use a função rand()) o conteúdo da lista l com n nós
contendo valores entre 1 e max e devolve verdadeiro para indicar o sucesso da operação, ou
falso, para indicar a falha (n é maior que o tamanho do vetor). Considere que a lista é de
inteiros.*/
bool lst_gerar(lista * l, int n, int max);

/* Implemente uma função de protótipo bool lst_ordenada(lista l); que devolve
verdadeiro se a lista l está em ordem crescente. Considere que a lista é de um tipo numérico.*/
bool lst_ordenada(lista l);

/*Implemente uma função de protótipo int lst_remover_menores(lista * l,
lst_info x); que remove todos os nós de uma lista l cujo valor for menor que x e
devolve o número de nós removidos. Considere que a lista é de um tipo numérico.*/
int lst_remover_menores(lista * l, lst_info x);

#endif // _LISTA_H
