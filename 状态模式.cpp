#include<iostream>
using namespace std;

class State;
class ForenoonState;
class NoonState;
class AfternonnState;
class EveningState;
class SleepingState;
class RestState;
class Work;

// 抽象状态角色，负责定义各个状态有哪些行为，该抽象状态包含所有具体状态的方法。并且封装环境角色，帮助切换状态。
class State
{
public:
	virtual void writeprogram(Work* w) = 0;
	virtual ~State() = default;
};
// Context 角色，在该类内部维护一个ConcreteState子类的一个实例，可以负责具体状态的切换
class Work
{
private:
	State* current;
	double m_hour;
	bool m_finish = false;
public:
	Work();
	~Work();
	void setHour(double hour) { m_hour = hour; }
	double getHour() { return m_hour; }

	void setFinish(bool finish) { m_finish = finish; }
	bool getFinish() { return m_finish; }
	void SetState(State* s)
	{
		delete current;
		current = s;
	}
	void WorkProgram()
	{
		current->writeprogram(this);
	}
};

// 下面都是具体的状态类，每一个具体状态类必须完成两个职责：该类本状态下要做的事情，以及如何执行到其他具体状态类的状态。
class ForenoonState :public State
{
public:
	void writeprogram(Work* w)override;
};

class NoonState :public State
{
public:
	void writeprogram(Work* w)override;
};

class AfternoonState :public State
{
public:
	void writeprogram(Work* w)override;
};

class EveningState :public State
{
public:
	void writeprogram(Work* w)override;
};

class SleepingState :public State
{// 睡眠状态
public:
	void writeprogram(Work* w)override;

};

class RestState :public State
{// 下班休息状态
public:
	void writeprogram(Work* w)override;

};

Work::Work()
{
	current = new ForenoonState();
}
Work::~Work()
{
	delete current;
}

void ForenoonState::writeprogram(Work* w)
{
	if (w->getHour() < 12)
	{
		cout << "当前时间：" << w->getHour() << "点，上午工作，精神百倍" << endl;
	}
	else
	{
		w->SetState(new NoonState());
		w->WorkProgram();
	}
}

void NoonState::writeprogram(Work* w)
{
	if (w->getHour() < 13)
	{
		cout << "当前时间：" << w->getHour() << "点，吃午饭，睡午觉" << endl;
	}
	else
	{
		w->SetState(new AfternoonState());
		w->WorkProgram();
	}
}

void AfternoonState::writeprogram(Work* w)
{
	if (w->getHour() < 17)
	{
		cout << "当前时间：" << w->getHour() << "点，下午状态还不错" << endl;
	}
	else
	{
		w->SetState(new EveningState());
		w->WorkProgram();
	}
}

void EveningState::writeprogram(Work* w)
{
	if (w->getFinish())
	{
		w->SetState(new RestState());
		w->WorkProgram();
	}
	else
	{
		if (w->getHour() < 21)
		{
			cout << "当前时间：" << w->getHour() << "点,加班哦，疲惫至极 " << endl;
		}
		else
		{
			w->SetState(new SleepingState());
			w->WorkProgram();
		}
	}
}

void SleepingState::writeprogram(Work* w)
{
	cout << "当前时间：" << w->getHour() << "点,不行了，睡着了 " << endl;
}

void RestState::writeprogram(Work* w)
{
	cout << "当前时间：" << w->getHour() << "点,下班回家了 " << endl;
}

int main()
{
	Work emergencyProjects;

	emergencyProjects.setHour(9);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(10);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(12);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(13);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(14);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(17);
	emergencyProjects.WorkProgram();

	emergencyProjects.setFinish(false);

	emergencyProjects.setHour(19);
	emergencyProjects.WorkProgram();

	emergencyProjects.setHour(22);
	emergencyProjects.WorkProgram();

	system("pause");
	return 0;
}