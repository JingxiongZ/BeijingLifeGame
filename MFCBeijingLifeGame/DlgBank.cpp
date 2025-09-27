// DlgBank.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBeijingLifeGame.h"
#include "DlgBank.h"
#include "afxdialogex.h"


// CDlgBank 对话框

IMPLEMENT_DYNAMIC(CDlgBank, CDialogEx)

CDlgBank::CDlgBank(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_BANK, pParent)
{

}

CDlgBank::~CDlgBank()
{
}

void CDlgBank::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SAVE, m_editSave);
	DDX_Control(pDX, IDC_EDIT_WITHDRAW, m_editWithDraw);
	DDX_Control(pDX, IDC_SPIN1, m_spinSave);
	DDX_Control(pDX, IDC_SPIN2, m_spinWithDraw);
}

void CDlgBank::SetCash(int cash)
{
	m_cash = cash;
	m_maxCash = cash;
}

void CDlgBank::SetDeposit(int deposit)
{
	m_deposit = deposit;
	m_maxDeposit = m_deposit;
}

BEGIN_MESSAGE_MAP(CDlgBank, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgBank::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgBank::OnBnClickedCancel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgBank::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CDlgBank::OnDeltaposSpin2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgBank::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgBank::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CDlgBank 消息处理程序


void CDlgBank::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDlgBank::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgBank::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_cash += pNMUpDown->iDelta;
	if (m_cash > m_maxCash)
	{
		m_cash = m_maxCash;
	}
	CString str;
	str.Format(L"%d", m_cash);
	m_editSave.SetWindowText(str);
}


void CDlgBank::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_deposit += pNMUpDown->iDelta;
	if (m_deposit > m_maxDeposit)
	{
		m_deposit = m_maxDeposit;
	}
	CString str;
	str.Format(L"%d", m_deposit);
	m_editWithDraw.SetWindowText(str);
}


void CDlgBank::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_editSave.EnableWindow(TRUE);
	m_spinSave.EnableWindow(TRUE);
	m_editWithDraw.EnableWindow(FALSE);
	m_spinWithDraw.EnableWindow(FALSE);
	m_saveOrWithDraw = true;
}


void CDlgBank::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_editSave.EnableWindow(FALSE);
	m_spinSave.EnableWindow(FALSE);
	m_editWithDraw.EnableWindow(TRUE);
	m_spinWithDraw.EnableWindow(TRUE);
	m_saveOrWithDraw = false;
}


BOOL CDlgBank::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString str;
	str.Format(L"%d", m_cash);
	m_editSave.SetWindowText(str);
	str.Format(L"%d", m_deposit);
	m_editWithDraw.SetWindowText(str);

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	OnBnClickedRadio1();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
