#include "json-parser/Exception.h"
#include <map>
#include <iostream>

using namespace std;

namespace JSON {
    map<int, string> errors = {
        {ERRORS::UNKNOWN, "Unknown error occured"},
        {ERRORS::CANT_OPEN_FILE, "Can't open file"},

        {ERRORS::MISSING_COMMA, "Missing comma"},
        {ERRORS::VALUE_EXPECTED, "Value expected (maybe you forgot a trailing comma)"},

        {ERRORS::OBJECT_MISSING_CLOSING_BRACKET, "Missing closing bracket for object"},
        {ERRORS::OBJECT_MISSING_OPENING_BRACKET, "Missing opening bracket for object"},

        {ERRORS::KEY_MISSING_QUOTE_START, "Missing quote a the beginning of the key"},
        {ERRORS::KEY_MISSING_QUOTE_END, "Missing quote a the end of the key"},
        {ERRORS::KEY_MISSING_SEPARATOR, "Missing ':' after the key"},

        {ERRORS::MISSING_CLOSING_OBJECT, "Missing '}'"},
        {ERRORS::MISSING_CLOSING_ARRAY, "Missing ']"},

        {ERRORS::STRING_MISSING_QUOTE_END, "Missing quote at the end for string value"},

        {ERRORS::UNKNOWN_VALUE, "Unknown value type"},

        {ERRORS::NUMBER_WRONG, "Number value contains an error"},
        {ERRORS::NUMBER_MULTIPLE_DOT, "Number value contains multiple dot"}
    };

    Exception::Exception(int errorCode, int line) : errorCode(errorCode), line(line) {
        reason = errors[errorCode] + string(" at line ") + to_string(line);
    }

    const string& Exception::GetReason() const {
        return reason;
    }

    int Exception::GetLine() const {
        return line;
    }

    int Exception::GetErrorCode() const {
        return errorCode;
    }
}