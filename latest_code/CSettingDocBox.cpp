// CSettingDocBox.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDocBox.h"
#include "afxdialogex.h"


// CSettingDocBox 对话框

IMPLEMENT_DYNAMIC(CSettingDocBox, CDialog)

CSettingDocBox::CSettingDocBox(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDocBox::IDD, pParent)
{

}

CSettingDocBox::~CSettingDocBox()
{
}

void CSettingDocBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDocBox, CDialog)
END_MESSAGE_MAP()


// CSettingDocBox 消息处理程序


BOOL CSettingDocBox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	SetDlgItemText(IDC_DOC_DLG_S1,title);
	SetDlgItemText(IDC_DOC_DLG_S2,author);
	SetDlgItemText(IDC_DOC_DLG_E1,txt);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
