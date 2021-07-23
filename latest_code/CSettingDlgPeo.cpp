// CSettingDlgPeo.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDlgPeo.h"
#include "afxdialogex.h"


// CSettingDlgPeo 对话框

IMPLEMENT_DYNAMIC(CSettingDlgPeo, CDialogEx)

CSettingDlgPeo::CSettingDlgPeo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlgPeo::IDD, pParent)
{

}

CSettingDlgPeo::~CSettingDlgPeo()
{
}

void CSettingDlgPeo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlgPeo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSettingDlgPeo::OnBnClickedOk)
END_MESSAGE_MAP()


// CSettingDlgPeo 消息处理程序


BOOL CSettingDlgPeo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString tmp;
	tmp.Format(TEXT("%d"),dlg_tickinsec);
	SetDlgItemTextW(ID_PEO_WEIGHT,tmp);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSettingDlgPeo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	GetDlgItemText(ID_PEO_TICKS,tmp);
	dlg_tickinsec = _ttoi(tmp);

	CDialogEx::OnOK();
}
