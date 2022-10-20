//Painting Program Practice Wnd - 1

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("UniqueClassName");

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndclass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hInstance = hInstance;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_ASTERISK);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(
		szAppName,
		TEXT("Painting Prac Wnd - 1"),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		400,
		500,
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
	HDC hdc;
	RECT rc;
	PAINTSTRUCT ps;
	HBRUSH hbrush;
	static int iPaintFlag = 0;

	switch (iMsg)
	{
	case WM_CHAR:
	{
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			iPaintFlag = 1;
			//InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'G':
		case 'g':
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'B':
		case 'b':
			iPaintFlag = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'Q':
		case 'q':
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'W':
		case 'w':
			iPaintFlag = 5;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'e':
		case 'E':
			iPaintFlag = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 't':
		case 'T':
			iPaintFlag = 7;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'Y':
		case 'y':
			iPaintFlag = 8;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	}

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);

		if (iPaintFlag == 1)
		{
			hbrush = CreateSolidBrush(RGB(255, 0, 0));
		}
		else if (iPaintFlag == 2)
		{
			hbrush = CreateSolidBrush(RGB(0, 255, 0));
		}
		else if (iPaintFlag == 3)
		{
			hbrush = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (iPaintFlag == 4)
		{
			hbrush = CreateSolidBrush(RGB(232, 204, 215));
		}
		else if (iPaintFlag == 5)
		{
			hbrush = CreateSolidBrush(RGB(124, 152, 171));
		}
		else if (iPaintFlag == 6)
		{
			hbrush = CreateSolidBrush(RGB(227, 38, 54));
		}
		else if (iPaintFlag == 7)
		{
			hbrush = CreateSolidBrush(RGB(176, 100, 227));
		}
		else if (iPaintFlag == 8)
		{
			hbrush = CreateSolidBrush(RGB(238, 230, 0));
		}

		SelectObject(hdc, hbrush);
		FillRect(hdc, &rc, hbrush);
		DeleteObject(hbrush);

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

