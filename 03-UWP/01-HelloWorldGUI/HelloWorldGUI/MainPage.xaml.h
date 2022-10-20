//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

using namespace Windows::UI::Core; //for corewindow & keyeventargs
using namespace Windows::UI::Xaml;

namespace HelloWorldGUI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

		//code
		void OnKeyDown(CoreWindow^ sender, KeyEventArgs^ args);
		void OnButtonClick(Object^ sender, RoutedEventArgs^ args);
	};
}
