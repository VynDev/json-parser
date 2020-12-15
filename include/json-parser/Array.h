#pragma once
#include "Type.h"

namespace JSON {

    class Object;

    class Array : public Type {

        public:

        virtual std::string ToString(int indentation = 0);

        void AddElement(const char* value);
        void AddElement(const std::string& value);
        void AddElement(const double value);

        const std::vector<std::unique_ptr<Type>> &GetElements() const;

        Object &AddObject();
        Array &AddArray();

        protected:

        void *GetValuePointer() override {
            return this;
        }

        private:

        std::vector<std::unique_ptr<Type>> elements;

    };
}