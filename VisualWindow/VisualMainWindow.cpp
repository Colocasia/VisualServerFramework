// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VisualWindow.h"
#include "VisualMainWindow.h"


// CTestDlg �Ի���

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


// CTestDlg ��Ϣ�������
