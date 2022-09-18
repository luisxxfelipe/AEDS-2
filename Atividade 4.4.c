#include <stdio.h>
#include <math.h>

#define pi 3.141592654

typedef struct ESFERA
{
    float raio;
    float area;
    float volume;
} tEsfera;

tEsfera criaEsfera()
{
    tEsfera p;
    p.raio = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

tEsfera raioEsfera(tEsfera p)
{
    printf("Insira o raio da esfera: ");
    scanf("%f", &p.raio);
    return p;
}

tEsfera areaEsfera(tEsfera p)
{ // 4 * Pi * Raio²
    p.area = 4.0 * pi * pow(p.raio, 2.0);
    return p;
}

tEsfera volumeEsfera(tEsfera p)
{ // 4/3 * Pi * Raio³
    p.volume = (4.0 / 3.0) * pi * pow(p.raio, 3.0);
    return p;
}

void exibe(tEsfera p)
{
    printf("\n> Medidas da esfera\n");
    printf("\nRaio: %.2f", p.raio);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
}

int main()
{

    tEsfera esfera;

    esfera = criaEsfera();

    esfera = raioEsfera(esfera);

    esfera = areaEsfera(esfera);

    esfera = volumeEsfera(esfera);

    exibe(esfera);

    return 0;
}
