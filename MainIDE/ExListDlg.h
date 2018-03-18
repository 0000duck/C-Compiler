#pragma once
#include "Interfaces.h"

// CExSymbolDlg �Ի���

class CExListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExListDlg)

public:
	CExListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CExListDlg();

// �Ի�������
	enum { IDD = IDD_LISTVIEW };

private:
	ILogic_ListInit*			m_pInterface;

public:
	void SetInterface(ILogic_ListInit* pInterface);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_List;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL OnInitDialog();
};
