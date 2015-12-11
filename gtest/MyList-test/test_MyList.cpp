#include "MyList.h"
#include <gtest.h>

TEST(MyList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(MyList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}

TEST(MyList, can_delete_element_in_list) {
  int vals1[5]={1,2,3,4,5};
  CNode *p1 = CreateList(5, vals1);
  int vals2[4]={1,3,4,5};
  CNode *p2= CreateList(4, vals2);
  DelElem(&p1, 2);
  EXPECT_EQ(true, compare(p1, p2));
}

TEST(MyList, can_delete_first_element_in_list) {
  int vals1[5]={1,2,3,4,5};
  CNode *p1 = CreateList(5, vals1);
  int vals2[4]={2,3,4,5};
  CNode *p2= CreateList(4, vals2);
  DelElem(&p1, 1);
  EXPECT_EQ(true, compare(p1, p2));
}

TEST(MyList, can_delete_last_element_in_list) {
  int vals1[5]={1,2,3,4,5};
  CNode *p1 = CreateList(5, vals1);
  int vals2[4]={1,2,3,4};
  CNode *p2= CreateList(4, vals2);
  DelElem(&p1, 5);
  EXPECT_EQ(true, compare(p1, p2));
}

TEST(MyList, can_delete_several_elements_in_list) {
  int vals1[5]={1,2,3,4,5};
  CNode *p1 = CreateList(5, vals1);
  int vals2[3]={1,3,4};
  CNode *p2= CreateList(3, vals2);
  DelElem(&p1, 2);
  DelElem(&p1, 5);
  EXPECT_EQ(true, compare(p1, p2));
}


 TEST(MyList, can_delete_negative_element_in_list) {
  int vals1[5]={-1,-2,-3,-4,-5};
  CNode *p1 = CreateList(5, vals1);
  int vals2[4]={-1,-3,-4,-5};
  CNode *p2= CreateList(4, vals2);
  DelElem(&p1, -2);
  EXPECT_EQ(true, compare(p1, p2));
}

 TEST(MyList_sort, sort_node_with_0_elements) {
  CNode* head = 0;
  ASSERT_ANY_THROW(sort(&head));
}

TEST(MyList_sort, sort_node_with_1_elements) {
  int vals[1] = {5};
  CNode *head = CreateList(1, vals);
  int vals1[1] = {5};
  CNode *head1 = CreateList(1, vals1);
  sort(&head);
  EXPECT_EQ(true, compare(head, head1));
}

TEST(MyList_sort, can_sort_node_with_2_elements) {
  int vals[2] = {10, 5};
  CNode *head = CreateList(2, vals);
  int vals1[2] = {5, 10 };
  CNode *head1 = CreateList(2, vals1);
  sort(&head);
  EXPECT_EQ(true, compare(head, head1));
}

TEST(MyList_sort, can_sort_node_with_3_elements) {
  int vals[3] = {8, 5, 3};
  CNode *head = CreateList(3, vals);
  int vals1[3] = {3, 5, 8 };
  CNode *head1 = CreateList(3, vals1);
  sort(&head);
  EXPECT_EQ(true, compare(head, head1));
}

 TEST(MyList_sort, sort_node_with_5_elements) {
  int vals[5] = {3, 10, 1, 7, 16};
  CNode *head = CreateList(5, vals);
  int vals1[5] = {1, 3, 7, 10, 16};
  CNode *head1 = CreateList(5, vals1);
  sort(&head);
  EXPECT_EQ(true, compare(head, head1));
}

 TEST(MyList_sort, sort_node_with_equal_elements) {
  int vals[5] = {2, 1, 1, 2, 3};
  CNode *head = CreateList(5, vals);
  int vals1[5] = {1, 1, 2, 2, 3};
  CNode *head1 = CreateList(5, vals1);
  sort(&head);
  EXPECT_EQ(true, compare(head, head1));
}

 //
 TEST(MyList, Can_create_list_with_positive_size) {
  ASSERT_NO_THROW(List l(10));
}

TEST(MyList, Cant_create_list_with_negative_size) {
  ASSERT_ANY_THROW(List l(-10));
}

TEST(MyList, Can_add_element) {
  List l(1);
  l.Add(10);
  l.Movenext();
  EXPECT_EQ(10, l.data[l.current]);
}

TEST(MyList, Cant_add_element_to_full_list) {
  List l(1);
  l.Add(10);
  l.Movenext();
  ASSERT_ANY_THROW(l.Add(9));
}

TEST(MyList, Cant_delete_element_from_empty_list) {
  List l(1);
  ASSERT_ANY_THROW(l.Del());
}

TEST(MyList, Can_delete_element_from_list) {
  List l(2);
  l.Add(10);
  l.Movenext();
  l.Add(9);
  l.Movenext();
  l.Movenext();
  l.Movenext();
  l.Del();
  EXPECT_EQ(0, l.index[l.current]);
}

TEST(MyList_2, Can_delete_element_from_list) {
  List l(5);
  l.Add(2);
  l.Movenext();
  l.Add(4);
  l.Movenext();
  l.Add(6);
  l.Movenext();
  l.Add(8);
  l.Movenext();
  l.Add(10);
  l.print();
  l.DelElem2(6);
  cout<<endl;
  l.print();
}

