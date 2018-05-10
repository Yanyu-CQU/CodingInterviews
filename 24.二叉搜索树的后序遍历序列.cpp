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


bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.size() == 1)
	{
		return true;
	}
	int root = sequence[sequence.size() - 1];
	int i = 0; 
	for (; i < sequence.size() - 1; ++i)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}
	int j = i;
	for (; j < sequence.size() - 1; ++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	bool left = true;
	if (i > 0)// exist left child tree
	{
		left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + i));
	}
	bool right = true;
	if (i < sequence.size() - 1)
	{
		right = VerifySquenceOfBST(vector<int>(sequence.begin() + i, sequence.end() - 1));
	}
	return left && right;
}


int main()
{
	int num = 0;
	vector<int> seq;
	while (cin >> num)
	{
		seq.push_back(num);
	}
	cout << VerifySquenceOfBST(seq) << endl;
	system("pause");
	return 0;
}
