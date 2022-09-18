#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 77

void quick_sort(int *a, int lado_esquerdo, int lado_direito);

int main()
{
    int i, vet[MAX];

    printf("\nInsira os valores para ordenar de acordo com o QuickSort\n\n");

    for (i = 0; i < MAX; i++)
    {
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &vet[i]);
    }

    quick_sort(vet, 0, MAX - 1);

    printf("\n\nValores ordenados\n\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    system("pause");
    return 0;
}

// Função de Ordenação por Seleção
void quick_sort(int *a, int lado_esquerdo, int lado_direito)
{
    int i, j, x, y;

    i = lado_esquerdo;
    j = lado_direito;
    x = a[(lado_esquerdo + lado_direito) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < lado_direito)
        {
            i++;
        }
        while (a[j] > x && j > lado_esquerdo)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > lado_esquerdo)
    {
        quick_sort(a, lado_esquerdo, j);
    }
    if (i < lado_direito)
    {
        quick_sort(a, i, lado_direito);
    }
}