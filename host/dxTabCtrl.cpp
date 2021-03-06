// dxTabCtrl.cpp : implementation file
//
/////////////////////////////////////////////////////
// This class is provided as is and Ben Hill takes no
// responsibility for any loss of any kind in connection
// to this code.
/////////////////////////////////////////////////////
// Is is meant purely as a educational tool and may
// contain bugs.
/////////////////////////////////////////////////////
// ben@shido.fsnet.co.uk
// http://www.shido.fsnet.co.uk
/////////////////////////////////////////////////////
// Thanks to a mystery poster in the C++ forum on 
// www.codeguru.com I can't find your name to say thanks
// for your Control drawing code. If you are that person 
// thank you very much. I have been able to use some of 
// you ideas to produce this sample application.
/////////////////////////////////////////////////////

#include "stdafx.h"
#include "dxTabCtrl.h"

#include "TabProgram.h"
#include "TabHook.h"
#include "TabDirectX.h"
#include "TabDirectX2.h"
#include "TabDirect3D.h"
#include "TabInput.h"
#include "TabTiming.h"
#include "TabWindow.h"
#include "TabOpenGL.h"
#include "TabCompat.h"
#include "TabColor.h"
#include "TabLogs.h"
#include "TabRegistry.h"
#include "TabNotes.h"
#include "TabSysLibs.h"
#include "TabDebug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern BOOL gbDebug;

/////////////////////////////////////////////////////////////////////////////
// CDXTabCtrl

CDXTabCtrl::CDXTabCtrl()
{
	int i=0;
	m_tabPages[i++]=new CTabProgram;
	m_tabPages[i++]=new CTabHook;
	m_tabPages[i++]=new CTabWindow;
	m_tabPages[i++]=new CTabInput;
	m_tabPages[i++]=new CTabDirectX;
	m_tabPages[i++]=new CTabDirectX2;
	m_tabPages[i++]=new CTabDirect3D;
	m_tabPages[i++]=new CTabTiming;
	m_tabPages[i++]=new CTabLogs;
	m_tabPages[i++]=new CTabSysLibs;
	m_tabPages[i++]=new CTabCompat;
	m_tabPages[i++]=new CTabRegistry;
	m_tabPages[i++]=new CTabNotes;
	if (gbDebug) m_tabPages[i++]=new CTabDebug;

	m_nNumberOfPages=i;
}

CDXTabCtrl::~CDXTabCtrl()
{
	for(int nCount=0; nCount < m_nNumberOfPages; nCount++){
		delete m_tabPages[nCount];
	}
}

void CDXTabCtrl::Init()
{
	int i = 0;
	m_tabCurrent=0;

	m_tabPages[i++]->Create(IDD_TAB_PROGRAM, this);
	m_tabPages[i++]->Create(IDD_TAB_HOOK, this);
	m_tabPages[i++]->Create(IDD_TAB_OUTPUT, this);
	m_tabPages[i++]->Create(IDD_TAB_INPUT, this);
	m_tabPages[i++]->Create(IDD_TAB_DIRECTX, this);
	m_tabPages[i++]->Create(IDD_TAB_DIRECTX2, this);
	m_tabPages[i++]->Create(IDD_TAB_D3D, this);
	m_tabPages[i++]->Create(IDD_TAB_TIMING, this);
	m_tabPages[i++]->Create(IDD_TAB_LOG, this);
	m_tabPages[i++]->Create(IDD_TAB_SYSLIBS, this);
	m_tabPages[i++]->Create(IDD_TAB_COMPAT, this);
	m_tabPages[i++]->Create(IDD_TAB_REGISTRY, this);
	m_tabPages[i++]->Create(IDD_TAB_NOTES, this);
	if (gbDebug) m_tabPages[i++]->Create(IDD_TAB_DEBUG, this);

	for(int nCount=0; nCount < m_nNumberOfPages; nCount++){
		m_tabPages[nCount]->ShowWindow(nCount ? SW_HIDE:SW_SHOW);
	}

	SetRectangle();
}

void CDXTabCtrl::SetRectangle()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	nX=itemRect.left;
	nY=itemRect.bottom+1;
	nXc=tabRect.right-itemRect.left-1;
	nYc=tabRect.bottom-nY-1;

	m_tabPages[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for(int nCount=1; nCount < m_nNumberOfPages; nCount++){
		m_tabPages[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
	}
}

BEGIN_MESSAGE_MAP(CDXTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CDXTabCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDXTabCtrl message handlers

void CDXTabCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CTabCtrl::OnLButtonDown(nFlags, point);

	if(m_tabCurrent != GetCurFocus()){
		m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
		m_tabCurrent=GetCurFocus();
		m_tabPages[m_tabCurrent]->ShowWindow(SW_SHOW);
		m_tabPages[m_tabCurrent]->SetFocus();
	}
}

void CDXTabCtrl::SwitchToTab(int pos)
{
	m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
	SetCurSel(pos);
	m_tabPages[pos]->ShowWindow(SW_SHOW);
	m_tabPages[pos]->SetFocus();
	m_tabCurrent=GetCurFocus();
}

void CDXTabCtrl::OnOK()
{
	for(int nCount=0; nCount < m_nNumberOfPages; nCount++){
		m_tabPages[nCount]->UpdateData(TRUE);
	}
}

