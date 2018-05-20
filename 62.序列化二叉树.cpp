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
#include <stack>
#include <memory.h>
#include <memory>
#include <string.h>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    string sHelper(TreeNode *node)
    {
        if (node == NULL)
            return "N";
		stringstream ss;
		ss << node->val;
		string str;
		ss >> str;
        return str + "," +sHelper(node->left) + "," + sHelper(node->right);
    }
 
    char* Serialize(TreeNode *root)
    {
        string s = sHelper(root);
        char *ret = new char[s.length() + 1];
        strcpy(ret, const_cast<char*>(s.c_str()));
        return ret;
    }
 
 
    TreeNode *dHelper(stringstream &ss)
    {
        string str;
        getline(ss, str, ',');
        if (str == "N")
            return NULL;
        else
        {
            TreeNode *node = new TreeNode(stoi(str));
            node->left = dHelper(ss);
            node->right = dHelper(ss);
            return node;
        }
    }
 
    TreeNode* Deserialize(const char *str) {
        stringstream ss(str);
        return dHelper(ss);
    }
};
int main()
{
	TreeNode *root = new TreeNode(8);
	root->right = new TreeNode(10);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);
	root->left = new TreeNode(6);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);
	Solution s;
	string str = s.Serialize(root);
	cout << str;
	
	TreeNode *newRoot = s.Deserialize(str.c_str());
	system("pause");
	return 1;
}
