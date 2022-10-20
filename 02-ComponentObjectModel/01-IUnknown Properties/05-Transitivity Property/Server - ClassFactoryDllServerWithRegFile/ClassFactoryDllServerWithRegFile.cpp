#include <Windows.h>
#include "ClassFactoryDllServerWithRegFile.h"

//Specifically for 5th Property Transitivity of IUnknown

//Commands to give for this file
//cl.exe /c /EHsc ClassFactoryDllServerWithRegFile.cpp
//link.exe ClassFactoryDllServerWithRegFile.obj /DLL /DEF:ClassFactoryDllServerWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS /MACHINE:x64(optional)

//Class declarations
class CSumSubtract :public ISum, public ISubtract, public IMultiply, public IDivision
{
private:
	long m_cRef;

public:
	//Constr method declaration
	CSumSubtract(void);

	//Destr method declaration
	~CSumSubtract(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//ISum specific method declarations (inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);
	
	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

	//IMultiply specific method declarations (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//IDivision specific method declarations (inherited)
	HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);
};

class CSumSubtractClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//Constr method declaration
	CSumSubtractClassFactory(void);

	//Destr method declaration
	~CSumSubtractClassFactory(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declarations (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//Global vars decalarations
long glNumberOfActiveComponents = 0;	//no of Active Components
long glNumberOfServerLocks = 0;			//no of locks on thid Dll

//Dll Main
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
	return(TRUE);
}

//Implementation of CSumSubtract's Constr method
CSumSubtract::CSumSubtract(void)
{
	//code
	m_cRef = 1;	//hardcoded initialization to anticipate possible failure of QueryInterface()

	InterlockedIncrement(&glNumberOfActiveComponents); //incre global counter
}

//Implementation of CSumSubtract's Destr method
CSumSubtract::~CSumSubtract(void)
{
	//code
	InterlockedDecrement(&glNumberOfActiveComponents); //decre global counter
}

//Implementation of CSumSubtract's IUnknown's method
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
	{
		MessageBox(NULL, TEXT("Got IUnknown"), TEXT("Success"), MB_OK);
		*ppv = static_cast<ISum*>(this);
	}
	else if (riid == IID_ISum)
	{
		MessageBox(NULL, TEXT("Got ISum"), TEXT("Success"), MB_OK);
		*ppv = static_cast<ISum*>(this);
	}
	else if (riid == IID_ISubtract)
	{
		MessageBox(NULL, TEXT("Got ISubtract"), TEXT("Success"), MB_OK);
		*ppv = static_cast<ISubtract*>(this);
	}
	else if (riid == IID_IMultiply)
	{
		MessageBox(NULL, TEXT("Got IMultiply"), TEXT("Success"), MB_OK);
		*ppv = static_cast<IMultiply*>(this);
	}
	else if (riid == IID_IDivision)
	{
		MessageBox(NULL, TEXT("Got IDivision"), TEXT("Success"), MB_OK);
		*ppv = static_cast<IDivision*>(this);
	}	
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CSumSubtract::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CSumSubtract::Release(void)
{
	//code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);
}

//Implementation of ISum's Methods
HRESULT CSumSubtract::SumOfTwoIntegers(int num1, int num2, int* pSum)
{
	//code
	*pSum = num1 + num2;
	return(S_OK);
}

//Implementation of ISubtract's Methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	//code
	*pSubtract = num1 - num2;
	return(S_OK);
}

//Implementation of IMultiply's Methods
HRESULT CSumSubtract::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiply)
{
	//code
	*pMultiply = num1 * num2;
	return(S_OK);
}

//Implementation of IDivision's Methods
HRESULT CSumSubtract::DivisionOfTwoIntegers(int num1, int num2, int* pDivision)
{
	//code
	*pDivision = num1 / num2;
	return(S_OK);
}

//Implementation CSumSubtractClassFactory's Constr Method
CSumSubtractClassFactory::CSumSubtractClassFactory(void) 
{
	//code
	m_cRef = 1;	//hardcoded initialization to anticipate possible failure of QueryInterface()
}

//Implementation CSumSubtractClassFactory's Destr Method
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//Empty Destr
}

//Implementation of CSumSubtractClassFactory's IClassFactory's IUnknown's Methods
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if(riid==IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CSumSubtractClassFactory::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CSumSubtractClassFactory::Release(void)
{
	//code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}
	return(m_cRef);
}

//Implementation pf CSumSubtractClassFactory's IClassFactory's Methods
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//var declarations
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hr;

	//code
	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}

	//create instance of component i.e of CSumSubtract class
	pCSumSubtract = new CSumSubtract;
	if (pCSumSubtract == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	//get the rquested interface
	hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();	//anticipate possible failure of QueryInterface()
	return(hr);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
{
	//code
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);
	return(S_OK);
}

//Implementation of Exported Funcs from this DLL
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//var declare
	CSumSubtractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hr;

	//code
	if (rclsid != CLSID_SumSubtract)
		return(CLASS_E_CLASSNOTAVAILABLE);

	//create class factory
	pCSumSubtractClassFactory = new CSumSubtractClassFactory;
	if (pCSumSubtractClassFactory == NULL)
		return(E_OUTOFMEMORY);
	hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release();	//anticipate failure of QuerytInterface()

	return hr;
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	//code
	if (glNumberOfActiveComponents == 0 && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);
}