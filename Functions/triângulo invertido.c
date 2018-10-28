#include <stdio.h>

void triangulo(int,char);

int main() {

int n;
char ch;

printf("Digite o tamanho do triangulo: ");
scanf("%d", &n);
printf("Digite o caractere: ");
scanf(" %c", &ch);

triangulo(n,ch);

return 0;

}

void triangulo(int n, char ch) {

int i;
int j=0;

do {

for (i=1; i<=j; i++) {
    printf(" ");
}

for (i=1; i<=n;i++) {
    printf("%c", ch);
}

printf("\n");
j += 1;
n -= 2;

} while (n >= 0);



}










