#ifndef NUCLEAR_ENGINE_HPP
#define NUCLEAR_ENGINE_HPP
/*
* The main nuclear reactor engine code
*/
#include "NuclearConstants.hpp"
#include "Atomic.hpp"
namespace nuclear
{
    /// @brief Nuclear Reactor Engine
    class Engine
    {
        public:
        DynamicConstantManager& GetConstMgr();
        nuclear::atomic::NucleusManager& GetNucleusMgr();
        void StartSimulation();
        private:
        // manage constants
        DynamicConstantManager m_DynConstMgr;
        nuclear::atomic::NucleusManager m_NucleusMgr;
    };
};


#endif