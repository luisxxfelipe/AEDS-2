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
int par(Fila *f);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila *f = (Fila *)malloc(sizeof(Fila));
    criarFila(f);
    inserir(f);
    printf("\nQuantidade números pares: %d", par(f));

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
    int i;
    printf("Insira os elementos da fila: ");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &vetor[i]);
        enfileirar(f, vetor[i]);
    }
}
int par(Fila *f)
{
    int i;
    int aux = 0;
    for (i = 0; i < MAX; i++)
    {
        if (f->vet[i] % 2 == 0)
        {
            aux++;
        }
    }
    return aux;
}
