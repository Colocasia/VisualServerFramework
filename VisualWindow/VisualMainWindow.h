#pragma once


// VisualMainWindow �Ի���

class VisualMainWindow : public CDialog
{
	DECLARE_DYNAMIC(VisualMainWindow)

public:
	VisualMainWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~VisualMainWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

