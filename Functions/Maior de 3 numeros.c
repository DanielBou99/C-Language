#include <stdio.h>

void maior(int,int,int);

int main () {

    int n1,n2,n3;

    scanf("%d %d %d",&n1,&n2,&n3);

    maior(n1,n2,n3);

}

void maior(int n1, int n2, int n3) {

    if ((n1 > n2) && (n1 > n3)) {
        printf("Maior = %d", n1);
    } else { if ((n2>n1) && (n2>n3)) {
        printf("Maior = %d",n2);
    } else{
    printf("Maior = %d", n3);
    }
    }
}


