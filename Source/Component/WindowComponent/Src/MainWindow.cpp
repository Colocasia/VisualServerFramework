// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WindowComponent.h"
#include "MainWindow.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(MainWindow, CDialog)

MainWindow::MainWindow(CWnd* pParent /*=NULL*/)
	: CDialog(MainWindow::IDD, pParent)
{

}

MainWindow::~MainWindow()
{
}

void MainWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainWindow, CDialog)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序
