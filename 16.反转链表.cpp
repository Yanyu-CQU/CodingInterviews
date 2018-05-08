#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (pListHead == nullptr)
		return nullptr;
	ListNode* node = pListHead;
	for (int i = 0; i < k - 1; ++i)
	{
		node = node->next;
		if (node == nullptr)
			return nullptr;
	}
	ListNode* kNode = pListHead;
	while (node->next != nullptr)
	{
		kNode = kNode->next;
		node = node->next;
	}
	return kNode;
}
ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	else if (pHead->next == nullptr)
	{
		return pHead;
	}
	else
	{
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		pHead->next = nullptr;
		ListNode* pNext = nullptr;
		ListNode* pReturn = nullptr;
		while (cur != nullptr)
		{
			pNext = cur->next;
			cur->next = pre;
			pre = cur;
			if (pNext == nullptr)
				pReturn = cur;
			cur = pNext;
		}
		return pReturn;
	}
}
int main()
{
	int val = 0;
	ListNode *head = nullptr, *temp = nullptr;
	while (cin >> val)
	{
		if (head == nullptr)
		{
			head = new ListNode(val);
			temp = head;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << '\t';
		temp = temp->next;
	}
	cout << endl << "****************************" << endl;

	head = ReverseList(head);
	temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << '\t';
		temp = temp->next;
	}
	cout << endl;
	
	system("pause");
	return 0;
}
