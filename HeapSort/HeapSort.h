#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "AbstractSort.h"
#include <exception>

class posicao_invalida_exception : public std::exception
{
	virtual const char* what() const throw()
  	{
    	return "Posicao invalida na heap";
  	}
} ; 

class HeapSort : public AbstractSort
{
	public :
		void sort(Elemento ** umVetor, int quantidadeDeElementos);
		void max_heapify(Elemento ** umVetor, int quantidadeDeElementos, int i);
		void construirHeapMax(Elemento ** umVetor,int tamanho);
};

#endif /* HEAPSORT_H */