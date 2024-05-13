local constants = {}

-- Resonance :

constants.NeutronResonanceWidthU238 = 3.6 * 10e-2 --[eV] electron volt
constants.NeutronCapturePartialWidthU238 = 3.5 * 10e-2 --[eV] electron volt
constants.NeutronCenterMassEnergyU238 = 2.5 * 10e-2 --[eV] electron volt
constants.CaptureCrossSectionPeakU238 = 6870 --[b] barns

-- Physics :

constants.BoltzmannConstant = 1.380649 * 10e-23 --[m^2 kg s^-2 K^-1] 
constants.AvogadrosNumber = 6.022141 * 10e23 --[mol^-1]
constants.NeutronAtomicMass = 1.008666 --[a.u]
constants.NeutronMass = 1.674929 * 10e-27 --[kg]

-- Fuel :

constants.FuelLinearExpansionCoefficient = 1.39 * 10e-5 -- [K-1]
constants.FuelMolarMass = 0.27003 --[kg mol^-1]
constants.Uranium238MolarMass = 0.23803 --[kg mol^-1]
constants.FuelEnrichment = 0.04 --[%]

constants.Uranium235MaxwellianAveragedCaptureCrossSection = 97.83 --[b] barns
constants.Uranium238MaxwellianAveragedCaptureCrossSection = 2.690 --[b] barns

constants.Zirconium95MaxwellianAveragedCaptureCrossSection = 1.201 --[b] barns

constants.Uranium235AveragedNeutronPerFission = 2.47 --[n] neutrons
constants.Uranium235MaxwellianAveragedFissionCrossSection = 571.4 --[b] barns

-- Oxygen :

constants.Oxygen16MaxwellianAveragedCaptureCrossSection = 1.9 * 10^-4 --[b] barns

-- Moderator :

constants.ModeratorLinearExpansionCoefficient = 2.1 * 10e-4 -- [K-1]
constants.ModeratorMolarMass = 0.01801528 --[kg mol^-1]
constants.HydrogenMolarMass = 0.00201568 --[kg mol^-1]

constants.HydrogenMaxwellianAveragedCaptureCrossSection = 3.322 * 10^-1 --[b] barns

constants.WaterLogarithmicEnergyDecrement = 0.920

-- Control Rods :

constants.ControlRodsLinearExpansionCoefficient = 6.5 * 10e-6 -- [K-1]
constants.ControlRodsMolarMass = 0.05525 --[kg mol^-1]

constants.BoronCarbideMaxwellianAveragedCaptureCrossSection  = 3840 --[b] barns
constants.BoronCarbideMaxwellianAveragedScatteringCrossSection  = 2.542 --[b] barns

return constants 