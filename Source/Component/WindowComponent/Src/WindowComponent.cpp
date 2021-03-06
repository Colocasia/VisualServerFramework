// WindowComponent.cpp: 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "WindowComponent.h"
#include "MainWindow.h"
#include "Api/WindowComponentAPI.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CWindowComponentApp

BEGIN_MESSAGE_MAP(CWindowComponentApp, CWinApp)
END_MESSAGE_MAP()


// CWindowComponentApp 构造

CWindowComponentApp::CWindowComponentApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CWindowComponentApp 对象

CWindowComponentApp theApp;


// CWindowComponentApp 初始化

BOOL CWindowComponentApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int CWindowComponentApp::ExitInstance()
{
    // TODO: 在此添加专用代码和/或调用基类
    return CWinApp::ExitInstance();
}

/***********************************************/
/**********    以下为接口实现部分    ***********/
/***********************************************/


VISUAL_WINDOW_API int PASCAL WindowComponent_Init(IN int nType)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return 0;
}


VISUAL_WINDOW_API int PASCAL WindowComponent_UnInit(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return 0;
}


VISUAL_WINDOW_API long PASCAL WindowComponent_CreateInstance(IN const int nFlag)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    MainWindow* pInstance = new MainWindow;
    if (NULL == pInstance)
    {
        return -1;
    }

    if (FALSE == pInstance->Create(IDD_DIALOG1))
    {
        return -2;
    }

    pInstance->ShowWindow(SW_SHOW);
    return long(pInstance);
}

VISUAL_WINDOW_API int PASCAL WindowComponent_DestroyInstance(IN long lInstace)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    MainWindow* pInstance = (MainWindow*)lInstace;
    if (pInstance)
    {
        pInstance->DestroyWindow();
        delete pInstance;
        pInstance = NULL;
    }

    return 0;
}
