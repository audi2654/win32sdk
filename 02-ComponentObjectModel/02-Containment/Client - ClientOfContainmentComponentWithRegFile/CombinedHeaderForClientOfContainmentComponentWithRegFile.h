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

class IMultiplication : public IUnknown
{
public:
	//IMultiplication specific method declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0; //pure virtual function
};

class IDivision : public IUnknown
{
public:
	//IDivision specific method declarations
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0; //pure virtual function
};

//CLSID of SumSubstract Component {82CB6EB8-92D3-4FCA-82FB-05F16837E927} put this string in .reg file
const CLSID CLSID_SumSubtract =
{ 0x82cb6eb8, 0x92d3, 0x4fca, 0x82, 0xfb, 0x5, 0xf1, 0x68, 0x37, 0xe9, 0x27 };

//IID of ISum Interface {AE3B5739-ABA7-4E33-B6FC-23B1C0670D3A}
const IID IID_ISum =
{ 0xae3b5739, 0xaba7, 0x4e33, 0xb6, 0xfc, 0x23, 0xb1, 0xc0, 0x67, 0xd, 0x3a };

//IID of ISubtract Interface {354A4AAC-029C-4400-912A-6D0C1EBEE03D}
const IID IID_ISubtract =
{ 0x354a4aac, 0x29c, 0x4400, 0x91, 0x2a, 0x6d, 0xc, 0x1e, 0xbe, 0xe0, 0x3d };

//IID of IMultiplication Interface {4607F4EC-135C-4753-95FE-00A969A78E36}
const IID IID_IMultiplication = { 0x4607f4ec, 0x135c, 0x4753, 0x95, 0xfe, 0x0, 0xa9, 0x69, 0xa7, 0x8e, 0x36 };

//IID of IDivision Interface {5921A6D1-1F6F-409A-A023-40643F802F28}
const IID IID_IDivision = { 0x5921a6d1, 0x1f6f, 0x409a, 0xa0, 0x23, 0x40, 0x64, 0x3f, 0x80, 0x2f, 0x28 };