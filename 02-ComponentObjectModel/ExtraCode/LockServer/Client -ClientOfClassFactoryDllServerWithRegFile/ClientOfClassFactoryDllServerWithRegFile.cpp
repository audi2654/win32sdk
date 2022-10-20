//ClassFactory LockServer() Extra Assignment Client File

//Commands to give for this file
//cl.exe /c /EHsc ClientOfClassFactoryDllServerWithRegFile.cpp
//link.exe ClientOfClassFactoryDllServerWithRegFile.obj user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS	/MACHINE:x64(optional)

#include <windows.h>
#include "ClassFactoryDllServerWithRegFile.h"

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable declarations
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;
IClassFactory* gpIClassFactory = NULL;
int giFlag = 0;

//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Local Variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");
	static HRESULT hr;

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
	int iNum1, iNum2, iSum, iSubtract;
	TCHAR str[255];

	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoGetClassObject(CLSID_SumSubtract, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory, (void**)&gpIClassFactory);
		//hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&pISum);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISumSubtract Interface cannot be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		gpIClassFactory->LockServer(TRUE);

		/*
		//intialize args hardcoded
		iNum1 = 55;
		iNum2 = 45;

		//call SumOfTwoIntegers() of ISum to get the sum
		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		//call QueryInterface() on ISum to get the ISubtract's pointer
		hr = pISum->QueryInterface(IID_ISubtract, (void**)&pISubtract);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISubtract Interface cannot be obtained"), TEXT("Error"), MB_OK);
			
			//as Isum is not not needed onwards, release it
			pISum->Release();
			pISum = NULL;

			DestroyWindow(hwnd);
		}

		//as ISum is not not needed onwards, release it
		pISum->Release();
		pISum = NULL;

		//again intialize args hardcoded
		iNum1 = 155;
		iNum2 = 145;

		//call SubtractOfTwoIntegers() of ISum to get the new sum
		pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSum);

		//as pISubtract is not not needed onwards, release it
		pISubtract->Release();
		pISubtract = NULL;

		//display the result
		wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		//exit application
		DestroyWindow(hwnd);
		break;
		*/

	case WM_LBUTTONDOWN:
		giFlag++;

		if(giFlag == 1)
		{
			hr = gpIClassFactory->CreateInstance(NULL, IID_ISum, (void**)&pISum);
			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("ISum Interface cannot be obtained"), TEXT("Error"), MB_OK);

				//as gpIClassFactory is now not needed onwards, release it
				gpIClassFactory->Release();
				gpIClassFactory = NULL;

				DestroyWindow(hwnd);
			}

			iNum1 = 9;
			iNum2 = 6;

			pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

			wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
			MessageBox(hwnd, str, TEXT("Sum Result"), MB_OK);

			pISum->Release();
			pISum = NULL;
		}

		if (giFlag == 2)
		{
			hr = gpIClassFactory->CreateInstance(NULL, IID_ISubtract, (void**)&pISubtract);
			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("ISubtract Interface cannot be obtained"), TEXT("Error"), MB_OK);

				//as gpIClassFactory is now not needed onwards, release it
				gpIClassFactory->Release();
				gpIClassFactory = NULL;

				DestroyWindow(hwnd);
			}

			iNum1 = 9;
			iNum2 = 6;

			pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSubtract);

			wsprintf(str, TEXT("Subtract of %d and %d = %d"), iNum1, iNum2, iSubtract);
			MessageBox(hwnd, str, TEXT("Subtract Result"), MB_OK);

			pISubtract->Release();
			pISubtract = NULL;
		}

		if (giFlag == 3)
		{
			DestroyWindow(hwnd);
		}
		break;

	case WM_DESTROY:
		if (gpIClassFactory != NULL)
		{
			gpIClassFactory->LockServer(FALSE);
			gpIClassFactory->Release();
			gpIClassFactory = NULL;
		}
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this

}

void SafeInterfaceRelease(void)
{
	if (pISum)
	{
		pISum->Release();
		pISum = NULL;
	}
	if (pISubtract)
	{
		pISubtract->Release();
		pISubtract = NULL;
	}
}