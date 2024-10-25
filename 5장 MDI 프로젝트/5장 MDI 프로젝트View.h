
// 5장 MDI 프로젝트View.h: CMy5장MDI프로젝트View 클래스의 인터페이스
//

#pragma once


class CMy5장MDI프로젝트View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy5장MDI프로젝트View() noexcept;
	DECLARE_DYNCREATE(CMy5장MDI프로젝트View)

// 특성입니다.
public:
	CMy5장MDI프로젝트Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy5장MDI프로젝트View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 5장 MDI 프로젝트View.cpp의 디버그 버전
inline CMy5장MDI프로젝트Doc* CMy5장MDI프로젝트View::GetDocument() const
   { return reinterpret_cast<CMy5장MDI프로젝트Doc*>(m_pDocument); }
#endif

