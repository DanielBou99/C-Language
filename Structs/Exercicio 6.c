#include <stdio.h>
#include <string.h>

/*6. Faça um programa que utilize as seguintes informações:
Médicos Pacientes Consultas
Código do médico Código do paciente Número do Prontuário
Nome Nome do paciente Data da consulta
Especialidade Sexo Horário da consulta
Idade Código do médico
Código do paciente
a) Crie rotinas para realizar a inclusão no cadastro de médicos e pacientes;
b) Crie rotinas para listar todos os médicos e pacientes cadastrados;
c) Crie uma rotina para cadastrar uma consulta. Verifique se o código do médico e do
paciente existem. Não permita que duas ou mais consultas sejam marcadas no mesmo
dia e horário para o mesmo médico;
d) Crie uma rotina para mostrar todas as consultas realizadas por um médico numa data
qualquer, escolhidos pelo usuário.
*/

struct medicos {

    int codigo;
    char nome[50];
    char especialidade[50];

};

struct pacientes {

    int codigo;
    char nome[50];
    char sexo[50];
    int idade;

};

struct consultas {

    int prontuario;
    char data[10];
    char horario[6];
    int codigo_medico;
    int codigo_paciente;

};

void cadastroMedico(struct medicos[], int *);
void cadastroPaciente(struct pacientes[], int *);
void listaMedicos(struct medicos[], int);
void listaPacientes(struct pacientes[], int);
void criarConsulta(struct pacientes pacientes[], struct medicos medicos[], struct consultas[], int *, int *, int *);
void listaConsulta(struct medicos[],int*,struct consultas[],int*);

int main() {

struct medicos medicos[50];
struct pacientes pacientes[50];
struct consultas consultas[50];

char c;
int k=0, kc=0, kp=0;

do {

    printf("***MENU***\n");
    printf("a - cadastrar medico.\n");
    printf("b - cadastrar paciente.\n");
    printf("c - lista de medicos.\n");
    printf("d - lista de pacientes.\n");
    printf("e - criar consulta.\n");
    printf("f - lista de consultas.\n");
    printf("s - sair.\n");
    scanf("%c", &c);
    fflush(stdin);

        switch(c) {

            case 'a':
                system("cls");
                cadastroMedico(medicos,&k);
                system("pause");
                system("cls");
                break;

            case 'b':
                system("cls");
                cadastroPaciente(pacientes,&kp);
                system("pause");
                system("cls");
                break;

            case 'c':
                system("cls");
                listaMedicos(medicos,k);
                system("pause");
                system("cls");
                break;

            case 'd':
                system("cls");
                listaPacientes(pacientes,kp);
                system("pause");
                system("cls");
                break;

            case 'e':
                system("cls");
                criarConsulta(pacientes,medicos,consultas,&kc,&k,&kp);
                system("pause");
                system("cls");
                break;

            case 'f':
                system("cls");
                listaConsulta(medicos,&k,consultas,&kc);
                system("pause");
                system("cls");
            case 's':
                break;

            default:
                fflush(stdin);
                printf("Opcao invalida.\n");
                system("pause");
                break;

                    }

} while (c!='s');

}

void cadastroMedico(struct medicos medicos[], int *k) {

    char c;
    int i,codigo;

        c ='t';

        printf("Codigo do medico: ");
        scanf("%d", &codigo);
        fflush(stdin);

        for (i=0; i < *k; i++) {
            if (medicos[i].codigo == codigo) {
                printf("O codigo ja existe.\n");
                c = 'f';
            }
        }

    if (c == 't') {

        medicos[*k].codigo = codigo;

        printf("Nome do medico: ");
        scanf("%49[^\n]", medicos[*k].nome);
        fflush(stdin);
        printf("Especialidade: ");
        scanf("%49[^\n]", medicos[*k].especialidade);
        fflush(stdin);

        *k += 1;
        printf("Cadastro feito com sucesso!\n");

    }
}

void cadastroPaciente(struct pacientes pacientes[], int * kp) {

    int codigo,i;
    char c='t';


    printf("Codigo do paciente: ");
    scanf("%d", &codigo);
    fflush(stdin);

    for (i=0; i<*kp; i++) {
        if (codigo == pacientes[i].codigo) {
            c = 'f';
            printf("Codigo ja existe.\n");
        }
    }

    if (c == 't') {

        pacientes[*kp].codigo = codigo;

        printf("Nome do paciente: ");
        scanf("%49[^\n]", pacientes[*kp].nome);
        fflush(stdin);
        printf("Sexo: ");
        scanf("%49[^\n]", pacientes[*kp].sexo);
        fflush(stdin);
        printf("idade: ");
        scanf("%d", &pacientes[*kp].idade);
        fflush(stdin);
        *kp += 1;
        printf("Cadastro feito com sucesso!\n");

    }

}

void listaMedicos(struct medicos medicos[], int k) {

    int i;

    for (i=0; i < k; i++) {

        printf("Codigo do medico: %d\n", medicos[i].codigo);
        printf("Nome: %s\n", medicos[i].nome);
        printf("Especialidade: %s\n\n", medicos[i].especialidade);


    }

}

void listaPacientes(struct pacientes pacientes[], int kp) {

    int i;

    for (i=0; i < kp; i++) {

        printf("Codigo: %d\n", pacientes[i].codigo);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Sexo: %s\n", pacientes[i].sexo);
        printf("Idade: %d\n\n", pacientes[i].idade);

    }



}

void criarConsulta(struct pacientes pacientes[], struct medicos medicos[], struct consultas consultas[], int *kc, int *k, int *kp) {

    int cm,cp,i;
    char c, data[10],hora[6];


    do {

        system("cls");

        printf("Codigo do medico: ");
        scanf("%d", &cm);
        fflush(stdin);

        /* VERIFICAR SE O MEDICO EXISTE*/

        for (i=0; i<*k; i++) {
            if (cm == medicos[i].codigo) {
               c = 't';
            }
        }

        if (c!='t') {
            printf("Codigo incorreto.\n");
            system("pause");
        }

    } while (c != 't');

    c = 'f';

    do {
        system("cls");
        printf("Codigo do medico: %d\n\n", cm);

        printf("Codigo do paciente: ");
        scanf("%d", &cp);
        fflush(stdin);

        /* VERIFICAR SE O PACIENTE EXISTE*/

        for (i=0; i<*kp; i++) {
            if (cp == pacientes[i].codigo) {
               c = 't';
            }
        }

        if (c!='t') {
            printf("Codigo incorreto.\n");
            system("pause");
        }

    } while (c != 't');


    do {

        system("cls");
        printf("Codigo do medico:   %d\n", cm);
        printf("Codigo do paciente: %d\n\n", cp);

        c = 't';

        printf("Data da consulta (Infome da seguinte maneira DD-MM-AA): ");
        scanf("%8[^\n]", data);
        fflush(stdin);

        printf("Horario da consulta (Informe da seguinte maneira HH:MM): ");
        scanf("%5[^\n]", hora);
        fflush(stdin);

        /*VERIFICAR SE NÃO HÁ OUTRA CONSULTA NO MESMO DIA/HORARIO*/

        for (i=0; i < *kc; i++) {

            if ( (strcmp(data,consultas[i].data) == 0) && (strcmp(consultas[i].horario,hora) == 0) ) {
                printf("Horario invalido. O medico ja possui uma consulta marcada.\n");
                c = 'f';
                system("pause");
                break;
            }
        }

    } while(c != 't');

    printf("Numero do prontuario: %d", *kc);

    consultas[*kc].prontuario = *kc;
    strcpy(consultas[*kc].data,data);
    strcpy(consultas[*kc].horario,hora);
    consultas[*kc].codigo_medico = cm;
    consultas[*kc].codigo_paciente = cp;

    *kc += 1;

}

void listaConsulta(struct medicos medicos[],int *k,struct consultas consultas[],int *kc) {

    char data[10],medico[50],c;
    int i,codigo;

    printf("Digite o nome do medico: ");
    scanf("%49[^\n]", medico);
    fflush(stdin);
    printf("Data das consultas (Infome da seguinte maneira DD-MM-AA): ");
    scanf("%8[^\n]", data);
    fflush(stdin);

    c = 'f';

    for (i=0; i < *k; i++) {
        if (strcmp(medico,medicos[i].nome) == 0) {
            codigo = medicos[i].codigo;
            c = 't';
            break;
        }
    }

    if (c == 'f') {
        printf("Medico nao existe.\n");
    } else {
        printf("CONSULTAS DO MEDICO %s NO DIA %s.\n\n",medico,data);
        for (i=0; i < *kc; i++) {
            if ( (codigo==consultas[i].codigo_medico) && (strcmp(data,consultas[i].data)==0) ) {
                printf("Numero do prontuario: %d\n", consultas[i].prontuario);
                printf("data da consulta: %s\n", consultas[i].data);
                printf("Horario da consulta: %s\n", consultas[i].horario);
                printf("Codigo do medico: %d\n", consultas[i].codigo_medico);
                printf("Codigo do paciente: %d\n\n", consultas[i].codigo_paciente);
            }
        }
    }
}
