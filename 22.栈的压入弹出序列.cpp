#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//选择题时一个简便俺的判断方法：
//如果入栈序列按照升序排序，那么出栈顺序中，每一个数后面比它小的数，一定按照降序排列
//如果入站序列没有排序，那么把入栈顺序当做值也行
bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
	int index1 = 0, index2 = 0;
	stack<int> st;
	while (index2 < popV.size())
	{
		if (index1 < pushV.size() && popV[index2] == pushV[index1])
		{
			index1++;
			index2++;
		}
		else if (st.size() != 0 && st.top() == popV[index2])
		{
			st.pop();
			index2++;
		}
		else if (index1 < pushV.size())
		{
			st.push(pushV[index1]);
			index1++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int count = 0, num = 0;
	vector<int> push, pop;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> num;
		push.push_back(num);
	}
	for (int i = 0; i < count; ++i)
	{
		cin >> num;
		pop.push_back(num);
	}
	cout << IsPopOrder(push, pop) << endl;
	system("pause");
	return 0;
}
