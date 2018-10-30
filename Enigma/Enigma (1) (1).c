/*�Enigma.c
*
*�Programa�que�determina�a quantidade de posi��es poss�veis para
* decriptar um crib informado pelo pr�prio usu�rio.
*
*�Daniel Bou�(Ci�ncia da Computa��o)
*�Mauricio Freire�(Ci�ncia�da�Computa��o)
*
*�Disciplina:�Introdu��o��Computa��o�II
*
*�27/09/2018
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool eh_possivel(int index, const char * mensagem, const char * crib);
void verificacao(int *, char []);

int main()
{

    int controle = 0;
    char script[10000];

    do
    {

        printf("Informe a mensagem cifrada: ");
        scanf("%9999[^\n]", script);
        fflush(stdin);

        verificacao(&controle,script);

    }
    while (controle == 0);

    int ts = strlen(script), tc;
    char crib[10000];

    do
    {

        do
        {

            printf("Informe o crib: ");
            scanf("%9999[^\n]", crib);
            fflush(stdin);
            tc = strlen(crib);

        }
        while ( tc > ts );

        verificacao(&controle,crib);

    }
    while (controle == 0);


    int vf = strlen(script) - strlen(crib), r=0, index=0;
    controle = 0;

    do
    {

        if (eh_possivel(index,script,crib))
        {
            r += 1;
        }

        index += 1;

    }
    while (index <= vf);

    printf("Resultado = %d", r);

    return 0;
}


/*�fun��o�que�recebe�um ponteiro inteiro e um vetor
* de caracteres. A fun��o altera o valor do inteiro. �*/

void verificacao(int *controle, char string[])
{
/*�A fun��o devolve 0 � variavel *controle se houver
* um caractere minusculo na string ou devolve o valor 1 se
* todos os caracteres forem maiusculos.
*/

    int i;

    *controle = 1;

    for (i=0; string[i] != '\0'; i++)
    {
        if ((string[i] < 65) || (string[i] > 90))
        {
            *controle = 0;

        }
    }

}

/*�fun��o�que�recebe�uma variavel int e dois ponteiros constantes do tipo char
e devolve true ou false*/

bool eh_possivel(int index, const char * mensagem, const char * crib)
{

/*�A fun��o ir� devolver true se n�o encontrar *crib em
* *mensagem de acordo com o int index
* e ira devolver false se encontrar a *crib na *mensagem.
*/

    int i;
    int j = index;

    for (i=0; crib[i] != '\0'; i++)
    {
        if (crib[i] == mensagem[j])
        {
            return false;
        }
        else
        {
            j = j + 1;
        }
    }

    return true;

}
