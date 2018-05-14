#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <cmath>
#include <sstream>

using namespace std;

string PrintMinNumber(vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		//throw exception();
		return "";
	}
	stringstream ss;
	stable_sort(numbers.begin(), numbers.end(), [&](int a, int b)->bool{	
		string aStr, bStr;
		ss.clear();
		ss << a;
		ss >> aStr;
		ss.clear();
		ss << b;
		ss >> bStr;
		if (aStr + bStr < bStr + aStr)
			return true;
		else
			return false; 
	});
	ss.clear();
	for (int i = 0; i < numbers.size(); ++i)
	{
		ss << numbers[i];
	}
	string result;
	ss >> result;
	return result;
}

int main()
{
	int num = 0;
	vector<int> numbers;
	while (cin >> num)
	{
		numbers.push_back(num);
	}
	cout << PrintMinNumber(numbers) << endl;
	system("pause");
	return 1;
}
