#pragma once
#include "constant.h"
#include "Type.h"
#include "Exception.h"

namespace JSON {
    class Array;

    class Object : public Type {

        public:

        Object() {};
        Object(const std::string& filename, int mode = SOURCE::FILE);

        virtual std::string ToString(int indentation = 0);
        virtual bool IsObject() const override;

        bool HasKey(const std::string& key) const;

        void AddField(const std::string& name);
        void AddField(const std::string& name, const char* value);
        void AddField(const std::string& name, const std::string& value);
        void AddField(const std::string& name, int value);
        void AddField(const std::string& name, double value);
        void AddField(const std::string& name, bool value);
        void AddField(const std::string& name, const Object &object);
        
        Object &AddObject(const std::string& name);
        Array &AddArray(const std::string& name);

        void Delete(const std::string& key);

        void Save(const std::string& filename);
        bool IsValid() const {return bIsValid;}

        std::string GetError() const;
        int GetErrorCode() const;
        int GetErrorLine() const;

        TypeAccessor operator[] (const std::string& key);

        protected:

        virtual void* GetValuePointer() override;

        private:

        bool bIsValid = true;
        std::string error;
        int errorCode;
        int errorLine;

        const std::map<std::string, std::unique_ptr<Type>>& GetMap() const;
        std::map<std::string, std::unique_ptr<Type>> fields;
    };
}