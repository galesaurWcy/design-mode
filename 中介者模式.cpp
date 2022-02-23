//中介者模式(Mediator),用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显示得相互引用，从而使得其耦合松散，而且可以独立地改变他们之间得交互

#include <iostream>
#include <string>

using namespace std;

#define SAFE_DELETE(p) if(p) {delete p; p = NULL}

class Mediator;

//抽象同事类
class Colleague
{
public:
    Colleague(Mediator* pMediator) : m_pMediator(pMediator) {}; //得到中介者对象
    virtual void Send(char* message) = 0;
protected:
    Mediator* m_pMediator;
};

//具体同事1
class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator* pMediator) : Colleague(pMediator) {};

    virtual void Send(char* message);

    void Notify(char* message)
    {
        cout << "同事1得到消息:" << message << endl;
    }
};
//具体同事2
class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator* pMediator) : Colleague(pMediator) {};

    virtual void Send(char* message);

    void Notify(char* message)
    {
        cout << "同事2得到消息:" << message << endl;
    }
};

//主管
class Mediator
{
public:
    virtual void Send(char* message, Colleague* pColleague) = 0;
};


void ConcreteColleague1::Send(char* message)
{
    m_pMediator->Send(message, this);
}

void ConcreteColleague2::Send(char* message)
{
    m_pMediator->Send(message, this);
}
//具体主管
class ConcreteMediator : public Mediator
{
public:
    //重写声明方法 实现了两个对象得通信
    void Send(char* message, Colleague* pColleague)
    {
        ConcreteColleague1* pConcreteColleague1 = dynamic_cast<ConcreteColleague1*>(pColleague);

        if (pConcreteColleague1)
        {
            cout << "消息来自同事1" << endl;

            if (m_pColleague2)
            {
                m_pColleague2->Notify(message);
            }
        }
        else
        {
            cout << "消息来自同事2" << endl;
            if (m_pColleague1)
            {
                m_pColleague1->Notify(message);
            }
        }
    }

    //具体主管了解改组下的所有得同事.... 所以拥有同事1和同事2得所有属性
    void setColleague1(Colleague* pColleague)
    {
        m_pColleague1 = dynamic_cast<ConcreteColleague1*>(pColleague);
    }

    void setColleague2(Colleague* pColleague)
    {
        m_pColleague2 = dynamic_cast<ConcreteColleague2*>(pColleague);
    }

private:
    ConcreteColleague1* m_pColleague1; //同事1
    ConcreteColleague2* m_pColleague2; //同事2 
};

int main(int argc, char** argv)
{
    Mediator* pMediator = new ConcreteMediator();

    Colleague* pColleague1 = new ConcreteColleague1(pMediator);
    Colleague* pColleague2 = new ConcreteColleague2(pMediator);

    ConcreteMediator* pConcreteMediator = dynamic_cast<ConcreteMediator*>(pMediator);
    pConcreteMediator->setColleague1(pColleague1);
    pConcreteMediator->setColleague2(pColleague2);

    char message1[128] = "你吃饭了吗?";
    pColleague1->Send(message1);

    char message2[128] = "还没呢";
    pColleague2->Send(message2);

    delete pColleague1;
    delete pColleague2;
    delete pMediator;

    return 0;
}