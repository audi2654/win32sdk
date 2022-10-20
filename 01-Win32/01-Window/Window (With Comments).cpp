//Including header files
#include <windows.h> 

//Global Function declarations or writing the prototype of user defined callback function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
//Above func is a callback func & hence always called by OS & as many times as required until the life of program

//Global Variable declarations


//Entry Point Function (which is always called by OS only once to start this program)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) //its a variadic func like int main() in c & c++
{
	//Above this you just define a usual skeleton like you do for a normal function
	//USUAL STEPS TO CREATE WINDOW
	//Step-1: Define declare initialize window class data structure. Any window program needs to initialize WNDCLASSEX WNDCLASS Struct
	//Step-2: Register this initialized structure with OS by passing its address
	//Step-3: Create the window in memory
	//Step-4: Show the windows on screen
	//Step-5: Paint window background
	//Step-6: Start the message loop or heart of the application

	//Local Variable declarations
	WNDCLASSEX wndclass;	//Struct of 12 members like in C or C++ before it had only 10 members, WNDCLASSEX is a category not actual class //STEP-1
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");

	//Code
	wndclass.cbSize = sizeof(WNDCLASSEX);							//1	cbSize = count of bytes in size Newly Added in WNDCLASSExtended Class Structure
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						//2 CS-ClassStyle class category style horizontal or vertical redraw
	wndclass.lpfnWndProc = WndProc;									//3 long pointer to callback function WndProc
	wndclass.cbClsExtra = 0;										//4 count of bytes for Extra info on Class
	wndclass.cbWndExtra = 0;										//5 count of bytes for Extra info on Window
	wndclass.hInstance = hInstance;									//6	handle id of your Window for Loader (OS or CLR or JVM)
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//7 taskbar & windows explorer big icon for your window; ID of an Icon which of type Application IDI_APP its a Macro (using 1st API from 3.5 lakh APIs)
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					//8 2nd API ID of a Cursor which of type Application
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//9 handle for brush of Background
	wndclass.lpszClassName = szAppName;								//10 long pointer to zero terminated string for UNICODE string name of your application, unique name of your application class	//used to differentiate between 2 types of windowclasses Predefined ClsWnd like DialogBox Cls, Edit, Scroll, RichEdit & Custom ClsWnd
	wndclass.lpszMenuName = NULL;									//11 menu like right click or options menu
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);				//12 window top left near system menu small icon for window ; Newly Added in WNDCLASSExtended Class Structure

	RegisterClassEx(&wndclass);		//STEP-2		Returns an ATOM type of unique string (ATOM is decorated unique classname with added some random string in front of classname) 

	//Create the window in memory	//STEP-3
	hwnd = CreateWindow(
		szAppName,
		TEXT("AMP: MyFirstWindow"),
		WS_OVERLAPPEDWINDOW,		//WS-WindowStyle internally this Macro is made from 6 styles class of windows
		CW_USEDEFAULT,				//CW-CreateWindow X coordinate
		CW_USEDEFAULT,				//Y coordinate
		CW_USEDEFAULT,				//W Width of window
		CW_USEDEFAULT,				//H Height of window
		NULL,						//OR HWND_DESKTOP also works, its a Handle for Parent window (if any)
		NULL,						//Handle for Menu Name
		hInstance,					//Handle for Instance
		NULL);						//Pointer to CREATESTRUCT, its type is LP Void also called as Creation Parameter

	//Now show the window created in memory on screen
	ShowWindow(hwnd, iCmdShow);		//STEP-4	SW_MAXIMIZE, SW_MINIMIZE, SW_HIDE, SW_SHOWNORMAL also works instead of iCmdShow & it is internally SW_SHOWNORMAL as default choice of OS
	UpdateWindow(hwnd);				//STEP-5

	//STEP-6	Heart of Application : Message Loop/Pump in Windows, Event Loop in Linux, Run Loop in MacOS, Game Loop in Real Time Rendering Gaming, Looper / Event Loop in Android 
	while (GetMessage(&msg, NULL, 0, 0))  //GetMessage here is Straw in the Message Pool - Heart Right Side
		//2nd NULL para is here for Handle if HWND is passed here the app with child window will not work properly & file will be opened in Task manager details even when closed
		//this is done so that all child window can use the same Message Loop from main parent window
		//3rd & 4th para are Message Filter paras with Min, Max range, usually kept as 0, 0 which says to put no filter & receive all msgs including child windows
		//For all msgs it returns true, WM_QUIT is the only window msg that returns false for GetMessage(), makes the above while loop false & breaks it
		//2nd para is kept NULL so that child windows mesg are also received or if hwnd is given only main window msgs are received
	{	
		TranslateMessage(&msg);		//oxygenated blood/ sanskar kelela blood - Heart Left Side
		DispatchMessage(&msg);		//sends to WndProc, takes addr from wndclass.lpfnWndProc
	}

	return((int)msg.wParam); //OR ... return (int)msg.wParam; ... also works  // similar as return(0);
	//here 0 is returned which you set in PostQuitMessage(0) in WndProc which was sent in Msg Loop by WM_QUIT using this Post msg
	//& here Program is succesfully a)Removed from system & b)Destroyed
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);		//Post message WM_QUIT to this window with wParam as 0 & this msg is sent to Message Pool  //Lec- 6th July 2021, 2hr8min
		//WM_QUIT is the only window msg that returns false for GetMessage(), makes the above while loop false & breaks it
		break;
	//this case break block for 1 msg is called as Win32 Message Handler, in .Net Event Handler/Deligate, in Java Listener
		
	default:
		break;
	}
	

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 	//Always Remember to give an empty Enter after this
	//Default Window Proc means OS chya Window cha WndProc i.e Desktop Window cha WndProc

}
