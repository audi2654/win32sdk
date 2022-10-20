#include "pch.h"
#include "MyPage.h"

using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation;

MyPage::MyPage(void)
{
	//code
	Window::Current->CoreWindow->KeyDown += ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &MyPage::OnKeyDown);
	Grid^ grid = ref new Grid();	//makes <Grid> in xaml, ^ is hat & is referenced counted pointer i.e COM pointer
	grid->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);	//using Fully Qualified Name	for Background in <Page>

	m_textBlock = ref new TextBlock();
	m_textBlock->Text = "HelloWorld";
	m_textBlock->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("SegoUI");	//only FontFamily("SegoUI"); also works but can cause IDE confusion which to choose from because some same methods can exist in multiple namespaces
	m_textBlock->FontSize = 96;
	m_textBlock->FontStyle = Windows::UI::Text::FontStyle::Oblique;
	m_textBlock->FontWeight = Windows::UI::Text::FontWeights::Bold;
	m_textBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Gold);
	m_textBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
	m_textBlock->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;

	grid->Children->Append(m_textBlock);

	Button^ button = ref new Button();
	button->Content = "Ok";
	button->Height = 200;
	button->BorderThickness = 12;
	button->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::Gold);
	button->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Gold);
	button->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("TimesNewRoman");
	button->FontSize = 80;
	button->FontStyle = Windows::UI::Text::FontStyle::Oblique;
	button->FontWeight = Windows::UI::Text::FontWeights::Bold;
	button->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Gold);
	button->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
	button->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;

	button->Click += ref new RoutedEventHandler(this, &MyPage::OnButtonClick);


	this->Content = grid;
}
