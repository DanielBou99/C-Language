#include <stdio.h>
#include <string.h>

// Inverter string

int main()
{
   char nome[15],inv[15];
   int i,j=0;

   scanf("%14[^\n]", nome);
   fflush(stdin);


    for (i= strlen(nome)-1; i >= 0 ; i--) {

    inv[j] = nome[i];
    j++;

    }

    inv[j] = '\0';

    printf("%s", inv);

    return 0;
}
