#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.h"

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe

public:
    MinhaListaEncadeada() 
    {
        ListaEncadeadaAbstrata<T>::_primeiro = NULL;
        ListaEncadeadaAbstrata<T>::_tamanho = 0;
    };
    
    ~MinhaListaEncadeada()
    {
        Elemento<T>* Lista;
        Elemento<T>* primeiro;
        
        Lista = ListaEncadeadaAbstrata<T>::_primeiro;
        while(Lista != NULL)
        {
            primeiro = Lista;
            Lista = Lista->_proximo;
            delete primeiro;
        }
        
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
        Elemento<T>* dadoPosicao;
        dadoPosicao = ListaEncadeadaAbstrata<T>::_primeiro;
        for (int i = 0; i < getTamanho(); i++)
        {
            if(dadoPosicao->_dado == umDado)
            {
                return i + 1;
                dadoPosicao = NULL;
                delete dadoPosicao;
            }

            dadoPosicao = dadoPosicao->_proximo;
        }
        return 0;
        dadoPosicao = NULL;
        delete dadoPosicao;
    }
    
    bool contem(T* umDado)
    {
        Elemento<T>* dadoContem;
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
        Elemento<T>* Dado_inicio = new Elemento<T>;
        
        Dado_inicio->_proximo = ListaEncadeadaAbstrata<T>::_primeiro;
        Dado_inicio->_dado = umDado;
        ListaEncadeadaAbstrata<T>::_primeiro = Dado_inicio;
        
        ListaEncadeadaAbstrata<T>::_tamanho += 1;
    }

    void adicionaNaPosicao(T* umDado, int umaPosicao)
    {
        if((umaPosicao <= 0) || (umaPosicao > getTamanho() + 1))
        {
            throw(posicao_invalida_exception());
        }
        
        if((umaPosicao == 1) || getTamanho() == 0)
        {
            adicionaNoInicio(umDado);
        }else{
                Elemento<T>* anteriores;
                Elemento<T>* proximo;
                Elemento<T>* atual;
                Elemento<T>* dado = new Elemento<T>;

                dado->_dado = umDado;
                dado->_proximo = NULL;
                atual = ListaEncadeadaAbstrata<T>::_primeiro;

                int j = 1;

            while(j != umaPosicao)
            {
                anteriores = atual;
                atual = atual->_proximo;
                j++;
            }

            if(atual == NULL)
            {
                dado->_proximo = atual;
                anteriores->_proximo = dado;
            }else
            {
                dado->_proximo = atual;
                anteriores->_proximo = dado;
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
        T* dado;
        Elemento<T>* novoDado_inicio;
        Elemento<T>* novoDado_posicao;
        if(getTamanho() == 0)
        {
            throw lista_encadeada_vazia_exception();
        }
        novoDado_inicio = ListaEncadeadaAbstrata<T>::_primeiro;

        novoDado_posicao = novoDado_inicio->_proximo;

        ListaEncadeadaAbstrata<T>::_primeiro = novoDado_posicao;
        ListaEncadeadaAbstrata<T>::_tamanho -= 1;
        dado = novoDado_inicio->_dado;
        
        delete novoDado_inicio;
        return dado;
    }

    T* retiraDaPosicao(int umaPosicao)
    {
        Elemento<T>* novoDado_inicio;
        Elemento<T>* dadoAnterior;
        Elemento<T>* novoDado_posicao;
        Elemento<T>* dadoRetirar;
        Elemento<T>* dadoProximo;
        
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
        dado = dadoRetirar->_dado;
        ListaEncadeadaAbstrata<T>::_tamanho -= 1;
        delete dadoRetirar;
        }

        return dado;
    }

    T* retiraDoFim()
    {
        T* dado;
        dado = retiraDaPosicao(getTamanho() + 1);

        return dado;
    }

    T* retiraEspecifico(T* umDado)
    {
        int posicaoDado = posicao(umDado);
        T* dado;
        dado = retiraDaPosicao(posicaoDado);

        return dado;
    }
};

#endif