#include<iostream>
#include<list>
using namespace std;
//公司类... 抽象或者接口
class Company {
public:
	Company(string name) {
		this->name = name;
	}
	virtual void Add(Company* c) = 0; //增加
	virtual void Remove(Company* c) = 0;//移除
	virtual void Display(int depth) = 0;//显示
	virtual void LineOfDuty() = 0;//履行职责...不同部分履行的职责不一样
protected:
	string name;
};

//具体公司类  树枝节点
class ConcreteCompany :public Company {
public:
	ConcreteCompany(string name) :Company(name) {}

	virtual void Add(Company* c) {
		children->push_back(c);
	}
	virtual void Remove(Company* c) {
		children->remove(c);
	}
	virtual void Display(int depth) {
		string  s(depth, '-');
		cout << s << name << endl;
		for (list<Company*>::iterator it = children->begin(); it != children->end(); it++) {
			(*it)->Display(depth + 2);
		}
	}
	virtual void LineOfDuty() {
		for (list<Company*>::iterator it = children->begin(); it != children->end(); it++) {
			(*it)->LineOfDuty();
		}
	}

private:
	list<Company*>* children = new list<Company*>;
};

//叶子节点  人力资源部
class HRDepartment :public Company {
public:
	HRDepartment(string name) :Company(name) {}

	virtual void Add(Company* c) {}
	virtual void Remove(Company* c) {}
	virtual void Display(int depth) {
		string  s(depth, '-');
		cout << s << name << endl;
	}
	virtual void LineOfDuty() {
		cout << name << " 员工招聘培训管理" << endl;
	}
};

class FinanceDepartment :public Company {
public:
	FinanceDepartment(string name) :Company(name) {}

	virtual void Add(Company* c) {}
	virtual void Remove(Company* c) {}
	virtual void Display(int depth) {
		string  s(depth, '-');
		cout << s << name << endl;
	}
	virtual void LineOfDuty() {
		cout << name << " 公司财务收支管理" << endl;
	}
};

int main() {
	ConcreteCompany* root = new ConcreteCompany("北京总公司");
	root->Add(new HRDepartment("总公司人力资源部"));
	root->Add(new FinanceDepartment("总公司财务部"));

	ConcreteCompany* comp = new ConcreteCompany("上海华东分公司");
	comp->Add(new HRDepartment("华东分公司人力资源部"));
	comp->Add(new FinanceDepartment("华东分公司财务部"));
	root->Add(comp);

	ConcreteCompany* comp1 = new ConcreteCompany("南京办事处");
	comp1->Add(new HRDepartment("南京办事处人力资源部"));
	comp1->Add(new FinanceDepartment("南京办事处财务部"));
	comp->Add(comp1);

	ConcreteCompany* comp2 = new ConcreteCompany("杭州办事处");
	comp2->Add(new HRDepartment("杭州办事处人力资源部"));
	comp2->Add(new FinanceDepartment("杭州办事处财务部"));
	comp->Add(comp2);

	cout << "结构图: " << endl;
	root->Display(1);

	cout << "\n职责图: " << endl;
	root->LineOfDuty();

	delete comp2;
	delete comp1;
	delete comp;
	delete root;
	return 0;
}

