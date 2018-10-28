#include <stdio.h>

void retangulo(int,int);

int main() {

int l,a;

scanf("%d %d", &l,&a);
retangulo(l,a);

return 0;
}

void retangulo(int l,int a) {

int i,j;

for (i=1; i <= l; i++) {
    for (j=1; j<= a; j++) {
        printf("*");
    }
    printf("\n");
}

}
