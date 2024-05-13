#include "NuclearConstants.hpp"

namespace Nuclear
{

}

luaconf::Value &nuclear::DynamicConstantManager::GetConstant(std::string name)
{
    for (auto& val : m_Constants)
        if (val.first == name)
            return val.second;
}

void nuclear::DynamicConstantManager::AddConstant(luaconf::Value val, std::string constantName, bool replace)
{
    if (m_Constants.find(constantName) == m_Constants.end() || replace)
    {
        m_Constants[constantName] = val;
    }
    printf("A constant with the name %s already exists, this one will not be added unless the replace option is used", constantName.c_str());
}
