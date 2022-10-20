#include <windows.h> 

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 


//Global Variable declarations


//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Variable declarations
	WNDCLASSEX wndclass;	//STEP-1
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");

	//Code
	wndclass.cbSize = sizeof(WNDCLASSEX);							//1
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						//2
	wndclass.lpfnWndProc = WndProc;									//3
	wndclass.cbClsExtra = 0;										//4
	wndclass.cbWndExtra = 0;										//5
	wndclass.hInstance = hInstance;									//6
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//7
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					//8
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//9
	wndclass.lpszClassName = szAppName;								//10
	wndclass.lpszMenuName = NULL;									//11
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);				//12

	RegisterClassEx(&wndclass);		//STEP-2

	//Create the window in memory	//STEP-3
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

	ShowWindow(hwnd, iCmdShow);		//STEP-4	SW_MAXIMIZE, SW_MINIMIZE, SW_HIDE, SW_SHOWNORMAL also works instead of iCmdShow & it is internally SW_SHOWNORMAL as default choice of OS
	UpdateWindow(hwnd);				//STEP-5

	while (GetMessage(&msg, NULL, 0, 0))
	{	
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//return((int)msg.wParam); //OR ... 
	return (int)msg.wParam; //... also works

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Code Message Handler in Win API, in Xwindows Event Handler, in Java called as Listener. in .NET Event Delegate, 
	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("WM_CREATE Message is arrived"), TEXT("Message"), MB_OK);
		break;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("Left Mouse Button is pressed"), TEXT("Message"), MB_OK);
		break;

	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("A keyboard key is pressed"), TEXT("Message"), MB_OK);
		break;

	case WM_RBUTTONDOWN:
		MessageBox(hwnd, TEXT("Right Mouse Button is pressed"), TEXT("Message"), MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);	  //Post message WM_QUIT to this window with wParam as 0 & this msg is sent to Message Pool
		break;
		
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}

