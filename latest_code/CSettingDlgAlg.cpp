// CSettingDlgAlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSettingDlgAlg.h"
#include "afxdialogex.h"


// CSettingDlgAlg �Ի���

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


// CSettingDlgAlg ��Ϣ�������


BOOL CSettingDlgAlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(ID_ALG_COMBO))->SetCurSel(alg_sel);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSettingDlgAlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	alg_sel=((CComboBox*)GetDlgItem(ID_ALG_COMBO))->GetCurSel();
	CDialog::OnOK();
}
