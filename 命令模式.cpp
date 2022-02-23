#include <iostream>
using namespace std;

//Receiver类 知道如何实施与执行一个与请求相关的操作，任何类都可能作为一个接收者
class Receiver {
public:
    void action() {
        cout << "请求执行!" << endl;
    }
};


//Command类，用来声明执行操作的接口
class Command 
{
protected:
    Receiver* receiver;
public:
    Command(Receiver* receiver):receiver(receiver){}
    virtual ~Command() {};
    virtual void Execute() = 0;//抽象执行命令接口
};

//ConcreteCommand类 将一个接收者对象绑定于一个动作 调用接收者相应的操作 以实现Execute
class ConcreteCommand :public Command {
public:    
    ConcreteCommand(Receiver* receiver):Command(receiver) {

    }
    virtual void Execute() {
        receiver->action();
    }
};


//Invoker类，要求该命令执行这个请求
class Invoker {
private:
    Command* command;
public:
    void SetCommand(Command* command) {
        this->command = command;
    }
    void ExecuteCommand() {
        return command->Execute();
    }
};



int main()
{
    Receiver* r = new Receiver();
    Command* c = new ConcreteCommand(r);
    Invoker* i = new Invoker();
    i->SetCommand(c);
    i->ExecuteCommand();
    delete i;
    i = nullptr;
    delete c;
    c = nullptr;
    delete r;
    r = nullptr;
    system("pause");
    return 0;
}