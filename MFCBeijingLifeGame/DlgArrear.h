#pragma once
#include "afxwin.h"

#include "TextStatic.h"

// CDlgArrear 对话框

class CDlgArrear : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgArrear)

public:
	CDlgArrear(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgArrear();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ARREAR };
#endif
public:
	int m_arrear;
	CString m_arrearTips;
	void SetArrear(int arrear);
	void SetArrearTips(CString str);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTextStatic m_staticArrear;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CEdit m_editArrear;
};
