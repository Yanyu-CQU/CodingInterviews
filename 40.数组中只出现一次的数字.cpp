#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
{
	if (data.size() == 0)
	{
		return;
	}
	int temp = data[0];
	for (int i = 1; i < data.size(); ++i)
	{
		temp ^= data[i];
	}
	int firstOne = 0;
	for (; firstOne < 32; ++firstOne)
	{
		if ((temp & (1 << firstOne)) != 0)
		{
			break;
		}
	}

	for (int i = 0; i < data.size(); ++i)
	{
		if ((data[i] & (1 << firstOne)) != 0)
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

int main()
{
	int num = 0;
	vector<int> data;
	while (cin >> num)
	{
		data.push_back(num);
	}
	int num1 = 0, num2 = 0;
	FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	system("pause");
	return 1;
}
