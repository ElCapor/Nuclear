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

// TODO : make a constants browser/editor

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
            if (ImGui::BeginTabBar("Tabs"))
            {
                if (ImGui::BeginTabItem("Constants"))
                {
                    if (ImGui::Button("Load Constants"))
                        LoadConstants();
                    ImGui::SameLine();
                    ImGui::Checkbox("Force ?", &m_forceLoad);
                    if (ImGui::Button("Print constants"))
                        PrintConstants();
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::End();
        }
    }

    // TODO : Replace this paste with an actual function
    void LoadConstants()
    {
        // replace with all ur constant logic
        ParseConfig("constants");
    }

    void PrintConstants()
    {
        for (auto& val : engine->GetConstMgr().Map())
        {
            std::cout << val.first << " " << val.second << std::endl;
        }
    }

    bool ParseConfig(std::string configName)
    {
        luaconf::Value config;
        bool ret = luaconf::Parse(rsrc->ReadEngineConfig(configName), config);
        if (ret)
        {
            for (auto& val : config.Get<luaconf::object_t>())
            {
                // TODO: ADD A SYSTEM TO PARSE NESTED TABLES AND MAKE THEM USE A NAMESPACE CONVENTION IF WANTED
                engine->GetConstMgr().AddConstant(val.second, val.first, m_forceLoad);
            }
        }
        if (!ret)
            Console::get()->error("[NON FATAL] Failed to parse config %s...\n", configName.c_str());
        return ret;
    }
private:
    nuclear::Engine* engine;
    ResourceManager* rsrc;
    bool m_forceLoad = false; // force the loading of constants (hot reload for example)
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Console::get()->open();
    App* app = App::get();
    app->GetGuiManager().AddWidget(NuclearMainWidget::get());
    app->Run();
    return 0;
}