#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
	vector<int> res(2);
	if (array.size() < 2)
	{
		vector<int> temp;
		return temp;
	}
	int left = 0, right = array.size() - 1;
	unsigned int multi = 0xFFFFFFFF;
	while (left <= right)
	{
		if (array[left] + array[right] == sum)
		{
			if (array[left] * array[right] < multi)
			{
				multi = array[left] * array[right];
				res[0] = array[left];
				res[1] = array[right];
			}
			right--;
		}
		else if (array[left] + array[right] < sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	if (res[0] == 0 && res[1] == 0)
	{
		vector<int> temp;
		return temp;
	}
	return res;
}
/*
vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > res;
	vector<int> seq;
	if (sum < 3)
	{
		return res;
	}
	int small = 1, big = 2, count = 3;
	while (small <= (sum + 1) / 2)
	{
		//int count = getCount(small, big);
		if (count == sum)
		{
			seq.clear();
			for (int i = small; i <= big; ++i)
			{
				seq.push_back(i);
			}
			res.push_back(seq);
			big++;
			count += big;
		}
		else if (count > sum)
		{
			count -= small;
			small++;
		}
		else
		{
			big++;
			count += big;
		}
	}
	return res;
}
*/
int main()
{
	int num = 0, sum = 0;
	cin >> sum;
	vector<int> data;
	while (cin >> num)
	{
		data.push_back(num);
	}
	vector<int> res = FindNumbersWithSum(data, sum);
	//vector<vector<int> > res = FindContinuousSequence(sum);
	system("pause");
	return 1;
}
