#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* esse programa tem por finalidade criar urnas aleatórias
e  */


int criarurnas(int siglas[]);
int apuraurnas(int siglas[]);

#define ELEITORES 1000000

int eleitores[ELEITORES];

int main() {

int controle;

int siglas[15];

siglas[0] = 19;
siglas[1] = 51;
siglas[2] = 12;
siglas[3] = 27;
siglas[4] = 13;
siglas[5] = 45;
siglas[6] = 50;
siglas[7] = 15;
siglas[8] = 17;
siglas[9] = 30;
siglas[10] = 54;
siglas[11] = 18;
siglas[12] = 16;
siglas[13] = 1;
siglas[14] = 2;

do {

    printf("-->MENU\n1 - Criar Urnas\n2 - Apurar Urnas\n0 - Sair\n>>> ");
    scanf("%d", &controle);

    switch (controle) {

        case 1:
        system("cls");
        criarurnas(siglas);
        break;
        case 2:
        system("cls");
        apuraurnas(siglas);
        break;
        default:
        printf("\a");
    }
system("cls");
} while (controle != 0);

return 0;
}

int criarurnas(int siglas[]) {

srand( (unsigned)time(NULL) );

int i,j,aux;

for (i=0; i < 24; i++) {


    for (j=0; j < ELEITORES; j++) {
        aux = rand() % 15;
        eleitores[j] = siglas[aux];
    }

char urna[20] = "urna";
char buffer[10];

itoa (i,buffer,10);

strcat(urna,buffer);
strcat(urna,".bin");

FILE * aurna;

aurna= fopen(urna,"wb");

if (aurna == NULL) {
    printf("Nao foi possivel criar o arquivo.");
    return 1;
} else {
printf("Criando o %d arquivo . . .\n", i+1);
}


fwrite(eleitores, sizeof(int), ELEITORES, aurna);

fclose(aurna);

}

system("cls");
}


int apuraurnas(int siglas[]) {

int ksiglas[15] = {0};

int i,j,k;

for (i=0; i < 24; i++) {

char urna[20] = "urna";
char buffer[10];

itoa (i,buffer,10);

strcat(urna,buffer);
strcat(urna,".bin");

FILE * aurna;

aurna= fopen(urna,"rb");

if (aurna == NULL) {
    printf("Nao foi possivel criar o arquivo.");
    return 1;
} else {
printf("Apurando o %d arquivo . . .\n", i+1);
}

fread(eleitores, sizeof(int), ELEITORES, aurna);

for (j=0; j < ELEITORES; j++) {

for (k = 0 ; k < 15; k++) {

    if (eleitores[j] == siglas[k]) {
        ksiglas[k] += 1;
    }

}

}

}



system("cls");

    /*NOME DOS CANDIDATOS*/

int auxi;
char aux[100],c='c';
char candidatos[15][100] =  {
                        {"Alvaro Dias"},
                        {"Cabo Daciolo"},
                        {"Ciro Gomes"},
                        {"Eymael"},
                        {"Fernando Haddad"},
                        {"Geraldo Alckmin"},
                        {"Guilherme Boulos"},
                        {"Henrique Meirelles"},
                        {"Jair Bolsonaro"},
                        {"Joao Amoedo"},
                        {"Joao Vicente Gourlat"},
                        {"Marina Silva"},
                        {"Vera Lucia"},
                        {"Brancos"},
                        {"Nulos"}
                        };


    /* ORDEM CRESCENTE*/

do {

   c = 's';

   for (i=0; i < 14; i++) {

    if (ksiglas[i] > ksiglas[i+1]) {
    c = 'c';

    auxi = ksiglas[i];
    ksiglas[i] = ksiglas[i+1];
    ksiglas[i+1] = auxi;

    strcpy(aux,candidatos[i]);
    strcpy(candidatos[i],candidatos[i+1]);
    strcpy(candidatos[i+1],aux);

    }

    }
} while (c == 'c');

/* ORGANIZAR DISTANCIA ENTRE COLUNAS */
for (i=0; i < 15; i++) {

j = strlen(candidatos[i]);

    for (j; j < 25; j++) {
    candidatos[i][j] = ' ';
    }

candidatos[i][j] = '\0';
}



/*MOSTRAR RESULTADO*/

printf("|Candidato\t\t  |Votos    |  %%   |\n");
for (i=0; i < 15; i++) {
    printf("|%s| %d | %.2f%%| \n", candidatos[i] ,ksiglas[i], 100.0*ksiglas[i] / 24000000.0);
}

system("pause");
}
