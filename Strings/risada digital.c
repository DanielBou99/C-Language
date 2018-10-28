#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
char a[50],c='s';
int i,j,aux;

scanf("%49[^\n]", a);

strlwr(a);

for(i=0;a[i] != '\0';i++) {
    if ((a[i] == 97) || (a[i] == 101) || (a[i] == 105) || (a[i] == 111) || (a[i] == 117)) {
        c = 'c';
    }
}

if (c == 'c') {

    for (i=0; a[i] != '\0'; i++) { // retirar as consoantes

        c = 's';
        aux = a[i];

        if ((aux != 97) && (aux != 101) && (aux != 105) && (aux != 111) && (aux != 117)) {

            c= 'c';

                for (j=i; a[j] != '\0'; j++) {
                    a[j] = a[j+1];
                }

        }

            if(c== 'c') {
                a[j] = '\0';
                i = 0;
            }

    }


}

int count=0;
char b[strlen(a)];

strcpy(b,a);

j= strlen(b) -1;

for (i=0; a[i] != '\0'; i++) {
    if (a[i] == b[j]) {
        count += 1;
    }
    j -= 1;
}

if( count == strlen(a)) {
    printf("\nS\n");
} else {
    printf("\nN\n");
}

    return 0;
}
