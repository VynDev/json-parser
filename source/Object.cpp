#include <iostream>
#include <fstream>

#include "json-parser/Null.h"
#include "json-parser/Object.h"
#include "json-parser/String.h"
#include "json-parser/Bool.h"
#include "json-parser/Number.h"
#include "json-parser/Array.h"
#include "json-parser/Parser.h"
#include "json-parser/Exception.h"
#include "json-parser/TypeAccessor.h"

using namespace std;

namespace JSON {

    Object::Object(const string& filename, int mode) {
        try {
            Parser parser(filename, mode);
            parser.ParseObject(this);
        }
        catch (const Exception& e) {
            bIsValid = false;
            error = e.GetReason();
            errorCode = e.GetErrorCode();
            errorLine = e.GetLine();
        }
    }

    void Object::AddField(const string& name) {
        fields.insert(make_pair(name, make_unique<Null>()));
    }

    void Object::AddField(const string& name, const char* value) {
        AddField(name, static_cast<string>(value));
    }

    void Object::AddField(const string& name, const string& value) {
        fields.insert(make_pair(name, make_unique<String>(value)));
    }

    void Object::AddField(const string& name, int value) {
        AddField(name, static_cast<double>(value));
    }

    void Object::AddField(const string& name, double value) {
        fields.insert(make_pair(name, make_unique<Number>(value)));
    }

    void Object::AddField(const string& name, bool value) {
        fields.insert(make_pair(name, make_unique<Bool>(value)));
    }

    Object& Object::AddObject(const string& name) {
        auto pair = fields.insert(make_pair(name, make_unique<Object>()));
        return *(static_cast<Object*>(pair.first->second.get()));
    }


    string Object::ToString(int indentation) {
        if (fields.size() == 0)
            return "{}";
        string returnValue = "{\n";
        for (auto field = fields.rbegin(); field != fields.rend(); ++field) {
            if (field != fields.rbegin())
                returnValue += ",\n";
            returnValue += GetTabString(indentation + 1) + "\"" + field->first + "\": " + field->second->ToString(indentation + 1);
        }
        returnValue += "\n" + GetTabString(indentation) + "}";
        return returnValue;
    }

    void Object::Save(const string& filename) {
        ofstream file(filename);
        if (file) {
            file << ToString();
            file.close();
        }
    }

    const map<string, unique_ptr<Type>> &Object::GetMap() const {
        return fields;
    }

    Array& Object::AddArray(const string& name) {
        auto pair = fields.insert(make_pair(name, make_unique<Array>()));
        return *(static_cast<Array*>(pair.first->second.get()));
    }

    void* Object::GetValuePointer() {
        return this;
    }

    bool Object::IsObject() const {
        return true;
    }

    TypeAccessor Object::operator[] (const string& key) {
        if (!HasKey(key))
            return TypeAccessor(nullptr, this, key);
        return TypeAccessor(fields[key].get(), this, key);
    }

    bool Object::HasKey(const string& key) const {
        return fields.find(key) != fields.end();
    }

    void Object::Delete(const string& key) {
        if (!HasKey(key))
            return ;
        fields.erase(key);
    }

    string Object::GetError() const {
        return error;
    };

    int Object::GetErrorCode() const {
        return errorCode;
    };

    int Object::GetErrorLine() const {
        return errorLine;
    };
}