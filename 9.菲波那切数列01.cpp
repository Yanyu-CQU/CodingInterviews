#include <iostream>
#include <time.h>
using namespace std;

long long Fib01(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fib01(n - 1) + Fib01(n - 2);
}

long long Fib02(int n)
{
	if (n == 1)
		return 1;
	long long num0 = 0, num1 = 1;
	long long num = 0;
	for (int i = 2; i <= n; ++i)
	{
		num = num0 + num1;
		num0 = num1;
		num1 = num;
	}
	return num;
}
int main()
{
	int num = 45;
	while (cin >> num)
	{
		//cin >> num;
		clock_t  clockBegin, clockEnd;  
    	clockBegin = clock();  
	
		cout << Fib01(num) << endl;
		//cout << Fib02(num) << endl;
		clockEnd = clock();  
    	printf("%d\n", clockEnd - clockBegin); 
		
	}
	//system("pause");
}
