
// CanAnalyse.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "CanAnalyse.h"
#include "MainFrm.h"

#include "CanAnalyseDoc.h"
#include "CanAnalyseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HANDLE hMutex = ::CreateMutex(NULL, FALSE, _T("CAN_ANALYSE_OUTPUT"));

#define WM_USER_OUTPUT             (WM_USER + 1)
#define WM_USER_SHOWTREE         (WM_USER + 2)

// CCanAnalyseApp

BEGIN_MESSAGE_MAP(CCanAnalyseApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CCanAnalyseApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	/*ON_COMMAND(ID_FILE_OPEN, &OnFileOpenMy)*/
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_BUTTON_START, &OnStartAnalyse)
END_MESSAGE_MAP()


// CCanAnalyseApp 构造

CCanAnalyseApp::CCanAnalyseApp()
{

	m_bHiColorIcons = TRUE;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CCanAnalyseApp 对象

CCanAnalyseApp theApp;


// CCanAnalyseApp 初始化

BOOL CCanAnalyseApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCanAnalyseDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CCanAnalyseView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CCanAnalyseApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCanAnalyseApp 自定义加载/保存方法

void CCanAnalyseApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CCanAnalyseApp::LoadCustomState()
{
}

void CCanAnalyseApp::SaveCustomState()
{
}

void CCanAnalyseApp::OnFileOpenMy()
{	
	CString StrFolder;
	BROWSEINFO bi;	
	memset(&bi, 0, sizeof(BROWSEINFO) );
	bi.hwndOwner = this->m_pMainWnd->GetSafeHwnd();
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT;
	bi.lpszTitle=_T("选择文件夹");
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	if(idl==NULL)
	{
		return;
	}
	SHGetPathFromIDList(idl,StrFolder.GetBuffer(MAX_PATH));
	m_Path = StrFolder;
	StrFolder.ReleaseBuffer();
	CMainFrame *pMain = (CMainFrame *)this->m_pMainWnd;
	HWND hFileViewWnd = pMain->GetFileView()->GetSafeHwnd();
	::SendMessage(hFileViewWnd, WM_USER_SHOWTREE, (WPARAM)&StrFolder, 0);
}

DWORD WINAPI MyProc(LPVOID pParam)
{
	CCanAnalyseApp * pInter = (CCanAnalyseApp *)pParam;
	while (!pInter->m_fileLst.IsEmpty())
	{
		BOOL endfile = TRUE;
		CString strTime ;
		CString strLine ; 
		CString strIsData ; 
		CString strIstime ;

		CString filename = pInter->m_fileLst.GetHead();		
		CStdioFile file(filename, CFile::modeRead);		
		
		for ( int i = 0 ; i < 2 ; i++ )             //先读前两行
		{
			endfile = file.ReadString( strTime ) ;
			strIstime = strTime.Right(7) ;
			endfile = file.ReadString( strLine ) ;
			strIsData = strLine.Left(7) ;
		}
		while(endfile)
		{
			endfile = file.ReadString( strLine ) ; 

			if( strLine.Right(7) == strIstime)
			{
				strTime = strLine ;
				::WaitForSingleObject(::hMutex, INFINITE);
				CMainFrame * pFrame = (CMainFrame *)pInter->m_pMainWnd;
				pFrame->m_OutPutBufLst.AddTail(strTime);		
				::ReleaseMutex(::hMutex);						
			}
			else if( strLine.Left(7) == strIsData)
			{				
				CFrameNode *pCurFrame = new CFrameNode;
				if( pCurFrame == NULL )
				{
					AfxMessageBox( _T("申请内存失败") ) ;
					TRACE( "申请内存失败" ) ;
					return 0; 
				}
				CString strModelNo = strLine.Trim().Mid(9, 4);				
				CString strCmd = strLine.Trim().Mid(22, 2);
				CString strKey = strModelNo + strCmd;

				pInter->GetDataPack(strLine , *pCurFrame) ;   //填充结构体		
				pCurFrame->n_Time = pInter->GetUnixTime(pCurFrame->str_DataPacket);

				CFrameNode prioNode;
				
				if (pInter->m_map.Lookup(strKey, prioNode))
				{
					if (pInter->IsDropPack(prioNode, *pCurFrame))
					{
						CString errorCode = 
							_T("时间 :")    + strTime + 
							_T("分机号 :") + strModelNo + 
							_T("命令字 :") + strCmd + 
							_T(" : 丢包点");
						pInter->m_Error.AddTail(errorCode);
						/*::PostMessage()*/
					}													
				}
				prioNode = *pCurFrame;
				pInter->m_map.SetAt(strKey, prioNode);

				if (pCurFrame != NULL)
				{
					delete pCurFrame;
					pCurFrame = NULL;				
				}				
			}
		}
		/*::Sleep(100);*/
	}
	return 0;
}


void CCanAnalyseApp::OnStartAnalyse()
{
	if (m_Path.IsEmpty())
	{
		AfxMessageBox(_T("no directory"));
		return;
	}
	CFileFind finder;
	BOOL bNotEnd = finder.FindFile(m_Path + _T("\\*.txt"));
	while (bNotEnd)
	{
		bNotEnd = finder.FindNextFile();
		CString strTmp = finder.GetFilePath();
		if (!strTmp.IsEmpty())
		{
			m_fileLst.AddTail(strTmp);
		}		
	}

	m_hThreadMyProc = ::CreateThread(
		NULL, 
		0,
		MyProc, 
		this, 
		CREATE_SUSPENDED,
		&m_dwThreadId);
	if (m_fileLst.GetCount() <= 0)
	{
		return;
	}
	else
	{
		::ResumeThread(m_hThreadMyProc);
		CMainFrame * pMain = (CMainFrame *)this->m_pMainWnd;	
		::SendMessage(pMain->m_wndOutput.GetSafeHwnd(), WM_USER_OUTPUT, 0, 0); 		
	}	
}

unsigned long CCanAnalyseApp::GetUnixTime(CString DataPacket)
{
	char p [9];
	memset(p,0,9);
	int i = 0;
	for(i = 0 ; i < 8 ; i++)//第4到第12位 是unix时间
	{
		p[i] = DataPacket[i+4] ;
	}
	//第1和第4字节互换
	char * tmp = new char [2];
	for(i = 0 ; i < 2 ; i++)
	{
		tmp[i] = p[i];
	}
	for(i = 0 ; i < 2 ; i++)
	{
		p[i] = p[i+6];
	}
	for(i = 0 ; i < 2 ; i++)
	{
		p[i+6]=tmp[i];
	}
	//第2和第3字节互换
	for(i = 0 ; i < 2 ; i++)
	{
		tmp[i] = p[i+2];
	}
	for(i = 0 ; i < 2 ; i++)
	{
		p[i+2] = p[i+4];
	}
	for(i = 0 ; i < 2 ; i++)
	{
		p[i+4] = tmp[i];
	}
	p[8]='\0';
	unsigned long time = 0;
	time = strtoul(p,0,16);
	return time;
}



BOOL inline CCanAnalyseApp::IsDropPack(CFrameNode node, CFrameNode nextnode)
{
	int differ=0;
	differ=nextnode.n_Time - node.n_Time;
	return differ >= 2 ? TRUE : FALSE;
}

void inline CCanAnalyseApp::GetDataPack(CString str,CFrameNode & node)
{
	str.Remove(' ');
	str.Delete(-1,18);
	node.str_DataPacket=str;
}

// CCanAnalyseApp 消息处理程序



