// 桥接模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


class HandsetSoft  // 手机软件
{
public:
	virtual ~HandsetSoft() = default;
	virtual void Run() = 0;
};

class HandsetGame : public HandsetSoft // 手机游戏
{
public:
	void Run()override
	{
		cout << "运行手机游戏！" << endl;
	}
};

class HandsetAddressList : public HandsetSoft //手机通讯录
{
public:
	void Run()override
	{
		cout << "运行手机通讯录！" << endl;
	}
};


class HandsetBrand // 手机品牌类
{
protected:
	HandsetSoft* m_soft; //手机品牌中包含着手机通讯录和手机游戏
public:
	virtual ~HandsetBrand() = default;
	void SetHandsetSoft(HandsetSoft* soft)
	{
		m_soft = soft;
	}
	virtual void Run() = 0;
};

class HandsetBrandN : public HandsetBrand  // 手机品牌 N
{
public:
	void Run()override
	{
		m_soft->Run();
	}
};

class HandsetBrandM : public HandsetBrand  // 手机品牌M
{
public:
	void Run()override
	{
		m_soft->Run();
	}
};

int main()
{
	cout << "手机品牌N：" << endl;
	HandsetBrand* abn = new HandsetBrandN();
	HandsetGame* hgn = new HandsetGame();
	abn->SetHandsetSoft(hgn);
	abn->Run();

	HandsetAddressList* haln = new HandsetAddressList();

	abn->SetHandsetSoft(haln);
	abn->Run();

	cout << endl << "手机品牌M：" << endl;
	HandsetBrand* abm = new HandsetBrandM();
	HandsetGame* hgm = new HandsetGame();
	abm->SetHandsetSoft(hgm);
	abm->Run();

	HandsetAddressList* halm = new HandsetAddressList();
	abm->SetHandsetSoft(halm);
	abm->Run();
	delete abn;
	delete hgn;
	delete haln;
	delete abm;
	delete hgm;
	delete halm;
	system("pause");
	return 0;
}