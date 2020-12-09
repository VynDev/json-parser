#include "json-parser/Number.h"

using namespace std;

namespace JSON {
    Number::Number(double value) : value(value) {

    }

    void Number::SetValue(double value) {
        this->value = value;
    }

    double Number::GetValue() const {
        return value;
    }

    std::string Number::ToString(int indentation) {
        return to_string(value);
    }
}