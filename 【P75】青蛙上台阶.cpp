#include <iostream>

using namespace std;
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
f(1) = 1

f(2) = f(2-1) + f(2-2) //f(2-2) 表示2阶一次跳2阶的次数。

f(3) = f(3-1) + f(3-2) + f(3-3)

...

f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n)



f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)

f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)

可以得出：

f(n) = 2*f(n-1)
*/
int jumpFloorII(int number) 
{
    if (number == 1) return 1;
    if (number == 2) return 2;
    return 2 * jumpFloorII(number - 1);
}

int main()
{
	int num = 0;
	cin >> num;
	cout << jumpFloorII(num);
	return 0;
}
