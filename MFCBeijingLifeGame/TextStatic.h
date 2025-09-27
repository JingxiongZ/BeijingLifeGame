#pragma once


// CTextStatic

class CTextStatic : public CStatic
{
	DECLARE_DYNAMIC(CTextStatic)

public:
	CTextStatic();
	virtual ~CTextStatic();
public:
	CFont m_font;
public:
	void SetWindowText(LPCTSTR lpszText);
	void SetFont(int font_width, LPCTSTR lpszFontName);
	CPoint CenterAlign(CDC* pdc, CRect rclient, CString str, int mode);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


