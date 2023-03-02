#pragma

#include "CompilerMessage.g.h"

namespace winrt::ShaderProject::implementation
{
struct CompilerMessage : CompilerMessageT<CompilerMessage>
{
    CompilerMessage() = default;
    CompilerMessage(CompilerMessageType type, int32_t line, int32_t column, hstring message);

    CompilerMessageType type() const { return mMessageType; }
    int32_t line() const { return mLine; }
    int32_t column() const { return mColumn; }
    hstring message() const { return mMessage; }

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

    CompilerMessageType mMessageType = CompilerMessageType::Info;
    int32_t mLine = -1;
    int32_t mColumn = -1;
    hstring mMessage;

    event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
};
}

namespace winrt::ShaderProject::factory_implementation
{
    struct CompilerMessage : CompilerMessageT<CompilerMessage, implementation::CompilerMessage>
    {
    };
}