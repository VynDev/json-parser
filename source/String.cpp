#include "json-parser/String.h"
#include "json-parser/utils.h"

namespace JSON {
    String::String(const std::string& value) : value(value) {

    }

    std::string String::ToString(int indentation) {
        std::string valueWithQuotes = value;
        EscapeQuotes(&valueWithQuotes);
        return "\"" + valueWithQuotes + "\"";
    }

    void* String::GetValuePointer() {
        return &value;
    }

    bool String::IsString() const {
        return true;
    }
}