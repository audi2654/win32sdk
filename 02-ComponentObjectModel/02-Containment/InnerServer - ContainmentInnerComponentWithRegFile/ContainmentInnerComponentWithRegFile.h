#pragma once

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

//CLSID of MultiplicationDivision Component {D05DD422-6601-4C07-A794-3855E1B51158}
const CLSID CLSID_MultiplicationDivision = { 0xd05dd422, 0x6601, 0x4c07, 0xa7, 0x94, 0x38, 0x55, 0xe1, 0xb5, 0x11, 0x58 };

//IID of IMultiplication Interface {4607F4EC-135C-4753-95FE-00A969A78E36}
const IID IID_IMultiplication = { 0x4607f4ec, 0x135c, 0x4753, 0x95, 0xfe, 0x0, 0xa9, 0x69, 0xa7, 0x8e, 0x36 };

//IID of IDivision Interface {5921A6D1-1F6F-409A-A023-40643F802F28}
const IID IID_IDivision = { 0x5921a6d1, 0x1f6f, 0x409a, 0xa0, 0x23, 0x40, 0x64, 0x3f, 0x80, 0x2f, 0x28 };