#include<iostream>
#include<memory>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "�������󴴽���" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "�����������٣�" << endl; };
	static void Destory(Singleton*) { cout << "���������ٵ�������" << endl; };//ע������
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

//���
//�������󴴽���
//���������ٵ�������