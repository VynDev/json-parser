#include <string>
#include <iostream>
#include <fstream>
#include "json-parser/JSON.h"
#include "json-parser/Parser.h"

using namespace std;

namespace JSON {

    Parser::Parser(const string& filename) : filename(filename), currentIndex(0), currentLine(1), jsonString("") {
        ifstream file(filename);
        if (!file) {
            cout << "Cannot open file" << endl;
            exit(1);
        }

        while (!file.eof()) {
            string line;
            getline(file, line);
            jsonString += line + "\n";
        }
        file.close();
    }

    void Parser::SkipWhiteSpaces() {
        while (CurrentChar() == ' ' || CurrentChar() == '\t' || CurrentChar() == '\n') {
            if (CurrentChar() == '\n')
                ++currentLine;
            NextChar();
        }
    }

    string Parser::ParseKey() {
        if (CurrentChar() != '"')
            throw Exception(ERRORS::KEY_MISSING_QUOTE_START, currentLine);
        NextChar();
        int start = currentIndex;
        while (CurrentChar() != '"')
            NextChar();
        string key = jsonString.substr(start, currentIndex - start);
        NextChar();
        return key;
    }

    void Parser::HandleValue(const string& key, Object* object) {
        if (CurrentChar() == '"')
            object->AddField(key, ParseString());
        else if (isdigit(CurrentChar()) || CurrentChar() == '-')
            object->AddField(key, ParseNumber());
        else if (CurrentChar() == 't' || CurrentChar() == 'f')
            object->AddField(key, ParseBool());
        else if (CurrentChar() == '{')
            ParseObject(&object->AddObject(key));
        else if (CurrentChar() == '[')
            ParseArray(&object->AddArray(key));
        else
            throw Exception(ERRORS::VALUE_EXPECTED, currentLine);
            
    }

    void Parser::HandleValue(Array* array) {
        if (CurrentChar() == '"')
            array->AddElement(ParseString());
        else if (isdigit(CurrentChar()) || CurrentChar() == '-')
            array->AddElement(ParseNumber());
        else if (CurrentChar() == 't' || CurrentChar() == 'f')
            array->AddElement(ParseBool());
        else if (CurrentChar() == '{') {
            ParseObject(&array->AddObject());
        }
        else
            throw Exception(ERRORS::VALUE_EXPECTED, currentLine);
        /*else if (CurrentChar() == '[') {    
            ParseArray(array->AddArray());
        }*/
            
    }

    string Parser::ParseString() {
        NextChar();
        int start = currentIndex;
        while (CurrentChar() != '"' && !IsEnd())
            NextChar();
        string value = jsonString.substr(start, currentIndex - start);
        NextChar();
        return value;
    }

    double Parser::ParseNumber() {
        bool hasDot = false;
        int start = currentIndex;
        if (CurrentChar() == '-')
            NextChar();
        while (isdigit(CurrentChar()) || CurrentChar() == '.') {
            if (CurrentChar() == '.')
                hasDot ? throw Exception(ERRORS::NUMBER_MULTIPLE_DOT, currentLine) : hasDot = true;
            NextChar();
        }
        return atof(jsonString.substr(start, currentIndex - start).c_str());
    }

    bool Parser::ParseBool() {
        int start = currentIndex;
        while (CurrentChar() != ',' && CurrentChar() != '}' && CurrentChar() != ']')
            NextChar();
        string stringValue = jsonString.substr(start, currentIndex - start);
        if (stringValue == "true")
            return true;
        if (stringValue == "false")
            return false;
        throw Exception(ERRORS::UNKNOWN_VALUE, currentLine);
    }

    void Parser::ParseObject(Object* object) {

        NextChar();
        while (!IsEnd()) {
            SkipWhiteSpaces();
            string key = ParseKey();
            SkipWhiteSpaces();
            if (CurrentChar() != ':')
                throw Exception(ERRORS::KEY_MISSING_SEPARATOR, currentLine);
            NextChar();
            SkipWhiteSpaces();
            HandleValue(key, object);
            SkipWhiteSpaces();

            if (CurrentChar() == '}') {
                NextChar();
                break;
            }
            else if (CurrentChar() == ',') {
                NextChar();
            }
            else {
                cout << "Parsing error" << endl;
            }
        }
    }

    void Parser::ParseArray(Array* array) {

        NextChar();
        while (!IsEnd()) {
            SkipWhiteSpaces();
            HandleValue(array);
            SkipWhiteSpaces();

            if (CurrentChar() == ']') {
                NextChar();
                break;
            }
            else if (CurrentChar() == ',') {
                NextChar();
            }
            else {
                cout << "Parsing error" << endl;
            }
        }
    }
}