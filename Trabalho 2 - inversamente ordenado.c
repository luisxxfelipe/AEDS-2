#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 100
int comparacoes;
int movimentacoes;

void metodo_select(int vetor[], int n);
void metodo_insert(int vetor[], int n);
void quick_sort(int vetor[], int lado_esquerdo, int lado_direito);
void metodo_mergesort(int vetor[], int n);
void sort(int vetor[], int *c, int i, int f);
void merge(int vetor[], int *c, int i, int m, int f);
int calcular_frequencia(int n);

int main()
{
    int vetor[TAM];
    int opcao, frequencia;
    clock_t inicio_do_processo, fim_do_processo;
    clock_t media_processo = 0;
    float media_comparacoes = 0, media_movimentacoes = 0;

    FILE *pont_arq = fopen("Arquivo.txt", "w");

    if (pont_arq == NULL)
    {
        printf("Error na abertura do arquivo!!");
        exit(1);
    }

    do
    {
        printf("\n[1] Ordenacao inversa - Quicksort.\n[2] Ordenacao inversa - Selectsort.\n[3] Ordenacao inversa - Insertsort\n[4] Ordenacao inversa - Mergesort\n");
        printf("\nEscola qual modo de ordenacao deseja usar: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {

            printf("\n\nOrdenacao inversa - Quicksort\n");
            for (int i = 0; i < 10; i++)
            {
                comparacoes = 0;
                srand(time(NULL));
                printf("\nVetores imprimido: ");
                for (int i = 0; i < TAM; i++)
                {
                    int gerar = rand() % 1000;

                    printf("%d ", gerar);
                    vetor[i] = gerar;
                }
                printf("\n");
                system("pause");

                inicio_do_processo = clock();
                quick_sort(vetor, 0, TAM - 1);

                printf("\n\nValores ordenados\n\n");
                for (int i = 0; i < TAM; i++)
                {
                    printf("%d ", vetor[i]);
                }
                printf("\n");

                printf("\n\nCalculando o tempo de processamento...\n");
                frequencia = calcular_frequencia(1000);
                printf("\nA frequencia inferior a 100000 foi: %d\n", frequencia);
                fim_do_processo = clock() - inicio_do_processo;
                media_processo += fim_do_processo;
                media_comparacoes += comparacoes;
                media_movimentacoes += movimentacoes;
                printf("\nOrdenacao inversa - Quicksort\n[%d ORDENACAO] - Foram feitos um total de [%d] comparacoes e [%d] movimentacoes, durante a ordenacao, por (%f) segundos.\n", i, comparacoes, movimentacoes, ((float)fim_do_processo) / CLOCKS_PER_SEC);

                fprintf(pont_arq, "\nOrdenacao inversa - Quicksort - [%d ORDENACAO] - Foram feitos um total de [%d] comparacoes durante a ordenacao, por (%f) segundos.\n", i, comparacoes, fim_do_processo / (float)CLOCKS_PER_SEC);

                system("pause");
                printf("\n");
                system("cls");
            }

            media_processo = media_processo / 10;
            media_comparacoes = media_comparacoes / 10;
            media_movimentacoes = media_movimentacoes / 10;
            printf("\nA media do tempo de execucao do programa foi de %f segundos.\n", ((float)media_processo) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "Media do tempo de processo gasto %fs\n", media_processo / (float)CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            system("pause");
            system("cls");
        }

        if (opcao == 2)
        {
            printf("\n\n Ordenacao inversa - Selectsort\n");
            for (int i = 0; i < 10; i++)
            {
                comparacoes = 0;
                srand(time(NULL));
                printf("\nVetores imprimido: ");
                for (int i = 0; i < TAM; i++)
                {
                    int gerar = rand() % 1000;

                    printf("%d ", gerar);
                    vetor[i] = gerar;
                }
                printf("\n");
                system("pause");

                inicio_do_processo = clock();
                metodo_select(vetor, TAM);

                printf("\n\nValores ordenados\n\n");
                for (int i = 0; i < TAM; i++)
                {
                    printf("%d ", vetor[i]);
                }
                printf("\n");

                printf("\n\nCalculando o tempo de processamento...\n");
                frequencia = calcular_frequencia(1000);
                printf("\nA frequencia inferior a 100000 foi: %d\n", frequencia);
                fim_do_processo = clock() - inicio_do_processo;
                media_processo += fim_do_processo;
                media_comparacoes += comparacoes;
                media_movimentacoes += movimentacoes;
                printf("\nOrdenacao inversa - Quicksort\n[%d ORDENACAO] - Foram feitos um total de [%d] comparacoes e [%d] movimentacoes, durante a ordenacao, por (%f) segundos.\n", i, comparacoes, movimentacoes, ((float)fim_do_processo) / CLOCKS_PER_SEC);

                fprintf(pont_arq, "\nOrdenacao inversa - Quicksort - [%d ORDENACAO] - Foram feitos um total de [%d] comparacoes durante a ordenacao, por (%f) segundos.\n", i, comparacoes, fim_do_processo / (float)CLOCKS_PER_SEC);
                system("pause");
                printf("\n");
                system("cls");
            }

            media_processo = media_processo / 10;
            media_comparacoes = media_comparacoes / 10;
            media_movimentacoes = media_movimentacoes / 10;
            printf("\nA media do tempo de execucao do programa foi de %f segundos.\n", ((float)media_processo) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes));
            printf("\nA media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "Media do tempo de processo gasto %fs\n", media_processo / (float)CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            system("pause");
            system("cls");
        }

        if (opcao == 3)
        {
            printf("\n\nOrdenacao inversa - Insertsort\n");
            for (int i = 0; i < 10; i++)
            {
                comparacoes = 0;
                srand(time(NULL));
                printf("\nVetores imprimido: ");
                for (int i = 0; i < TAM; i++)
                {
                    int gerar = rand() % 1000;

                    printf("%d ", gerar);
                    vetor[i] = gerar;
                }
                printf("\n");
                system("pause");

                inicio_do_processo = clock();
                metodo_insert(vetor, TAM);

                printf("\n\nValores ordenados\n\n");
                for (int i = 0; i < TAM; i++)
                {
                    printf("%d ", vetor[i]);
                }
                printf("\n");

                printf("\n\nCalculando o tempo de processamento...\n");
                frequencia = calcular_frequencia(1000);
                printf("\nA frequencia inferior a 100000 foi: %d\n", frequencia);
                fim_do_processo = clock() - inicio_do_processo;
                media_processo += fim_do_processo;
                media_comparacoes += comparacoes;
                media_movimentacoes += movimentacoes;
                printf("\nOrdenacao inversa - Quicksort\n[%d ORDENACAO] - Foram feitos um total de [%d] comparacoes e [%d] movimentacoes, durante a ordenacao, por (%f) segundos.\n", i, comparacoes, movimentacoes, ((float)fim_do_processo) / CLOCKS_PER_SEC);

                fprintf(pont_arq, "\nOrdenacao inversa - Quicksort - [%d ORDENACAO] - Foram feitos um total de [%d] comparacoes durante a ordenacao, por (%f) segundos.\n", i, comparacoes, fim_do_processo / (float)CLOCKS_PER_SEC);
                system("pause");
                printf("\n");
                system("cls");
            }

            media_processo = media_processo / 10;
            media_comparacoes = media_comparacoes / 10;
            media_movimentacoes = media_movimentacoes / 10;
            printf("\nA media do tempo de execucao do programa foi de %f segundos.\n", ((float)media_processo) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "Media do tempo de processo gasto %fs\n", media_processo / (float)CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            system("pause");
            system("cls");
        }
        if (opcao == 4)
        {
            printf("\n\nOrdenacao inversa - Mergesort\n");
            for (int i = 0; i < 10; i++)
            {
                comparacoes = 0;
                srand(time(NULL));
                printf("\nVetores imprimido: ");
                for (int i = 0; i < TAM; i++)
                {
                    int gerar = rand() % 1000;

                    printf("%d ", gerar);
                    vetor[i] = gerar;
                }
                printf("\n");
                system("pause");
                inicio_do_processo = clock();
                metodo_mergesort(vetor, TAM);
                printf("\n\nValores ordenados\n\n");
                for (int i = 0; i < TAM; i++)
                {
                    printf("%d ", vetor[i]);
                }
                printf("\n");

                printf("\n\nCalculando o tempo de processamento...\n");
                frequencia = calcular_frequencia(1000);
                printf("\nA frequencia inferior a 100000 foi: %d\n", frequencia);
                fim_do_processo = clock() - inicio_do_processo;
                media_processo += fim_do_processo;
                media_comparacoes += comparacoes;
                media_movimentacoes += movimentacoes;
                printf("\nOrdenacao inversa - Quicksort\n[%d ORDENACAO] - Foram feitos um total de [%d] comparacoes e [%d] movimentacoes, durante a ordenacao, por (%f) segundos.\n", i, comparacoes, movimentacoes, ((float)fim_do_processo) / CLOCKS_PER_SEC);

                fprintf(pont_arq, "\nOrdenacao inversa - Quicksort - [%d ORDENACAO] - Foram feitos um total de [%d] comparacoes durante a ordenacao, por (%f) segundos.\n", i, comparacoes, fim_do_processo / (float)CLOCKS_PER_SEC);
                system("pause");
                printf("\n");
                system("cls");
            }

            media_processo = media_processo / 10;
            media_comparacoes = media_comparacoes / 10;
            media_movimentacoes = media_movimentacoes / 10;

            printf("\nA media do tempo de execucao do programa foi de %f segundos.\n", ((float)media_processo) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            printf("\nA media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "Media do tempo de processo gasto %fs\n", media_processo / (float)CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de comparacoes foram de %f.\n", ((float)media_comparacoes) / CLOCKS_PER_SEC);
            fprintf(pont_arq, "A media do numeros de movimentacoes foram de %f.\n", ((float)media_movimentacoes) / CLOCKS_PER_SEC);
            system("pause");
            system("cls");
        }

    } while (!(opcao == 0));

    fclose(pont_arq);
    printf("\nArquivo salvado com sucesso!!\n");
}

void metodo_select(int vetor[], int n)
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
            comparacoes++;
        }
        temp = vetor[i];
        vetor[i] = vetor[minimo];
        vetor[minimo] = temp;
        movimentacoes++;
    }
}

void metodo_insert(int vetor[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = vetor[i];
        j = i - 1;
        while (temp < vetor[j] && j >= 0)
        {
            comparacoes++;
            vetor[j + 1] = vetor[j];
            j = j + 1;
        }
        vetor[j + 1] = temp;
        movimentacoes++;
    }
}

void quick_sort(int vetor[], int lado_esquerdo, int lado_direito)

{
    int i, j, x, y;

    i = lado_esquerdo;
    j = lado_direito;
    x = vetor[(lado_esquerdo + lado_direito) / 2];

    while (i <= j)
    {
        while (vetor[i] < x && i < lado_direito)
        {
            i++;
            comparacoes++;
        }
        while (vetor[j] > x && j > lado_esquerdo)
        {
            j--;
            comparacoes++;
        }
        if (i <= j)
        {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
            comparacoes++;
        }
        movimentacoes++;
    }

    if (j > lado_esquerdo)
    {
        quick_sort(vetor, lado_esquerdo, j);
        comparacoes++;
        movimentacoes++;
    }

    if (i < lado_direito)
    {
        quick_sort(vetor, i, lado_direito);
        comparacoes++;
        movimentacoes++;
    }
}

void metodo_mergesort(int vetor[], int n) // Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
{
    int *c = malloc(sizeof(int) * n);
    sort(vetor, c, 0, n - 1);
    free(c);
}

void sort(int vetor[], int *c, int i, int f) // Dado um vetor de inteiros e dois inteiros i e f, ordena o vetor vetor[i..f] em ordem crescente. O vetor c é utilizado internamente durante a ordenação.
{
    if (i >= f)
        return;

    int m = (i + f) / 2;

    sort(vetor, c, i, m);

    sort(vetor, c, m + 1, f);

    /* Se vetor[m] <= vetor[m + 1], então vetor[i..f] já está ordenado. */

    if (vetor[m] <= vetor[m + 1])
    {
        return;
    }

    merge(vetor, c, i, m, f);
}

void merge(int vetor[], int *c, int i, int m, int f) // Dado um vetor e três inteiros i, m e f, sendo vetor[i..m] e vetor[m+1..f] vetores ordenados, coloca os elementos destes vetores, em ordem crescente, no vetor em vetor[i..f].
{
    int z,
        iv = i, ic = m + 1;

    for (z = i; z <= f; z++)
    {
        c[z] = vetor[z];
        comparacoes++;
    }
    z = i;

    while (iv <= m && ic <= f)
    {
        /* Invariante: vetor[i..z] possui os valores de vetor[iv..m] e vetor[ic..f] em ordem crescente. */

        if (c[iv] <= c[ic])
        {
            vetor[z++] = c[iv++];
            comparacoes++;
        }
        else
        {
            vetor[z++] = c[ic++];
            comparacoes++;
        }
        movimentacoes++;
    }

    while (iv <= m)
    {
        vetor[z++] = c[iv++];
        comparacoes++;
    }

    while (ic <= f)
    {
        vetor[z++] = c[ic++];
        comparacoes++;
    }
}

int calcular_frequencia(int n)
{
    int i, j;
    int freq = n - 1;
    for (i = 2; i <= n; ++i)
    {
        for (j = sqrt(i); j > 1; --j)
        {
            if (i % j == 0)
            {
                --freq;
                break;
            }
        }
    }
    return freq;
}