#include "pch.h"
#include "CompilerMessage.h"
#include "CompilerMessage.g.cpp"

namespace winrt::ShaderProject::implementation
{
    CompilerMessage::CompilerMessage(CompilerMessageType type, int32_t line, int32_t column, hstring message)
        : mMessageType(type)
        , mLine(line)
        , mColumn(column)
        , mMessage(message)
    {}
}