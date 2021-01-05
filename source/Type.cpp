#include "json-parser/Type.h"

using namespace std;

namespace JSON {
    
    std::string Type::ToString(int indentation) {return "TypeUnknown";}
    bool Type::IsString() const {return false;}
    bool Type::IsNumber() const {return false;}
    bool Type::IsBool() const {return false;}
    bool Type::IsObject() const {return false;}
    bool Type::IsArray() const {return false;}
    bool Type::IsNull() const {return false;}

    string& Type::AsString() {
        return *static_cast<string*>(GetValuePointer());
    }

    double& Type::AsNumber() {
        return *static_cast<double*>(GetValuePointer());
    }

    bool& Type::AsBool() {
        return *static_cast<bool*>(GetValuePointer());
    }

    Object& Type::AsObject() {
        return *static_cast<Object*>(GetValuePointer());
    }

    Array& Type::AsArray() {
        return *static_cast<Array*>(GetValuePointer());
    }

    string Type::GetTabString(int count) const {
        string returnValue = "";
        for (int i = 0; i < count; ++i) {
            returnValue += "\t";
        }
        return returnValue;
    }
}