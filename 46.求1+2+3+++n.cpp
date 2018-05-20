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

class Cal
{
private:
	static int n, sum;
public:
	Cal()
	{
		n++;
		sum += n;
	}
	int getSum()
	{
		return sum;
	}
	void reset()
	{
		n = sum = 0;
	}
	virtual int getN(int n)
	{
		return 0;
	}
};
int Cal::n = 0;
int Cal::sum = 0;


class GetZero
{
public:
	virtual int getN(int n)
	{
		return 0;
	}
};
GetZero *pGet[2];
class CalN : public GetZero
{
public:
	virtual int getN(int n)
	{
		return pGet[!!n]->getN(n - 1) + n; // !!n make result only can be 0 or 1.
	}
};

int getZero(int n);
int getN(int n);
typedef int (*fun)(int);
fun pFun[2] = {getZero, getN};
int getZero(int n)
{
	return 0;
}
int getN(int n)
{
	return pFun[!!n](n - 1) + n;
}

template<int n>
struct TempGetN
{
	enum val
	{
		N = TempGetN<n - 1>::N + n
	};
};
template<>
struct TempGetN<1>
{
	enum val
	{
		N = 1
	};
};
int main()
{
	int n = 0;
	cin >> n;
	Cal *p = new Cal[n];
	cout << p[n - 1].getSum() << endl;

	pGet[0] = new GetZero();
	pGet[1] = new CalN();
	cout << pGet[1]->getN(n) << endl;

	cout << getN(n) << endl;

	cout << TempGetN<5>::N << endl; // n cannot be variable
	system("pause");
	return 1;
}
