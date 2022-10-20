#include <windows.h>
#include "MyMathOne.h"
#include "MyMathTwo.h"
//" " used to include headers files from Local Directory which has signature, declaration or prototype of function 
//that may be used in the below program

#pragma comment(lib, "MyMathTwo.lib")
#pragma comment(lib, "MyMathOne.lib")		//to include MyMath.lib directly implicitly from inside program code

//You can include commonly used import libraries like below instead of command line
/*#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")*/


//Link command to use: link.exe Window.obj user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS

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
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
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
	case WM_CREATE:
		MakeSquare(30);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}