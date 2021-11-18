#include <stdlib.h>
#include <exception>
#include <new>
#include <stdio.h>

typedef struct 
{
	int numerador;
	int denominador;
} Racional;

Racional* init(int numerador, int denominador);
void destroy(Racional *p);
Racional* add(Racional* r1, Racional* r2);
Racional* subtract(Racional* r1, Racional* r2);
Racional* multiply(Racional* r1, Racional* r2);
Racional* divide(Racional* r1, Racional* r2);