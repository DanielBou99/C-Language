#include <stdio.h>
#include <string.h>

int main() {

    char nome[20],c='c';
    int i,j;

    scanf("%19[^\n]", nome);

while (c=='c') {
    c='s';

    for (i=0; nome[i] != '\0'; i++) {

        if (nome[i] == ' ') {
            c= 'c';
            for (j=i; nome[j] != '\0'; j++) {
                nome[j] = nome[j+1];
            }
        nome[j] = '\0';
          }
     }
}


printf("%s", nome);
    return 0;
}
