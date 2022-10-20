#pragma once
using namespace Windows::UI::Xaml;	//for sealed Application
using namespace Windows::ApplicationModel::Activation;	//for LaunchActivatedEventArgs


ref class App sealed :Application		//in package manifest App class is mentioned
{
public:
	App(void);	//constructor

	virtual void OnLaunched(LaunchActivatedEventArgs^ args) override;	//Pure virtual function in WinRT //sealed from WinRT is Final Class from Java, concrete class from COM
};
