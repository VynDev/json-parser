#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "constant.h"
#include "Object.h"

namespace JSON {
    class Parser {

        public:

        Parser(const std::string& filename, int mode = SOURCE::FILE);

        bool IsObject() const {return jsonString[0] == '{';}
        bool IsArray() const {return jsonString[0] == '[';};
        bool HasError() const;

        char CurrentChar() const {return jsonString[currentIndex];}
        void NextChar() {++currentIndex;}
        bool IsEnd() const {return currentIndex >= jsonString.size();}

        void SkipWhiteSpaces();

        std::string ParseKey();

        void HandleValue(const std::string& key, Object* object);

        void HandleValue(Array *array);

        bool ParseNull();
        std::string ParseString();
        double ParseNumber();
        bool ParseBool();
        void ParseObject(Object* object);
        void ParseArray(Array* array);

        private:

        std::string filename;
        std::string jsonString;
        size_t currentLine;
        size_t currentIndex;
    };
}