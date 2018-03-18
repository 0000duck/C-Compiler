
// MainIDEView.cpp : CMainIDEViewBase ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "Logic.h"
#include "MainIDEViewBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainIDEViewBase

IMPLEMENT_DYNCREATE(CMainIDEViewBase, CUIEditView)

BEGIN_MESSAGE_MAP(CMainIDEViewBase, CUIEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMainIDEViewBase ����/����

CMainIDEViewBase::CMainIDEViewBase()
{
	// TODO: �ڴ˴���ӹ������
}

CMainIDEViewBase::~CMainIDEViewBase()
{
}

// CMainIDEViewBase ��ӡ


void CMainIDEViewBase::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMainIDEViewBase::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return CUIEditView::OnPreparePrinting(pInfo);
}

void CMainIDEViewBase::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
	CUIEditView::OnBeginPrinting(pDC, pInfo);
}

void CMainIDEViewBase::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: ��Ӵ�ӡ����е��������
	CUIEditView::OnEndPrinting(pDC, pInfo);
}

void CMainIDEViewBase::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
	CUIEditView::OnRButtonUp(nFlags, point);
}

void CMainIDEViewBase::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMainIDEViewBase ���

#pragma region DEBUG
#ifdef _DEBUG
void CMainIDEViewBase::AssertValid() const
{
	CView::AssertValid();
}

void CMainIDEViewBase::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

#endif //_DEBUG
#pragma endregion DEBUG

CMainIDEDocBase* CMainIDEViewBase::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMainIDEDocBase)));
	return (CMainIDEDocBase*)m_pDocument;
}

void CMainIDEViewBase::SetSelection( const CPoint &ptStart, const CPoint &ptEnd )
{
	CUITextView::SetSelection(ptStart,ptEnd);
}

void CMainIDEViewBase::SelectLine( int line )
{
	CUITextBuffer* pBuffer = &((CMainIDEDocBase*)GetDocument())->m_TextBuffer;
	ASSERT( pBuffer );

	if( line < 1 ) line = 1;
	if( line > pBuffer->GetLineCount() ) line = pBuffer->GetLineCount();

	WINDOWPLACEMENT pl;
	GetWindowPlacement( &pl );
	pl.flags = WPF_RESTORETOMAXIMIZED;
	pl.showCmd = SW_SHOWMAXIMIZED;
	SetWindowPlacement( &pl );
	this->SetFocus();
	SetSelection( CPoint(0, line - 1),
		CPoint(pBuffer->GetLineLength(line-1), line - 1) );
	SetCursorPos( CPoint(pBuffer->GetLineLength(line - 1), line - 1) );
	EnsureVisible( CPoint(pBuffer->GetLineLength(line - 1), line - 1) );
}

CUITextBuffer * CMainIDEViewBase::LocateTextBuffer()
{
	return &((CMainIDEDocBase*)GetDocument())->m_TextBuffer;
}


// CMainIDEViewBase ��Ϣ�������


void CMainIDEViewBase::OnInitialUpdate()
{
	CUIEditView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	InitHashMap();
	SetFont(((CMainIDEDocBase*)GetDocument())->m_lf);
}

void CMainIDEViewBase::InitHashMap()
{
	using namespace Logic_Global;
	LPTSTR* s_apszCKeywordList = Logic_GetKeywords();
	LPTSTR* s_apszCTypeList = Logic_GetTypes();

	for( int L = 0; s_apszCKeywordList[L] != NULL; L++ ) {
		m_mapKeywords[s_apszCKeywordList[L]] = NULL;
	}
	for( int L = 0; s_apszCTypeList[L] != NULL; L++ ) {
		m_mapTypes[s_apszCTypeList[L]] = NULL;
	}
}
