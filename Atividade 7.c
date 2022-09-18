#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define inicio_vetor 0
#define FALSE 0
#define TRUE 1

typedef struct lista
{
    int item[MAX];
    int fim;
} s_lista;

s_lista *inicializacao();
int lista_vazia(s_lista *lista);
int lista_cheia(s_lista *lista);
int inserir_final(s_lista *lista, int valor);
int ponteiro_valido(s_lista *lista);
int quantidade_elementos(s_lista *lista);
int inserir_posicao(s_lista *lista, int valor, int posicao);
int remover_final(s_lista *lista, int *valor);
int retirar_item(s_lista *lista, int valor);
int retirar_ultimo(s_lista *lista, int posicao, int *valor);
void imprimir_lista(s_lista *lista);

int main()
{
    s_lista *lista;
    lista = inicializacao();
    int opcao, valor, valor2;

    do
    {
        printf("\n\n[1]Inserir elemento no final da lista.\n[2]Remover elemento do final da lista.\n[3]Imprimir elementos da lista.\n[4]Quantidade de elementos.\n[5]Insira elemento em determinada posicao.\n[6]Remover determinado elemento.\n[7]Remover elemento de uma posicao.\n[8]Finalizar programa.\n\n");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro invalido.\n");
            }

            printf("\nDigite os valores para adicionar no fina da lista: ");
            scanf("%d", &valor);

            int inserir = inserir_final(lista, valor);
            if (inserir == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor na lista pois ela se encontra cheia.\n");
            }
        }

        if (opcao == 2)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            system("cls");
            int inserir = remover_final(lista, &valor);
            if (inserir == FALSE)
            {
                system("cls");
                printf("\nA lista se encontra vazia.\n");
            }
            else
            {
                printf("\nO valor removido da lista foi: %d\n", valor);
            }
        }

        if (opcao == 3)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
            }

            system("cls");
            imprimir_lista(lista);
        }

        if (opcao == 4)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }
            system("cls");
            quantidade_elementos(lista);
            system("pause");
        }

        if (opcao == 5)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
                break;
            }

            printf("\nDigite o valor que deseja adicionar na lista para modificar: ");
            scanf("%d", &valor);
            printf("\nDigite a posicao deseja inserir o valor na lista: ");
            scanf("%d", &valor2);

            int inserir = inserir_posicao(lista, valor, valor2);
            if (inserir == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel inserir o valor nesta posicao.");
            }
            system("pause");
        }

        if (opcao == 6)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
            }

            printf("\nDigite o valor que deseja remover da lista: ");
            scanf("%d", &valor);

            int inserir = retirar_item(lista, valor);
            if (inserir == FALSE)
            {
                printf("\nNao foi possivel remover o valor da lista pois ele nao foi encontrado ou a lista se encontra vazia.\n\n");
            }
            else
            {
                printf("\nO valor %d foi removido com sucesso.\n", valor);
            }
            system("pause");
        }

        if (opcao == 7)
        {
            if (!ponteiro_valido(lista))
            {
                printf("\nO ponteiro nao e valido.\n");
                system("pause");
            }

            printf("\nDigite a posicao que deseja remover da lista: ");
            scanf("%d", &valor);

            int inserir = retirar_ultimo(lista, valor, &valor2);
            if (inserir == FALSE)
            {
                system("cls");
                printf("\nNao foi possivel remover o valor desta posicao.\n");
            }
            else
            {
                printf("\nO valor %d foi removido com sucesso.\n", valor2);
            }
            system("pause");
        }

    } while (!(opcao == 8));

    return 0;
}

s_lista *inicializacao()
{
    s_lista *valor;
    valor = (s_lista *)calloc(1, sizeof(s_lista));
    valor->fim = -1;
    return valor;
}

int lista_vazia(s_lista *lista)
{
    int tamanho = quantidade_elementos(lista);
    if (tamanho == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int quantidade_elementos(s_lista *lista)
{
    int elementos = 0;
    for (int i = 0; i <= MAX - 1; i++)
    {
        if (!(lista->item[i] == inicio_vetor))
        {
            elementos++;
        }
    }
    return elementos;
}

int lista_cheia(s_lista *lista)
{
    int tamanho = quantidade_elementos(lista);
    if (tamanho == MAX)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int inserir_final(s_lista *lista, int valor)
{
    int status = lista_cheia(lista);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        lista->fim++;
        lista->item[lista->fim] = valor;
        return TRUE;
    }
}

int inserir_posicao(s_lista *lista, int valor, int posicao)
{

    if (posicao > MAX - 1)
        return FALSE;

    if (lista->item[posicao - 1] == inicio_vetor)
        return FALSE;

    else
    {
        lista->fim++;
        lista->item[lista->fim] = valor;
        return TRUE;
    }
}

int ponteiro_valido(s_lista *lista)
{
    if (lista == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int remover_final(s_lista *lista, int *valor)
{
    int status = lista_vazia(lista);
    if (status == TRUE)
    {
        return FALSE;
    }
    else
    {
        *valor = lista->item[lista->fim];
        lista->item[lista->fim] = inicio_vetor;
        lista->fim--;
        return TRUE;
    }
}

int retirar_item(s_lista *lista, int valor)
{
    int status = lista_vazia(lista);
    if (status == TRUE)
    {
        printf("A posicao nao existe!\n");
        return FALSE;
    }

    else
    {
        for (int i = 0; i <= MAX - 1; i++)
        {
            if (lista->item[i] == valor)
            {
                for (int j = i; j <= lista->fim; j++)
                {
                    lista->item[j] = lista->item[j + 1];
                }
                lista->item[lista->fim] = inicio_vetor;
                lista->fim--;
                return TRUE;
            }
        }
        return FALSE;
    }
}

int retirar_ultimo(s_lista *lista, int posicao, int *valor)
{
    int inserir = lista_vazia(lista);
    if (inserir == TRUE)
        return FALSE;

    if (posicao > MAX - 1)
        return FALSE;

    if (lista->item[posicao] == inicio_vetor)
        return FALSE;

    *valor = lista->item[posicao];

    for (int i = posicao; i <= lista->fim; i++)
    {
        lista->item[i] = lista->item[i + 1];
    }

    lista->item[lista->fim] = inicio_vetor;
    lista->fim--;
    return TRUE;
}

void imprimir_lista(s_lista *lista)
{
    printf("\n");
    printf("\nImprimindo lista estatica: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d] - %d\n", i, lista->item[i]);
    }
    printf("\nFim = %d", lista->fim);
    printf("\n");
}