#include "json-parser/Array.h"
#include "json-parser/Object.h"
#include "json-parser/String.h"
#include "json-parser/Bool.h"
#include "json-parser/Number.h"

using namespace std;

namespace JSON {
    string Array::ToString(int indentation) {
        if (elements.size() == 0)
            return "[]";
        string returnValue = "[\n";
        for (int i = 0; i < elements.size(); ++i) {
            if (i != 0)
                returnValue += ",\n";
            returnValue += GetTabString(indentation + 1) + elements[i]->ToString(indentation + 1);
        }
        returnValue += "\n" + GetTabString(indentation) + "]";
        return returnValue;
    }

    const vector<unique_ptr<Type>> &Array::GetElements() const {
        return elements;
    }

    void Array::AddElement(const char* value) {
        AddElement(static_cast<string>(value));
    }

    void Array::AddElement(const string& value) {
        elements.push_back(make_unique<String>(value));
    }

    void Array::AddElement(const double value) {
        elements.push_back(make_unique<Number>(value));
    }

    Object& Array::AddObject() {
        elements.push_back(make_unique<Object>());
        return *(static_cast<Object*>(elements[elements.size() - 1].get()));
    }

    Array& Array::AddArray() {
        elements.push_back(make_unique<Array>());
        return *(static_cast<Array*>(elements[elements.size() - 1].get()));
    }

    void* Array::GetValuePointer() {
        return this;
    }

    bool Array::IsArray() const {
        return true;
    }
}