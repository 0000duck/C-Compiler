#pragma once
#include "MainIDEDocBase.h"
#include "MainIDEViewBase.h"


class CExAsmView : public CMainIDEViewBase
{
protected: // �������л�����
	CExAsmView();
	DECLARE_DYNCREATE(CExAsmView)

public:
	virtual ~CExAsmView();

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnInitialUpdate();

	void InitHashMap();
};

#ifndef _DEBUG  // MainIDEView.cpp �еĵ��԰汾
inline CMainIDEDocBase* CExAsmView::GetDocument() const
{ return reinterpret_cast<CMainIDEDocBase*>(m_pDocument); }
#endif

