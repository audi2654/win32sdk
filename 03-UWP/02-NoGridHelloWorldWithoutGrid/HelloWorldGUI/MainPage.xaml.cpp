//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace HelloWorldGUI;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;	//for <Grid></Grid>, <TextBlock></TextBlock>
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;	//for SolidColorBrush(), FontFamily
using namespace Windows::UI::Xaml::Navigation;

using namespace Windows::UI::Text;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();	//COM

	//My Code
	Grid^ grid = ref new Grid();	//makes <Grid> in xaml, ^ is hat & is referenced counted pointer i.e COM pointer
	grid->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);	//using Fully Qualified Name	for Background in <Page>

	TextBlock^ textBlock = ref new TextBlock();
	textBlock->Text = "HelloWorld";
	textBlock->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("SegoUI");	//only FontFamily("SegoUI"); also works but can cause IDE confusion which to choose from because some same methods can exist in multiple namespaces
	textBlock->FontSize = 120;
	textBlock->FontStyle = Windows::UI::Text::FontStyle::Oblique;
	textBlock->FontWeight = Windows::UI::Text::FontWeights::Bold;
	textBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Gold);
	textBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
	textBlock->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;

	grid->Children->Append(textBlock);
	this->Content = grid;
}
