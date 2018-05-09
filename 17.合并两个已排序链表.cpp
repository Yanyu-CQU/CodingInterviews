#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr && pHead2 == nullptr)
	{
		return nullptr;
	}
	else if (pHead1 != nullptr && pHead2 == nullptr)
	{
		return pHead1;
	}
	else if (pHead1 == nullptr && pHead2 != nullptr)
	{
		return pHead2;
	}
	else
	{
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode* pFirst = nullptr;
		while (p1 != nullptr && p2 != nullptr)
		{
			if (p1->val <= p2->val && (p1->next == nullptr || p1->next->val > p2->val))
			{
				if (pFirst == nullptr)
				{
					pFirst = p1;
				}
				ListNode* temp = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p1 = p1->next;
				p2 = temp;
			}
			else if (p1->val >= p2->val)
			{
				if (pFirst == nullptr)
				{
					pFirst = p2;
				}
				ListNode* temp = p2->next;
				p2->next = p1;
				p2 = temp;
			}
			else
			{
				if (pFirst == nullptr)
				{
					pFirst = p1;
				}
				p1 = p1->next;
			}
		}
		return pFirst;
	}
}
int main()
{
	int val = 0;
	ListNode *head1 = nullptr, *head2 = nullptr, *temp = nullptr;
	while (cin >> val)
	{
		if (val == 0)
		{
			break;
		}
		if (head1 == nullptr)
		{
			head1 = new ListNode(val);
			temp = head1;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	while (cin >> val)
	{
		if (head2 == nullptr)
		{
			head2 = new ListNode(val);
			temp = head2;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	cout << endl << "****************************" << endl;

	//head = ReverseList(head);
	ListNode* head = Merge(head1, head2);
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
