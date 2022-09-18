#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct lista
{
    int valores[MAX];
    int fim;
} Lista;

Lista *criarLista();
int liberaLista(Lista *l);
int estaCheia(Lista *l);
int estaVazia(Lista *l);
int inserir(Lista *l, int e);
int remover(Lista *l, int *r);
void imprimir(Lista *l);
int preencher(Lista *l);

int removerElemento(Lista *l, int r); // Função exercício 18

int main()
{
    Lista *l = criarLista();
    int valor;

    preencher(l);
    imprimir(l);

    system("pause");
    system("cls");

    printf("Informa o valor a ser removido: ");
    scanf("%d", &valor);

    system("cls");
    imprimir(l);

    removerElemento(l, valor);
    printf("Apos a remocao: ");
    imprimir(l);

    return 0;
}

Lista *criarLista()
{
    Lista *p = (Lista *)malloc(sizeof(Lista));

    p->fim = -1;
    return p;
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
        int i, j;
        l->fim++;

        if (estaVazia(l))
        {
            l->valores[0] = e;
        }
        else
        {
            for (i = 0; i < l->fim; i++)
            {
                if (l->valores[i] > e)
                {
                    break;
                }
            }

            for (j = l->fim; j > i; j--)
            {
                l->valores[j] = l->valores[j - 1];
            }

            l->valores[i] = e;
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover(Lista *l, int *r)
{
    if (!estaVazia(l))
    {
        *r = l->valores[l->fim];
        l->fim--;
        return 1;
    }
    else
    {
        return 0;
    }
}

void imprimir(Lista *l)
{
    int i;

    printf("Lista : ");
    for (i = 0; i <= l->fim; i++)
    {
        printf("%d ", l->valores[i]);
    }
    printf("\n\n");
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
    int i;

    for (i = 0; i <= l->fim; i++)
    {
        if (l->valores[i] == r)
        {
            break;
        }
    }

    if (l->valores[i] != r)
    {
        printf("Valor não encontrado!\n");
        return 0;
    }
    else
    {
        for (i; i <= l->fim; i++)
        {
            l->valores[i] = l->valores[i + 1];
        }

        l->fim--;
        return 1;
    }
}
