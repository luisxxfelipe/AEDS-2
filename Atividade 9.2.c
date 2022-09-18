#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct fila
{
    Elemento *inicio;
    Elemento *final;
} Fila;

void criarFila(Fila *f);
void enfileirar(Fila *f, int valor);
void imprime(Fila *f);
int quantidade(Fila *f);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila *f = (Fila *)malloc(sizeof(Fila));
    Fila *aux = (Fila *)malloc(sizeof(Fila));

    criarFila(f);
    criarFila(aux);

    int op, n, qtA, qtB;
    do
    {
        printf("\n[1]Inserir elemento Fila A\n");
        printf("[2]Inserir elemento Fila B\n");
        printf("[3]Imprimir a Fila A\n");
        printf("[4]Imprimir a Fila B\n");
        printf("[5]Maior Fila\n");
        printf("[0]Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &n);
            enfileirar(f, n);
            break;
        case 2:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &n);
            enfileirar(aux, n);
            break;
        case 3:
            imprime(f);
            break;
        case 4:
            imprime(aux);
            break;
        case 5:
            qtA = quantidade(f);
            qtB = quantidade(aux);
            printf("\nQuantidade elementos Fila A: %d", qtA);
            printf("\nQuantidade elementos Fila B: %d", qtB);
            if (qtA > qtB)
            {
                printf("\nMaior = Fila A");
            }
            else
            {
                printf("\nMaior = Fila B");
            }
            break;
        case 0:
            printf("\nSaindo...");
            break;
        }
    } while (op != 0);

    return 0;
}
void criarFila(Fila *f)
{
    f->inicio = NULL;
    f->final = NULL;
}
void enfileirar(Fila *f, int valor)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    if (e == NULL)
    {
        printf("Erro alocação");
        return;
    }
    else
    {
        e->valor = valor;
        e->proximo = NULL;
        if (f->inicio == NULL)
        {
            f->inicio = e;
        }
        else
        {
            f->final->proximo = e;
        }
        f->final = e;
    }
}
void imprime(Fila *f)
{
    Elemento *e = f->inicio;
    if (f->inicio != NULL)
    {
        while (e != NULL)
        {
            printf("\n%d", e->valor);
            e = e->proximo;
        }
    }
    else
    {
        printf("\nFila vazia");
    }
}
int quantidade(Fila *f)
{
    Elemento *e;
    int qt = 0;
    for (e = f->inicio; e != NULL; e = e->proximo)
    {
        qt++;
    }
    return qt;
}
