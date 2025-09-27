#pragma once
#include "afxwin.h"


// CDlgDeal 对话框

class CDlgDeal : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDeal)

public:
	CDlgDeal(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgDeal();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
public:
	void SetTip(CString str);
	void SetMaxCnt(int maxCnt);
	CString m_strTips;
	int m_comMaxCnt;//商品最大数量
	int m_commCnt;//商品数量
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_editDeal;
};
