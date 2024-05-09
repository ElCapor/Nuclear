#include "NuclearEngine.hpp"

void nuclear::Engine::LoadConstants(std::vector<DynamicConstant> constants) {
    for (auto& constant : constants)
    {
        m_DynConstMgr.AddConstant(constant);
    }
}