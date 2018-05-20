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

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
	{
		return false;
	}
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}
	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}
	if (*(pattern + 1) == '*')
	{
		if ((*pattern == '.' && *str != '\0') || *pattern == *str)
		{
			//				0 time					one time 						any times
			return match(str, pattern + 2) || match(str + 1, pattern + 2) || match(str + 1, pattern);
		}
		else
			return match(str, pattern + 2);
	}
	else
	{
		if ((*pattern == '.' && *str != '\0') || *pattern == *str)
		{
			return match(str + 1, pattern + 1);
		}
	}
	return false;
}
int main()
{
	char str[100], pattern[100];
	str[0] = '\0';
	scanf("%s",str);
	scanf("%s",pattern);
	cout << match(str, pattern) << endl;
	system("pause");
	return 1;
}
