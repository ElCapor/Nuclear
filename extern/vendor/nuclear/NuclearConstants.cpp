#include "NuclearConstants.hpp"

std::vector<nuclear::DynamicConstant*> nuclear::m_DynamicConstants = {};

nuclear::DynamicConstant* nuclear::GetConstant(std::string name)
{
    for (auto& constant : nuclear::m_DynamicConstants)
    {
        if (constant->Name() == name)
            return constant;
    }
    return nullptr;
}