#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
 };
void tailToHead(ListNode* node, vector<int>& vec)
{
	if (node == NULL)
		return ;
	tailToHead(node->next, vec);
	vec.push_back(node->val);
}
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> list;
	if (head == NULL)
		return list;
	tailToHead(head, list);
	return list;
}

int main()
{
	
	return 0;
}
