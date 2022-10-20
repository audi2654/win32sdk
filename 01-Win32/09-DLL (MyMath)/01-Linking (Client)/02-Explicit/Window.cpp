//Date: 9th Aug 2021

//Output of this file is ERROR Window

#include <windows.h>

//Use command
//cl.exe /c /EHcs Window.cpp
//link.exe Window.obj user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS

//COM & .NET use this Explicit method internally to link DLLs & doesn't depend much on OS work to link DLLs

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
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
	//Local Variable Declaration
	HMODULE hLib = NULL;

	typedef int (*PMAKECUBEFUNCTION)(int);	//Function Pointer type
	PMAKECUBEFUNCTION pMakeCube = NULL;		//Function Pointer Variable

	int num1, num2;
	TCHAR str[255];

	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		//Load our Library
		hLib = LoadLibrary(TEXT("MyMath.dll"));
		if (hLib == NULL)
		{
			//hLib = LoadLibrary(TEXT("MyMathTwo.dll"));		//Freedom to call another library if one fails
			MessageBox(hwnd, TEXT("Load Library Failed"), TEXT("ERROR Caption Text"), MB_OK);
			DestroyWindow(hwnd);
		}

		//Store address of function from library
		pMakeCube = (PMAKECUBEFUNCTION)GetProcAddress(hLib, "MakeCube");		
		//We don't use TEXT("MakeCube") because you can use this API over network too & those network socket APIs are still today also in ANSI format
		if (pMakeCube == NULL)
		{
			MessageBox(hwnd, TEXT("MakeCube Function address can't be obtained"), TEXT("ERROR"), MB_OK);
			DestroyWindow(hwnd);
		}

		num1 = 15;
		num2 = pMakeCube(num1);

		wsprintf(str, TEXT("Cube of %d is %d"), num1, num2);
		MessageBox(hwnd, str, TEXT("Explicitly Loaded Dll"), MB_OK);

		FreeLibrary(hLib);			//to unload the loaded DLL, if you don't call this OS will
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}