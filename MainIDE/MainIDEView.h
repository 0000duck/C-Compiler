
// MainIDEView.h : CMainIDEView ��Ľӿ�
//

#pragma once
#include "MainIDEDoc.h"
#include "MainIDEViewBase.h"


class CMainIDEView : public CMainIDEViewBase
{
protected: // �������л�����
	CMainIDEView();
	DECLARE_DYNCREATE(CMainIDEView)

public:
	virtual ~CMainIDEView();

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MainIDEView.cpp �еĵ��԰汾
inline CMainIDEDoc* CMainIDEView::GetDocument() const
   { return reinterpret_cast<CMainIDEDoc*>(m_pDocument); }
#endif

