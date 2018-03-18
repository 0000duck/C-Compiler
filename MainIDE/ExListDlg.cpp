// ExSymbolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainIDE.h"
#include "ExListDlg.h"
#include "afxdialogex.h"


// CExSymbolDlg �Ի���

IMPLEMENT_DYNAMIC(CExListDlg, CDialogEx)

CExListDlg::CExListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExListDlg::IDD, pParent)
{
	m_pInterface = NULL;
}

CExListDlg::~CExListDlg()
{
}

void CExListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

void CExListDlg::SetInterface( ILogic_ListInit* pInterface )
{
	m_pInterface = pInterface;
}

BEGIN_MESSAGE_MAP(CExListDlg, CDialogEx)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CExSymbolDlg ��Ϣ�������


void CExListDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE) OnOK();
}

BOOL CExListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (m_pInterface)
	{
		CString title;
		m_pInterface->Init(title, m_List);
		SetWindowText(title);
	}

	return TRUE;
}
