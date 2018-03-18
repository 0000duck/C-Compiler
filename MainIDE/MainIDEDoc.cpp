
// MainIDEDoc.cpp : CMainIDEDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "MainIDEDoc.h"

#include <propkey.h>
#include "MainIDEView.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "ExListDlg.h"
#include "ExTreeDlg.h"
#include "Logic.h"
#include "Initial.h"
#include "Lexer.h"
#include "Parser.h"
#include "Analyzer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainIDEDoc

IMPLEMENT_DYNCREATE(CMainIDEDoc, CMainIDEDocBase)

BEGIN_MESSAGE_MAP(CMainIDEDoc, CMainIDEDocBase)
	ON_COMMAND(ID_COMPILE_LEXER, &CMainIDEDoc::OnCompileScan)
	ON_COMMAND(ID_COMPILE_PARSE, &CMainIDEDoc::OnCompileParse)
	ON_COMMAND(ID_COMPILE_SYMBOL, &CMainIDEDoc::OnCompileSymbol)
	ON_COMMAND(ID_COMPILE_PCODE, &CMainIDEDoc::OnCompilePcode)
	ON_COMMAND(ID_COMPILE_ASM, &CMainIDEDoc::OnCompileAsm)
	ON_COMMAND(ID_COMPILE_CHECK, &CMainIDEDoc::OnCompileCheck)
END_MESSAGE_MAP()


// CMainIDEDoc ����/����

CMainIDEDoc::CMainIDEDoc()
{
	m_pApp = static_cast<CMainIDEApp*>(AfxGetApp());
	ASSERT(m_pApp);
}

CMainIDEDoc::~CMainIDEDoc()
{
}

void CMainIDEDoc::OnCompileScan()
{
	CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT(pMainFrame); ASSERT_KINDOF(CMainFrame, pMainFrame);

	CString strBuf;
	m_TextBuffer.GetText( 0, 0, m_TextBuffer.GetLineCount() - 1,
		m_TextBuffer.GetLineLength(m_TextBuffer.GetLineCount() - 1), strBuf );
	if( strBuf.IsEmpty() ) return;

	COutputCtrl& console = pMainFrame->m_wndOutput.m_wndRichEdit;
	console.Clear();
	Logic_SetErrorFlag(FALSE);

	LIST_ARRAY data;
	Logic_SetDataPtr(&data); // global set data ptr
	CLexer lexer( strBuf );
	if (!lexer.Run()) return;

	// show dialog
	CExListDlg dlg;
	dlg.SetInterface(&Logic_Class::exInitScanner);
	dlg.DoModal();
}

void CMainIDEDoc::OnCompileParse()
{
	CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT(pMainFrame); ASSERT_KINDOF(CMainFrame, pMainFrame);

	CString strBuf;
	m_TextBuffer.GetText( 0, 0, m_TextBuffer.GetLineCount() - 1,
		m_TextBuffer.GetLineLength(m_TextBuffer.GetLineCount() - 1), strBuf );
	if( strBuf.IsEmpty() ) return;

	COutputCtrl& console = pMainFrame->m_wndOutput.m_wndRichEdit;
	console.Clear();
	Logic_SetErrorFlag(FALSE);

	CParser parser( strBuf );
	CTreeNode* node = parser.BuildSyntaxTree();
	if (!node) return;
	Logic_Class::exInitTree.SetNode(node);

	// show dialog
	CExTreeDlg dlg;
	dlg.SetInterface(&Logic_Class::exInitTree);
	dlg.DoModal();
}

void CMainIDEDoc::OnCompileSymbol()
{
	CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT(pMainFrame); ASSERT_KINDOF(CMainFrame, pMainFrame);

	CString strBuf;
	m_TextBuffer.GetText( 0, 0, m_TextBuffer.GetLineCount() - 1,
		m_TextBuffer.GetLineLength(m_TextBuffer.GetLineCount() - 1), strBuf );
	if( strBuf.IsEmpty() ) return;

	COutputCtrl& console = pMainFrame->m_wndOutput.m_wndRichEdit;
	console.Clear();
	Logic_SetErrorFlag(FALSE);

	LIST_ARRAY data;
	Logic_SetDataPtr(&data); // global set data ptr
	CAnalyzer analyzer( strBuf );
	if (!analyzer.Run()) return;

	// show dialog
	CExListDlg dlg;
	dlg.SetInterface(&Logic_Class::exInitSymbol);
	dlg.DoModal();
}

void CMainIDEDoc::OnCompileCheck()
{
	CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT(pMainFrame); ASSERT_KINDOF(CMainFrame, pMainFrame);

	CString strBuf;
	m_TextBuffer.GetText( 0, 0, m_TextBuffer.GetLineCount() - 1,
		m_TextBuffer.GetLineLength(m_TextBuffer.GetLineCount() - 1), strBuf );
	if( strBuf.IsEmpty() ) return;

	COutputCtrl& console = pMainFrame->m_wndOutput.m_wndRichEdit;
	console.Clear();
	Logic_SetErrorFlag(FALSE);

	CAnalyzer analyzer( strBuf );
	analyzer.TypeCheck();
}

void CMainIDEDoc::OnCompilePcode()
{

}

void CMainIDEDoc::OnCompileAsm()
{

}

