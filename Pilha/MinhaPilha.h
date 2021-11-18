#ifndef MINHAPILHA_H
#define MINHAPILHA_H

#include "PilhaAbstrata.h"

template <typename T>
class MinhaPilha :  public PilhaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe

public:
    MinhaPilha()
    {
        PilhaAbstrata<T>::_lista = new MinhaListaEncadeada<int>;
    };

    ~MinhaPilha()
    {
        delete _lista;
    }

    bool estaVazia()
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;
        return lista->estaVazia();
    }

    int getTamanho()
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;
        return lista->getTamanho();
    }

    void push(T* umDado)
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;

        lista->adicionaNoInicio(umDado);
    }

    bool contem(T* umDado)
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;

        return lista->contem(umDado);        
    }

    int posicao(T* umDado)
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;

        return lista->posicao(umDado);        
    }

    T* pop()
    {
        ListaEncadeadaAbstrata<T>* lista;
        lista = PilhaAbstrata<T>::_lista;

        if(lista->estaVazia())
        {
            throw pilha_vazia_exception();
        }
        return lista->retiraDoInicio();
    }
};

#endif


