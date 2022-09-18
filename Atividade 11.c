#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

void metodo_bubble_sort(int vetor[], int n);
void metodo_selection(int vetor[], int n);
void metodo_insertion(int vetor[], int n);
void imprimir_vetor(int vetor[], int n, int repeticoes);

int main()
{
    int vetor[TAM];
    int opcao;

    do
    {
        printf("\n[1] Ordenacao Bubble sort.\n[2] Ordenacao Selection sort.\n[3] Ordenacao Insection sort");
        printf("\nEscola qual modo de ordenacao deseja usar: ");
        scanf("%d", &opcao);

        srand(time(NULL));
        for (int i = 0; i < TAM; i++)
        {
            int gerar = rand() % 25;

            printf("%d ", gerar);
            vetor[i] = gerar;
        }

        if (opcao == 1)
        {
            printf("\n\nOrdenacao Bubble sort\n");
            metodo_bubble_sort(vetor, TAM);
            printf("\n");
            system("pause");
            system("cls");
        }

        if (opcao == 2)
        {
            printf("\n\n Ordenacao Selection sort/n");
            metodo_selection(vetor, TAM);
            printf("\n");
            system("pause");
            system("cls");
        }

        if (opcao == 3)
        {
            printf("\n\nOrdenacao Insertion sort\n");
            metodo_insertion(vetor, TAM);
            printf("\n");
            system("pause");
            system("cls");
        }
    } while (opcao != 3);
}

void imprimir_vetor(int vetor[], int n, int repeticoes)
{
    printf("\nVetor imprimido: [%d] - ", repeticoes - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void metodo_bubble_sort(int vetor[], int n)
{
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        imprimir_vetor(vetor, n, k);
        for (j = 0; j < n - 1; j++)
        {

            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void metodo_selection(int vetor[], int n)
{
    int i, j, minimo, temp;
    for (i = 0; i < n - 1; i++)
    {
        minimo = i;
        for (j = i + 1; j < n; j++)
        {
            if (vetor[minimo] > vetor[j])
            {
                minimo = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[minimo];
        vetor[minimo] = temp;
        imprimir_vetor(vetor, n, i + 1);
    }
}

void metodo_insertion(int vetor[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = vetor[i];
        j = i - 1;
        while (temp < vetor[j] && j >= 0)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
        imprimir_vetor(vetor, n, i + 1);
    }
}