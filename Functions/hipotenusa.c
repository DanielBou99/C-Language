#include <stdio.h>
#include <math.h>

double hipotenusa(double,double);

int main() {

double x,y;

scanf("%lf %lf", &x, &y);

hipotenusa(x,y);


    return 0;
}

double hipotenusa(double x, double y) {
double t;

t +=  pow(x,2);
t +=  pow(y,2);
t = sqrt(t);
printf("%lf \n", t);

return t;
}
