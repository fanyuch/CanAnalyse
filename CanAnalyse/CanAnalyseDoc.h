
// CanAnalyseDoc.h : CCanAnalyseDoc ��Ľӿ�
//


#pragma once


class CCanAnalyseDoc : public CDocument
{
protected: // �������л�����
	CCanAnalyseDoc();
	DECLARE_DYNCREATE(CCanAnalyseDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
public:
	BOOL OnOpenDocument(LPCTSTR lpszPathName);

// ʵ��
public:
	virtual ~CCanAnalyseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


