#include <stdio.h>

int fatorial(int a);

int main() {

    int a;

    printf("Digite o numero a ser fatorado: ");
    scanf("%d", &a);

    a = fatorial(a);

    printf("O numero fatorado eh %d", a);
    return 0;
}

int fatorial(int a) {

int t=1;

do {
    t *= a;
    a--;
} while(a > 0);

return t;
}
