
#include "stdafx.h"
#include "ViewTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFSIZE 4096

#define WM_OPEN_FILE  (WM_USER + 3)

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &OnClick)
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree 消息处理程序

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

 	if (pNMHDR && pNMHDR->code == NM_CLICK )
 		{
 			GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
 		}

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}


afx_msg void CViewTree::OnClick(NMHDR * pNMHDR, LRESULT *q)
{
// 	CDocument * pDoc;
// 	pDoc->
// 	pDoc->OnOpenDocument(*q);


// 	AfxGetApp()->OpenDocumentFile(*q);
	
	LPWSTR buffer; 
	LPWSTR * lpPart;
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR; 
	TVITEM item = pNMTreeView->itemNew; 
// 	CString str = ::GetFullPathName((LPCWCHAR)item.hItem,  BUFSIZE,	buffer,	lpPart);
}
