#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
void DelElem (CNode **pf, int n);
bool compare(CNode *pf1, CNode *pf2);
int size(CNode *pf);
void sort(CNode **pf);

class List {
private:
   void DelFreeNode(int i);
   void AddNewNode(int i, int j);
public:
	double *data;
	int *index;
	int prev;
	int curr;
	List(int n);
	~List();
	void Movenext();
	void print();
	void Add(double l);
	void Del();
	void DelElem2(int n);
};

#endif  // GTEST_MYLIST_MYLIST_H
