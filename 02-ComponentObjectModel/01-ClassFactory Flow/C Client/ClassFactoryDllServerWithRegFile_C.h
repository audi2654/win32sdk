#pragma once

#undef INTERFACE
#define INTERFACE ISum
DECLARE_INTERFACE_(ISum, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;

};

#undef INTERFACE
#define INTERFACE ISubtract
DECLARE_INTERFACE_(ISubtract, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;

};

//CLSID of SumSubstract Component {9DEF60F9-50F2-4685-9E4E-7570E28D9F69} put this string in .reg file
const CLSID CLSID_SumSubtract =
{ 0x9def60f9, 0x50f2, 0x4685, 0x9e, 0x4e, 0x75, 0x70, 0xe2, 0x8d, 0x9f, 0x69 };

//IID of ISum Interface {AEBF6DE7-EE4E-42DE-A3BE-9AEE00B777FA}
const IID IID_ISum =
{ 0xaebf6de7, 0xee4e, 0x42de, 0xa3, 0xbe, 0x9a, 0xee, 0x0, 0xb7, 0x77, 0xfa };

//IID of ISubtract Interface {AA56D3AF-B697-4188-9A31-6DEC90AB1D65}
const IID IID_ISubtract =
{ 0xaa56d3af, 0xb697, 0x4188, 0x9a, 0x31, 0x6d, 0xec, 0x90, 0xab, 0x1d, 0x65 };
