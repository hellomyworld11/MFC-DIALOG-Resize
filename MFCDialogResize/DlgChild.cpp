// DlgChild.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDialogResize.h"
#include "DlgChild.h"
#include "afxdialogex.h"


// CDlgChild 对话框

IMPLEMENT_DYNAMIC(CDlgChild, CDialog)

CDlgChild::CDlgChild(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_CHILD, pParent)
{

}

CDlgChild::~CDlgChild()
{
}

void CDlgChild::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgChild, CDialog)
	ON_BN_CLICKED(ID_CHILDDIALOG1, &CDlgChild::OnBnClickedChilddialog1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgChild 消息处理程序


void CDlgChild::OnBnClickedChilddialog1()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CDlgChild::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_rsizeMgr.ManageCDlg(this);
	m_rsizeMgr.Record();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgChild::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	m_rsizeMgr.Update(nType, cx, cy);

}
