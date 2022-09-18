#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int primeiro;
    int ultimo;
    int vetor;
    float *elementos;
    int capacidade;
} fila;

void criar_fila(fila *f, int c);
void inserir_fila(fila *f, int v);
int remover_fila(fila *f);
int fila_vazia(fila *f);
int fila_cheia(fila *f);
void mostrar_fila(fila *f);

int main()
{
    int opcao, quantidade_elementos;
    float valores;
    fila fila_aux;

    printf("Digite a capacidade da fila: ");
    scanf("%d", &quantidade_elementos);

    criar_fila(&fila_aux, quantidade_elementos);

    do
    {
        printf("\n\n[1]Adicionar valores para a fila.\n[2]Remover valor da fila.\n[3]Mostrar os elementos da fila.\n[4]Sair do programa.\n");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        // Adicionar valores para a fila.

        if (opcao == 1)
        {
            int fila_che = fila_cheia(&fila_aux);

            if (fila_che)
            {
                printf("\n\nA fila esta cheia!!\n\n");
            }

            else
            {
                printf("\n\nDigite os valores para a fila: \n");
                scanf("%f", &valores);
                inserir_fila(&fila_aux, valores);

                printf("\n");
            }

            system("pause");
            system("cls");
        }

        // Remover valores da fila.

        if (opcao == 2)
        {
            int fila_vaz = fila_vazia(&fila_aux);

            if (fila_vaz)
            {
                printf("\n\nA fila esta vazia!!\n\n");
            }

            else
            {
                valores = remover_fila(&fila_aux);
                printf("\n\n%lf foi removido com sucesso da fila.\n\n", valores);
            }
        }

        // Mostrar valores da fila.

        if (opcao == 3)
        {
            int fila_vaz = fila_vazia(&fila_aux);

            if (fila_vaz)
            {
                printf("\n\nA fila esta vazia!!\n\n");
            }

            else
            {
                printf("\nos valores que estao na fila sao: \n");
                mostrar_fila(&fila_aux);

            }

            system("pause");
            system("cls");
        }

    } while (!(opcao == 4));
}

void criar_fila(fila *f, int c)
{
    f->capacidade = c;
    f->elementos = (float *)malloc(f->capacidade * sizeof(float));
    f->primeiro = 0;
    f->ultimo = -1;
    f->vetor = 0;
}

void inserir_fila(fila *f, int v)
{
    if (f->ultimo == f->capacidade - 1)
    {
        f->ultimo = -1;
    }
        f->ultimo++;
    
        f->elementos[f->ultimo] = v; // adiciona o ultimo valor e insere
        f->vetor++;   // mais um valor inserido
    
}

int remover_fila(fila *f) // pega o valor do começo da fila
{

    int aux = f->elementos[f->primeiro++]; // pega o valor e incrementa o primeiro

    if (f->primeiro == f->capacidade)
    {
        f->primeiro = 0;

        f->vetor--; // um valor retirado
        return aux;
    }
}

int fila_vazia(fila *f)
{
    return (f->vetor == 0);
}

int fila_cheia(fila *f)
{
    return (f-> vetor == f->capacidade);
}

void mostrar_fila(fila *f)
{

    int aux, i;

    for (aux = 0, i = f->primeiro; aux < f->vetor; aux++)
    {

        printf("%.2f\t", f->elementos[i++]);

        if (i == f->capacidade)
            i = 0;
    }
    printf("\n\n");
}