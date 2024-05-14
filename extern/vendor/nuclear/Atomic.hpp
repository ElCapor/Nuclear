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
    std::vector<Nucleus> m_Nucs;

    void AddNucleus()
};
};

#endif /* ATOMIC_HPP */
