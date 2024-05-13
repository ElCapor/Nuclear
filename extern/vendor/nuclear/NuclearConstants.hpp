#ifndef NUCLEARCONSTANTS_HPP
#define NUCLEARCONSTANTS_HPP
#include <string>
#include <map>
#include <vector>
#include <luaconfig/luaconf.h>
namespace nuclear
{   
    /// @brief Manage dynamic constants
    class DynamicConstantManager
    {
    public:
        /// @brief Get a constant by it's name
        /// @param name name of the constant
        /// @return the associated constant
        luaconf::Value& GetConstant(std::string name);

        /// @brief Directly return the value from the constant
        /// @tparam T return type (double/float/string etc)
        /// @param constantName Name of the constant
        /// @return the value if any
        template <typename T>
        T GetValue(std::string constantName)
        {
            return GetConstant(constantName).Get<T>();
        }

        /// @brief Add a new constant into the manager
        /// @param val the constant to add
        /// @param constantName the name of the constant
        void AddConstant(luaconf::Value val, std::string constantName, bool replace = false);

        std::map<std::string, luaconf::Value>& Map();
    private:
       std::map<std::string, luaconf::Value> m_Constants;
    };
}

#endif /* NUCLEARCONSTANTS_HPP */
