#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
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

/*
bool findNode(TreeNode* root, TreeNode* node)
{
	if (root == node && root != nullptr)
	{
		return true;
	}
	else if (root == nullptr || node == nullptr)
	{
		return false;
	}
	return (findNode(root->left, node) || findNode(root->right, node));
}
TreeNode* getLastCommonParent(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
	if (root == nullptr || node1 == nullptr || node2 == nullptr)
	{
		return nullptr;
	}
	if (findNode(root->left, node1))
	{
		if (findNode(root->right, node2))
		{
			return root;
		}
		return getLastCommonParent(root->left, node1, node2);
	}
	else
	{
		if (findNode(root->left, node2))
		{
			return root;
		}
		return getLastCommonParent(root->right, node1, node2);
	}
}*/
bool getPath(TreeNode* root, TreeNode* node, list<TreeNode*> & path)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root == node)
	{
		return true;
	}
	path.push_back(root);
	bool found = false;
	found = getPath(root->left, node, path) || getPath(root->right, node, path);
	if (found == false)
	{
		path.pop_back();
	}
	return found;
}
TreeNode* getLastCommonParent(TreeNode* root, TreeNode* node1, TreeNode* node2) //fast solution
{
	if (root == nullptr || node1 == nullptr || node2 == nullptr)
	{
		return nullptr;
	}
	list<TreeNode*> path1, path2;
	getPath(root, node1, path1);
	getPath(root, node2, path2);
	if (path1.size() == 0 || path2.size() == 0)
	{
		return nullptr;
	}
	auto it1 = path1.rbegin();
	auto it2 = path2.rbegin();
	while (*it1 != *it2)
	{
		it1++;
		it2++;
	}
	return *it1;
}
int main()
{
	TreeNode* root1 = new TreeNode(4);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(6);
	root1->left->left = new TreeNode(1);
	root1->left->right = new TreeNode(3);
	root1->right->left = new TreeNode(5);
	root1->right->right = new TreeNode(7);

	TreeNode* res = getLastCommonParent(root1, root1->left->left, root1->left->right);
	if (res != nullptr)
	{
		cout << res->val << endl;
	}
	system("pause");
	return 1;
}
