#include "gtest/gtest.h"
#include "HeapSort.h"
#include <mutex>

//std::mutex g_singleThread;

TEST(HeapSortTest,MelhorCaso){
	Elemento e0, e1, e2;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;

  HeapSort sorter;
  Elemento** vetor = new Elemento*[3];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  sorter.construirHeapMax(vetor,3);
  sorter.sort(vetor, 3);
  ASSERT_EQ(sorter.getSwapsCount(),4);
  
  delete[] vetor;
}

TEST(HeapSortTest,PiorCaso){
	Elemento e0, e1, e2, e3, e4;
  e0._chave = 5;
  e1._chave = 4;
  e2._chave = 3;
  e3._chave = 1;
  e4._chave = 2;

  HeapSort sorter;
  Elemento** vetor = new Elemento*[5];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  
  
  sorter.sort(vetor, 5);
  ASSERT_EQ(sorter.getSwapsCount(),7);
  
  delete[] vetor;
}

TEST(HeapSortTest,CasoMedio){
	Elemento e0, e1, e2, e3, e4, e5;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;
  e3._chave = 5;
  e4._chave = 3;
  e5._chave = 4;

  HeapSort sorter;
  Elemento** vetor = new Elemento*[6];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  vetor[5] = &e5;
  
  sorter.construirHeapMax(vetor,6);
  sorter.sort(vetor, 6);
  ASSERT_EQ(sorter.getSwapsCount(),14);
  
  delete[] vetor;
}

TEST(HeapSortTest,TesteLimites){
	Elemento e0, e1, e2, e3, e4, e5;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;
  e3._chave = 5;
  e4._chave = 3;
  e5._chave = 4;

  HeapSort sorter;
  Elemento** vetor = new Elemento*[6];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  vetor[5] = &e5;
  sorter.construirHeapMax(vetor,6);

  EXPECT_THROW(sorter.max_heapify(vetor,5,5),posicao_invalida_exception);
  EXPECT_THROW(sorter.max_heapify(vetor,5,6),posicao_invalida_exception);
  EXPECT_THROW(sorter.max_heapify(vetor,5,-1),posicao_invalida_exception);
  
  delete[] vetor;
} 

TEST(HeapSortTest,testeTroca){
	Elemento e0, e1, e2, e3, e4, e5,e6,e7,e8,e9;
  e0._chave = -1;
  e1._chave = 12;
  e2._chave = 11;
  e3._chave = 10;
  e4._chave = 1;
  e5._chave = 2;
  e6._chave = 9;
  e7._chave = 8;
  e8._chave = 7;
  e9._chave = 6;

  HeapSort sorter;
  Elemento** vetor = new Elemento*[10];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  vetor[5] = &e5;
  vetor[6] = &e6;
  vetor[7] = &e7;
  vetor[8] = &e8;
  vetor[9] = &e9;
  
  sorter.max_heapify(vetor,10,0);
  ASSERT_EQ(vetor[7]->_chave,-1);
  ASSERT_EQ(sorter.getSwapsCount(),3);
  
  delete[] vetor;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}