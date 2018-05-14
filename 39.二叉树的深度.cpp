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

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return 0;
	}
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);

	return max(leftDepth, rightDepth) + 1;
}
int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	cout << TreeDepth(root) << endl;
	system("pause");
	return 1;
}
