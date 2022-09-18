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
int maior(Pilha *p);
int menor(Pilha *p);
float media(Pilha *p);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    criarPilha(p);
    inserir(p);

    printf("\nMaior elemento: %d", maior(p));
    printf("\nMenor elemento: %d", menor(p));
    printf("\nMédia: %0.2f", media(p));

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
    for (int i = 0; i < MAX; i++)
    {
        printf("Insira o %dº elemento do vetor: ", i + 1);
        scanf("%i", &vetor[i]);
        empilhar(p, vetor[i]);
    }
    printf("\nVetor: ");
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d ", vetor[i]);
    }
    printf("\nPilha do vetor: ");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("\n%d", vetor[i]);
    }
}
int maior(Pilha *p)
{
    int maior = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (p->vet[i] > maior)
        {
            maior = p->vet[i];
        }
    }
    return maior;
}
int menor(Pilha *p)
{
    int menor = 999;
    for (int i = 0; i < MAX; i++)
    {
        if (p->vet[i] < menor)
        {
            menor = p->vet[i];
        }
    }
    return menor;
}
float media(Pilha *p)
{
    float soma;
    for (int i = 0; i < MAX; i++)
    {
        soma += p->vet[i];
    }
    return soma / MAX;
}
