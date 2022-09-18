#include <stdio.h>
#include <stdlib.h>~

#define MAX 5

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

Lista *criarListaComVetor(Lista *l, int vetor[]); // Função Exercício 12
void *inverterLista(Lista *l);                    // Função do Exercício 13

int main()
{
    Lista *l = criarLista();
    Lista *l2;
    int i, valor, vetor[MAX];

    for (i = 0; i < MAX; i++)
    {
        printf("Informe um valor para o vetor: ");
        scanf("%d", &vetor[i]);
    }
    system("cls");

    printf("Vetor: [ ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n\nLista: ");

    l2 = criarListaComVetor(l, &vetor);
    imprimir(l2);

    printf("\n\nLista Invertida: ");
    l2 = inverterLista(l2);
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

Lista *criarListaComVetor(Lista *l, int vetor[])
{
    Lista *nova_lista = criarLista();
    int i;

    for (i = 0; i < MAX; i++)
    {
        inserir(nova_lista, vetor[i]);
    }

    return nova_lista;
}

void *inverterLista(Lista *l)
{
    Elemento *pAnt, *p, *pSeg;

    pAnt = NULL;
    p = l->inicio;

    while (p != NULL)
    {
        pSeg = p->proximo;
        p->proximo = pAnt;
        pAnt = p;
        p = pSeg;
    }

    l->inicio = pAnt;
}