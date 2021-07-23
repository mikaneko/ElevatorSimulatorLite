#pragma once


// CSettingDlgAlg 对话框

class CSettingDlgAlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgAlg)

public:
	int alg_sel;
public:
	CSettingDlgAlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDlgAlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ALGARG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
