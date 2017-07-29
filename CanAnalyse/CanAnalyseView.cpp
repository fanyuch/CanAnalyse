// 
// // CanAnalyseView.cpp : CCanAnalyseView ���ʵ��
// //
// 
// #include "stdafx.h"
// #include "CanAnalyse.h"
// 
// #include "CanAnalyseDoc.h"
// #include "CanAnalyseView.h"
// 
// #ifdef _DEBUG
// #define new DEBUG_NEW
// #endif
// 
// 
// // CCanAnalyseView
// 
// IMPLEMENT_DYNCREATE(CCanAnalyseView, CView)
// 
// BEGIN_MESSAGE_MAP(CCanAnalyseView, CView)
// 	// ��׼��ӡ����
// 	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
// 	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
// 	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCanAnalyseView::OnFilePrintPreview)
// END_MESSAGE_MAP()
// 
// // CCanAnalyseView ����/����
// 
// CCanAnalyseView::CCanAnalyseView()
// {
// 	// TODO: �ڴ˴���ӹ������
// 
// }
// 
// CCanAnalyseView::~CCanAnalyseView()
// {
// }
// 
// BOOL CCanAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
// {
// 	// TODO: �ڴ˴�ͨ���޸�
// 	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
// 
// 	return CView::PreCreateWindow(cs);
// }
// 
// // CCanAnalyseView ����
// 
// void CCanAnalyseView::OnDraw(CDC* /*pDC*/)
// {
// 	CCanAnalyseDoc* pDoc = GetDocument();
// 	ASSERT_VALID(pDoc);
// 	if (!pDoc)
// 		return;
// 
// 	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
// 	
// }
// 
// 
// // CCanAnalyseView ��ӡ
// 
// 
// void CCanAnalyseView::OnFilePrintPreview()
// {
// 	AFXPrintPreview(this);
// }
// 
// BOOL CCanAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
// {
// 	// Ĭ��׼��
// 	return DoPreparePrinting(pInfo);
// }
// 
// void CCanAnalyseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
// {
// 	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
// }
// 
// void CCanAnalyseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
// {
// 	// TODO: ��Ӵ�ӡ����е��������
// }
// 
// void CCanAnalyseView::OnRButtonUp(UINT nFlags, CPoint point)
// {
// 	ClientToScreen(&point);
// 	OnContextMenu(this, point);
// }
// 
// void CCanAnalyseView::OnContextMenu(CWnd* pWnd, CPoint point)
// {
// 	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
// }
// 
// 
// // CCanAnalyseView ���
// 
// #ifdef _DEBUG
// void CCanAnalyseView::AssertValid() const
// {
// 	CView::AssertValid();
// }
// 
// void CCanAnalyseView::Dump(CDumpContext& dc) const
// {
// 	CView::Dump(dc);
// }
// 
// CCanAnalyseDoc* CCanAnalyseView::GetDocument() const // �ǵ��԰汾��������
// {
// 	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCanAnalyseDoc)));
// 	return (CCanAnalyseDoc*)m_pDocument;
// }
// #endif //_DEBUG
// 
// 
// // CCanAnalyseView ��Ϣ�������

// CEditTextView.cpp : CCEditTextView ���ʵ��
//

#include "stdafx.h"
#include "CanAnalyse.h"

#include "CanAnalyseDoc.h"
#include "CanAnalyseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCEditTextView

IMPLEMENT_DYNCREATE(CCanAnalyseView, CEditView)

BEGIN_MESSAGE_MAP(CCanAnalyseView, CEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCanAnalyseView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCEditTextView ����/����

CCanAnalyseView::CCanAnalyseView()
{
	// TODO: �ڴ˴���ӹ������

}

CCanAnalyseView::~CCanAnalyseView()
{
}

BOOL CCanAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���û���

	return bPreCreated;
}


// CCEditTextView ��ӡ


void CCanAnalyseView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CCanAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ׼��
	return CEditView::OnPreparePrinting(pInfo);
}

void CCanAnalyseView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ��ʼ��ӡ
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CCanAnalyseView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ������ӡ
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CCanAnalyseView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCanAnalyseView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CCEditTextView ���

#ifdef _DEBUG
void CCanAnalyseView::AssertValid() const
{
	CEditView::AssertValid();
}

void CCanAnalyseView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CCanAnalyseDoc* CCanAnalyseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCanAnalyseDoc)));
	return (CCanAnalyseDoc*)m_pDocument;
}
#endif //_DEBUG


// CCEditTextView ��Ϣ�������
