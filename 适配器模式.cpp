
#include <iostream>
using namespace std;
//球员
class Player
{
protected:
    string name;
public:
    Player(string name):name(name){}
    virtual void Attack() = 0;
    virtual void Defense() = 0;
    virtual~Player() {}
};
//前锋
class Forwards : public Player
{
public:
    Forwards(string name):Player(name){}
    virtual void Attack() {
        cout << "前锋" << name << "进攻" << endl;
    }
    virtual void Defense() {
        cout << "前锋" << name << "防守" << endl;
    }
};

//中锋
class Center : public Player
{
public:
    Center(string name) :Player(name) {}
    virtual void Attack() {
        cout << "中锋" << name << "进攻" << endl;
    }
    virtual void Defense() {
        cout << "中锋" << name << "防守" << endl;
    }
};

//后卫
class Guards : public Player
{
public:
    Guards(string name) :Player(name) {}
    virtual void Attack() {
        cout << "后卫" << name << "进攻" << endl;
    }
    virtual void Defense() {
        cout << "后卫" << name << "防守" << endl;
    }
};

class ForeignCenter {
public:
    void SetName(string name) {
        this->name = name;
    }
    string GstName() {
        return name;
    }
    void ForeignAttack() {
        cout << "外籍中锋 " << name << " 攻击" << endl;
    }
    void ForeignDefense() {
        cout << "外籍中锋 " << name << " 防守" << endl;
    }

private:
    string name;
};

//适配器类 翻译者
class Translator :public Player {
public:
    Translator(string name) :Player(name) {
        ym = new ForeignCenter;
        ym->SetName(name);
    }
    ~Translator()
    {
        if (ym != NULL) delete ym;
    }
    void Attack() { //翻译者将Attack 翻译成 ForeignAttack
        ym->ForeignAttack();
    }
    void Defense() {
        ym->ForeignDefense(); //翻译者将Defense 翻译成 ForeignDefense
    }

private:
    ForeignCenter* ym; //外籍中锋
};
int main()
{
    Player* b = new Forwards("巴蒂尔");
    b->Attack();
    Player* c = new Guards("麦克格雷迪");
    c->Attack();
    Player* ym  = new Translator("姚明"); //姚明问: "Attack和Defense是什么意思？"
    ym->Attack();
    ym->Defense();
    system("pause");
    return 0;
}
