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
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	ListNode *node = pHead, *front = pHead;
	while (node->next != nullptr)
	{
		if (node->val == node->next->val)
		{
			while (node->next != nullptr && node->val == node->next->val)//删除后面所有一样的节点，然后删除自己
			{
				ListNode *del = node->next;
				node->next = del->next;
				delete del;
				del = nullptr;
			}
			if (node != pHead) //该结点不是头
			{
				front->next = node->next;
				delete node;
				node = front;
			}
			else//如果是头部
			{
				if (node->next != nullptr)//后面还有结点
				{
					ListNode *temp = node;
					node = node->next;
					delete temp;
					pHead = node;
				}
				else //后面没有节点，整个链表清空
				{
					pHead = nullptr;
					delete node;
					node = nullptr;
					return nullptr;
				}
			}
		}
		else
		{
			if (front != node)//保持front一直是node的前一个节点
			{
				front = front->next;
			}
			node = node->next;
		}
	}
	return pHead;
}

int main()
{
	int num = 0;
	ListNode *head = nullptr, *temp = nullptr;
	while (cin >> num)
	{
		if (head == nullptr)
		{
			head = new ListNode(num);
			temp = head;
		}
		else
		{
			temp->next = new ListNode(num);
			temp = temp->next;
		}
	}
	ListNode *node = deleteDuplication(head);
	while (node != nullptr)
	{
		cout << node->val << '\t';
		node = node->next;
	}
	system("pause");
	return 1;
}
