#include <iostream>

using namespace std;
/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/

/*
f(1) = 1

f(2) = f(2-1) + f(2-2) //f(2-2) ��ʾ2��һ����2�׵Ĵ�����

f(3) = f(3-1) + f(3-2) + f(3-3)

...

f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n)



f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)

f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)

���Եó���

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
