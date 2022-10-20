//Automation - SERVER file
//Date: 19th Oct 2021

//Commands to give for this file
//cl.exe /c /EHsc AutomationServerWithRegFile.cpp
//link.exe AutomationServerWithRegFile.obj /DLL /DEF:AutomationServerWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS /MACHINE:x64(optional)

//header files
#include <Windows.h>
//#include <stdio.h>	//for swprintf_s() (optional)
#include "AutomationServerWithRegFile.h"
//#include <cstdio> 
//#include <cwchar> 
//#include <wchar.h>

//class declarations
//CoClass
class CMyMath :public IMyMath
{
private:
	long m_cRef;
	ITypeInfo* m_pITypeInfo;

public:
	//constr method decl.
	CMyMath(void);

	//destr method decl.
	~CMyMath(void);

	//IUnknown specific method decl. (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IDispatch specific method decl. (inherited)
	HRESULT __stdcall GetTypeInfoCount(UINT*);
	HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo**);
	HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*);
	HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*);

	//IMyMath specific method decl. (inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

	//custom method
	HRESULT InitInstance(void);
};

//ClassFactory
class CMyMathClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//constr method decl.
	CMyMathClassFactory(void);

	//destr method decl.
	~CMyMathClassFactory(void);

	//IUnknown specific method decl. (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method decl. (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//Global variables decl.
long glNumberOfActiveComponents = 0; //no of active compo
long glNumberOfServerLocks = 0; //no of locks on this dll

//Type Lib LIBID {F14C8E20-55B1-4F33-B518-B5E348534692}
const GUID LIBID_AutomationServer = { 0xf14c8e20, 0x55b1, 0x4f33, 0xb5, 0x18, 0xb5, 0xe3, 0x48, 0x53, 0x46, 0x92 };

//DllMain
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
	//code
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

//Implementation of CMyMath's Constr method
CMyMath::CMyMath(void)
{
	//code
	m_cRef = 1;	//hardcoded initialization to anticipate possible failure of QI()
	m_pITypeInfo = NULL;
	InterlockedIncrement(&glNumberOfActiveComponents); //increment global cnt
}

//Implementation of CMyMath's Destr method
CMyMath::~CMyMath(void)
{
	//code
	InterlockedDecrement(&glNumberOfActiveComponents); //decrement global cnt
}

//Implementation of CMyMath's IUnknown's method
HRESULT CMyMath::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IMyMath*>(this);
	else if (riid == IID_IDispatch)
		*ppv = static_cast<IMyMath*>(this);
	else if (riid == IID_IMyMath)
		*ppv = static_cast<IMyMath*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG CMyMath::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CMyMath::Release(void)
{
	//code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		m_pITypeInfo->Release();
		m_pITypeInfo = NULL;
		delete(this);
		return 0;
	}
	return(m_cRef);
}

//Implementation of IMyMath's methods
HRESULT CMyMath::SumOfTwoIntegers(int num1, int num2, int* pSum)
{
	//code
	*pSum = num1 + num2;
	return S_OK;
}

HRESULT CMyMath::SubtractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	//code
	*pSubtract = num1 - num2;
	return S_OK;
}

HRESULT CMyMath::InitInstance(void)
{
	//func decl.
	//void ComErrorDescriptionString(HWND, HRESULT);	//optional

	//var decl.
	HRESULT hr;
	ITypeLib* pITypeLib = NULL;

	//code
	if (m_pITypeInfo == NULL)
	{
		hr = LoadRegTypeLib(LIBID_AutomationServer,
			1, 0, //major & minor version numbers
			0x00, //LANG_NEUTRAL
			&pITypeLib);
		if (FAILED(hr))
		{
			//ComErrorDescriptionString(NULL, hr);
			return hr;
		}

		hr = pITypeLib->GetTypeInfoOfGuid(IID_IMyMath, &m_pITypeInfo);
		if (FAILED(hr))
		{
			//ComErrorDescriptionString(NULL, hr);
			pITypeLib->Release();
			return hr;
		}
		pITypeLib->Release();
	}
	return(S_OK);
}

//Implementation of CMyMathClassFactory's Constr Method
CMyMathClassFactory::CMyMathClassFactory(void)
{
	//code
	m_cRef = 1;	//hardcoded initialization to anticipate possible failure of QI()
}

CMyMathClassFactory::~CMyMathClassFactory(void)
{
	//empty destr
}

//Implementation of CMyMathClassFactory's IClassFactory's IUnknown's methods
HRESULT CMyMathClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CMyMathClassFactory::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return m_cRef;
}

ULONG CMyMathClassFactory::Release(void)
{
	//code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return m_cRef;
}

//Implementation of CMyMathClassFactory's IClassFactory's Method
HRESULT CMyMathClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//var decl.
	CMyMath* pCMyMath = NULL;
	HRESULT hr;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	//create the instance of component i.e of CMyMath Class
	pCMyMath = new CMyMath;
	if (pCMyMath == NULL)
		return E_OUTOFMEMORY;

	//call automation related init method
	pCMyMath->InitInstance();

	//get the requested interface
	hr = pCMyMath->QueryInterface(riid, ppv);
	pCMyMath->Release(); //anticipate possible failure of QI()
	return(hr);
}

HRESULT CMyMathClassFactory::LockServer(BOOL fLock)
{
	//code
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);
	return S_OK;
}

//Implementation of IDispatch's method
HRESULT CMyMath::GetTypeInfoCount(UINT* pCountTypeInfo)
{
	//code
	//as we have type library it is 1, else 0
	*pCountTypeInfo = 1;
	return(S_OK);
}

HRESULT CMyMath::GetTypeInfo(UINT iTypeInfo, LCID lcid, ITypeInfo** ppITypeInfo)
{
	//code
	*ppITypeInfo = NULL;
	if (iTypeInfo != 0)
		return(DISP_E_BADINDEX);
	m_pITypeInfo->AddRef();
	*ppITypeInfo = m_pITypeInfo;
	return(S_OK);
}

HRESULT CMyMath::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId)
{
	//code
	return(DispGetIDsOfNames(m_pITypeInfo, rgszNames, cNames, rgDispId));
}

HRESULT CMyMath::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,
	VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
	//var decl.
	HRESULT hr;

	//code
	hr = DispInvoke(this,
		m_pITypeInfo,
		dispIdMember,
		wFlags,
		pDispParams,
		pVarResult,
		pExcepInfo,
		puArgErr);
	return(hr);
}

//Implmentation of Exported Func from this dll
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//var decl.
	CMyMathClassFactory* pCMyMathClassFactory = NULL;
	HRESULT hr;

	//code
	if (rclsid != CLSID_MyMath)
		return(CLASS_E_CLASSNOTAVAILABLE);

	//create class factory
	pCMyMathClassFactory = new CMyMathClassFactory;
	if (pCMyMathClassFactory == NULL)
		return(E_OUTOFMEMORY);
	hr = pCMyMathClassFactory->QueryInterface(riid, ppv);
	pCMyMathClassFactory->Release();	//anticipate possible failure of QI()
	return hr;
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	//code
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return S_OK;
	else
		return(S_FALSE);
}

/*
void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
	//var decl.
	TCHAR* szErrorMessage = NULL;
	TCHAR str[255];

	//code
	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
		hr = HRESULT_CODE(hr);

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&szErrorMessage, 0, NULL) != 0)
	{
		//wsprintf(str, TEXT("%#x : %s"), hr, szErrorMessage);
		swprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);
		LocalFree(szErrorMessage);
	}
	else
		wsprintf(str, TEXT("[Could not find a decsription for error # % #x.]\n"), hr);
		swprintf_s(str, TEXT("[Could not find a decsription for error # % #x.]\n"), hr);


	MessageBox(hwnd, str, TEXT("COM Error"), MB_OK);
}*/
