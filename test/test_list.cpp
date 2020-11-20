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
	ASSERT_NO_THROW(List<int> ());
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
/*
TEST(List, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(List<int> m(-5));
}

TEST(List, can_create_copied_matrix)
{
	List<int> m(5);

	ASSERT_NO_THROW(List<int> m1(m));
}

TEST(List, copied_matrix_is_equal_to_source_one)
{
	List<int> m(5);
	List<int> m1(m);
	EXPECT_EQ(m==m1, 1);
}

TEST(List, can_get_size)
{
	List<int> m(5);
	EXPECT_EQ(5,m.Length());
}

TEST(List, can_set_and_get_element)
{
	List<int> m1(5);
    m1[3][2] = 11;
	EXPECT_EQ(m1[3][2], 11);
}

TEST(List, throws_when_set_element_with_negative_index)
{
	List<int> m(4);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(List, throws_when_set_element_with_too_large_index)
{
	List<int> m(4);
	ASSERT_ANY_THROW(m[5]);
}

TEST(List, can_assign_matrix_to_itself)
{
	List<int> m(4);
	ASSERT_NO_THROW(m = m);
}

TEST(List, can_assign_matrices_of_equal_size)
{
	List<int> m1(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
			m1[i][j] = j;
	List<int>m2(5);
	m2 = m1;
	EXPECT_EQ(m1 == m2, 1);

}


TEST(List, can_assign_matrices_of_different_size)
{
	List<int> m1(10);
	List<int> m2(5);
	m2 = m1;
	EXPECT_EQ(m1==m2,1);
	
}

TEST(List, compare_equal_matrices_return_true)
{
	List<int> m1(5);
	List<int>m2(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = j;
			m2[i][j] = j;
		}
	EXPECT_EQ(1, m1==m2);
}

TEST(List, compare_matrix_with_itself_return_true)
{
	List<int> m1(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = j;
		}
	EXPECT_EQ(1, m1==m1);
}

TEST(List, matrices_with_different_size_are_not_equal)
{
	List<int> m1(10);
	List<int> m2(5);
	EXPECT_EQ(m1==m2,0);
}

TEST(List, can_add_matrices_with_equal_size)
{
	List<int> m1(5);
	List<int> m2(5);
	List<int> m3(5);
	List<int> m4(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			m3[i][j] = 3;
		}
	m4 = m1 + m2;
	EXPECT_EQ(1, m4==m3);
}

TEST(List, cant_add_matrices_with_not_equal_size)
{
	List<int> m1(4);
	List<int> m2(8);
	ASSERT_ANY_THROW(m1+m2);
}

*/