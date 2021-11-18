#include "gtest/gtest.h"
#include "racional.h"


TEST(RacionalTest,Init){
    Racional* p = init(1,0);
    ASSERT_EQ(p,nullptr);
    destroy(p);
    
    p = init(10,1);
    ASSERT_EQ(p->numerador,10);
    ASSERT_EQ(p->denominador,1);
    destroy(p);
    
}


TEST(RacionalTest,Add){
	Racional* r1, *r2, *r3;
	
	r1 = init(2,5);
	r2 = init(3,7);
	r3 = add(r1, r2);
	
    ASSERT_EQ(r3->numerador,29);
    ASSERT_EQ(r3->denominador,35);
	
	destroy(r1);
	destroy(r2);
	destroy(r3);
}

TEST(RacionalTest,Sub){
	Racional* r1, *r2, *r3;
	
	r1 = init(2,5);
	r2 = init(3,7);
	r3 = subtract(r1, r2);
	
    ASSERT_EQ(r3->numerador,-1);
    ASSERT_EQ(r3->denominador,35);
	
	destroy(r1);
	destroy(r2);
	destroy(r3);
}


TEST(RacionalTest,Mult){
	Racional* r1, *r2, *r3;
	
	r1 = init(6,7);
	r2 = init(2,4);
	r3 = multiply(r1, r2);
	
    ASSERT_EQ(r3->numerador,3);
    ASSERT_EQ(r3->denominador,7);
	
	destroy(r1);
	destroy(r2);
	destroy(r3);
}

TEST(RacionalTest,Div){
	Racional* r1, *r2, *r3;
	
	r1 = init(2,5);
	r2 = init(3,6);
	r3 = divide(r1, r2);
	
    ASSERT_EQ(r3->numerador,4);
    ASSERT_EQ(r3->denominador,5);
	
	destroy(r1);
	destroy(r2);
	destroy(r3);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}