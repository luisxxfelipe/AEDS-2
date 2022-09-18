#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct elemento
{
    int valor;
    struct elemento *anterior;
} Elemento;

typedef struct pilha
{
    Elemento *topo;
} Pilha;

Pilha *criaPilha();
int empilha(Pilha *p, int v);
void imprime(Pilha *p);
int quantidade(Pilha *p);

int main()
{
    Pilha *p, *aux;
    p = criaPilha();
    aux = criaPilha();

    int op, v, qtA, qtB;
    do
    {
        printf("\n[1]Inserir elemento pilha A\n");
        printf("[2]Inserir elemento pilha B\n");
        printf("[3]Imprimir a pilha A\n");
        printf("[4]Imprimir a pilha B\n");
        printf("[5]Maior pilha\n");
        printf("[0]Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &v);
            empilha(p, v);
            break;
        case 2:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &v);
            empilha(aux, v);
            break;
        case 3:
            imprime(p);
            break;
        case 4:
            imprime(aux);
            break;
        case 5:
            qtA = quantidade(p);
            qtB = quantidade(aux);
            printf("\nQuantidade elementos pilha A: %d", qtA);
            printf("\nQuantidade elementos pilha B: %d", qtB);
            if (qtA > qtB)
            {
                printf("\nMaior = pilha A");
            }
            else
            {
                printf("\nMaior = pilha B");
            }
            break;
        case 0:
            printf("\nSaindo...");
            break;
        }
    } while (op != 0);

    return 0;
}
Pilha *criaPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
int empilha(Pilha *p, int v)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->valor = v;
    e->anterior = p->topo;
    p->topo = e;

    return v;
}
void imprime(Pilha *p)
{
    Elemento *e = p->topo;
    while (e != NULL)
    {
        printf("\n%d", e->valor);
        e = e->anterior;
    }
}
int quantidade(Pilha *p)
{
    Elemento *e;
    int qt;
    for (e = p->topo; e != NULL; e = e->anterior)
    {
        qt++;
    }
    return qt;
}
