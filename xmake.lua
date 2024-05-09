set_allowedmodes("release", "debug")

target("Reactor")
    set_kind("binary")
    set_languages("cxx23")
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
target_end()