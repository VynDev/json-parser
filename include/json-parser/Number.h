#pragma once
#include "Type.h"

namespace JSON {
    class Number : public Type {

        public:

        virtual std::string ToString(int indentation = 0);
        virtual bool IsNumber() const override;

        Number(double value);

        void SetValue(double value);
        double GetValue() const;

        protected:

        virtual void *GetValuePointer() override;

        private:

        double value;
    };
}