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

vector<int> multiply(const vector<int>& A)
{
	
	if (A.size() == 0)
	{
		vector<int> B;
		return B;
	}
	vector<int> B(A.size());
	B[0] = 1;
	for (int i = 1; i < A.size(); ++i)
	{
		B[i] = B[i - 1] * A[i - 1];
	}
	int multi = 1;
	for (int i = A.size() - 2; i >= 0; --i)
	{
		multi *= A[i + 1];
		B[i] *= multi;
	}
	return B;
}
int main()
{
	int num = 0;
	vector<int> A, B;
	while (cin >> num)
	{
		A.push_back(num);
	}
	B = multiply(A);
	for (int i = 0; i < A.size(); ++i)
	{
		cout << B[i] << '\t';
	}
	system("pause");
	return 1;
}
