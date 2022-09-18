#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5

typedef struct pilha
{
    int topo;
    int vet[MAX];
} Pilha;

void criarPilha(Pilha *p);
void empilha(Pilha *p, int n);
int desempilha(Pilha *p);
void imprime(Pilha *p);
void imprimeInvertida(Pilha *p);

int main()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    criarPilha(p);
    inserir(p);
    imprime(p);
    imprimeInvertida(p);

    return 0;
}

void criarPilha(Pilha *p)
{
    p->topo = 0;
}
void empilha(Pilha *p, int n)
{
    p->vet[p->topo] = n;
    p->topo++;
}
void inserir(Pilha *p)
{
    int vetor[MAX];
    int i;
    printf("\nInsira os elementos da pilha: ");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &vetor[i]);
        empilha(p, vetor[i]);
    }
}
void imprime(Pilha *p)
{
    printf("\nElementos na pilha: ");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("\n%d", p->vet[i]);
    }
}
void imprimeInvertida(Pilha *p)
{
    int i;
    printf("\nPilha Invertida: ");
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d", p->vet[i]);
    }
}
