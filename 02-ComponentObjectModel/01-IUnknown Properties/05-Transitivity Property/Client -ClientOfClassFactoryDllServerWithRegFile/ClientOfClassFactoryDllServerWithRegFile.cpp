//ClassFactory Flow Client CPP file
//Date:8th Sept 2021

//5th Property Transitivity of IUnknown

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
IMultiply* pIMultiply = NULL;
IDivision* pIDivision = NULL;

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
	//HRESULT	hr2;
	int iNum1, iNum2, iSum;
	TCHAR str[255];

	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&pISum);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("ISum Interface cannot be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		//intialize args hardcoded
		iNum1 = 55;
		iNum2 = 45;

		//call SumOfTwoIntegers() of ISum to get the sum
		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Add Result"), MB_OK);

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

		//display the result
		wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Subtract Result"), MB_OK);
		
		//call QueryInterface() on ISubtract to get the IMultiply's pointer
		hr = pISubtract->QueryInterface(IID_IMultiply, (void**)&pIMultiply);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("IMultiply Interface cannot be obtained"), TEXT("Error"), MB_OK);

			//as ISubtract is not not needed onwards, release it
			pISubtract->Release();
			pISubtract = NULL;

			DestroyWindow(hwnd);
		}

		//as pISubtract is not not needed onwards, release it
		pISubtract->Release();
		pISubtract = NULL;

		//again intialize args hardcoded
		iNum1 = 12;
		iNum2 = 5;

		//call MultiplicationOfTwoIntegers() of ISum to get the new sum
		pIMultiply->MultiplicationOfTwoIntegers(iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Multiplication of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Multiply Result"), MB_OK);

		//call QueryInterface() on IMultiply to get the IDivision's pointer
		hr = pIMultiply->QueryInterface(IID_IDivision, (void**)&pIDivision);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("IDivision Interface cannot be obtained"), TEXT("Error"), MB_OK);

			//as IMultiply is not not needed onwards, release it
			pIMultiply->Release();
			pIMultiply = NULL;

			DestroyWindow(hwnd);
		}

		//as iMultiply is not not needed onwards, release it
		pIMultiply->Release();
		pIMultiply = NULL;

		//again intialize args hardcoded
		iNum1 = 60;
		iNum2 = 5;

		//call DivisionOfTwoIntegers() of ISum to get the new sum
		pIDivision->DivisionOfTwoIntegers(iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Division of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Division Result"), MB_OK);

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
	if (pIMultiply)
	{
		pIMultiply->Release();
		pIMultiply = NULL;
	}
	if (pIDivision)
	{
		pIDivision->Release();
		pIDivision = NULL;
	}
}