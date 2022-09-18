#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct f_fila
{
    int *v;
    int inicio, fim, n, tamanho; // n representa o tamanho do valor alocado e o tamanho representa o tamanho da fila
} f_fila;

void incializacao(f_fila *fila, int capacidade);
void enfileirar_fila(f_fila *f, int x);
int desenfileirar_fila(f_fila *f);
int fila_vazia(f_fila *f);

int main()
{
    int opcao, i, quantidade_elementos, elementos_fila;
    f_fila f;

    printf("Digite a capacidade da fila: ");
    scanf("%d", &quantidade_elementos);

    incializacao(&f, quantidade_elementos);

    for (i = 0; i < quantidade_elementos; i++)
    {
        printf("\n\nDigite o %do elemento que deseja adicionar na fila circular: ", i + 1);
        scanf("%d", &elementos_fila);
    }

    do
    {
        printf("\n\n[1]Enfileirar valores da fila circular.\n[2]Desenfileirar valores da fila circular.\n[3]Sair do programa.\n");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            enfileirar_fila(&f, elementos_fila);
        }

        if (opcao == 2)
        {
            fila_vazia(&f);
            elementos_fila = desenfileirar_fila(&f);
            printf("Foi desinfileirado com sucesso: \n%d\n", elementos_fila);
        }

    } while (!(opcao == 3));

    return 0;
}

void incializacao(f_fila *f, int capacidade)
{
    f->v = malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->n = capacidade;
    f->tamanho = 0;
}

void enfileirar_fila(f_fila *f, int x)
{
    if (fila_vazia(f))
    {
        return;
    }
    else
    {
        f->v[f->fim] = x;
        f->fim = (f->fim + 1) % f->n;
        (f->tamanho)++;
    }
}

int desenfileirar_fila(f_fila *f)
{
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->n;
    (f->tamanho)--;
    return x;
}

int fila_vazia(f_fila *f)
{
    if (f->inicio == -1)
    {
        printf("A pilha esta vazia!");
        return 1;
    }
    else
        return 0;
}