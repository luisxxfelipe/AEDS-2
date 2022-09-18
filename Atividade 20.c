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

int tamanhoLista(Elemento *e);

int main()
{
    Lista *l = criarLista();
    int tamanho;

    preencher(l);
    imprimir(l);

    tamanho = tamanhoLista(l->inicio);
    printf("Tamanho da lista: %d\n\n", tamanho);

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
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));

    aux = l->inicio;
    novo_elemento->valor = v;
    novo_elemento->proximo = NULL;
    l->tamanho++;

    if (estaVazia(l))
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

int remover(Lista *l, int *r)
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

int tamanhoLista(Elemento *e)
{
    Elemento *aux;

    aux = e;

    if (aux->proximo == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + tamanhoLista(aux->proximo);
    }
}
