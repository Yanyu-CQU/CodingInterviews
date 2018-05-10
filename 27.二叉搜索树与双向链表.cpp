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
void convertCore(TreeNode* pRootOfTree, TreeNode* & lastNode)
{
	if (pRootOfTree == nullptr)
	{
		return ;
	}
	TreeNode* node = pRootOfTree;
	if (pRootOfTree->left != nullptr)
	{
		convertCore(pRootOfTree->left, lastNode);
	}
	//中序遍历二叉树就相当于从小到大遍历，每经过一个元素，就将其放到尾节点，然后更新尾节点
	node->left = lastNode;
	if (lastNode != nullptr)//这个判断是防止找到最左边元素时，lastNode还是空指针
	{
		lastNode->right = node;
	}
	lastNode = node;

	if (pRootOfTree->right != nullptr)
	{
		convertCore(pRootOfTree->right, lastNode);
	}
	return;

}
TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* lastNode = nullptr;
	TreeNode* head = nullptr;
	if (pRootOfTree == nullptr)
	{
		return nullptr;
	}
	convertCore(pRootOfTree, lastNode);
	head = lastNode;
	while (head->left != nullptr)
	{
		head = head->left;
	}
	return head;
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

	TreeNode* head = Convert(root1);
	system("pause");
	return 0;
}
