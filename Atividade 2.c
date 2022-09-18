#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno
{
    char nome[50];
    float matricula;
    float notas[3];
    float media;
} aluno;

int dados_aluno_completo(aluno *dados_aluno, int quantidade_alunos);
int imprimir_dados(aluno *dados_aluno, int quantidade_alunos);
void funcao_ordenacao(aluno dados_aluno[], int quantidade_alunos);
float media(float n1, float n2, float n3);
int buscando_matricula(aluno *dados_aluno, int buscar, int quantidade_alunos);
int busca_binaria(aluno dados_aluno[], int quantidade_alunos, int buscar);

int main()
{ 

    aluno *dados_aluno;
    int quantidade_alunos, opcao, i, buscar;

    printf("Para iniciar, digite quantos alunos deseja adicionar: ");
    scanf("%d", &quantidade_alunos);

    // Aloca o espaco de memoria do vetor

    dados_aluno = (aluno *)calloc(quantidade_alunos, sizeof(aluno));

    // Verifica se houve erro na alocacao de memoria

    if (dados_aluno == NULL)
    {
        printf("Erro: Finalizando o programa devido a memoria insuficiente!\n");
        system("pause");
        exit(1);
    }

    dados_aluno_completo(dados_aluno, quantidade_alunos);

    do
    {

        printf("\n\n[1]Imprimir todos os dados dos alunos.\n[2]Fazer busca sequencial de matricula.\n[3]Fazer busca binaria de matricula.\n[4]Imprimir os alunos ordenados de acordo com sua matricula.\n[0] Sair do programa.");
        printf("\n\nEscolha alguma opcao acima: ");
        scanf("%d", &opcao);

        // Imprimir todos os dados dos alunos

        if (opcao == 1)
        {
            imprimir_dados(dados_aluno, quantidade_alunos);

            system("pause");
            system("cls");
        }

        // Fazer busca sequencial de matricula

        if (opcao == 2)
        {
            printf("Digite a matricula do aluno que deseja procurar: ");
            scanf("%d", &buscar);

            int indice_matricula = -1;

            indice_matricula = buscando_matricula(dados_aluno, buscar, quantidade_alunos);

            if (indice_matricula == -1)
            {
                printf("\nAluno nao encontrado!!");

                printf("\n");
            }
            else
            {
                printf("\nO valor procurado encontra-se na %do posicao do vetor.\n\n", indice_matricula);
                printf("\nNome: %s", dados_aluno[indice_matricula].nome);
                printf("\nMatricula: %.0f\n", dados_aluno[indice_matricula].matricula);
                printf("\nNota 1: %.2f\n", dados_aluno[indice_matricula].notas[0]);
                printf("Nota 2: %.2f\n", dados_aluno[indice_matricula].notas[1]);
                printf("Nota 3: %.2f\n", dados_aluno[indice_matricula].notas[2]);
                printf("Media: %.2f\n\n", dados_aluno[indice_matricula].media);
            }

            system("pause");
            system("cls");
        }

        // Fazer busca binaria de matricula

        if (opcao == 3)
        {
            printf("Digite a matricula do aluno que deseja procurar: ");
            scanf("%d", &buscar);

            int indice_matricula = -1;
            funcao_ordenacao(dados_aluno, quantidade_alunos);
            indice_matricula = busca_binaria(dados_aluno, quantidade_alunos, buscar);

            if (indice_matricula == -1)
            {
                printf("Matricula nao encontrada, tente novamente!!");
            }

            else
            {
                printf("\nO valor procurado encontra-se na %do posicao do vetor.\n\n", indice_matricula);
                printf("\nNome: %s", dados_aluno[indice_matricula].nome);
                printf("\nMatricula: %.0f\n", dados_aluno[indice_matricula].matricula);
                printf("\nNota 1: %.2f\n", dados_aluno[indice_matricula].notas[0]);
                printf("Nota 2: %.2f\n", dados_aluno[indice_matricula].notas[1]);
                printf("Nota 3: %.2f\n", dados_aluno[indice_matricula].notas[2]);
                printf("Media: %.2f\n\n", dados_aluno[indice_matricula].media);
            }
        }

        // Imprimir os alunos ordenados de acordo com sua matricula

        if (opcao == 4)
        {
            printf("\n\nNumeros de matricula em ordem crescente:\n");

            funcao_ordenacao(dados_aluno, quantidade_alunos);

            for (i = 0; i < quantidade_alunos; i++)
            {
                printf("\n\nAluno: %s\n", dados_aluno[i].nome);
                printf("\nMatricula: %0.f\n", dados_aluno[i].matricula);
                printf("\nNota 1: %.2f\n", dados_aluno[i].notas[0]);
                printf("Nota 2: %.2f\n", dados_aluno[i].notas[1]);
                printf("Nota 3: %.2f\n", dados_aluno[i].notas[2]);
                printf("Media: %.2f\n\n", dados_aluno[i].media);
            }

            printf("\n");

            system("pause");
            system("cls");
        }
    } while (!(opcao == 0));

    return 0;
}

int dados_aluno_completo(aluno *dados_aluno, int quantidade_alunos)
{
    for (int i = 0; i < quantidade_alunos; i++)
    {
        dados_aluno[i].media = 0;

        printf("\nDigite o nome do %do aluno: ", i + 1);
        scanf("%s", dados_aluno[i].nome);
        printf("\nDigite o numero da matricula do %do aluno: ", i + 1);
        scanf("%f", &dados_aluno[i].matricula);
        printf("\nDigite a nota 1 do aluno %d aluno: ", i + 1);
        scanf("%f", &dados_aluno[i].notas[0]);
        printf("\nDigite a nota 2 do aluno %d aluno: ", i + 1);
        scanf("%f", &dados_aluno[i].notas[1]);
        printf("\nDigite a nota 3 do aluno %d aluno: ", i + 1);
        scanf("%f", &dados_aluno[i].notas[2]);
        dados_aluno[i].media = (dados_aluno[i].notas[0] + dados_aluno[i].notas[1] + dados_aluno[i].notas[2]) / 3.0;
    }
}

int imprimir_dados(aluno *dados_aluno, int quantidade_alunos)
{
    for (int i = 0; i < quantidade_alunos; i++)
    {
        printf("\n\nAluno: %s\n", dados_aluno[i].nome);
        printf("\nMatricula: %0.f\n", dados_aluno[i].matricula);
        printf("\nNota 1: %.2f\n", dados_aluno[i].notas[0]);
        printf("Nota 2: %.2f\n", dados_aluno[i].notas[1]);
        printf("Nota 3: %.2f\n", dados_aluno[i].notas[2]);
        printf("Media: %.2f\n\n", dados_aluno[i].media);
    }
}

void funcao_ordenacao(aluno dados_aluno[], int quantidade_alunos)
{
    int i, j;
    aluno aux;
    for (j = quantidade_alunos - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (dados_aluno[i + 1].matricula < dados_aluno[i].matricula)
            {
                // trocar dados_aluno[i] com dados_aluno[i+1]

                aux = dados_aluno[i];
                dados_aluno[i] = dados_aluno[i + 1];
                dados_aluno[i + 1] = aux;
            }
        }
    }
}

// Função para buscar de matricula pelo Bubblesort

int buscando_matricula(aluno *dados_aluno, int buscar, int quantidade_alunos)
{
    for (int i = 0; i < quantidade_alunos; i++)
    {
        if (dados_aluno[i].matricula == buscar)
        {
            return i;
        }
    }
    return -1; // Se nao entrar na condiçao if, o codigo continua executando e retorna ao -1
}

int busca_binaria(aluno dados_aluno[], int quantidade_alunos, int buscar)
{
    int esq, dir, i;
    esq = 0;
    dir = quantidade_alunos - 1;
    do
    {
        i = (esq + dir) / 2;
        if (buscar > dados_aluno[i].matricula)
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }
    } while (buscar != dados_aluno[i].matricula && esq <= dir);

    if (buscar == dados_aluno[i].matricula)
    {
        return i;
    }
    else
    {
        return -1;
    }

    return (0);
}
