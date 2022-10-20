#include "pch.h"
#include "MyPage.h"

using namespace Windows::UI::Xaml::Media;

MyPage::MyPage(void)
{
	//code
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
