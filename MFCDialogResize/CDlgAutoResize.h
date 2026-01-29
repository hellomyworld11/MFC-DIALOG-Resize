#pragma once

#include <map>
#include <vector>

class CDlgAutoResize 
{
public:
	explicit CDlgAutoResize();

	bool ManageCDlg(CDialog* pDlg);

	bool Record();	

	bool RecordChildDlg(CDialog* pDlg);

	bool Update(UINT nType, int cx, int cy);

	bool UpdateRecur(CWnd* pParentWnd, UINT nType, int cx, int cy);

	bool RecordRecur(CWnd* pParentWnd, int parentId = -1);

	float GetScaleX() { return m_dXScale; }

	float GetScaleY() { return m_dYScale; }
private:
	bool GetWndNewRect(CWnd*&pWnd, float dxScale, float dyScale, CRect oldCliRect, CRect& newCliRect);
	
	float GetTabTitleHeigth(CWnd*& pWnd);
private:
	CDialog* m_pDlg;

	float m_dXScale;
	float m_dYScale;

	CRect m_oldDlgScrRect; 
	CRect m_oldDlgCliRect;

	std::map<int, CRect> m_oldRectMap;  //客户区坐标

	std::vector<CRect> m_childDlgRects;
	std::vector<CDialog*> m_childDlgs;
};


