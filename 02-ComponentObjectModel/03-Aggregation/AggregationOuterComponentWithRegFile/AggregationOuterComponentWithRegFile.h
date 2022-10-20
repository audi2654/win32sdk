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

//CLSID of SumSubtract Component {06C78215-A104-4B2F-A421-9118B53DA0FF}
const CLSID CLSID_SumSubtract = { 0x6c78215, 0xa104, 0x4b2f, 0xa4, 0x21, 0x91, 0x18, 0xb5, 0x3d, 0xa0, 0xff };

//IID of ISum Interface {13F74A78-7BCA-4613-992D-7E9C5049CA90}
const IID IID_ISum = { 0x13f74a78, 0x7bca, 0x4613, 0x99, 0x2d, 0x7e, 0x9c, 0x50, 0x49, 0xca, 0x90 };

//IID of ISubtract Interface {72004D1A-AC88-4B53-9BE1-32487E806EEA}
const IID IID_ISubtract = { 0x72004d1a, 0xac88, 0x4b53, 0x9b, 0xe1, 0x32, 0x48, 0x7e, 0x80, 0x6e, 0xea };
