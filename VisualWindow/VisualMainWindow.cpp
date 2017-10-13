// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VisualWindow.h"
#include "VisualMainWindow.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(VisualMainWindow, CDialog)

VisualMainWindow::VisualMainWindow(CWnd* pParent /*=NULL*/)
	: CDialog(VisualMainWindow::IDD, pParent)
{

}

VisualMainWindow::~VisualMainWindow()
{
}

void VisualMainWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(VisualMainWindow, CDialog)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序
