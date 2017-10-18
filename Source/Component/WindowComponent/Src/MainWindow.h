#pragma once


// VisualMainWindow 对话框

class MainWindow : public CDialog
{
	DECLARE_DYNAMIC(MainWindow)

public:
	MainWindow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainWindow();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

