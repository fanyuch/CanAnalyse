
// CanAnalyse.h : CanAnalyse Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

typedef struct   CFrameNode//ͬһ���ڣ�ͬһ�ֻ���ͬһ�����֣��Ľڵ�
{
	CString str_Cmd;
	unsigned long n_Time;//unix ʱ��
	BOOL multi_packet;
	CString str_DataPacket;//�����ģ��������������Ҫ���ݾ���������ֽ��ͣ��ٷ���洢	
}CFrameNode;

typedef CMap<CString, LPCTSTR, CFrameNode, CFrameNode&> CCmd;


// CCanAnalyseApp:
// �йش����ʵ�֣������ CanAnalyse.cpp
//

class CCanAnalyseApp : public CWinAppEx
{
public:
	CCanAnalyseApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileOpenMy();
	afx_msg void OnStartAnalyse();
	DECLARE_MESSAGE_MAP()

public:
	HANDLE m_hThreadMyProc;
	DWORD m_dwThreadId;
	CList <CString, CString&> m_fileLst;
	CList <CString, CString&> m_Error;
	CString m_Path;
	CCmd m_map;

public:
	unsigned long GetUnixTime(CString);
	BOOL IsDropPack(CFrameNode, CFrameNode);
	void GetDataPack(CString, CFrameNode&);
};

extern CCanAnalyseApp theApp;
