#include "CNode.h"
#include "MyList.h"

CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

void DelElem (CNode **pf, int n) {
	if (pf == NULL)
		return;
	CNode *tmp = *pf;

	if (tmp->val == n) {
		CNode *t = *pf;
		tmp = tmp->next;
		*pf = tmp;
		delete t;
		return;
	}
	CNode *t = 0;
	while ((tmp != 0) && (tmp->next->val != n))
		tmp = tmp->next;
		t = tmp->next;
		tmp->next = t->next;
		delete t;
}

//Функции, которые нужны для теста
int size(CNode *pf) {
  int Size = 0;
  while (pf != 0) {
    pf = pf->next;
    Size++;
  }
  return Size;
}

bool compare(CNode *pf1, CNode *pf2) {
  if (size(pf1) != size(pf2))
    return false;
  else
    while (pf1 != 0 && pf2 != 0) {
      if ((pf1->val) != (pf2->val))
        return false;
      pf1 = pf1->next;
      pf2 = pf2->next;
    }
  return true;
}

void sort(CNode **pf) {
  if (*pf == 0) {
    throw std::exception("Empty node");
  }

  if ((*pf)->next == 0) {
    return;
  }

  if ((*pf)->next->next == 0) {
    if ((*pf)->val > (*pf)->next->val) {
      CNode *tmp = (*pf)->next;
      (*pf)->next->next = (*pf);
      (*pf)->next = 0;
      (*pf) = tmp;
    }
    return;
  }

  CNode *tmp;
  int f = 0;
  while (f == 0) {
    f = 1;
    tmp = (*pf);
    if (tmp->val > tmp->next->val) {
      f = 0;
      CNode *tmp2 = (*pf)->next;
      CNode *tmp3 = (*pf)->next->next;
      (*pf)->next->next = (*pf);
      (*pf)->next = tmp3;
	  (*pf) = tmp2;
    }

    while (tmp->next->next != 0) {
      if (tmp->next->val > tmp->next->next->val) {
        CNode *tmp1, *tmp2, *tmp3;
          f = 0;
          tmp1 = tmp->next;
          tmp2 = tmp->next->next;
          tmp3 = tmp->next->next->next;
          tmp2->next = tmp1;
          tmp1->next = tmp3;
          tmp->next = tmp2;
       }
       tmp = tmp->next;
    }
  }
}

List::List(int n) {
  if (n <= 0)
    throw std::exception("Wrong size");
  data = new double[n + 2];
  index = new int[n + 2];
  curr = 0;
  index[0] = 0;
  for (int i = 1; i < n + 1; i++)
    index[i] = i + 1;
  index[n + 1] = 1;
}

List::~List() {
	delete[]data;
	delete[]index;
}

void List::Movenext() {
	curr = index[curr];
}

void List::print() {
	int i = index[0];
	while (i != 0) {
		cout<<data[i]<<endl;
		i = index[i];
	}
}

void List::DelFreeNode(int i) {
  int tmp = index[i];
  index[i] = index[tmp];
  index[tmp] = -1;
}

void List::AddNewNode(int i, int j) {
  int tmp = index[i];
  index[i] = j;
  index[j] = tmp;
}

void List::Add(double l) {
  if (index[1] == 1)
    throw std::exception("Full List");
  int tmp = index[1]; 
  this->DelFreeNode(1);
  this->AddNewNode(curr, tmp);
  data[tmp] = l;
}

void List::Del() {
  if (index[0] == 0)
    throw std::exception("No elements in list");
  if (index[curr] == 0)
    this->Movenext();
  int tmp = index[curr]; 
  this->DelFreeNode(curr);
  this->AddNewNode(1, tmp);
}

void List::DelElem2(int n) {
	if (index[0] == 0)
		throw std::exception("No elements in list");
	int i = index[0];
	if (data[i] == n) {
		this->DelFreeNode(0);
		this->AddNewNode(1, i);
		return;
	}

	while (i != 0 && data[index[i]] != n) {
		if(index[i] == 0)
			throw std::exception("Element is absent");
		i = index[i];
	}
	int tmp = index[i];
	this->DelFreeNode(i);
	this->AddNewNode(1, tmp);
}