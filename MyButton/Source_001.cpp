//#include <iostream>
//c:\Windows\System32\user32.dll
//using namespace std;



#include <windows.h>
#include <Winuser.h>
//#pragma comment(lib,"User32.lib")
//#define NUM (sizeof button / sizeof button[0])
#define NUM 5

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{


	static LPCTSTR szAppName = L"HelloMyWin";
	HWND        hwnd;
	MSG         msg;
	WNDCLASSEX  wndclass;		// —труктура дл€ хранени€ атрибутов  окна 

	wndclass.cbSize = sizeof (wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);


	hwnd = CreateWindow(szAppName,         // window class name
		szAppName,     // window caption
		WS_OVERLAPPEDWINDOW,     // window style
		CW_USEDEFAULT,           // initial x position
		CW_USEDEFAULT,           // initial y position
		CW_USEDEFAULT,           // initial x size
		CW_USEDEFAULT,           // initial y size
		NULL,                    // parent window handle
		NULL,                    // window menu handle
		hInstance,               // program instance handle
		NULL);		             // creation parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	;
	//	     static char  szHeading [] =
	//                   "Mapping Mode            Left   Right     Top  Bottom" ;
	//    static char  szUndLine [] = 
	//                    "------------            ----   -----     ---  ------" ;
	static HWND  hwndButton[NUM];
	static int  cxClient, cyClient;
	//     HDC         hdc ;
	int         i,iY=25;
	//     PAINTSTRUCT ps ;
	//    POINT       pt [NUM] ;
	//	static int  cxChar,  cyChar;
	//    TEXTMETRIC  tm ;
	//static LPCTSTR szBtnName = L"button";
static LPCTSTR szBtnName[] = { L"BUTTON 1", L"BUTTON 2", L"BUTTON 3", L"BUTTON 4" };
long szBtnStyle[] = { BS_PUSHBUTTON, BS_CHECKBOX, BS_RADIOBUTTON, BS_RADIOBUTTON };
	switch (iMsg)
	{
		
	case WM_CREATE:
		for (i= 0; i < 4; i++)
		{

			hwndButton[i]=CreateWindow(L"BUTTON", szBtnName[i], WS_CHILD | WS_VISIBLE | szBtnStyle[i],
				20, iY, 200, 25, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
			iY=iY + 50;
		}
		/*CreateWindow(L"BUTTON", L"BS_CHECKBOX", WS_CHILD |BS_CHECKBOX | WS_VISIBLE | BS_PUSHBUTTON,
			20, 25, 200, 25, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		CreateWindow(L"BUTTON", L"BUTTON 2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 105, 100, 50, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		CreateWindow(L"BUTTON", L"BS_RADIOBUTTON", BS_RADIOBUTTON | WS_CHILD | WS_VISIBLE,
			20, 205, 200, 25, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		CreateWindow(L"BUTTON", L"BUTTON 2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 305, 150, 50, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);*/
		return 0;
		
//	case	WM_COMMAND:
//		BN_CLICKED

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
		;



	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
