#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

void reverse(string & str, int begin, int end)
{
	if (str.size() == 0)
	{
		return;
	}
	char temp = 0;
	while (end > begin)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		end--;
		begin++;
	}
	return;
}
string ReverseSentence(string str)
{

	if (str.size() == 0)
	{
		return str;
	}
	int begin = 0, end = str.size() - 1;
	reverse(str, begin, end);
	begin = end = 0;
	while (begin < str.size() && end <= str.size())
	{
		if (end < str.size() && str[begin] == ' ' && str[end] == ' ')
		{
			begin++;
			end++;
		}
		else if (end == str.size() || str[end] == ' ')
		{
			reverse(str, begin, end - 1);
			begin = end;
		}
		else
		{
			end++;
		}
	}
	return str;
}
string LeftRotateString(string str, int n)
{
	if (str.size() == 0)
	{
		return str;
	}
	reverse(str, 0, n - 1);
	reverse(str, n, str.size() - 1);
	reverse(str, 0, str.size() - 1);
	return str;
}
int main()
{
	int num = 0, sum = 0;
	string str;
	getline(cin, str);
	str = ReverseSentence(str);
	cout << str << endl;
	system("pause");
	return 1;
}
