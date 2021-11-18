#include "racional.h"

int mdc(int den1, int den2)
{
    int r = 1;

    while (r != 0)
    {
        r = den1 % den2;
        den1 = den2;
        den2 = r;
    }

    return den1;
}

int mmc(int den1, int den2)
{
    return den1 * (den2 / mdc(den1, den2));
}

Racional* init(int numerador, int denominador)
{
    //Racional* number = (Racional*) calloc(1, sizeof(Racional));
    Racional* number = new Racional;

    if (denominador == 0)
    {
        return nullptr;
    }
    if (number == NULL)
    {
        system("pause");
        exit(1);
    }
    number->numerador = numerador;
    number->denominador = denominador;

    
    return number;
}
void destroy(Racional *p)
{
    delete p;
}
Racional* add(Racional* r1, Racional* r2)
{
    Racional* number = new Racional;

    number->denominador = mmc(r1->denominador, r2->denominador);
    number->numerador = ((number->denominador / r1->denominador) * r1->numerador) + ((number->denominador / r2->denominador) * r2->numerador);
    
    return number;
}
Racional* subtract(Racional* r1, Racional* r2)
{
    Racional* number = new Racional;

    number->denominador = mmc(r1->denominador, r2->denominador);
    number->numerador = ((number->denominador / r1->denominador) * r1->numerador) - ((number->denominador / r2->denominador) * r2->numerador);
    
    return number;
}
Racional* multiply(Racional* r1, Racional* r2)
{
    Racional* number = new Racional;

    number->numerador = r1->numerador * r2->numerador;
    number->denominador = r1->denominador * r2->denominador;

    int s;

    s = mdc(number->numerador, number->denominador);

    number->numerador /= s;
    number->denominador /= s;
    
    return number;
}

Racional* divide(Racional* r1, Racional* r2)
{
    Racional* number = new Racional;
    
    number->numerador = r1->numerador * r2->denominador;
    number->denominador = r1->denominador * r2->numerador;

    int s;

    s = mdc(number->numerador, number->denominador);

    number->numerador /= s;
    number->denominador /= s;
    
    return number;
}