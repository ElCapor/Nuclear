add_rules("mode.debug", "mode.release")


add_requires("luajit")
add_requires("libsdl")
target("Reactor")
    set_kind("binary")
    set_languages("cxx23")
    set_symbols("debug")
    add_ldflags("cl::-subsystem:windows")
    -- Source files
    add_files("src/**.cpp")
    add_files("src/**.c")
    add_files("extern/vendor/luaconfig/luaconf.cpp")
    add_includedirs("extern/vendor")
    add_files("extern/vendor/imgui/imgui_demo.cpp","extern/vendor/imgui/imgui_draw.cpp", "extern/vendor/imgui/imgui_tables.cpp", "extern/vendor/imgui/imgui_widgets.cpp", "extern/vendor/imgui/imgui.cpp")
    add_includedirs("extern/vendor/imgui")
    add_files("extern/vendor/imgui/backends/imgui_impl_sdl2.cpp", "extern/vendor/imgui/backends/imgui_impl_sdlrenderer2.cpp")
    add_headerfiles("extern/vendor/imgui/backends/imgui_impl_sdl2.h", "extern/vendor/imgui/backends/imgui_impl_sdl2.")
    add_files("extern/vendor/imgui/backends/imgui_impl_win32.cpp", "extern/vendor/imgui/backends/imgui_impl_dx11.cpp")
    add_headerfiles("extern/vendor/imgui/backends/imgui_impl_win32.h")
    remove_files("src/test.cpp")
    -- Header files
    add_headerfiles("src/**.hpp")
    add_headerfiles("src/**.h")

    -- Include Directories
    add_includedirs("extern/vendor")
    add_includedirs("src")

    -- Source modules
    add_files("extern/vendor/nuclear/**.cpp")

    -- Packages
    add_packages("luajit")
    add_packages("libsdl")
    
    -- Resources
    after_build(function (target)
        local binary_dir = path.directory(target:targetfile())
        os.cp("resources", binary_dir)
    end)
target_end()

target("Test")
    set_kind("binary")
    set_languages("cxx23")
    -- Source files
    add_files("test.cpp")

    -- Include Directories
    add_includedirs("extern/vendor")
    add_includedirs("src")

    -- Source modules
    add_files("extern/vendor/nuclear/**.cpp")

    -- Packages
    add_packages("luajit")

target_end()