#ifndef NUCLEARCONSTANTS_HPP
#define NUCLEARCONSTANTS_HPP
#include <string>
#include <map>
#include <vector>
namespace nuclear
{
    /// @brief Dynamic constant that can store any type
    class DynamicConstant
    {
    public:

        DynamicConstant(void* ptr = nullptr, std::string name = "UnknownConstant") : value(ptr), name(name) {};
        
        template <typename T>
        DynamicConstant(T value, std::string name = "UnknownConstant") {
            this->value = new T(value);
            this->name = name;
        };

        template <typename T>
        T GetValue()
        {
            return *(T*)value;
        }

        template <typename T>
        void SetValue(T ctor)
        {
            value = new T(ctor);
        }

        std::string& Name()
        {
            return this->name;
        }

        void*& Ptr()
        {
            return value;
        }

    private:
        void* value; // pointer to value
        std::string name; // name of constant
    };
    
    /// @brief Manage dynamic constants
    class DynamicConstantManager
    {
    public:
        std::vector<DynamicConstant*> m_DynamicConstants = {};

        DynamicConstant* GetConstant(std::string name);
        
        template <typename T>
        DynamicConstant* AddConstant(T val, std::string name)
        {
            auto constant = new DynamicConstant(val, name);
            m_DynamicConstants.push_back(constant);
            return constant;
        }

        DynamicConstant* AddConstant(DynamicConstant constant)
        {
            auto real = new DynamicConstant(constant);
            m_DynamicConstants.push_back(real);
            return real;
        }
    };
}

#endif /* NUCLEARCONSTANTS_HPP */
