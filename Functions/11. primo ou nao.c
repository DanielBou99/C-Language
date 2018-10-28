#include <stdio.h>

/*Verificar se o numero informado eh primo ou nao*/

int primo(int n);

int main() {

    int n;

do {
        scanf("%d", &n);

    if (primo(n)) {
        printf("EH PRIMO!");
    } else {
        printf("NAO EH PRIMO!");
            }

} while (n>=0);

    return 0;

}

int primo(int n) {

int i,c=0;

for (i=1;i<=n;i++) {
    if (n % i == 0) {
        c+=1;
    }
}

if (c==2) {
    n=1;
    } else {
        n=0;
            }

return n;
}
