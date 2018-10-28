#include <stdio.h>
#include <math.h>

/* 1)Considere a estrutura struct circulo
definida anteriormente e escreva um
programa que dados dois círculos,
verifique se eles se sobrepõem. Dois
círculos se sobrepõem se a distância
entre os centros destes círculos é menor
que a soma de seus raios. Distância
entre dois pontos:
d= (EQUACAO)
*/


struct ponto {
    float x;
    float y;
};

struct circulo {
    struct ponto centro;
    float raio;
};

int main() {

float d;
struct circulo c[2];

printf("Digite a coordenada x do circulo 1: ");
scanf("%f", &c[0].centro.x);
printf("Digite a coordenada y do circulo 1: ");
scanf("%f", &c[0].centro.y);
printf("Digite o raio do circulo 1: ");
scanf("%f", &c[0].raio);

printf("Digite a coordenada x do circulo 2: ");
scanf("%f", &c[1].centro.x);
printf("Digite a coordenada y do circulo 2: ");
scanf("%f", &c[1].centro.y);
printf("Digite o raio do circulo 2: ");
scanf("%f", &c[1].raio);


d = sqrt( (pow((c[0].centro.x-c[1].centro.x),2)) + (pow((c[0].centro.y-c[1].centro.y),2)) );



if (d < (c[1].raio + c[0].raio)) {
    printf("os circulos se sobrepoem!\n");
} else{
    printf("nao se sobrepoem!\n");
}



return 0;
}


