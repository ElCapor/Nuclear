#ifndef NUCLEAR_ENGINE_HPP
#define NUCLEAR_ENGINE_HPP
/*
* The main nuclear reactor engine code
*/
#include "NuclearConstants.hpp"

namespace nuclear
{
    /// @brief Nuclear Reactor Engine
    class Engine
    {
        public:
        DynamicConstantManager& GetConstMgr();
        private:
        // manage constants
        DynamicConstantManager m_DynConstMgr;
    };
}


#endif