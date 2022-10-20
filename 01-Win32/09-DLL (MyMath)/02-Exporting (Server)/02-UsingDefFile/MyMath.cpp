//Date: 10th Aug 2021
//Server DLL

#include <Windows.h>

//Commands: 
//cl.exe /c /EHsc MyMath.cpp
//link.exe MyMath.obj /DLL /DEF:MyMath.def user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS


//DLL main entry point function declaration
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
//here hDll is given by OS (dll actual run nai hot but hatha madhun kathi run zalya sarkhi vatte)
//dwReason is reason like which process or thread & for what it is calling this dll
//lpReserved is reserved by OS, should never be used
{
	//Code
	//Usually all cases comes & run even if it loads in only 1 program process because every process is itself an one thread known as MainThread
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

	default:
		break;
	}

	return TRUE;	
	//DLL is considered to return & should always & always return TRUE when you write any code in above cases, usually you wont hardcode return TRUE value
	//you can do API Hooking & DLL Injection if you can write some code in above cases 

}

//dllexport is Windows only specifier
//using __declspec(dllexport) tells Linker to create a new topi above DLL file called as Export Function Table (EFT)
//just like (ImportFT) above EXE file in client
extern "C" int MakeCube(int num)	//this function is now pari purn with extern "C" declaration
{
	//Code
	int cube = num * num * num;

	return cube;

}
