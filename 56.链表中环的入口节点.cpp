#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <memory.h>
#include <memory>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == nullptr || pHead->next == nullptr || pHead->next->next == nullptr)
	{
		return nullptr;
	}
	bool isCircle = false;
	ListNode *step1 = pHead, *step2 = pHead;
	while (step2 != nullptr && step1 != nullptr)
	{
		step1 = step1->next;
		if (step2->next != nullptr)
		{
			step2 = step2->next->next;
		}
		else
		{
			return nullptr;
		}
		if (step1 == step2)
		{
			isCircle = true;
			break;
		}
	}
	if (isCircle != true)
	{
		return nullptr;
	}
	int crlNodes = 1;
	ListNode *node = step1->next;
	while (step1 != node) // get how mant nodes in circle 
	{
		crlNodes++;
		node = node->next;
	}
	ListNode *behind = pHead, *front = pHead;
	while (crlNodes != 0)
	{
		front = front->next;
		crlNodes--;
	}
	while (front != behind)
	{
		front = front->next;
		behind = behind->next;
	}
	return front;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = head->next;
	cout << EntryNodeOfLoop(head)->val << endl;
	system("pause");
	return 1;
}
