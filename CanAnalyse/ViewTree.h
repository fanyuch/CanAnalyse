
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree ����

class CViewTree : public CTreeCtrl
{
// ����
public:
	CViewTree();

// ��д
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg void OnClick(NMHDR * p, LRESULT *q);

// ʵ��
public:
	virtual ~CViewTree();


protected:
	DECLARE_MESSAGE_MAP()
};
