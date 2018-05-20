#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>

using namespace std;
int minThreeNum(int a, int b, int c)
{
	a = a < b ? a : b;
	a = a < c ? a : c;
	return a;
}

int GetUglyNumber_Solution(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int *uglyNumbers = new int[index];
	uglyNumbers[0] = 1;
	int *pMultiply2 = uglyNumbers;//分别记住，一个坐标，该坐标是从小到大，第一个与相应因子相乘，大于当前最大丑数的
	int *pMultiply3 = uglyNumbers;
	int *pMultiply5 = uglyNumbers;

	int calIndex = 1;

	while (calIndex < index)
	{
		int minNum = minThreeNum(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		uglyNumbers[calIndex] = minNum;
//有可能出现的情况：三个坐标都更新了，但是最终不是2的坐标被选中，下一轮移动时，该坐标依然符合要求
		while (*pMultiply2 * 2 <= uglyNumbers[calIndex])
		{
			++pMultiply2;
		}
		while (*pMultiply3 * 3 <= uglyNumbers[calIndex])
		{
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <= uglyNumbers[calIndex])
		{
			++pMultiply5;
		}

		++calIndex;
	}
	int result = uglyNumbers[index - 1];
	delete[] uglyNumbers;
	return result;
}

int main()
{
	int index= 0;
	cin >> index;
	cout << GetUglyNumber_Solution(index) << endl;
	system("pause");
	return 1;
}
