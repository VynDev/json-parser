#pragma once
#include "Type.h"

namespace JSON {
    class Bool : public Type {

        public:

        virtual std::string ToString(int indentation = 0);

        Bool(bool value);

        void SetValue(bool value);
        bool GetValue() const;

        protected:

        void *GetValuePointer() override {
            return &value;
        }

        private:

        bool value;
    };
}