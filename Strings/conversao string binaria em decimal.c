#include <stdio.h>
#include <string.h>

int main() {

char binario[7];
int i,t=0,m=2;

scanf("%6[^\n]", binario);

if (binario[5] == '1') {
    printf("TESTE");
    t += 1;
}


for (i= strlen(binario)-2; i>=0 ; i--) {

    if (binario[i] == '1') {
        t += m;
        printf("\n %d", t);
    }

    m *= 2;
}

printf("Valor em decimais= %d", t);



    return 0;
}
