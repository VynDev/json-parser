#include "json-parser/Null.h"

using namespace std;

namespace JSON {
    Null::Null() {

    }

    string Null::ToString(int indentation) {
        return "null";
    }

    void* Null::GetValuePointer() {
        return 0;
    }

    bool Null::IsNull() const {
        return true;
    }
}