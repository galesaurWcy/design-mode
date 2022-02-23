#include <iostream>
#include <list>
using namespace std;

//Observer类 抽象观察者,为所有的具体观察者定义一个接口，在得到主题的通知时更新自己。这个接口要做更新接口。
//观察者一般用一个抽象类或者接口实现，更新接口通常包含一个Update()方法 这个方法叫做更新方法。
class Observer
{
public:
    virtual void Update(int) = 0;
};

//Subject类 可翻译为主题或抽象通知者 一般用一个抽象类或者一个接口实现。他把所有对观察者对象的引用保存
//在一个聚集里,每个主题都可以又任何数量的观察者。抽象主题提供一个接口，可增加或者删除观察者对象
class Subject
{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

//ConcreteObserver 具体观察者 实现抽象观察角色所要求的更新接口,以便使本身的状态与主题的状态相协调.
//具体观察者角色可以保存一个指向具体主题对象的引用.具体观察者校色通常用一个具体子类实现
class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject* pSubject) : m_pSubject(pSubject) {}
    void Update(int value)
    {
        cout << "ConcreteObserver get the update. New State:" << value << endl;
    }
private:
    Subject* m_pSubject;
};

class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject* pSubject) : m_pSubject(pSubject) {}

    void Update(int value)
    {
        cout << "ConcreteObserver2 get the update. New State:" << value << endl;
    }

private:
    Subject* m_pSubject;
};

//ConcreteSubject类，叫做具体主题或者具体通知者..将有关状态存入具体观察者对象；在具体主题内部状态改变时...给所有登记过的观察者发出通知.
//具体主题对象通常用一个具体子类实现.
class ConcreteSubject : public Subject
{
public:
    void Attach(Observer* pObserver) 
    {
        m_ObserverList.push_back(pObserver);
    }
    void Detach(Observer* pObserver) {
        m_ObserverList.remove(pObserver);
    }
    void Notify() {
        std::list<Observer*>::iterator it = m_ObserverList.begin();
        while (it != m_ObserverList.end())
        {
            (*it)->Update(m_iState);
            ++it;
        }
    }

    void SetState(int state)
    {
        m_iState = state;
    }

private:
    std::list<Observer*> m_ObserverList;
    int m_iState;
};


int main()
{
    // Create Subject
    ConcreteSubject* pSubject = new ConcreteSubject();

    // Create Observer
    Observer* pObserver = new ConcreteObserver(pSubject);
    Observer* pObserver2 = new ConcreteObserver2(pSubject);

    // Change the state
    pSubject->SetState(2);

    // Register the observer
    pSubject->Attach(pObserver);
    pSubject->Attach(pObserver2);

    pSubject->Notify();

    // Unregister the observer
    pSubject->Detach(pObserver);

    pSubject->SetState(3);
    pSubject->Notify();

    delete pObserver;
    delete pObserver2;
    delete pSubject;
    system("pause");
    return 0;
}