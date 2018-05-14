#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <cmath>

using namespace std;

int powerTen(int n)
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		result *= 10;
	}
	return result;
}
int getCountOne(const string & number)
{
	if (number.size() == 0 || number[0] < '0' || number[0] > '9')
	{
		return 0;
	}
	int first = number[0] - '0';
	if (number.size() == 1 && first == 0)
	{
		return 0;
	}
	if (number.size() == 1 && first > 0)
	{
		return 1;
	}

	int numFirst = 0;
	if (first > 1)
	{
		numFirst = powerTen(number.size() - 1);
	}
	else if (first == 1) 
	{
		numFirst = atoi(number.substr(1, number.size() - 1).c_str()) + 1;
	}

	int numOther = first * (number.size() - 1) * powerTen(number.size() - 2);
	int numRecur = getCountOne(number.substr(1, number.size() - 1));

	return numFirst + numOther + numRecur;
}

int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	string number;
	stringstream ss;
	ss << n;
	ss >> number;
	return getCountOne(number);
}

int main()
{
	int num = 21345;
	cin >> num;
	cout << NumberOf1Between1AndN_Solution(num) << endl;
	system("pause");
	return 0;
}
