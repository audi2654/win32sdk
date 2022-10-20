//Aggregation - BARE SERVER file
//Date: 27th Sept 2021

//Commands to give for this file
//cl.exe /c /EHsc AggregationInnerComponentWithRegFile.cpp
//link.exe AggregationInnerComponentWithRegFile.obj /DLL /DEF:AggregationInnerComponentWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS	/MACHINE:x64(optional)

#include<Windows.h>
#include"AggregationInnerComponentWithRegFile.h"

//Interface declaration (for internal use only i.e not to be included in .h file)

interface INoAggregationIUnknown //new change from previous containment & classfactory //Interfaces in C, C++ are internally structs
{
	virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**) = 0;
	virtual ULONG __stdcall AddRef_NoAggregation(void) = 0;
	virtual ULONG __stdcall Release_NoAggregation(void) = 0;
};

//class declarations
class CMultiplicationDivision : public INoAggregationIUnknown, IMultiplication, IDivision
{
private:
	long m_cRef;
	IUnknown* m_pIUnknownOuter;

public:
	//constructor method declaration
	CMultiplicationDivision(IUnknown*);

	//destructor method declaration
	~CMultiplicationDivision(void);

	//Aggregation supported IUnknown specific method declartions (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Aggregation non-supported IUnknown specific method declartions (inherited)
	HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**);
	ULONG __stdcall AddRef_NoAggregation(void);
	ULONG __stdcall Release_NoAggregation(void);

	//IMultiplication specific method declrations (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//IDivision specific method declrations (inherited)
	HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);
};

class CMultiplicationDivisionClassFactory : public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor declaration
	CMultiplicationDivisionClassFactory(void);

	//constructor declaration
	~CMultiplicationDivisionClassFactory(void);

	//IUnknown specific method declarations(inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declarations(inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//global var decl.
long glNumberOfActiveComponents = 0;  //no of active compo
long glNumberOfServerLocks = 0;		//no of server locks on this dll

//Dll main
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

//Implementation of CMultiplicationDivision's Constr
CMultiplicationDivision::CMultiplicationDivision(IUnknown* pIUnknownOuter)
{
	//code
	m_cRef = 1; //hardcoded initialisation to anticipate possible failure of QI()

	InterlockedIncrement(&glNumberOfActiveComponents); //incre global cnt

	if (pIUnknownOuter != NULL)
	{
		m_pIUnknownOuter = pIUnknownOuter;
	}
	else
	{
		m_pIUnknownOuter = reinterpret_cast<IUnknown*>(static_cast<INoAggregationIUnknown*>(this));	//Method Coloring here
	}
}

//Implementation of CMultiplicationDivision's Destr
CMultiplicationDivision::~CMultiplicationDivision(void)
{
	//code
	InterlockedDecrement(&glNumberOfActiveComponents);	//decrement global cnt
}

//Implementation of CMultiplicationDivision's Aggregation SUPPORTING IUnknown's methods
HRESULT CMultiplicationDivision::QueryInterface(REFIID riid, void** ppv)
{
	//code
	return(m_pIUnknownOuter->QueryInterface(riid, ppv));	//magic happens here for all 7 use cases of aggre
}

ULONG CMultiplicationDivision::AddRef(void)
{
	//code
	return(m_pIUnknownOuter->AddRef());
}

ULONG CMultiplicationDivision::Release(void)
{
	//code
	return(m_pIUnknownOuter->Release());
}

//Implementation of CMultiplicationDivision's Aggregation NON-SUPPORTING IUnknown's methods
HRESULT CMultiplicationDivision::QueryInterface_NoAggregation(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<INoAggregationIUnknown*>(this);	//Method Coloring here
	else if (riid == IID_IMultiplication)
		*ppv = static_cast<IMultiplication*>(this);
	else if (riid == IID_IDivision)
		*ppv = static_cast<IDivision*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CMultiplicationDivision::AddRef_NoAggregation(void)
{
	//code
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CMultiplicationDivision::Release_NoAggregation(void)
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

//Implementation of IMultiplication's method
HRESULT CMultiplicationDivision::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiplication)
{
	//code
	*pMultiplication = num1 * num2;
	return(S_OK);
}

//Implementation of IDivision's method
HRESULT CMultiplicationDivision::DivisionOfTwoIntegers(int num1, int num2, int* pDivision)
{
	//code
	*pDivision = num1 / num2;
	return(S_OK);
}

//Implementation of CMultiplicationDivisionClassFactory's Constr
CMultiplicationDivisionClassFactory::CMultiplicationDivisionClassFactory(void)
{
	//code
	m_cRef = 1; //hardcoded initialisation to anticipate possible failure of QI()
}

//Implementation of CMultiplicationDivisionClassFactory's Destr
CMultiplicationDivisionClassFactory::~CMultiplicationDivisionClassFactory(void)
{
	//empty destr
}

//Implementation of CMultiplicationDivisionClassFactory's IClassFactory's IUnknown's methods
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
		return(0);
	}
	return(m_cRef);
}

//Implementation of CMultiplicationDivisionClassFactory's IClassFactory's methods
HRESULT CMultiplicationDivisionClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//var decl.
	CMultiplicationDivision* pCMultiplicationDivision = NULL;
	HRESULT hr;

	//code
	if ((pUnkOuter != NULL) && (riid != IID_IUnknown))
		return(CLASS_E_NOAGGREGATION);

	//create instance of compo i.e CMultiplicationDivision class
	pCMultiplicationDivision = new CMultiplicationDivision(pUnkOuter);
	if (pCMultiplicationDivision == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	//get the requested Interface
	hr = pCMultiplicationDivision->QueryInterface_NoAggregation(riid, ppv);
	pCMultiplicationDivision->Release_NoAggregation();	//anticipate possible failure of QI()

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

//Implementation of Exported Function from this DLL
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//var decl.
	CMultiplicationDivisionClassFactory* pCMultiplicationDivisionClassFactory = NULL;
	HRESULT hr;

	//code
	if (rclsid != CLSID_MultiplicationDivision)
		return(CLASS_E_CLASSNOTAVAILABLE);

	//create classfactory
	pCMultiplicationDivisionClassFactory = new CMultiplicationDivisionClassFactory;
	if (pCMultiplicationDivisionClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hr = pCMultiplicationDivisionClassFactory->QueryInterface(riid, ppv);
	pCMultiplicationDivisionClassFactory->Release(); //anticipate possible failure of QI()

	return(hr);
}

HRESULT __stdcall DllCanUnloadNow(void)
{
	//code
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);
}
