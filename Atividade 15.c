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
void liberarLista(Lista *l);
int esta_vazia(Lista *l);
int inserir(Lista *l, int v);
int inserirPorPosicao(Lista *l, int v, int p);
int removerFinal(Lista *l, int *r);
int removerPorPosicao(Lista *l, int p, int *r);
int quantidadeItens(Lista *l);
void imprimir(Lista *l);

int inserirO(Lista *l, int v); // Função exercício 15

int main()
{
    Lista *l = criarLista();
    int i, valor;

    for (i = 0; i < 5; i++)
    {
        printf("Informe o valor a ser inserido a lista: ");
        scanf("%d", &valor);
        inserirO(l, valor);
    }
    system("cls");

    imprimir(l);

    return 1;
}

Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

void liberarLista(Lista *l)
{
    if (!esta_vazia(l))
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

int esta_vazia(Lista *l)
{
    return l->inicio == NULL;
}

int inserir(Lista *l, int v)
{
    Elemento *novo_elemento = (Elemento *)malloc(sizeof(Elemento));
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));

    aux = l->inicio;
    novo_elemento->valor = v;
    novo_elemento->proximo = NULL;
    l->tamanho++;

    if (esta_vazia(l))
    {
        l->inicio = novo_elemento;
    }
    else
    {
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo_elemento;
    }

    return 1;
}

int inserirPorPosicao(Lista *l, int v, int p)
{
    Elemento *novo_elemento = (Elemento *)malloc(sizeof(Elemento));
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    int i = 1;

    novo_elemento->valor = v;
    aux = l->inicio;

    while (i < p - 1)
    {
        i++;
        aux = aux->proximo;
    }

    novo_elemento->proximo = aux->proximo;
    aux->proximo = novo_elemento;
    l->tamanho++;

    return 1;
}

int removerFinal(Lista *l, int *r)
{
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    Elemento *remover = (Elemento *)malloc(sizeof(Elemento));
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

int removerPorPosicao(Lista *l, int p, int *r)
{
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    Elemento *remover = (Elemento *)malloc(sizeof(Elemento));
    int i = 1;
    if (p != 1)
    {
        aux = l->inicio;
        remover = l->inicio->proximo;

        while (i < p - 1)
        {
            aux = aux->proximo;
            remover = remover->proximo;
            i++;
        }

        aux->proximo = remover->proximo;
    }
    else
    {
        remover = l->inicio;
        l->inicio = remover->proximo;
    }

    *r = remover->valor;
    free(remover);
    l->tamanho--;

    return 1;
}

int quantidadeItens(Lista *l)
{
    return l->tamanho;
}

void imprimir(Lista *l)
{
    if (l == NULL)
    {
        printf("Lista vazia!\n\n");
    }
    else
    {
        Elemento *aux;
        aux = (Elemento *)malloc(sizeof(Elemento));
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

int inserirO(Lista *l, int v)
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
