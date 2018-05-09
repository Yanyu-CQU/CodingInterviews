#include <iostream>
#include <vector>
using namespace std;

void printCircle(const vector<vector<int> >& matrix, vector<int>& print, int start)
{
	int xLen = matrix[0].size() - 2 * start;
	int yLen = matrix.size() - 2 * start;
	int x = start, y = start;
	for (; x < start + xLen; ++x)
	{
		print.push_back(matrix[y][x]);
	}
	x = start + xLen - 1; y = start + 1;
	for (; y < start + yLen; ++y)
	{
		print.push_back(matrix[y][x]);
	}
	y = start + yLen - 1; x = start + xLen - 2;
	for (; x >= start && y != start; --x)//从右边返回左边的过程，纵坐标不能等于开始的那一行，防止单行的输入被重复打印
	{
		print.push_back(matrix[y][x]);
	}
	x = start; y = start + yLen - 2;
	for (; y > start && x != start + xLen - 1; --y)//从下边返回上边的过程，横坐标不能等于开始的那一列，防止单列的输入被重复打印
	{
		print.push_back(matrix[y][x]);
	}
}

vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> print;
	for (int i = 0; i < (matrix.size() + 1) / 2 && i < (matrix[0].size() + 1) / 2; ++i)//size + 1是为了考虑到单数的时候
	{
		printCircle(matrix, print, i);
	}
	return print;
}
int main()
{
	int row = 0, col = 0, temp = 0;;
	vector<int> num;
	vector<vector<int> > matrix;
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		num.clear();
		for (int j = 0; j < col; ++j)
		{
			cin >> temp;
			num.push_back(temp);
		}
		matrix.push_back(num);
	}
	vector<int> print = printMatrix(matrix);
	for (int i = 0; i < print.size(); ++i)
	{
		cout << print[i] << "\t";
	}
	system("pause");
	return 0;
}
