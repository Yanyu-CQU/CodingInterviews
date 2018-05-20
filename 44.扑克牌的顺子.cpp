#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <memory.h>
#include <memory>
using namespace std;

bool IsContinuous( vector<int> numbers )
{
	if (numbers.size() == 0)
	{
		return false;
	}
	sort(numbers.begin(),numbers.end(),[](int a, int b){
		return a < b;
	});
	int zero = 0, sub = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == 0)
		{
			zero++;
		}
	}
	for (int i = zero; i < numbers.size() - 1; ++i)
	{
		sub = numbers[i + 1] - numbers[i] - 1;
		if (numbers[i] == numbers[i + 1] || sub > zero)
		{
			return false;
		}
		else
		{
			zero -= sub;
		}
	}
	return true;
}
int main()
{
	int num = 0;
	vector<int> data;
	while (cin >> num)
	{
		data.push_back(num);
	}
	cout << IsContinuous(data) << endl;
	system("pause");
	return 1;
}
