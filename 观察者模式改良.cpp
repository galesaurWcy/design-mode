#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;
//抽象观察者
class Observer
{
protected:
    string name;
    Subject* sub;
public:
    Observer(string name, Subject* sub)
    {
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};
//具体的观察者，看股票的
class StockObserver :public Observer
{
public:
    StockObserver(string name, Subject* sub) :Observer(name, sub)
    {
    }
    void update();
};
//具体的观察者，看NBA的
class NBAObserver :public Observer
{
public:
    NBAObserver(string name, Subject* sub) :Observer(name, sub)
    {
    }
    void update();
};
//抽象通知者
class Subject
{
protected:
    list<Observer*> observers;
public:
    string action;
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};
//具体通知者，秘书
class Secretary :public Subject
{
    void attach(Observer* observer)
    {
        observers.push_back(observer);
    }
    void detach(Observer* observer)
    {
        list<Observer*>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            if ((*iter) == observer)
            {
                observers.erase(iter);
            }
            ++iter;
        }
    }
    void notify()
    {
        list<Observer*>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void StockObserver::update()
{
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "梁所长来了!")
    {
        cout << "我马上关闭股票，装做很认真工作的样子！" << endl;
    }
}

void NBAObserver::update()
{
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "梁所长来了!")
    {
        cout << "我马上关闭NBA，装做很认真工作的样子！" << endl;
    }
}

int main()
{
    Subject* dwq = new Secretary(); //创建观察者<br>　　　　//被观察的对象
    Observer* xs = new NBAObserver("xiaoshuai", dwq);
    Observer* zy = new NBAObserver("zouyue", dwq);
    Observer* lm = new StockObserver("limin", dwq);
    //加入观察队列
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);
    //事件
    dwq->action = "去吃饭了！";//通知
    dwq->notify();
    cout << endl;
    dwq->action = "梁所长来了!";
    dwq->notify();
    return 0;
}