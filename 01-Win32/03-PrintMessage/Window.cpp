#include <windows.h> 

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
	while (GetMessage(&msg, NULL, 0, 0))	//GetMessage here is Straw in the Message Pool
	{	
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int num1, num2, num3;
	TCHAR str[255];

	switch (iMsg)
	{
	case WM_CREATE:					//Sending of a Message
		num1 = 300; 
		num2 = 200;
		num3 = num1 + num2;
		wsprintf(str, TEXT("Addition of %d & %d is %d"), num1, num2, num3);			//wide string printf
		MessageBox(hwnd, str, TEXT("ADDITION"), MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
