#pragma once


// CSettingDocBox �Ի���

class CSettingDocBox : public CDialog
{
	DECLARE_DYNAMIC(CSettingDocBox)

public:
	CSettingDocBox(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDocBox();

// �Ի�������
	enum { IDD = IDD_DOC_DLG };
	CString title;
	CString author;
	CString txt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
