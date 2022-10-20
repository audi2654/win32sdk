//Multithreading Prac Wnd - 1
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("UniqueClassName");

	HBRUSH hbrush = CreateSolidBrush(RGB(159, 231, 100));

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wndclass.hbrBackground = hbrush;
	wndclass.hCursor = LoadCursor(NULL, IDC_HELP);
	wndclass.hInstance = hInstance;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(
		szAppName,
		TEXT("Multithreading Prac Wnd - 2"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HANDLE hThreadOne = NULL;
	static HANDLE hThreadTwo = NULL;

	switch (iMsg)
	{
	case WM_CREATE:
		hThreadOne = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd, 0, NULL);

		hThreadTwo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0, NULL);
		break;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("LBUTTON Pressed"), TEXT("Msg Box Caption"), MB_OK);
		break;

	case WM_DESTROY:
		CloseHandle(hThreadOne);
		CloseHandle(hThreadTwo);
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}

DWORD WINAPI ThreadProcOne(LPVOID param)
{
	HDC hdc = NULL;
	TCHAR str[255];
	long i;

	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(63, 25, 64));
	SetTextColor(hdc, RGB(123, 231, 254));

	for (i = 0; i < 87654321; i++)
	{
		wsprintf(str, TEXT("Incrementing Order : %ld"), i);
		TextOut(hdc, 500, 300, str, (int)_tcslen(str));
	}
	ReleaseDC((HWND)param, hdc);
	return 0;

}

DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	HDC hdc = NULL;
	TCHAR str[255];
	long i;

	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(41, 52, 63));
	SetTextColor(hdc, RGB(04, 177, 99));

	for (i = 87654321; i >= 0; i--)
	{
		wsprintf(str, TEXT("Decrementing Order : %ld"), i);
		TextOut(hdc, 500, 325, str, (int)_tcslen(str));
	}
	ReleaseDC((HWND)param, hdc);
	return 0;

}