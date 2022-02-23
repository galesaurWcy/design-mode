#include<iostream>
#include<string>

//WorkExperience类
class WorkExprerience {
private:
    std::string workDate;
    std::string company;
public:
    WorkExprerience() {}
    ~WorkExprerience() {}

    WorkExprerience(WorkExprerience* work) {
        this->workDate = work->workDate;
        this->company = work->company;
    }
    std::string getWorkDate() {
        return workDate;
    }
    void setWorkDate(std::string workDate) {
        this->workDate = workDate;
    }
    std::string getCompany() {
        return company;
    }
    void setCompany(std::string company) {
        this->company = company;
    }

    //clone
    WorkExprerience* Clone() {
        return new WorkExprerience(this);
    }
};

//原型类，声明一个克隆自身的接口。
class Prototype {
protected:
    std::string name;
    std::string sex;
    std::string age;
    std::string timeArea;
    std::string company;
public:
    virtual void SetPersonalInfo(std::string sex, std::string age) = 0;
    virtual void Display() = 0;
    virtual Prototype* Clone() = 0;
};

//具体原型类，即ConcretePrototype类，本例中为简历Resume类，实现一个克隆自身的操作
class Resume :public Prototype {
private:
    WorkExprerience* workExp;
public:
    Resume(std::string name) {
        this->name = name;
        workExp = new WorkExprerience();
    }
    ~Resume() {
        if (workExp != NULL)
            delete workExp;
    }
    //克隆需要的构造函数
    Resume(WorkExprerience* workExp) {
        this->workExp = workExp->Clone();
    }
    void SetPersonalInfo(std::string sex, std::string age) {
        this->sex = sex;
        this->age = age;
    }
    void SetWorkExperience(std::string company, std::string workDate) {
        workExp->setCompany(company);
        workExp->setWorkDate(workDate);
    }
    void Display() {
        std::cout << name << "  " << age << " " << sex << "  " << std::endl;
        std::cout << "工作经历  " << workExp->getWorkDate() << "  " << workExp->getCompany() << std::endl;
    }
    Resume* Clone() {
        Resume* clonedResume = new Resume(workExp);
        clonedResume->name = this->name;
        clonedResume->sex = this->sex;
        return clonedResume;
    }
};

int main() {
    Resume* a = new Resume("big bird");
    a->SetPersonalInfo("MAN", "");
    a->SetWorkExperience("1998-2000", "baidu");

    Resume* b = a->Clone();
    b->SetWorkExperience("2000-2008", "google");

    Resume* c = a->Clone();
    c->SetPersonalInfo("MAN", "");
    c->SetWorkExperience("2000-2008", "apple");

    a->Display();
    b->Display();
    c->Display();
    system("pause");
    return 0;
}