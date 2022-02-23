//饿汉式 即类产生的时候就创建好实例化对象，这是一种空间换时间的方式
#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "单例对象创建！" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "单例对象销毁！" << endl; };

	static Singleton myInstance; // 单例对象在这里！
public:
	static Singleton* getInstance()
	{
		return &myInstance;
	}
};

Singleton Singleton::myInstance;
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