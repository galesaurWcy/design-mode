//饿汉式 即在需要的时候，才创建对象，这是一种时间换空间的方式
#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "单例对象创建！" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "单例对象销毁！" << endl; };
public:
	static Singleton* getInstance()
	{
		static Singleton myInstance;
		return &myInstance;
	}
};

int main()
{
	Singleton* ct1 = Singleton::getInstance();
	Singleton* ct2 = Singleton::getInstance();
	Singleton* ct3 = Singleton::getInstance();
	return 0;
}
//输出
//单例对象创建！
//单例对象销毁！
