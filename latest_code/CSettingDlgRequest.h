#pragma once


// CSettingDlgRequest 对话框

class CSettingDlgRequest : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlgRequest)

public:
	CSettingDlgRequest(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDlgRequest();

// 对话框数据
public:

	enum { IDD = IDD_DIALOG_REQUEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL Check_0_9;
	BOOL Check_0_8;
	BOOL Check_0_7;
	BOOL Check_0_6;
	BOOL Check_0_5;
	BOOL Check_0_4;
	BOOL Check_0_3;
	BOOL Check_0_2;
	BOOL Check_0_1;
	BOOL Check_1_9;
	BOOL Check_1_8;
	BOOL Check_1_7;
	BOOL Check_1_6;
	BOOL Check_1_5;
	BOOL Check_1_4;
	BOOL Check_1_3;
	BOOL Check_1_2;
	BOOL Check_1_1;
	BOOL Check_2_9;
	BOOL Check_2_8;
	BOOL Check_2_7;
	BOOL Check_2_6;
	BOOL Check_2_5;
	BOOL Check_2_4;
	BOOL Check_2_3;
	BOOL Check_2_2;
	BOOL Check_2_1;
	BOOL Check_out_up_9;
	BOOL Check_out_up_8;
	BOOL Check_out_up_7;
	BOOL Check_out_up_6;
	BOOL Check_out_up_5;
	BOOL Check_out_up_4;
	BOOL Check_out_up_3;
	BOOL Check_out_up_2;
	BOOL Check_out_up_1;
	BOOL Check_out_down_9;
	BOOL Check_out_down_8;
	BOOL Check_out_down_7;
	BOOL Check_out_down_6;
	BOOL Check_out_down_5;
	BOOL Check_out_down_4;
	BOOL Check_out_down_3;
	BOOL Check_out_down_2;
	BOOL Check_out_down_1;
	afx_msg void OnBnClickedOk();
};
