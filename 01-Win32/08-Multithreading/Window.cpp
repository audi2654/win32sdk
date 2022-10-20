//Lecture: 21st July 2021
//Multithreading

//add kernel32.lib while linking

#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Variable declarations
	WNDCLASSEX wndclass;	
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("UniqueClassName");

	//Code
	wndclass.cbSize = sizeof(WNDCLASSEX);							
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						
	wndclass.lpfnWndProc = WndProc;									
	wndclass.cbClsExtra = 0;										
	wndclass.cbWndExtra = 0;										
	wndclass.hInstance = hInstance;									
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;								
	wndclass.lpszMenuName = NULL;									
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);				

	RegisterClassEx(&wndclass);		

	//Create the window in memory	
	hwnd = CreateWindow(
		szAppName,
		TEXT("AMP: MyFirstWindow"),
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

	return((int)msg.wParam); 

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//if we are using across the msgs local variables they should be declared as Static
	static HANDLE hThreadOne = NULL;
	static HANDLE hThreadTwo = NULL;
	
	switch (iMsg)
	{
	case WM_CREATE:
		hThreadOne = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd, 0, NULL);
		//Here there should be error checking for hThreadOne
		hThreadTwo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0, NULL);
		//Here there should be error checking for hThreadTwo
		break;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("I'm Thread No. 4"), TEXT("Message Caption"), MB_OK);
		break;

	case WM_DESTROY:
		CloseHandle(hThreadOne); //even if you don't close here, thread is a kernel obj hence OS will close it anyway when program ends, but its a good practice to reduce the work of machine OS
		CloseHandle(hThreadTwo);
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}

DWORD WINAPI ThreadProcOne(LPVOID param) 
{
	//Local variable declarations
	HDC hdc = NULL;
	TCHAR str[255];
	long i;

	//Code
	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	for (i = 0; i < 2147483647; i++)
	{
		wsprintf(str, TEXT("Incrementing Order  : %ld"), i);
		TextOut(hdc, 5, 5, str, (int)_tcslen(str));
	}
	ReleaseDC((HWND)param, hdc);
	return 0;
}

DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	//Local variable declarations
	HDC hdc = NULL;
	TCHAR str[255];
	long i;

	//Code
	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 0, 0));

	for (i = 2147483647; i >= 0; i--)
	{
		wsprintf(str, TEXT("Decrementing Order : %ld"), i);
		TextOut(hdc, 5, 25, str, (int)_tcslen(str));
	}
	ReleaseDC((HWND)param, hdc);
	return 0;
}


//Important Thread Functions
/*
	-TerminateThread();
		GetExitCodeThread();

	-ExitThread();
		GetExitCodeThread();

	-DWORD SuspendThread();
	 DWORD ResumeThread();

	-GetPriorityClass
	 SetPriorityClass

	-GetThreadPriority
	 SetThreadPriority

*/