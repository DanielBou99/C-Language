#include <stdio.h>
#include <string.h>

int main () {

char s1[33],s2[11],s3[11],s4[11];


    scanf("%10[^\n]", s1);
    fflush(stdin);
    scanf("%10[^\n]", s2);
    fflush(stdin);
    scanf("%10[^\n]", s3);
    fflush(stdin);
    scanf("%10[^\n]", s4);
    fflush(stdin);

    strcat(s1,s2);
    strcat(s1,s3);
    strcat(s1,s4);

    puts(s1);



    return 0;
}
