
// CanAnalyse.cpp : ����Ӧ�ó��������Ϊ��
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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	/*ON_COMMAND(ID_FILE_OPEN, &OnFileOpenMy)*/
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_BUTTON_START, &OnStartAnalyse)
END_MESSAGE_MAP()


// CCanAnalyseApp ����

CCanAnalyseApp::CCanAnalyseApp()
{

	m_bHiColorIcons = TRUE;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CCanAnalyseApp ����

CCanAnalyseApp theApp;


// CCanAnalyseApp ��ʼ��

BOOL CCanAnalyseApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCanAnalyseDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CCanAnalyseView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void CCanAnalyseApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCanAnalyseApp �Զ������/���淽��

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
	bi.lpszTitle=_T("ѡ���ļ���");
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
		
		for ( int i = 0 ; i < 2 ; i++ )             //�ȶ�ǰ����
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
					AfxMessageBox( _T("�����ڴ�ʧ��") ) ;
					TRACE( "�����ڴ�ʧ��" ) ;
					return 0; 
				}
				CString strModelNo = strLine.Trim().Mid(9, 4);				
				CString strCmd = strLine.Trim().Mid(22, 2);
				CString strKey = strModelNo + strCmd;

				pInter->GetDataPack(strLine , *pCurFrame) ;   //���ṹ��		
				pCurFrame->n_Time = pInter->GetUnixTime(pCurFrame->str_DataPacket);

				CFrameNode prioNode;
				
				if (pInter->m_map.Lookup(strKey, prioNode))
				{
					if (pInter->IsDropPack(prioNode, *pCurFrame))
					{
						CString errorCode = 
							_T("ʱ�� :")    + strTime + 
							_T("�ֻ��� :") + strModelNo + 
							_T("������ :") + strCmd + 
							_T(" : ������");
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
	for(i = 0 ; i < 8 ; i++)//��4����12λ ��unixʱ��
	{
		p[i] = DataPacket[i+4] ;
	}
	//��1�͵�4�ֽڻ���
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
	//��2�͵�3�ֽڻ���
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

// CCanAnalyseApp ��Ϣ�������



