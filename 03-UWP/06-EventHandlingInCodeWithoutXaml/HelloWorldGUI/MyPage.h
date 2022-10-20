#pragma once
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml;	//textblock, object
using namespace Windows::UI::Core;	//corewindwo


ref class MyPage sealed :Page
{
private:
	TextBlock^ m_textBlock;
public:
	MyPage(void);

	void OnKeyDown(CoreWindow^, KeyEventArgs^);
	void OnButtonClick(Object^, RoutedEventArgs^);
};
