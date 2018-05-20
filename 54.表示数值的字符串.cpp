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

bool isNumeric(char* string)
{
	if (string == nullptr)
	{
		return false;
	}
	if ((*string == '-' || *string == '+') && *(string + 1) != '\0')
	{
		string++;
	}
	bool hasPoint = false;
	while (*string != '\0')
	{
		if (isdigit(*string) == false)
		{
			if ((*string == 'e' || *string == 'E') && *(string + 1) != '\0')
			{
				string++;
				break;;
			}
			else if (hasPoint == false && *string == '.' && *(string + 1) != '\0')
			{
				hasPoint = true;
				string++;
			}
			else
			{
				return false;
			}
		}
		string++;
	}
	if (*string != '\0')
	{
		if ((*string == '-' || *string == '+') && *(string + 1) != '\0')
		{
			string++;
		}
		while (*string != '\0')
		{
			if (isdigit(*string) == false)
			{
				return false;
			}
			string++;
		}
	}
	return true;
}
int main()
{
	char num[100];
	scanf("%s", num);
	cout << isNumeric(num) << endl;
	system("pause");
	return 1;
}
