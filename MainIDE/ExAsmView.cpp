#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "MainIDEDocBase.h"
#include "ExAsmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExAsmView

IMPLEMENT_DYNCREATE(CExAsmView, CMainIDEViewBase)

BEGIN_MESSAGE_MAP(CExAsmView, CMainIDEViewBase)
END_MESSAGE_MAP()

// CExAsmView ����/����

CExAsmView::CExAsmView()
{
}

CExAsmView::~CExAsmView()
{
}

void CExAsmView::OnInitialUpdate()
{
	CMainIDEViewBase::OnInitialUpdate();
	InitHashMap();
}

void CExAsmView::InitHashMap()
{
	LPTSTR s_apszCKeywordList[] =
	{
		NULL
	};

	for( int L = 0; s_apszCKeywordList[L] != NULL; L++ ) {
		m_mapKeywords[s_apszCKeywordList[L]] = NULL;
	}
}
