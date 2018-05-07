#include <iostream>

using namespace std;

int partition(int* data, int len, int start, int end)
{
	if (data == nullptr || len <= 0 || start < 0 || end <= start || end >= len)
	{
		throw exception();
	}
	//数组最后作为基准
	//small代表边界，边界从start - 1开始，向前寻找
	//发现小于基准的坐标，将边界移到该坐标
	//index要不就跟着边界同步走，如果走到边界前边，说明遇到了比基准大的数
	//index一旦发现小于基准的数，将他与边界右边的数交换
	//		（如果边界右边的数和index同一坐标，不用交换，将边界向前移；如果不同坐标，可以保证边界右边的数一定是大于基准的的，因为index已经扫描过这个坐标了，可以放心交换）
	//index走在前面的过程中，保证了index和边界small中间不再有小于基准的数
	//当index走到基准时，边界及其左边都是小于基准的，边界右边都是大于基准的，因此把边界右边的数和基准交换
	//细节：index没有走到最后的基准位置，因为防止数组本身就是升序排列时，边界直接走到基准坐标，此时边界右边不再有数
	int small = start - 1;
	for (int index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				int temp = data[small];
				data[small] = data[index];
				data[index] = temp;
			}
		}
	}
	++small;
	int temp = data[small];
	data[small] = data[end];
	data[end] = temp;

	return small;
}

void quickSort(int* data, int len, int start, int end)
{
	if (start == end)
	{
		return;
	}
	int index = partition(data, len, start, end);
	if (index > start)
	{
		quickSort(data, len, start, index - 1);
	}
	if (index < end)
	{
		quickSort(data, len, index + 1, end);
	}
}
int main()
{
	static const int len = 9;
	int data[] = {1,6,3,9,5,8,3,4,7,0};
	quickSort(data, len, 0, len - 1);
	for (int i = 0; i < len; ++i)
	{
		cout << data[i] << "\t";
	}
	return 0;
}
