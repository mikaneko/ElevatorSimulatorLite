#pragma once


// CSettingDlgAlg �Ի���

class CSettingDlgAlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgAlg)

public:
	int alg_sel;
public:
	CSettingDlgAlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlgAlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ALGARG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
