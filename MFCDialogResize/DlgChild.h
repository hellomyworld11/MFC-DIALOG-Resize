#pragma once
#include "CDlgAutoResize.h"

// CDlgChild 对话框

class CDlgChild : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild)

public:
	CDlgChild(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgChild();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHILD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChilddialog1();

private:
	CDlgAutoResize m_rsizeMgr;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
