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

void Mirror(TreeNode *pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	else if (pRoot->left == nullptr && pRoot->right == nullptr)
	{
		return;
	}
	else
	{
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
}

int main()
{
	TreeNode* root1 = new TreeNode(8);	TreeNode* root2 = new TreeNode(8);
	root1->left = new TreeNode(8);		root2->left = new TreeNode(9);
	root1->right = new TreeNode(7);		root2->right = new TreeNode(2);
	root1->left->left = new TreeNode(9);
	root1->left->right = new TreeNode(2);
	//bool res = HasSubtree(root1, root2);
	//cout << res << endl;
	Mirror(root1);
	system("pause");
	return 0;
}
