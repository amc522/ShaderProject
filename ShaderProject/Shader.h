#pragma once

#include "Shader.g.h"

namespace winrt::ShaderProject::implementation
{
    struct Shader : ShaderT<Shader>
    {
        Shader(Windows::Storage::StorageFile file);

        Windows::Storage::StorageFile file() const { return mFile; }

        hstring filePath() const { return mFile.Path(); }

        void compilationStatus(CompilationStatus status)
        {
            UpdateValue(L"compilationStatus", mCompilationStatus, status);
        }
        CompilationStatus compilationStatus() const { return mCompilationStatus; }

        bool compiling() const { return mCompilationStatus == CompilationStatus::Compiling; }

        int32_t errorCount() const { return mErrorCount; }

        int32_t warningCount() const { return mWarningCount; }

        Microsoft::UI::Xaml::Visibility errorBadgeVisibility() const;
        Microsoft::UI::Xaml::Visibility warningBadgeVisibility() const;

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> compilerMessages() const { return mCompilerMessages; }
        
        // Property changed notifications.
        event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value)
        {
            return m_propertyChanged.add(value);
        }

        void PropertyChanged(event_token const& token)
        {
            m_propertyChanged.remove(token);
        }

    private:
        template <class T>
        void UpdateValue(hstring const& propertyName, T& var, T value)
        {
            if (var != value)
            {
                var = value;
                RaisePropertyChanged(propertyName);
            }
        }

        void RaisePropertyChanged(hstring const& propertyName)
        {
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
        }

        Windows::Storage::StorageFile mFile;
        CompilationStatus mCompilationStatus = CompilationStatus::None;
        int32_t mErrorCount = 0;
        int32_t mWarningCount = 0;
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> mCompilerMessages;

        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::ShaderProject::factory_implementation
{
    struct Shader : ShaderT<Shader, implementation::Shader>
    {
    };
}