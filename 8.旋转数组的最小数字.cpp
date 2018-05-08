#include <iostream>

using namespace std;

int minElement(int data[], int len)
{
	int left = 0, right = len - 1;
	int mid = (left + right) / 2;
	while (right - left > 1)
	{
		//if three nums are same, the only way is find in order
		/*if (data[mid] == data[left] && data[mid] == data[right])
			return minInOrder(int data[], int len);*/
		if (data[mid] >= data[left])
		{
			left = mid;
		}
		else if (data[mid] <= data[right])
		{
			right = mid;
		}
		mid = (left + right) / 2;
	}
	return data[right];
}

int main()
{
	int data[] = {4,5,6,7,8,9,1,2,3};
	cout << minElement(data, sizeof(data)/sizeof(int));
	//system("pause");
	return 0;
}
