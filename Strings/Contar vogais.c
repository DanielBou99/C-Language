#include <stdio.h>
#include <string.h>

// Contador de vogais

int main() {

char a[50];
int i,k=0;

scanf("%49[^\n]", a);

for(i=0; a[i] != '\0'; i++) {
    if (a[i]=='a' || a[i]=='A' || a[i]=='e' || a[i]=='E' || a[i]=='i' || a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='u' || a[i]=='U') {
        k += 1;
    }
}

printf("\nPossui %d vogais!", k);



return 0;
}
