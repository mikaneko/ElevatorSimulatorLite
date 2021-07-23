// CSettingDlgAlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDlgAlg.h"
#include "afxdialogex.h"


// CSettingDlgAlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlgAlg, CDialog)

CSettingDlgAlg::CSettingDlgAlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlgAlg::IDD, pParent)
{

}

CSettingDlgAlg::~CSettingDlgAlg()
{
}

void CSettingDlgAlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlgAlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingDlgAlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSettingDlgAlg 消息处理程序


BOOL CSettingDlgAlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(ID_ALG_COMBO))->SetCurSel(alg_sel);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSettingDlgAlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	alg_sel=((CComboBox*)GetDlgItem(ID_ALG_COMBO))->GetCurSel();
	CDialog::OnOK();
}
