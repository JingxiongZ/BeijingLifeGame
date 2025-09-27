#pragma once
#include "afxwin.h"

#include "TextStatic.h"

// CDlgInfo 对话框

class CDlgInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInfo)

public:
	CDlgInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CTextStatic m_staticTitle;
	CEdit m_editStory;
};
