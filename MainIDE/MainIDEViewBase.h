
// MainIDEView.h : CMainIDEViewBase ��Ľӿ�
//

#pragma once
#include "UIEditView.h"
#include "MainIDEDocBase.h"


class CMainIDEViewBase : public CUIEditView
{
protected: // �������л�����
	CMainIDEViewBase();
	DECLARE_DYNCREATE(CMainIDEViewBase)

	// ����
public:
	CMainIDEDocBase* GetDocument() const;
	virtual CUITextBuffer * LocateTextBuffer();

	// ����
public:
	void SetSelection(const CPoint &ptStart, const CPoint &ptEnd);
	void SelectLine( int line );

	// ��д
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// ʵ��
public:
	virtual ~CMainIDEViewBase();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL IsCKeyword(LPCTSTR pszChars, int nLength);
	BOOL IsCType(LPCTSTR pszChars, int nLength);
	BOOL IsCNumber(LPCTSTR pszChars, int nLength);

public:
	CMapStringToPtr m_mapKeywords;
	CMapStringToPtr m_mapTypes;

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();

	virtual DWORD ParseLine( DWORD dwCookie, int nLineIndex, TEXTBLOCK *pBuf, int &nActualItems );
	void InitHashMap();
};

#ifndef _DEBUG  // MainIDEView.cpp �еĵ��԰汾
inline CMainIDEDocBase* CMainIDEViewBase::GetDocument() const
{ return reinterpret_cast<CMainIDEDocBase*>(m_pDocument); }
#endif

