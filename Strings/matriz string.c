#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

char n[3][40];
int i,j, aux;

    for (i=0; i < 3; i++) {
        fgets(n[i],39,stdin);
        fflush(stdin);
        n[i][strlen(n)] = '\0';
    }

    printf("\n");

    for (i=0; i < 3; i++) {

        aux = n[i][0];

      if (aux >= 65 && aux <= 74 || aux >= 97 && aux <= 106 ){
            printf ("%s\n", n[i]);
        }

    }



    return 0;
}
