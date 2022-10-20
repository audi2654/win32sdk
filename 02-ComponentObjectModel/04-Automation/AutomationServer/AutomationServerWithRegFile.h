class IMyMath : public IDispatch
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; //pure virtual func
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; //pure virtual func
};

//CLSID of CoClass MyMath Compo {44EA501F-515E-4B8A-8786-238D4110A31E}
const CLSID CLSID_MyMath = { 0x44ea501f, 0x515e, 0x4b8a, 0x87, 0x86, 0x23, 0x8d, 0x41, 0x10, 0xa3, 0x1e };

//IID of IMyMath Interface {EC449CA0-BE1A-4571-89B7-F2E6153CE243}
const IID IID_IMyMath = { 0xec449ca0, 0xbe1a, 0x4571, 0x89, 0xb7, 0xf2, 0xe6, 0x15, 0x3c, 0xe2, 0x43 };
