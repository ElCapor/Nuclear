set_allowedmodes("release", "debug")


add_requires("luajit")
target("Reactor")
    set_kind("binary")
    set_languages("cxx23")
    set_symbols("debug")
    -- Source files
    add_files("src/**.cpp")
    add_files("src/**.c")
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
    add_files("src/**.cpp")
    add_files("src/**.c")
    remove_files("src/main.cpp")
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

target_end()