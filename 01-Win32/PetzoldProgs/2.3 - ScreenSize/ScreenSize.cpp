#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CDECL MessageBoxPrintf(TCHAR* szCaption, TCHAR* szFormat, ...) {
	TCHAR szBuffer[1024]; 
	va_list pArgList;
		// The va_start macro (defined in STDARG.H) is usually equivalent to: 
		// pArgList = (char *) &szFormat + sizeof (szFormat) ;
	
	va_start(pArgList, szFormat); 
		// The last argument to wvsprintf points to the arguments
	
	_vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
	
	// The va_end macro just zeroes out pArgList for no good reason va_end (pArgList);
	va_end(pArgList);
	return MessageBox(NULL, szBuffer, szCaption, 0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	int cxScreen, cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN); 
	cyScreen = GetSystemMetrics(SM_CYSCREEN); 
	
	MessageBoxPrintf(TEXT("ScrnSize"), TEXT("The screen is %i pixels wide by %i pixels high."), cxScreen, cyScreen);
	return 0;

}

/*LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:

	}
}*/