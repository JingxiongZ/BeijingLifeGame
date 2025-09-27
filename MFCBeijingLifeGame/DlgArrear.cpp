// DlgArrear.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBeijingLifeGame.h"
#include "DlgArrear.h"
#include "afxdialogex.h"


// CDlgArrear 对话框

IMPLEMENT_DYNAMIC(CDlgArrear, CDialogEx)

CDlgArrear::CDlgArrear(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_ARREAR, pParent)
{

}

CDlgArrear::~CDlgArrear()
{
}

void CDlgArrear::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ARREARS, m_staticArrear);
	DDX_Control(pDX, IDC_EDIT1, m_editArrear);
}

void CDlgArrear::SetArrear(int arrear)
{
	m_arrear = arrear;
}

void CDlgArrear::SetArrearTips(CString str)
{
	m_arrearTips = str;
}

BEGIN_MESSAGE_MAP(CDlgArrear, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgArrear::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgArrear::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgArrear 消息处理程序


BOOL CDlgArrear::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_staticArrear.SetFont(200, L"雅黑");
	m_staticArrear.SetWindowText(m_arrearTips);
	CString str;
	str.Format(L"%d", m_arrear);
	m_editArrear.SetWindowText(str);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgArrear::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_editArrear.GetWindowText(str);
	m_arrear = _ttoi(str);
	CDialogEx::OnOK();
}


void CDlgArrear::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
