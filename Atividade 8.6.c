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
void empilhar(Pilha *p, int n);
void inserir(Pilha *p);
int impar(Pilha *p, int vetor[]);
void imprime(Pilha *p);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    int vetor[MAX];
    int aux;

    criarPilha(p);
    inserir(p);

    return 0;
}

void criarPilha(Pilha *p)
{
    p->topo = 0;
}
void empilhar(Pilha *p, int n)
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
        empilhar(p, vetor[i]);
    }
    imprime(p);
    int aux = 0;
    for (i = 0; i < MAX; i++)
    {
        if (vetor[i] % 2 != 0)
        {
            aux++;
        }
    }
    printf("\n\nÍmpares = %d", aux);
}
void imprime(Pilha *p)
{
    printf("\nElementos na pilha: ");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("\n%d", p->vet[i]);
    }
}
