dependencies = { base = path.getrelative(os.getcwd(), path.getabsolute("deps")) }

function dependencies.load()
    dir = path.join(dependencies.base, "*.lua")
    deps = os.matchfiles(dir)

    for i, dep in pairs(deps) do
        dep = dep:gsub(".lua", "")
        require(dep)
    end
end

dependencies.load()
-------------------------------------------------
workspace "gsc-tool"
    location "./build"
    objdir "%{wks.location}/obj/%{cfg.buildcfg}/%{prj.name}"
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}"
    targetname "%{prj.name}"
    staticruntime "On"
    language "C++"
    cppdialect "C++20"
    architecture "x86_64"

    filter "action:vs*"
        buildoptions "/bigobj"
        buildoptions "/Zc:__cplusplus"
        disablewarnings "4244"
    filter {}

    configurations { "Debug", "Release" }

    symbols "On"
    warnings "Extra"

    filter "configurations:Release"
        optimize "Full"
        defines { "NDEBUG" }
        flags { "FatalCompileWarnings" }
    filter {}

    filter "configurations:Debug"
        optimize "Debug"
        defines { "DEBUG", "_DEBUG" }
    filter {}

    startproject "xsk-tool"

project "xsk-tool"
    kind "ConsoleApp"
    language "C++"
    targetname "gsc-tool"

    dependson "xsk-utils"
    dependson "xsk-arc"
    dependson "xsk-gsc"
    dependson "xsk-iw5_pc"
    dependson "xsk-iw5_ps"
    dependson "xsk-iw5_xb"
    dependson "xsk-iw6_pc"
    dependson "xsk-iw6_ps"
    dependson "xsk-iw6_xb"
    dependson "xsk-s1_pc"
    dependson "xsk-s1_ps"
    dependson "xsk-s1_xb"
    dependson "xsk-iw7"
    dependson "xsk-iw8"
    dependson "xsk-iw9"
    dependson "xsk-h1"
    dependson "xsk-h2"
    dependson "xsk-s2"
    dependson "xsk-s4"
    -- dependson "xsk-t6"

    pchheader "stdafx.hpp"
    pchsource "src/tool/stdafx.cpp"

    files {
        "./src/tool/**.h",
        "./src/tool/**.hpp",
        "./src/tool/**.cpp"
    }

    links {
        "xsk-utils",
        "xsk-arc",
        "xsk-gsc",
        "xsk-iw5_pc",
        "xsk-iw5_ps",
        "xsk-iw5_xb",
        "xsk-iw6_pc",
        "xsk-iw6_ps",
        "xsk-iw6_xb",
        "xsk-s1_pc",
        "xsk-s1_ps",
        "xsk-s1_xb",
        "xsk-iw7",
        "xsk-iw8",
        "xsk-iw9",
        "xsk-h1",
        "xsk-h2",
        "xsk-s2",
        "xsk-s4",
        -- "xsk-arc-t6",
    }

    includedirs {
        "./src/tool",
        "./src"
    }

    fmt:include()
    fmt:link()
    zlib:link()

project "xsk-utils"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/utils/stdafx.cpp"

    files {
        "./src/utils/**.h",
        "./src/utils/**.hpp",
        "./src/utils/**.cpp"
    }

    includedirs {
        "./src/utils",
        "./src"
    }

    fmt:include()
    zlib:include()

project "xsk-arc"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/arc/stdafx.cpp"

    files {
        "./src/arc/**.h",
        "./src/arc/**.hpp",
        "./src/arc/**.cpp"
    }

    includedirs {
        "./src/arc",
        "./src"
    }

    fmt:include()

project "xsk-gsc"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/gsc/stdafx.cpp"

    files {
        "./src/gsc/**.h",
        "./src/gsc/**.hpp",
        "./src/gsc/**.cpp"
    }

    includedirs {
        "./src/gsc",
        "./src"
    }

    fmt:include()

project "xsk-iw5_pc"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw5/stdafx.cpp"

    files {
        "./src/iw5/stdafx.hpp",
        "./src/iw5/stdafx.cpp",
        "./src/iw5/xsk/iw5_pc.hpp",
        "./src/iw5/xsk/iw5_pc.cpp",
        "./src/iw5/xsk/iw5_pc_code.cpp",
        "./src/iw5/xsk/iw5_pc_func.cpp",
        "./src/iw5/xsk/iw5_pc_meth.cpp",
        "./src/iw5/xsk/iw5_pc_token.cpp"
    }

    includedirs {
        "./src/iw5",
        "./src"
    }

project "xsk-iw5_ps"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw5/stdafx.cpp"

    files {
        "./src/iw5/stdafx.hpp",
        "./src/iw5/stdafx.cpp",
        "./src/iw5/xsk/iw5_ps.hpp",
        "./src/iw5/xsk/iw5_ps.cpp",
        "./src/iw5/xsk/iw5_ps_code.cpp",
        "./src/iw5/xsk/iw5_ps_func.cpp",
        "./src/iw5/xsk/iw5_ps_meth.cpp",
        "./src/iw5/xsk/iw5_ps_token.cpp"
    }

    includedirs {
        "./src/iw5",
        "./src"
    }

project "xsk-iw5_xb"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw5/stdafx.cpp"

    files {
        "./src/iw5/stdafx.hpp",
        "./src/iw5/stdafx.cpp",
        "./src/iw5/xsk/iw5_xb.hpp",
        "./src/iw5/xsk/iw5_xb.cpp",
        "./src/iw5/xsk/iw5_xb_code.cpp",
        "./src/iw5/xsk/iw5_xb_func.cpp",
        "./src/iw5/xsk/iw5_xb_meth.cpp",
        "./src/iw5/xsk/iw5_xb_token.cpp"
    }

    includedirs {
        "./src/iw5",
        "./src"
    }

project "xsk-iw6_pc"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw6/stdafx.cpp"

    files {
        "./src/iw6/stdafx.hpp",
        "./src/iw6/stdafx.cpp",
        "./src/iw6/xsk/iw6_pc.hpp",
        "./src/iw6/xsk/iw6_pc.cpp",
        "./src/iw6/xsk/iw6_pc_code.cpp",
        "./src/iw6/xsk/iw6_pc_func.cpp",
        "./src/iw6/xsk/iw6_pc_meth.cpp",
        "./src/iw6/xsk/iw6_pc_token.cpp"
    }

    includedirs {
        "./src/iw6",
        "./src"
    }

project "xsk-iw6_ps"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw6/stdafx.cpp"

    files {
        "./src/iw6/stdafx.hpp",
        "./src/iw6/stdafx.cpp",
        "./src/iw6/xsk/iw6_ps.hpp",
        "./src/iw6/xsk/iw6_ps.cpp",
        "./src/iw6/xsk/iw6_ps_code.cpp",
        "./src/iw6/xsk/iw6_ps_func.cpp",
        "./src/iw6/xsk/iw6_ps_meth.cpp",
        "./src/iw6/xsk/iw6_ps_token.cpp"
    }

    includedirs {
        "./src/iw6",
        "./src"
    }

project "xsk-iw6_xb"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw6/stdafx.cpp"

    files {
        "./src/iw6/stdafx.hpp",
        "./src/iw6/stdafx.cpp",
        "./src/iw6/xsk/iw6_xb.hpp",
        "./src/iw6/xsk/iw6_xb.cpp",
        "./src/iw6/xsk/iw6_xb_code.cpp",
        "./src/iw6/xsk/iw6_xb_func.cpp",
        "./src/iw6/xsk/iw6_xb_meth.cpp",
        "./src/iw6/xsk/iw6_xb_token.cpp"
    }

    includedirs {
        "./src/iw6",
        "./src"
    }


project "xsk-s1_pc"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/s1/stdafx.cpp"

    files {
        "./src/s1/stdafx.hpp",
        "./src/s1/stdafx.cpp",
        "./src/s1/xsk/s1_pc.hpp",
        "./src/s1/xsk/s1_pc.cpp",
        "./src/s1/xsk/s1_pc_code.cpp",
        "./src/s1/xsk/s1_pc_func.cpp",
        "./src/s1/xsk/s1_pc_meth.cpp",
        "./src/s1/xsk/s1_pc_token.cpp"
    }

    includedirs {
        "./src/s1",
        "./src"
    }

project "xsk-s1_ps"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/s1/stdafx.cpp"

    files {
        "./src/s1/stdafx.hpp",
        "./src/s1/stdafx.cpp",
        "./src/s1/xsk/s1_ps.hpp",
        "./src/s1/xsk/s1_ps.cpp",
        "./src/s1/xsk/s1_ps_code.cpp",
        "./src/s1/xsk/s1_ps_func.cpp",
        "./src/s1/xsk/s1_ps_meth.cpp",
        "./src/s1/xsk/s1_ps_token.cpp"
    }

    includedirs {
        "./src/s1",
        "./src"
    }

project "xsk-s1_xb"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/s1/stdafx.cpp"

    files {
        "./src/s1/stdafx.hpp",
        "./src/s1/stdafx.cpp",
        "./src/s1/xsk/s1_xb.hpp",
        "./src/s1/xsk/s1_xb.cpp",
        "./src/s1/xsk/s1_xb_code.cpp",
        "./src/s1/xsk/s1_xb_func.cpp",
        "./src/s1/xsk/s1_xb_meth.cpp",
        "./src/s1/xsk/s1_xb_token.cpp"
    }

    includedirs {
        "./src/s1",
        "./src"
    }

project "xsk-iw7"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw7/stdafx.cpp"

    files {
        "./src/iw7/**.h",
        "./src/iw7/**.hpp",
        "./src/iw7/**.cpp"
    }

    includedirs {
        "./src/iw7",
        "./src"
    }

project "xsk-iw8"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw8/stdafx.cpp"

    files {
        "./src/iw8/**.h",
        "./src/iw8/**.hpp",
        "./src/iw8/**.cpp"
    }

    includedirs {
        "./src/iw8",
        "./src"
    }

project "xsk-iw9"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/iw9/stdafx.cpp"

    files {
        "./src/iw9/**.h",
        "./src/iw9/**.hpp",
        "./src/iw9/**.cpp"
    }

    includedirs {
        "./src/iw9",
        "./src"
    }

project "xsk-h1"
kind "StaticLib"
language "C++"

pchheader "stdafx.hpp"
pchsource "src/h1/stdafx.cpp"

files {
    "./src/h1/**.h",
    "./src/h1/**.hpp",
    "./src/h1/**.cpp"
}

includedirs {
    "./src/h1",
    "./src"
}

project "xsk-h2"
kind "StaticLib"
language "C++"

pchheader "stdafx.hpp"
pchsource "src/h2/stdafx.cpp"

files {
    "./src/h2/**.h",
    "./src/h2/**.hpp",
    "./src/h2/**.cpp"
}

includedirs {
    "./src/h2",
    "./src"
}

project "xsk-s2"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/s2/stdafx.cpp"

    files {
        "./src/s2/**.h",
        "./src/s2/**.hpp",
        "./src/s2/**.cpp"
    }

    includedirs {
        "./src/s2",
        "./src"
    }

project "xsk-s4"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource "src/s4/stdafx.cpp"

    files {
        "./src/s4/**.h",
        "./src/s4/**.hpp",
        "./src/s4/**.cpp"
    }

    includedirs {
        "./src/s4",
        "./src"
    }

-- project "xsk-arc-t6"
--     kind "StaticLib"
--     language "C++"

--     pchheader "stdafx.hpp"
--     pchsource "src/t6/stdafx.cpp"

--     files {
--         "./src/t6/**.h",
--         "./src/t6/**.hpp",
--         "./src/t6/**.cpp"
--     }

--     includedirs {
--         "./src/t6",
--         "./src"
--     }

group "Dependencies"
    fmt:project()
    zlib:project()
