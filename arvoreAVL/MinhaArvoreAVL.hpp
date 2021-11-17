#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "MinhaArvoreDeBuscaBinaria.hpp"

/**
 * @brief Representa uma árvore AVL.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL : public MinhaArvoreDeBuscaBinaria<T>
{
    //implemente aqui
public:
    MinhaArvoreAVL() {};
    ~MinhaArvoreAVL(){};

    bool contemPai(Nodo<T> *pai, T chave) const
    {
        bool flag = false;
        Nodo<T>* arvore;
        arvore = pai;
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

    int verificarBalanceamento(Nodo<T> *No)
    {
        if((No->filhoEsquerda == NULL) && (No->filhoDireita == NULL))
        {
            return No->altura;
        }else if((No->filhoEsquerda != NULL) && (No->filhoDireita == NULL))
        {
            return No->filhoEsquerda->altura - (-1);
        }else if((No->filhoEsquerda == NULL) && (No->filhoDireita != NULL))
        {
            return (-1) - No->filhoDireita->altura;
        }
        return No->filhoEsquerda->altura - No->filhoDireita->altura;
    }

    Nodo<T>* acharNodesbalanceado(Nodo<T> *No)
    {
        Nodo<T> *elemento = NULL;

        ListaEncadeadaAbstrata<Nodo<T>*>* listaAuxiliar = new MinhaListaEncadeada<Nodo<T>*>;

        listaAuxiliar->adicionaNoInicio(No);
        while(!listaAuxiliar->estaVazia())
        {
            Nodo<T>* aux = listaAuxiliar->retiraDoInicio();
            if(aux->filhoEsquerda != NULL)
            {
                listaAuxiliar->adicionaNoFim(aux->filhoEsquerda);
                if(verificarBalanceamento(aux) > 1)
                {
                    elemento = aux;
                }
            }
            if(aux->filhoDireita != NULL)
            {
                listaAuxiliar->adicionaNoFim(aux->filhoDireita);
                if(verificarBalanceamento(aux) < -1)
                {
                    elemento = aux;
                }
            }
        }

        delete listaAuxiliar;

        if(elemento == NULL)
        {
            return NULL;
        }

        return elemento;
    }

    int paiNoDesbalanceado(int chave)
    {
        Nodo<T> *arvore = ArvoreDeBuscaBinaria<T>::_raiz;
        Nodo<T> *aux = arvore;

        while(arvore->chave != chave)
        {
            if(chave < arvore->chave)
            {
                if(chave == aux->filhoEsquerda->chave)
                {
                    return aux->chave;
                }

                aux = aux->filhoEsquerda;

            }else if(chave > arvore->chave)
            {
                if(chave == arvore->filhoDireita->chave)
                {
                    return arvore->chave;
                }

                aux = aux->filhoDireita;
            }
        }
        if(aux->chave == chave)
        {
            return aux->chave;
        }
        return 0;
    }

    Nodo<T>* RotacaoDireitaSimples(Nodo<T> *No)
    {
        Nodo<T> *rotacao;
        rotacao = No->filhoEsquerda;
        No->filhoEsquerda = rotacao->filhoDireita;
        rotacao->filhoDireita = No;
        No->altura = MinhaArvoreDeBuscaBinaria<T>::alturaArvore(No);
        rotacao->altura = MinhaArvoreDeBuscaBinaria<T>::alturaArvore(rotacao);
        return rotacao;
    }

    Nodo<T>* RotacaoEsquerdaSimples(Nodo<T> *No)
    {
        Nodo<T> *rotacao;
        rotacao = No->filhoDireita;
        No->filhoDireita = rotacao->filhoEsquerda;
        rotacao->filhoEsquerda = No;
        No->altura = MinhaArvoreDeBuscaBinaria<T>::alturaArvore(No);
        rotacao->altura = MinhaArvoreDeBuscaBinaria<T>::alturaArvore(rotacao);
        return rotacao;
    }

    void inserir(T chave)
    {
        MinhaArvoreDeBuscaBinaria<T>::inserir(chave);
        Nodo<T> *arvoreBalanceada;
        Nodo<T> *desbalanceado;
        int pai;

        arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz;
        std::cout <<"oiiii"<< arvoreBalanceada->chave << std::endl;
        desbalanceado = acharNodesbalanceado(arvoreBalanceada);

        if(desbalanceado != NULL)
        {
            pai = paiNoDesbalanceado(desbalanceado->chave);
            if(verificarBalanceamento(desbalanceado) > 1)
            {
                if(chave < desbalanceado->filhoEsquerda->chave)
                {
                    desbalanceado = RotacaoDireitaSimples(desbalanceado);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz;
                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = desbalanceado;
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        ArvoreDeBuscaBinaria<T>::_raiz = desbalanceado;
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }else
                {
                    desbalanceado->filhoEsquerda = RotacaoEsquerdaSimples(desbalanceado->filhoEsquerda);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz;
                    while(arvoreBalanceada->chave != pai)
                    {

                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = RotacaoDireitaSimples(desbalanceado);
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        arvoreBalanceada->filhoEsquerda = RotacaoDireitaSimples(desbalanceado);
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }
            }else if(verificarBalanceamento(desbalanceado) < -1)
            {
                if(chave > desbalanceado->filhoDireita->chave)
                {
                    desbalanceado = RotacaoEsquerdaSimples(desbalanceado);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz; 
                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoDireita->chave == pai)
                        {
                            arvoreBalanceada->filhoDireita = desbalanceado;
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoDireita;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        ArvoreDeBuscaBinaria<T>::_raiz = desbalanceado;
                    }

                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);

                }else
                {
                    desbalanceado->filhoDireita = RotacaoDireitaSimples(desbalanceado->filhoDireita);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz; 

                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoDireita->chave == pai)
                        {
                            arvoreBalanceada->filhoDireita = RotacaoEsquerdaSimples(desbalanceado);
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoDireita;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        arvoreBalanceada->filhoDireita = RotacaoEsquerdaSimples(desbalanceado);
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }
                
            }
        }
        
    }

    void remover(T chave)
    {
        MinhaArvoreDeBuscaBinaria<T>::remover(chave);
        Nodo<T> *arvoreBalanceada;
        Nodo<T> *desbalanceado;
        int pai;

        arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz;

        desbalanceado = acharNodesbalanceado(arvoreBalanceada);

        if(desbalanceado != NULL)
        {
            pai = paiNoDesbalanceado(desbalanceado->chave);
            if(verificarBalanceamento(desbalanceado) > 1)
            {
                if((MinhaArvoreDeBuscaBinaria<T>::alturaArvore(desbalanceado->filhoEsquerda->filhoEsquerda)) >= (MinhaArvoreDeBuscaBinaria<T>::alturaArvore(desbalanceado->filhoEsquerda->filhoDireita)))
                {
                    desbalanceado = RotacaoDireitaSimples(desbalanceado);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz; 
                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = desbalanceado;
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        ArvoreDeBuscaBinaria<T>::_raiz = desbalanceado;
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }else
                {
                    desbalanceado->filhoEsquerda = RotacaoEsquerdaSimples(desbalanceado->filhoEsquerda);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz;

                    while(arvoreBalanceada->chave != pai)
                    {

                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = RotacaoDireitaSimples(desbalanceado);
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        arvoreBalanceada->filhoEsquerda = RotacaoDireitaSimples(desbalanceado);
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }

            }else if(verificarBalanceamento(desbalanceado) < -1)
            {
                if((MinhaArvoreDeBuscaBinaria<T>::alturaArvore(desbalanceado->filhoDireita->filhoEsquerda)) <= (MinhaArvoreDeBuscaBinaria<T>::alturaArvore(desbalanceado->filhoDireita->filhoDireita)))
                {
                    desbalanceado = RotacaoEsquerdaSimples(desbalanceado);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz; 
                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = desbalanceado;
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        ArvoreDeBuscaBinaria<T>::_raiz = desbalanceado;
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);
                }else
                {
                    desbalanceado->filhoEsquerda = RotacaoDireitaSimples(desbalanceado->filhoEsquerda);
                    arvoreBalanceada = ArvoreDeBuscaBinaria<T>::_raiz; 
                    while(arvoreBalanceada->chave != pai)
                    {
                        if(arvoreBalanceada->filhoEsquerda->chave == pai)
                        {
                            arvoreBalanceada->filhoEsquerda = RotacaoEsquerdaSimples(desbalanceado);
                        }
                        arvoreBalanceada = arvoreBalanceada->filhoEsquerda;
                    }
                    if(arvoreBalanceada->chave == pai)
                    {
                        ArvoreDeBuscaBinaria<T>::_raiz = RotacaoEsquerdaSimples(desbalanceado);
                    }
                    MinhaArvoreDeBuscaBinaria<T>::alturaArvore(ArvoreDeBuscaBinaria<T>::_raiz);

                }

            }
        }
    }
    
};

#endif