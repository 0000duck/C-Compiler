
// MainIDE.h : MainIDE Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMainIDEApp:
// �йش����ʵ�֣������ MainIDE.cpp
//

class CMainIDEApp : public CWinAppEx
{
public:
	CMainIDEApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	CMultiDocTemplate* m_pMainIDEDocTemplate;
	CMultiDocTemplate* m_pPCodeDocTemplate;
	CMultiDocTemplate* m_pAsmDocTemplate;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
};

extern CMainIDEApp theApp;
