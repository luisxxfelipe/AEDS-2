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
int maior(Fila *f);
int menor(Fila *f);
float media(Fila *f);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila *f = (Fila *)malloc(sizeof(Fila));
    criarFila(f);
    inserir(f);
    printf("\nMaior = %d", maior(f));
    printf("\nMenor = %d", menor(f));
    printf("\nMédia = %0.2f", media(f));

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
        scanf("%