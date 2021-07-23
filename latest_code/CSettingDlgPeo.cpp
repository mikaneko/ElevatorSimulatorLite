// CSettingDlgPeo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSettingDlgPeo.h"
#include "afxdialogex.h"


// CSettingDlgPeo �Ի���

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


// CSettingDlgPeo ��Ϣ�������


BOOL CSettingDlgPeo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString tmp;
	tmp.Format(TEXT("%d"),dlg_tickinsec);
	SetDlgItemTextW(ID_PEO_WEIGHT,tmp);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSettingDlgPeo::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tmp;
	GetDlgItemText(ID_PEO_TICKS,tmp);
	dlg_tickinsec = _ttoi(tmp);

	CDialogEx::OnOK();
}
