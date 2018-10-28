#include <stdio.h>

/* 4. Escreva um programa em C que define estruturas para representar as seguintes entidades:
a) Processador: tem como características a frequência e o fabricante;
b) Monitor:   tem   como   características   o   tamanho   (em   polegadas),   o   tipo   (LCD,   CRT,
Plasma, etc.) e o fabricante;
c) Computador: tem como características o processador, o monitor, a capacidade de disco
rígido e de memória RAM.
O programa deve cadastrar n computadores e depois listar os dados daqueles computadores
com processador com frequência superior 2 GHz, com monitor maior que 17” e capacidade
de memória RAM maior ou igual a 4 GB */

struct Processador {
    int Frequencia;
    char Fabricante[20];
};

struct Monitor {
    int Tamanho;
    char Tipo[20];
    char Fabricante [20];
};

struct Computador {
    struct Processador Processador;
    struct Monitor Monitor;
    int CapacidadeDisco;
    int MemoriaRAM;
};

void scan(int, struct Computador[]);
void print(int, struct Computador[]);

int main () {

int i,n;

printf("Quantidade de computadores:\n>>>>");
scanf("%d", &n);

struct Computador Computador[n];

for (i=0; i < n; i++) {
    system("cls");
    printf("***COMPUTADOR %d***\n\n", i+1);
    scan(i, Computador);
}

system("cls");

printf("****************************************************************\n");

for (i=0; i < n; i++) {

    if ((Computador[i].Processador.Frequencia > 2) && (Computador[i].Monitor.Tamanho > 17) && (Computador[i].MemoriaRAM >= 4)) {

        print(i, Computador);
        printf("****************************************************************\n");

    }
}


    return 0;
}

void scan(int i, struct Computador Computador[]) {

printf("***PROCESSADOR***\n");
printf("Informe a frequencia: ");
scanf("%d", &Computador[i].Processador.Frequencia);
fflush(stdin);
printf("Informe o fabricante: ");
scanf("%19[^\n]", Computador[i].Processador.Fabricante);
fflush(stdin);
printf("\n\n");

printf("***MONITOR***");
printf("Informe o tamanho em polegadas: ");
scanf("%d", &Computador[i].Monitor.Tamanho);
fflush(stdin);
printf("Informe o tipo: ");
scanf("%19[^\n]", Computador[i].Monitor.Tipo);
fflush(stdin);
printf("Informe o fabricante: ");
scanf("%19[^\n]", Computador[i].Monitor.Fabricante);
fflush(stdin);
printf("\n\n");

printf("***COMPUTADOR***");
printf("Informe a capacidade do disco rigido: ");
scanf("%d", &Computador[i].CapacidadeDisco);
fflush(stdin);
printf("Informe a capacidade da memoria RAM: ");
scanf("%d", &Computador[i].MemoriaRAM);
fflush(stdin);

}

void print(int i, struct Computador Computador[]) {

printf("***PROCESSADOR***\n");
printf("Frequencia: %d\n", Computador[i].Processador.Frequencia);
printf("Fabricante: %s\n", Computador[i].Processador.Fabricante);
printf("***MONITOR***\n");
printf("Tamanho: %d\n", Computador[i].Monitor.Tamanho);
printf("Tipo: %s\n", Computador[i].Monitor.Tipo);
printf("Fabricante: %s\n", Computador[i].Monitor.Fabricante);
printf("***Computador***\n");
printf("Disco Rigido: %d\n", Computador[i].CapacidadeDisco);
printf("Memoria RAM: %d\n", Computador[i].MemoriaRAM);
}
