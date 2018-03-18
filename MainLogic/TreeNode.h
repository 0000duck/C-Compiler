#pragma once
#include "Lexer.h"

#define MAX_CHILDREN 3

using namespace Logic_Global;

// �﷨���������
enum NodeKind
{
	kVarDec,		// ��������
	kFunDec,		// ��������
	kParam,			// ����
	kStmt,			// ���
	kExp			// ���ʽ
};

// �������
enum StmtKind
{
	kIf,
	kWhile,
	kGoto,
	kBreak,
	kContinue,
	kReturn,
	kLabel,
	kCall
};

// ���ʽ����
enum ExpKind
{
	kOp,
	kConst,
	kID
};

// ������
union UndefKind
{
	StmtKind	stmt;
	ExpKind		exp;
};

/*
*	����֧�����(3-Tree)
*/
class AFX_EXT_CLASS CTreeNode
{
public:
	CTreeNode();
	~CTreeNode();

	CTreeNode* LastSibling();

public:
	CTreeNode*		father;					// point to father node
	CTreeNode*		child[ MAX_CHILDREN ];	// point to child node
	CTreeNode*		sibling;				// point to sibling node
	int				lineno;
	NodeKind		nodekind;
	UndefKind		kind;
	LTokenType		type;
	CString			szName;
	CString			szScope;				// node function scope
	BOOL			bArray;					// is this an array declaration
	int				iArraySize;				// array size
};
