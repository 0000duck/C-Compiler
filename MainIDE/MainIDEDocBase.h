
// MainIDEDocBase.h : CMainIDEDocBase ��Ľӿ�
//


#pragma once
#include "UITextBuffer.h"


class CMainIDEDocBase : public CDocument
{
protected: // �������л�����
	CMainIDEDocBase();
	DECLARE_DYNCREATE(CMainIDEDocBase)

	// ����
public:
	LOGFONT m_lf;
	CUITextBuffer m_TextBuffer;

	// ����
public:

	// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// ʵ��
public:
	virtual ~CMainIDEDocBase();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	LPCTSTR GetTitleFromPathName( CString& strPathName );

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual void DeleteContents();
};
