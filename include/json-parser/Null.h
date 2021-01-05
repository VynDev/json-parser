#pragma once
#include "Type.h"

namespace JSON {
    class Null : public Type {

        public:

        virtual std::string ToString(int indentation = 0);
        virtual bool IsNull() const override;

        Null();

        protected:

        virtual void* GetValuePointer() override;
    };
}