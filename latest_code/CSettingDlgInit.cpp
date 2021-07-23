// CSettingDlgInit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSettingDlgInit.h"
#include "afxdialogex.h"


// CSettingDlgInit �Ի���

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


// CSettingDlgInit ��Ϣ�������


BOOL CSettingDlgInit::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO1))->SetCurSel(ele1init);
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO2))->SetCurSel(ele2init);
	((CComboBox*)GetDlgItem(IDC_INIT_COMBO3))->SetCurSel(ele3init);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSettingDlgInit::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ele1init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO1))->GetCurSel();
	ele2init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO2))->GetCurSel();
	ele3init=((CComboBox*)GetDlgItem(IDC_INIT_COMBO3))->GetCurSel();
	CDialog::OnOK();
}
