#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>

namespace JSON {

    class Object;
    class Array;

    class Type {

        public:

        /**
         *  Returns a string with of the value with the needed padding.
         *  @param indentation The needed padding.
         *  @return The value as string. 
        */
        virtual std::string ToString(int indentation = 0);

        /**
         *  @return true if the value is a string, false otherwise. 
        */
        virtual bool IsString() const;

        /**
         *  @return true if the value is a number (integer, float, double), false otherwise. 
        */
        virtual bool IsNumber() const;

        /**
         *  @return true if the value is a boolean, false otherwise. 
        */
        virtual bool IsBool() const;

        /**
         *  @return true if the value is a json object, false otherwise. 
        */
        virtual bool IsObject() const;

        /**
         *  @return true if the value is a json array, false otherwise. 
        */
        virtual bool IsArray() const;

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

        protected:

        std::string GetTabString(int count) const;
        virtual void* GetValuePointer() = 0;
    };
}