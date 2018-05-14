#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
	{
		return nullptr;
	}
	int len1 = 0, len2 = 0;
	ListNode *node = pHead1;
	while (node != nullptr)
	{
		len1++;
		node = node->next;
	}
	node = pHead2;
	while (node != nullptr)
	{
		len2++;
		node = node->next;
	}
	ListNode *pNode1 = pHead1;
	ListNode *pNode2 = pHead2;
	if (len1 > len2)
	{
		int diff = len1 - len2;
		while (diff != 0)
		{
			pNode1 = pNode1->next;
			diff--;
		}
	}
	else
	{
		int diff = len2 - len1;
		while (diff != 0)
		{
			pNode2 = pNode2->next;
			diff--;
		}
	}

	while (pNode1 != pNode2 && pNode1 != nullptr)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}

int main()
{
	ListNode *p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(3);

	ListNode *p2 = new ListNode(2);
	p2->next = p1->next;
	cout << FindFirstCommonNode(p1, p2)->val << endl;
	system("pause");
	return 1;
}
