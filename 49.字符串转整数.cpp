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

bool StrToInt(string str, int & result)
{
	if (str.size() == 0)
	{
		return false;
	}
	bool isNegative = false;
	int start = 0;
	while (start < str.size() && str[start] == ' ')
	{
		start++;
	}
	if (start < str.size())
	{
		if (str[start] == '-')
		{
			isNegative = true;
			start++;
		}
		else if (str[start] == '+')
		{
			start++;
		}
		else if (str[start] > '9' || str[start] < '0')
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	long long num = 0;
	while (start < str.size())
	{
		if (isdigit(str[start]) == false)
		{
			return false;
		}
		num = num * 10 + str[start] - '0';
		if ((isNegative && num > (long long )0x80000000) || (isNegative != true && num > 0x7FFFFFFF))
		{
			return false;
		}
		start++;
	}
	if (isNegative == true)
	{
		result = -num;
	}
	result = num;
}
int main()
{
	string str;
	int num = 0;
	cin >> str;
	bool flag = StrToInt(str, num);
	cout << num << endl;
	system("pause");
	return 1;
}
