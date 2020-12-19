#include "json-parser/TypeAccessor.h"

namespace JSON {
    TypeAccessor::TypeAccessor(Type* object, Type* parent, const std::string& key)
        : object(object), parent(parent), key(key) {

    }

    std::string TypeAccessor::ToString(int indentation) {
        return object != nullptr ? object->ToString(indentation) : "ToString() Error";
    }

    bool TypeAccessor::IsString() const {
        return object != nullptr && object->IsString();
    }

    bool TypeAccessor::IsNumber() const {
        return object != nullptr && object->IsNumber();
    }

    bool TypeAccessor::IsBool() const {
        return object != nullptr && object->IsBool();
    }

    bool TypeAccessor::IsObject() const {
        return object != nullptr && object->IsObject();
    }

    bool TypeAccessor::IsArray() const {
        return object != nullptr && object->IsArray();
    }

    bool TypeAccessor::KeyExists() const {
        return object != nullptr;
    }

    std::string& TypeAccessor::AsString() {
        return *static_cast<std::string*>(object->GetValuePointer());
    }

    double& TypeAccessor::AsNumber() {
        return *static_cast<double*>(object->GetValuePointer());
    }

    bool& TypeAccessor::AsBool() {
        return *static_cast<bool*>(object->GetValuePointer());
    }

    Object& TypeAccessor::AsObject() {
        return *static_cast<Object*>(object->GetValuePointer());
    }

    Array& TypeAccessor::AsArray() {
        return *static_cast<Array*>(object->GetValuePointer());
    }

    TypeAccessor TypeAccessor::operator=(int value) {
        return *this = static_cast<double>(value);
    }

    TypeAccessor TypeAccessor::operator=(double value) {
        if (parent && parent->IsObject()) {
            if (KeyExists() && IsNumber()) {
                object->AsNumber() = value;
            }
            else if (KeyExists() && !IsNumber()) {
                parent->AsObject().Delete(key);
                parent->AsObject().AddField(key, value);
            }
            else if (!KeyExists()) {
                parent->AsObject().AddField(key, value);
            }
        }
        return parent->AsObject()[key];
    }

    TypeAccessor TypeAccessor::operator=(bool value) {
        if (parent && parent->IsObject()) {
            if (KeyExists() && IsBool()) {
                object->AsBool() = value;
            }
            else if (KeyExists() && !IsBool()) {
                parent->AsObject().Delete(key);
                parent->AsObject().AddField(key, value);
            }
            else if (!KeyExists()) {
                parent->AsObject().AddField(key, value);
            }
        }
        return parent->AsObject()[key];
    }

    TypeAccessor TypeAccessor::operator=(const char* value) {
        if (parent && parent->IsObject()) {
            if (KeyExists() && IsString()) {
                object->AsString() = value;
            }
            else if (KeyExists() && !IsString()) {
                parent->AsObject().Delete(key);
                parent->AsObject().AddField(key, value);
            }
            else if (!KeyExists()) {
                parent->AsObject().AddField(key, value);
            }
        }
        return parent->AsObject()[key];
    }

    void TypeAccessor::Delete() {
        if (parent && parent->IsObject())
            parent->AsObject().Delete(key);
    };
}