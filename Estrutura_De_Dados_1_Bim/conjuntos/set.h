/*
    Implementa��o dos prototipos das  fun��es sobre conjuntos,
    para a realiza��o das opera��es com conjuntos.
*/
#ifndef _SET_H
#define _SET_H
#define SET_MAX 10

#include <stdbool.h>
/*definica��o do TAD set*/
typedef int set_info;
typedef struct {
    set_info itens[SET_MAX];
    int n;
}set;

void set_init(set *);

bool set_isempty(set);

bool set_isfull(set);

bool set_member(set, set_info);

bool set_insert(set *, set_info);

bool set_remover(set *, set_info);

bool set_union(set, set, set *);

void set_intersection(set, set, set *);

void set_difference(set, set, set *);

#endif // _SET_H
