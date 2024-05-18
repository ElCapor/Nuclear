#ifndef ATOMIC_HPP
#define ATOMIC_HPP
#include <string>
#include <vector>

namespace nuclear::atomic
{

/// @brief Abstract class to represent a nucleus
class Nucleus
{
public:
    Nucleus(std::string symbol = "") : protons(0),
    neutrons(0), atomicMass(0), spin(0), bindingEnergy(0),
    averageNeutronPerFission(0), MaxwellianAveragedCaptureCrossSection(0),
    MaxwellianAveragedFissionCrossSection(0), molarMass(0), symbol(symbol){}

    Nucleus(Nucleus& nuc)
    {
        this->protons = nuc.protons;
        this->neutrons = nuc.neutrons;
        this->symbol = nuc.symbol;
        this->atomicMass = nuc.atomicMass;
        this->charge = nuc.charge;
        this->spin = nuc.spin;
        this->bindingEnergy = nuc.bindingEnergy;
        this->averageNeutronPerFission = nuc.averageNeutronPerFission;
        this->MaxwellianAveragedCaptureCrossSection = nuc.MaxwellianAveragedCaptureCrossSection;
        this->MaxwellianAveragedFissionCrossSection = nuc.MaxwellianAveragedFissionCrossSection;
        this->molarMass = nuc.molarMass;
    }

    int protons; // Number of protons
    int neutrons; // Number of neutrons
    double atomicMass; // Atomic mass in atomic mass units (u)
    double charge; // Charge of the nucleus
    double spin; // Spin of the nucleus
    double bindingEnergy; // Binding energy in MeV
    double averageNeutronPerFission;
    double MaxwellianAveragedCaptureCrossSection; // 
    double MaxwellianAveragedFissionCrossSection;
    double molarMass;
    std::string symbol; // International Symbol
};

/// Handles nucleuses
class NucleusManager
{
public:
    NucleusManager() {}
    std::vector<Nucleus*> m_Nucs;

    void AddNucleus(Nucleus nucleus, bool force = false)
    {
        for (int i=m_Nucs.size()-1; i >= 0; i--)
        {
            Nucleus* nuc = m_Nucs[i];
            if (nuc->symbol == nucleus.symbol)
            {
                if (force)
                {
                    printf("Failed to add nucleus, already exisiting symbol %s, use force option to replace it..\n", nuc->symbol.c_str());
                    return;
                }else
                {
                    printf("[WARNING] Force replaced %s", nuc->symbol.c_str());
                    m_Nucs[i] = new Nucleus(nucleus);
                    delete nuc;
                    return;
                }
            }
            
        }
        m_Nucs.emplace_back(new Nucleus(nucleus));
    }

    Nucleus* get(std::string symbol)
    {
        for (auto& nuc : m_Nucs)
        {
            if (nuc->symbol == symbol)
            {
                return nuc;
            }
        }
    }
};
};

#endif /* ATOMIC_HPP */
