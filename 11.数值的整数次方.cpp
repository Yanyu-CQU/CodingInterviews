#include <iostream>
#include <ctime>
using namespace std;

double Power(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	if (exponent == -1)
		return (1.0f / base); // if base = 0, we can choose return 0
	
	double res = Power(base, exponent / 2);
	res *= res;
	if (exponent & 1 != 0)
	{
		if (exponent > 0)
			res *= base;
		else
			res *= (1.0f / base);
	}
	return res;
}

int main()
{
	double base = 0.0;
	int exp = 0;
	while (cin >> base >> exp)
	{
		clock_t  clockBegin, clockEnd;  
		clockBegin = clock();
		cout << Power(base, exp) << endl;
		clockEnd = clock();  
    	printf("%d\n", clockEnd - clockBegin);
	}

	return 0;
}
