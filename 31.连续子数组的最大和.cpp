#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.size() == 0)
	{
		return 0;
	}
	int sum = array[0];
	int maxSum = sum;
	for (int i = 1; i < array.size(); ++i)
	{
		if (sum < 0)
		{
			sum = array[i];
		}
		else
		{
			sum += array[i];
		}
		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

int main()
{
	vector<int> num;// = {1,2,3,2,2,2,5,4,2};
	int temp = 0;
	while (cin >> temp)
	{
		num.push_back(temp);
	}
	
	system("pause");
	return 0;
}
