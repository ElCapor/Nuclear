#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
#include <filesystem>
#include "utils/ResourceManager.hpp"
#include <Windows.h>
#include "app.hpp"
#include "utils/console/console.hpp"
namespace fs = std::filesystem;

class NuclearMainWidget : public Widget, public Singleton<NuclearMainWidget>
{
public:
    NuclearMainWidget()
    {
        engine = new nuclear::Engine();
        rsrc = new ResourceManager();
    }

    void Init() override
    {
        setName("NuclearWidget");
    }

    void Render(double dt) override
    {
        if (ImGui::Begin("Nuclear Simulator"))
        {
            if (ImGui::Button("Load Constants"))
                LoadConstants();
            if (ImGui::Button("Print constants"))
                PrintConstants();
            ImGui::End();
        }
    }

    void LoadConstants()
    {
        // replace with all ur constant logic
        luaconf::Value config;
        bool ret = luaconf::Parse(rsrc->ReadEngineConfig("reactorParameters"), config);
        if (ret)
        {
            for (auto& val : config.Get<luaconf::object_t>())
            {
                // TODO: ADD A SYSTEM TO PARSE NESTED TABLES AND MAKE THEM USE A NAMESPACE CONVENTION IF WANTED
                engine->GetConstMgr().AddConstant(val.second, val.first);
            }
            return;
        }
        Console::get()->error("Failed to load config...");
    }

    void PrintConstants()
    {
        for (auto& val : engine->GetConstMgr().Map())
        {
            std::cout << val.first << " " << val.second << std::endl;
        }
    }
private:
    nuclear::Engine* engine;
    ResourceManager* rsrc;
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Console::get()->open();
    App* app = App::get();
    app->GetGuiManager().AddWidget(NuclearMainWidget::get());
    app->Run();
    return 0;
}