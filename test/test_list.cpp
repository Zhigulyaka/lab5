#include "List.h"
#include <../gtest/gtest.h>


TEST(ListElem, can_create_element)
{
	ASSERT_NO_THROW(ListElem<int> e(5));
}

TEST(ListElem, can_get_element_data)
{
	ListElem<int> e(5);
	EXPECT_EQ(e.GetData(), 5);
}

TEST(ListElem, can_set_element_data)
{
	ListElem<int> e(5);
	ASSERT_NO_THROW(e.SetData(6));
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l());
}

TEST(List, can_create_copied_list)
{
	List<int> l;
	int k = 7;
	int m = 5;
	l.InsFirst(k);
	l.InsLast(m);
	ASSERT_NO_THROW(List<int>e(l));
}

TEST(List, can_insert_first_element)
{

	List<int> l;
	ASSERT_NO_THROW(l.InsFirst(7));
}

TEST(List, can_insert_last_element)
{

	List<int> l;
	ASSERT_NO_THROW(l.InsLast(7));
}

TEST(List, can_insert_middle_element)
{

	List<int> l;
    int k=7;
	int m = 5;
	l.InsLast(m);
	ASSERT_NO_THROW(l.Ins(l.GetMiddle(m),k));
}

TEST(List, can_get_first_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	l.InsFirst(k);
	l.InsLast(m);
	EXPECT_EQ(7, l.GetFirst()->GetData());
}

TEST(List, can_get_last_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	l.InsFirst(k);
	l.InsLast(m);
	EXPECT_EQ(5, l.GetLast()->GetData());
}

TEST(List, can_get_middle_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	EXPECT_EQ(3, l.GetMiddle(n)->GetData());
}

TEST(List, cant_get_element_from_empty_list)
{
	List<int> l;
	ASSERT_ANY_THROW(l.GetLast());
}

TEST(List, can_delete_first_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l.DelFirst());
}

TEST(List, can_delete_last_element)
{
	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l.DelLast());
}

TEST(List, can_delete_middle_element)
{
	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l.Del(l.GetMiddle(m)));
}

TEST(List, cant_delete_element_from_empty_list)
{
	List<int> l;
	ASSERT_ANY_THROW(l.DelLast());
}

TEST(List, can_assign_list_to_itself)
{
	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l = l);
}

TEST(List, can_assign_list_to_other_with_equal_size)
{
	List<int> l1;
	List<int> l2;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l2.InsFirst(n);
	l2.InsLast(m);
	ASSERT_NO_THROW(l1 = l2);

}

TEST(List, can_assign_list_to_other_with_non_equal_size)
{
	List<int> l1;
	List<int> l2;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l2.InsFirst(n);
	l2.InsLast(m);
	ASSERT_NO_THROW(l1 = l2);

}
