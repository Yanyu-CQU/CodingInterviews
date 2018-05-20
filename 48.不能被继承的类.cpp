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

class Base
{
private:
	Base()
	{
	}
public:
	static Base* getInstance()
	{
		return new Base();
	}
	void deletInstance()
	{
		delete this;
	}
};
/*
class Son : public Base
{
public:
	Son() // cannot call Base's constructor
	{

	}
};*/

template<typename T>
class Base1
{
	friend T;
private:
	Base1();
	~Base1();
};
class Base2 : virtual public Base1<Base2>
{

};
/*
class Son2 : public Base2
{
public:
	Son2(){}; // cannot call Base's constructor
};*/
int main()
{
	Base *i = Base::getInstance();
	i->deletInstance();
	system("pause");
	return 1;
}
