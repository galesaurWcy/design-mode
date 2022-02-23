#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "�������󴴽���" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "�����������٣�" << endl; };

	static Singleton* myInstance; // ������ˣ�
public:
	static Singleton* getInstance()
	{
		return myInstance; // ����Ҳ���ˣ�
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
	Singleton::releaseInstance();//�ֶ��ͷ�
	return 0;
}
//���
//�������󴴽���
//�����������٣�