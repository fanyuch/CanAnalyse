
// CanAnalyse.h : CanAnalyse 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号

typedef struct   CFrameNode//同一秒内，同一分机，同一命令字，的节点
{
	CString str_Cmd;
	unsigned long n_Time;//unix 时间
	BOOL multi_packet;
	CString str_DataPacket;//具体的模拟量，开关量，要根据具体的命令字解释，再分类存储	
}CFrameNode;

typedef CMap<CString, LPCTSTR, CFrameNode, CFrameNode&> CCmd;


// CCanAnalyseApp:
// 有关此类的实现，请参阅 CanAnalyse.cpp
//

class CCanAnalyseApp : public CWinAppEx
{
public:
	CCanAnalyseApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
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
