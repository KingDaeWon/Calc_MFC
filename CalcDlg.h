
// CalcDlg.h: 헤더 파일
//
#pragma once
#include<vector>

// CCalcDlg 대화 상자
class CCalcDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalcDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CCalcDlg();  // 소멸자 선언
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString parseStr[1000];
	int parseStrCount;
	// 피연산자
	CString operandArr[1000];
	int operandIndexArr[1000];
	int operandCount;
	// 연산자
	CString operateArr[1000];
	int operateIndexArr[1000];
	int operateCount;
	// 괄호
	int openParenArrIndexArr[1000];
	int closeParenArrIndexArr[1000];
	int openParenCount;
	int closeParenCount;

	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonZero();
	CString m_EDITDisplay;
	double m_Result;
	afx_msg void OnEnChangeEditDisplay();
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonLeftParen();
	afx_msg void OnBnClickedButtonRightParen();
	afx_msg void OnBnClickedButtonResult();
	CString CCalcDlg::Calculate(CString& str);
	CString CCalcDlg::Parentheses(CString& str);
	bool CCalcDlg::ErrorCheck(CString& str);
	void CCalcDlg::StrParse(CString& str);
	void CCalcDlg::OperandParse();
	void CCalcDlg::OperateParse();
	void CCalcDlg::ParenParse();
	bool CCalcDlg::ConsecutiveOpCheck();
	bool CCalcDlg::ParenOperateCheck(CString& str);
	CString CCalcDlg::MultipleCalc(CString& str);

	CString CCalcDlg::MultipleCalc2(CString& str);
	CString CCalcDlg::RemoveZero(CString& str);
};
