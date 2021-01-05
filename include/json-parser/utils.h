#pragma once
#include <string>

namespace JSON {
    void EscapeQuotes(std::string* text);
    void UnescapeQuotes(std::string* text);
}