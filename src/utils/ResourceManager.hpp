#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <filesystem>
#include "FilesystemUtils.hpp"
namespace fs = std::filesystem;
class ResourceManager
{
public:
    ResourceManager() : m_ResourcesPath(fsutils::executableDirectory().concat("\\resources")) {}
    fs::path& ResourcesPath() {return m_ResourcesPath;}
    fs::path& ConfigPath() {return m_ResourcesPath.concat("\\config");}
    fs::path& EngineConfigPath() {return ConfigPath().concat("\\engine");}
    fs::path& DataPath() {return m_ResourcesPath.concat("\\data");}

    std::string ReadEngineConfig(std::string m_name) {return fsutils::loadFile(EngineConfigPath().concat("\\" + m_name).string());};
private:
    fs::path m_ResourcesPath;
};

#endif /* RESOURCEMANAGER_HPP */
