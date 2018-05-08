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
	cout << endl;
	cout << FindKthToTail(head, 3)->val << endl;
	
	system("pause");
	return 0;
}
