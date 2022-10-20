#include <windows.h>
#include "Window.h"

//cl.exe /c /EHsc Window.c
//rc.exe Window.rc	-generates Window.res file
//link.exe Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

//Global Variable declarations

//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Variable declarations
	WNDCLASSEX wndclass;	
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");

	//Code
	wndclass.cbSize = sizeof(WNDCLASSEX);							
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						
	wndclass.lpfnWndProc = WndProc;									
	wndclass.cbClsExtra = 0;										
	wndclass.cbWndExtra = 0;										
	wndclass.hInstance = hInstance;									
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));				
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
	wndclass.lpszClassName = szAppName;								
	wndclass.lpszMenuName = NULL;									
	//wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
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

	//Message Loop 
	while (GetMessage(&msg, NULL, 0, 0))  //GetMessage here is Straw in the Message Pool
	{	
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam); 

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}