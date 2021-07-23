#pragma once


// CSettingDlgEle 对话框

class CSettingDlgEle : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgEle)

public:
	CString speed;
	CString maxheavy;
	CString open_close_time;
	CString auto_close_time;

public:
	CSettingDlgEle(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDlgEle();

// 对话框数据
	enum { IDD = IDD_DIALOG_ELEARG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
