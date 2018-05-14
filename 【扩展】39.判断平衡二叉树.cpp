#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool isBalance(TreeNode* pRoot, int & depth)
{
	if (pRoot == nullptr)
	{
		return true;
	}
	int lDepth = 0, rDepth = 0;
	bool left = isBalance(pRoot->left, lDepth);
	bool right = isBalance(pRoot->right, rDepth);
	depth = max(lDepth, rDepth) + 1;
	if (left && right && (abs(lDepth - rDepth) <= 1))
	{
		return true;
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return true;
	}
	int depth = 0;
	return isBalance(pRoot, depth);
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	cout << IsBalanced_Solution(root);
	system("pause");
	return 1;
}
