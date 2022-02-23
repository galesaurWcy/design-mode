#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "单例对象创建！" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "单例对象销毁！" << endl; };
	static Singleton* myInstance;
public:
	static Singleton* getInstance()
	{
		return myInstance;
	}
private:
	// 定义一个内部类
	class GC {
	public:
		GC() {};
		~GC()
		{
			if (nullptr != myInstance)
			{
				delete myInstance;
				myInstance = nullptr;
			}
		}
	};
	// 定义一个内部类的静态对象
	// 当该对象销毁时，顺带就释放myInstance指向的堆区资源
	static GC m_garbo;
};
Singleton* Singleton::myInstance = new Singleton();

Singleton::GC Singleton::m_garbo; // 注意这里！！
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
