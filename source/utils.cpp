#include "json-parser/utils.h"

namespace JSON {
    void EscapeQuotes(std::string* text) {
        size_t pos = text->find("\"");
        while(pos != std::string::npos) {
            text->replace(pos, 1, "\\\"");
            pos = text->find("\"", pos + 2);
        }
    }

    void UnescapeQuotes(std::string* text) {
        size_t pos = text->find("\\\"");
        while(pos != std::string::npos) {
            text->replace(pos, 2, "\"");
            pos = text->find("\\\"", pos + 1);
        }
    }
}