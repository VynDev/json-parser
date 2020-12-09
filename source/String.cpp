#include "json-parser/String.h"

using namespace std;

namespace JSON {
    String::String(const string& value) : value(value) {

    }

    std::string String::ToString(int indentation) {
        return "\"" + GetValue() + "\"";
    }

    void String::SetValue(const string& value) {
        this->value = value;
    }

    const std::string& String::GetValue() const {
        return value;
    }
}