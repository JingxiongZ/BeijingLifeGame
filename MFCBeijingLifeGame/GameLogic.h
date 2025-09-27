#pragma once
#include <vector>


//地点个数
#define  LOCATION_CNT	10
//商品种类
#define COMMODITY_CNT	8
//每个地点商品种类范围
#define  COMMODITY_MIN  4
#define  COMMODITY_MAX  7

//事件个数
#define  EVENT_CNT		10
struct CommodityCfg
{
	int id;				//商品id
	CString strName;	//商品名称
	int priceMin;		//商品价格区间
	int priceMax;		//
};
//商品信息
struct Commodity
{
	int id;				//商品id
	CString strName;	//商品名称
	int cnt;			//数量
	int price;			//价格
};
//地点信息
struct Location
{
	int id;				//地点id
	CString strName;	//地点名称
	std::vector<Commodity> m_commodityVec;//商品列表
};

//事件信息
struct Event
{
	CString strName;	//事件叙述
	int comm_id;		//影响的商品
	float value;		//影响价格百分比   >1价格翻倍，小于1<价格下跌
};
class GameLogic
{
public:
	GameLogic();
	~GameLogic();
public:
	void Init();
	//按地点生成商品
	void GenerateCommodity(int localtion_id);
	//产生n个数的随机序列
	void GetRandomArray(std::vector<int>& result, int number);

	Location GetCurrLocation();
	Event GetCurrEvent();
	//执行一步
	void DoStep(int location_id);
	void Buy(int commIdx);
	void Sell(int commIdx);
	//触发事件
	void TriggerEvent();
	//触发成就
	void TriggerAchieve();
	//触发健康
	void TriggerHealth();

public:
	//玩家现金
	int m_cash;
	//玩家存款
	int m_deposit;
	//玩家欠债
	int m_arrears;
	//玩家健康
	//玩家成就

	//玩家商品列表
	std::vector<Commodity> m_commodityVec;
	//地点列表
	std::vector<Location> m_locatVec;
	//当前地点
	int m_currLocation;

	//持续天数
	int m_day;
	//当前事件
	int m_currEventId;
};

