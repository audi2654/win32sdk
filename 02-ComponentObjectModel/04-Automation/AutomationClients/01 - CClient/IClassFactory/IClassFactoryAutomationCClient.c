//Automation Flow -IClassFactory C Client file
//C++ Server binding with C Client
//Date:

//Commands to give for this file
//cl.exe /c /EHsc IClassFactoryAutomationCClient.c
//link.exe IClassFactoryAutomationCClient.obj user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS /MACHINE:X64(optional)

#include <windows.h>
#include "AutomationServerWithRegFile_C_ClassFactory.h"

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable declarations
IMyMath* pIMyMath = NULL;

//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");
	HRESULT hr;

	//Code

	//COM initialization
	hr = CoInitialize(NULL);	//COM helper function (these are all procedural internally)
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library can't be Initialized \n Program will no Exit"), TEXT("Program Error"), MB_OK);
		exit(0);
	}

	//WNDCLASSEX initialization
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

	//COM Uninitialization
	CoUninitialize();

	return((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Function declaration
	//void SafeInterfaceRelease(void);

	//Variable declarations
	HRESULT hr;
	int iNum1, iNum2, iSum;
	TCHAR str[255];

	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(&CLSID_MyMath, NULL, CLSCTX_INPROC_SERVER, &IID_IMyMath, (void**)&pIMyMath);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("Automation IClassFactory C Client - IMyMath Interface cannot be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		else
		{
			MessageBox(NULL, TEXT("Automation IClassFactory C Client - IMyMath Interface obtained"), TEXT("From WM Create in Client"), MB_OK);
		}

		//intialize args hardcoded
		iNum1 = 99;
		iNum2 = 99;

		//call SumOfTwoIntegers() of ISum to get the sum
		pIMyMath->lpVtbl->SumOfTwoIntegers(pIMyMath, iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Automation IClassFactory C Client - Result"), MB_OK);

		//again intialize args hardcoded
		iNum1 = 60;
		iNum2 = 60;

		//call SubtractOfTwoIntegers() of ISum to get the new sum
		pIMyMath->lpVtbl->SubtractionOfTwoIntegers(pIMyMath, iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Automation IClassFactory C Client - Result"), MB_OK);

		//as pIMyMath is not not needed onwards, release it
		pIMyMath->lpVtbl->Release(pIMyMath);
		pIMyMath = NULL;

		//exit application
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

//void SafeInterfaceRelease(void)
//{
//	if (pIMyMath)
//	{
//		pIMyMath->lpVtbl->Release(pIMyMath);
//		pIMyMath = NULL;
//	}
//}