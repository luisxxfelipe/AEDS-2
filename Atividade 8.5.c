#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5

typedef struct pilha
{
    int topo;
    int vet[MAX];
} Pilha;

typedef struct fila
{
    int comeco;
    int fim;
    int vet[MAX];
} Fila;

void criarPilha(Pilha *p);
void empilha(Pilha *p, int n);
void desempilha(Pilha *p);
void criarFila(Fila *f);
void enfileirar(Fila *f, int n);
void desenfileirar(Fila *f);
void trocaPpilha(Pilha *p, Fila *f);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    Fila *f = (Fila *)malloc(sizeof(Fila));
    criarPilha(p);
    criarFila(f);
    inserir(f);
    trocaPpilha(f, p);

    return 0;
}
void criarPilha(Pilha *p)
{
    p->topo = -1;
}
void empilha(Pilha *p, int n)
{
    p->vet[p->topo] = n;
    p->topo++;
}
void desempilha(Pilha *p)
{
    p->topo--;
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
void desenfileirar(Fila *f)
{
    f->comeco++;
}
void trocaPpilha(Pilha *p, Fila *f)
{
    for (int i = 0; i < MAX; i++)
    {
        f->vet[f->comeco] = p->topo;
        p->topo++;
    }
    printf("\nPilha que foi preenchida atráves da Fila:");
    for (int i = p->topo; i > 0; i--)
    {
        printf("\n%d", p->vet[i]);
    }
}
void inserir(Fila *f)
{
    int vet[MAX];
    printf("Inserir os elementos da fila: ");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &vet[i]);
        enfileirar(f, vet[i]);
    }
}
