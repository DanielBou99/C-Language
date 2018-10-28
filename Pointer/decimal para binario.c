#include <stdio.h>
#include <math.h>

void conversao(int*);
int conversaobtd(int n[], int);

int main()
{

    int d;

    printf("Decimal>>> ");
    scanf("%d", &d);

    conversao(&d);

    printf("Binario>>> %d", d);

    return 0;
}

void conversao(int * d)
{
    int v[100],iv=0;

    while (*d != 0)
    {
        v[iv] = *d % 2;
        *d = *d / 2;
        iv += 1;
    }

    iv -= 1;

    int vc[iv],i,ic=iv;

    for (i=0; i <= iv; i++)
    {
        vc[i] = v[ic];
        ic = ic - 1;
    }


    *d = conversaobtd(vc, iv);


}

int conversaobtd(int n[],int t)
{

    int i,d=0,aux= pow(10,t);

    for (i=0; i<=t; i++)
    {

        if (n[i] != 0)
        {
            d = d + aux;
            aux = aux / 10;
        }
        else
        {
            aux = aux / 10;
        }

    }

    return d;
}
