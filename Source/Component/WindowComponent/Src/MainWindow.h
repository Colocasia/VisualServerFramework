#pragma once


// VisualMainWindow �Ի���

class MainWindow : public CDialog
{
	DECLARE_DYNAMIC(MainWindow)

public:
	MainWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MainWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

