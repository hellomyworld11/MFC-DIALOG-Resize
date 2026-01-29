// DlgResize.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDialogResize.h"
#include "DlgResize.h"
#include "afxdialogex.h"
#include "DlgChild.h"



// CDlgResize 对话框

IMPLEMENT_DYNAMIC(CDlgResize, CDialog)

CDlgResize::CDlgResize(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLGRESIZE, pParent)
	, m_pChildDlg(nullptr)
{

}

CDlgResize::~CDlgResize()
{
}

void CDlgResize::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgResize, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDCANCEL, &CDlgResize::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgResize 消息处理程序


BOOL CDlgResize::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_pChildDlg = new CDlgChild();
	CWnd *pParaent = GetDlgItem(IDC_STATIC_CONTAINER);
	m_pChildDlg->Create(IDD_DIALOG_CHILD, pParaent);
	CRect containerRect;
	pParaent->GetClientRect(&containerRect);
	m_pChildDlg->MoveWindow(containerRect);
	m_pChildDlg->ShowWindow(SW_SHOW);

	m_rsizeMgr.ManageCDlg(this);
	m_rsizeMgr.Record();
	m_rsizeMgr.RecordChildDlg(m_pChildDlg);

	return TRUE;  
}


void CDlgResize::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	m_rsizeMgr.Update(nType, cx, cy);

	Invalidate();
}


void CDlgResize::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	delete m_pChildDlg;
	CDialog::OnCancel();
}
