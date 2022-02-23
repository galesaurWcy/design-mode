#include <iostream>
using namespace std;

class Subject  //Subject 定义了RealSubject和Proxy的共用接口..这样就在任何使用RealSubject的地方都可以使用Proxy
{
public:
	virtual void func()
	{
		cout << "Subject" << endl;
	}
};

class RealSubject :public Subject // RealSubject  定义proxy所代表的真实实体
{
public:
	virtual void func()
	{
		cout << "RealSubject" << endl;
	}
};

class Proxy : public Subject //proxy 保存一个引用使得代理可以访问实体,并且提供一个于Subject的接口相同的接口 这样代理就可以用来替代实体
{
	RealSubject real;
public:
	virtual void func()
	{
		cout << "Proxy" << endl;
		real.func();
	}
};

int main()
{
	Proxy proxy;
	proxy.func();
	return 0;
}