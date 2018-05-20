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
/*
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	list<int> circle;
	for (int i = 0; i < n; ++i)
	{
		circle.push_back(i);
	}
	auto it = circle.begin();
	while (circle.size() > 1)
	{
		int i = 0;
		for (;i < m - 1; ++i)
		{
			++it;
			if (it == circle.end())
			{
				it = circle.begin();
			}
		}
		auto del = it;
		it++;
		if (it == circle.end())
		{
			it = circle.begin();
		}
		circle.erase(del);
	}
	return *circle.begin();
}*/
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	if (n == 1)
	{
		return 0;
	}
	return (LastRemaining_Solution(n - 1, m) + m) % n;
}
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	cout << LastRemaining_Solution(n, m) << endl;
	system("pause");
	return 1;
}
