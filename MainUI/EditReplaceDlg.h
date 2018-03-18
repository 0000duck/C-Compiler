#pragma once
#include "EDIT_CMD.h"


class CUIEditView;

// CEditReplaceDlg �Ի���

class AFX_EXT_CLASS CEditReplaceDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditReplaceDlg)

private:
	CUIEditView *m_pBuddy;
	BOOL m_bFound;
	CPoint m_ptFoundAt;
	BOOL DoHighlightText();

public:
	CEditReplaceDlg(CUIEditView* pBuddy, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditReplaceDlg();

	BOOL m_bEnableScopeSelection;
	CPoint m_ptCurrentPos;
	CPoint m_ptBlockBegin, m_ptBlockEnd;

// �Ի�������
	enum { IDD = IDD_EDIT_REPLACE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	afx_msg void OnChangeEditText();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditReplace();
	afx_msg void OnEditReplaceAll();
	afx_msg void OnEditSkip();

	DECLARE_MESSAGE_MAP()

public:
	BOOL		m_bMatchCase;
	BOOL		m_bWholeWord;
	CString		m_sText;
	CString		m_sNewText;
	int			m_nScope;
	CButton		m_btnEditSkip;
	CButton		m_btnEditReplace;
	CButton		m_btnEditReplaceAll;
	CButton		m_btnCancel;
};
