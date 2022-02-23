//����ʽ ������Ҫ��ʱ�򣬲Ŵ�����������һ��ʱ�任�ռ�ķ�ʽ
#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "�������󴴽���" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "�����������٣�" << endl; };
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
//���
//�������󴴽���
//�����������٣�
