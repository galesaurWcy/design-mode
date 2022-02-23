#include <algorithm>
#include <iostream>
using namespace std;
#define free_ptr(p) if(p) delete p; p = nullptr;

//Strategt类，定义所有支持的算法的公共接口
class Strategy {
public:
	virtual ~Strategy() {};
	virtual void AlgorithmInterface() = 0;
};

//ConcreteStrategy 封装了具体的算法或行为，继承Strategy
class ConcreteStrategyA : public Strategy{
	void AlgorithmInterface() {
		cout << "算法A实现" << endl;
	}
};

class ConcreteStrategyB : public Strategy {
	void AlgorithmInterface() {
		cout << "算法B实现" << endl;
	}
};

class ConcreteStrategyC : public Strategy {
	void AlgorithmInterface() {
		cout << "算法C实现" << endl;
	}
};

//Context,用一个ConcreteStrategy来配置,维护一个对Strategy的引用
class Context {
public:
	Context(Strategy* strategy) : m_strategy(strategy) {};
	~Context() { free_ptr(m_strategy); }
	void AlgorithmInterface() {
		m_strategy->AlgorithmInterface();
	};
private:
	Strategy* m_strategy;
};


int main() {
	Strategy* concreteStrategyA = new ConcreteStrategyA();
	Strategy* concreteStrategyB = new ConcreteStrategyB();
	Strategy* concreteStrategyC = new ConcreteStrategyC();

	concreteStrategyA->AlgorithmInterface();
	concreteStrategyB->AlgorithmInterface();
	concreteStrategyC->AlgorithmInterface();

	free_ptr(concreteStrategyA);
	free_ptr(concreteStrategyB);
	free_ptr(concreteStrategyC);
	return 0;
}