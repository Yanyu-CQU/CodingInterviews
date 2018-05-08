#include <iostream>
#include <string>
#include <vector>
using namespace std;
//use a string to simulate add function
void addCore(string& num, int index)
{
	if (num[index] < '9')
		num[index] += 1;
	else if (index == 0)
	{
		int len = num.size();
		num = "";
		for (int i = 0; i <= len; ++i)
		{
			num += "0";
		}
		num[0] = '1';
	}
	else
	{
		num[index] = '0';
		addCore(num, index - 1);
	}
	return;
}

void addNum(string& num)
{
	addCore(num, num.size() - 1);
}

//All Permutations
void getNumCore(vector<string>& nums, string& num, int index)
{
	if (index >= num.size())
	{
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		num[index] = '0' + i;
		getNumCore(nums, num, index + 1);
		if (index == num.size() - 1)
		{
			nums.push_back(num);
		}
	}
}

void getAllNum(int n)
{
	if (n <= 0)
	{
		return;
	}
	string num(n, '0');
	vector<string> nums;
	getNumCore(nums, num, 0);
	for (auto it = nums.cbegin(); it != nums.cend(); ++it)
	{
		cout << *it << '\t';
	}
	return;
}

int main()
{
	int n = 0;
	string maxNum = "",num = "1";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		maxNum += "9";
	}
	while (num.size() <= maxNum.size() && num <= maxNum)
	{
		cout << num << '\t';
		addNum(num);
	}
	cout << endl;
	cout << "***********************************" << endl;
	getAllNum(n);
	system("pause");
	return 0;
}
