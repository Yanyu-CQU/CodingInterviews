#include <iostream>
#include <mutex>
#include <future>
#include <thread>
#include <set>
using namespace std;

class Singleton  
{
public:
	static Singleton* GetInstance();
	void show()
	{
		cout << "singleton!" << endl;
	}
private:
	Singleton() {}
	static Singleton *singleton;
};
Singleton* Singleton::singleton = nullptr;
Singleton* Singleton::GetInstance() 
{
	if(singleton == NULL)
		singleton = new Singleton();
	return singleton;
};


class ThdSafeSingleton
{
public:
	static ThdSafeSingleton* GetInstance();
	void show()
	{
		cout << "thread safe singleton!" << endl;
	}
private:
	static mutex lc;
	static ThdSafeSingleton* pSl;
	ThdSafeSingleton() {}
};
mutex ThdSafeSingleton::lc;
ThdSafeSingleton* ThdSafeSingleton::pSl = nullptr;
ThdSafeSingleton* ThdSafeSingleton::GetInstance()
{
	lock_guard<mutex> l(lc);
	if (pSl == nullptr)
	{
		pSl = new ThdSafeSingleton();
	}
	return pSl;
};

ThdSafeSingleton* fun1()
{
	ThdSafeSingleton* tsl = ThdSafeSingleton::GetInstance();
	tsl->show();
	return tsl;
}

int main()
{
	Singleton* sl1 = Singleton::GetInstance();
	sl1->show();
	Singleton* sl2 = Singleton::GetInstance();
	if (sl1 == sl2)
	{
		cout << "singleton is Ok!" << endl;
	}
	
	static const int threadCount = 1000;
	future<ThdSafeSingleton*> f[threadCount];
	for (int i = 0; i < threadCount; ++i)
	{
		f[i] = future<ThdSafeSingleton*>(async(launch::async, fun1));
	}
	set<ThdSafeSingleton*> isSame;
	for (int i = 0; i < threadCount; ++i)
	{
		isSame.insert(f[i].get());
	}
	if (isSame.size() == 1)
	{
		cout << "thread safe singleton is Ok!" << endl;
	}
	return 0;
}

