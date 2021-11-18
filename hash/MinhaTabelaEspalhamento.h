#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente

#include <string>
#include <cstring>
#include <math.h>
template<typename T, std::size_t _capacidade>
class MinhaTabelaEspalhamento : public TabelaEspalhamentoAbstrata<T, _capacidade>
{
//implemente aqui
public:
    
    MinhaTabelaEspalhamento() {};
    ~MinhaTabelaEspalhamento() {};

    std::size_t capacidade() const
    {
        return _capacidade;
    }

    std::size_t quantidade() const
    {
        
        int i = 0;
        int tamanho = _capacidade;
        int quantidade = 0;

        while (tamanho != 0)
        {
            quantidade += this->_tabela[i].getTamanho();
            i++;
            tamanho--;
        }

        return quantidade;
    }

    std::size_t espalhamento(std::string dado) const
    {
        int tamanho = dado.length();
        int _dado = 0;
        int m = 0;
        char c_dado [tamanho + 1];

        strcpy(c_dado, dado.c_str());

        for(int i = 0; i < (tamanho + 1); i++)
        {
            m = tamanho - (i + 1);
            _dado += int(c_dado[i]) * pow(31, m);
        }
        return std::size_t(_dado);
    }

    std::size_t funcaoEspalhamento(T dado) const
    {
        return espalhamento(dado) % _capacidade;
    }
    
    template <class U>
    std::size_t espalhamento(U dado) const 
    {
        return (std::size_t) dado;
    }

    void inserir(T dado)
    {
        std::size_t chave = funcaoEspalhamento(dado);

        bool _contem = false;
        _contem = this->_tabela[chave].contem(dado);

        if(!_contem)
        {
            this->_tabela[chave].adicionaNoFim(dado);
        }
    }

    bool contem(T dado) const
    {
        std::size_t chave = funcaoEspalhamento(dado);
        bool _contem = false;
        _contem = this->_tabela[chave].contem(dado);
        return _contem;
    }

    void remover(T dado)
    {
        std::size_t chave = funcaoEspalhamento(dado);

        std::size_t posicao = 0;
        bool _contem = false;

        _contem = this->_tabela[chave].contem(dado);

        if(_contem == true)
        {
            posicao = this->_tabela[chave].posicao(dado);
            this->_tabela[chave].retiraDaPosicao(posicao);
        }else
        {
            throw(ExcecaoDadoInexistente());
        }
    }
};

#endif
