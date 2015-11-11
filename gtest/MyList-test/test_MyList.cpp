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

TEST(MyList, DelElem) {
  int vals1[6]={1,2,3,4,5,6};
  CNode *p1 = CreateList(6, vals1);
  int vals2[5]={1,2,4,5,6};
  CNode *p2= CreateList(5, vals2);
  DelElem(&p1, 3);
  EXPECT_EQ(true, compare(p1, p2));
}