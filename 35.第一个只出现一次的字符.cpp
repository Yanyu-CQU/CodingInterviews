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

int FirstNotRepeatingChar(string str)
{
	if (str.size() == 0)
	{
		return -1;
	}
	map<char, int> m;
	for (int i = 0; i < str.size(); ++i)
	{
		m[str[i]]++;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (m[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	string str;
	cin >> str;
	cout << FirstNotRepeatingChar(str);
	system("pause");
	return 1;
}
