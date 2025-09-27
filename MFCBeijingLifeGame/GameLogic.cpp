#include "stdafx.h"
#include "GameLogic.h"

CString glocationName[LOCATION_CNT] = { L"苹果园", L"公主坟", L"复兴门", L"西直门", L"积水潭",
L"东直门",L"建国门",L"北京站",L"崇文门", L"长椿街" };

CommodityCfg gCommodityCfg[] = {
{1001,L"上海小宝贝",5000,7500},
{ 1002,L"走私汽车",20000,40000 },
{ 1003,L"盗版vcd",50,150 },
{ 1004,L"假白酒",100,300 },
{ 1005,L"进口玩具",50,200 },
{ 1006,L"水货手机",500,2000 },
{ 1007,L"劣质化妆品",100,500 },
{ 1008,L"国产香烟",800,1000 }
};

Event gEvent[] = {
	{ L"专家提议提高大学生“动手素质”",1005,2.0f },

	{ L"有人说：生病不用打针吃药，喝假白酒（剧毒）就可以!",1004,3.0f },

	{ L"医院的秘密报告：“《上海小宝贝》功效甚过伟哥”!",1001,4.0f },

	{ L"文盲说：“2000年诺贝尔文学奖？呸！不如盗版VCD港台片。”",1003,4.0f },

	{ L"《北京经济小报》社论：“走私汽车大力推进汽车消费!”",1002,3.0f },

	{ L"谢不疯在晚会上说：“我酷!我使用伪劣化妆品!”",1007,2.0f },

	{ L"市场上充斥着来自福建的走私香烟",1005,0.2f },

	{ L"北京的孩子们都忙于上网学习，进口玩具没人愿意买。",1005,0.16f },

	{ L"“中国硅谷”——中关村全是卖盗版VCD的村姑。",1003,0.25f },

	{ L"北京的富人疯狂地购买走私汽车！",1002,4.f },
};

GameLogic::GameLogic()
{
}


GameLogic::~GameLogic()
{
}

void GameLogic::Init()
{
	for (int i = 0; i < m_locatVec.size();i++)
	{
		m_locatVec[i].m_commodityVec.clear();
	}
	m_locatVec.clear();
	m_commodityVec.clear();

	for (int i = 0; i < 10;i++)
	{
		Location locat;
		locat.id = i;
		locat.strName = glocationName[i];
		m_locatVec.push_back(locat);
	}

	m_currLocation = 0;
	GenerateCommodity(m_currLocation);

	m_cash = 3000;
	m_arrears = 5400;
}

void GameLogic::GenerateCommodity(int localtion_id)
{
	if (localtion_id < 0 || localtion_id > LOCATION_CNT)
	{
		return;
	}

	Location& local = m_locatVec[localtion_id];
	local.m_commodityVec.clear();

	std::vector<int> result;
	GetRandomArray(result, COMMODITY_CNT);


	int cnt = rand() % (COMMODITY_MAX - COMMODITY_MIN) + COMMODITY_MIN;
	for (int i = 0; i < cnt; i++)
	{
		int commIdx = result[i];
		Commodity comm;
		comm.id = gCommodityCfg[commIdx].id;
		comm.strName = gCommodityCfg[commIdx].strName;
		//comm.cnt = rand() % 1000;
		comm.price = rand() % (gCommodityCfg[commIdx].priceMax - gCommodityCfg[commIdx].priceMin) + gCommodityCfg[commIdx].priceMin;

		local.m_commodityVec.push_back(comm);
	}
}

void GameLogic::GetRandomArray(std::vector<int>& result, int number)
{
	int i = 0, k = 0;
	//初始化
	for (i = 0; i < number; i++)
	{
		result.push_back(i);
	}

	//随机交换，产生随机数列
	srand((int)time(0));
	for (i = 0; i < number - 1; i++)
	{
		//随机性不是很好
		k = rand() % (number - i) + i;
		//交换k , i 位置
		int t = result.at(i);
		result[i] = result.at(k);
		result[k] = t;
	}
}

Location GameLogic::GetCurrLocation()
{
	return m_locatVec[m_currLocation];
}

Event GameLogic::GetCurrEvent()
{
	if (m_currEventId != -1)
	{
		return gEvent[m_currEventId];
	}
	return Event();
}

void GameLogic::DoStep(int location_id)
{
	m_day++;
	m_currLocation = location_id;

	GenerateCommodity(location_id);

	TriggerEvent();

	TriggerAchieve();

	TriggerHealth();
}

void GameLogic::Buy(int commIdx)
{

}

void GameLogic::Sell(int commIdx)
{

}

//触发事件
void GameLogic::TriggerEvent()
{
	m_currEventId = rand() % (EVENT_CNT + 5);
	if (m_currEventId >= EVENT_CNT)
	{
		m_currEventId = -1;
		return;//不触发事件
	}

	Event event = gEvent[m_currEventId];

	Location& local = m_locatVec[m_currLocation];

	for (int i = 0; i < local.m_commodityVec.size();i++)
	{
		if (local.m_commodityVec[i].id = event.comm_id)
		{
			local.m_commodityVec[i].price = local.m_commodityVec[i].price * event.value;
		}
	}

}
//触发成就
void GameLogic::TriggerAchieve()
{

}
//触发健康
void GameLogic::TriggerHealth()
{

}