#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H

typedef struct Elemento
{
	int _chave;
	void* _dado;
} Elemento;

class AbstractSort
{
	protected : 
		unsigned int _swapsCount;
	
	public :
		AbstractSort()
		{
			this->_swapsCount = 0;
		}

		virtual ~AbstractSort()
		{

		}

		unsigned int getSwapsCount()
		{
			return this->_swapsCount;
		}

		void swap(int indiceDeUmElemento, int indiceDeOutroElemento, Elemento** umVetor){
    		this->_swapsCount++;
    		Elemento* tmp = umVetor[indiceDeUmElemento];
    		umVetor[indiceDeUmElemento] = umVetor[indiceDeOutroElemento];
    		umVetor[indiceDeOutroElemento] = tmp;
		}

		virtual void sort(Elemento** elementos, int qtd) = 0;
};

#endif /* ABSTRACTSORT_H */
