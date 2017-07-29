
// CanAnalyseDoc.cpp : CCanAnalyseDoc 类的实现
//

#include "stdafx.h"
#include "CanAnalyse.h"

#include "CanAnalyseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCanAnalyseDoc

IMPLEMENT_DYNCREATE(CCanAnalyseDoc, CDocument)

BEGIN_MESSAGE_MAP(CCanAnalyseDoc, CDocument)
END_MESSAGE_MAP()


// CCanAnalyseDoc 构造/析构

CCanAnalyseDoc::CCanAnalyseDoc()
{
	// TODO: 在此添加一次性构造代码

}

CCanAnalyseDoc::~CCanAnalyseDoc()
{
}

BOOL CCanAnalyseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

BOOL CCanAnalyseDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CDocument::OnOpenDocument(lpszPathName);
	return true;
}




// CCanAnalyseDoc 序列化

void CCanAnalyseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CCanAnalyseDoc 诊断

#ifdef _DEBUG
void CCanAnalyseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCanAnalyseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCanAnalyseDoc 命令
