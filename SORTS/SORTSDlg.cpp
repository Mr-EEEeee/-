
// SORTSDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SORTS.h"
#include "SORTSDlg.h"
#include "afxdialogex.h"
#include "s.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CSORTSDlg 对话框



CSORTSDlg::CSORTSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SORTS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSORTSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSORTSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSORTSDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSORTSDlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT1, &CSORTSDlg::OnEnChangeEdit1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSORTSDlg 消息处理程序

BOOL CSORTSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSORTSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSORTSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSORTSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSORTSDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	create(a);
	
	InsertSort(a);
	CListBox* listbox3 = (CListBox*)GetDlgItem(IDC_LIST3);
	listbox3->AddString(ss1);
	CListBox* listbox2 = (CListBox*)GetDlgItem(IDC_LIST2);
	listbox2->AddString(xs1);
	CListBox* listbox1 = (CListBox*)GetDlgItem(IDC_LIST1);
	CString cs1(s.c_str());
	listbox1->AddString(cs1);
	
	ShellSort(a);
	CListBox* listbox4 = (CListBox*)GetDlgItem(IDC_LIST4);
	listbox4->AddString(ss2);
	CListBox* listbox5 = (CListBox*)GetDlgItem(IDC_LIST5);
	listbox5->AddString(xs2);
	CString cs2(s.c_str());
	listbox1->AddString(cs2);
	
	BubbleSort(a);
	CListBox* listbox6 = (CListBox*)GetDlgItem(IDC_LIST6);
	listbox6->AddString(ss3);
	CListBox* listbox7 = (CListBox*)GetDlgItem(IDC_LIST7);
	listbox7->AddString(xs3);
	CString cs3(s.c_str());
	listbox1->AddString(cs3);

	heapSort(a);
	CListBox* listbox10 = (CListBox*)GetDlgItem(IDC_LIST10);
	listbox10->AddString(ss5);
	CListBox* listbox11 = (CListBox*)GetDlgItem(IDC_LIST11);
	listbox11->AddString(xs5);
	CString cs5(s.c_str());
	listbox1->AddString(cs5);

	easySort(a);
	CListBox* listbox12 = (CListBox*)GetDlgItem(IDC_LIST12);
	listbox12->AddString(ss6);
	CListBox* listbox13 = (CListBox*)GetDlgItem(IDC_LIST13);
	listbox13->AddString(xs6);
	CString cs6(s.c_str());
	listbox1->AddString(cs6);
	
	n = 0; m = 0;
	int start = clock();
	QuickSort(a, 0, L - 1);
	int end = clock();
	ss4.Format(_T("%d"), n);
	xs4.Format(_T("%d"), m);
	CListBox* listbox8 = (CListBox*)GetDlgItem(IDC_LIST8);
	listbox8->AddString(ss4);
	CListBox* listbox9 = (CListBox*)GetDlgItem(IDC_LIST9);
	listbox9->AddString(xs4);
	ostringstream cout;
	n4 = log(n/chu1); m4 = log(m / chu2); t4 = log((end - start) / chu3);
	cout << "快速排序: " << end - start << " ms" << endl;
	s = cout.str();
	CString cs4(s.c_str());
	listbox1->AddString(cs4);

	CDC* pORIDC = GetDC();
	HDC hdc = pORIDC->GetSafeHdc();
	HBRUSH hBr;
	hBr = CreateSolidBrush(	RGB(254, 67, 101));
	SelectObject(hdc, hBr); 
	Pie(// o(800,500)
		hdc,
		700,400,
		900,600,
		900,500,
		pl1(n1).x,pl1(n1).y
	);
	Pie(// o(200,500)
		hdc,
		100, 400,
		300, 600,
		900, 500,
		pl2(m1).x, pl2(m1).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		900, 540,
		pl3(t1).x, pl3(t1).y
	);

	hBr = CreateSolidBrush(RGB(253, 157, 154));
	SelectObject(hdc, hBr);
	Pie(// o(800,500)
		hdc,
		700, 400,
		900, 600,
		pl1(n1).x, pl1(n1).y,
		pl1(n1+ n2).x,pl1(n1+ n2).y
	);
	Pie(// o(200,500)
		hdc,
		100, 400,
		300, 600,
		pl2(m1).x, pl2(m1).y,
		pl2(m1 + m2).x, pl2(m1 + m2).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		pl3(t1).x, pl3(t1).y,
		pl3(t1+t2).x, pl3(t1+t2).y
	);


	hBr = CreateSolidBrush(RGB(249, 205, 173));
	SelectObject(hdc, hBr);
	Pie(// o(800,500)
		hdc,
		700, 400,
		900, 600,
		pl1(n1 + n2).x, pl1(n1 + n2).y,
		pl1(n1 + n2+ n3).x, pl1(n1 + n2+ n3).y
	);
	Pie(// o(200,500)
		hdc,
		100, 400,
		300, 600,
		pl2(m1+m2).x, pl2(m1+m2).y,
		pl2(m1 + m2+m3).x, pl2(m1 + m2+m3).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		pl3(t1 + t2).x, pl3(t1 + t2).y,
		pl3(t1 + t2+t3).x, pl3(t1 + t2+t3).y
	);

	hBr = CreateSolidBrush(RGB(200, 200, 169));
	SelectObject(hdc, hBr);
	Pie(// o(800,500)
		hdc,
		700, 400,
		900, 600,
		pl1(n1 + n2 + n3).x, pl1(n1 + n2 + n3).y,
		pl1(n1 + n2 + n3+ n4).x, pl1(n1 + n2 + n3+ n4).y
	);
	Pie(// o(200,500)
		hdc,
		100, 400,
		300, 600,
		pl2(m1 + m2 + m3).x, pl2(m1 + m2 + m3).y,
		pl2(m1 + m2 + m3 + m4).x, pl2(m1 + m2 + m3 + m4).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		pl3(t1 + t2 + t3).x, pl3(t1 + t2 + t3).y,
		pl3(t1 + t2 + t3+t4).x, pl3(t1 + t2 + t3 + t4).y
	);
	

	hBr = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBr);
	Pie(// o(800,500)
		hdc,
		700, 400,
		900, 600,
		pl1(n1 + n2 + n3+ n4).x, pl1(n1 + n2 + n3+ n4).y,
		pl1(n1 + n2 + n3 + n4+ n5).x, pl1(n1 + n2 + n3 + n4+ n5).y
	); 
	Pie(// o(200,500)
		hdc,
		100, 400,
		300, 600,
		pl2(m1 + m2 + m3+m4).x, pl2(m1 + m2 + m3+m4).y,
		pl2(m1 + m2 + m3+m5 + m4).x, pl2(m1 + m2 + m3+m5 + m4).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		pl3(t1 + t2 + t3 + t4).x, pl3(t1 + t2 + t3 + t4).y,
		pl3(t1 + t2 + t3 + t4+t5).x, pl3(t1 + t2 + t3 + t4 + t5).y
	);
	

	hBr = CreateSolidBrush(RGB(34, 75, 155));
	SelectObject(hdc, hBr);
	Pie(// o(800,500)
		hdc,
		700, 400,
		900, 600,
		pl1(n1 + n2 + n3 + n4+ n5).x, pl1(n1 + n2 + n3 + n4+ n5).y,
		pl1(n1 + n2 + n3 + n4 + n5+ n6).x, pl1(n1 + n2 + n3 + n4 + n5+ n6).y
	);
	Pie(// o(500,540)
		hdc,
		400, 440,
		600, 640,
		pl3(t1 + t2 + t3 + t4 + t5).x, pl3(t1 + t2 + t3 + t4 + t5).y,
		pl3(t1 + t2 + t3 + t4 + t5+t6).x, pl3(t1 + t2 + t3 + t4 + t5+t6).y
	);

}


void CSORTSDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CSORTSDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


HBRUSH CSORTSDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1) {
			//pDC->SetTextColor(RGB(54, 245, 79));	// 文字颜色
			pDC->SetBkColor(RGB(254, 67, 101));	// 背景色（只是文字部分，不是整个控件）
		}  
	if (pWnd->GetDlgCtrlID() == IDC_STATIC2) {
		//pDC->SetTextColor(RGB(16, 117, 232));	// 文字颜色
		pDC->SetBkColor(RGB(253, 157, 154));
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC3) {
		//pDC->SetTextColor(RGB(16, 117, 232));	// 文字颜色
		pDC->SetBkColor(RGB(249, 205, 173));
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC4) {
		//pDC->SetTextColor(RGB(16, 117, 232));	// 文字颜色
		pDC->SetBkColor(RGB(200, 200, 169));
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC5) {
		//pDC->SetTextColor(RGB(16, 117, 232));	// 文字颜色
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC6) {
		//pDC->SetTextColor(RGB(16, 117, 232));	// 文字颜色
		pDC->SetBkColor(RGB(34, 75, 155));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
