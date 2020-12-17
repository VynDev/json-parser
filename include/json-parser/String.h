#pragma once
#include "Type.h"

namespace JSON {
    class String : public Type {

        public:

        String(const std::string& value);

        virtual std::string ToString(int indentation = 0) override;
        virtual bool IsString() const override;

        void SetValue(const std::string& value);
        const std::string &GetValue() const;

        protected:

        virtual void *GetValuePointer() override;

        private:

        std::string value;
    };
}