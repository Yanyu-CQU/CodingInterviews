#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool isOverHalf(vector<int> & numbers, int num)
{
	int count = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == num)
		{
			count++;
		}
	}
	if (count * 2 > numbers.size())
	{
		return true;
	}
	return false;
}

/*int partition(vector<int> & data, int start, int end)
{
	if (data.size() == 0 || start < 0 || end < start || end >= data.size())
	{
		throw exception();
	}
	int small = start - 1;
	for (int index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				int temp = data[small];
				data[small] = data[index];
				data[index] = temp;
			}
		}
	}
	++small;
	int temp = data[small];
	data[small] = data[end];
	data[end] = temp;

	return small;
}

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.size() == 0)
	{
		return 0;
	}
	int mid = (numbers.size() - 1) / 2;
	int start = 0, end = numbers.size() - 1;
	int index = partition(numbers, start, end);
	while (index != mid)
	{
		if (index > mid)
		{
			end = index - 1;
			index = partition(numbers, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(numbers, start, end);
		}
	}
	int result = numbers[mid];
	if (isOverHalf(numbers, result))
	{
		return result;
	}
	return 0;
}*/
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		return 0;
	}
	int num = numbers[0];
	int count = 1;
	for (int i = 1; i < numbers.size(); ++i)
	{
		if (numbers[i] != num)
		{
			count--;
			if (count == 0)
			{
				num = numbers[i];
				count = 1;
			}
		}
		else
		{
			count++;
		}
	}
	if (isOverHalf(numbers, num))
	{
		return num;
	}
	return 0;
}
int main()
{
	vector<int> num;// = {1,2,3,2,2,2,5,4,2};
	int temp = 0;
	while (cin >> temp)
	{
		num.push_back(temp);
	}
	cout << MoreThanHalfNum_Solution(num) << endl;
	system("pause");
	return 0;
}
