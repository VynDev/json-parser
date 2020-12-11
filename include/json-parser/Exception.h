#pragma once
#include <exception>
#include <map>
#include <string>

namespace JSON {
    
    namespace ERRORS {
        enum {
            UNKNOWN = 0,
            MISSING_COMMA,
            VALUE_EXPECTED,

            KEY_MISSING_QUOTE_START,
            KEY_MISSING_QUOTE_END,
            KEY_MISSING_SEPARATOR,

            MISSING_CLOSING_OBJECT,
            MISSING_CLOSING_ARRAY,

            STRING_MISSING_QUOTE_END,

            UNKNOWN_VALUE,

            NUMBER_WRONG,
            NUMBER_MULTIPLE_DOT
        };
    }

    extern std::map<int, std::string> errors;

    class Exception : public std::exception {

        public:

        Exception(int errorCode, int line);

        /* 
        *   Same purpose as exception::what()
        *   but because it won't be used outside of the library I won't use what()
        */
        const std::string& GetReason() const;

        int GetLine() const;
        
        private:

        int errorCode;
        std::string reason;
        int line;
    };
}