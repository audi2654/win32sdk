#include "pch.h"
#include "Hello.h"
#include "MyPage.h"

using namespace Platform;	//for Array String
/*
int main(Array<String^>^ args)
{
	//code
	Application::Start(ref new ApplicationInitializationCallback([](ApplicationInitializationCallbackParams^ params)		//lambda in WinRT C++ aka Closure, Anonymous, Blob method
		{
			//code
			App^ app = ref new App;
		}));

		return 0;
}
*/

void MyCallbackMethod(ApplicationInitializationCallbackParams^ params)		//in above lambda [] is MyCallbackMethod
{
	//code
	App^ app = ref new App();
}

int main(Array<String^>^ args)
{
	//code
	ApplicationInitializationCallback^ callback = ref new ApplicationInitializationCallback(MyCallbackMethod);
	Application::Start(callback);

	return(0);
}

//App class
App::App(void)
{
	//default empty constr
}

void App::OnLaunched(LaunchActivatedEventArgs^ args)
{
	//code
	MyPage^ page = ref new MyPage();

	Window::Current->Content = page;
	Window::Current->Activate();
}
