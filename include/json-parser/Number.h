#pragma once
#include "Type.h"

namespace JSON {
    class Number : public Type {

        public:

        virtual std::string ToString(int indentation = 0);

        Number(double value);

        void SetValue(double value);
        double GetValue() const;

        protected:

        void *GetValuePointer() override {
            return &value;
        }

        private:

        double value;
    };
}