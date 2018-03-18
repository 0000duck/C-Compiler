// ExTreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainIDE.h"
#include "ExTreeDlg.h"
#include "afxdialogex.h"


// CExTreeDlg �Ի���

IMPLEMENT_DYNAMIC(CExTreeDlg, CDialogEx)

CExTreeDlg::CExTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExTreeDlg::IDD, pParent)
{
	m_pInterface = NULL;
}

CExTreeDlg::~CExTreeDlg()
{
}

void CExTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
}

void CExTreeDlg::SetInterface( ILogic_TreeInit* pInterface )
{
	m_pInterface = pInterface;
}


BEGIN_MESSAGE_MAP(CExTreeDlg, CDialogEx)
END_MESSAGE_MAP()


// CExTreeDlg ��Ϣ�������

void CExTreeDlg::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	if (nChar == VK_ESCAPE) OnOK();
}

BOOL CExTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (m_pInterface)
	{
		CString title;
		m_pInterface->Init(title, m_Tree);
		SetWindowText(title);
	}

	return TRUE;
}
