#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.h"
#include <stdlib.h>

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe

private:
    Elemento<T>* dadoPosicao = new Elemento<T>;
    Elemento<T>* dadoContem = new Elemento<T>;
    Elemento<T>* novoDado_inicio = new Elemento<T>;
    Elemento<T>* novoDado_posicao = new Elemento<T>;
    Elemento<T>* dadoAnterior = new Elemento<T>;
    Elemento<T>* dadoRetirar = new Elemento<T>;
    Elemento<T>* dadoProximo = new Elemento<T>;
public:
    MinhaListaEncadeada() 
    {
        ListaEncadeadaAbstrata<T>::_primeiro = NULL;
        ListaEncadeadaAbstrata<T>::_tamanho = 0;
    };

    ~MinhaListaEncadeada()
    {
        /*delete novoDado_inicio;
        delete dadoContem;
        delete dadoPosicao;
        delete novoDado_posicao;
        delete dadoAnterior;
        delete dadoRetirar;
        delete dadoProximo;*/
    };

    int getTamanho() {
        return ListaEncadeadaAbstrata<T>::_tamanho;
    }

    bool estaVazia() {
        if (getTamanho() == 0)
            return true;

        return false;
    }
    
    int posicao(T* umDado)
    {
        dadoPosicao = ListaEncadeadaAbstrata<T>::_primeiro;
        for (int i = 0; i < getTamanho(); i++)
        {
            if(dadoPosicao->_dado == umDado)
            {
                return i + 1;
            }

            dadoPosicao = dadoPosicao->_proximo;
        }
        return 0;
    }
    
    bool contem(T* umDado)
    {
        dadoContem = ListaEncadeadaAbstrata<T>::_primeiro;
        for (int i = 0; i < getTamanho(); i++)
        {
            if(dadoContem->_dado == umDado)
            {
                return true;
            }

            dadoContem = dadoContem->_proximo;
        }
        return false;
    }
    
    void adicionaNoInicio(T* umDado)
    {
        if(getTamanho() == 0)
        {
            novoDado_inicio->_proximo = ListaEncadeadaAbstrata<T>::_primeiro;
            novoDado_inicio->_dado = umDado;
            ListaEncadeadaAbstrata<T>::_primeiro = novoDado_inicio;
        }else
        {
            novoDado_inicio++;
            novoDado_inicio->_proximo = ListaEncadeadaAbstrata<T>::_primeiro;
            novoDado_inicio->_dado = umDado;
            ListaEncadeadaAbstrata<T>::_primeiro = novoDado_inicio;
        }

        
        ListaEncadeadaAbstrata<T>::_tamanho += 1;
    }

    void adicionaNaPosicao(T* umDado, int umaPosicao)
    {
        if((umaPosicao <= 0) || (umaPosicao > getTamanho() + 1))
        {
            throw(posicao_invalida_exception());
        }
        dadoPosicao = ListaEncadeadaAbstrata<T>::_primeiro;
        int j = 0;
        while(j != umaPosicao - 1)
        {
                j++;
                dadoAnterior->_proximo = dadoPosicao->_proximo;
                dadoAnterior->_dado = dadoPosicao->_dado;
                dadoPosicao = dadoPosicao->_proximo;
        }
        if((umaPosicao == 0) || getTamanho() == 0)
        {
            adicionaNoInicio(umDado);
        }else{
            dadoPosicao = ListaEncadeadaAbstrata<T>::_primeiro;
            novoDado_inicio = ListaEncadeadaAbstrata<T>::_primeiro;
            for (int i = 0; i <= getTamanho(); i++)
            {
                if(i == umaPosicao - 1)
                {
                    dadoAnterior->_proximo = novoDado_posicao;
                    novoDado_posicao->_proximo = dadoPosicao;
                    novoDado_posicao->_dado = umDado;
                    if(dadoAnterior->_dado != novoDado_inicio->_dado)
                    {
                        novoDado_inicio->_proximo = dadoAnterior;
                        ListaEncadeadaAbstrata<T>::_primeiro = novoDado_inicio;
                        break;
                    }
                    ListaEncadeadaAbstrata<T>::_primeiro = dadoAnterior;
                    break;
                }
                dadoPosicao = dadoPosicao->_proximo;
            }
            ListaEncadeadaAbstrata<T>::_tamanho += 1;
        }
    }
    void adicionaNoFim(T* umDado)
    {
        adicionaNaPosicao(umDado, getTamanho() + 1);
    }

    T* retiraDoInicio()
    {
        if(getTamanho() == 0)
        {
            throw lista_encadeada_vazia_exception();
        }
        novoDado_inicio = ListaEncadeadaAbstrata<T>::_primeiro;

        novoDado_posicao = novoDado_inicio->_proximo;

        ListaEncadeadaAbstrata<T>::_primeiro = novoDado_posicao;
        ListaEncadeadaAbstrata<T>::_tamanho -= 1;
        return novoDado_inicio->_dado;
    }

    T* retiraDaPosicao(int umaPosicao)
    {
        T* dado;
        if((umaPosicao <= 0) || (umaPosicao >= getTamanho() + 1))
        {
            throw(posicao_invalida_exception());
        }
        novoDado_posicao = ListaEncadeadaAbstrata<T>::_primeiro;
        dadoAnterior = ListaEncadeadaAbstrata<T>::_primeiro;

        int j = umaPosicao - 1;

        if(umaPosicao == 1)
        {
            dado = retiraDoInicio();
        }else{
        while(j != 0)
        {
            dadoAnterior = novoDado_posicao;
            novoDado_posicao = novoDado_posicao->_proximo;
            if(j == 1)
            {
                dadoProximo = novoDado_posicao->_proximo;
                dadoRetirar = novoDado_posicao;
                dadoRetirar->_dado = novoDado_posicao->_dado;
            }
            j--;            
        }
        dadoAnterior->_proximo = dadoProximo;
        novoDado_inicio++;
        dado = dadoRetirar->_dado;
        ListaEncadeadaAbstrata<T>::_tamanho -= 1;
        }

        return dado;
    }

    T* retiraDoFim()
    {
        T* dado;
        dado = retiraDaPosicao(getTamanho() + 1);
        delete dado;
        return dado;
    }

    T* retiraEspecifico(T* umDado)
    {
        int posicaoDado = posicao(umDado);
        T* dado;
        dado = retiraDaPosicao(posicaoDado);
        delete dado;
        return dado;
    }
};

#endif