#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

No *empilhar(No *pilha, char valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No *desempilhar(No **pilha)
{
    No *remover = NULL;

    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void inverter_palavras(char x[])
{
    int i = 0;
    No *remover, *pilha = NULL;

    while (x[i] != '\0')
    {
        if (x[i] != ' ')
            pilha = empilhar(pilha, x[i]);
        else
        {
            while (pilha)
            {
                remover = desempilhar(&pilha);
                printf("%c", remover->caracter);
                free(remover);
            }
            printf(" ");
        }
        i++;
    }
    while (pilha)
    {
        remover = desempilhar(&pilha);
        printf("%c", remover->caracter);
        free(remover);
    }
    printf("\n");
}

int main()
{
    char texto[50] = {"ESTE EXERCICIO E MUITO FACIL"};

    inverter_palavras(texto);
}