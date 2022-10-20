//BARE SERVER file
//Date: 15th Sept 2021

//Commands to give for this file
//cl.exe /c /EHsc ContainmentInnerComponentWithRegFile.cpp
//link.exe ContainmentInnerComponentWithRegFile.obj /DLL /DEF:ContainmentInnerComponentWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS	/MACHINE:x64(optional)

#include <Windows.h>
#include "ContainmentInnerComponentWithRegFile.h"

//Class declarations

//CoClass declaration
class CMultiplicationDivision : public IMultiplication, IDivision
{
private:
	long m_cRef;

public:
	//constructor method declaration
	CMultiplicationDivision(void);

	//destr method declaration
	~CMultiplicationDivision(void);

	//IUnknown specific method declr (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IMultiplication (interface/class) specific method declr (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//IDivision (interface/class) specific method declr (inherited)
	HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);
};


//ClassFactory declrn of CoClass
class CMultiplicationDivisionClassFactory : public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor method declaration
	CMultiplicationDivisionClassFactory(void);

	//destr method declaration
	~CMultiplicationDivisionClassFactory(void);

	//IUnknown specific method declr (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//ICLassFactory specific method declrn (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//global var decln
long glNumberOfActiveComponents = 0; //no of active compo
long glNumberOfServerLocks = 0; //no of locks on this dll

//DLL main()
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

//implementation of CMultiplicationDivision's Constr method
CMultiplicationDivision::CMultiplicationDivision(void)
{
	//code
	m_cRef = 1; //hardcoded initialization to anticipate possible failure of QueryInteface()
	
	InterlockedIncrement(&glNumberOfActiveComponents); //increment global cnt
}

//implementation of CMultiplicationDivision's Destr method
CMultiplicationDivision::~CMultiplicationDivision(void)
{
	//code
	InterlockedDecrement(&glNumberOfActiveComponents); //decrement global cnt
}

//implemtation of CMultDiv's IUnknown's Method
HRESULT CMultiplicationDivision::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IMultiplication*>(this);
	else if (riid == IID_IMultiplication)
		*ppv = static_cast<IMultiplication*>(this);
	else if (riid == IID_IDivision)
		*ppv = static_cast <IDivision*> (this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CMultiplicationDivision::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CMultiplicationDivision::Release(void)
{
	//code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}
	return m_cRef;
}

//Implementation of IMulti's Methods
HRESULT CMultiplicationDivision::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiplication)
{
	//code
	*pMultiplication = num1 * num2;
	return(S_OK);
}

//Implementation of IDiv's Method
HRESULT CMultiplicationDivision::DivisionOfTwoIntegers(int num1, int num2, int* pDivision)
{
	//code
	*pDivision = num1 / num2;
	return(S_OK);
}

//Implementation of CMultiplicationDivisionClassFactory's Constr method
CMultiplicationDivisionClassFactory::CMultiplicationDivisionClassFactory(void)
{
	//code
	m_cRef = 1; //hardcoded initialization to anticipate possible failure of QueryInteface()
}

//Implementation of CMultiplicationDivisionClassFactory's Destr method
CMultiplicationDivisionClassFactory::~CMultiplicationDivisionClassFactory(void)
{
	//empty destr
}

//Implementation of CMultiplicationDivisionClassFactory's IClassFactory's IUnknown's method
HRESULT CMultiplicationDivisionClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CMultiplicationDivisionClassFactory::AddRef(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CMultiplicationDivisionClassFactory::Release(void)
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

//Implementation of CMultiplicationDivisionClassFactory's IClassFactory's Methods
HRESULT CMultiplicationDivisionClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declrn
	CMultiplicationDivision *pCMultiplicationDivision = NULL;
	HRESULT hr;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	//create the instance of component i.e of CMultiplicationDivision class
	pCMultiplicationDivision = new CMultiplicationDivision;

	if (pCMultiplicationDivision == NULL)
		return(E_OUTOFMEMORY);

	//get the requested interface
	hr = pCMultiplicationDivision->QueryInterface(riid, ppv);
	pCMultiplicationDivision->Release(); //anticipate possible failure of QueryInterface()
	return(hr);
}

HRESULT CMultiplicationDivisionClassFactory::LockServer(BOOL fLock)
{
	//code
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);
	return(S_OK);
}

//Implementation of exported funcs from this Dll
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//var declarn
	CMultiplicationDivisionClassFactory* pCMultiplicationDivisionClassFactory = NULL;
	HRESULT hr;

	//code
	if (rclsid != CLSID_MultiplicationDivision)
		return(CLASS_E_CLASSNOTAVAILABLE);

	//create classfactory
	pCMultiplicationDivisionClassFactory = new CMultiplicationDivisionClassFactory;

	if (pCMultiplicationDivisionClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hr = pCMultiplicationDivisionClassFactory->QueryInterface(riid, ppv);

	pCMultiplicationDivisionClassFactory->Release(); //anticipate possible failure of QueryInterface()
	return hr;
}

HRESULT __stdcall DllCanUnloadNow(void)
{
	//code
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);
}