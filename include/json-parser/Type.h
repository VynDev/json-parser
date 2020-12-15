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

        

        virtual std::string ToString(int indentation = 0) {return "TypeUnknown";}

        std::string& AsString() {
            return *static_cast<std::string *>(GetValuePointer());
        }

        double& AsNumber() {
            return *static_cast<double *>(GetValuePointer());
        }

        bool& AsBool() {
            return *static_cast<bool *>(GetValuePointer());
        }

        Object& AsObject() {
            return *static_cast<Object *>(GetValuePointer());
        }

        Array& AsArray() {
            return *static_cast<Array *>(GetValuePointer());
        }

        std::string GetTabString(int count) const {
            std::string returnValue = "";
            for (int i = 0; i < count; ++i) {
                returnValue += "\t";
            }
            return returnValue;
        }

        protected:

        virtual void *GetValuePointer() = 0;
    };
}