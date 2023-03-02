// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace ShaderProject;
using namespace ShaderProject::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif
}

/// <summary>
/// Invoked when the application is launched.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    //mCurrentTheme = RequestedTheme();
    //auto uiSettings = UISettings();
    //mCurrentAccentColor = uiSettings.GetColorValue(UIColorType::Accent);

    //window = winrt::Microsoft::UI::Xaml::Window();
    //window.Activate();

    //Frame rootFrame = CreateRootFrame();
    //if (!rootFrame.Content())
    //{
    //    TextBlock textBlock;
    //    textBlock.Text(hstring(L"Text of the TextBlock"));

    //    TextBlock buttonText;
    //    buttonText.Text(hstring(L"Test Button"));

    //    Button button;
    //    button.Content(buttonText);
    //    button.Click({ this, &App::OnButtonClicked });
    //    button.RequestedTheme(ElementTheme::Default);

    //    mListItems = single_threaded_observable_vector<IInspectable>();

    //    ListView listView;
    //    listView.ItemsSource(mListItems);

    //    StackPanel stackPanel;
    //    stackPanel.Children().Append(textBlock);
    //    stackPanel.Children().Append(button);
    //    stackPanel.Children().Append(listView);
    //    stackPanel.Spacing(10.0);

    //    auto ret = Application::Current().Resources().Lookup(box_value(L"SolidBackgroundFillColorBaseBrush"));
    //    auto brush = ret.try_as<Microsoft::UI::Xaml::Media::SolidColorBrush>();

    //    Page page;
    //    page.Background(brush);
    //    page.Content(stackPanel);

    //    rootFrame.ActualThemeChanged([this, uiSettings, page](const FrameworkElement& /*element*/, const IInspectable& /*object*/)
    //        {
    //            const ApplicationTheme theme = this->RequestedTheme();
    //            if (mCurrentTheme != theme)
    //            {
    //                mCurrentTheme = theme;

    //                auto ret = Application::Current().Resources().Lookup(box_value(L"SolidBackgroundFillColorBaseBrush"));
    //                auto brush = ret.try_as<Microsoft::UI::Xaml::Media::SolidColorBrush>();
    //                page.Background(brush);
    //            }

    //            const Color accentColor = uiSettings.GetColorValue(UIColorType::Accent);
    //            if (mCurrentAccentColor != accentColor)
    //            {

    //            }
    //        });
    //}

    mWindow = make<MainWindow>();
    mWindow.Activate();

    Frame rootFrame = createRootFrame();

    if (!rootFrame.Content())
    {
        rootFrame.Navigate(xaml_typename<CompilePage>());
    }
}

/// <summary>
/// Invoked when Navigation to a certain page fails
/// </summary>
/// <param name="sender">The Frame that failed navigation</param>
/// <param name="e">Details about the navigation failure</param>
void App::OnNavigationFailed(IInspectable const&, NavigationFailedEventArgs const& e)
{
    throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
}

Frame App::createRootFrame()
{
    Frame rootFrame{ nullptr };

    auto content = mWindow.Content();
    if (content)
    {
        rootFrame = content.try_as<Frame>();
    }

    // Don't repeat app initialization when the Window already has content,
    // just ensure that the window is active
    if (!rootFrame)
    {
        // Create a Frame to act as the navigation context
        rootFrame = Frame();

        rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

        // Place the frame in the current Window
        mWindow.Content(rootFrame);
    }

    return rootFrame;
}