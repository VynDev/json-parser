#pragma once
#include "Type.h"
#include "Object.h"
#include <iostream>

namespace JSON {
    class TypeAccessor {

        public:

        TypeAccessor(Type* object, Type* parent, const std::string& key);
        TypeAccessor(Type* object, Type* parent, int index);

        /**
         *  Returns a string with of the value with the needed padding.
         *  @param indentation The needed padding.
         *  @return The value as string. 
        */
        std::string ToString(int indentation = 0);

        /**
         *  @return true if the value is a string, false otherwise. 
        */
        bool IsString() const;

        /**
         *  @return true if the value is a number (integer, float, double), false otherwise. 
        */
        bool IsNumber() const;

        /**
         *  @return true if the value is a boolean, false otherwise. 
        */
        bool IsBool() const;

        /**
         *  @return true if the value is a json object, false otherwise. 
        */
        bool IsObject() const;

        /**
         *  @return true if the value is a json array, false otherwise. 
        */
        bool IsArray() const;

        bool KeyExists() const;
        bool HasIndex() const;

        /**
         *  Convert the value to a <std::string>. 
         *  You must be sure the value is a <std::string> before, or it will lead to unexpected behaviors.
         *  @return a reference to the value as a <std::string>. 
        */
        std::string& AsString();

        /**
         *  Convert the value to a <double>. 
         *  You must be sure the value is a <double> before, or it will lead to unexpected behaviors.
         *  @return a reference to the value as a <double>. 
        */
        double& AsNumber();

        /**
         *  Convert the value to a <bool>. 
         *  You must be sure the value is a <bool> before, or it will lead to unexpected behaviors.
         *  @return a reference to the value as a <bool>. 
        */
        bool& AsBool();

        /**
         *  Convert the value to a <JSON::Object>. 
         *  You must be sure the value is a <JSON::Object> before, or it will lead to unexpected behaviors.
         *  @return a reference to the value as a <JSON::Object>. 
        */
        Object& AsObject();

        /**
         *  Convert the value to a <JSON::Array>. 
         *  You must be sure the value is a <JSON::Array> before, or it will lead to unexpected behaviors.
         *  @return a reference to the value as a <JSON::Array>. 
        */
        Array& AsArray();

        TypeAccessor operator=(int value);
        TypeAccessor operator=(double value);
        TypeAccessor operator=(bool value);
        TypeAccessor operator=(const std::string& value);
        TypeAccessor operator=(const char* value);

        void Delete();

        private:

        std::string key;
        int index;
        Type* parent = nullptr;
        Type* object = nullptr;
    };
}