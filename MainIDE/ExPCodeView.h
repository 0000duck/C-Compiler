#pragma once
#include "MainIDEDocBase.h"
#include "MainIDEViewBase.h"


class CExPCodeView : public CMainIDEViewBase
{
protected: // �������л�����
	CExPCodeView();
	DECLARE_DYNCREATE(CExPCodeView)

public:
	virtual ~CExPCodeView();

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnInitialUpdate();

	void InitHashMap();
};

#ifndef _DEBUG  // MainIDEView.cpp �еĵ��԰汾
inline CMainIDEDocBase* CExPCodeView::GetDocument() const
{ return reinterpret_cast<CMainIDEDocBase*>(m_pDocument); }
#endif

