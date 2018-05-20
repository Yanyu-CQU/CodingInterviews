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

class Solution {
public:
	void Insert(int num)
	{
		if ((max.size() + min.size()) % 2 == 0) // odd index num number insert into min heap(right heap)
		{
			if (max.size() > 0 && num < max[0]) //make sure the max heap always less than min heap!!!!
			{
				//get the max num in max heap, replace num
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>()); // mak heap from big to small
				num = max[0];//get the max num
				pop_heap(max.begin(), max.end(), less<int>());//pop_heap make the old max number to the last location of vector
				max.pop_back();//pop the old max number
			}
			// now num must bigger than everyone in max heap
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if (min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = max.size() + min.size();
		if (size == 0)
		{
			logic_error ex("No number!"); // notie: when use gcc, we must construct a logic_error; in VS,we can just use throw exception("XXX")
			throw exception(ex);
		}
		double median = 0.0;
		if (size % 2 == 1)
		{
			return min[0];
		}
		else
		{
			return (max[0] + min[0]) / 2.0;
		}
		return median;
	}
private:
	vector<int> max, min;
};

int main()
{
	Solution so;
	int num = 0;
	while (cin >> num)
	{
		so.Insert(num);
	}
	cout << so.GetMedian() << endl;
	

	system("pause");
	return 1;
}

