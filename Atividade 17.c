#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct lista
{
    Elemento *inicio;
    int tamanho;
} Lista;

Lista *criarLista();
int estaVazia(Lista *l);
void liberarLista(Lista *l);
int inserir(Lista *l, int v);
int remover(Lista *l, int *r);
void imprimir(Lista *l);
int preencher(Lista *l);

int removerElemento(Lista *l, int r); // Função do exercício 17

int main()
{
    Lista *l = criarLista();
    int valor;

    preencher(l);
    imprimir(l);

    printf("\n\nInforme o valor a ser removido: ");
    scanf("%d", &valor);

    system("cls");

    printf("Lista: ");
    imprimir(l);
    removerElemento(l, valor);
    printf("Lista com valor removido: ");
    imprimir(l);

    return 0;
}

Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

int estaVazia(Lista *l)
{
    return l->inicio == NULL;
}

void liberarLista(Lista *l)
{
    if (!estaVazia(l))
    {
        do
        {
            Elemento *aux;
            aux = l->inicio;
            l->inicio = aux->proximo;
            free(aux);
        } while (l->inicio != NULL);
        free(l);
    }
}

int inserir(Lista *l, int v)
{
    Elemento *novo_elemento = (Elemento *)malloc(sizeof(Elemento));
    Elemento *pAnterior, *p;

    novo_elemento->valor = v;

    for (pAnterior = NULL, p = l->inicio; p; pAnterior = p, p = p->proximo)
    {
        if (novo_elemento->valor > p->valor)
        {
            // posição encontrada
            break;
        }
    }

    if (!pAnterior)
    { // inserir na primeira posição
        novo_elemento->proximo = p;
        l->inicio = novo_elemento;
    }
    else if (p == NULL)
    { // inserir na ultima posição
        pAnterior->proximo = novo_elemento;
        novo_elemento->proximo = NULL;
    }
    else
    { // inserir no meio
        pAnterior->proximo = novo_elemento;
        novo_elemento->proximo = p;
    }

    return 1;
}

int remover(Lista *l, int *r)
{
    Elemento *remover = (Elemento *)malloc(sizeof(Elemento));
    Elemento *aux;
    aux = l->inicio;
    remover = l->inicio->proximo;

    if (l->tamanho != 1)
    {
        while (remover->proximo != NULL)
        {
            aux = aux->proximo;
            remover = remover->proximo;
        }

        *r = remover->valor;
        aux->proximo = NULL;
        free(remover);
    }
    else
    {
        *r = aux->valor;
        free(aux);
        l->inicio = NULL;
    }

    l->tamanho--;

    return 1;
}

void imprimir(Lista *l)
{
    if (l == NULL)
    {
        printf("Lista esta vazia!\n\n");
    }
    else
    {
        Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n\n");
    }
}

int preencher(Lista *l)
{
    int i, valor;

    for (i = 0; i < 5; i++)
    {
        printf("Informe o valor a ser inserido: ");
        scanf("%d", &valor);
        inserir(l, valor);
    }
    system("cls");

    return 1;
}

int removerElemento(Lista *l, int r)
{
    Elemento *pAnt, *p;

    pAnt = NULL;
    p = l->inicio;

    while (p != NULL)
    {
        if (p->valor == r)
        {
            pAnt->proximo = p->proximo;
            free(p);
            break;
        }
        pAnt = p;
        p = p->proximo;
    }

    return 1;
}