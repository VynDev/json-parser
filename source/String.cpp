#include "json-parser/String.h"

namespace JSON {
    String::String(const std::string& value) : value(value) {

    }

    std::string String::ToString(int indentation) {
        return "\"" + GetValue() + "\"";
    }

    void String::SetValue(const std::string& value) {
        this->value = value;
    }

    const std::string& String::GetValue() const {
        return this->value;
    }

    void* String::GetValuePointer() {
        return &value;
    }

    bool String::IsString() const {
        return true;
    }
}