#include<iostream>
#include<memory>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "单例对象创建！" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "单例对象销毁！" << endl; };
	static void Destory(Singleton*) { cout << "在这里销毁单例对象！" << endl; };//注意这里
	static shared_ptr<Singleton> myInstance;
public:
	static shared_ptr<Singleton> getInstance()
	{
		return myInstance;
	}

};

shared_ptr<Singleton> Singleton::myInstance(new Singleton(), Singleton::Destory);
int main()
{
	shared_ptr<Singleton>  ct1 = Singleton::getInstance();
	shared_ptr<Singleton>  ct2 = Singleton::getInstance();
	shared_ptr<Singleton>  ct3 = Singleton::getInstance();
	return 0;
}

//输出
//单例对象创建！
//在这里销毁单例对象！