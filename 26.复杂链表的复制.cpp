#include <iostream>
using namespace std;
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {
	}
};

void copyAtNext(RandomListNode* pHead)
{
	RandomListNode* node = pHead;
	RandomListNode* copyNode = nullptr;
	RandomListNode* temp = nullptr;
	while (node != nullptr)
	{
		temp = node->next;
		copyNode = new RandomListNode(node->label);
		node->next = copyNode;
		copyNode->next = temp;
		node = copyNode->next;
	}
}
void connect(RandomListNode* pHead)
{
	RandomListNode* node = pHead;
	while (node != nullptr)
	{
		if (node->random != nullptr)
		{
			node->next->random = node->random->next;
		}
		node = node->next->next;
	}
}
void reConnect(RandomListNode* pHead)
{
	RandomListNode* node = pHead;
	RandomListNode* pClone = node->next;
	RandomListNode* temp = nullptr;
	while (node != nullptr)
	{
		node->next = pClone->next;
		if (pClone->next != nullptr)
		{
			pClone->next = pClone->next->next;
		}
		node = node->next;
		pClone = pClone->next;
	}
}
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	copyAtNext(pHead);
	connect(pHead);
	RandomListNode* pNewNode = pHead->next;
	reConnect(pHead);
	return pNewNode;
}

int main()
{
	RandomListNode* head = new RandomListNode(1);
	RandomListNode* temp = head;;
	for (int i = 2; i <= 5; ++i)
	{
		temp->next = new RandomListNode(i);
		temp = temp->next;
	}
	head->random = head->next->next;
	head->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next;
	RandomListNode* newHead = Clone(head);
	system("pause");
	return 0;
}
