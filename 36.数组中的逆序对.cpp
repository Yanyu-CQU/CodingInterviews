#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
using namespace std;

int InversePairsCore(vector<int> & data, vector<int> & copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int len = (end - start) / 2;//首先将数组分到单个元素，然后开始两两组合，从小数组开始判断大小关系
	int left = InversePairsCore(copy, data, start, start + len);//注意！这里copy和data交换了顺序，目的是将原数组先分两半分别排好序
	int right = InversePairsCore(copy, data, start + len + 1, end);
	int i = start + len;
	int j = end;
	int copyIndex = end;
	int count = 0;
	while (i >= start && j >= start + len + 1)
	{
		if (data[i] > data[j])
		{
			copy[copyIndex--] = data[i--];
			count += j - start - len;
		}
		else
		{
			copy[copyIndex--] = data[j--];
		}
	}
	while (i >= start)
	{
		copy[copyIndex--] = data[i--];
	}
	while (j >= start + len + 1)
	{
		copy[copyIndex--] = data[j--];
	}
	return left + right + count;
}

int InversePairs(vector<int> data)//本质上是一个归并排序
{
	if (data.size() == 0)
	{
		return 0;
	}
	vector<int> copy(data.begin(), data.end());
	int result = InversePairsCore(data, copy, 0, data.size() - 1);
	return result;
}

int main()
{
	int num = 0;
	vector<int> data;
	while (cin >> num)
	{
		data.push_back(num);
	}
	cout <<	InversePairs(data) << endl;
	system("pause");
	return 1;
}
