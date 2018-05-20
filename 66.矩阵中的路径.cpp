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
#include <string.h>
using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, char* str, int x, int y, bool *isVisited, int & pairLength)
{
	if (pairLength == 0)
	{
		return true;
	}
	if (y >= rows || x >= cols || y < 0 || x < 0 || isVisited[y * cols + x] == true)
	{
		return false;
	}
	if (*str != '\0' && matrix[y * cols + x] == *str)
	{
		pairLength--;
		isVisited[y * cols + x] = true;
		bool flag = hasPathCore(matrix, rows, cols, str + 1, x + 1, y, isVisited, pairLength) || \
			hasPathCore(matrix, rows, cols, str + 1, x - 1, y, isVisited, pairLength) || \
			hasPathCore(matrix, rows, cols, str + 1, x, y + 1, isVisited, pairLength) || \
			hasPathCore(matrix, rows, cols, str + 1, x, y - 1, isVisited, pairLength);
		if (flag == true)
		{
			return true;
		}
		else
		{
			pairLength++;
			isVisited[y * cols + x] = false;
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || str == nullptr || rows < 1 || cols < 1)
	{
		return false;
	}
	//shared_ptr<bool> isVisited(new bool[rows * cols]);
	bool *isVisited = new bool[rows * cols];
	memset(isVisited, 0, sizeof(bool) * cols * rows);
	int pairLength = strlen(str);
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			if (hasPathCore(matrix, rows, cols, str, x, y, isVisited, pairLength) == true)
			{
				delete[] isVisited;
				return true;
			}
		}
	}
	delete[] isVisited;
	return false;
}

int main()
{
	char data[4] = {'1','2','3','4'};
	char* str = "243";
	int num = 0;
	cout << hasPath(data, 2, 2, str);
	
	system("pause");
	return 1;
}
