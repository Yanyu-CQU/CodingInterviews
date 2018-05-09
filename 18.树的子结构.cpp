#include <iostream>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool isTreeSame(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
	{
		return true;
	}
	else if (pRoot1 == nullptr)
	{
		return false;
	}
	else
	{
		bool res = false;
		res = (pRoot1->val == pRoot2->val) && isTreeSame(pRoot1->left, pRoot2->left) && isTreeSame(pRoot1->right, pRoot2->right);
		return res;
	}
}

bool subTreCore(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr || pRoot2 == nullptr)
	{
		return false;
	}
	else
	{
		bool res = false;
		res = isTreeSame(pRoot1, pRoot2);
		if (res == true)
		{
			return res;
		}
		else
		{
			return (subTreCore(pRoot1->left, pRoot2) || subTreCore(pRoot1->right, pRoot2));
		}
	}
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	return subTreCore(pRoot1, pRoot2) || subTreCore(pRoot2, pRoot1);
}

int main()
{
	TreeNode* root1 = new TreeNode(8);	TreeNode* root2 = new TreeNode(8);
	root1->left = new TreeNode(8);		root2->left = new TreeNode(9);
	root1->right = new TreeNode(7);		root2->right = new TreeNode(2);
	root1->left->left = new TreeNode(9);
	root1->left->right = new TreeNode(2);
	bool res = HasSubtree(root1, root2);
	cout << res << endl;
	system("pause");
	return 0;
}
