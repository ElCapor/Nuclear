#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
#include <filesystem>
namespace fs = std::filesystem;

fs::path GetCurrentExecutablePath()
{
    return fs::current_path();
}

int main()
{
    nuclear::Engine* engine = new nuclear::Engine();
    luaconf::Value reactorConfig;
    //bool ret = luaconf::ParseFile(.string(),reactorConfig);
    auto exec = GetCurrentExecutablePath();
    auto data = exec.append("\\resources\\data");
    delete engine;
    return 0;
}