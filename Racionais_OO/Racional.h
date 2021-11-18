#ifndef _racional_h_
#define _racional_h_

#include <exception>

class excecao_denominador_nulo : public std::exception
{
	virtual const char* what() const throw()
    {
        return "Denominador nulo";
    }
}; 

class Racional
{
    private:
        int _numerador;
        int _denominador;

    public:
        Racional(int numerado, int denominador);
        int getNumerador() const;
        int getDenominador() const;
        bool operator==(const Racional& r2);
        Racional operator+(const Racional& r2);
        Racional operator-(const Racional& r2);
        Racional operator*(const Racional& r2);
        Racional operator/(const Racional& r2);
};
#endif