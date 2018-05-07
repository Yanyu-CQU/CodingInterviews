#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class MyString
{
private:
	char* pData;
public:
	MyString(char* d)
	{
		if (d == nullptr)
		{
			pData = new char[1];
			pData[0] = '\0';
		}
		else 
		{
			int len = strlen(d) + 1;
			pData = new char[len];
			strcpy(pData, d);
		}
	}
	MyString(const MyString& str)
	{
		if (str.pData == nullptr)
		{
			pData = new char[1];
			pData[0] = '\0';
		}
		else 
		{
			int len = strlen(str.pData) + 1;
			pData = new char[len];
			strcpy(pData, str.pData);
		}
	}
	MyString& operator=(const MyString& str)
	{
		if (this == &str)
			return *this;
		MyString temp(str); 
		char* pTemp = temp.pData;
		temp.pData = pData;
		pData = pTemp;
		return *this;
	}
	~MyString()
	{
		delete[] pData;
	}
	void show()
	{
		printf("%s\n", pData);
	}
};

int main()
{
	MyString str1("str1"), str2("str2"), str3("str3");
	str1.show();
	str1 = str2 = str3;
	str1.show();
	str2.show();
	str1 = str1;
	str1.show();
	return 0;
}
