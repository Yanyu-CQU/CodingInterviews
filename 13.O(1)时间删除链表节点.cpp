#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

void delNode(ListNode* head, ListNode* delNode)
{
	if (head == nullptr)
	{
		return;
	}
	else if (delNode == head)
	{
		delete delNode;
		head = nullptr; 
	}
	if (delNode->next != nullptr)
	{
		delNode->val = delNode->next->val;
		ListNode* node = delNode->next;
		delNode->next = delNode->next->next;
		delete node;
	}
	else
	{
		delNode = head;
		while (delNode->next->next != nullptr)
		{
			delNode = delNode->next;
		}
		ListNode* node = delNode->next;
		delNode->next = nullptr;
		delete node;
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
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << endl;
	delNode(head, head->next);
	temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
