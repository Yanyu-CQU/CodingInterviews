#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <memory.h>
#include <memory>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
TreeNode* KthNodeCore(TreeNode* pRoot, int & k)
{
	TreeNode * node = nullptr;
	if (pRoot->left != nullptr)
	{
		node = KthNodeCore(pRoot->left, k);
	}
	if (node == nullptr)
	{
		if (k == 1)
		{
			node = pRoot;
		}
		k--;
	}
	if (node == nullptr && pRoot->right != nullptr)
	{
		node = KthNodeCore(pRoot->right, k);
	}
	return node;
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k < 1)
	{
		return nullptr;
	}
	return KthNodeCore(pRoot, k);
}
int main()
{
	TreeNode *root = new TreeNode(8);
	root->right = new TreeNode(10);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);
	root->left = new TreeNode(6);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);
	cout << KthNode(root, 3)->val << endl;
	system("pause");
	return 1;
}
