// CSettingDlgEle.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSettingDlgEle.h"
#include "afxdialogex.h"


// CSettingDlgEle �Ի���

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


// CSettingDlgEle ��Ϣ�������


BOOL CSettingDlgEle::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(ID_ELE_EDIT1,speed);
	SetDlgItemText(ID_ELE_EDIT2,maxheavy);
	SetDlgItemText(ID_ELE_EDIT3,open_close_time);
	SetDlgItemText(ID_ELE_EDIT4,auto_close_time);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSettingDlgEle::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemTextW(ID_ELE_EDIT1,speed);
	GetDlgItemTextW(ID_ELE_EDIT2,maxheavy);
	GetDlgItemTextW(ID_ELE_EDIT3,open_close_time);
	GetDlgItemTextW(ID_ELE_EDIT4,auto_close_time);
	CDialog::OnOK();
}
