#include "gtest/gtest.h"
#include "MinhaPilha.h"

//extern "C" {
//#include "stack.h"
//}

TEST(PilhaTest,Init){
	PilhaAbstrata<int>* p = new MinhaPilha<int>;
	ASSERT_NE(p,nullptr);
	ASSERT_EQ(p->estaVazia(),true);
	delete p;
}

TEST(PilhaTest,PilhaVazia){
	PilhaAbstrata<int>* p = new MinhaPilha<int>;
	int d1 = 10;
	
	ASSERT_EQ(p->estaVazia(),true);
	
	p->push(&d1);
	
	ASSERT_EQ(p->estaVazia(),false);

	delete p;
}

TEST(PilhaTest,Push){
    PilhaAbstrata<int>* p = new MinhaPilha<int>;
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;
	
	p->push(&d1);
	ASSERT_EQ(p->getTamanho(),1);
	ASSERT_EQ(p->contem(&d1),true);
	ASSERT_EQ(p->posicao(&d1),1);
	
	p->push(&d2);
	ASSERT_EQ(p->getTamanho(),2);
	ASSERT_EQ(p->contem(&d2),true);
	ASSERT_EQ(p->posicao(&d2),1);
	ASSERT_EQ(p->posicao(&d1),2);

	p->push(&d3);
	ASSERT_EQ(p->getTamanho(),3);
	ASSERT_EQ(p->contem(&d3),true);
	ASSERT_EQ(p->posicao(&d3),1);
	ASSERT_EQ(p->posicao(&d2),2);
	ASSERT_EQ(p->posicao(&d1),3);
	
	
	delete p;
}

TEST(PilhaTest,Pop){
    PilhaAbstrata<int>* p = new MinhaPilha<int>;
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;
	
	int *r;
	
	p->push(&d3);
	p->push(&d2);
	p->push(&d1);
	
	r = (int*) p->pop();
	ASSERT_EQ(*r, d1);
	ASSERT_EQ(p->getTamanho(),2);
	ASSERT_EQ(p->posicao(&d2),1);
	ASSERT_EQ(p->posicao(&d3),2);
	
	r = (int*) p->pop();
	ASSERT_EQ(*r, d2);
	ASSERT_EQ(p->getTamanho(),1);
	ASSERT_EQ(p->posicao(&d3),1);
	
	r = p->pop();
	ASSERT_EQ(*r, d3);
	ASSERT_EQ(p->getTamanho(),0);
	
	EXPECT_THROW(p->pop(), pilha_vazia_exception);
	
	delete p;
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
