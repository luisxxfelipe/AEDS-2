#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct lista
{
    int valores[MAX];
    int fim;
} Lista;

Lista *criarLista();
void lerValores(Lista *l, int quantidade);
void imprimirLista(Lista *l);
int liberaLista(Lista *l);
int estaCheia(Lista *l);
int estaVazia(Lista *l);
int inserir(Lista *l, int e);
int remover(Lista *l, int **r);

int numerosPares(Lista *l);  // Função exercício 06
Lista *listaPares(Lista *l); // Função do exercício 07
int listaOrdenada(Lista *l); // Função do exercício 08

int main()
{
    Lista *l = criarLista();
    Lista *lista_pares = (Lista *)malloc(sizeof(Lista));

    int pares, lista_ordenada;

    lerValores(l, 5);
    pares = numerosPares(l);
    imprimirLista(l);

    printf("Informe os numeros pares: %d\n\n", pares);

    printf("Nova lista com os elementos pares: ");
    lista_pares = listaPares(l);
    imprimirLista(lista_pares);
    printf("\n\n");

    lista_ordenada = listaOrdenada(l);
    if (lista_ordenada)
    {
        printf("A lista esta ordenada!\n\n");
    }
    else
    {
        printf("NAO ESTA ORDENADA!\n\n");
    }

    return 1;
}

Lista *criarLista()
{
    Lista *p = (Lista *)malloc(sizeof(Lista));
    p->fim = -1;

    return p;
}

void lerValores(Lista *l, int quantidade)
{
    int i, valor;

    system("cls");
    for (i = 0; i < quantidade; i++)
    {
        printf("Informe o valor a ser inserido na lista: ");
        scanf("%d", &valor);
        inserir(l, valor);
    }
}

void imprimirLista(Lista *l)
{
    int i;

    printf("\n\n");
    for (i = 0; i <= l->fim; i++)
    {
        printf(" %d", l->valores[i]);
    }
    printf("\n\n");
}

int liberaLista(Lista *l)
{
    free(l);
    return 1;
}

int estaCheia(Lista *l)
{
    return l->fim == MAX;
}

int estaVazia(Lista *l)
{
    return l->fim == -1;
}

int inserir(Lista *l, int e)
{
    if (!estaCheia(l))
    {
        l->fim++;
        l->valores[l->fim] = e;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remover(Lista *l, int **r)
{
    if (!estaVazia(l))
    {
        **r = l->valores[l->fim];
        l->fim--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int numerosPares(Lista *l)
{
    int i, pares = 0;

    for (i = 0; i <= l->fim; i++)
    
    {
        if (l->valores[i] % 2 == 0)
        {
            pares++;
        }
    }

    return pares;
}

Lista *listaPares(Lista *l)
{
    Lista *nova_lista = (Lista *)malloc(sizeof(Lista));
    nova_lista->fim = -1;
    int i;

    for (i = 0; i <= l->fim; i++)
    {
        if (l->valores[i] % 2 == 0)
        {
            inserir(nova_lista, l->valores[i]);
        }
    }

    return nova_lista;
}

int listaOrdenada(Lista *l)
{
    int i;
    int lista_ordenada_crescente = 0;
    int lista_ordenada_decrescente = 0;

    for (i = 0; i < l->fim; i++)
    {
        if (l->valores[i] <= l->valores[i + 1])
        {
            lista_ordenada_crescente = 1;
        }
        else
        {
            lista_ordenada_crescente = 0;
            i = l->fim;
        }
    }

    for (i = 0; i < l->fim; i++)
    {
        if (l->valores[i] >= l->valores[i + 1])
        {
            lista_ordenada_decrescente = 1;
        }
        else
        {
            lista_ordenada_decrescente = 0;
            i = l->fim;
        }
    }

    if (lista_ordenada_crescente || lista_ordenada_decrescente)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}