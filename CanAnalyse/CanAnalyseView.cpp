// 
// // CanAnalyseView.cpp : CCanAnalyseView 类的实现
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
// 	// 标准打印命令
// 	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
// 	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
// 	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCanAnalyseView::OnFilePrintPreview)
// END_MESSAGE_MAP()
// 
// // CCanAnalyseView 构造/析构
// 
// CCanAnalyseView::CCanAnalyseView()
// {
// 	// TODO: 在此处添加构造代码
// 
// }
// 
// CCanAnalyseView::~CCanAnalyseView()
// {
// }
// 
// BOOL CCanAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
// {
// 	// TODO: 在此处通过修改
// 	//  CREATESTRUCT cs 来修改窗口类或样式
// 
// 	return CView::PreCreateWindow(cs);
// }
// 
// // CCanAnalyseView 绘制
// 
// void CCanAnalyseView::OnDraw(CDC* /*pDC*/)
// {
// 	CCanAnalyseDoc* pDoc = GetDocument();
// 	ASSERT_VALID(pDoc);
// 	if (!pDoc)
// 		return;
// 
// 	// TODO: 在此处为本机数据添加绘制代码
// 	
// }
// 
// 
// // CCanAnalyseView 打印
// 
// 
// void CCanAnalyseView::OnFilePrintPreview()
// {
// 	AFXPrintPreview(this);
// }
// 
// BOOL CCanAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
// {
// 	// 默认准备
// 	return DoPreparePrinting(pInfo);
// }
// 
// void CCanAnalyseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
// {
// 	// TODO: 添加额外的打印前进行的初始化过程
// }
// 
// void CCanAnalyseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
// {
// 	// TODO: 添加打印后进行的清理过程
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
// // CCanAnalyseView 诊断
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
// CCanAnalyseDoc* CCanAnalyseView::GetDocument() const // 非调试版本是内联的
// {
// 	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCanAnalyseDoc)));
// 	return (CCanAnalyseDoc*)m_pDocument;
// }
// #endif //_DEBUG
// 
// 
// // CCanAnalyseView 消息处理程序

// CEditTextView.cpp : CCEditTextView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCanAnalyseView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCEditTextView 构造/析构

CCanAnalyseView::CCanAnalyseView()
{
	// TODO: 在此处添加构造代码

}

CCanAnalyseView::~CCanAnalyseView()
{
}

BOOL CCanAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// CCEditTextView 打印


void CCanAnalyseView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CCanAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void CCanAnalyseView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CCanAnalyseView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
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


// CCEditTextView 诊断

#ifdef _DEBUG
void CCanAnalyseView::AssertValid() const
{
	CEditView::AssertValid();
}

void CCanAnalyseView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CCanAnalyseDoc* CCanAnalyseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCanAnalyseDoc)));
	return (CCanAnalyseDoc*)m_pDocument;
}
#endif //_DEBUG


// CCEditTextView 消息处理程序
