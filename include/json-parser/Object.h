#pragma once
#include "Type.h"

namespace JSON {
    class Array;

    class Object : public Type {

        public:

        virtual std::string ToString(int indentation = 0);

        void AddField(const std::string& name, const char* value);
        void AddField(const std::string& name, const std::string& value);
        void AddField(const std::string& name, double value);
        void AddField(const std::string& name, bool value);

        void AddField(const std::string& name, const Object &object);
        

        Object &AddObject(const std::string& name);
        Array &AddArray(const std::string& name);

        void Save(const std::string& filename);

        private:

        const std::map<std::string, std::unique_ptr<Type>> &GetMap() const;
        std::map<std::string, std::unique_ptr<Type>> fields;
    };
}