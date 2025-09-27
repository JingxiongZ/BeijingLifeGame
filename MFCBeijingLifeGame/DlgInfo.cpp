// DlgInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBeijingLifeGame.h"
#include "DlgInfo.h"
#include "afxdialogex.h"


// CDlgInfo 对话框

IMPLEMENT_DYNAMIC(CDlgInfo, CDialogEx)

CDlgInfo::CDlgInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_INFO, pParent)
{

}

CDlgInfo::~CDlgInfo()
{
}

void CDlgInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_staticTitle);
	DDX_Control(pDX, IDC_EDIT_STORT, m_editStory);
}


BEGIN_MESSAGE_MAP(CDlgInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgInfo::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgInfo::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgInfo 消息处理程序


BOOL CDlgInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_staticTitle.SetFont(600, L"幼圆");
	m_staticTitle.SetWindowText(L"北京浮生记");

	m_editStory.SetWindowText(L"       你从家乡来到北京，举目无亲，仅剩下现金2000元,同时还欠\r\n\
村长5400高利贷。自己动手丰衣足食考虑再三，你决定来到北京\r\n\
做生意，每天在各个地铁站倒卖物品。你只能在北京待40天，然\r\n\
后回老家结婚。你的目标是在这40天里还掉高利贷，而且要赚大\r\n\
钱。但是发财并不容易，北京的小偷，流氓，坏人，工商局，高\r\n\
利贷，卫生局的人都会找你的麻烦。您必须与他们斗智斗勇。");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgInfo::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDlgInfo::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
