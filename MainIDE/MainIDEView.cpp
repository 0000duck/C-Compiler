
// MainIDEView.cpp : CMainIDEView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainIDE.h"
#endif

#include "MainIDEDoc.h"
#include "MainIDEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainIDEView

IMPLEMENT_DYNCREATE(CMainIDEView, CMainIDEViewBase)

BEGIN_MESSAGE_MAP(CMainIDEView, CMainIDEViewBase)
END_MESSAGE_MAP()

// CMainIDEView ����/����

CMainIDEView::CMainIDEView()
{
}

CMainIDEView::~CMainIDEView()
{
}

