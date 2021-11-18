#ifndef MINHAARVOREDEBUSCABINARIA_HPP
#define MINHAARVOREDEBUSCABINARIA_HPP

#include "ArvoreDeBuscaBinaria.hpp"
#include "ListaEncadeadaAbstrata.hpp"
#include <cassert>
#include <utility>
#include<iostream>
#include<algorithm>
#include <limits> 

/**
 * @brief Representa uma árvore binária de busca.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template<typename T>
class MinhaArvoreDeBuscaBinaria : public ArvoreDeBuscaBinaria<T>
{
    //implemente aqui
public:
    MinhaArvoreDeBuscaBinaria()
    {
        ArvoreDeBuscaBinaria<T>::_raiz = NULL;
    };

    void desalocarArvore(Nodo<T> *arvore)
    {
        if(arvore == NULL)
        {
            return;
        }

        desalocarArvore(arvore->filhoEsquerda);
        desalocarArvore(arvore->filhoDireita);
        delete arvore;
        arvore = NULL;
    }
    ~MinhaArvoreDeBuscaBinaria() {
        Nodo<T> *arvore;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        desalocarArvore(arvore);
        
    };

    void percorrerEmOrdem(Nodo<T> *No, ListaEncadeadaAbstrata<T>* lista) const
    {
        if(No != NULL)
        {
            percorrerEmOrdem(No->filhoEsquerda, lista);
            lista->adicionaNoFim(No->chave);
            percorrerEmOrdem(No->filhoDireita, lista);
        }
    }

    void percorrerPreOrdem(Nodo<T> *No, ListaEncadeadaAbstrata<T>* lista) const
    {
        if(No != NULL)
        {
            lista->adicionaNoFim(No->chave);
            percorrerPreOrdem(No->filhoEsquerda, lista);
            percorrerPreOrdem(No->filhoDireita, lista);
        }
    }

    void percorrerPosOrdem(Nodo<T> *No, ListaEncadeadaAbstrata<T>* lista) const
    {
        if(No != NULL)
        {
            percorrerPosOrdem(No->filhoEsquerda, lista);
            percorrerPosOrdem(No->filhoDireita, lista);
            lista->adicionaNoFim(No->chave);
        }
    }

    bool vazia() const
    {
        if (ArvoreDeBuscaBinaria<T>::_raiz == NULL)
        {
            return true;
        }
        return false;
    }

    int quantidade() const
    {
        int i = 0;

        if(ArvoreDeBuscaBinaria<T>::_raiz == NULL)
        {
            i = 0;
        }else{
            ListaEncadeadaAbstrata<Nodo<T>*>* listaQuantidade = new MinhaListaEncadeada<Nodo<T>*>;
            Nodo<T>* quantidade_No;
            quantidade_No = ArvoreDeBuscaBinaria<T>::_raiz;
            listaQuantidade->adicionaNoInicio(quantidade_No);
            i++;
            while(!listaQuantidade->estaVazia())
            {
                Nodo<T>* aux = listaQuantidade->retiraDoInicio();

                if(aux->filhoEsquerda != NULL)
                {
                    listaQuantidade->adicionaNoFim(aux->filhoEsquerda);
                    i++;
                }

                if(aux->filhoDireita != NULL)
                {
                    listaQuantidade->adicionaNoFim(aux->filhoDireita);
                    i++;
                }
            }
            delete listaQuantidade;
        }
        
        return i;
    }

    bool contem(T chave) const
    {
        bool flag = false;
        Nodo<T>* arvore;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        while(arvore != NULL && !flag)
        {
            if(arvore->chave == chave)
            {
                flag = true;
            }else if(arvore->chave > chave)
            {
                arvore= arvore->filhoEsquerda;
            }else if(arvore->chave < chave)
            {
                arvore = arvore->filhoDireita;
            }
        }

        return flag;
    }

    int alturaArvore(Nodo<T> *arvore, int chave) const
    {
        int i;
        if(arvore == NULL)
        {
            return 0;
        }else
        {
            i = 1 + std::max(alturaArvore(arvore->filhoEsquerda, chave), alturaArvore(arvore->filhoDireita, chave));
            return i;
        }
        
    }
    std::optional<int> altura(T chave) const
    {
        if(!contem(chave))
        {
            return std::nullopt;
        }else
        {
            Nodo<T>* arvore;
            arvore = ArvoreDeBuscaBinaria<T>::_raiz;
            while(arvore->chave != chave)
            {
                if(arvore->chave > chave)
                {
                    arvore = arvore->filhoEsquerda;
                }else if(arvore->chave < chave)
                {
                    arvore = arvore->filhoDireita;
                }               
            }
            return alturaArvore(arvore, chave) - 1;

        }
        return -1;
    }

    std::optional<T> filhoEsquerdaDe(T chave) const
    {
        if(!contem(chave))
        {
            return std::nullopt;
        }

        Nodo<T>* arvore;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        bool flag = false;
        int i = 0;
        while(arvore != NULL && !flag)
        {
            if(arvore->chave == chave)
            {
                if(arvore->filhoEsquerda == NULL)
                {
                    return std::nullopt;
                }else
                {
                    flag = true;
                    i = arvore->filhoEsquerda->chave;
                }
            }else if(arvore->chave > chave)
            {
                arvore= arvore->filhoEsquerda;
            }else if(arvore->chave < chave)
            {
                arvore = arvore->filhoDireita;
            }
        }

        return i;
    }

    std::optional<T> filhoDireitaDe(T chave) const
    {
        if(!contem(chave))
        {
            return std::nullopt;
        }

        Nodo<T>* arvore;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        bool flag = false;
        int i = 0;
        while(arvore != NULL && !flag)
        {
            if(arvore->chave == chave)
            {
                if(arvore->filhoDireita == NULL)
                {
                    return std::nullopt;
                }else
                {
                    flag = true;
                    i = arvore->filhoDireita->chave;
                }
            }else if(arvore->chave > chave)
            {
                arvore= arvore->filhoEsquerda;
            }else if(arvore->chave < chave)
            {
                arvore = arvore->filhoDireita;
            }
        }
        return i;
    }

    ListaEncadeadaAbstrata<T>* emOrdem() const
    {
        Nodo<T> *arvore;
        ListaEncadeadaAbstrata<T>* listaOrdenada;
        ListaEncadeadaAbstrata<T>* lista = new MinhaListaEncadeada<T>;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;

        percorrerEmOrdem(arvore, lista);
        listaOrdenada = lista;
        return listaOrdenada;
    }

    ListaEncadeadaAbstrata<T>* preOrdem() const
    {
        Nodo<T> *arvore;
        ListaEncadeadaAbstrata<T>* listaOrdenada;
        ListaEncadeadaAbstrata<T>* lista = new MinhaListaEncadeada<T>;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;

        percorrerPreOrdem(arvore, lista);
        listaOrdenada = lista;
        return listaOrdenada;
    }

    ListaEncadeadaAbstrata<T>* posOrdem() const
    {
        Nodo<T> *arvore;
        ListaEncadeadaAbstrata<T>* listaOrdenada;
        ListaEncadeadaAbstrata<T>* lista = new MinhaListaEncadeada<T>;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;

        percorrerPosOrdem(arvore, lista);
        listaOrdenada = lista;
        return listaOrdenada;
    }

    void inserir(T chave)
    {
        Nodo<T> *novaArvore = new Nodo<T>;
        if(ArvoreDeBuscaBinaria<T>::_raiz == NULL)
        {
            novaArvore->filhoDireita = NULL;
            novaArvore->filhoEsquerda = NULL;
            novaArvore->altura = 1;
            novaArvore->chave = chave;
            ArvoreDeBuscaBinaria<T>::_raiz = novaArvore;
        }else
        {
            Nodo<T> *arvore;
            arvore = ArvoreDeBuscaBinaria<T>::_raiz;
            int i = 1;
            while (arvore != NULL)
            {
                if(chave < arvore->chave)
                {
                    i++;
                    if(arvore->filhoEsquerda == NULL)
                    {
                        novaArvore->chave = chave;
                        novaArvore->altura = i;
                        novaArvore->filhoEsquerda = NULL;
                        novaArvore->filhoDireita = NULL;
                        arvore->filhoEsquerda = novaArvore;
                        arvore = NULL;
                    }else
                    {
                        arvore = arvore->filhoEsquerda;
                    }
                }else if(chave > arvore->chave)
                {
                    i++;
                    if(arvore->filhoDireita == NULL)
                    {
                        novaArvore->chave = chave;
                        novaArvore->altura = i;
                        novaArvore->filhoEsquerda = NULL;
                        novaArvore->filhoDireita = NULL;
                        arvore->filhoDireita = novaArvore;
                        arvore = NULL;
                    }else
                    {
                        arvore = arvore->filhoDireita;
                    }
                }
            }
        }
    }

    int encontrarMinimo(Nodo<T> *No) const
    {
        if(No == NULL)
        {
            return std::numeric_limits<int>::max();
        }

        int valorDireita;
        int valorEsquerda;
        int elemento;

        elemento = No->chave;
        valorDireita = encontrarMinimo(No->filhoDireita);
        valorEsquerda = encontrarMinimo(No->filhoEsquerda);


        if(valorEsquerda < elemento)
        {
            elemento = valorEsquerda;
        }

        if(valorDireita < No->chave)
        {
            elemento = valorDireita;
        }
        return elemento;
    }

    void deletar(Nodo<T> *arvore, T chave)
    {
        Nodo<T> *pai;
        bool flag;
        bool flag_2 = false;
        bool vazia = false;
        if(arvore->chave == chave && !flag_2)
        {
            flag_2 = true;
            pai = arvore;
            if((arvore->filhoDireita != NULL) && (arvore->filhoEsquerda != NULL))
            {
                if(chave == arvore->filhoDireita->chave)
                {
                    flag = false;
                    arvore = arvore->filhoDireita;
                }else if(chave == arvore->filhoEsquerda->chave)
                {
                    flag = true;
                    arvore = arvore->filhoEsquerda;
                }
            }else
            {
                pai = ArvoreDeBuscaBinaria<T>::_raiz;
                if(arvore == pai->filhoDireita)
                {
                    flag = false;
                }else if(arvore == pai->filhoEsquerda)
                {
                    flag = true;
                }else
                {
                    vazia = true;
                }
            }
        }
        else
        {
            while(arvore->chave != chave)
            {
                if(arvore->chave > chave)
                {
                    pai = arvore;
                    flag = true;
                    arvore = arvore->filhoEsquerda;
                }else if(arvore->chave < chave)
                {
                    pai = arvore;
                    flag = false;
                    arvore = arvore->filhoDireita;
                }
            }
        }

        if((arvore->filhoEsquerda == NULL) && (arvore->filhoDireita == NULL))
        {
            delete arvore;
            if(flag)
            {
                pai->filhoEsquerda = NULL;
            }else if(!flag && !vazia)
            {
                pai->filhoDireita = NULL;
            }
            if(vazia){
                ArvoreDeBuscaBinaria<T>::_raiz = NULL;
            }
            
        }else if(((arvore->filhoEsquerda != NULL)) && (arvore->filhoDireita == NULL))
        {
            if(pai->filhoEsquerda == arvore)
            {
                delete arvore;
                pai->filhoEsquerda = arvore->filhoEsquerda;
            }else{
                pai->filhoDireita = arvore->filhoEsquerda;
                delete arvore;
            }

        }else if((arvore->filhoEsquerda == NULL) && (arvore->filhoDireita != NULL))
        {
            if(pai->filhoEsquerda == arvore)
            {
                pai->filhoEsquerda = arvore->filhoDireita;
                delete arvore;
            }else{
                pai->filhoDireita = arvore->filhoDireita;
                delete arvore;
            }
        }else if((arvore->filhoEsquerda != NULL) && (arvore->filhoDireita != NULL))
        {
            T menor;
            menor = encontrarMinimo(arvore->filhoDireita);
            arvore->chave = menor;
            if(arvore == ArvoreDeBuscaBinaria<T>::_raiz)
            {
                deletar(arvore->filhoDireita, menor);
            }else
            {
                deletar(arvore, menor);
            }
            
        }
    }

    void remover(T chave)
    {
        Nodo<T> *arvore;
        arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        if(!contem(chave))
        {
            return;
        }else
        {
            deletar(arvore, chave);
        }
        
        
    }
};

#endif
