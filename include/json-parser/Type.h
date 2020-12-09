#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>

namespace JSON {
    class Type {

        public:

        virtual std::string ToString(int indentation = 0) = 0;

        std::string GetTabString(int count) const {
            std::string returnValue = "";
            for (int i = 0; i < count; ++i) {
                returnValue += "\t";
            }
            return returnValue;
        }
    };
}