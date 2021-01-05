#pragma once
#include "Type.h"

namespace JSON {

    class Object;

    class Array : public Type {

        public:

        Array() {};
        Array(const std::string& filename);

        virtual std::string ToString(int indentation = 0);
        virtual bool IsArray() const override;

        void AddElement();
        void AddElement(const char* value);
        void AddElement(const std::string& value);
        void AddElement(const int value);
        void AddElement(const double value);
        void AddElement(const bool value);

        const std::vector<std::unique_ptr<Type>>& GetElements() const;

        Object& AddObject();
        Array& AddArray();

        bool IsValid() const {return bIsValid;}

        int GetLenth() const {return elements.size();}

        void Save(const std::string& filename);

        TypeAccessor operator[] (int index);

        void Delete(int index);

        template<class T>
        void Replace(int index, T value) {
            elements.erase(elements.begin() + index);
            elements.insert(elements.begin() + index, std::make_unique<T>(value));
        }

        std::string GetError() const;
        int GetErrorCode() const;
        int GetErrorLine() const;

        protected:

        virtual void* GetValuePointer() override;

        private:

        bool bIsValid = true;
        std::string error;
        int errorCode;
        int errorLine;

        std::vector<std::unique_ptr<Type>> elements;

    };
}