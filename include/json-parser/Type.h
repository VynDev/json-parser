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

        virtual std::string ToString(int indentation = 0);

        std::string& AsString();
        double& AsNumber();
        bool& AsBool();
        Object& AsObject();
        Array& AsArray();

        std::string GetTabString(int count) const;

        protected:

        virtual void *GetValuePointer() = 0;
    };
}