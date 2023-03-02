#include "pch.h"
#include "Shader.h"
#include "Shader.g.cpp"
#include "CompilerMessage.g.h"

using namespace std;
namespace winrt
{
    using namespace Microsoft::UI::Xaml;
    using namespace Microsoft::UI::Xaml::Media::Imaging;
    using namespace Windows::Foundation;
    using namespace Windows::Storage;
    using namespace Windows::Storage::Streams;
}

namespace winrt::ShaderProject::implementation
{
    Shader::Shader(Windows::Storage::StorageFile file)
        : mFile(file)
    {
        mCompilerMessages = single_threaded_observable_vector<IInspectable>();
    }
    
    Microsoft::UI::Xaml::Visibility Shader::errorBadgeVisibility() const
    {
        return (mErrorCount > 0) ? Visibility::Visible : Visibility::Collapsed;
    }

    Microsoft::UI::Xaml::Visibility Shader::warningBadgeVisibility() const
    {
        return (mWarningCount > 0) ? Visibility::Visible : Visibility::Collapsed;
    }
}