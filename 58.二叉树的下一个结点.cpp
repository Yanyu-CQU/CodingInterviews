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

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}
	if (pNode->right != nullptr) //如果有右子树，取右子树中最下面的左结点
	{
		TreeLinkNode *node = pNode->right;
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
	else//没有右子树，有父结点，一直向上遍历，直到有一个结点，是他父结点的左孩子
	{	//有可能出现，根节点只有左子树，所以既没有父结点，也没有右子树
		//还有可能，结点是最右边一个节点，虽然有父结点，但是所有祖先没有一个满足条件，直到找到根节点，返回null
		if (pNode->next == nullptr)
		{
			return nullptr;
		}
		if (pNode->next->left == pNode)
		{
			return pNode->next;
		}
		else
		{
			TreeLinkNode *node = pNode->next;
			if (node->next == nullptr)
			{
				return nullptr;
			}
			while (node->next->left != node)
			{
				node = node->next;
				if (node == nullptr || node->next == nullptr)
				{
					return nullptr;
				}
			}
			return node->next;
		}
	}
}
int main()
{
	TreeLinkNode *root = new TreeLinkNode(8);
	root->right = new TreeLinkNode(10);
	root->right->left = new TreeLinkNode(9);
	root->right->right = new TreeLinkNode(11);
	root->left = new TreeLinkNode(6);
	root->left->left = new TreeLinkNode(5);
	root->left->right = new TreeLinkNode(7);
	cout << GetNext(root)->val << endl;
	system("pause");
	return 1;
}
