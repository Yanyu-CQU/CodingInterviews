#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void perCore(string & str, int start, vector<string> & res)
{
	if (start == str.size() - 1)
	{
		res.push_back(str);
	}
	else
	{
		for (int i = start; i < str.size(); ++i)
		{
			int temp = str[start];
			str[start] = str[i];
			str[i] = temp;

			perCore(str, start + 1, res);

			temp = str[start];
			str[start] = str[i];
			str[i] = temp;
		}
	}
}
vector<string> Permutation(string str)
{
	vector<string> res;
	perCore(str, 0, res);
	sort(res.begin(), res.end());
	auto it = unique(res.begin(), res.end());
	res.erase(it, res.end());
	return res;
}
int main()
{
	string str = "abc";
	vector<string> res = Permutation(str);
	system("pause");
	return 0;
}
