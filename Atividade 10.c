#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio, *fim;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor);
void inserirFim(Lista *lista, int valor);
void imprimir(Lista *lista);
void remover(Lista *lista, int valor);
No *removerPrimeiroNO(Lista *lista);
void dividirLista(Lista *lista, Lista *listaI, Lista *listaP);

int main()
{
    Lista lista, listaI, listaP; // criação de 3 listas
    int opcao, valor;

    // inicialização das listas
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    listaI.inicio = NULL;
    listaI.fim = NULL;
    listaI.tam = 0;

    listaP.inicio = NULL;
    listaP.fim = NULL;
    listaP.tam = 0;

    do
    { // menu de opções
        printf("[1]Inserir no inicio\n[2]Imprimir\n[3]Inserir no fim\n[4]Remover\n[5]Dividir lista\n[6]Sair\n");
        printf("\nDigite uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            printf("\n");
            break;

        case 2:
            printf("\nLista original:\n");
            imprimir(&lista);
            printf("\nLista impar:\n");
            imprimir(&listaI);
            printf("\nLista par:\n");
            imprimir(&listaP);
            printf("\n");
            break;

        case 3:
            printf("\nDigite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            printf("\n");
            break;

        case 4:
            printf("\nDigite um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&lista, valor);
            printf("\n");
            break;

        case 5:
            printf("\nFinalizando...\n");
            break;

        case 6:
            dividirLista(&lista, &listaI, &listaP);
            printf("\n");
            break;
            
        default:
            printf("\nOpcao invalida!\n");
            printf("\n");
        }
    } while (opcao != 5);

    return 0;
}

// inserção no início da lista

void inserirInicio(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;                 // (*novo).valor = valor

    if (lista->inicio == NULL)
    { // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }

    else
    { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->tam++;
}

// inserir no final da lista

void inserirFim(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    }

    else
    { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}

// imprimir a lista

void imprimir(Lista *lista)
{
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);

    while (inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }

    printf("\n\n");
}

// remover um elemento da lista

void remover(Lista *lista, int valor)
{
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No *noARemover = NULL;      // ponteiro para o nó a ser removido

    if (inicio != NULL && lista->inicio->valor == valor)
    { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if (lista->inicio == NULL)
            lista->fim = NULL;
    }

    else
    { // remoção no meio ou no final
        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor)
        {
            inicio = inicio->proximo;
        }
        if (inicio != NULL && inicio->proximo != NULL)
        {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if (inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }

    if (noARemover)
    {
        free(noARemover); // libera a memória do nó
        lista->tam--;     // decrementa o tamanho da lista
    }
}

// função que remove e retorna o primeiro nó

No *removerPrimeiroNO(Lista *lista)
{
    if (lista->inicio != NULL)
    {
        No *no = lista->inicio;
        lista->inicio = no->proximo;
        lista->tam--;
        if (lista->inicio == NULL)
            lista->fim = NULL;
        return no;
    }

    else
        return NULL;
}

// procedimento que divide uma lista em duas

void dividirLista(Lista *lista, Lista *listaI, Lista *listaP)
{
    No *removido;
    while (lista->inicio != NULL)
    {
        removido = removerPrimeiroNO(lista);
        inserirFim(listaI, removido->valor);
        free(removido);

        removido = removerPrimeiroNO(lista);
        if (removido != NULL)
        {
            inserirFim(listaP, removido->valor);
            free(removido);
        }
    }
}
