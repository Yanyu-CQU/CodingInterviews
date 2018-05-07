#include <iostream>
#include <vector>
using namespace std;

bool find(vector<vector<int>>& mat, int num)
{
	int rows = mat.size();
	int cols = mat[0].size();
	int row = 0, col = cols - 1;
	if (rows != 0 && cols != 0)
	{
		while (row < rows && col >= 0)
		{
			if (mat[row][col] == num)
			{
				return true;
			}
			else if (mat[row][col] > num)
			{
				col--;
			}
			else
			{
				row++;
			}
		}
	}
	return false;
}

int main()
{
	vector<int> line;
	vector<vector<int>> mat;
	int rows = 0, cols = 0, num = 0, target = 0;
	cin >> rows >> cols >> target;
	for (int i = 0; i < rows; ++i)
	{
		line.clear();
		for (int j = 0; j < cols; ++j)
		{
			cin >> num;
			line.push_back(num);
		}
		mat.push_back(line);
	}
	cout << find(mat, target) << endl;
	return 0;
} 
