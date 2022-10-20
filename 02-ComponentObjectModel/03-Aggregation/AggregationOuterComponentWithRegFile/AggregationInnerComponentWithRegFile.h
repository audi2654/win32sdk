#pragma once

class IMultiplication : public IUnknown
{
public:
	//IMultiplication specific method declaration
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;	//pure virtual function
};

class IDivision : public IUnknown
{
public:
	//IDivision specific method declaration
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0; //pure virtual function
};

//CLSID of MultiplicationDivision Component {AB4407FD-3F9B-414F-8B76-5233B6E63A14}
const CLSID CLSID_MultiplicationDivision = { 0xab4407fd, 0x3f9b, 0x414f, 0x8b, 0x76, 0x52, 0x33, 0xb6, 0xe6, 0x3a, 0x14 };

//IID of IMultiplication Interface {ED2CA933-23D9-48B5-AC63-B1AE0C148C1D}
const IID IID_IMultiplication = { 0xed2ca933, 0x23d9, 0x48b5, 0xac, 0x63, 0xb1, 0xae, 0xc, 0x14, 0x8c, 0x1d };

//IID of IDivision Interface {1A9DB915-0CF7-45D6-9A8C-C59FA97468C9}
const IID IID_IDivision = { 0x1a9db915, 0xcf7, 0x45d6, 0x9a, 0x8c, 0xc5, 0x9f, 0xa9, 0x74, 0x68, 0xc9 };
