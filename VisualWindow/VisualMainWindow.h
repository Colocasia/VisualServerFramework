#pragma once


// VisualMainWindow 对话框

class VisualMainWindow : public CDialog
{
	DECLARE_DYNAMIC(VisualMainWindow)

public:
	VisualMainWindow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~VisualMainWindow();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

