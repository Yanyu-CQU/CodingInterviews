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

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
bool isSymmetricalCore(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
	{
		return true;
	}
	if (pRoot1 == nullptr || pRoot2 == nullptr)
	{
		return false;
	}
	if (pRoot1->val != pRoot2->val)
	{
		return false;
	}
	return isSymmetricalCore(pRoot1->left, pRoot2->right) && isSymmetricalCore(pRoot1->right, pRoot2->left);
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return true;
	}
	return isSymmetricalCore(pRoot->left, pRoot->right);
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
	cout << isSymmetrical(root) << endl;
	system("pause");
	return 1;
}
