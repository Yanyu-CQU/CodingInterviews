#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void combine(char* str, int num, vector<vector<char>> & res, vector<char> & comb)
{
	if (num == 0)
	{
		res.push_back(comb);
		return;
	}
	if (*str == '\0')
	{
		return;
	}
	comb.push_back(*str);
	combine(str + 1, num - 1, res, comb);
	comb.pop_back();
	combine(str + 1, num, res, comb);
}

int main()
{
	vector<vector<char> > res;
	vector<char> comb;
	char* str = "abc";
	for (int len = 1; len <= strlen(str); ++len)
	{
		combine(str, len, res, comb);
	}
	
	system("pause");
	return 0;
}
