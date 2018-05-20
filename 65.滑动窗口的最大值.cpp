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
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	queue<int> qu;
	if (num.size()  < size || size < 1)
	{
		return result;
	}
	int maxNum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (qu.size() == size)
		{
			qu.pop();
			if (qu.size() != 0 && qu.back() >= qu.front())
			{
				int s = qu.size();
				while (s != 1)
				{
					qu.pop();
					s--;
				}
			}
		}
		if (qu.size() != 0 && num[i] >= qu.front())
		{
			while (qu.size() != 0)
			{
				qu.pop();
			}
		}
		qu.push(num[i]);
	}
	result.push_back(qu.front());

	for (int i = size; i < num.size(); ++i)
	{
		if (qu.size() == size)
		{
			qu.pop();
			if (qu.size() != 0 && qu.back() >= qu.front())
			{
				int s = qu.size();
				while (s != 1)
				{
					qu.pop();
					s--;
				}
			}
		}
		if (qu.size() != 0 && num[i] >= qu.front())
		{
			while (qu.size() != 0)
			{
				qu.pop();
			}
		}
		qu.push(num[i]);
		result.push_back(qu.front());
	}

	return result;
}
int main()
{
	vector<int> data, res;
	int num = 0;
	while (cin >> num)
	{
		data.push_back(num);
	}
	res = maxInWindows(data, 3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	system("pause");
	return 1;
}

