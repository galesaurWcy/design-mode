#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "单例对象创建！" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "单例对象销毁！" << endl; };

	static Singleton* myInstance; // 这里改了！
public:
	static Singleton* getInstance()
	{
		return myInstance; // 这里也改了！
	}
	static void releaseInstance()
	{
		delete myInstance;
	}
};

Singleton* Singleton::myInstance = new Singleton();
int main()
{
	Singleton* ct1 = Singleton::getInstance();
	Singleton* ct2 = Singleton::getInstance();
	Singleton* ct3 = Singleton::getInstance();
	Singleton::releaseInstance();//手动释放
	return 0;
}
//输出
//单例对象创建！
//单例对象销毁！