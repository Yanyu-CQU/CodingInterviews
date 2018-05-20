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

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
bool duplicate(int numbers[], int length, int* duplication)
{
	if (length <= 0 || numbers == nullptr)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		while (i != numbers[i])
		{
			if (numbers[i] == numbers[numbers[i]]) // if [location i] has a number is not i, and the number at [loaction number] has a same number, it's duplicate
			{
				*duplication = numbers[i];
				return true;
			}
			else if (numbers[i] != i) // keep swap the num woth wrong location, until the location i has number i
			{
				swap(numbers + i, numbers + numbers[i]);
			}
		}
		
	}
	return false;
}
int main()
{
	
	int data[] = {1,2,4,3,0,2}, num = 0;
	bool flag = duplicate(data, 6, &num);
	system("pause");
	return 1;
}
