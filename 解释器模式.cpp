#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>
using namespace std;

//抽象表达式类 声明一个抽象的解释操作，这个接口为抽象语法树中的所有的结点共享
class Expression
{
public:
	virtual bool Interpret(const std::string& info) = 0;
};

//终结符表达式类 实现与文法中的终结符相关联的解释操作
class TerminalExpressin : public Expression
{
private:
	std::set<std::string> infos;

public:
	TerminalExpressin(const std::vector<std::string> datas)
	{
		infos.insert(datas.begin(), datas.end());
	}

	bool Interpret(const std::string& info)
	{
		if (infos.find(info) != infos.end())
			return true;
		return false;
	}
};

//非终结符表达式类 为文法中的非终结符实现解释操作。对文法中每一条规则R1、R2....Rn都需要一个具体的非终结符表达式类
//通过实现抽象表达式的interpret()方法实现解释操作.解释操作以递归方式调用上面所提到的代表R1、R2....Rn中各个符号的实例遍历
class AndExpression : public Expression
{
private:
	std::shared_ptr<Expression> smartCity;
	std::shared_ptr<Expression> smartPerson;

public:
	AndExpression(std::shared_ptr<Expression> city, std::shared_ptr<Expression> person) : smartCity(city), smartPerson(person) {}

	bool Interpret(const std::string& info)
	{
		std::regex pattern("的");
		std::vector<std::string> results(std::sregex_token_iterator(info.begin(), info.end(), pattern, -1), std::sregex_token_iterator());
		if (results.size() != 2)
		{
			std::cout << "输入解释信息有误，无法解析！" << std::endl;
			return false;
		}
		return smartCity->Interpret(results[0]) && smartPerson->Interpret(results[1]); //得到的两个名字 
	}
};

//上下文全局信息类  包括解释器之外的一些全局信息
class Context {
private:
	std::vector<std::string> citys;
	std::vector<std::string> persons;
	std::shared_ptr<Expression> smartAndExpr;

public:
	Context()
	{
		citys.push_back("成都");
		citys.push_back("临沂");
		persons.push_back("老人");
		persons.push_back("儿童");
		smartAndExpr = std::make_shared<AndExpression>(std::make_shared<TerminalExpressin>(citys), std::make_shared<TerminalExpressin>(persons));
	}

	void IsFree(const std::string& info)
	{
		if (smartAndExpr->Interpret(info))
		{
			std::cout << info << " , 您本次乘车免费" << std::endl;
		}
		else
		{
			std::cout << info << ", 您本次乘车扣费2￥" << std::endl;
		}
	}
};

int main()
{
	std::shared_ptr<Context> bus = std::make_shared<Context>();
	std::vector<std::string> passengers = { "成都的老人" , "成都的年轻人" , "成都的儿童" , "临沂的老人" , "临沂的年轻人" , "临沂的儿童" };
	for (std::string passenger : passengers)
	{
		bus->IsFree(passenger);
	}

	system("pause");
	return 0;
}