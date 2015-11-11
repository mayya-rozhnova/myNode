#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
void DelElem (CNode **pf, int n);
bool compare(CNode *pf1, CNode *pf2);
int size(CNode *pf);

#endif  // GTEST_MYLIST_MYLIST_H
