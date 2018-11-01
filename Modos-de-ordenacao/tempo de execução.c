#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

void insertion(int vet[]);
void bubbleSortString(int , int*);
void selecao(int, int*);
void quicksort(int *, int, int);
static int separa (int *, int, int);

int main() {

int t;
t = time(0);

srand ( (unsigned)time(NULL) );



int vet[MAX];
register int i;

for (i=0; i < MAX; i++) {
    vet[i] = 1 + ( rand() % 10000 );
}

//insertion(vet);
//bubbleSortString(MAX,vet);
//(MAX, vet);
quicksort(vet, 0, MAX);

for (i=0; i < MAX; i++) {
    printf("%d\n", vet[i]);
}


printf("Tempo total = %ld ",time(0) - t);

return 0;

}

void insertion(int v[]) {

    int i,j,aux;

    for (i=1; i < MAX; i++) {

        aux = v[i];
        j = i - 1;

        while ((j >= 0) && (aux < v[j])) {

            v[j+1] = v[j];
            j--;
        }

        v[j+1] = aux;
    }

}

void bubbleSortString(int n, int v[]){

  int temp;
  int i,j;
  for(i = 1; i < n; i++){
       for (j = 0; j < n-1; j++){

          if(v[j] > v[j+1]){
                 temp = v[j];
                 v[j] = v[j+1];
                 v[j+1] = temp;
          }
       }
  }

}

void selecao (int n, int v[])
{
    int i,j;
    for (i = 0; i < n-1; ++i)
    {
        int min = i;
        for (j = i+1; j < n; ++j)
            if (v[j] < v[min])  min = j;
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

static int separa (int v[], int p, int r) {
   register int c = v[r]; // pivô
   register int k,t, j = p;
   for (k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j;
      }
   t = v[j], v[j] = v[r], v[r] = t;
   return j;
}

void quicksort (int v[], int p, int r)
{
   if (p < r) {                   // 1
      register int j = separa (v, p, r);   // 2
      quicksort (v, p, j-1);      // 3
      quicksort (v, j+1, r);      // 4
   }
}

