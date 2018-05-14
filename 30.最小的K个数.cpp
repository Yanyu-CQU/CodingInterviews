#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
//使用红黑树维持一个K大小的排序空间，将原数据一个一个往里面加
//复杂度O(nlogk),不会改变原数组顺序
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> result;
	if (input.size() == 0 || k > input.size())
	{
		return result;
	}
	multiset<int, greater<int>> kFront;
	for (int i = 0; i < input.size(); ++i)
	{
		if (kFront.size() < k)
		{
			kFront.insert(input[i]);
		}
		else
		{
			if (input[i] < *kFront.begin())
			{
				kFront.erase(kFront.begin());
				kFront.insert(input[i]);
			}
		}
	}
	int index = 0;
	for (auto it = kFront.cbegin(); it != kFront.cend(); it++)
	{
		result.push_back(*it);
	}
	return result;
}
int main()
{
	vector<int> num;// = {1,2,3,2,2,2,5,4,2};
	int temp = 0;
	while (cin >> temp)
	{
		num.push_back(temp);
	}
	vector<int> result = GetLeastNumbers_Solution(num, 5);
	system("pause");
	return 0;
}
