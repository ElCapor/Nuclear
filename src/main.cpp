#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
#include <filesystem>
#include "utils/ResourceManager.hpp"

namespace fs = std::filesystem;

int main()
{
    nuclear::Engine* engine = new nuclear::Engine();
    ResourceManager* rsrc = new ResourceManager();
    std::cout << rsrc->ResourcesPath() << std::endl;
    luaconf::Value reactorConfig;
    bool ret = luaconf::Parse(rsrc->ReadEngineConfig("reactorParameters.lua"), reactorConfig);
    if (ret)
        std::cout << reactorConfig << std::endl;
    delete engine;
    delete rsrc;
    return 0;
}