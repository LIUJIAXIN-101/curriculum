
// MyCalcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyCalc.h"
#include "MyCalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
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


// CMyCalcDlg �Ի���



CMyCalcDlg::CMyCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYCALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CMyCalcDlg::OnBnClickedButtonEqu)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMyCalcDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CMyCalcDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CMyCalcDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CMyCalcDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMyCalcDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMyCalcDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CMyCalcDlg::OnBnClickedButtonFour)
END_MESSAGE_MAP()


// CMyCalcDlg ��Ϣ�������

BOOL CMyCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString strValue = L"0";




void CMyCalcDlg::OnBnClickedButtonClear()
{
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(L"");
}


void CMyCalcDlg::OnBnClickedButtonOne()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);
	cur += L"1";
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(cur);

}


void CMyCalcDlg::OnBnClickedButtonTwo()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);
	cur += L"2";
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(cur);
}


void CMyCalcDlg::OnBnClickedButtonThree()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);
	cur += L"3";
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(cur);
}

int first = 0;
int second = 0;
int add = 0;

void CMyCalcDlg::OnBnClickedButtonAdd()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);

	if (cur.IsEmpty())
		return;
	
	first = _ttoi(cur);
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(L"");
	add = 1;
}


void CMyCalcDlg::OnBnClickedButtonSub()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);

	if (cur.IsEmpty())
		return;

	first = _ttoi(cur);
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(L"");

	add = -1;
}

void CMyCalcDlg::OnBnClickedButtonEqu()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);

	if (cur.IsEmpty())
	{
		MessageBox(L"û�в�����", L"Info", MB_ICONERROR);
		return;
	}
	

	second = _ttoi(cur);
	//GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(L"");
	
	int res = add == 1 ? first + second : first - second;

	//cur.Format(_T("%d"), res);

	cur.Format(_T("%d%s%d=%d"),first, add==1?L"+" :L"-",second, res);
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(cur);
}

void CMyCalcDlg::OnBnClickedButtonFour()
{
	CString cur;
	GetDlgItem(IDC_EDIT_SHOW)->GetWindowText(cur);
	cur += L"4";
	GetDlgItem(IDC_EDIT_SHOW)->SetWindowText(cur);
}
