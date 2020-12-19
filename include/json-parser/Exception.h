#pragma once
#include <exception>
#include <map>
#include <string>

namespace JSON {
    
    namespace ERRORS {
        enum {
            UNKNOWN = 0,
            CANT_OPEN_FILE,
            
            MISSING_COMMA,
            VALUE_EXPECTED,

            OBJECT_MISSING_OPENING_BRACKET,
            OBJECT_MISSING_CLOSING_BRACKET,

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
        int GetErrorCode() const;
        
        private:

        int errorCode;
        std::string reason;
        int line;
    };
}