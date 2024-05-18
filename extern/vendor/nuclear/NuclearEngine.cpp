#include "NuclearEngine.hpp"

nuclear::DynamicConstantManager& nuclear::Engine::GetConstMgr()
{
    return m_DynConstMgr;
}

nuclear::atomic::NucleusManager &nuclear::Engine::GetNucleusMgr()
{
    return m_NucleusMgr;
}

void nuclear::Engine::StartSimulation()
{
    
}
