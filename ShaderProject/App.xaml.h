// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"

namespace winrt::ShaderProject::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        void OnNavigationFailed(IInspectable const&, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e);

    private:
        winrt::Microsoft::UI::Xaml::Controls::Frame createRootFrame();
        winrt::Microsoft::UI::Xaml::Window mWindow{ nullptr };
    };
}
