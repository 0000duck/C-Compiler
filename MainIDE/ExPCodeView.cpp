#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "MainIDEDocBase.h"
#include "ExPCodeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExPCodeView

IMPLEMENT_DYNCREATE(CExPCodeView, CMainIDEViewBase)

BEGIN_MESSAGE_MAP(CExPCodeView, CMainIDEViewBase)
END_MESSAGE_MAP()

// CExPCodeView ����/����

CExPCodeView::CExPCodeView()
{
}

CExPCodeView::~CExPCodeView()
{
}

void CExPCodeView::OnInitialUpdate()
{
	CMainIDEViewBase::OnInitialUpdate();
	InitHashMap();
}

void CExPCodeView::InitHashMap()
{
	LPTSTR s_apszCKeywordList[] =
	{
		NULL
	};

	for( int L = 0; s_apszCKeywordList[L] != NULL; L++ ) {
		m_mapKeywords[s_apszCKeywordList[L]] = NULL;
	}
}
