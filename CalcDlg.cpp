
// CalcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcDlg 대화 상자



CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, m_EDITDisplay(_T(""))
	, m_Result(0)
	, parseStrCount(0)
	, operandCount(0)
	, operateCount(0)
	, openParenCount(0)
	, closeParenCount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CCalcDlg::~CCalcDlg()
{
}
void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISPLAY, m_EDITDisplay);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalcDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CCalcDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CCalcDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CCalcDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CCalcDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CCalcDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CCalcDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CCalcDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CCalcDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CCalcDlg::OnBnClickedButtonZero)
	ON_EN_CHANGE(IDC_EDIT_DISPLAY, &CCalcDlg::OnEnChangeEditDisplay)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CCalcDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalcDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalcDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalcDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalcDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalcDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalcDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_PAREN, &CCalcDlg::OnBnClickedButtonLeftParen)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT_PAREN, &CCalcDlg::OnBnClickedButtonRightParen)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CCalcDlg::OnBnClickedButtonResult)
END_MESSAGE_MAP()


// CCalcDlg 메시지 처리기

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalcDlg::OnBnClickedButtonOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("1");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("2");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("3");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("4");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("5");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("6");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("7");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("8");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("9");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T("0");
	UpdateData(FALSE);
}

void CCalcDlg::OnEnChangeEditDisplay()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_EDITDisplay = _T("");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" + ");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" - ");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" * ");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" / ");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(".");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonLeftParen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" ( ");
	UpdateData(FALSE);
}

void CCalcDlg::OnBnClickedButtonRightParen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDITDisplay += _T(" ) ");
	UpdateData(FALSE);
}

// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
void CCalcDlg::OnBnClickedButtonResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	// 피연산자,연산자,괄호 파싱
	StrParse(m_EDITDisplay);

	// 오류검사 후 연산
	if (ErrorCheck(m_EDITDisplay)) { // 오류처리
		m_EDITDisplay = Parentheses(m_EDITDisplay); // 괄호처리
		
		m_EDITDisplay = RemoveZero(m_EDITDisplay); // 24.000000 -> .000000 처리
		// 결과를 m_EDITDisplay에 설정
		UpdateData(FALSE);
	}
}

// 소수점 및 0 지우기
CString CCalcDlg::RemoveZero(CString& str) {
	int endIndex = str.GetLength() - 1;
	CString result;

	// 문자열의 끝부터 역순으로 0을 찾음
	while (endIndex >= 0 && (str[endIndex] == _T('0') || str[endIndex] == _T('.'))) {
		endIndex--;
		if (str[endIndex] == _T('.')) { // 소수점을 만나면 소수점까지 지우고 break
			endIndex--;
			break;
		}
	}

	result = str.Left(endIndex + 1); // 왼쪽 기준 추출할 문자의 수

	return result;
}

// 괄호 찾기
CString CCalcDlg::Parentheses(CString& str) {
	CString result;
	int parenCase = 0;
	CString subStr;

	if (openParenCount >= 0 ) { // 괄호 있을 때
		for (int i = 0; i < str.GetLength(); i++) {
			if (str[i] == _T('(')) {	// 열린괄호 찾기
				for (int j = i + 1; j < str.GetLength(); j++) {
					if (str[j] == _T('(')) {	
						break;
					}
					if (str[j] == _T(')')) { // 닫힌괄호 찾기
						subStr = str.Mid(i, j - i + 1); // 괄호 ~ 괄호까지 포함된 문자열
						CString minStr = subStr.Mid(1, subStr.GetLength() - 2);
						CString parenVal = MultipleCalc2(minStr); // 괄호안에서 여러가지 연산식 연산
						str.Replace(subStr, parenVal);
						i = 0;
						j = 0;
					}
				}
			}
			if (str.Find(_T('(')) == -1) {
				break;
			}
		}
	}
	result = MultipleCalc2(str); // 괄호 없으면 바로 여러가지 연산식 연산
	return result;
}

// 여러개 연산식 분리해서 계산 subStr에 공백 문자열 줘야함 ****안씀****
CString CCalcDlg::MultipleCalc(CString& str) {
	CString subStr = _T("");
	CString calculatedStr = _T("");
	StrParse(str);

	if (str.Find(_T('*/')) != -1) {
		for (int i = 0; i < parseStrCount; i++) {
			if (parseStr[i] == _T('*') || parseStr[i] == _T('/')) {
				subStr.Empty(); // 새로운 반복을 위해 초기화
				// subStr에 값을 연결
				for (int j = 0; j < operandCount; j++) {
					if (parseStr[i - 1] == operandArr[j]) {
						subStr += operandArr[j] + _T(" ") + parseStr[i] + _T(" ");
					}
					if (parseStr[i + 1] == operandArr[j]) {
						subStr += operandArr[j];
					}
				}
				calculatedStr = Calculate(subStr);
				str.Replace(subStr, calculatedStr);
				StrParse(str);
			}
		}
		if (parseStrCount == 1) {
			return str;
		}
		else {
			MultipleCalc(str);
		}
	}

	if (str.Find(_T('+-'))!= -1) {
		for (int i = 0; i < parseStrCount; i++) {
			if (str[i] == _T('+') || str[i] == _T('-')) {
				subStr.Empty(); // 새로운 반복을 위해 초기화

				CString leftOperand;  // 왼쪽 피연산자
				TCHAR operate = _T('\0'); // 연산자
				CString rightOperand;  // 오른쪽 피연산자

				leftOperand = str.Mid(0, i);
				operate = str[i];
				rightOperand = str.Mid(i + 1);



				calculatedStr = Calculate(subStr);
				str.Replace(subStr, calculatedStr);
				StrParse(str);
			}
		}
		if (parseStrCount == 1) {
			return str;
		}
		else {
			MultipleCalc(str);
		}
	}

	return str;
}

CString CCalcDlg::MultipleCalc2(CString& str) {
	CString leftOperand; // 왼쪽 피연산자
	TCHAR operate; // 연산자
	CString rightOperand; // 오른쪽 피연산자
	CString subStr; // 다항연산식 중간의 단항연산식
	CString calculatedStr; // subStr가 계산된 '값'

	int index;

	while ((index = str.FindOneOf(_T("*/"))) != -1) { 
		if (index != -1) {
			leftOperand = str.Mid(0, index);
			operate = str[index];

			CString temp = str.Mid(index + 1);
			int index2 = temp.FindOneOf(_T("*/+-"));
			if (index2 != -1) {
				rightOperand = temp.Mid(0, index2);
			}
			else {
				rightOperand = str.Mid(index + 1);
			}
			subStr = leftOperand + operate + rightOperand;
			calculatedStr = Calculate(subStr);
			str.Replace(subStr, calculatedStr);
		}
		else {
			break;
		}
	}
	
	while ((index = str.FindOneOf(_T("+-"))) != -1) {
		if (index != -1) {
			leftOperand = str.Mid(0, index);
			operate = str[index];

			CString temp = str.Mid(index + 1);
			int index2 = temp.FindOneOf(_T("+-"));
			if (index2 != -1) {
				rightOperand = temp.Mid(0, index2);
			}
			else {
				rightOperand = str.Mid(index + 1);
			}
			subStr = leftOperand + operate + rightOperand;
			calculatedStr = Calculate(subStr);
			str.Replace(subStr, calculatedStr);
		}
		else {
			break;
		}
	}
	
	return str;

}

// subStr가 들어올 사칙연산 함수
CString CCalcDlg::Calculate(CString& str)
{
	CString result = _T(""); // 리턴할 CString변수 선언
	double temp = 0;	// 계산된 값을 저장하는 double변수

	CString leftOperand;  // 왼쪽 피연산자
	TCHAR operate = _T('\0'); // 연산자
	CString rightOperand;  // 오른쪽 피연산자

	for (int i = 0; i < str.GetLength(); i++) {
		if (str[i] == _T('+') || str[i] == _T('-') || str[i] == _T('*') || str[i] == _T('/')) {
			leftOperand = str.Mid(0, i);
			operate = str[i];
			rightOperand = str.Mid(i + 1);
		}
	}

	double leftOperandValue = _ttof(leftOperand);	// 나누어진 피연산자 형변환
	double rightOperandValue = _ttof(rightOperand);

	// (* / + -)처리하기
	switch (operate) {
	case _T('*'):
		temp = leftOperandValue * rightOperandValue;
		break;

	case _T('/'):
		if (rightOperandValue != 0) {
			temp = leftOperandValue / rightOperandValue;
		}
		else {
			AfxMessageBox(_T("0으로 나눌 수 없습니다."));
			return 0; // 오류 처리 후 종료
		}
		break;

	case _T('+'):
		temp = leftOperandValue + rightOperandValue;
		break;

	case _T('-'):
		temp = leftOperandValue - rightOperandValue;
		break;

	default:
		break;
	}

	result.Format(_T("%f"), temp);

	return result;
}

// 오류검사
bool CCalcDlg::ErrorCheck(CString& str) {

	// 연산식이 유효한지 검사
	if (openParenCount != closeParenCount) { // 괄호 개수 검사
		AfxMessageBox(_T("올바른 식 입력해주세요."));
		return false; // 오류 처리 후 종료
	}
	// 숫자 1개 들어올때
	else if (m_EDITDisplay.FindOneOf(_T("0123456789")) != -1 && m_EDITDisplay.FindOneOf(_T("*/+-")) == -1 && m_EDITDisplay.FindOneOf(_T("()")) == -1) {
		return true;
	}
	else if (operateCount != operandCount - 1) { // 연산자 개수 검사
		AfxMessageBox(_T("올바른 식 입력해주세요."));
		return false;
	}
	else if (str.Find(_T(")  (")) != -1 || str.Find(_T("(  )")) != -1) { //  ") (" "( )" 일때 오류
		AfxMessageBox(_T("올바른 식 입력해주세요."));
		return false;
	}
	else if (ConsecutiveOpCheck()) { // 연속된 피연산자, 연산자 검사
		AfxMessageBox(_T("올바른 식 입력해주세요."));
		return false;
	}
	else if (ParenOperateCheck(str)){ // 괄호+연산자 || 연산자+괄호 검사 || )로 시작 || ( 로 끝 || +로 시작 || +로 끝
		AfxMessageBox(_T("올바른 식 입력해주세요."));
		return false;
	}
	
	return true;
}

// 오류검사(ErrorCheck) - 괄호+연산자 || 연산자+괄호 검사 || )로 시작 || ( 로 끝 || +로 시작 || +로 끝 ex. "( +" "- )"
bool CCalcDlg::ParenOperateCheck(CString& str) {
    if (str.Find(_T("(  +")) != -1 || str.Find(_T("(  -")) != -1 || str.Find(_T("(  *")) != -1 || str.Find(_T("(  /")) != -1) { // (+ 이 발견되면 
        return true;
    }
    else if (str.Find(_T("+  )")) != -1 || str.Find(_T("-  )")) != -1 || str.Find(_T("*  )")) != -1 || str.Find(_T("/  )")) != -1) { // +) 이 발견되면 
        return true;
    }
    else if (parseStr[0] == _T(')') 
        || parseStr[0] == _T('+') 
		|| parseStr[0] == _T('-')
        || parseStr[0] == _T('*') 
		|| parseStr[0] == _T('/')
		|| parseStr[parseStrCount - 1] == _T('(')
        || parseStr[parseStrCount - 1] == _T('+') 
		|| parseStr[parseStrCount - 1] == _T('-')
        || parseStr[parseStrCount - 1] == _T('*') 
		|| parseStr[parseStrCount - 1] == _T('/')
        ) {
        return true;
    }
    return false;
}

// 오류검사(ErrorCheck) - 연속된 피연산자, 연산자 검사
bool CCalcDlg::ConsecutiveOpCheck() {
	for (int i = 1; i < operandCount; i++) {
		if (operandIndexArr[i] - operandIndexArr[i - 1] == 1) {
			return true; // 연속됐으면 true
		}
	}
	for (int i = 1; i < operateCount; i++) {
		if (operateIndexArr[i] - operateIndexArr[i - 1] == 1) {
			return true; // 연속됐으면 true
		}
	}
	return false;
}

// 전체 파싱
void CCalcDlg::StrParse(CString& str) {
	// 공백을 기준으로 문자열을 나누기
	// 전체 초기화
	int start = 0;
	int end = str.Find(_T(' '));
	int i = 0;
	parseStrCount = 0;
	for (int i = 0; i < 1000; i++) {
		parseStr[i].Empty();
		operandArr[i].Empty();
		operateArr[i].Empty();
	}
	operandCount = 0;
	operateCount = 0;
	openParenCount = 0;
	closeParenCount = 0;

	if (end != -1) {
		while (end != -1) {
			if (end != 0) {
				parseStr[i] = str.Mid(start, end - start);
				i++;
			}
			start = end + 1;
			end = str.Find(_T(' '), start);
		}
		// 마지막 단어 처리
		parseStr[i] = str.Mid(start);

		// 파싱된 문자열의 개수 업데이트
		parseStrCount = i + 1;

		// 각각 분리하기
		OperandParse();
		OperateParse();
		ParenParse();
	}
	else {
		parseStrCount = 1;
	}
}

// 피연산자 파싱
void CCalcDlg::OperandParse() {
	operandCount = 0; // 피연산자 개수
	int operandIndexCount = 0; // 피연산자 인덱스 개수
	CString currentToken;

	for (int i = 0; i < parseStrCount; i++) {
		currentToken = parseStr[i];

		// 숫자, 소수점이 포함된 숫자인 경우
		if (currentToken.FindOneOf(_T("0123456789.")) != -1) {
			operandArr[operandCount++] = currentToken; // 피연산자를 피연산자 배열에 저장
			operandIndexArr[operandIndexCount++] = i; // 피연산자 인덱스 저장
		}
	}
}

// 연산자 파싱
void CCalcDlg::OperateParse() {
	operateCount = 0; // 연산자 개수
	int operateIndexCount = 0; // 연산자 인덱스 개수
	CString operate;

	for (int i = 0; i < parseStrCount; i++) {
		CString currentToken = parseStr[i];

		if (currentToken == '+' || currentToken == '-' || currentToken == '*' || currentToken == '/'){
			// 현재 토큰이 연산자인 경우
			operateArr[operateCount++] = currentToken;
			operateIndexArr[operateIndexCount++] = i;
		}
	}
}

// 괄호 파싱
void CCalcDlg::ParenParse() {
	openParenCount = 0; // 여는 괄호 개수
	closeParenCount = 0; // 닫는 괄호 개수
	CString openParen;
	CString closeParen;

	for (int i = 0; i < parseStrCount; i++) {
		CString currentToken = parseStr[i];

		if (currentToken == _T("(")) {
			// 현재 토큰이 여는 괄호인 경우
			openParenCount++;
			openParenArrIndexArr[openParenCount - 1] = i;
		}
		else if (currentToken == _T(")")) {
			// 현재 토큰이 닫는 괄호인 경우
			closeParenCount++;
			closeParenArrIndexArr[closeParenCount - 1] = i;
		}
	}
}




