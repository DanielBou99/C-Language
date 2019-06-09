/*
    Implementação das funções definadas no arquivo set.h,
    para a realização das operações com conjuntos.
*/
#include "set.h"
#include <stdio.h>
#include <stdbool.h>

/*função que inicializa um conjunto*/
void set_init(set * s1)
{
    s1->n = 0;
}
/*função que verifica se um conjunto está vazio,
  recebe como parametro um conjuto e retorna verdadeiro ou falso.
*/
bool set_isempty(set s1)
{
    return s1.n == 0;
}
/*função que verifica se um conjunto está cheio,
  recebe como parametro um conjuto e retorna verdadeiro ou falso.
*/
bool set_isfull(set s1)
{
    return s1.n == SET_MAX;
}
/*função que verifica se um dado numero pertence ao conjunto,
  recebe como parametro um conjuto e a informação e retorna verdadeiro ou falso.
*/
bool set_member(set s1, set_info x)
{
    int i;
    for(i = 0; i < s1.n; i++)
    {
        if(s1.itens[i] == x) {
            return true;
        }
    }
    return false;
}
/* função que inseri um dado numero no conjunto,
   recebe como parametro o endereço de um conjunto e a informação
   retorna verdadeiro se a operação for sucedida com sucesso.
*/
bool set_insert(set * s1, set_info x)
{
    if(!set_isfull(*s1)) {
        int i;
        for(i = 0; i < s1->n; i++) {
            if(s1->itens[i] == x) {
                return false;
            }
        }
    }
        s1->itens[s1->n++] = x;
        return true;
}
/*função que remove um dado numero do conjunto.
  retorna verdadeiro se a operação for sucedida com sucesso.
*/
bool set_remove(set * s1, set_info x)
{
    if(!set_isempty(*s1)) {
        int i;
        bool found = false;
        for(i = 0; i < s1->n ; i++) {
            if(s1->itens[i] == x || found == true) {
                found = true;
                if(i == s1->n - 1) {
                  --s1->n;
                    break;
                }
                s1->itens[i] = s1->itens[i + 1];
            }
        }
        return found == true;
    }
    return false;
}
/*função que da a diferença do conjunto A - B
  recebe como parametro dois conjuntos e o endereço de um terceiro
*/
void set_difference(set s1, set s2, set * s3)
{
    int i, j;
    bool contains = false;
    for(i = 0; i < s1.n; i++) {
        for(j = 0; j < s2.n; j++) {
            if(s1.itens[i] == s2.itens[j]) {
                contains = true;
                break;
            }
        }

        if(contains == false) {
            s3->itens[s3->n++] = s1.itens[i];
        }
        contains = false;
    }
}
/*função que realiza a união de dois conjuntos A U B,
  recebe como parametro dois conjuntos e o endereço de um terceiro,
  retorna verdadeiro se a operação for sucedida com sucesso.
*/
bool set_union(set s1, set s2, set * s3)
{
    int i;
    set sx;
    set_init(&sx);
    set_difference(s1, s2, &sx);

    if(s1.n + s2.n < SET_MAX) {
        for(i = 0; i < s2.n; i++) {
            s3->itens[s3->n++] = s2.itens[i];
        }

        for(i = 0; i < sx.n; i++) {
            s3->itens[s3->n++] = sx.itens[i];
        }

        return true;
    }
    return false;
}
/*função que realiza a interceção de dois conuntos A ∩ B
  recebe como parametro dois conjuntos e o endereço de um terceiro
 */
void set_intersection(set s1, set s2, set * s3)
{
    int i, j;
    bool contains = false;
    for(i = 0; i < s1.n; i++) {
        for(j = 0; j < s2.n; j++) {
            if(s1.itens[i] == s2.itens[j]) {
                contains = true;
                break;
            }
        }

        if(contains == true) {
            s3->itens[s3->n++] = s1.itens[i];
        }
        contains = false;
    }

}
/*função que imprimi um conjunto
  recebe como parametro um conjunto.
 */
void set_print(set s1)
{
    int i;
    for(i = 0; i < s1.n; i++) {
        printf("%d, ", s1.itens[i]);
    }
}
