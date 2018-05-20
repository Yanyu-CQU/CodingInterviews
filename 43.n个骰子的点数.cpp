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

void getSumCount(int number, int n, int sum, int *sumCount)
{
	if (n == 0)
	{
		sumCount[sum - number]++;
		return;
	}
	for (int i = 1; i <= 6; ++i)
	{
		getSumCount(number, n - 1, sum + i, sumCount);
	}
}

void printProb(int n)
{
	if (n < 1)
	{
		return;
	}
	int maxSum = n * 6;
	shared_ptr<int> sumCount(new int[maxSum - n + 1]);
	memset(sumCount.get(), 0, (maxSum - n + 1) * sizeof(int));
	getSumCount(n, n, 0, sumCount.get());
	int totalCount = pow(6.0, n);
	for (int i = 0; i <= maxSum - n; ++i)
	{
		cout << "The sum == " << i + n << " has count == " << sumCount.get()[i];
		float prob = (float)sumCount.get()[i] / totalCount;
		cout << " The prob is: " << prob << endl;
	}
	
}
int main()
{
	int num = 0;
	cin >> num;
	printProb(num);
	system("pause");
	return 1;
}
