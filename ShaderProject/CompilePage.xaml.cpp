// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "CompilePage.xaml.h"
#if __has_include("CompilePage.g.cpp")
#include "CompilePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::Storage::Search;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ShaderProject::implementation
{
    CompilePage::CompilePage()
    {
        InitializeComponent();

        mShaders = single_threaded_observable_vector<IInspectable>();
        ShaderListView().ItemsSource(mShaders);
    }

    Windows::Foundation::IAsyncAction CompilePage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs)
    {
        if (mShaders.Size() == 0)
        {
            co_await getShadersAsync();
        }
    }


    // Loads images from the user's Pictures library.
    IAsyncAction CompilePage::getShadersAsync()
    {
        // Show the loading progress bar.
        LoadProgressIndicator().Visibility(Microsoft::UI::Xaml::Visibility::Visible);

        // File type filter.
        QueryOptions options{};
        options.FolderDepth(FolderDepth::Shallow);
        options.FileTypeFilter().Append(L".hlsl");

        // Get the Pictures library.
        StorageFolder documentsFolder = KnownFolders::DocumentsLibrary();
        auto result = documentsFolder.CreateFileQueryWithOptions(options);
        auto hlslFiles = co_await result.GetFilesAsync();

        // Populate Photos collection.
        for (auto&& file : hlslFiles)
        {
            // Only files on the local computer are supported. 
            // Files on OneDrive or a network location are excluded.
            if (file.Provider().Id() == L"computer")
            {
                Shader shader(file);
                mShaders.Append(shader);
            }
        }

        // Hide the loading progress bar.
        LoadProgressIndicator().Visibility(Microsoft::UI::Xaml::Visibility::Collapsed);
    }
}
