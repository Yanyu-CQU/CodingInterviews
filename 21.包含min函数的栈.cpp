#include <iostream>
#include <stack>
using namespace std;


class MinStack
{
private:
	stack<int> dataStack;
	stack<int> minStack;
	int minVal;
public:
	MinStack() : minVal(2147483647) {}
	void push(int value) {
		minVal = minVal < value ? minVal : value;
		dataStack.push(value);
		minStack.push(minVal);
	}
	void pop() {
		dataStack.pop();
		minStack.pop();
	}
	int top() {
		return dataStack.top();
	}
	int min() {
		return minStack.top();
	}
	bool empty()
	{
		return dataStack.empty();
	}
};

int main()
{
	int num = 0;
	MinStack st;
	while (cin >> num)
	{
		st.push(num);
	}
	while (st.empty() != true)
	{
		num = st.top();
		cout << num << '\t';
		st.pop();
	}
	system("pause");
	return 0;
}
