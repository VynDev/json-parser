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

    std::string Number::ToString(int indentation) {
        std::ostringstream out;
        out.precision(std::numeric_limits<double>::max_digits10 + 2);
        out << std::fixed << this->value;
        return out.str();
    }

    void *Number::GetValuePointer() {
        return &value;
    }

    bool Number::IsNumber() const {
        return true;
    }
}