#pragma once

#undef INTERFACE
#define INTERFACE IMyMath

DECLARE_INTERFACE_(IMyMath, IDispatch)
{
	//IUnknown specific method decl. (inherited) cause IDispatch comes from inside IUnknown
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	//IDispatch specific method decl. (inherited)
	//HRESULT __stdcall GetTypeInfoCount(UINT*);
	STDMETHOD(GetTypeInfoCount)(UINT*) PURE;

	//HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo**);
	STDMETHOD(GetTypeInfo)(UINT, LCID, ITypeInfo**) PURE;

	//HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*);
	STDMETHOD(GetIDsOfNames)(THIS_ REFIID, LPOLESTR*, UINT, LCID, DISPID*) PURE;


	//HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*);
	STDMETHOD(Invoke)(DISPID, THIS_ REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*) PURE;

	STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;
	STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;
};

//CLSID of MyMath Compo {44EA501F-515E-4B8A-8786-238D4110A31E}
const CLSID CLSID_MyMath = { 0x44ea501f, 0x515e, 0x4b8a, 0x87, 0x86, 0x23, 0x8d, 0x41, 0x10, 0xa3, 0x1e };

//IID of IMyMath Interface {EC449CA0-BE1A-4571-89B7-F2E6153CE243}
const IID IID_IMyMath = { 0xec449ca0, 0xbe1a, 0x4571, 0x89, 0xb7, 0xf2, 0xe6, 0x15, 0x3c, 0xe2, 0x43 };
