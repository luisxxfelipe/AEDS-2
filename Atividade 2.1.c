#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vetor
{
    float vet;

} vetor;

int vetores_apresentados(vetor *vetor_dados, int quantidade_vetor);
int imprimir_dados(vetor *vetor_dados, int quantidade_vetor);
int buscando_vet(vetor *vetor_dados, int buscar, int quantidade_vetor);
void funcao_ordenacao(vetor vetor_dados[], int quantidade_vetor);
int busca_binaria(vetor vetor_dados[], int quantidade_vetor, int buscar);

int main()
{
    vetor *vetor_dados;
    int opcao, quantidade_vetor, buscar;

    printf("Digite a quantidade de valores que deseja adicionar no seu vetor: ");
    scanf("%d", &quantidade_vetor);

    // Aloca o espaco de memoria do vetor

    vetor_dados = (vetor *)calloc(quantidade_vetor, sizeof(vetor));

    // Verifica se houve erro na alocacao de memoria

    if (vetor_dados == NULL)
    {
        printf("Erro: Finalizando o programa devido a memoria insuficiente!\n");
        system("pause");
        exit(1);
    }

    vetores_apresentados(vetor_dados, quantidade_vetor);

    do
    {
        printf("\n\n[1]Apresentar todos os vetores.\n[2]Buscar sequencial do vetor.\n[3]Fazer busca binaria do vetor.\n[0] Sair do programa.");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            imprimir_dados(vetor_dados, quantidade_vetor);

            system("pause");
            system("cls");
        }

        if (opcao == 2)
        {
            printf("Digite o vetor que deseja procurar: ");
            scanf("%d", &buscar);

            int indice_vet = -1;
            funcao_ordenacao(vetor_dados, quantidade_vetor);
            indice_vet = buscando_vet(vetor_dados, buscar, quantidade_vetor);

            if (indice_vet == -1)
            {
                printf("\n\nVetor nao encontrado!!\n\n");

                printf("\n");
            }
            else
            {
                printf("\nO valor procurado encontra-se na %do posicao do vetor.\n\n", indice_vet);
            }

            system("pause");
            system("cls");
        }

        if (opcao == 3)
        {
            printf("Digite o vetor que deseja procurar: ");
            scanf("%d", &buscar);

            int indice_vet = -1;
            funcao_ordenacao(vetor_dados, quantidade_vetor);
            indice_vet = busca_binaria(vetor_dados, quantidade_vetor, buscar);

            if (indice_vet == -1)
            {
                printf("\n\nVetor nao encontrado!!\n\n");
            }

            else
            {
                printf("\nO valor procurado encontra-se na %do posicao do vetor.\n\n", indice_vet);
            }

            system("pause");
            system("cls");
        }

    } while (!(opcao == 0));

    return 0;
}

int vetores_apresentados(vetor *vetor_dados, int quantidade_vetor)
{
    for (int i = 0; i < quantidade_vetor; i++)
    {
        printf("\n\nDigite o %do valor do vetor: \n", i + 1);
        scanf("%f", &vetor_dados[i].vet);
    }
}

int imprimir_dados(vetor *vetor_dados, int quantidade_vetor)
{
    for (int i = 0; i < quantidade_vetor; i++)
    {
        printf("Vetor: %.1f\n", vetor_dados[i].vet);
    }
}

void funcao_ordenacao(vetor vetor_dados[], int quantidade_vetor)
{
    int i, j;
    vetor aux;
    for (j = quantidade_vetor - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (vetor_dados[i + 1].vet < vetor_dados[i].vet)
            {
                // trocar vetor_dados[i] com vetor_dados[i+1]

                aux = vetor_dados[i];
                vetor_dados[i] = vetor_dados[i + 1];
                vetor_dados[i + 1] = aux;
            }
        }
    }
}

// Função para buscar de vet pelo Bubblesort

int buscando_vet(vetor *vetor_dados, int buscar, int quantidade_vetor)
{
    for (int i = 0; i < quantidade_vetor; i++)
    {
        if (vetor_dados[i].vet == buscar)
        {
            return i;
        }
    }
    return -1; // Se nao entrar na condiçao if, o codigo continua executando e retorna ao -1
}

int busca_binaria(vetor vetor_dados[], int quantidade_vetor, int buscar)
{
    int esq, dir, i;
    esq = 0;
    dir = quantidade_vetor - 1;
    do
    {
        i = (esq + dir) / 2;
        if (buscar > vetor_dados[i].vet)
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }
    } while (buscar != vetor_dados[i].vet && esq <= dir);

    if (buscar == vetor_dados[i].vet)
    {
        return i;
    }
    else
    {
        return -1;
    }

    return (0);
}