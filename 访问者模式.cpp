#include <iostream>
#include <list>
using namespace std;

class Visitor;

//组成Computer的各组件基类
class Element
{
public:
    Element(string strName) :m_strName(strName) {}
    string GetName()
    {
        return m_strName;
    }
    //组件接受访问者访问的接口
    virtual void AcceptVisitor(Visitor* pVisitor) = 0;

private:
    //组件的标识名称
    string m_strName;
};

//访问者基类，针对不同组件，提供不同的访问接口
class Visitor
{
public:
    virtual void VisitCPU(Element* pEle) = 0;
    virtual void VisitGPU(Element* pEle) = 0;
    virtual void VisitDISK(Element* pEle) = 0;
};

//Computer类，由各组件组成，访问者访问Computer时将依次访问各组件
class Computer
{
public:
    ~Computer()
    {
        for (Element* pElement : m_listEle)
        {
            delete pElement;
        }
    }

    void AddElement(Element* pEle)
    {
        m_listEle.push_back(pEle);
    }

    void DelElement(Element* pEle)
    {
        m_listEle.remove(pEle);
    }

    //访问者访问Computer时将依次访问各组件
    void AcceptVisitor(Visitor* pVisitor)
    {
        for (Element* pElement : m_listEle)
        {
            pElement->AcceptVisitor(pVisitor);
        }
    }

private:
    list<Element*> m_listEle;
};

//访问者实现类，实现各自的访问方法
class VisitorA : public Visitor
{
public:
    void VisitCPU(Element* pEle)
    {
        printf("Visitor A record CPU's name:%s\n", pEle->GetName().c_str());
    }

    void VisitGPU(Element* pEle)
    {
        printf("Visitor A do nothing to GPU:%s\n", pEle->GetName().c_str());
    }

    void VisitDISK(Element* pEle)
    {
        printf("Visitor A change DISK:%s\n", pEle->GetName().c_str());
    }
};

class VisitorB : public Visitor
{
public:
    void VisitCPU(Element* pEle)
    {
        printf("Visitor B do nothing to CPU:%s\n", pEle->GetName().c_str());
    }

    void VisitGPU(Element* pEle)
    {
        printf("Visitor B record GPU's name:%s\n", pEle->GetName().c_str());
    }

    void VisitDISK(Element* pEle)
    {
        printf("Visitor B do nothing to DISK:%s\n", pEle->GetName().c_str());
    }
};

//组件的实现类，调用访问者相应的访问方法
class CPU :public Element
{
public:
    CPU(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitCPU(this);
    }
};

class GPU :public Element
{
public:
    GPU(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitGPU(this);
    }
};

class Disk :public Element
{
public:
    Disk(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitDISK(this);
    }
};

int main()
{
    Computer oComputer;
    oComputer.AddElement(new CPU("i9-10980XE"));
    oComputer.AddElement(new GPU("Titan RTX"));
    oComputer.AddElement(new Disk("HOF PRO M.2"));

    VisitorA oVisitorA;
    VisitorB oVisitorB;

    oComputer.AcceptVisitor(&oVisitorA);
    oComputer.AcceptVisitor(&oVisitorB);

    return 0;
}