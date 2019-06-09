#include <stdio.h>
#include "fila.h"

int main()
{
	fila f;
	queue_info x;
	int op;
	
	queue_init(&f);
	do {
		printf("\n\n\tFILA\n");
		printf("<1> Inserir\n");
		printf("<2> Remover\n");
		printf("<0> Sair\n");
		printf("Opção: ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("\n\nInserção\n");
				printf("Valor: ");
				scanf("%d", &x);
				enqueue(&f, x);
				break;
			case 2:
				printf("\n\nValor removido: %d\n", dequeue(&f));
				break;
			case 0:
				break;
			default:
				printf("\nErro: opção inválida!\n");
		}
	} while (op != 0);
	return 0;
}
