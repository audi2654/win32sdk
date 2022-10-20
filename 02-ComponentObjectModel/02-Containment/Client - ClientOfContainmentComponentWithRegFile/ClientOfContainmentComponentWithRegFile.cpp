//Containment Flow BARE CLIENT CPP file
//Date:15th Sept 2021

//Commands to give for this file
//cl.exe /c /EHsc ClientOfContainmentComponentWithRegFile.cpp
//link.exe ClientOfContainmentComponentWithRegFile.obj user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS	/MACHINE:x64(optional)


#include <windows.h>
#include "CombinedHeaderForClientOfContainmentComponentWithRegFile.h"

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable declarations
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;
IMultiplication* pIMultiplication = NULL;
IDivision* pIDivision = NULL;

//Entry Point Function WinMain()
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
		MessageBox(NULL, TEXT("COM Library can't be Initialized \n Program will now Exit"), TEXT("Program Error"), MB_OK);
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
		TEXT("AMP: MyContainmentFlowWindow"),
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
	int iNum1, iNum2, iSum, iSubtraction, iMultiplication, iDivision;
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
		else
		{
			MessageBox(NULL, TEXT("ISum Interface obtained"), TEXT("Msg from Client CPP"), MB_OK);
		}

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
			
			//as Isum is now not needed onwards, release it
			pISum->Release();
			pISum = NULL;

			DestroyWindow(hwnd);
		}

		//as ISum is now not needed onwards, release it
		pISum->Release();
		pISum = NULL;

		//again intialize args hardcoded
		iNum1 = 155;
		iNum2 = 145;

		//call SubtractOfTwoIntegers() of ISum to get the new sum
		pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSum);

		//display the result
		wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		//call QueryInterface() on ISubtract to get the IMultiplication's pointer
		hr = pISubtract->QueryInterface(IID_IMultiplication, (void**)&pIMultiplication);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("IMultiplication Interface cannot be obtained"), TEXT("Error"), MB_OK);

			//as ISubtract is now not needed onwards, release it
			pISubtract->Release();
			pISubtract = NULL;

			DestroyWindow(hwnd);
		}

		//as ISubtract is now not needed onwards, release it
		pISubtract->Release();
		pISubtract = NULL;

		//again intialize args hardcoded
		iNum1 = 12;
		iNum2 = 5;

		//call MultiplicationOfTwoIntegers() of IMultiplication to get the new sum
		pIMultiplication->MultiplicationOfTwoIntegers(iNum1, iNum2, &iMultiplication);

		//display the result
		wsprintf(str, TEXT("Multiplication of %d and %d = %d"), iNum1, iNum2, iMultiplication);
		MessageBox(hwnd, str, TEXT("Multiplication Result"), MB_OK);

		//call QueryInterface() on IMultiplication to get the IDivision's pointer
		hr = pIMultiplication->QueryInterface(IID_IDivision, (void**)&pIDivision);
		if (FAILED(hr))
		{
			MessageBox(NULL, TEXT("IMultiplication Interface cannot be obtained"), TEXT("Error"), MB_OK);

			//as IMultiplication is now not needed onwards, release it
			pIMultiplication->Release();
			pIMultiplication = NULL;

			DestroyWindow(hwnd);
		}

		//as IMultiplication is now not needed onwards, release it
		pIMultiplication->Release();
		pIMultiplication = NULL;

		//again intialize args hardcoded
		iNum1 = 60;
		iNum2 = 5;

		//call DivisionOfTwoIntegers() of IDivision to get the new sum
		pIDivision->DivisionOfTwoIntegers(iNum1, iNum2, &iDivision);

		//display the result
		wsprintf(str, TEXT("Division of %d and %d = %d"), iNum1, iNum2, iDivision);
		MessageBox(hwnd, str, TEXT("Division Result"), MB_OK);

		//finally release IDivision
		pIDivision->Release();
		pIDivision = NULL;	//make released Interface NULL

		//exit application
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		SafeInterfaceRelease();
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
	if (pIMultiplication)
	{
		pIMultiplication->Release();
		pIMultiplication = NULL;
	}
	if (pIDivision)
	{
		pIDivision->Release();
		pIDivision = NULL;
	}
}