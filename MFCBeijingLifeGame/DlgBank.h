#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgBank 对话框

class CDlgBank : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBank)

public:
	CDlgBank(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgBank();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_BANK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

public:
	int m_cash;
	int m_maxCash;
	int m_deposit;
	int m_maxDeposit;
	bool m_saveOrWithDraw;
public:
	void SetCash(int cash);
	void SetDeposit(int deposit);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_editSave;
	CEdit m_editWithDraw;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CSpinButtonCtrl m_spinSave;
	CSpinButtonCtrl m_spinWithDraw;
	virtual BOOL OnInitDialog();
};
