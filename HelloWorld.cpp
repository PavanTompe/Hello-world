#include<Windows.h>

//accessible to os and our program
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MYAPP");
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndClass);

	hwnd = CreateWindow(szAppName, TEXT("My Media Player"), WS_OVERLAPPEDWINDOW, 300, 100, 400, 400, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	TCHAR str[] = TEXT("Hello World");
	switch (iMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		GetClientRect(hwnd,&rc);
		hdc = BeginPaint(hwnd,&ps);
		SelectObject(hdc, hBrush);
		SetTextColor(hdc,RGB(0,255,0));
		SetBkColor(hdc,RGB(0, 0, 0));
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE|DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

