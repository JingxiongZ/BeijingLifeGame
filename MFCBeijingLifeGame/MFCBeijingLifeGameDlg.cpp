
// MFCBeijingLifeGameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBeijingLifeGame.h"
#include "MFCBeijingLifeGameDlg.h"
#include "afxdialogex.h"

#include "DlgInfo.h"
#include "DlgDeal.h"
#include "DlgBank.h"
#include "DlgArrear.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMFCBeijingLifeGameDlg 对话框



CMFCBeijingLifeGameDlg::CMFCBeijingLifeGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCBEIJINGLIFEGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBeijingLifeGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_staticTitle);
	DDX_Control(pDX, IDC_LIST_MARKET, m_listMarket);
	DDX_Control(pDX, IDC_LIST_MY_STORE, m_listMyStore);
	DDX_Control(pDX, IDC_STATIC_CASH, m_staticCash);
	DDX_Control(pDX, IDC_STATIC_DEPOSIT, m_staticDeposit);
	DDX_Control(pDX, IDC_STATIC_ARREARS, m_staticArrears);
	DDX_Control(pDX, IDC_STATIC_HEALTH, m_staticHealth);
	DDX_Control(pDX, IDC_STATIC_ACHIEVE, m_staticAchieve);
}

void CMFCBeijingLifeGameDlg::ShowCurrLocation()
{
	m_listMarket.DeleteAllItems();

	Location currLocal = m_gameLogic.GetCurrLocation();

	for (int i = 0; i < currLocal.m_commodityVec.size(); i++)
	{
		m_listMarket.InsertItem(i, currLocal.m_commodityVec[i].strName);
		CString strPrice;
		strPrice.Format(L"%d", currLocal.m_commodityVec[i].price);
		m_listMarket.SetItemText(i, 1, strPrice);
	}
}

void CMFCBeijingLifeGameDlg::ShowPlayerInfo()
{
	CString str;
	str.Format(L"%d", m_gameLogic.m_cash);
	m_staticCash.SetWindowText(str);

	str.Format(L"%d", m_gameLogic.m_deposit);
	m_staticDeposit.SetWindowText(str);

	str.Format(L"%d", m_gameLogic.m_arrears);
	m_staticArrears.SetWindowText(str);


	m_listMyStore.DeleteAllItems();
	for (int i = 0; i < m_gameLogic.m_commodityVec.size();i++)
	{
		m_listMyStore.InsertItem(i, m_gameLogic.m_commodityVec[i].strName);
		CString str;

		str.Format(L"%d", m_gameLogic.m_commodityVec[i].price);
		m_listMyStore.SetItemText(i, 1, str);

		str.Format(L"%d", m_gameLogic.m_commodityVec[i].cnt);
		m_listMyStore.SetItemText(i, 2, str);
	}
}

void CMFCBeijingLifeGameDlg::ShowEvent()
{
	Event event = m_gameLogic.GetCurrEvent();
	if (m_gameLogic.m_currEventId != -1)
	{
		MessageBox(event.strName, L"提示", MB_OK);
	}
}

BEGIN_MESSAGE_MAP(CMFCBeijingLifeGameDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED,IDC_BTN_1, IDC_BTN_10, &CMFCBeijingLifeGameDlg::OnBnClickedBtn)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCBeijingLifeGameDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCBeijingLifeGameDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BTN_BANK, &CMFCBeijingLifeGameDlg::OnBnClickedBtnBank)
	ON_BN_CLICKED(IDC_BTN_POST, &CMFCBeijingLifeGameDlg::OnBnClickedBtnPost)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CMFCBeijingLifeGameDlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


// CMFCBeijingLifeGameDlg 消息处理程序

BOOL CMFCBeijingLifeGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CDlgInfo  infoDlg;
	if (infoDlg.DoModal() != IDOK)
	{
		CDialogEx::OnCancel();
		return TRUE;
	}

	m_staticCash.SetFont(200, L"雅黑");
	m_staticDeposit.SetFont(200, L"雅黑");
	m_staticArrears.SetFont(200, L"雅黑");
	m_staticHealth.SetFont(200, L"雅黑");
	m_staticAchieve.SetFont(200, L"雅黑");
	m_staticTitle.SetFont(300, L"隶书");
	CRect  rcRect;
	GetClientRect(rcRect);
	m_listMarket.GetClientRect(rcRect);
	m_listMarket.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listMarket.InsertColumn(0, L"商品", LVCFMT_LEFT, rcRect.Width() / 2);
	m_listMarket.InsertColumn(1, L"价格", LVCFMT_LEFT, rcRect.Width() / 2);

	rcRect;
	GetClientRect(rcRect);
	m_listMyStore.GetClientRect(rcRect);
	m_listMyStore.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listMyStore.InsertColumn(0, L"商品", LVCFMT_LEFT, rcRect.Width() / 3);
	m_listMyStore.InsertColumn(1, L"买入价格", LVCFMT_LEFT, rcRect.Width() / 3);
	m_listMyStore.InsertColumn(2, L"库存数量", LVCFMT_LEFT, rcRect.Width() / 3);


	m_gameLogic.Init();
	for (int i = 0; i < LOCATION_CNT; i++)
	{
		GetDlgItem(IDC_BTN_1 + i)->SetWindowText(m_gameLogic.m_locatVec[i].strName);
	}

	ShowCurrLocation();
	ShowPlayerInfo();

	CString strStep;
	strStep.Format(L"北京浮生记 第%d天", m_gameLogic.m_day + 1);
	m_staticTitle.SetWindowText(strStep);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCBeijingLifeGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCBeijingLifeGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCBeijingLifeGameDlg::OnBnClickedBtn(UINT uId)
{
	// TODO: 在此添加控件通知处理程序代码
	int localId = uId - IDC_BTN_1;

	m_gameLogic.DoStep(localId);
	ShowCurrLocation();
	ShowEvent();

	CString strStep;
	strStep.Format(L"北京浮生记 第%d天", m_gameLogic.m_day + 1);
	m_staticTitle.SetWindowText(strStep);
}


void CMFCBeijingLifeGameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//buy
	POSITION pos = m_listMarket.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(L"请选择", L"提示", MB_OK);
		return;
	}
	int item = m_listMarket.GetNextSelectedItem(pos);

	Commodity comm = m_gameLogic.GetCurrLocation().m_commodityVec[item];

	int maxCnt = m_gameLogic.m_cash / comm.price;
	if (maxCnt==0)
	{
		MessageBox(L"你的钱不够，再努力", L"提示", MB_OK);
		return;
	}
	CDlgDeal dealDlg;

	dealDlg.SetMaxCnt(maxCnt);
	CString str;

	str.Format(L"您当前的现金是=%d,最多可以购买=%d个%s", m_gameLogic.m_cash, maxCnt, comm.strName);
	dealDlg.SetTip(str);

	if (dealDlg.DoModal() != IDOK)
	{
		return;
	}
	if (dealDlg.m_commCnt == 0 ||dealDlg.m_commCnt >maxCnt)
	{
		return;
	}

	m_gameLogic.m_cash -= comm.price * dealDlg.m_commCnt;

	comm.cnt = dealDlg.m_commCnt;
	m_gameLogic.m_commodityVec.push_back(comm);

	ShowPlayerInfo();

}


void CMFCBeijingLifeGameDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//sell
	POSITION pos = m_listMyStore.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(L"请选择", L"提示", MB_OK);
		return;
	}
	int item = m_listMyStore.GetNextSelectedItem(pos);

	Commodity& comm = m_gameLogic.m_commodityVec[item];

	int maxCnt =comm.cnt;
	if (maxCnt == 0)
	{
		MessageBox(L"你的钱不够，再努力", L"提示", MB_OK);
		return;
	}

	//找到当前价格
	int price = 0;
	Location local = m_gameLogic.GetCurrLocation();
	for (int i = 0; i < local.m_commodityVec.size(); i++)
	{
		if (local.m_commodityVec[i].id == comm.id)
		{
			price = local.m_commodityVec[i].price;
			break;
		}
	}
	if (price == 0)
	{
		MessageBox(L"此地不买卖此商品", MB_OK);
		return;
	}

	CDlgDeal dealDlg;

	dealDlg.SetMaxCnt(maxCnt);
	CString str;

	str.Format(L"最多可以出售=%d个%s", maxCnt, comm.strName);
	dealDlg.SetTip(str);

	if (dealDlg.DoModal() != IDOK)
	{
		return;
	}
	if (dealDlg.m_commCnt == 0 || dealDlg.m_commCnt > maxCnt)
	{
		return;
	}

	m_gameLogic.m_cash += price * dealDlg.m_commCnt;

	comm.cnt -= dealDlg.m_commCnt;
	if (comm.cnt == 0)
	{
		m_gameLogic.m_commodityVec.erase(m_gameLogic.m_commodityVec.begin() + item);
	}

	ShowPlayerInfo();
}


void CMFCBeijingLifeGameDlg::OnBnClickedBtnBank()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgBank bankDlg;
	bankDlg.SetCash(m_gameLogic.m_cash);
	bankDlg.SetDeposit(m_gameLogic.m_deposit);
	if (bankDlg.DoModal() != IDOK)
	{
		return;
	}

	if (bankDlg.m_saveOrWithDraw)
	{
		m_gameLogic.m_cash -= bankDlg.m_cash;
		m_gameLogic.m_deposit += bankDlg.m_cash;
	}
	else
	{
		m_gameLogic.m_deposit -= bankDlg.m_deposit;
		m_gameLogic.m_cash += bankDlg.m_deposit;
	}
	ShowPlayerInfo();
}


void CMFCBeijingLifeGameDlg::OnBnClickedBtnPost()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgArrear arrearDlg;
	if (m_gameLogic.m_cash > m_gameLogic.m_arrears)
	{
		arrearDlg.SetArrear(m_gameLogic.m_arrears);
	}
	else
	{
		arrearDlg.SetArrear(m_gameLogic.m_cash);
	}

	CString str;
	str.Format(L"你的欠款金额=%d", m_gameLogic.m_arrears);
	arrearDlg.SetArrearTips(str);
	if (arrearDlg.DoModal() != IDOK)
	{
		return;
	}
	if (arrearDlg.m_arrear > m_gameLogic.m_arrears || arrearDlg.m_arrear > m_gameLogic.m_cash)
	{
		MessageBox(L"输入正确还款金额", MB_OK);
		return;
	}

	m_gameLogic.m_arrears -= arrearDlg.m_arrear;
	m_gameLogic.m_cash -= arrearDlg.m_arrear;
	ShowPlayerInfo();
}
void CMFCBeijingLifeGameDlg::OnBnClickedBtnExit()
{
	if (m_gameLogic.m_arrears == 0)
	{
		MessageBox(L"胡楠还款成功实现财务自由！");
	}
	else
	{
		MessageBox(L"胡楠欠了一屁股债=_=!!!");
	}
	CDialogEx::OnCancel();
}
