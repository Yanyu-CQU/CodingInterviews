#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <memory.h>
#include <memory>
using namespace std;

bool isAllow(int x, int y, int threshold)
{
	int count = 0;
	while (x != 0)
	{
		count += x % 10;
		x /= 10;
	}
	while (y != 0)
	{
		count += y % 10;
		y /= 10;
	}
	if (threshold < count)
	{
		return false;
	}
	return true;
}
int movingCountCore(int threshold, int rows, int cols, int x, int y, bool *isVisited)
{
	int count = 0;
	if (y >= rows || x >= cols || y < 0 || x < 0 || isVisited[y * cols + x] == true || isAllow(x, y, threshold) == false)
	{
		return 0;
	}
	isVisited[y * cols + x] = true;
	return 1 + movingCountCore(threshold, rows, cols, x + 1, y, isVisited) + \
		movingCountCore(threshold, rows, cols, x - 1, y, isVisited) + \
		movingCountCore(threshold, rows, cols, x, y + 1, isVisited) + \
		movingCountCore(threshold, rows, cols, x, y - 1, isVisited);

}
int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows < 1 || cols < 1)
	{
		return 0;
	}
	bool *isVisited = new bool[rows * cols];
	int max = 0;
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			if (isAllow(x, y, threshold) == true) 
			{
				//因为题中限制开始地点是(0,0),如果没有这个限制，轮训每个起点才能找到最大行动区域，因为禁区和活动区域都不是连续的！！！
				memset(isVisited, 0, sizeof(bool) * rows * cols);
				int count = movingCountCore(threshold, rows, cols, x, y, isVisited);
				if (count > max)
				{
					max = count;
				}
			}
		}
	}
	return max;
}
int main()
{
	cout << movingCount(18, 10, 10);
	system("pause");
	return 1;
}
