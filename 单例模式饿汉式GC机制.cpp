#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton() { cout << "�������󴴽���" << endl; };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton() { cout << "�����������٣�" << endl; };
	static Singleton* myInstance;
public:
	static Singleton* getInstance()
	{
		return myInstance;
	}
private:
	// ����һ���ڲ���
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
	// ����һ���ڲ���ľ�̬����
	// ���ö�������ʱ��˳�����ͷ�myInstanceָ��Ķ�����Դ
	static GC m_garbo;
};
Singleton* Singleton::myInstance = new Singleton();

Singleton::GC Singleton::m_garbo; // ע�������
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
