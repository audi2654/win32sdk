#pragma once

class ISum :public IUnknown
{
public:
	//ISum specific method declarations
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;	//Pure Virtual function declaration
};

class ISubtract :public IUnknown
{
public:
	//ISubstract specific method declarations
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0;	//Pure Virtual function declaration
};

class IMultiply :public IUnknown
{
public:
	//IMultiply specific method declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;	//Pure Virtual function declaration
};

class IDivision :public IUnknown
{
public:
	//IMultiply specific method declarations
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0;	//Pure Virtual function declaration
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

//IID of IMultiply Interface {EFDE267F-ACBD-4F4F-B332-C0ECB407D98E}
const IID IID_IMultiply =
{ 0xefde267f, 0xacbd, 0x4f4f, 0xb3, 0x32, 0xc0, 0xec, 0xb4, 0x7, 0xd9, 0x8e };

//IID of IDivision Interface {970F083E-59CA-4331-8B78-864BE6392172}
const IID IID_IDivision =
{ 0x970f083e, 0x59ca, 0x4331, 0x8b, 0x78, 0x86, 0x4b, 0xe6, 0x39, 0x21, 0x72 };
