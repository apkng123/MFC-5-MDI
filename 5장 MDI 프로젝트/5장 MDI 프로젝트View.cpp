
// 5장 MDI 프로젝트View.cpp: CMy5장MDI프로젝트View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "5장 MDI 프로젝트.h"
#endif

#include "5장 MDI 프로젝트Doc.h"
#include "5장 MDI 프로젝트View.h"
#include "CinputDlg.h"
#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy5장MDI프로젝트View

IMPLEMENT_DYNCREATE(CMy5장MDI프로젝트View, CView)

BEGIN_MESSAGE_MAP(CMy5장MDI프로젝트View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy5장MDI프로젝트View 생성/소멸

CMy5장MDI프로젝트View::CMy5장MDI프로젝트View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy5장MDI프로젝트View::~CMy5장MDI프로젝트View()
{
}

BOOL CMy5장MDI프로젝트View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy5장MDI프로젝트View 그리기

void CMy5장MDI프로젝트View::OnDraw(CDC* pDC)
{
	CMy5장MDI프로젝트Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	pDC->TextOut(pDoc->m_nDocX, pDoc->m_nDocY, pDoc->m_strDocText);
}


// CMy5장MDI프로젝트View 인쇄

BOOL CMy5장MDI프로젝트View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy5장MDI프로젝트View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy5장MDI프로젝트View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy5장MDI프로젝트View 진단

#ifdef _DEBUG
void CMy5장MDI프로젝트View::AssertValid() const
{
	CView::AssertValid();
}

void CMy5장MDI프로젝트View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy5장MDI프로젝트Doc* CMy5장MDI프로젝트View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy5장MDI프로젝트Doc)));
	return (CMy5장MDI프로젝트Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy5장MDI프로젝트View 메시지 처리기


void CMy5장MDI프로젝트View::OnRButtonDown(UINT nFlags, CPoint point)
{

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CinputDlg* pInput = new CinputDlg;
	if (pInput->DoModal() == IDOK)
	{
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CChildFrame* pChild = (CChildFrame*)pFrame->GetActiveFrame();
		CMy5장MDI프로젝트Doc* pDoc = (CMy5장MDI프로젝트Doc*)pChild->GetActiveDocument();

		pDoc->m_nDocX = pInput->m_nX;
		pDoc->m_nDocY = pInput->m_nY;
		pDoc->m_strDocText = pInput->m_strText;
		Invalidate();
	}
	delete pInput; pInput = 0;
	CView::OnRButtonDown(nFlags, point);
}



