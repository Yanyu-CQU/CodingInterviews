#include <iostream>
#include <vector>
using namespace std;
//quick sort
//not stable
/*
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	int odd = -1;
	for (int index = 0; index < len; ++index)
	{
		if (array[index] % 2 != 0)
		{
			odd++;
			if (odd != index)
			{
				int temp = array[index];
				array[index] = array[odd];
				array[odd] = temp;
			}
		}
	}
}*/
//bubble sort
//stable
//O(N*N)
/*
void reOrderArray(vector<int> &array)
{
	for (int j = 0; j < array.size() - 1; ++j)
	{
		for (int i =0; i < array.size() - 1 - j; ++i)
		{
			if (array[i] % 2 == 0 && array[i + 1] % 2 != 0)
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}*/
void reOrderArray(vector<int> &array)
{
	vector<int> temp;
	for (int i = 0; i < array.size(); ++i)
	{
		if (array[i] % 2 != 0)
		{
			temp.push_back(temp[i]);
		}
	}
	for (int i = 0; i < array.size(); ++i)
	{
		if (array[i] % 2 == 0)
		{
			temp.push_back(temp[i]);
		}
	}
	array = temp;
}
int main()
{
	int num = 0;
	vector<int> arr;
	while (cin >> num)
	{
		arr.push_back(num);
	}
	reOrderArray(arr);
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
	{
		cout << *it << '\t';
	}
	system("pause");
	return 0;
}
