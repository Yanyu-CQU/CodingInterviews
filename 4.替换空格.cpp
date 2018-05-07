#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h> 
using namespace std;


void replaceSpace(char *str,int length) {
	vector<int> index;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			index.push_back(i);
		}
	}
	int count = index.size();
	str[length + count * 2] = '\0';
	for (int i = length - 1; i >= 0; --i)
	{
		if (count != 0 && i == index[count - 1])
		{
			count--;
			str[i + count * 2] = str[i];
			str[i + count * 2] = '%';
			str[i + count * 2 + 1] = '2';
			str[i + count * 2 + 2] = '0';
		}
		else
		{
			str[i + count * 2] = str[i];
		}
	}
}
int main()
{
	char str[9999];
	//scanf("%s",str);
	gets(str);
	replaceSpace(str, strlen(str));
	printf("%s",str);
	return 0;
} 
