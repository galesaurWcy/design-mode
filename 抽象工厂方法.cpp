#include<iostream>
using namespace std;
class Department  // 抽象产品Department ,定义具体产品的公共接口
{
public:
	virtual ~Department() = default;
	virtual void Insert() = 0;
	virtual Department* GetDepartment() = 0;
};

// 创建具体产品类SqlserDepartment， 定义生产的具体产品；
class  SqlserDepartment :public Department
{
public:
	void Insert()override
	{
		cout << "在SQL Server 中给 Department 表增加一条记录！" << endl;
	}
	Department* GetDepartment()override
	{
		cout << "在SQL Server 中根据ID 得到 Department 表一条记录！" << endl;
		return nullptr;
	}
};
// 创建具体产品类AccessDepartment， 定义生产的具体产品；
class AccessDepartment : public Department
{
public:
	void Insert()override
	{
		cout << "在 Access 中给 Department 表增加一条记录！" << endl;
	}
	Department* GetDepartment()override
	{
		cout << "在 Access 中根据ID 得到 Department 表一条记录！" << endl;
		return nullptr;
	}
};

class User   // 抽象产品User ,定义具体产品的公共接口
{
public:
	virtual ~User() = default;
	virtual void Insert() = 0;
	virtual User* GetUser() = 0;
};

// 创建具体产品类SqlserverUser， 定义生产的具体产品；
class SqlserverUser :public User
{
public:
	void Insert()override
	{
		cout << "在SQL Server 中给 User表增加一条记录！" << endl;
	}
	User* GetUser()override
	{
		cout << "在SQL Server 中根据ID 得到 User表一条记录！" << endl;
		return nullptr;
	}
};
// 创建具体产品类AccessUser， 定义生产的具体产品；
class AccessUser :public User
{
public:
	void Insert()override
	{
		cout << "在 Access 中给 User表增加一条记录！" << endl;
	}
	User* GetUser()override
	{
		cout << "在 Access 中根据ID 得到 User表一条记录！" << endl;
		return nullptr;
	}
};



class AbstractFactory  // 抽象工厂,定义具体工厂的公共接口
{
public:
	virtual ~AbstractFactory() = default;
	virtual User* CreateUser() = 0;
	virtual Department* CreateDepartment() = 0;
};

// 创建具体工厂SqlServerFactory,定义创建对应具体产品实例的方法；
class SqlServerFactory :public AbstractFactory
{
public:
	User* CreateUser()override
	{
		return new SqlserverUser(); // 该工厂 生产的产品
	}
	Department* CreateDepartment()override
	{
		return new SqlserDepartment;
	}
};
// 创建具体工厂AccessFactory，定义创建对应具体产品实例的方法；
class AccessFactory :public AbstractFactory
{
public:
	User* CreateUser()override
	{
		return new AccessUser(); // 该工厂 生产的产品
	}
	Department* CreateDepartment()override
	{
		return new AccessDepartment;
	}
};


int main()
{
	// AbstractFactory *factory = new SqlServerFactory;
	AbstractFactory* factory = new AccessFactory;
	User* iu = factory->CreateUser(); // 调用的是 AccessFactory 工厂，准备生产  SqlserverUser 产品
	iu->Insert();
	iu->GetUser();

	Department* id = factory->CreateDepartment(); // 调用的是 AccessFactory 工厂，准备生产  AccessDepartment 产品
	id->Insert();
	id->GetDepartment();

	delete factory;
	delete iu;
	delete id;
	factory = nullptr;
	id = nullptr;
	id = nullptr;
	system("pause");
	return 0;
}