#include "NuclearConstants.hpp"

nuclear::DynamicConstant* nuclear::DynamicConstantManager::GetConstant(std::string name)
{
    for (auto& constant : m_DynamicConstants)
    {
        if (constant->Name() == name)
            return constant;
    }
    return nullptr;
}