#pragma once
#include "Type.h"

namespace JSON {
    class String : public Type {

        public:

        virtual std::string ToString(int indentation = 0) override;

        String(const std::string& value);

        void SetValue(const std::string& value);
        const std::string &GetValue() const;

        protected:

        void *GetValuePointer() override {
            return &value;
        }

        private:

        std::string value;
    };
}