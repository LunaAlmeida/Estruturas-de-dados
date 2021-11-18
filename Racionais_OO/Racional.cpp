#include "Racional.h"

//implemente aqui as funcoes do Racional

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

Racional::Racional (int numerador = 0, int denominador = 1)
{
    if (denominador == 0)
    {
        throw::excecao_denominador_nulo();
    }
    _numerador = numerador;
    _denominador = denominador;
}

int Racional::getNumerador() const
{
    return _numerador;
}

int Racional::getDenominador() const
{
    return _denominador;
}

bool Racional::operator==(const Racional& r2)
{
    bool equal = false;
    if ((_denominador == r2.getDenominador()) && (_numerador == r2.getNumerador()))
    {
        equal = true;
    }
    return equal;
}

Racional Racional::operator+(const Racional& r2)
{
    Racional sum;

    sum._denominador = mmc(_denominador, r2.getDenominador());
    sum._numerador = (_numerador * (sum._denominador / _denominador)) + (r2.getNumerador() * (sum._denominador / r2.getDenominador()));

    return sum;
}
Racional Racional::operator-(const Racional& r2)
{
    Racional sub;
    sub._denominador = mmc(_denominador, r2.getDenominador());
    sub._numerador = (_numerador * (sub._denominador / _denominador)) - (r2.getNumerador() * (sub._denominador / r2.getDenominador()));

    if(sub.getNumerador() < 0)
    {
        sub._numerador *= -1;
        sub._denominador *= -1; 
    }

    return sub;
}
Racional Racional::operator*(const Racional& r2)
{
    Racional mult;
    mult._numerador = _numerador * r2.getNumerador();
    mult._denominador = _denominador * r2.getDenominador();

    int simplify;
    simplify = mdc(mult.getNumerador(), mult.getDenominador());

    mult._numerador /= simplify;
    mult._denominador /= simplify;

    return mult;
}

Racional Racional::operator/(const Racional& r2)
{
        Racional mult;
    mult._numerador = _numerador * r2.getDenominador();
    mult._denominador = _denominador * r2.getNumerador();

    int simplify;
    simplify = mdc(mult.getNumerador(), mult.getDenominador());

    mult._numerador /= simplify;
    mult._denominador /= simplify;

    return mult;
}