#include <iostream>
#include <vector>
using namespace std;
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<int>::const_iterator pos;
TreeNode* construct(pos startPre, pos endPre, pos startVin, pos endVin)
{
	int rootVal = *startPre;
	TreeNode* root = new TreeNode(rootVal);
	root->left = root->right = nullptr;
	if (startPre == endPre && startVin == endVin)
	{
		return root;
	}
	pos rootVin = startVin;
	while (*rootVin != root->val)
	{
		rootVin++;
	}
	pos leftEnd = startPre + (rootVin - startVin);
	if (rootVin - startVin > 0)
	{
		root->left = construct(startPre + 1, leftEnd, startVin, rootVin - 1);
	}
	if (rootVin - startVin < endVin - startVin)
	{
		root->right = construct(leftEnd + 1, endPre, rootVin + 1, endVin);
	}
	return root;
}
TreeNode* reConstructBinaryTree(const vector<int>& pre, const vector<int>& vin)
{
	if (pre.size() == 0 || vin.size() == 0)
	{
		return nullptr;
	}
	return construct(pre.begin(), pre.end() - 1, vin.begin(), vin.end() - 1);
}

void preView(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->val << "\t";
	preView(node->left);
	preView(node->right);
}

void vinView(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	vinView(node->left);
	cout << node->val << "\t";
	vinView(node->right);
}
int main()
{
	vector<int> pre, vin;
	int num = 0, count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> num;
		pre.push_back(num);
	}
	for (int i = 0; i < count; ++i)
	{
		cin >> num;
		vin.push_back(num);
	}
	TreeNode* root = reConstructBinaryTree(pre, vin);
	preView(root);
	cout << "\n";
	vinView(root);
	system("pause");
	return 0;
}
