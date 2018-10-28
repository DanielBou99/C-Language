#include <stdio.h>
#include <string.h>

// Contador da maior sequencia de espacos na string

int main(){


char nome[20];
int i,s=0,ts=0;

scanf("%19[^\n]", nome);

for (i=0; nome[i] != '\0'; i++) {

    if (nome[i] == ' ') {
        s += 1;
        if (s > ts) {
            ts = s;
        }
    } else {
    s = 0;
    }


}


printf("Total de espacos = %d", ts);




return 0;
}
