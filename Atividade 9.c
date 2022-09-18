#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

typedef struct fila
{
    int comeco;
    int fim;
    int vet[MAX];
} Fila;

void criarFila(Fila *f);
void enfileirar(Fila *f, int n);
void inserir(Fila *f);
void reverso(Fila *f);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila *f = (Fila *)malloc(sizeof(Fila));
    criarFila(f);
    inserir(f);
    reverso(f);
    return 0;
}
void criarFila(Fila *f)
{
    f->comeco = 0;
    f->fim = 0;
}
void enfileirar(Fila *f, int n)
{
    f->vet[f->fim] = n;
    f->fim++;
}
void inserir(Fila *f)
{
    int vetor[MAX];
    int i, aux, j = MAX - 1;
    printf("Insira os elementos da fila: ");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &vetor[i]);
        enfileirar(f, vetor[i]);
    }
}
void reverso(Fila *f)
{
    int i, aux;
    for (i = 0; i < MAX; i++)
    {
        aux = f->vet[0];
        f->vet[0] = f->vet[MAX - 1];
        f->vet[MAX - 1] = aux;
    }
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d\n", f->vet[i]);
    }
}
