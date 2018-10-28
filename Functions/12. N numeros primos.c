#include <stdio.h>
/* Mostrar os n numeros primos informado pelo usuario*/
int primo(int n);


int main() {

int x;

do {
    scanf("%d", &x);
} while (x <= 0);

primo(x);

}

int primo(int n) {

    int i,c=0,j=1,cf=1;

while (cf <= n) {

for (i=1;i<=j;i++) {
    if (j % i == 0) {
        c+=1;
    }
}

if (c==2) {
    printf(" %d /", j);
    cf +=1;
}

j+=1;
c=0;

}

}
