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

    string Bool::ToString(int indentation) {
        return GetValue() ? "true" : "false";
    }

    void* Bool::GetValuePointer() {
        return &value;
    }

    bool Bool::IsBool() const {
        return true;
    }
}