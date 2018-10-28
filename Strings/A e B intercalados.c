#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Printar uma string C intercalando as strings A e B*/

int main() {

    char a[10],b[10],c[20];
    int i,ia=0,ib=1,j;

    printf("Digite a string A: \n");
    scanf("%9[^\n]", a);
    fflush(stdin);

    printf("Digite a string B: \n");
    scanf(" %9[^\n]", b);
    fflush(stdin);

    for (i=0;i < 20;i++) {
        c[i] = ' ';
    }

        for (i=0; a[i] != '\0'; i++) {
            c[ia] = a[i];
            ia += 2;
        }

        for (i=0; b[i] != '\0'; i++) {
            c[ib] = b[i];
            ib += 2;
        }

        if (strlen(a) > strlen(b)) {
        j= strlen(a) *2;
        c[j] = '\0';
        } else {
        j= strlen(b) *2;
        c[j] = '\0';
        }




char controle='c';

while (controle=='c') {
    controle='s';

    for (i=0;c[i] != '\0';i++) {

        if (c[i] == ' ') {

            controle='c';
            for (j=i; c[j] != '\0'; j++) {
                c[j] = c[j+1];
            }
        }
    }
}



       printf("\nStrind A= %s / Strind B= %s / String C= %s", a,b,c);






    return 0;
}
