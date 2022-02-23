#include <iostream>
#include <string>

using namespace std;

class SubSystem1
{
public:
	void Method1()
	{
		cout << "Method1" << endl;
	}
};

class SubSystem2
{
public:
	void Method2()
	{
		cout << "Method2" << endl;
	}
};

class SubSystem3
{
public:
	void Method3()
	{
		cout << "Method3" << endl;
	}
};

//外观类 它需要了解所有的子系统的方法或属性，进程组合 以备外界调用
class Facade
{
public:
	Facade() {
		m_a = new SubSystem1();
		m_b = new SubSystem2();
		m_c = new SubSystem3();
	}
	void Method1()
	{
		m_a->Method1();
		m_b->Method2();
	}
	void Method2()
	{
		m_b->Method2();
		m_c->Method3();
	}
private:
	SubSystem1* m_a;
	SubSystem2* m_b;
	SubSystem3* m_c;
};

int main()
{
	Facade* face = new Facade();  //由于Facade的作用 客户端可以根本不知道三个子系统类的存在
	face->Method1();
	face->Method2();
	system("pause");
	return 0;
}