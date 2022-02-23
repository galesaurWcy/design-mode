#include <iostream>
using namespace std;
#include <mutex>

class Singleton {
private:
	Singleton() { cout << "�������󴴽���" << endl; }  //���캯��

	static Singleton* m_pSingleton;
	static mutex m_mutex; //��

public:
	static Singleton* GetInstance() {
		if (m_pSingleton == nullptr) {
			std::lock_guard<std::mutex> lock(m_mutex);  //����
			if (m_pSingleton == nullptr) {
				m_pSingleton = new Singleton();
			}
		}
		return m_pSingleton;
	}

private:
	//GC����
	class GC {
	public:
		GC() {}

		~GC() {
			//�����������������е���Դ�����磺db���ӡ��ļ������
			if (m_pSingleton != nullptr) {
				cout << "���������ٵ�������" << endl;
				delete m_pSingleton;
				m_pSingleton = nullptr;
			}
		}
	};
	static GC gc;
};

Singleton* Singleton::m_pSingleton = nullptr;
Singleton::GC Singleton::gc;

mutex Singleton::m_mutex;  //ע������һ��Ҫд

int main() {
	Singleton* st1 = Singleton::GetInstance();
	Singleton* st2 = Singleton::GetInstance();
	Singleton* st3 = Singleton::GetInstance();

	return 0;
}
//���
//�������󴴽���
//���������ٵ�������