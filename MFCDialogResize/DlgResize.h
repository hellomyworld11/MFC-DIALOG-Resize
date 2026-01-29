#pragma once

#include "CDlgAutoResize.h"
// CDlgResize 对话框

class CDlgResize : public CDialog
{
	DECLARE_DYNAMIC(CDlgResize)

public:
	CDlgResize(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgResize();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGRESIZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedCancel();

private:
	CDlgAutoResize m_rsizeMgr;
	CDialog * m_pChildDlg;
};
