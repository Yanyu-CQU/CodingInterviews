#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};
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
