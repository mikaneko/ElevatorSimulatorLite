#pragma once


// CSettingDlgInit �Ի���

class CSettingDlgInit : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgInit)

public:
	CSettingDlgInit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlgInit();

public:
	int ele1init;
	int ele2init;
	int ele3init;

// �Ի�������
	enum { IDD = IDD_DIALOG_INIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
