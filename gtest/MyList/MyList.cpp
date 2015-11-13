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