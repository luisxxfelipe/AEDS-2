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

int inserirOrdem(Lista *l, int e); // Função exercício 14

int main()
{
    Lista *l = criarLista();

    int nValores;
    int pInicial, pFinal;

    printf("Informe a quantidade de valores a serem inseridos: ");
    scanf("%d", &nValores);
    lerValores(l, nValores);

    imprimirLista(l);

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
        inserirOrdem(l, valor);
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

int inserirOrdem(Lista *l, int e)
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
