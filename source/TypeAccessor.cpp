#include "json-parser/TypeAccessor.h"
#include "json-parser/Array.h"
#include "json-parser/Number.h"
#include "json-parser/Bool.h"
#include "json-parser/String.h"

namespace JSON {
    TypeAccessor::TypeAccessor(Type* object, Type* parent, const std::string& key)
        : object(object), parent(parent), key(key) {

    }

    TypeAccessor::TypeAccessor(Type* object, Type* parent, int index)
        : object(object), parent(parent), index(index) {

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

    bool TypeAccessor::HasIndex() const {
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
            return parent->AsObject()[key];
        }
        else if (parent && parent->IsArray()) {
            if (HasIndex() && IsNumber()) {
                object->AsNumber() = value;
            }
            else if (HasIndex() && !IsNumber()) {
                parent->AsArray().Replace<Number>(index, value);
            }
            return parent->AsArray()[index];
        }
        return parent->AsObject()[key]; // TODO, handle this case
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
            return parent->AsObject()[key];
        }
        else if (parent && parent->IsArray()) {
            if (HasIndex() && IsBool()) {
                object->AsBool() = value;
            }
            else if (HasIndex() && !IsBool()) {
                parent->AsArray().Replace<Bool>(index, value);
            }
            return parent->AsArray()[index];
        }
        return parent->AsObject()[key]; // TODO, handle this case
    }

    TypeAccessor TypeAccessor::operator=(const std::string& value) {
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
            return parent->AsObject()[key];
        }
        else if (parent && parent->IsArray()) {
            if (HasIndex() && IsString()) {
                object->AsString() = value;
            }
            else if (HasIndex() && !IsString()) {
                parent->AsArray().Replace<String>(index, value);
            }
            return parent->AsArray()[index];
        }
        return parent->AsObject()[key]; // TODO, handle this case
    }

    TypeAccessor TypeAccessor::operator=(const char* value) {
        return (*this = std::string(value));
    }

    void TypeAccessor::Delete() {
        if (parent && parent->IsObject())
            parent->AsObject().Delete(key);
    };
}