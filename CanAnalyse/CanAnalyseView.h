// 
// // CanAnalyseView.h : CCanAnalyseView ��Ľӿ�
// //
// 
// 
// #pragma once
// 
// 
// class CCanAnalyseView : public CView
// {
// protected: // �������л�����
// 	CCanAnalyseView();
// 	DECLARE_DYNCREATE(CCanAnalyseView)
// 
// // ����
// public:
// 	CCanAnalyseDoc* GetDocument() const;
// 
// // ����
// public:
// 
// // ��д
// public:
// 	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
// 	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
// protected:
// 	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
// 	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
// 	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
// 
// // ʵ��
// public:
// 	virtual ~CCanAnalyseView();
// #ifdef _DEBUG
// 	virtual void AssertValid() const;
// 	virtual void Dump(CDumpContext& dc) const;
// #endif
// 
// protected:
// 
// // ���ɵ���Ϣӳ�亯��
// protected:
// 	afx_msg void OnFilePrintPreview();
// 	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
// 	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
// 	DECLARE_MESSAGE_MAP()
// };
// 
// #ifndef _DEBUG  // CanAnalyseView.cpp �еĵ��԰汾
// inline CCanAnalyseDoc* CCanAnalyseView::GetDocument() const
//    { return reinterpret_cast<CCanAnalyseDoc*>(m_pDocument); }
// #endif
// 

// CEditTextView.h : CCEditTextView ��Ľӿ�
//


#pragma once


class CCanAnalyseView : public CEditView
{
protected: // �������л�����
	CCanAnalyseView();
	DECLARE_DYNCREATE(CCanAnalyseView)

	// ����
public:
	CCanAnalyseDoc* GetDocument() const;

	// ����
public:

	// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// ʵ��
public:
	virtual ~CCanAnalyseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CEditTextView.cpp �еĵ��԰汾
inline CCEditTextDoc* CCEditTextView::GetDocument() const
{ return reinterpret_cast<CCEditTextDoc*>(m_pDocument); }
#endif

