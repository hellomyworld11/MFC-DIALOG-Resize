# MFC 对话框快速实现控件的按比例缩放，可以兼容包含子对话框的情况。 tabCtrl也可进行比例缩放。
## 比例缩放管理主要靠 CDlgAutoResize 类
    对话框初始化时记录所有子控件的初始CRect,是客户端坐标。
    对话框大小变化时，计算缩放比例，获取新CRect,对每个控件进行MoveWindow()即可。
    子对话框内也需要记录和实现OnSize() ,并由父窗口进行管理。
## 使用方法：
  1.引用头文件：
    #include "CDlgAutoResize.h"
  2.对话框类成员变量声明：
     CDlgAutoResize m_rsizeMgr;
  3. OnInitDialog()函数内：
    ...
    m_rsizeMgr.ManageCDlg(this);
	  m_rsizeMgr.Record();

  4. OnSize 内
     m_rsizeMgr.Update(nType, cx, cy);

效果如下:
