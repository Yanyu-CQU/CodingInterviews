#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <list>
#include <memory.h>
#include <memory>
using namespace std;

int Add(int num1, int num2)
{
	int sum = 0, carry = 0;
	do 
	{
		sum = num1 ^ num2; // add without carry 
		carry = (num1 & num2) << 1; // if some bit has to carry, we should do add again

		num1 = sum;
		num2 = carry;
	} while (carry != 0);

	return sum;
}
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	cout << Add(n, m) << endl;
	system("pause");
	return 1;
}
