//MIDDLEWARE SERVER file
//Date: 15th Sept 2021

//Commands to give for this file
//cl.exe /c /EHsc ContainmentOuterComponentWithRegFile.cpp
//link.exe ContainmentOuterComponentWithRegFile.obj /DLL /DEF:ContainmentOuterComponentWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS /MACHINE:x64(optional)

#include <Windows.h>
#include "ContainmentOuterComponentWithRegFile.h"		//.h file of Outer Compo
#include "ContainmentInnerComponentWithRegFile.h"		//.h file of Inner Compo

//Class declarations

//CoClass decl
class CSumSubtract :public ISum, ISubtract, IMultiplication, IDivision
{
private:
	long m_cRef;
	IMultiplication* m_pIMultiplication;
	IDivision* m_pIDivision;

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

	//IMultiplication specific method declarations (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//IDivision specific method declarations (inherited)
	HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);

	//Custom method for inner compo creation
	HRESULT __stdcall InitializeInnerComponent(void);
};

//ClassFactory decl of CoClass
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
	//intialize private data members
	m_pIMultiplication = NULL;
	m_pIDivision = NULL;

	m_cRef = 1;	//hardcoded initialization to anticipate possible failure of QueryInterface()

	InterlockedIncrement(&glNumberOfActiveComponents); //incre global counter
}

//Implementation of CSumSubtract's Destr method
CSumSubtract::~CSumSubtract(void)
{
	//code
	InterlockedDecrement(&glNumberOfActiveComponents); //decre global counter

	if (m_pIMultiplication)
	{
		m_pIMultiplication->Release();
		m_pIMultiplication = NULL;
	}
	if (m_pIDivision)
	{
		m_pIDivision->Release();
		m_pIDivision = NULL;
	}
}

//Implementation of CSumSubtract's IUnknown's method
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	TCHAR str[255];

	//code
	if (riid == IID_IUnknown)
	{
		MessageBox(NULL, TEXT("Got IUnknown"), TEXT("Success"), MB_OK);
		*ppv = static_cast<ISum*>(this);
	}
	else if (riid == IID_ISum)
	{
		wsprintf(str, TEXT("Got ISum"));
		MessageBox(NULL, str, TEXT("Success"), MB_OK);
		*ppv = static_cast<ISum*>(this);
	}
	else if (riid == IID_ISubtract)
	{
		MessageBox(NULL, TEXT("Got ISubtract"), TEXT("Success"), MB_OK);
		*ppv = static_cast<ISubtract*>(this);
	}
	else if (riid == IID_IMultiplication)
	{
		MessageBox(NULL, TEXT("Got IMultiplication"), TEXT("Success"), MB_OK);
		*ppv = static_cast<IMultiplication*>(this);
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

//Implementation of IMultiplication's Methods
HRESULT CSumSubtract::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiplication)
{
	//code
	 
	//here you can do some PREPROCESSING
	
	//delegate to inner component
	m_pIMultiplication->MultiplicationOfTwoIntegers(num1, num2, pMultiplication);

	//here you can do some POSTPROCESSING
	return(S_OK);
}

//Implementation of IDivision's Methods
HRESULT CSumSubtract::DivisionOfTwoIntegers(int num1, int num2, int* pDivision)
{
	//code

	//here you can do some PREPROCESSING

	//delegate to inner component
	m_pIDivision->DivisionOfTwoIntegers(num1, num2, pDivision);

	//here you can do some POSTPROCESSING
	return(S_OK);
}

HRESULT CSumSubtract::InitializeInnerComponent(void)
{
	//var decln
	HRESULT hr;

	//code
	hr = CoCreateInstance(CLSID_MultiplicationDivision, NULL, CLSCTX_INPROC_SERVER, IID_IMultiplication, (void**)&m_pIMultiplication);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IMultiplication interface can't be obtained from Inner Compo"), TEXT("ERROR"), MB_OK);
		return(E_FAIL);
	}
	else
	{
		MessageBox(NULL, TEXT("Got INNER COMPONENT IID_IMultiplication"), TEXT("SUCCESS"), MB_OK);
	}

	hr = m_pIMultiplication->QueryInterface(IID_IDivision, (void**)&m_pIDivision);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IDivision interface can't be obtained from Inner Compo"), TEXT("ERROR"), MB_OK);
		return(E_FAIL);
	}
	else
	{
		MessageBox(NULL, TEXT("Got INNER COMPONENT IID_IDivision"), TEXT("SUCCESS"), MB_OK);
	}
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

	//intialize INNER COMPONENT
	hr = pCSumSubtract->InitializeInnerComponent();
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Failed to initialize INNER COMPONENT"), TEXT("ERROR"), MB_OK);

		pCSumSubtract->Release();
		return(hr);
	}
	else
	{
		MessageBox(NULL, TEXT("Succes INNER COMPONENT initialized"), TEXT("In CSumSubtract CreateInstance"), MB_OK);
	}

	//get the requested interface
	hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();	//anticipate possible failure of QueryInterface()
	MessageBox(NULL, TEXT("End of CreateInstance"), TEXT("In CSumSubtract CreateInstance"), MB_OK);
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