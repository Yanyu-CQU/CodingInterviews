#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template<typename T>
class Queue
{
private:
	stack<T> front;
	stack<T> back;
public:
	void push(const T& t)
	{
		back.push(t);
	}
	void pop()
	{
		if (front.size() == 0)
		{
			while (back.size() != 0)
			{
				front.push(back.top());
				back.pop();
			}
			if (front.size() != 0)
			{
				front.pop();
			}
		}
		else
		{
			front.pop();
		}
	}
	T& top()
	{
		if (front.size() != 0)
		{
			return front.top();
		}
		else
		{
			while (back.size() != 0)
			{
				front.push(back.top());
				back.pop();
			}
			if (front.size() != 0)
			{
				return front.top();
			}
			else
			{
				throw new exception();
			}
		}
	}
	int size()
	{
		return front.size() + back.size();
	}
}; 

int main()
{
	Queue<int> qu;
	qu.push(10);
	qu.push(9);
	qu.push(8);
	qu.push(7);
	qu.pop();
	qu.push(1);
	qu.push(2);
	qu.push(11);
	qu.push(12);
	while (qu.size() != 0)
	{
		cout << qu.top() << "\t";
		qu.pop();
	}
	return 0;
}
