
// MainIDEDocBase.cpp : CMainIDEDocBase ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "MainIDEDocBase.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainIDEDocBase

IMPLEMENT_DYNCREATE(CMainIDEDocBase, CDocument)

BEGIN_MESSAGE_MAP(CMainIDEDocBase, CDocument)
END_MESSAGE_MAP()


// CMainIDEDocBase ����/����

CMainIDEDocBase::CMainIDEDocBase()
{
	// TODO: �ڴ����һ���Թ������
	// GetObject(GetStockObject(SYSTEM_FIXED_FONT), sizeof(LOGFONT), &m_lf);
	memset(&m_lf, 0, sizeof(LOGFONT));
	m_lf.lfHeight = -14;
	m_lf.lfWeight = FW_LIGHT;
	_tcscpy( m_lf.lfFaceName, _T("������") );
}

CMainIDEDocBase::~CMainIDEDocBase()
{
}

BOOL CMainIDEDocBase::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	m_TextBuffer.InitNew();

	return TRUE;
}




// CMainIDEDocBase ���л�

void CMainIDEDocBase::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMainIDEDocBase::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMainIDEDocBase::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMainIDEDocBase::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMainIDEDocBase ���

#pragma region DEBUG
#ifdef _DEBUG
void CMainIDEDocBase::AssertValid() const
{
	CDocument::AssertValid();
}

void CMainIDEDocBase::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
#pragma endregion DEBUG


// CMainIDEDocBase ����


BOOL CMainIDEDocBase::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  �ڴ������ר�õĴ�������

	return m_TextBuffer.LoadFromFile(lpszPathName);
}


BOOL CMainIDEDocBase::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: �ڴ����ר�ô����/����û���

	return m_TextBuffer.SaveToFile(lpszPathName);
}


void CMainIDEDocBase::OnCloseDocument()
{
	// TODO: �ڴ����ר�ô����/����û���
	// 	if( m_TextBuffer.IsModified() )
	// 	{
	// 		int ret = AfxMessageBox( _T("�ļ��Ѿ����ģ�Ҫ������"), MB_YESNOCANCEL | MB_ICONQUESTION);
	// 		if( ret == IDCANCEL )
	// 			return;
	// 		else if( ret == IDYES )
	// 			this->OnFileSave();
	// 	}

	CDocument::OnCloseDocument();
}


void CMainIDEDocBase::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_TextBuffer.FreeAll();

	CDocument::DeleteContents();
}

LPCTSTR CMainIDEDocBase::GetTitleFromPathName( CString& strPathName )
{
	int index1 = strPathName.ReverseFind( _T('\\') );
	int index2 = strPathName.ReverseFind( _T('.') );

	if( index2 > -1 && index2 > index1 )
		strPathName.SetAt( index2, _T('\0') );

	return (LPCTSTR)strPathName;
}
