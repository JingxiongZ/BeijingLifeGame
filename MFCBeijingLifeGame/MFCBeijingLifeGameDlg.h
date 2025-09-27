
// MFCBeijingLifeGameDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "GameLogic.h"
#include "TextStatic.h"

// CMFCBeijingLifeGameDlg 对话框
class CMFCBeijingLifeGameDlg : public CDialogEx
{
// 构造
public:
	CMFCBeijingLifeGameDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBEIJINGLIFEGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	GameLogic m_gameLogic;
	//显示商品
	void ShowCurrLocation();
	//显示玩家信息
	void ShowPlayerInfo();
	//显示发生事件
	void ShowEvent();
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTextStatic m_staticTitle;
	CListCtrl m_listMarket;
	CListCtrl m_listMyStore;
	CTextStatic m_staticCash;
	CTextStatic m_staticDeposit;
	CTextStatic m_staticArrears;
	CTextStatic m_staticHealth;
	CTextStatic m_staticAchieve;
	afx_msg void OnBnClickedBtn(UINT uID);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedBtnBank();
	afx_msg void OnBnClickedBtnPost();
	afx_msg void OnBnClickedBtnExit();
};
