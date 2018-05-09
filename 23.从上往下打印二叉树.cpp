#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root)
{
	vector<int> res;
	queue<TreeNode*> temp;
	if (root == nullptr)
	{
		return res;
	}
	TreeNode* node = root;
	temp.push(node);
	while (temp.empty() != true)
	{
		node = temp.front();
		temp.pop();
		res.push_back(node->val);
		if (node->left != nullptr)
		{
			temp.push(node->left);
		}
		if (node->right != nullptr)
		{
			temp.push(node->right);
		}
	}
	return res;
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	vector<int> res = PrintFromTopToBottom(root);
	system("pause");
	return 0;
}
