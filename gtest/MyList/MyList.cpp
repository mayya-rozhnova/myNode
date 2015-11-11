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
	if (n == 1) {
		CNode *tmp = *pf;
		CNode *t = *pf;
		tmp = tmp->next;
		*pf = tmp;
		delete t;
		return;
	}
	CNode *tmp = *pf;
	CNode *t = 0;
	while (tmp != 0 && tmp->val != (n - 1))
		tmp = tmp->next;
		t = tmp->next;
		tmp->next = t->next;
		delete t;
}

