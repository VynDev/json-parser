#include <iostream>
#include <fstream>

#include "json-parser/Object.h"
#include "json-parser/String.h"
#include "json-parser/Bool.h"
#include "json-parser/Number.h"
#include "json-parser/Array.h"
#include "json-parser/Parser.h"
#include "json-parser/Exception.h"

using namespace std;

namespace JSON {

    Object::Object(const std::string& filename) {
        Parser parser(filename);

        try {
            parser.ParseObject(this);
        }
        catch (const Exception& e) {
            bIsValid = false;
            error = e.GetReason();
        }
    }

    void Object::AddField(const string& name, const char* value) {
        AddField(name, static_cast<string>(value));
    }

    void Object::AddField(const string& name, const string& value) {
        fields.insert(std::make_pair(name, make_unique<String>(value)));
    }

    void Object::AddField(const std::string& name, int value) {
        AddField(name, static_cast<double>(value));
    }

    void Object::AddField(const std::string& name, double value) {
        fields.insert(std::make_pair(name, make_unique<Number>(value)));
    }

    void Object::AddField(const string& name, bool value) {
        fields.insert(std::make_pair(name, make_unique<Bool>(value)));
    }

    Object &Object::AddObject(const string& name) {
        auto pair = fields.insert(std::make_pair(name, make_unique<Object>()));
        return *(static_cast<Object*>(pair.first->second.get()));
    }

    string Object::ToString(int indentation) {
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

    const std::map<std::string, std::unique_ptr<Type>> &Object::GetMap() const {
        return fields;
    }

    Array &Object::AddArray(const string& name) {
        auto pair = fields.insert(std::make_pair(name, make_unique<Array>()));
        return *(static_cast<Array*>(pair.first->second.get()));
    }
}

