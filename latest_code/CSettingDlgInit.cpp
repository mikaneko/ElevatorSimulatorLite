// CSettingDlgInit.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDlgInit.h"
#include "afxdialogex.h"


// CSettingDlgInit 对话框

IMPLEMENT_DYNAMIC(CSettingDlgInit, CDialog)

CSettingDlgInit::CSettingDlgInit(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlgInit::IDD, pParent)
{

}

CSettingDlgInit::~CSettingDlgInit()
{
}

void CSettingDlgInit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlgInit, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingDlgInit::OnBnClickedOk)
END_MESSAGE_MAP()


// CSettingDlgInit 消息处理程序


BOOL CSettingDlgInit::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO1))->SetCurSel(ele1init);
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO2))->SetCurSel(ele2init);
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO3))->SetCurSel(ele3init);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSettingDlgInit::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ele1init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO1))->GetCurSel();
	ele2init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO2))->GetCurSel();
	ele3init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO3))->GetCurSel();
	CDialog::OnOK();
}
