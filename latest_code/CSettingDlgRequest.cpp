// CSettingDlgRequest.cpp : 实现文件
//

#include "stdafx.h"
#include "CSettingDlgRequest.h"
#include "afxdialogex.h"


// CSettingDlgRequest 对话框

IMPLEMENT_DYNAMIC(CSettingDlgRequest, CDialog)

CSettingDlgRequest::CSettingDlgRequest(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlgRequest::IDD, pParent)
	, Check_0_9(FALSE)
	, Check_0_8(FALSE)
	, Check_0_7(FALSE)
	, Check_0_6(FALSE)
	, Check_0_5(FALSE)
	, Check_0_4(FALSE)
	, Check_0_3(FALSE)
	, Check_0_2(FALSE)
	, Check_0_1(FALSE)
	, Check_1_9(FALSE)
	, Check_1_8(FALSE)
	, Check_1_7(FALSE)
	, Check_1_6(FALSE)
	, Check_1_5(FALSE)
	, Check_1_4(FALSE)
	, Check_1_3(FALSE)
	, Check_1_2(FALSE)
	, Check_1_1(FALSE)
	, Check_2_9(FALSE)
	, Check_2_8(FALSE)
	, Check_2_7(FALSE)
	, Check_2_6(FALSE)
	, Check_2_5(FALSE)
	, Check_2_4(FALSE)
	, Check_2_3(FALSE)
	, Check_2_2(FALSE)
	, Check_2_1(FALSE)
	, Check_out_up_9(FALSE)
	, Check_out_up_8(FALSE)
	, Check_out_up_7(FALSE)
	, Check_out_up_6(FALSE)
	, Check_out_up_5(FALSE)
	, Check_out_up_4(FALSE)
	, Check_out_up_3(FALSE)
	, Check_out_up_2(FALSE)
	, Check_out_up_1(FALSE)
	, Check_out_down_9(FALSE)
	, Check_out_down_8(FALSE)
	, Check_out_down_7(FALSE)
	, Check_out_down_6(FALSE)
	, Check_out_down_5(FALSE)
	, Check_out_down_4(FALSE)
	, Check_out_down_3(FALSE)
	, Check_out_down_2(FALSE)
	, Check_out_down_1(FALSE)
{

}

CSettingDlgRequest::~CSettingDlgRequest()
{
}

void CSettingDlgRequest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_REQ_0_9, Check_0_9);
	DDX_Check(pDX, IDC_REQ_0_8, Check_0_8);
	DDX_Check(pDX, IDC_REQ_0_7, Check_0_7);
	DDX_Check(pDX, IDC_REQ_0_6, Check_0_6);
	DDX_Check(pDX, IDC_REQ_0_5, Check_0_5);
	DDX_Check(pDX, IDC_REQ_0_4, Check_0_4);
	DDX_Check(pDX, IDC_REQ_0_3, Check_0_3);
	DDX_Check(pDX, IDC_REQ_0_2, Check_0_2);
	DDX_Check(pDX, IDC_REQ_0_1, Check_0_1);
	DDX_Check(pDX, IDC_REQ_1_9, Check_1_9);
	DDX_Check(pDX, IDC_REQ_1_8, Check_1_8);
	DDX_Check(pDX, IDC_REQ_1_7, Check_1_7);
	DDX_Check(pDX, IDC_REQ_1_6, Check_1_6);
	DDX_Check(pDX, IDC_REQ_1_5, Check_1_5);
	DDX_Check(pDX, IDC_REQ_1_4, Check_1_4);
	DDX_Check(pDX, IDC_REQ_1_3, Check_1_3);
	DDX_Check(pDX, IDC_REQ_1_2, Check_1_2);
	DDX_Check(pDX, IDC_REQ_1_1, Check_1_1);
	DDX_Check(pDX, IDC_REQ_2_9, Check_2_9);
	DDX_Check(pDX, IDC_REQ_2_8, Check_2_8);
	DDX_Check(pDX, IDC_REQ_2_7, Check_2_7);
	DDX_Check(pDX, IDC_REQ_2_6, Check_2_6);
	DDX_Check(pDX, IDC_REQ_2_5, Check_2_5);
	DDX_Check(pDX, IDC_REQ_2_4, Check_2_4);
	DDX_Check(pDX, IDC_REQ_2_3, Check_2_3);
	DDX_Check(pDX, IDC_REQ_2_2, Check_2_2);
	DDX_Check(pDX, IDC_REQ_2_1, Check_2_1);
	DDX_Check(pDX, IDC_REQ_OUT_9_U, Check_out_up_9);
	DDX_Check(pDX, IDC_REQ_OUT_8_U, Check_out_up_8);
	DDX_Check(pDX, IDC_REQ_OUT_7_U, Check_out_up_7);
	DDX_Check(pDX, IDC_REQ_OUT_6_U, Check_out_up_6);
	DDX_Check(pDX, IDC_REQ_OUT_5_U, Check_out_up_5);
	DDX_Check(pDX, IDC_REQ_OUT_4_U, Check_out_up_4);
	DDX_Check(pDX, IDC_REQ_OUT_3_U, Check_out_up_3);
	DDX_Check(pDX, IDC_REQ_OUT_2_U, Check_out_up_2);
	DDX_Check(pDX, IDC_REQ_OUT_1_U, Check_out_up_1);
	DDX_Check(pDX, IDC_REQ_OUT_9_D, Check_out_down_9);
	DDX_Check(pDX, IDC_REQ_OUT_8_D, Check_out_down_8);
	DDX_Check(pDX, IDC_REQ_OUT_7_D, Check_out_down_7);
	DDX_Check(pDX, IDC_REQ_OUT_6_D, Check_out_down_6);
	DDX_Check(pDX, IDC_REQ_OUT_5_D, Check_out_down_5);
	DDX_Check(pDX, IDC_REQ_OUT_4_D, Check_out_down_4);
	DDX_Check(pDX, IDC_REQ_OUT_3_D, Check_out_down_3);
	DDX_Check(pDX, IDC_REQ_OUT_2_D, Check_out_down_2);
	DDX_Check(pDX, IDC_REQ_OUT_1_D, Check_out_down_1);
}


BEGIN_MESSAGE_MAP(CSettingDlgRequest, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingDlgRequest::OnBnClickedOk)
END_MESSAGE_MAP()


// CSettingDlgRequest 消息处理程序


void CSettingDlgRequest::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialog::OnOK();
}
