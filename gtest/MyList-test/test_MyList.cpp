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
  int vals2[4]={1,3,4};
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

