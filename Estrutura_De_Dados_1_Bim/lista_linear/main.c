#include "lista.h"
#include <stdio.h>

int main()
{
	lista l;
	int k, op;
	lst_info val;
	
	lst_init(&l);	
	do {
		printf("\n\nLISTA LINEAR\n");
		printf("<1> Inserir\n");
		printf("<2> Remover\n");
		printf("<3> Acessar\n");
		printf("<4> Alterar\n");
		printf("<5> Imprimir\n");
		printf("<6> Procurar\n");
		printf("<0> Sair\n");
		printf("Opção: ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("\n\nInserir um novo nó\n");
				/*
				printf("Posição: ");
				scanf("%d", &k);
				*/
				printf("Valor: ");
				scanf("%d", &val);
				//if (lst_inserir(&l, k, val)) {
				if (lst_ins_ordenado(&l, val)) {
					printf("Inserção realizada com sucesso!\n");
				}
				else {
					//printf("Erro: posição inválida ou lista cheia!\n");
					printf("Erro: lista cheia!\n");
				}
				break;
			case 2:
				printf("\n\nRemover um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				if (lst_remover(&l, k, &val)) {
					printf("%d removido da lista\n", val);
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 3:
				printf("\n\nAcessar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				if (lst_acessar(l, k, &val)) {
					printf("Valor da posição %d = %d\n", k, val);
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 4:
				printf("\n\nAlterar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				printf("Valor: ");
				scanf("%d", &val);
				if (lst_alterar(&l, k, val)) {
					printf("Alteração realizada com sucesso!\n");
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 5:
				printf("\n\nConteúdo da lista: ");
				lst_imprimir(l);
				break;
			case 6:
				printf("\n\nProcurar um valor na lista\n");
				printf("Valor: ");
				scanf("%d", &val);
				k = lst_procurar(l, val);
				if (k != -1) {
					printf("%d está na posição %d da lista\n", val, k);
				}
				else {
					printf("%d não está contido na lista\n", val);
				}
				break;
			case 0:
				break;
			default:
				printf("\nErro: opção inválida!\n");
				break;
		}		
	} while (op != 0);
	
	return 0;
}
