#include <stdio.h>
#include <string.h>

int main() {

    char a[50];

    scanf("%49[^\n]", a);

    strrev(a);

    printf("%s", a);




    return 0;
}
