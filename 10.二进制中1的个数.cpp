#include <iostream>

using namespace std;

/*
int  NumberOf1(int n)
{
	int index = 1, sum = 0;
	while (index)
	{
		sum += (index & n) != 0;
		index <<= 1;
	}
	return sum;
}*/ 
int  NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = (n - 1) & n;
		count++;
	}
	return count;
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << NumberOf1(num) << endl;
	}
	return 0;
}
