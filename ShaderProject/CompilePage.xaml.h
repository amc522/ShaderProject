// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "CompilePage.g.h"

namespace winrt::ShaderProject::implementation
{
    struct CompilePage : CompilePageT<CompilePage>
    {
        CompilePage();

        Windows::Foundation::IAsyncAction OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs);

    private:
        Windows::Foundation::IAsyncAction getShadersAsync();

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> mShaders;
    };
}

namespace winrt::ShaderProject::factory_implementation
{
    struct CompilePage : CompilePageT<CompilePage, implementation::CompilePage>
    {
    };
}
