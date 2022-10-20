//Automation Flow - IDispatch C Client
//Date:

//Commands to give for this file
//cl.exe /c /EHsc IDispatchAutomationCClient.c
//link.exe IDispatchAutomationCClient.obj user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS	/MACHINE:x64(optional)

#include <windows.h>
#include "AutomationServerWithRegFile_C_IDispatch.h"

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable declarations
IDispatch* pIDispatch = NULL;

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
	void SafeInterfaceRelease(void);

	//Variable declarations
	HRESULT hr;
	int iNum1, iNum2, iSum;
	TCHAR str[255];

	DISPID dispid;
	OLECHAR* szFunctionOne = L"SumOfTwoIntegers";
	OLECHAR* szFunctionTwo = L"SubtractionOfTwoIntegers";
	VARIANT vArg[2], vRet;
	DISPPARAMS params;
	//you can include ComErrorExceptionString func from server & declare prototype here to use

	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(&CLSID_MyMath, NULL, CLSCTX_INPROC_SERVER, &IID_IDispatch, (void**)&pIDispatch);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("Automation IDispatch C Client - IDispatch Interface cannot be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		else
		{
			MessageBox(NULL, TEXT("Automation IDispatch C Client - IDispatch Interface obtained"), TEXT("From WM Create in Client"), MB_OK);
		}



		//intialize args hardcoded
		iNum1 = 15;
		iNum2 = 10;

		VariantInit(vArg);
		vArg[0].vt = VT_INT;
		vArg[0].intVal = iNum2;
		vArg[1].vt = VT_INT;
		vArg[1].intVal = iNum1;

		params.rgvarg = vArg;
		params.cArgs = 2;
		params.rgdispidNamedArgs = NULL;
		params.cNamedArgs = 0;

		VariantInit(&vRet);

		MessageBox(NULL, TEXT("Below VariantInit & Above pIDispatch->GetIDsOfNames"), TEXT("From WM Create in Client"), MB_OK);

		//FOR SUM
		hr = pIDispatch->lpVtbl->GetIDsOfNames(pIDispatch, &IID_NULL, &szFunctionOne, 1, GetUserDefaultLCID(), &dispid);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("pIDispatch->GetIDsOfNames failed"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		else
		{
			MessageBox(NULL, TEXT("pIDispatch->GetIDsOfNames success"), TEXT("From WM Create in Client"), MB_OK);
		}


		hr = pIDispatch->lpVtbl->Invoke(pIDispatch, 
			dispid,
			&IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&params,
			&vRet,
			NULL,
			NULL);

		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("pIDispatch->Invoke failed"), TEXT("Error From WM Create in Client"), MB_OK);
			DestroyWindow(hwnd);
		}

		//display the result
		wsprintf(str, TEXT("Sum of %d & %d = %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Sum Result"), MB_OK);


		//FOR SUBTRACTION
		hr = pIDispatch->lpVtbl->GetIDsOfNames(pIDispatch, &IID_NULL, &szFunctionTwo, 1, GetUserDefaultLCID(), &dispid);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("pIDispatch->GetIDsOfNames for Subtract failed"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		hr = pIDispatch->lpVtbl->Invoke(pIDispatch,
			dispid,
			&IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&params,
			&vRet,
			NULL,
			NULL);

		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("pIDispatch->Invoke failed"), TEXT("Error From WM Create in Client"), MB_OK);
			DestroyWindow(hwnd);
		}

		//display the result
		wsprintf(str, TEXT("Subtract of %d & %d = %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Subtract Result"), MB_OK);

		pIDispatch->lpVtbl->Release(pIDispatch);
		pIDispatch = NULL;

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

void SafeInterfaceRelease(void)
{
	if (pIDispatch)
	{
		pIDispatch->lpVtbl->Release(pIDispatch);
		pIDispatch = NULL;
	}
}