#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

void fingPathCore(vector<vector<int> >& allPath, vector<int>& path, TreeNode* root, int expectNumber)
{
	if (root == nullptr)
	{
		return;
	}
	path.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr)
	{
		int sum=accumulate(path.begin(),path.end(),0);
		if (sum == expectNumber)
		{
			allPath.push_back(path);
		}
	}
	fingPathCore(allPath, path, root->left, expectNumber);
	fingPathCore(allPath, path, root->right, expectNumber);
	path.pop_back();
	return;
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
{
	vector<int> path;
	vector<vector<int> > allPath;
	if (root == nullptr)
	{
		return allPath;
	}
	fingPathCore(allPath, path, root, expectNumber);
	return allPath;
}
int main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	vector<vector<int> >res;
	res = FindPath(root, 22);
	system("pause");
	return 0;
}
