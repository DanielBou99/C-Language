#include "lista.h"
#include <stdio.h>

int main()
{
	lista l1, l2, l3, l4;
	
	lst_init(&l1);
	lst_init(&l2);
	
	lst_ins_ordenado(&l1, 5);
	lst_ins_ordenado(&l1, 1);
	lst_ins_ordenado(&l1, 3);

	lst_ins_ordenado(&l2, 10);
	lst_ins_ordenado(&l2, 3);
	lst_ins_ordenado(&l2, 6);
	
	printf("l1: ");
	lst_imprimir(l1);
	printf("l2: ");
	lst_imprimir(l2);
	
	lst_concatenar(l1, l2, &l3);
	printf("l3: ");
	lst_imprimir(l3);
	
	lst_gerar(&l4, 10, 20);
	printf("l4: ");
	lst_imprimir(l4);
	
	int x = lst_remover_menores(&l4, 10);
	printf("Número de remoções: %d\n", x);
	printf("l4: ");
	lst_imprimir(l4);

	return 0;
}
