#include <iostream>
#include<string>
#include<map>
using namespace std;

//用户类 用户网站的客户账号，是"网站"类的外部状态
class User
{
private:
	string m_name;
public:
	User(string name)
	{
		m_name = name;
	}
	std::string GetName()
	{
		return m_name;
	}
};

//抽象网站类 定义对象的内部状态和外部状态及其对应的方法。
class WebSite
{
public:
	virtual ~WebSite() = default;
	virtual void Use(User user) = 0;
};

//此处为具体网站类  实现抽象享元角色的方法，在具体的角色中，实现具体方法时需要注意将内部状态与外部状态区分开，不应出现二者同时被修改的方法。
class ConcreteWebSite :public WebSite
{
private:
	string m_name;
public:
	ConcreteWebSite(std::string name)
	{
		m_name = name;
	}
	void Use(User user)override
	{
		cout << "网站分类：" << m_name << "  用户：" + user.GetName() << endl;
	}
};

//此处为网站工程类 负责创建和管理享元角色。当客户对象请求一个享元对象时，享元工厂检査系统中是否存在符合要求的享元对象，
//如果存在则提供给客户；如果不存在的话，则创建一个新的享元对象。
class WebSiteFactory
{
private:
	std::map<std::string, WebSite*> flyweights;
public:
	~WebSiteFactory()
	{
		for (auto it = flyweights.begin(); it != flyweights.end(); ++it)
			delete it->second;
	}
	WebSite* GetWebSiteCategory(string key)
	{
		for (auto it = flyweights.begin(); it != flyweights.end(); ++it)
		{
			if (it->first == key)
				return it->second;
		}

		WebSite* website = new ConcreteWebSite(key);
		flyweights.insert(pair<std::string, WebSite*>(key, website));
		return website;
	}
	int GetWebSiteCount()
	{
		return flyweights.size();
	}
};

int main()
{
	WebSiteFactory f;

	WebSite* fx = f.GetWebSiteCategory("产品展示");
	fx->Use(User("小菜"));

	WebSite* fy = f.GetWebSiteCategory("产品展示");
	fy->Use(User("大鸟"));

	WebSite* fz = f.GetWebSiteCategory("产品展示");
	fz->Use(User("娇娇"));

	WebSite* fl = f.GetWebSiteCategory("博客");
	fl->Use(User("老顽童"));

	WebSite* fm = f.GetWebSiteCategory("博客");
	fm->Use(User("桃谷六仙"));

	WebSite* fn = f.GetWebSiteCategory("博客");
	fn->Use(User("南海鳄神"));

	cout << "得到网站分类总数：" << f.GetWebSiteCount() << endl;

	system("pause");
	return 0;
}