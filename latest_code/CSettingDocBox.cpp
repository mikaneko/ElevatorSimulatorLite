// CSettingDocBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSettingDocBox.h"
#include "afxdialogex.h"


// CSettingDocBox �Ի���

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


// CSettingDocBox ��Ϣ�������


BOOL CSettingDocBox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	SetDlgItemText(IDC_DOC_DLG_S1,title);
	SetDlgItemText(IDC_DOC_DLG_S2,author);
	SetDlgItemText(IDC_DOC_DLG_E1,txt);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
