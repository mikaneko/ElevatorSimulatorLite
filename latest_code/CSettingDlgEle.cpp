// CSettingDlgEle.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDlgEle.h"
#include "afxdialogex.h"


// CSettingDlgEle 对话框

IMPLEMENT_DYNAMIC(CSettingDlgEle, CDialog)

CSettingDlgEle::CSettingDlgEle(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlgEle::IDD, pParent)
{

}

CSettingDlgEle::~CSettingDlgEle()
{
}

void CSettingDlgEle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlgEle, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingDlgEle::OnBnClickedOk)
END_MESSAGE_MAP()


// CSettingDlgEle 消息处理程序


BOOL CSettingDlgEle::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(ID_ELE_EDIT1,speed);
	SetDlgItemText(ID_ELE_EDIT2,maxheavy);
	SetDlgItemText(ID_ELE_EDIT3,open_close_time);
	SetDlgItemText(ID_ELE_EDIT4,auto_close_time);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSettingDlgEle::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemTextW(ID_ELE_EDIT1,speed);
	GetDlgItemTextW(ID_ELE_EDIT2,maxheavy);
	GetDlgItemTextW(ID_ELE_EDIT3,open_close_time);
	GetDlgItemTextW(ID_ELE_EDIT4,auto_close_time);
	CDialog::OnOK();
}
