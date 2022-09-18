#include <stdio.h>
#include <math.h>

#define pi 3.141592654

typedef struct CILINDRO
{
    float altura;
    float raio;
    float area;
    float volume;
} tCilindro;

tCilindro criaCilindro()
{
    tCilindro p;
    p.altura = 0;
    p.raio = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

tCilindro alturaCilindro(tCilindro p)
{
    printf("Insira a altura do cilindro: ");
    scanf("%f", &p.altura);
    return p;
}

tCilindro raioCilindro(tCilindro p)
{
    printf("Insira o raio do cilindro: ");
    scanf("%f", &p.raio);
    return p;
}

tCilindro areaCilindro(tCilindro p)
{ // 2 * Pi * Raio * Altura + 2 * (Pi * Raio²)
    p.area = 2.0 * pi * p.raio * p.altura + 2.0 * (pi * pow(p.raio, 2.0));
    return p;
}

tCilindro volumeCilindro(tCilindro p)
{ // Pi * Raio² * Altura
    p.volume = pi * pow(p.raio, 2.0) * p.altura;
    return p;
}

void exibe(tCilindro p)
{
    printf("\n> Medidas do cilindro\n");
    printf("\nAltura: %.2f", p.altura);
    printf("\nRaio: %.2f", p.raio);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
}

int main()
{

    tCilindro cilindro;

    cilindro = criaCilindro();

    cilindro = alturaCilindro(cilindro);

    cilindro = raioCilindro(cilindro);

    return 0;
}
