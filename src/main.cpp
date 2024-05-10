#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
#include <filesystem>
#include "utils/ResourceManager.hpp"

namespace fs = std::filesystem;

fs::path GetCurrentExecutablePath() {
    return fs::current_path();
}

int main()
{
    nuclear::Engine* engine = new nuclear::Engine();
    ResourceManager* rsrc = new ResourceManager();
    std::cout << GetCurrentExecutablePath() << std::endl;
    rsrc->ResourcesPath() = GetCurrentExecutablePath().concat("\\resources");
    std::cout << rsrc->ResourcesPath() << std::endl;
    std::cout << rsrc->ReadEngineConfig("reactorParameters.lua") << std::endl;
    luaconf::Value reactorConfig;
    //bool ret = luaconf::ParseFile(.string(),reactorConfig);
    auto exec = GetCurrentExecutablePath();
    auto data = exec.append("\\resources\\data");
    delete engine;
    delete rsrc;
    return 0;
}