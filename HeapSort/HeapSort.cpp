#include "HeapSort.h"
#include "string"

//implemente AQUI as funcoes sort e max_heapify do HeapSort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void HeapSort::sort(Elemento** umVetor, int quantidadeDeElmentos)
{
    construirHeapMax(umVetor, quantidadeDeElmentos);

    while (quantidadeDeElmentos > 1)
    {
        AbstractSort::swap(0, quantidadeDeElmentos - 1, umVetor);
        quantidadeDeElmentos -= 1;
        max_heapify(umVetor, quantidadeDeElmentos, 0);
    }
}

void HeapSort::max_heapify(Elemento ** umVetor, int quantidadeDeElementos, int i)
{
    if (((i >= quantidadeDeElementos) || i < 0) && (i != 0))
        throw(posicao_invalida_exception());

    int left = i * 2 + 1;
    int right = (i * 2) + 2;
    int max = i;

    if ((left < quantidadeDeElementos) && (umVetor[left]->_chave > umVetor[max]->_chave))
    {
        max = left;
    }
    if((right < quantidadeDeElementos) && (umVetor[right]->_chave > umVetor[max]->_chave))
    {
        max = right;
    }

    if(max != i)
    {
        AbstractSort::swap(max, i, umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
    }

}

void HeapSort::construirHeapMax(Elemento ** umVetor, int tamanho)
{
    for (int i = 0; i < (tamanho / 2); i++)
    {
        max_heapify(umVetor, tamanho, i);
    }
}