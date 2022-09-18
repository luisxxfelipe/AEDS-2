#include <stdio.h>
#include <math.h>

typedef struct CUBO{
    float aresta;
    float lado;
    float area;
    float volume;
}tCubo;

tCubo criaCubo(){
    tCubo p;
    p.aresta = 0;
    p.lado = 0;
    p.area = 0;
    p.volume = 0;
    return p;
}

tCubo leAresta(tCubo p){
    printf("Insira a medida da aresta: ");
    scanf("%f", &p.aresta);
    return p;
}

tCubo ladoCubo(tCubo p){//Aresta²
    p.lado = pow(p.aresta, 2.0);
    return p;
}

tCubo areaCubo(tCubo p){//Aresta² * 6
    p.area = pow(p.aresta, 2.0) * 6;
    return p;
}

tCubo volumeCubo(tCubo p){//Aresta³
    p.volume = pow(p.aresta, 3.0);
    return p;
}

void exibe(tCubo p){
    printf("\n> Medidas do cubo\n");
    printf("\nLado: %.2f", p.lado);
    printf("\nArea: %.2f", p.area);
    printf("\nVolume: %.2f\n", p.volume);
};

int main(){

    tCubo cubo;

    cubo = criaCubo();

    cubo = leAresta(cubo);

    cubo = ladoCubo(cubo);

    cubo = areaCubo(cubo);

    cubo = volumeCubo(cubo);

    exibe(cubo);

    return 0;
}
