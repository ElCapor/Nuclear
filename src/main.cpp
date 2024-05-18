#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <nuclear/NuclearEngine.hpp>
#include <luaconfig/luaconf.h>
#include <filesystem>
#include "utils/ResourceManager.hpp"
#include <Windows.h>
#include "app.hpp"
#include "utils/console/console.hpp"
#include <nuclear/Atomic.hpp>
namespace fs = std::filesystem;

// TODO : make a constants browser/editor

class NuclearMainWidget : public Widget, public Singleton<NuclearMainWidget>
{
public:
    NuclearMainWidget()
    {
        engine = new nuclear::Engine();
        rsrc = new ResourceManager();
        nucleusMgr = new nuclear::atomic::NucleusManager();
    }

    void Init() override
    {
        setName("NuclearWidget");
    }

    void Render(double dt) override
    {
        ImGui::ShowDemoWindow();
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
                    if (ImGui::Button("Load Nucleuses"))
                        ParseNucleuses();
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            RenderConstantsTable();
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

    void RenderConstantsTable()
    {
        if (ImGui::BeginTable("ConstantsTable", 2))
        {
            ImGui::TableSetupColumn("Name");
            ImGui::TableSetupColumn("Value");
            ImGui::TableHeadersRow();
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            bool open = ImGui::TreeNodeEx("Constants");
            ImGui::TableNextColumn();
            ImGui::TextDisabled("%d",engine->GetConstMgr().Map().size());
            if (open)
            {
                for (auto& val : engine->GetConstMgr().Map())
                {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text(val.first.c_str());
                    ImGui::TableNextColumn();
                    std::stringstream ss;
                    ss << val.second;
                    ImGui::Text(ss.str().c_str());
                }
                ImGui::TreePop();
            }
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            bool nucopen = ImGui::TreeNodeEx("Nucleuses");
            ImGui::TableNextColumn();
            ImGui::TextDisabled("%d", nucleusMgr->m_Nucs.size());
            if (nucopen)
            {
                for (auto& nuc : nucleusMgr->m_Nucs)
                {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Symbol");
                    ImGui::TableNextColumn();
                    ImGui::Text(nuc->symbol.c_str());
                }
                ImGui::TreePop();
            }
            ImGui::EndTable();
        }
    }

    bool ParseConfig(std::string configName)
    {
        luaconf::Value config;
        bool ret = luaconf::Parse(rsrc->ReadEngineConfig(configName), config);
        if (ret && config.Type() == luaconf::ValueType::TYPE_OBJECT)
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

    bool ParseNucleuses()
    {
        luaconf::Value config;
        bool ret = luaconf::Parse(rsrc->ReadEngineConfig("nucleus"), config);
        if (ret && (config.Type() == luaconf::ValueType::TYPE_ARRAY))
        {
            for (auto& val : config.Get<luaconf::array_t>())
            {
                if (val.Type() == luaconf::ValueType::TYPE_OBJECT)
                {
                    nuclear::atomic::Nucleus nuc;
                    nuc.symbol = val["symbol"].Get<luaconf::string_t>();
                    nuc.protons = val["protons"].Get<luaconf::int_t>();
                    nuc.neutrons = val["neutrons"].Get<luaconf::int_t>();
                    nucleusMgr->AddNucleus(nuc);
                }
            }
        }
        if (!ret)
            Console::get()->error("[NON FATAL] Failed to parse config %s...\n", "nucleus");
            
        return ret;
    }
private:
    nuclear::Engine* engine;
    ResourceManager* rsrc;
    nuclear::atomic::NucleusManager* nucleusMgr;
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