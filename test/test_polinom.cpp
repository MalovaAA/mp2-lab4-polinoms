#include <gtest.h>
#include "polinom.h"
#include "monom.h"
#include "list.h"
// тесты мономов и полиномов and list
TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}
TEST(List, can_push)
{
	List<int> list;
	int a = 3;
	list.Push(a);
	cout<<list.GetCurrData(0)<<endl;
	EXPECT_EQ(3,list.GetCurrData(0));
}
TEST(List, can_push_unsort_element)
{
	List<int> list;
	list.Push(10);
	list.Push(5);
	list.Push(6);
	list.Push(1);
	EXPECT_EQ(10,list.GetCurrData(0));
	EXPECT_EQ(6,list.GetCurrData(1));
	EXPECT_EQ(5,list.GetCurrData(2));
	EXPECT_EQ(1,list.GetCurrData(3));
}
TEST(List, can_delete_list)
{
	List<int> list;
	list.Push(10);
	list.Push(5);
	list.Push(6);
	list.DeleteList();
	EXPECT_EQ(0,list.GetLength());
}
TEST(Polinom, can_add_polinoms)
{
	Polinom p1;
	Polinom p2;
	
	Monom m1(2,200);
	Monom m2(9,100);
	p1.Push(Monom(1,100));
	p1.Push(Monom(1,200));
	p2.Push(Monom(8,100));
	p2.Push(Monom(1,200));
	p1+=p2;
	EXPECT_EQ(m1.coef,p1.GetCurrData(0).coef);
	EXPECT_EQ(m1.power,p1.GetCurrData(0).power);
	EXPECT_EQ(m2.coef,p1.GetCurrData(1).coef);
	EXPECT_EQ(m2.power,p1.GetCurrData(1).power);
}
TEST(Polinom, can_subtract_polinoms)
{
	Polinom p1;
	Polinom p2;
	Monom m2(-7,100);
	p1.Push(Monom(1,100));
	p1.Push(Monom(1,200));
	p2.Push(Monom(8,100));
	p2.Push(Monom(1,200));
	p1-=p2;
	EXPECT_EQ(m2.coef,p1.GetCurrData(0).coef);
	EXPECT_EQ(m2.power,p1.GetCurrData(0).power);
}
TEST(Polinom, can_subtract_polinoms2)
{
	Polinom p1;
	Polinom p2;
	Monom m1(-5,200);
	Monom m2(-2,101);
	Monom m3(2,100);
	p1.Push(Monom(6,101));
	p1.Push(Monom(3,100));
	p2.Push(Monom(8,101));
	p2.Push(Monom(1,100));
	p2.Push(Monom(5,200));
	p1-=p2;
	EXPECT_EQ(m1.coef,p1.GetCurrData(0).coef);
	EXPECT_EQ(m1.power,p1.GetCurrData(0).power);
	EXPECT_EQ(m2.coef,p1.GetCurrData(1).coef);
	EXPECT_EQ(m2.power,p1.GetCurrData(1).power);
	EXPECT_EQ(m3.coef,p1.GetCurrData(2).coef);
	EXPECT_EQ(m3.power,p1.GetCurrData(2).power);
}