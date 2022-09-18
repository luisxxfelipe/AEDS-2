#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int elementos;

typedef struct conjuntos
{
     elementos *valores;
} conjunto;

conjunto *criar_conjunto_vazio(conjunto *conj, int capacidade);
void inserir_valores(conjunto *A, conjunto *B, int capacidade);
void uniao_elemento(conjunto *A, conjunto *B, conjunto *C, int capacidade);
void interseccao_elemento(conjunto *A, conjunto *B, conjunto *C, int capacidade);
int insere_elemento(elementos x, conjunto *A, int capacidade);
int remove_elemento(elementos x, conjunto *A, int capacidade);
int maximo(conjunto *A, int capacidade);
int minimo(conjunto *A, int capacidade);
void diferenca(conjunto *A, conjunto *B, conjunto *C, int capacidade);
int tamanho_conjunto(conjunto *A, int capacidade);
int conjuntos_iguais(conjunto *A, conjunto *B, int capacidade);
int testar_vazio(conjunto *A, int capacidade);

int main()
{
    int opcao, quantidade_elemento;
    conjunto conjA, conjB, conjC;
    elementos x1;

    printf("Digite a quantidade de elementos que deseja adicionar: ");
    scanf("%d", &quantidade_elemento);

    criar_conjunto_vazio(&conjA, quantidade_elemento);
    criar_conjunto_vazio(&conjB, quantidade_elemento);
    criar_conjunto_vazio(&conjC, quantidade_elemento);

    do
    {
        printf("\n\n[1]Apresentar os valores.\n[2]Uniao.\n[3]Cria um conjunto vazio.\n[4]Insere.\n[5]Remove.\n[6]Interseccao.\n[7]Diferenca.\n[8]Testa se um numero pertence ao conjunto.\n[9]Menor valor.\n[10]Maior valor.\n[11]Testa se os conjuntos são iguais.\n[12]Verifica o tamanho do conjunto.\n[13]Sair do programa.\n");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        // Apresentar os valores

        if (opcao == 1)
        {

            inserir_valores(&conjA, &conjB, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Uniao

        else if (opcao == 2)
        {
            uniao_elemento(&conjA, &conjB, &conjC, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Conjunto vazio

        else if (opcao == 3)
        {
            float test = testar_vazio(&conjA, quantidade_elemento);

            printf("%f", test);

            system("pause");
            system("cls");
        }

        // Insere

        else if (opcao == 4)
        {
            insere_elemento(x1, &conjA, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Remove

        else if (opcao == 5)
        {
            remove_elemento(x1, &conjA, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Intersecção

        else if (opcao == 6)
        {
            interseccao_elemento(&conjA, &conjB, &conjC, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Diferença

        else if (opcao == 7)
        {
            diferenca(&conjA, &conjB, &conjC, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Testa se um número pertence ao conjunto

        /*else if (opcao == 8)
        {
            pertence();


            system("pause");
            system("cls");
        }*/

        // Menor valor

        else if (opcao == 9)
        {
            minimo(&conjA, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Maior valor

        else if (opcao == 10)
        {
            maximo(&conjA, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Testa se os conjuntos são iguais

        else if (opcao == 11)
        {
            conjuntos_iguais(&conjA, &conjB, quantidade_elemento);

            system("pause");
            system("cls");
        }

        // Verifica o tamanho do conjunto

        else if (opcao == 12)
        {
            tamanho_conjunto(&conjA, quantidade_elemento);

            system("pause");
            system("cls");
        }

    } while (!(opcao == 13));

    return 0;
}

conjunto *criar_conjunto_vazio(conjunto *conj, int capacidade)
{

    conj->valores = (int *)malloc(capacidade * sizeof(int));

    return conj;
}

void inserir_valores(conjunto *A, conjunto *B, int capacidade)
{
    int i;
    for (i = 0; i < capacidade; i++)
    {
        printf("\nDigite os valores do elemento A: ");
        scanf("%d", &A->valores[i]);
        printf("Digite os valores do elemento B: ");
        scanf("%d", &B->valores[i]);
    }
}

void uniao_elemento(conjunto *A, conjunto *B, conjunto *C, int capacidade)
{
    int i;
    for (i = 0; i < capacidade; i++)
    {
        if (A->valores[i] == 1 || B->valores[i] == 1)
        {
            C->valores[i] = 1;
        }
    }
}

void interseccao_elemento(conjunto *A, conjunto *B, conjunto *C, int capacidade)
{
    int i;
    for (i = 0; i < capacidade; i++)
    {
        if (A->valores[i] == 1 && B->valores[i] == 1)
        {
            C->valores[i] = 1;
        }
    }
}

int insere_elemento(elementos x, conjunto *A, int capacidade)
{
    if (x >= capacidade || x < 0)
    {
        return 0;
    }

    A->valores[x] = 1;
    return 1;
}

int remove_elemento(elementos x, conjunto *A, int capacidade)
{
    if ((x >= capacidade) || (x < 0) || (A->valores[x] == 0))
    {
        return 0;
    }

    A->valores[x] = 0;
    return 1;
}

int maximo(conjunto *A, int capacidade)
{
    int i;

    for (i = capacidade - 1; i > -1; i--)
    {
        if (A->valores[i] == 1)
        {
            return i;
        }
    }

    return capacidade; // condição de conjunto vazio
}

int minimo(conjunto *A, int capacidade)
{
    int i;

    for (i = 0; i < capacidade; i++)
    {
        if (A->valores[i] == 1)
            return i;
    }

    return capacidade; // condição de conjunto vazio
}

void diferenca(conjunto *A, conjunto *B, conjunto *C, int capacidade)
{
    int i;

    for (i = 0; i < capacidade; i++)
    {
        if ((A->valores[i] == 1) && (B->valores[i] == 0))
        {
            C->valores[i] = 1;
        }
    }
}

/*int membro(conjunto *A, conjunto *B, conjunto *C, int capacidade)
{
}*/

int tamanho_conjunto(conjunto *A, int capacidade)
{
    int i, tamanho = 0;

    for (i = 0; i < capacidade; i++)
    {
        if ((A->valores[i] = 1))
        {
            tamanho++;
        }
    }

    return tamanho;
}

int conjuntos_iguais(conjunto *A, conjunto *B, int capacidade)
{
    int i;

    for (i = 0; i < capacidade + 1; i++)
    {
        if ((A->valores[i] == 1) != (B->valores[i] == 1))
        {
            return 0;
        }
    }

    return 1;
}

int testar_vazio(conjunto *A, int capacidade)
{
    int i;

    for (i = 0; i < capacidade; i++)
    {
        if (A->valores[i] == 1)
        {
            return 0;
        }
    }

    return 1;
}