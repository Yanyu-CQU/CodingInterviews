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
vector<vector<int> > Print(TreeNode* pRoot)
{
	vector<vector<int> > res; 
	vector<int> l;
	if (pRoot == nullptr)
	{
		return res;
	}
	queue<TreeNode*> line, temp;
	line.push(pRoot);
	l.push_back(pRoot->val);
	res.push_back(l);
	while (line.size() != 0)
	{
		l.clear();
		while (line.size() != 0)
		{
			TreeNode *node = line.front();
			if (node->left != nullptr)
			{
				temp.push(node->left);
				l.push_back(node->left->val);
			}
			if (node->right != nullptr)
			{
				temp.push(node->right);
				l.push_back(node->right->val);
			}
			line.pop();
		}
		line = move(temp);
		if (l.size() != 0)
		{
			res.push_back(l);
		}
	}
	return res;
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
	vector<vector<int>> res = Print(root);
	for (auto it = res.cbegin(); it != res.cend(); ++it)
	{
		for (auto c = it->cbegin(); c != it->cend(); ++c)
		{
			cout << *c << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}
