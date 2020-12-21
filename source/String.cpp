#include "json-parser/String.h"

namespace JSON {
    String::String(const std::string& value) : value(value) {

    }

    std::string String::ToString(int indentation) {
        return "\"" + value + "\"";
    }

    void* String::GetValuePointer() {
        return &value;
    }

    bool String::IsString() const {
        return true;
    }
}