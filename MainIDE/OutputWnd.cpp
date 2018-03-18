
#include "stdafx.h"

#include "OutputWnd.h"
#include "Resource.h"
#include "MainFrm.h"
#include <atlconv.h>
#include "..\MainLogic\Logic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputBar

COutputWnd::COutputWnd()
{
}

COutputWnd::~COutputWnd()
{
}

BEGIN_MESSAGE_MAP(COutputWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int COutputWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// ����ѡ�����:
	if (!m_wndTabs.Create(CMFCTabCtrl::STYLE_FLAT, rectDummy, this, 1))
	{
		TRACE("δ�ܴ������ѡ�����\n");
		return -1;      // δ�ܴ���
	}

	// �����������:
	const DWORD dwStyle = LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL |
		ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_LEFT | ES_READONLY;

	if (!m_wndRichEdit.Create(dwStyle, rectDummy, &m_wndTabs, 2))
	{
		TRACE("δ�ܴ����������\n");
		return -1;      // δ�ܴ���
	}

	m_wndRichEdit.SetOwner(this);

	CString strTabName;
	BOOL bNameValid;

	// ���б��ڸ��ӵ�ѡ�:
	bNameValid = strTabName.LoadString(IDS_OUTPUT_TAB);
	ASSERT(bNameValid);
	m_wndTabs.AddTab(&m_wndRichEdit, strTabName, (UINT)0);

	return 0;
}

void COutputWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// ѡ��ؼ�Ӧ��������������:
	m_wndTabs.SetWindowPos (NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

void COutputWnd::AdjustHorzScroll(CListBox& wndListBox)
{
	CClientDC dc(this);
	CFont* pOldFont = dc.SelectObject(&afxGlobalData.fontRegular);

	int cxExtentMax = 0;

	for (int i = 0; i < wndListBox.GetCount(); i ++)
	{
		CString strItem;
		wndListBox.GetText(i, strItem);

		cxExtentMax = max(cxExtentMax, dc.GetTextExtent(strItem).cx);
	}

	wndListBox.SetHorizontalExtent(cxExtentMax);
	dc.SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// COutputCtrl

COutputCtrl::COutputCtrl()
{

}

COutputCtrl::~COutputCtrl()
{

}

BEGIN_MESSAGE_MAP(COutputCtrl, CRichEditCtrl)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_VIEW_OUTPUTWND, OnViewOutput)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputCtrl ��Ϣ�������

int COutputCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CRichEditCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = -14;
	lf.lfWeight = FW_NORMAL;
	_tcscpy( lf.lfFaceName, _T("������") );
	m_fontOutput.CreateFontIndirect(&lf);

	SetFont(&m_fontOutput);
	SetUndoLimit(0);
	AddColorText(_T("����ɹ�������"), RGB(0, 0, 255));

	// Attach output interface
	Logic_SetInterface(this);

	return 0;
}

void COutputCtrl::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_OUTPUT_POPUP);

	CMenu* pSumMenu = menu.GetSubMenu(0);

	if (AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

		if (!pPopupMenu->Create(this, point.x, point.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
			return;

		((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
		UpdateDialogControls(this, FALSE);
	}

	SetFocus();
}

void COutputCtrl::Clear()
{
	SetSel( 0, -1 );			// ȫѡ
	ReplaceSel( NULL );			// �滻�ɿ�
}

void COutputCtrl::AddColorText( LPCTSTR pstrText, COLORREF color )
{
	static CHARFORMAT cf;
	cf.cbSize		= sizeof(CHARFORMAT);
	cf.dwMask		= CFM_COLOR;
	cf.dwEffects	&= ~CFE_AUTOCOLOR;
	cf.crTextColor	= color;

	SetSel( -1, -1 );
	SetWordCharFormat(cf);
	ReplaceSel( pstrText );

	PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
}

void COutputCtrl::OnEditCopy()
{
	Copy();
}

void COutputCtrl::OnEditClear()
{
	Clear();
}

void COutputCtrl::OnViewOutput()
{
	CDockablePane* pParentBar = DYNAMIC_DOWNCAST(CDockablePane, GetOwner());
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());

	if (pMainFrame != NULL && pParentBar != NULL)
	{
		pMainFrame->SetFocus();
		pMainFrame->ShowPane(pParentBar, FALSE, FALSE, FALSE);
		pMainFrame->RecalcLayout();

	}
}

void COutputCtrl::Output( LPCTSTR pstrText )
{
	AddColorText(pstrText, RGB(255, 0, 0));
	AddColorText( _T("\r\n") );
}

void COutputCtrl::Trace( LPCTSTR pstrText )
{
	AddColorText(pstrText, RGB(0, 0, 255));
	AddColorText( _T("\r\n") );
}
