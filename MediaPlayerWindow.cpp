#include<Windows.h>
#define MYTIMER 100
//global function declaration
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreviousInstance,LPSTR plzCmdLine,int iCmdShow) {
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("PAVAN");

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;		
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndClass);

	hwnd = CreateWindow(szAppName, TEXT("My Media Player"), WS_OVERLAPPEDWINDOW, 300, 100, 400, 400, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	TCHAR str[255];
	HDC hdc;
	PAINTSTRUCT ps;
	static int status;
	static int rectStatus = 0;
	RECT rc;
	
	GetClientRect(hwnd, &rc);
	RECT rcTemp;
	rcTemp.bottom = rc.bottom;
	rcTemp.left = rc.left;
	rcTemp.right = (rc.right)/3;
	rcTemp.top = rc.top;
	static int timer = 3000;
	RECT rcTemp1;
	rcTemp1.bottom = rc.bottom;
	rcTemp1.left = (rc.right) / 3;
	rcTemp1.right = (rc.right)/3+ (rc.right) / 3;
	rcTemp1.top = rc.top;
	RECT rcTemp2;
	rcTemp2.bottom = rc.bottom;
	rcTemp2.left = rcTemp1.right;
	rcTemp2.right = rcTemp1.right + (rc.right) / 3;
	rcTemp2.top = rc.top;


	TCHAR str1[] = TEXT("Hello World...");
	switch (iMsg)
	{
	case WM_CLOSE:
		if (MessageBox(hwnd, L"Really quit?", L"My Media Player", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hwnd);
		}
		// Else: User canceled. Do nothing.
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		status = 0;
		HINSTANCE hInstance;
		static HBITMAP hBitMap;
		hInstance=GetModuleHandle(NULL);
		hBitMap = LoadBitmap(hInstance,TEXT("MYBITMAP"));
	
		SetTimer(hwnd, MYTIMER, timer, NULL);
		wsprintf(str, TEXT("MEDIA PLAYER IS STARTING......"));
		MessageBox(hwnd, str, TEXT("Media Player"), MB_HELP | MB_ICONINFORMATION);

		break;
	case WM_PAINT:
		
	
		switch (rectStatus)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
		
		if (1==status) {
			
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
			hdc = BeginPaint(hwnd, &ps);

			SelectObject(hdc, hBrush);
			//SetTextColor(hdc, RGB(0, 255, 0));
			//SetBkColor(hdc, RGB(0, 0, 0));
			//DrawText(hdc, str1, -1, &rc, DT_SINGLELINE | DT_VCENTER);

			FillRect(hdc, &rc, hBrush);
			EndPaint(hwnd, &ps);
			DeleteObject(hBrush);
		}	
		if (2 == status) {
			
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
			hdc = BeginPaint(hwnd, &ps);

			SelectObject(hdc, hBrush);
			//SetTextColor(hdc, RGB(0, 255, 0));
			//SetBkColor(hdc, RGB(0, 0, 0));
			//DrawText(hdc, str1, -1, &rc, DT_SINGLELINE | DT_VCENTER);

			FillRect(hdc, &rcTemp, hBrush);
			EndPaint(hwnd, &ps);
			DeleteObject(hBrush);
		}
		if (3 == status) {
			
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
			hdc = BeginPaint(hwnd, &ps);

			SelectObject(hdc, hBrush);
			//SetTextColor(hdc, RGB(0, 255, 0));
			//SetBkColor(hdc, RGB(0, 0, 0));
			//DrawText(hdc, str1, -1, &rc, DT_SINGLELINE | DT_VCENTER);

			FillRect(hdc, &rcTemp1, hBrush);
			EndPaint(hwnd, &ps);
			DeleteObject(hBrush);
		}
	
		break;
	case WM_TIMER:
		KillTimer(hwnd, MYTIMER);
		SetTimer(hwnd, MYTIMER, timer,NULL);
		status++;
		if (status == 5) {
			status = 0;
			status++;
		}
		
		InvalidateRect(hwnd,&rc,false);
		break;
	case WM_KEYDOWN:
		

		break;
	case WM_CHAR:
		
		//MessageBox(hwnd, TEXT(wParam), TEXT(""), MB_OK);
	
		
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			status = 1;
			InvalidateRect(hwnd,&rc,false);
			//MessageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;
		case 'G':
		case 'g':
			status = 2;
			InvalidateRect(hwnd, &rc, false);
			//MessageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;
		case 'B':
		case 'b':
			status = 3;
			InvalidateRect(hwnd, &rc, false);
		//essageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;
		case 'P':
		case 'p':
			//SetTimer(hwnd, MYTIMER, 2000, NULL);
			timer = 2000;
			//status = 3;
			//InvalidateRect(hwnd, &rc, false);
			//essageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;
		case 'Q':
		case 'q':
			//SetTimer(hwnd, MYTIMER, 1000, NULL);
			timer = 1000;
			//status = 3;
			//InvalidateRect(hwnd, &rc, false);
			//essageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;

		case 'Z':
		case 'z':
			//SetTimer(hwnd, MYTIMER, 1000, NULL);
			timer = 100;
			//status = 3;
			//InvalidateRect(hwnd, &rc, false);
			//essageBox(hwnd, TEXT("A"), TEXT(""), MB_OK);
			break;

		default:
			break;
		}
		break;
	

	default:
		break;
	}
	


	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
 }


