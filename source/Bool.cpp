#include "json-parser/Bool.h"

using namespace std;

namespace JSON {
    Bool::Bool(bool value) : value(value) {

    }

    string Bool::ToString(int indentation) {
        return value ? "true" : "false";
    }

    void* Bool::GetValuePointer() {
        return &value;
    }

    bool Bool::IsBool() const {
        return true;
    }
}