#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
int main()
{
    nuclear::Engine* engine = new nuclear::Engine();
    luaconf::Value reactorConfig;
    bool ret = luaconf::ParseFile("resources/data/reactorParameters.lua",reactorConfig);
    if (ret)
    {
        std::cout << reactorConfig << std::endl;
    }
    delete engine;
    return 0;
}