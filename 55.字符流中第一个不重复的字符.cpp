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

class Solution
{
	int a[256], index;
public:
	Solution(){
		index = 0;
		memset(a, -1, sizeof a);
	}
	void Insert(char ch){
		if (a[ch] == -1)
		{
			a[ch] = index++;
		}
		else
		{
			a[ch] = -2;
		}
	}
	char FirstAppearingOnce(){
		char res = '#', minIndex = index;
		for (int i = 0; i < 256; ++i)
		{
			if (a[i] >= 0 && a[i] < minIndex)
			{
				res = (char)i;
				minIndex = a[i];
			}
		}
		return res;
	}
};
int main()
{
	char c = 0;
	Solution s;
	while (cin >> c)
	{
		s.Insert(c);
	}
	cout << s.FirstAppearingOnce();
	system("pause");
	return 1;
}

