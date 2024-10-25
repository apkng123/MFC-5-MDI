#pragma once
#include "afxdialogex.h"


// CinputDlg 대화 상자

class CinputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CinputDlg)

public:
	CinputDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CinputDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strText;
	int m_nX;
	int m_nY;
};
