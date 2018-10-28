#include <stdio.h>
#include <string.h>

int main() {

char nome[50];
int i,s=0,j;

scanf("%49[^\n]", nome);

for (i=0; nome[i] != '\0'; i++) {

    if (nome[i] == ' ') {
        s += 1;
        if (s > 1) {
            for (j=i;j < 50; j++) {
                nome[j] = nome[j+1];
            }
            s = 0;
            i = 0;
        }
    }   else {
            s = 0;
            }
}

puts(nome);

    return 0;
}
