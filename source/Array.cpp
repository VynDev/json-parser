#include <fstream>
#include "json-parser/Array.h"
#include "json-parser/Object.h"
#include "json-parser/String.h"
#include "json-parser/Bool.h"
#include "json-parser/Number.h"
#include "json-parser/Parser.h"
#include "json-parser/TypeAccessor.h"

using namespace std;

namespace JSON {

    Array::Array(const string& filename) {
        try {
            Parser parser(filename);
            parser.ParseArray(this);
        }
        catch (const Exception& e) {
            bIsValid = false;
            error = e.GetReason();
            errorCode = e.GetErrorCode();
            errorLine = e.GetLine();
        }
    }

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

    void Array::AddElement(const int value) {
        AddElement(static_cast<double>(value));
    }

    void Array::AddElement(const bool value) {
        elements.push_back(make_unique<Bool>(value));
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

    void Array::Save(const string& filename) {
        ofstream file(filename);
        if (file) {
            file << ToString();
            file.close();
        }
    }

    TypeAccessor Array::operator[](int index) {
        return TypeAccessor(index < elements.size() ? elements[index].get() : nullptr, this, "");
    }

    void Array::Delete(int index) {
        elements.erase(elements.begin() + index);
    }
}