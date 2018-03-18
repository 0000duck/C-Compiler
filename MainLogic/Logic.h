#include "stdafx.h"
#include "Interfaces.h"

namespace Logic_Global
{
	//////////////////////////////////////////////////////////////////////////
	// ȫ�ֱ���
	extern ILogic_OutputMsg* g_IOMsg; // global output interface
	extern LIST_ARRAY* g_pList; // global data output interface
	extern BOOL g_bError; // global error flag

	//////////////////////////////////////////////////////////////////////////
	// ���������ı��༭����ɫ

	// C- Keywords
	extern LPTSTR s_apszCKeywordList[];
	// C- Types
	extern LPTSTR s_apszCTypeList[];

	//////////////////////////////////////////////////////////////////////////
	// �������ڼǷ�����
	extern LPTSTR s_apszCReservedKeywords[];
}

AFX_EXT_CLASS void Logic_SetInterface( ILogic_OutputMsg* );
AFX_EXT_CLASS ILogic_OutputMsg* Logic_GetInterface();
AFX_EXT_CLASS void Logic_SetErrorFlag( BOOL bErrFlag );
AFX_EXT_CLASS BOOL Logic_GetErrorFlag();
AFX_EXT_CLASS void Logic_SetDataPtr( LIST_ARRAY* );
AFX_EXT_CLASS LIST_ARRAY* Logic_GetDataPtr();
AFX_EXT_CLASS void Logic_OutputMsg( TCHAR* format, ... );
AFX_EXT_CLASS void Logic_OutputMsg( UINT id, ... );
AFX_EXT_CLASS void Logic_TraceMsg( TCHAR* format, ... );
AFX_EXT_CLASS void Logic_TraceMsg( UINT id, ... );

AFX_EXT_CLASS LPTSTR* Logic_GetKeywords();
AFX_EXT_CLASS LPTSTR* Logic_GetTypes();
AFX_EXT_CLASS LPTSTR* Logic_GetRevKeywords();
