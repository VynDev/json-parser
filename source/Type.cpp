#include "json-parser/Type.h"

namespace JSON {
    std::string Type::ToString(int indentation) {
        return "TypeUnknown";
    }

    std::string& Type::AsString() {
        return *static_cast<std::string *>(GetValuePointer());
    }

    double& Type::AsNumber() {
        return *static_cast<double *>(GetValuePointer());
    }

    bool& Type::AsBool() {
        return *static_cast<bool *>(GetValuePointer());
    }

    Object& Type::AsObject() {
        return *static_cast<Object *>(GetValuePointer());
    }

    Array& Type::AsArray() {
        return *static_cast<Array *>(GetValuePointer());
    }

    std::string Type::GetTabString(int count) const {
        std::string returnValue = "";
        for (int i = 0; i < count; ++i) {
            returnValue += "\t";
        }
        return returnValue;
    }
}