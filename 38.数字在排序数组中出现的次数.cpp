#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;



int getFirstK(const vector<int> & data ,int k)
{
	if (data.size() == 0)
	{
		return 0;
	}
	int left = 0, right = data.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (data[mid] == k)
		{
			if (mid == 0 || (mid > 0 && data[mid - 1] != k))
			{
				right = mid;
				break;
			}
			else
			{
				right = mid - 1;
			}
		}
		else if (data[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (data[mid] == k)
		return mid;
	else
		return -1;
}

int getLastK(const vector<int> & data ,int k)
{
	if (data.size() == 0)
	{
		return 0;
	}
	int left = 0, right = data.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (data[mid] == k)
		{
			if (mid == data.size() - 1 || (mid < data.size() - 1 && data[mid + 1] != k))
			{
				right = mid;
				break;
			}
			else
			{
				//right = mid - 1;
				left = mid + 1;
			}
		}
		else if (data[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (data[mid] == k)
		return mid;
	else
		return -1;
}

int GetNumberOfK(vector<int> data ,int k)
{
	if (data.size() == 0)
	{
		return 0;
	}
	int start = getFirstK(data, k);
	int end = getLastK(data, k);
	if (start != -1 && end != -1)
	{
		return end - start + 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int num = 0, key = 0;
	cin >> key;
	vector<int> data;
	while (cin >> num)
	{
		data.push_back(num);
	}
	cout << GetNumberOfK(data, key) << endl;
	system("pause");
	return 1;
}
