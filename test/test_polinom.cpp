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
	//cout<<list.GetCurrData(1)<<endl;
	//cout<<list.GetCurrData(2)<<endl;
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
TEST(List, can_delete_element)
{
	List<int> list;
	list.Push(3);
	list.Push(10);
	list.Push(2);
	list.Push(6);
	list.DeleteCurr();
	cout<<list.GetCurrData(0)<<endl;
	cout<<list.GetCurrData(1)<<endl;
	cout<<list.GetCurrData(2)<<endl;
	EXPECT_EQ(0,list.GetLength());
}

