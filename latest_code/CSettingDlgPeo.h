#pragma once


// CSettingDlgPeo �Ի���

class CSettingDlgPeo : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlgPeo)

public:
	int dlg_tickinsec;
public:
	CSettingDlgPeo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlgPeo();

// �Ի�������
	enum { IDD = IDD_DIALOG_PEOARG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
