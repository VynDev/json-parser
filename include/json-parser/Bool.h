#pragma once
#include "Type.h"

namespace JSON {
    class Bool : public Type {

        public:

        virtual std::string ToString(int indentation = 0);
        virtual bool IsBool() const override;

        Bool(bool value);

        void SetValue(bool value);
        bool GetValue() const;

        protected:

        virtual void* GetValuePointer() override;

        private:

        bool value;
    };
}