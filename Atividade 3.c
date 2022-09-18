#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int topo;
    int vetor;
    float *elementos;
} pilha;

void criar_pilha();
void liberar_pilha(pilha *f);
int empilhar(pilha *f, float v);
int desempilhar(pilha *f);
int pilha_vazia(pilha *f);
int pilha_cheia(pilha *f);
float retornar_topo(pilha *f);

int main()
{
    pilha elementos;
    int quantidade_elementos, opcao;
    float valores;

    printf("Digite a capacidade da pilha: ");
    scanf("%d", &quantidade_elementos);

    criar_pilha(&elementos, quantidade_elementos);

    do
    {
        printf("\n\n[1]Empilhar os valores.\n[2]Desempilhar os valores.\n[3]Mostrar o topo.\n[4]Sair do programa.\n");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        // empilhar os valores

        if (opcao == 1)
        {
            int pilha_che = pilha_cheia(&elementos);

            if (pilha_che == 1)
            {
                printf("\n\nA pilha esta cheia!!\n\n");
                liberar_pilha(&elementos);
            }

            else
            {
                printf("\n\nDigite os valores para empilhar: \n");
                scanf("%f", &valores);

                printf("\n");

                empilhar(&elementos, valores);
            }

            system("pause");
            system("cls");
        }

        // desempilhar os valores

        if (opcao == 2)
        {
            int pilha_vaz = pilha_vazia(&elementos);

            if (pilha_vaz == 1)
            {
                printf("\n\nA pilha esta vazia!!\n\n");
                liberar_pilha(&elementos);
            }

            else
            {
                valores = desempilhar(&elementos);

                printf("\n\n%.1f Valores desempilhados!!\n\n", valores);
            }

            system("pause");
            system("cls");
        }

        // mostrar o topo

        if (opcao == 3)
        {
            int pilha_vaz = pilha_vazia(&elementos);

            if (pilha_vaz == 1)
            {
                printf("\n\nA pilha esta vazia!!\n\n");
                liberar_pilha(&elementos);
            }

            else
            {
                retornar_topo(&elementos);

                printf("\nO valor do topo sera: %1.f\n\n", valores); //apresentacao do primeiro valor adicionado
            }

            system("pause");
            system("cls");
        }

    } while (!(opcao == 4));

    liberar_pilha(&elementos);

    return 0;
}

void criar_pilha(pilha *f, int c)
{
    f->elementos = (float *)malloc(c * sizeof(float)); // alocaçao de memoria
    f->vetor = c; //definindo variavel c como a capacidade do vetor
    f->topo = -1;
}

void liberar_pilha(pilha *elementos)
{
    free(elementos);  //liberar memoria
}

int empilhar(pilha *f, float v) //funcao para empilhar em seguida cada valor
{
    f->topo++;
    f->elementos[f->topo] = v;
}

int desempilhar(pilha *f)
{
    float aux = f->elementos[f->topo];
    f->topo--;
    return aux;
}

int pilha_vazia(pilha *f) //funcao que retorna 1 quando estiver com a pilha vazia
{

    if (f->topo == -1)

        return 1;

    else

        return 0;
}

int pilha_cheia(pilha *f)
{

    if ((f->topo) == (f->vetor - 1)) //funcao que retorna 1 quando estiver com a pilha cheia

        return 1;

    else

        return 0;
}

float retornar_topo(pilha *f) //funcao que retorna ao topo da pilha
{

    return f[f->topo].vetor;
}