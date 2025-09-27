// TextStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "TextStatic.h"


COLORREF colorBkg = RGB(113, 184, 255);//整体背景色
COLORREF colorTxt = RGB(0, 0, 0);//文字
// CTextStatic

IMPLEMENT_DYNAMIC(CTextStatic, CStatic)

CTextStatic::CTextStatic()
{

}

CTextStatic::~CTextStatic()
{
}


void CTextStatic::SetWindowText(LPCTSTR lpszText)
{
	CStatic::SetWindowText(lpszText);
	Invalidate(TRUE);
}
void CTextStatic::SetFont(int font_width, LPCTSTR lpszFontName)
{
	m_font.DeleteObject();
	m_font.CreatePointFont(font_width, lpszFontName);
}

CPoint CTextStatic::CenterAlign(CDC* pdc, CRect rclient, CString str, int mode)
{
	CPoint pt;

	CSize size = pdc->GetTextExtent(str);
	pt.x = round((rclient.Width() - size.cx) * 1.0f / 2);
	switch (mode)
	{
	case 0://单行水平垂直居中
		pt.y = round((rclient.Height() - size.cy) *1.0f / 2);
		break;
	case 1://单行水平居中,垂直靠上
		pt.y = round((rclient.Height()*0.65 - size.cy) *1.0f / 2);
		break;
	case 2://单行水平居中,垂直靠下
		pt.y = round((rclient.Height()*1.45 - size.cy) *1.0f / 2);
		break;
	default:
		break;
	}

	return pt;
}

BEGIN_MESSAGE_MAP(CTextStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CTextStatic 消息处理程序




void CTextStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CStatic::OnPaint()
	CRect rclient;
	GetClientRect(rclient);

	CDC memdc;
	CBitmap bitmap;
	memdc.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, rclient.Width(), rclient.Height());
	CBitmap* pOldmap = memdc.SelectObject(&bitmap);


	//绘制背景颜色
	memdc.FillSolidRect(rclient, colorBkg);

	//绘制文字
	memdc.SetTextColor(colorTxt);

	CString str;
	GetWindowText(str);
	memdc.SelectObject(&m_font);
	CPoint pt = CenterAlign(&memdc, rclient, str, 0);
	memdc.TextOut(pt.x, pt.y, str);

	//拷贝内存dc
	dc.BitBlt(rclient.left, rclient.top, rclient.Width(), rclient.Height(), &memdc, 0, 0, SRCCOPY);

	memdc.SelectObject(pOldmap);
	bitmap.DeleteObject();
	memdc.DeleteDC();
}
