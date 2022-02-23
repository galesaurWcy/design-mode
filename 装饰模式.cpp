//装饰模式,动态地给一个对象添加一些额外的职责，就增加功能来说 装饰模式比生成子类更为灵活
#include <iostream>
using namespace std;

//ConcreteComponent即Component
class Person
{
protected:
    string name;
public:
    Person() {};
    Person(string name):name(name) {};
    virtual void show() {
        cout << "装扮的" << name << endl;
    }

};


//Decorator类（装饰类），继承了Persson类，并且弱拥有Person类
class Finery : public Person
{
protected:
    Person* component;
public:
    Finery():component(nullptr){}
    void Decorate(Person* component)
    {
        this->component = component;
    }
    virtual void show()
    {
        if (component)
            component->show();
    }
};

//ConcreteDecorator类
class TShirts : public Finery
{
public:
    virtual	~TShirts() {}
    virtual void show()
    {
        cout << "Tshirt" << endl;
        Finery::show();
    }
};

//ConcreteDecorator类
class Jeans : public Finery
{
public:
    virtual	~Jeans() {}
    virtual void show()
    {
        cout << "Jeans" << endl;
        Finery::show();
    }
};

int main()
{
    Person* p = new Person("小菜");
    TShirts* oTShirt = new TShirts();
    Jeans* oJeans = new Jeans();
    oTShirt->Decorate(p);
    oJeans->Decorate(oTShirt);
    oJeans->show();


    delete p; p = nullptr;
    delete oTShirt; oTShirt = nullptr;
    delete oJeans; oJeans = nullptr;
    system("pause");
    return 0;
}

