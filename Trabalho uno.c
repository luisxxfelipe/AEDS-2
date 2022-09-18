#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define MAX 108
int pontos;
int pontos1;

typedef struct baralho_carta
{
    int numero;
    int cor;
} cartas;

typedef struct baralho_pilha
{
    int topo;
    cartas c[MAX];
} pilhas;

typedef struct baralho_lista // struct em lista simplesmente encadeada
{
    cartas c;
    struct baralho_lista *prox;
} lista;

void inicializa_pilha(pilhas *p);
int pilha_vazia(pilhas *p);
int pilha_cheia(pilhas *p);
int inserir(pilhas *p, cartas c);
int remover(pilhas *p, cartas *c);
int vazia(lista *l);
lista *inicializa(void);
lista *insere(lista *l, cartas c);
lista *retirar_carta(lista *jogador, cartas c, pilhas *mesa, pilhas *baralho, int cor, int num);
void carta_mesa(pilhas *mesa, pilhas *baralho);
int altura_pilha(pilhas *p);
lista *criar_mao(pilhas *baralho, lista *jogador);
void imprime_pilha(pilhas *p);
void imprime_lista(lista *l);
void cartas_amarelas(int numeros_amarelos[], int quantidade_numeros, int limiteAmarelo);
void cartas_azuis(int numeros_azuis[], int quantidade_numeros, int limiteAzul);
void cartas_vermelhas(int numeros_vermelhos[], int quantidade_numeros, int limiteVermelho);
void cartas_verdes(int numeros_verde[], int quantidade_numeros, int limiteVerde);
int contador_Cartas(lista *jogador);
int criar_baralho(pilhas *baralho);
lista *compra_43_77(pilhas *baralho, lista *jogador, int cor, int numero);
void jogar(pilhas *baralho, pilhas *mesa, lista *jogador_1, lista *jogador_2);
bool Existe(int valores[], int tam, int valor);

int main()
{
    // Declarando as variáveis do struct, pilhas e listas
    pilhas mesa;
    pilhas baralho;
    lista *jogador_1;
    lista *jogador_2;
    int opcao;
    do
    {
        printf("-----------------------------------------------------------------------------------------------\n");
        printf("|  Primeiramente, para inicializar o jogo, voce precisa aprender um pouco sobre como jogar...\n");
        printf("|  Cada numero de 0 a 4 sao representados por uma cor, sendo elas:\n");
        printf("|  0 - Amarelo.\n|  1 - Azul.\n|  2 - Vermelho.\n|  3 -Verde.\n|  4 - Preto (ele muda a cor da carta).\n|  \n");
        printf("|  Alem disso, temos as cartas especiais, sendo elas:\n");
        printf("|  +2, compre duas cartas.\n|  Bloquear, Bloqueia.\n|  Inverter, inverte o sentido.\n|  T, Curinga, TROCAR AS MAOS.\n|  +4, compre 4 e troca a cor.\n");
        printf("|  Para digitar qual carta deseja jogar, digite da seguinte forma a cor e o numero:\n|\n");
        printf("|                         5 5 ou 3 1 ou 3 3 ou 4 bloquear\n|");
        printf("\n|  Digite 1 para comecar a jogar!!\n");
        printf("|                               \n|  Digite 2 para sair!!           ");
        printf("\n");
        printf("-----------------------------------------------------------------------------------------------\n");
        printf("\n  Escolha: ");
        scanf("%d", &opcao);
        system("pause");
        system("cls");

        if (opcao == 1)
        {
            criar_baralho(&baralho);                    // criando o baralho passando a pilha de variável baralho
            carta_mesa(&mesa, &baralho);                // criando a carta que aparecerá na mesa no início da partida
            jogador_1 = criar_mao(&baralho, jogador_1); // cria as cartas para o jogador 1
            jogador_2 = criar_mao(&baralho, jogador_2); // cria as cartas para o jogador 2
            printf("\n");
            imprime_pilha(&baralho);
            jogar(&baralho, &mesa, jogador_1, jogador_2); // função jogar passando o baralho, a mesa e os jogadores
        }

    } while (!(opcao == 2));

    int opc;
    printf("\nDeseja retornar ao programa?");
    printf("\n[1] Sim\n[2] Nao: ");
    scanf("%d", &opc);

    if (opc == 1)
    {
        criar_baralho(&baralho);
        carta_mesa(&mesa, &baralho);
        jogador_1 = criar_mao(&baralho, jogador_1);
        jogador_2 = criar_mao(&baralho, jogador_2);
        printf("\n");
        imprime_pilha(&baralho);
        jogar(&baralho, &mesa, jogador_1, jogador_2);
    }

    else
    {
        exit(0);
    }
}

void inicializa_pilha(pilhas *p) // inicializa pilhas
{
    p->topo = -1;
}

int pilha_vazia(pilhas *p) // Verifica se a pilha está vazia
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_cheia(pilhas *p) // Verifica se a pilha está cheia
{
    if (p->topo == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(pilhas *p, cartas c) // Inserindo novo elemento no topo da pilha
{
    if (pilha_cheia(p))
    {
        return 0;
    }
    else
    {
        p->topo++;
        p->c[p->topo] = c;
        return 1;
    }
}

int remover(pilhas *p, cartas *c) // Removendo elemento do topo da pilha
{
    if (pilha_vazia(p))
    {
        return 0;
    }
    else
    {
        *c = p->c[p->topo];
        p->topo--;
        return 1;
    }
}

int vazia(lista *l) // verifica se a lista está vazia ou não, se nao tiver cartas, ele sera o vencedor
{
    if (l == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int altura_pilha(pilhas *p) // Imprime quantas cartas tem e retorna essa quantidade
{
    printf("A pilha esta com %d cartas", p->topo + 1);
    return p->topo + 1;
}

lista *inicializa(void) // Iniciar a lista, trazendo as "cartas" do baralho para a mão (Já que a lista representa a mão)
{
    return NULL;
}

lista *insere(lista *l, cartas c) // Ação de inserir a carta na lista "Mão"
{
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->c = c;
    novo->prox = l;
    return novo;
}

void carta_mesa(pilhas *mesa, pilhas *baralho) // Remove do baralho a carta e insere na mesa ( esta separado somente para organização )
{
    inicializa_pilha(mesa);
    cartas c;
    remover(baralho, &c);
    inserir(mesa, c);
}

lista *criar_mao(pilhas *baralho, lista *jogador) // Função que cria a mão dos jogadores (tira a carta do baralho e coloca na mão) [tira o elemento da pilha e coloca na lista]
{
    cartas c;
    jogador = inicializa();

    for (int i = 0; i < 7; i++) // comando de repetição que ira representar as 7 cartas na mao do jogador
    {
        remover(baralho, &c); // remove do topo e insere a carta na lista
        jogador = insere(jogador, c);
    }

    return jogador;
}

lista *retirar_carta(lista *jogador, cartas c, pilhas *mesa, pilhas *baralho, int cor, int num)
{

    lista *ant = NULL;
    lista *p = jogador;

    if (cor == 4 || num == 84 || num == 77)
    {

        do
        {
            printf("Deseja alterar para qual cor?: ");
            scanf("%d", &cor);

        } while (cor > 3);
        c.cor = cor;
        c.numero = num;
        remover(baralho, &c);

        inserir(mesa, c);
        system("cls");

        // verifica se achou elemento
        if (p == NULL)
            return jogador; // não achou: retorna lista original

        if (ant == NULL)
        {
            jogador = p->prox; // retira elemento do inicio
        }
        else
        {
            ant->prox = p->prox; // retira elemento do meio da lista
        }

        free(p);
        return jogador;
    }
    else
    {
        c.cor = cor; // A carta é inserida da pilha
        c.numero = num;
        inserir(mesa, c);

        // verifica se achou elemento
        if (p == NULL)
            return jogador; // não achou: retorna lista original

        // retira elemento
        if (ant == NULL)
        {
            // retira elemento do inicio
            jogador = p->prox;
        }
        else
        {
            // retira elemento do meio da lista
            ant->prox = p->prox;
        }
        free(p);
        return jogador;
    }
}

void imprime_pilha(pilhas *p) // Imprime a pilha
{
    cartas c;
    while (!pilha_vazia(p))
    {
        remover(p, &c);

        if (c.numero == 66)
        {
            printf("Cor = [%d] Carta = [%d]  \n", c.cor, c.numero);
        }
        else if (c.numero == 82)
        {
            printf("Cor = [%d] Carta = [%d] \n", c.cor, c.numero);
        }
        else if (c.numero == 77)
        {
            printf("Cor = [%d] Carta = [%d] \n", c.cor, c.numero);
        }
        else if (c.numero == 43)
        {
            printf("Cor = [%d] Carta = [%d] \n", c.cor, c.numero);
        }
        else if (c.numero == 84)
        {
            printf("Cor = %d [%d] \n", c.cor, c.numero); // Carta Curinga (trocar a cor)
        }
        else if (c.numero < 10)
        {
            printf("Cor = [%d] Carta = [%d] \n", c.cor, c.numero);
        }
    }
}

void imprime_lista(lista *l) // Ação de imprimir a lista, ou no caso do uno, mostrar a mão do jogador
{
    lista *p;
    printf("\n");
    for (p = l; p != NULL; p = p->prox)
    {

        if (p->c.numero == 66)
        {
            printf("Cor = [%d] Carta = [%d]- Bloquear \n", p->c.cor, p->c.numero); // Caso da carta especial Bloqueio
        }
        else if (p->c.numero == 82)
        {
            printf("Cor = [%d] Carta = [%d]- Inverter \n", p->c.cor, p->c.numero); // Caso da carta especial de inverter
        }
        else if (p->c.numero == 77)
        {
            printf("Cor = [%d] Carta = [%d]- +4 \n", p->c.cor, p->c.numero); // Caso da carta especial para comprar quatro cartas (e trocar a cor)
        }
        else if (p->c.numero == 43)
        {
            printf("Cor = [%d] Carta = [%d]- +2 \n", p->c.cor, p->c.numero); // Caso da carta especial para comprar duas cartas
        }
        else if (p->c.numero == 84)
        {
            printf("Cor = [%d] Carta = [%d]- Troca de cor \n", p->c.cor, p->c.numero); // Carta Curinga (trocar a cor)
        }
        else if (p->c.numero < 10)
        {
            printf("Cor = [%d] Carta = [%d] \n", p->c.cor, p->c.numero); // Caso das cartas normais
        }
    }
}

void cartas_amarelas(int numeros_amarelos[], int quantidade_numeros, int limiteAmarelo) // Função para gerar os numeros Amarelos
{

    int vAmarelo;
    for (int z = 0; z < quantidade_numeros; z++) // Passa no for 19 vezes ( que é a quantNumeros )
    {
        vAmarelo = rand() % limiteAmarelo;
        while (Existe(numeros_amarelos, z, vAmarelo))
        { // Verfica se a carta ja existe
            vAmarelo = rand() % limiteAmarelo;
        }

        if (vAmarelo != 10)
        { // Se a carta for diferente de 10 ela é inserida
            numeros_amarelos[z] = vAmarelo;
        }
        else
        {
            z--; // Se for igual a 10 ele n entra
        }
    }
}

void cartas_azuis(int numeros_azuis[], int quantidade_numeros, int limiteAzul)
{

    int vAzul;
    for (int x = 0; x < quantidade_numeros; x++)
    {
        vAzul = rand() % limiteAzul;
        while (Existe(numeros_azuis, x, vAzul))
        {
            vAzul = rand() % limiteAzul;
        }
        if (vAzul != 10)
        {
            numeros_azuis[x] = vAzul;
        }
        else
        {
            x--;
        }
    }
}

void cartas_vermelhas(int numeros_vermelhos[], int quantidade_numeros, int limiteVermelho)
{

    int vVermelho;
    for (int c = 0; c < quantidade_numeros; c++)
    {
        vVermelho = rand() % limiteVermelho;

        while (Existe(numeros_vermelhos, c, vVermelho))
        {
            vVermelho = rand() % limiteVermelho;
        }
        if (vVermelho != 10)
        {
            numeros_vermelhos[c] = vVermelho;
        }
        else
        {
            c--;
        }
    }
}

void cartas_verdes(int numeros_verde[], int quantidade_numeros, int limiteVerde)
{

    int vVerde;
    for (int i = 0; i < quantidade_numeros; i++)
    {
        while (Existe(numeros_verde, i, vVerde))
        {
            vVerde = rand() % limiteVerde;
        }
        vVerde = rand() % limiteVerde;
        if (vVerde != 10)
        {
            numeros_verde[i] = vVerde;
        }
        else
        {
            i--;
        }
    }
}

int contador_Cartas(lista *jogador)
{
    int cont = 0;
    lista *p;
    p = jogador;

    while (p != NULL)
    {
        cont++;
        p = p->prox;
    }

    printf("\nNumero de cartas que o jogador ainda tem na mao: %d\n\n", cont);

    return cont;
}

bool Existe(int valores[], int tam, int valor)
{ // Verificar se a carta já foi inserida no baralho e retorna true ou false
    for (int i = 0; i < tam; i++)
    {
        if (valores[i] == valor)
            return true;
    }
    return false;
}

int criar_baralho(pilhas *baralho) // função que ira criar o baralho e organizara o jogo
{
    cartas c;
    pilhas amarelo, azul, vermelho, verde, preto, cartas_especiais; // cria as pilhas de cores
    //// Inicializa as pilhas de cor /////
    inicializa_pilha(&amarelo);
    inicializa_pilha(&azul);
    inicializa_pilha(&vermelho);
    inicializa_pilha(&verde);
    inicializa_pilha(&preto);
    inicializa_pilha(&cartas_especiais);
    inicializa_pilha(baralho);

    srand(time(NULL));
    // Amarelo

    for (int w = 0; w < 2; w++) // Inserindo carta especial Bloqueio, inserindo na pilha especial
    {
        c.cor = 0;
        c.numero = 66;
        inserir(&cartas_especiais, c);
    }

    for (int w = 0; w < 2; w++) // Inserindo carta especial Inverter, inserindo na pilha especial
    {
        c.cor = 0;
        c.numero = 82;
        inserir(&cartas_especiais, c);
    }

    int numeros_amarelos[19];
    cartas_amarelas(numeros_amarelos, 19, 20); // Chama a função de gerar as cores e numeros
    c.cor = 0;

    for (int i = 0; i < 19; i++)
    {

        if (numeros_amarelos[i] > 10)
        {
            numeros_amarelos[i] = numeros_amarelos[i] - 10; // Ele é subtraido por 10 (nao existe numero 10)
            c.numero = numeros_amarelos[i];
            inserir(&amarelo, c); // insere na pilha
        }
        else
        {

            c.numero = numeros_amarelos[i]; // Se não for maior que 10, entra normal
            inserir(&amarelo, c);
        }
    }

    for (int w = 0; w < 2; w++) // Inserindo carta especial +2, inserindo na pilha especial
    {
        c.cor = 0;
        c.numero = 43;
        inserir(&cartas_especiais, c);
    }

    // Azul
    for (int w = 0; w < 2; w++)
    {
        c.cor = 1;
        c.numero = 43;
        inserir(&cartas_especiais, c);
    }

    int numeros_azuis[19];
    cartas_azuis(numeros_azuis, 19, 20);
    c.cor = 1;
    for (int i = 0; i < 19; i++)
    {
        if (numeros_azuis[i] > 10)
        {
            numeros_azuis[i] = numeros_azuis[i] - 10;
            c.numero = numeros_azuis[i];
            inserir(&azul, c);
        }
        else
        {

            c.numero = numeros_azuis[i];
            inserir(&azul, c);
        }
    }

    for (int w = 0; w < 2; w++)
    {
        c.cor = 1;
        c.numero = 66;
        inserir(&cartas_especiais, c);
    }

    for (int w = 0; w < 2; w++)
    {
        c.cor = 1;
        c.numero = 82;
        inserir(&cartas_especiais, c);
    }

    // Vermelho
    for (int w = 0; w < 2; w++)
    {
        c.cor = 2;
        c.numero = 66;
        inserir(&cartas_especiais, c);
    }

    for (int w = 0; w < 2; w++)
    {
        c.cor = 2;
        c.numero = 82;
        inserir(&cartas_especiais, c);
    }

    int numeros_vermelhos[19];
    cartas_vermelhas(numeros_vermelhos, 19, 20);
    c.cor = 2;

    for (int i = 0; i < 19; i++)
    {
        if (numeros_vermelhos[i] > 10)
        {
            numeros_vermelhos[i] = numeros_vermelhos[i] - 10;
            c.numero = numeros_vermelhos[i];
            inserir(&vermelho, c);
        }
        else
        {
            c.numero = numeros_vermelhos[i];
            inserir(&vermelho, c);
        }
    }

    for (int w = 0; w < 2; w++)
    {
        c.cor = 2;
        c.numero = 43;
        inserir(&cartas_especiais, c);
    }

    // Verde
    for (int w = 0; w < 2; w++)
    {
        c.cor = 3;
        c.numero = 43;
        inserir(&cartas_especiais, c);
    }

    int numeros_verde[19];
    cartas_verdes(numeros_verde, 19, 20);
    c.cor = 3;

    for (int i = 0; i < 19; i++)
    {
        if (numeros_verde[i] > 10)
        {
            numeros_verde[i] = numeros_verde[i] - 10;
            c.numero = numeros_verde[i];
            inserir(&verde, c);
        }
        else
        {
            c.numero = numeros_verde[i];
            inserir(&verde, c);
        }
    }
    for (int w = 0; w < 2; w++)
    {
        c.cor = 3;
        c.numero = 66;
        inserir(&cartas_especiais, c);
    }
    for (int w = 0; w < 2; w++)
    {
        c.cor = 3;
        c.numero = 82;
        inserir(&cartas_especiais, c);
    }

    // Preto
    int m;
    int contT = 4;
    int contR = 4;

    for (m = 0; m < 8; m++)
    {
        c.cor = 4;
        c.numero = 84; // Carta T = Troca de cor
        inserir(&preto, c);
        contT--;
    }

    for (m = 0; m < 16; m++)
    {
        c.cor = 4;
        c.numero = 77; // Carta M = +4
        inserir(&preto, c);
        contR--;
    }

    // Inserir a carta na pilha do Baralho

    srand(time(NULL));
    int aux = 0;
    for (int i = 0; i < 108; i++)
    {
        aux = rand() % 6;

        if (aux == 0)
        {
            if (!pilha_vazia(&vermelho)) // Se a pilha vermelha não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
            {
                remover(&vermelho, &c);
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }
        else

            if (aux == 1)
        {
            if (!pilha_vazia(&azul)) // Se a pilha azul não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
            {
                remover(&azul, &c);
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }
        else

            if (aux == 2)
        {
            if (!pilha_vazia(&amarelo)) // Se a pilha amarela não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
            {
                remover(&amarelo, &c);
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }
        else

            if (aux == 3)
        {
            if (!pilha_vazia(&verde)) // Se a pilha verde não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
            {
                remover(&verde, &c);
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }

        if (aux == 4)
        {
            if (!pilha_vazia(&preto))
            {                        // Se a pilha das cartas especiais não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
                remover(&preto, &c); // Lembrando que essa pilha, guarda as especiais de todas as cores
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }

        if (aux == 5)
        {
            if (!pilha_vazia(&cartas_especiais)) // Se a pilha das cartas especiais não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho (guarda as especiais de todas as cores)
            {
                remover(&cartas_especiais, &c);
                inserir(baralho, c);
            }
            else
            {
                i--;
            }
        }
    }
}

lista *compra_43_77(pilhas *baralho, lista *jogador, int cor, int numero) // Se o numero for 43 ou 77 ele entra na função das cartas "+2" e "+4"
{
    cartas c;
    if ((cor == 0 && numero == 43) || (cor == 1 && numero == 43) || (cor == 2 && numero == 43) || (cor == 3 && numero == 43) || (cor == 4 && numero == 43))
    {
        criar_baralho(baralho);
        for (int i = 0; i < 2; i++)
        {

            remover(baralho, &c);
            jogador = insere(jogador, c);
        }
    }

    if ((cor == 0 && numero == 77) || (cor == 1 && numero == 77) || (cor == 2 && numero == 77) || (cor == 3 && numero == 77) || (cor == 4 && numero == 77))
    {
        criar_baralho(baralho);
        for (int i = 0; i < 4; i++)
        {
            remover(baralho, &c);
            jogador = insere(jogador, c);
        }
    }

    return jogador;
}

void jogar(pilhas *baralho, pilhas *mesa, lista *jogador_1, lista *jogador_2)
{
    cartas c;
    int cor, cor2;
    int num, num2;
    int vez_do_jogador = 1;
    FILE *pont_arq = fopen("Arquivo_jogo.txt", "w");

    if (pont_arq == NULL)
    {
        printf("Error na abertura do arquivo!!");
        exit(1);
    }

    do
    {
        if (vez_do_jogador == 1)
        {
            pontos1 = 0;
            do
            {

                imprime_pilha(mesa); // mostra em tela as cartas que esta na mao do jogador 1
                contador_Cartas(jogador_1);
                printf("\n");
                printf("Carta na Mesa: \n");
                printf("\nO jogador 1 esta com %d pontos\n", pontos);
                printf("\n[0] Amarelo\n[1] Azul\n[2] Vermelho\n[3] Verde\n[4] Preto\n\n");
                printf("\n");
                printf("Jogador 1:\n");
                imprime_lista(jogador_1);
                printf("\n\nEscolha a carta que deseja jogar: ");
                setbuf(stdin, NULL);
                scanf("%d", &cor);
                scanf("%d", &num);

                if (num == 66)
                {
                    pontos1 = pontos1 + 20;
                }

                else if (num == 82)
                {
                    pontos1 = pontos1 + 20;
                }

                else if (num == 77)
                {
                    pontos1 = pontos1 + 50;
                }

                else if (num == 43)
                {
                    pontos1 = pontos1 + 20;
                }
                else if (num == 84)
                {
                    pontos1 = pontos1 + 50;
                }

                else if (num < 10)
                {
                    pontos1 = pontos1 + 5;
                }

                if (num > 47)
                {
                    if (num <= 57)
                    {
                        num = num - 48; // Subtraidos para encontrar os numeros de 0-9 correspondentes
                    }
                }

                if (num > 97)
                {
                    if (num <= 115)
                    {
                        num = num - 32; // Os numeros 97 a 105 são subtraídos pelo 32 para obter o alfabeto em maiusculo
                    }
                }

            } while (cor > 6 && num > 10);

            if (((num == 77) || (num == 82)) || ((num == 84) || (num == 66)) || ((num == 43) || (num < 10)))
            {
                if (cor == 5) // ao inserir cor 5 e a letra tal, o jogador irá comprar
                {
                    remover(baralho, &c);
                    jogador_1 = insere(jogador_1, c);
                    vez_do_jogador++;
                }
                else
                {
                    c.cor = cor;
                    c.numero = num;
                    jogador_1 = retirar_carta(jogador_1, c, mesa, baralho, c.cor, c.numero); // retira a carta da mão do jogador e se for 43 ou 77, o jogador adversario ira comprar
                    jogador_2 = compra_43_77(baralho, jogador_2, cor, num);
                    vez_do_jogador++;

                    if ((cor == 0 && num == 66) || (cor == 1 && num == 66) || (cor == 2 && num == 66) || (cor == 3 && num == 66) || (cor == 0 && num == 82) || (cor == 1 && num == 82) || (cor == 2 && num == 82) || (cor == 3 && num == 82)) // lembrando que 66 e block e 82 é inverter
                    {
                        vez_do_jogador = 1; // sera novamente a vez do jogador que jogou a carta 66 ou 82
                    }

                    else if ((cor == 0 && num == 77) || (cor == 1 && num == 77) || (cor == 2 && num == 77) || (cor == 3 && num == 77) || (cor == 4 && num == 77))
                    {

                        vez_do_jogador = 2;
                    }

                    else if ((cor == 4 && num == 84))
                    {
                        remover(baralho, &c);
                    }
                    contador_Cartas(jogador_1); // mostra vencedor, se acaso nao tiver mais cartas
                    system("cls");
                }

                if (pontos1 >= 500)
                {
                    printf("\n\nO jogador 1 foi o vencedor, parabens!!!\n\n");
                    fprintf(pont_arq, "\nO jogador 1 foi o vencedor, parabens!!!\n\n");
                    return;
                }
            }

            else
            {
                vez_do_jogador = 1;
            }
        }

        if (vez_do_jogador == 2)
        {
            do
            {

                printf("\n");
                contador_Cartas(jogador_2);
                printf("Carta na Mesa: ");
                imprime_pilha(mesa);
                printf("\nO jogador 2 esta com %d pontos\n", pontos);
                printf("\n[0] Amarelo\n[1] Azul\n[2] Vermelho\n[3] Verde\n[4] Preto\n\n");
                printf("\n");
                printf("Jogador 2: \n");
                imprime_lista(jogador_2);
                printf("\n\nEscolha a carta que deseja jogar: ");
                setbuf(stdin, NULL);
                scanf("%d", &cor2);
                scanf("%d", &num2);

                if (num2 == 66)
                {
                    pontos = pontos + 20;
                }

                else if (num2 == 82)
                {
                    pontos = pontos + 20;
                }

                else if (num2 == 77)
                {
                    pontos = pontos + 50;
                }

                else if (num2 == 43)
                {
                    pontos = pontos + 20;
                }

                else if (num2 == 84)
                {
                    pontos = pontos + 50;
                }
                else if (num2 < 10)
                {
                    pontos = pontos + 5;
                }
                if (num2 > 47)
                {
                    if (num2 <= 57)
                    {
                        num2 = num2 - 48; // Subtraidos para encontrar os numeros de 0-9 correspondentes
                    }
                }

                if (num2 > 97)
                {
                    if (num2 <= 115)
                    {
                        num2 = num2 - 32; // Os numeros 97 a 105 são subtraídos pelo 32 para obter o alfabeto em maiusculo
                    }
                }

            } while (cor2 > 6 && num2 > 10);

            if (((num2 == 77) || (num2 == 82)) || ((num2 == 84) || (num2 == 66)) || ((num2 == 43) || (num2 < 10)))
            {
                if (cor2 == 5)
                {
                    remover(baralho, &c);
                    jogador_2 = insere(jogador_2, c);
                    vez_do_jogador--;
                }

                else
                {
                    c.cor = cor2;
                    c.numero = num2;
                    jogador_2 = retirar_carta(jogador_2, c, mesa, baralho, c.cor, c.numero);
                    jogador_1 = compra_43_77(baralho, jogador_1, cor2, num2);
                    vez_do_jogador--;

                    if ((cor2 == 0 && num2 == 66) || (cor2 == 1 && num2 == 66) || (cor2 == 2 && num2 == 66) || (cor2 == 3 && num2 == 66) || (cor2 == 0 && num2 == 82) || (cor2 == 1 && num2 == 82) || (cor2 == 2 && num2 == 82) || (cor2 == 3 && num2 == 82))
                    {
                        vez_do_jogador = 2;
                    }

                    else if ((cor2 == 0 && num2 == 77) || (cor2 == 1 && num2 == 77) || (cor2 == 2 && num == 77) || (cor2 == 3 && num2 == 77) || (cor2 == 4 && num2 == 77))
                    {
                        vez_do_jogador = 1;
                    }

                    else if ((cor2 == 4 && num2 == 84))
                    {
                        remover(baralho, &c);
                    }
                    contador_Cartas(jogador_2);
                    system("cls");
                }

                if (pontos >= 500)
                {
                    printf("\n\nO jogador 2 foi o vencedor, parabens!!!\n\n");
                    fprintf(pont_arq, "\nO jogador 2 foi o vencedor, parabens!!!\n\n");
                    return;
                }
            }

            else
            {
                vez_do_jogador = 2;
            }
        }

        if (((cor != cor2) && (num != num2)) && ((cor != c.cor) && (num != c.numero))) // Caso esteja errada, ele recebe essa frase e perde a vez
        {
            inserir(mesa, c); // Se tiver errado ela pega a carta de volta
            printf("\nVoce tentou jogar uma carta que nao existe no seu baralho, preste atencao!\n\n");
            system("pause");
            remover(baralho, &c);
            jogador_2 = insere(jogador_2, c);
            system("cls");

            criar_baralho(baralho);
            for (int i = 0; i < 1; i++)
            {

                remover(baralho, &c);
                jogador_2 = insere(jogador_2, c);
            }

            vez_do_jogador = 1;
        }

        if (((cor2 != cor) && (num2 != num)) && ((cor2 != c.cor) && (num2 != c.numero))) // Caso esteja errada, ele recebe essa frase e perde a vez
        {
            inserir(mesa, c); // Se tiver errado ela pega a carta de volta
            printf("\nVoce tentou jogar uma carta que nao existe no seu baralho, preste mais atencao!\n\n");
            system("pause");
            remover(baralho, &c);
            jogador_1 = insere(jogador_1, c);
            system("cls");
            criar_baralho(baralho);
            for (int i = 0; i < 1; i++)
            {

                remover(baralho, &c);
                jogador_1 = insere(jogador_1, c);
            }

            vez_do_jogador = 2;
        }

        fprintf(pont_arq, "\nCartas selecionadas pelo jogador 1.\nCor: %d || Numero: %d\nPontuacao do jogador 1: %d\n.", cor, num, pontos1);
        fprintf(pont_arq, "\nCartas selecionadas pelo jogador 2.\nCor: %d || Numero: %d\nPontuacao do jogador 2: %d\n", cor2, num2, pontos);

    } while (!(pontos >= 500 || pontos1 >= 500));

    fclose(pont_arq);
    printf("\nArquivo salvado com sucesso!!\n");
}