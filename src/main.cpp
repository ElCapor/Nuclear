#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>

int main()
{
    nuclear::Engine* engine = new nuclear::Engine();
    delete engine;
    return 0;
}