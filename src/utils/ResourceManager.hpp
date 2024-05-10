#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <filesystem>
namespace fs = std::filesystem;
class ResourceManager
{
public:
    fs::path& ResourcesPath() {return m_ResourcesPath;}
    fs::path& ConfigPath() {return m_ResourcesPath.append("\\config");}
    fs::path& EngineConfigPath() {return ConfigPath().append("\\engine");}
    fs::path& DataPath() {return m_ResourcesPath.append("\\data");}
private:
    fs::path m_ResourcesPath;
};

#endif /* RESOURCEMANAGER_HPP */
