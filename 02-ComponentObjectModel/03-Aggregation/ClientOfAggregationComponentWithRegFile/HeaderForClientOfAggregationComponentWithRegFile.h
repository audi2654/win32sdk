#pragma once

class ISum : public IUnknown
{
public:
	//ISum specific method declaration
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;	//pure virtual function
};

class ISubtract : public IUnknown
{
public:
	//ISubtract specific method declaration
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; //pure virtual function
};

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

//CLSID of SumSubtract Component {06C78215-A104-4B2F-A421-9118B53DA0FF}
const CLSID CLSID_SumSubtract = { 0x6c78215, 0xa104, 0x4b2f, 0xa4, 0x21, 0x91, 0x18, 0xb5, 0x3d, 0xa0, 0xff };

//IID of ISum Interface {13F74A78-7BCA-4613-992D-7E9C5049CA90}
const IID IID_ISum = { 0x13f74a78, 0x7bca, 0x4613, 0x99, 0x2d, 0x7e, 0x9c, 0x50, 0x49, 0xca, 0x90 };

//IID of ISubtract Interface {72004D1A-AC88-4B53-9BE1-32487E806EEA}
const IID IID_ISubtract = { 0x72004d1a, 0xac88, 0x4b53, 0x9b, 0xe1, 0x32, 0x48, 0x7e, 0x80, 0x6e, 0xea };

//CLSID of MultiplicationDivision Component {AB4407FD-3F9B-414F-8B76-5233B6E63A14}
const CLSID CLSID_MultiplicationDivision = { 0xab4407fd, 0x3f9b, 0x414f, 0x8b, 0x76, 0x52, 0x33, 0xb6, 0xe6, 0x3a, 0x14 };

//IID of IMultiplication Interface {ED2CA933-23D9-48B5-AC63-B1AE0C148C1D}
const IID IID_IMultiplication = { 0xed2ca933, 0x23d9, 0x48b5, 0xac, 0x63, 0xb1, 0xae, 0xc, 0x14, 0x8c, 0x1d };

//IID of IDivision Interface {1A9DB915-0CF7-45D6-9A8C-C59FA97468C9}
const IID IID_IDivision = { 0x1a9db915, 0xcf7, 0x45d6, 0x9a, 0x8c, 0xc5, 0x9f, 0xa9, 0x74, 0x68, 0xc9 };
