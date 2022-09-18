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
int removerFinal(Lista *l, int *r);
int removerPorPosicao(Lista *l, int p, int *r);
int recuperarKey(Lista *l, int key, int *p);
int recuperarPorPosicao(Lista *l, int p, int *key);
int quantidadeItens(Lista *l);
void imprimir(Lista *l);

Lista *copiarLista(Lista *l);          // Função Exercício 09
Lista *copiarSemRepetidos(Lista *l);   // Função Exercício 10
Lista *copiarListaInvertida(Lista *l); // Função Exercício 11

int main()
{
    Lista *l1 = criarLista();
    Lista *l2;

    int i, valor;

    for (i = 0; i < 5; i++)
    {
        printf("Informe um valor a ser inserido: ");
        scanf("%d", &valor);

        inserir(l1, valor);
    }
    system("cls");

    l2 = copiarListaInvertida(l1);
    printf("Lista 1\n");
    imprimir(l1);
    printf("\n\nLista 2\n\n");
    imprimir(l2);

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

Lista *copiarLista(Lista *l)
{
    Lista *nova_lista = criarLista();
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    aux = l->inicio;

    while (aux != NULL)
    {
        inserir(nova_lista, aux->valor);
        aux = aux->proximo;
    };

    return nova_lista;
}

Lista *copiarSemRepetidos(Lista *l)
{
    Lista *nova_lista = criarLista();
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    aux = l->inicio;
    int tamanho = l->tamanho, i, j = 0;
    int elementos[tamanho], elemento_repetido = 0;

    while (aux != NULL)
    {
        for (i = 0; i <= tamanho; i++)
        {
            if (aux->valor == elementos[i])
            {
                elemento_repetido = 1;
            }
        }

        if (elemento_repetido == 0)
        {
            inserir(nova_lista, aux->valor);
            elementos[j] = aux->valor;
            j++;
        }

        elemento_repetido = 0;
        aux = aux->proximo;
    };

    return nova_lista;
}

Lista *copiarListaInvertida(Lista *l)
{
    Lista *nova_lista = criarLista();
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    aux = l->inicio;
    int tamanho = l->tamanho, i = 0;
    int elementos[tamanho];

    while (aux != NULL)
    {
        elementos[i] = aux->valor;
        i++;

        aux = aux->proximo;
    };

    for (i = tamanho - 1; i >= 0; i--)
    {
        inserir(nova_lista, elementos[i]);
    }

    return nova_lista;
}