
// CanAnalyseDoc.cpp : CCanAnalyseDoc ���ʵ��
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


// CCanAnalyseDoc ����/����

CCanAnalyseDoc::CCanAnalyseDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CCanAnalyseDoc::~CCanAnalyseDoc()
{
}

BOOL CCanAnalyseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

BOOL CCanAnalyseDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CDocument::OnOpenDocument(lpszPathName);
	return true;
}




// CCanAnalyseDoc ���л�

void CCanAnalyseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CCanAnalyseDoc ���

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


// CCanAnalyseDoc ����
