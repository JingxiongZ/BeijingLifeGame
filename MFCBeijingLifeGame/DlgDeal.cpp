// DlgDeal.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBeijingLifeGame.h"
#include "DlgDeal.h"
#include "afxdialogex.h"


// CDlgDeal 对话框

IMPLEMENT_DYNAMIC(CDlgDeal, CDialogEx)

CDlgDeal::CDlgDeal(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgDeal::~CDlgDeal()
{
}

void CDlgDeal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DEAL, m_editDeal);
}

void CDlgDeal::SetTip(CString str)
{
	m_strTips = str;
}

void CDlgDeal::SetMaxCnt(int maxCnt)
{
	m_comMaxCnt = maxCnt;
	m_commCnt = m_comMaxCnt;
}

BEGIN_MESSAGE_MAP(CDlgDeal, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgDeal::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgDeal::OnBnClickedCancel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgDeal::OnDeltaposSpin1)
END_MESSAGE_MAP()


// CDlgDeal 消息处理程序


BOOL CDlgDeal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_STATIC_TIP)->SetWindowText(m_strTips);

	CString str;
	str.Format(L"%d", m_commCnt);
	m_editDeal.SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgDeal::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str;
	m_editDeal.GetWindowText(str);
	m_commCnt = _ttoi(str);
	CDialogEx::OnOK();
}


void CDlgDeal::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgDeal::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_commCnt += pNMUpDown->iDelta;
	if (m_commCnt > m_comMaxCnt)
	{
		m_commCnt = m_comMaxCnt;
	}

	CString str;
	str.Format(L"%d", m_commCnt);
	m_editDeal.SetWindowText(str);
}
