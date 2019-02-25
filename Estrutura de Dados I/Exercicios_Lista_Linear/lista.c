#include "lista.h"

void init_lst(lista * l) {

    l->n = 0;

}

bool lst_inserir_final(lista * l, lst_info x) {

    if (l->n >= 0 && l->n < MAX_LST) {
        l->itens[l->n] = x;
        l->n++;
        return true;
    }
    return false;

}

bool lst_inserir_inicio(lista * l, lst_info x) {

    if (l->n >= 0 && l->n < MAX_LST) {
        int i;
        for (i= l->n; i > 0; i--) {
            l->itens[i] = l->itens[i-1];
        }
        l->n++;
        l->itens[0] = x;
        return true;
    }
    return false;

}

void lst_imprimir(lista l)
{
	int i;
	printf("[ ");
	for (i = 0; i < l.n; i++) {
		printf("%d,", l.itens[i]);
	}
	printf("\b ]\n");
}

bool lst_remover_final(lista * l, lst_info * x) {

    if (l->n > 0) {
        *x = l->itens[l->n-1];
        l->n--;
        return true;
    }
    return false;
}

bool lst_remover_inicio(lista * l, lst_info * x) {

    if (l->n > 0) {
        *x = l->itens[0];
        int i;
        for (i=0; i < l->n-1; i++) {
            l->itens[i] = l->itens[i+1];
        }
        l->n--;
        return true;
    }
    return false;

}

bool lst_gerar(lista * l, int n, int max) {

    if (n > 0 && n < MAX_LST) {
        int i;
        for (i=0; i < n; i++) {
            l->itens[i] = 1 + ( rand() % max );
        }
        l->n = n;
        return true;
    }
        return false;
}

bool lst_ordenada(lista l) {

    int i;
    for (i=0; i < l.n-1; i++) {
        if(l.itens[i] > l.itens[i+1]) {
            return false;
        }
    }
    return true;
}

int lst_remover_menores(lista * l, lst_info x) {

    int i,count=0,j;
    for (i=0; i < l->n; i++) {
        if (l->itens[i] < x) {
            count++;
            for (j=i; j < l->n; j++) {
                l->itens[j] = l->itens[j+1];
            }
            l->n--;
            i--;
        }
    }
    return count;
}
