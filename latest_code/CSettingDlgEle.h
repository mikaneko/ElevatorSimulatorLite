#pragma once


// CSettingDlgEle �Ի���

class CSettingDlgEle : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgEle)

public:
	CString speed;
	CString maxheavy;
	CString open_close_time;
	CString auto_close_time;

public:
	CSettingDlgEle(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlgEle();

// �Ի�������
	enum { IDD = IDD_DIALOG_ELEARG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
