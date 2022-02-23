#include <iostream>
using namespace std;
#include <mutex>

class Singleton {
private:
	Singleton() { cout << "单例对象创建！" << endl; }  //构造函数

	static Singleton* m_pSingleton;
	static mutex m_mutex; //锁

public:
	static Singleton* GetInstance() {
		if (m_pSingleton == nullptr) {
			std::lock_guard<std::mutex> lock(m_mutex);  //加锁
			if (m_pSingleton == nullptr) {
				m_pSingleton = new Singleton();
			}
		}
		return m_pSingleton;
	}

private:
	//GC机制
	class GC {
	public:
		GC() {}

		~GC() {
			//可以在这里销毁所有的资源，例如：db连接、文件句柄等
			if (m_pSingleton != nullptr) {
				cout << "在这里销毁单例对象" << endl;
				delete m_pSingleton;
				m_pSingleton = nullptr;
			}
		}
	};
	static GC gc;
};

Singleton* Singleton::m_pSingleton = nullptr;
Singleton::GC Singleton::gc;

mutex Singleton::m_mutex;  //注意这里一定要写

int main() {
	Singleton* st1 = Singleton::GetInstance();
	Singleton* st2 = Singleton::GetInstance();
	Singleton* st3 = Singleton::GetInstance();

	return 0;
}
//输出
//单例对象创建！
//在这里销毁单例对象