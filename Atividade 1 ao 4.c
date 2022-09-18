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

Lista *concatenarListas(Lista *a, Lista *b);           // Função Ex 01
int removerPrimeirosElementos(Lista *l, int n);        // Função Ex 02
int indexMaiorValor(Lista *l, int **p, int **v);       // Função Ex 03
int trocarPosicao(Lista *l, int pInicial, int pFinal); // FUnção Ex 04

int main()
{
    Lista *a = criarLista();
    Lista *b = criarLista();
    Lista *c;

    int nValores;
    int *maior, *index;
    int pInicial, pFinal;

    lerValores(a, 5);
    lerValores(b, 5);

    imprimirLista(a);
    imprimirLista(b);

    c = concatenarListas(a, b);
    imprimirLista(c);

    printf("Informe os n valores a serem removidos: ");
    scanf("%d", &nValores);

    removerPrimeirosElementos(c, nValores);
    imprimirLista(c);

    if (indexMaiorValor(c, &index, &maior))
    {
        printf("Maior valor %d, na posicao %d\n\n", *maior, *index);
    }

    printf("Informe as 2 posicoes que terao elementos trocados: ");
    scanf("%d %d", &pInicial, &pFinal);

    imprimirLista(c);
    trocarPosicao(c, pInicial, pFinal);
    imprimirLista(c);

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

Lista *concatenarListas(Lista *a, Lista *b)
{
    Lista *c = criarLista();
    int i;

    for (i = 0; i <= a->fim; i++)
    {
        inserir(c, a->valores[i]);
    }

    for (i = 0; i <= b->fim; i++)
    {
        inserir(c, b->valores[i]);
    }

    return c;
}

int removerPrimeirosElementos(Lista *l, int n)
{
    int i, *r;

    for (i = 0; i < l->fim; i++)
    {
        l->valores[i] = l->valores[i + n];
    }

    for (i = n; i > 0; i--)
    {
        remover(l, &r);
    }

    return 1;
}

int indexMaiorValor(Lista *l, int **p, int **v)
{
    int i, indexMaior = 0;
    int maior = l->valores[0];

    for (i = 0; i <= l->fim; i++)
    {
        if (l->valores[i] > maior)
        {
            maior = l->valores[i];
            indexMaior = i;
        }
    }

    **p = indexMaior;
    **v = maior;

    return 1;
}

int trocarPosicao(Lista *l, int pInicial, int pFinal)
{
    int aux = l->valores[pInicial];

    l->valores[pInicial] = l->valores[pFinal];
    l->valores[pFinal] = aux;

    return 1;
}
