#include <stdio.h>
#include <stdlib.h>

typedef struct s_valor
{
    int valor;
    struct s_valor *vetor;
} s_valor;

typedef struct s_pilha
{
    int tamanho;
    s_valor *topo;
} s_pilha;

void criar_pilha(s_pilha *f);
void exibir_pilha(s_pilha *f);
void liberar_pilha(s_pilha *f);
void empilhar_pilha(s_pilha *f, int valor);
void desempilhar_pilha(s_pilha *f);

int main()
{
    int opcao;
    int valores;
    s_pilha pilha;
    criar_pilha(&pilha);
    do
    {
        printf("\n\n[1]Empilhar os valores.\n[2]Desempilhar os valores.\n[3]Mostrar valores.\n[4]Esvaziar pilha.\n[5]Sair do programa.");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        // empilhar os valores

        if (opcao == 1)
        {
            printf("\n\nDigite os valores para empilhar: \n");
            scanf("%d", &valores);

            printf("\n");

            empilhar_pilha(&pilha, valores);

            system("pause");
            system("cls");
        }

        // desempilhar os valores

        if (opcao == 2)
        {
            desempilhar_pilha(&pilha);
            system("pause");
            system("cls");
        }

        if (opcao == 3)
        {
            exibir_pilha(&pilha);
            system("pause");
            system("cls");
        }

        if (opcao == 4)
        {
            liberar_pilha(&pilha);
            criar_pilha(&pilha);

            system("pause");
            system("cls");
        }

    } while (!(opcao == 5));

    return 0;
}

void criar_pilha(s_pilha *f)
{
    f->topo = NULL;
    f->tamanho = 0;
}

void liberar_pilha(s_pilha *f)
{
    printf("\nLiberando valores alocados\n\n");
    s_valor *temporario;
    temporario = f->topo;
    while (temporario != NULL)
    {

        free(temporario);
        temporario = temporario->vetor;
        return f->topo;
    }
}

void empilhar_pilha(s_pilha *f, int valor)
{
    s_valor *aux = (s_valor *)malloc(sizeof(s_valor));
    aux->valor = valor;

    if (f->tamanho == 0)
        aux->vetor = NULL;

    else
        aux->vetor = f->topo;
    f->topo = aux;
    f->tamanho++;
}

void desempilhar_pilha(s_pilha *f)
{
    if (f->tamanho == 0)
    {
        printf("\nA pilha esta vazia\n\n");
    }

    else
    {
        printf("\n[ %d ] Desempilhado\n", f->topo->valor);
        f->tamanho--;
        f->topo = f->topo->vetor;
    }
}

void exibir_pilha(s_pilha *f)
{
    s_valor *temporario;

    temporario = f->topo;
    printf("Exibindo PILHA c/ %i Itens: \n", f->tamanho);
    int i = f->tamanho;
    while (i > 0)
    {
        printf("Item: %i | Valor: [ %i ]\n", i, temporario->valor);
        temporario = temporario->vetor;
        i--;
    }
}