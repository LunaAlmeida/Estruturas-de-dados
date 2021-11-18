#ifndef PILHAABSTRATA_H
#define PILHAABSTRATA_H

#include <exception>
#include "ListaEncadeadaAbstrata.h"
#include "MinhaListaEncadeada.h"

class pilha_vazia_exception : public std::exception
{
	virtual const char* what() const throw()
    {
        return "Pilha vazia";
    }
}; 


template <typename T>
class PilhaAbstrata
{
    protected :
        ListaEncadeadaAbstrata<T>* _lista;

    public :
        virtual ~PilhaAbstrata() {};
        virtual bool estaVazia() = 0;
        virtual int getTamanho() = 0;
        virtual T* pop() = 0;
        virtual void push(T* umDado) = 0;
        virtual bool contem(T* umDado) = 0;
        virtual int posicao(T* umDado) = 0;
};

#endif