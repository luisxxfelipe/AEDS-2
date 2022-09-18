#include <stdio.h>

typedef struct RACIONAIS
{
    float num;
} tRacional;

tRacional criaRacional(tRacional *A, tRacional *B, int capacidade);
int soma(tRacional *A, tRacional *B, int capacidade);
int multiplica(tRacional *A, tRacional *B, int capacidade);
int igual(tRacional *A, tRacional *B, int capacidade);

int main()
{
    int aux, opcao;

    do
    {
        system("cls");

        printf("Seleciona uma das seguintes opções:\n\n");
        printf("(1) Somar;\n");
        printf("(2) Multiplicar;\n");
        printf("(3) Comparar iguais;\n");
        printf("(0) Encerrar.\n");
        printf("\nInsira uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            aux = soma(fila);

            break;

        case 2:
            aux = multiplica(fila);

            break;

        case 3:
            aux = igual() if (aux == 1)
            { // Vazia
                printf("\nSão iguais!\n");
            }
            else
            {
                printf("\nNão são iguais!\n");
            }

            break;

        case 0:
            printf("\nEncerrando...\n");
            liberaFila(fila);
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }

        printf("\n");
        system("pause");

    } while (opcao != 0);

    return 0;
}

tRacional criaRacional(tRacional *A, tRacional *B, int capacidade)
{
}

int soma(tRacional *A, tRacional *B, int capacidade)
{
}

int multiplica(tRacional *A, tRacional *B, int capacidade)
{
}

int igual(tRacional *A, tRacional *B, int capacidade)
{
