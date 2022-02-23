#include<cstdio>

class Operator // 抽象类-计算器类
{
public:
	virtual void GetResult() = 0;
	void SetNumA(double numA)
	{
		a = numA;
	}
	void SetNumB(double numB)
	{
		b = numB;
	}
protected:
	double a, b;
};

class OperatorAdd : public Operator //加法器类，继承计算器类
{
public:
	void GetResult()
	{
		printf("a+b=%lf\n", a + b);
	}
};

class OperatorSub : public Operator // 减法器类，继承计算器类
{
public:
	void GetResult()
	{
		printf("a-b=%lf\n", a - b);
	}
};

class IFactory  // 工厂类
{
public:
	virtual Operator* CreateOperator() = 0;
};

class AddFactory : public IFactory
{
	Operator* CreateOperator()
	{
		return new OperatorAdd();
	}
};

class SubFactory : public IFactory
{
	Operator* CreateOperator()
	{
		return new OperatorSub();
	}
};

int main()
{
	IFactory* operFactory = new AddFactory();
	Operator* oper = operFactory->CreateOperator();
	oper->SetNumA(1.1);
	oper->SetNumB(2.2);
	oper->GetResult();

	return 0;
}
