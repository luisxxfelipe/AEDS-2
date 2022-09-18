#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100

typedef struct pilha
{
    int topo;
    char letra[MAX];
} Pilha;

void criarPilha(Pilha *p);
void empilhar(Pilha *p, char letra);
char desempilhar(Pilha *p);
void palindromo(Pilha *p);
void imprimir(Pilha *p);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    criarPilha(p);
    palindromo(p);

    return 0;
}

void criarPilha(Pilha *p)
{
    p->topo = 0;
}
void empilhar(Pilha *p, char letra)
{
    p->letra[p->topo] = letra;
    p->topo++;
}

char desempilhar(Pilha *p)
{
    p->topo--;
    return p->letra[p->topo];
}

void palindromo(Pilha *p)
{
    char palavra[MAX];
    printf("Insira uma palavra: ");
    scanf("%s", palavra);

    for (int i = 0; i < strlen(palavra); i++)
    {
        empilhar(p, palavra[i]);
    }
    printf("Palavra digitada: %s", palavra);

    char *aux = "É palíndromo";

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] != desempilhar(p))
        {
            aux = "Não é palíndromo";
        }
    }
    printf("\n%s", aux);
}
