// CinputDlg.cpp: 구현 파일
//

#include "pch.h"
#include "5장 MDI 프로젝트.h"
#include "afxdialogex.h"
#include "CinputDlg.h"


// CinputDlg 대화 상자

IMPLEMENT_DYNAMIC(CinputDlg, CDialogEx)

CinputDlg::CinputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CARD, pParent)
	, m_strText(_T(""))
	, m_nX(0)
	, m_nY(0)
{
	m_nX = 30;
	m_nY = 30;
}

CinputDlg::~CinputDlg()
{
}

void CinputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
}


BEGIN_MESSAGE_MAP(CinputDlg, CDialogEx)
END_MESSAGE_MAP()


// CinputDlg 메시지 처리기
