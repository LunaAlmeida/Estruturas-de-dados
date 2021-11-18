#include "gtest/gtest.h"
#include "Racional.h"


TEST(RacionalTest,Construtor){
    Racional p(10,1);
    ASSERT_EQ(p.getNumerador(),10);
    ASSERT_EQ(p.getDenominador(),1);    
    EXPECT_THROW(Racional(1,0), excecao_denominador_nulo);
}

TEST(RacionalTest,Equal)
{
    Racional r1(4,5), r2(4,5), r3(8,10), r4(3,5);

    ASSERT_EQ(r1==r2, true);
    ASSERT_EQ(r1==r3, false);
    ASSERT_EQ(r1==r4, false);
}


TEST(RacionalTest,Add){
	Racional r1(2,5), r2(3,7);

	Racional r3 = r1 + r2;
	
    ASSERT_EQ(r3.getNumerador(),29);
    ASSERT_EQ(r3.getDenominador(),35);
}

TEST(RacionalTest,Sub){
	Racional r1(2,5), r2(3,7);
	Racional r3 = r1 - r2;
	
    ASSERT_EQ(r3.getNumerador(),1);
    ASSERT_EQ(r3.getDenominador(),-35);
}


TEST(RacionalTest,Mult){
	
	Racional r1(6,7);
	Racional r2(2,4);
	Racional r3 = r1 * r2;
	
    ASSERT_EQ(r3.getNumerador(),3);
    ASSERT_EQ(r3.getDenominador(),7);
}

TEST(RacionalTest,Div){
	
	Racional r1(2,5);
	Racional r2(3,6);
	Racional r3 = r1 / r2;
	
    ASSERT_EQ(r3.getNumerador(),4);
    ASSERT_EQ(r3.getDenominador(),5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}