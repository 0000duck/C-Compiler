
// MainIDEDoc.h : CMainIDEDoc ��Ľӿ�
//


#pragma once
#include "MainIDEDocBase.h"


class CMainIDEDoc : public CMainIDEDocBase
{
protected: // �������л�����
	CMainIDEDoc();
	DECLARE_DYNCREATE(CMainIDEDoc)

public:
	virtual ~CMainIDEDoc();

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCompileScan();
	afx_msg void OnCompileParse();
	afx_msg void OnCompileSymbol();
	afx_msg void OnCompilePcode();
	afx_msg void OnCompileAsm();
	afx_msg void OnCompileCheck();

protected:
	CMainIDEApp* m_pApp;
};
