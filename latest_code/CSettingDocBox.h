#pragma once


// CSettingDocBox 对话框

class CSettingDocBox : public CDialog
{
	DECLARE_DYNAMIC(CSettingDocBox)

public:
	CSettingDocBox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDocBox();

// 对话框数据
	enum { IDD = IDD_DOC_DLG };
	CString title;
	CString author;
	CString txt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
