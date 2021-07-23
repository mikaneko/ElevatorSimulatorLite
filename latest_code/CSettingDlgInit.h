#pragma once


// CSettingDlgInit 对话框

class CSettingDlgInit : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgInit)

public:
	CSettingDlgInit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDlgInit();

public:
	int ele1init;
	int ele2init;
	int ele3init;

// 对话框数据
	enum { IDD = IDD_DIALOG_INIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
