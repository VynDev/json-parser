#include <sstream>
#include <limits>
#include "json-parser/Number.h"

using namespace std;

namespace JSON {
    Number::Number(double value) : value(value) {
        this->value = value;
    }

    void Number::SetValue(double value) {
        this->value = value;
    }

    double Number::GetValue() const {
        return this->value;
    }

    string Number::ToString(int indentation) {
        ostringstream out;
        out.precision(numeric_limits<double>::max_digits10 + 2);
        out << fixed << this->value;
        return out.str();
    }

    void* Number::GetValuePointer() {
        return &value;
    }

    bool Number::IsNumber() const {
        return true;
    }
}