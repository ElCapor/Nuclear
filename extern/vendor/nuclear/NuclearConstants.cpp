#include "NuclearConstants.hpp"

namespace Nuclear
{

}

luaconf::Value &nuclear::DynamicConstantManager::GetConstant(std::string name)
{
    for (auto& val : m_Constants)
        if (val.first == name)
            return val.second;
    auto v = luaconf::Value("NoConstant");
    return v;
}

void nuclear::DynamicConstantManager::AddConstant(luaconf::Value val, std::string constantName, bool replace)
{
    if (m_Constants.find(constantName) == m_Constants.end() || replace)
    {
        m_Constants[constantName] = val;
        return;
    }
    printf("A constant with the name %s already exists, this one will not be added unless the replace option is used\n", constantName.c_str());
}

std::map<std::string, luaconf::Value> &nuclear::DynamicConstantManager::Map()
{
    return m_Constants;
}
