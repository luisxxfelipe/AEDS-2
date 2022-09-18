#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
    struct elemento *anterior;
} Elemento;

typedef struct lista
{
    Elemento *inicio;
    Elemento *final;
    int tamanho;
} Lista;

Lista *criarLista();
int estaVazia(Lista *l);
void liberarLista(Lista *l);
int inserir(Lista *l, int v);
int remover(Lista *l, int *r);
void imprimir(Lista *l);

int buscar(Lista *l, int e); // Função exercício 19

int main()
{
    Lista *l = criarLista();
    int i, valor, busca;

    for (i = 0; i < 5; i++)
    {
        printf("Informe um valor: ");
        scanf("%d", &valor);

        inserir(l, valor);
    }

    system("cls");
    imprimir(l);
    printf("Informe o valor para busca da posicao: ");
    scanf("%d", &valor);
    busca = buscar(l, valor);

    if (busca == -1)
    {
        printf("Valor não encontrado na lista!\n\n");
    }
    else
    {
        printf("Valor encontrado na posicao %d!\n\n", busca);
    }

    return 0;
}

Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    l->inicio = NULL;
    l->final = NULL;
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
        if (novo_elemento->valor < p->valor)
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
        printf("Lista  esta vazia!\n\n");
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

int buscar(Lista *l, int e)
{
    Elemento *aux;
    int i = 0;

    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == e)
        {
            return i;
        }
        aux = aux->proximo;
        i++;
    }

    return -1;
}
