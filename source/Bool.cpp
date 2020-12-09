#include "json-parser/Bool.h"

using namespace std;

namespace JSON {
    Bool::Bool(bool value) : value(value) {

    }

    void Bool::SetValue(bool value) {
        this->value = value;
    }

    bool Bool::GetValue() const {
        return value;
    }

    std::string Bool::ToString(int indentation) {
        return GetValue() ? "true" : "false";
    }
}