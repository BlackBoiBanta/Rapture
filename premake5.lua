









  -- system is the platform, e.g. Mac


  -- since the lua file is in the solution, we need to make all files relative to the Rapture project by using the location keyword
  -- dynamic lib


   -- the .. + space is how to append strings (I think)
   -- this is for the object code



  -- the ** means that it recursively searches through everything








  -- apply certain properties to certain platform         
  -- anything under filter applies to windows

  -- we want to link to the redistribute libraries, and other c++ runtime libraries statically










  -- the copy just copies the current project. the {cfg.build...} refers to the current solution (workspace)



  -- note that this filter does not change the current selection state to windows/debug. This applies to all platforms using debug





















  -- the ** means that it recursively searches through everything











  -- we link to the above dll we made 


  -- apply certain properties to certain platform
  -- anything under filter applies to windows

  -- we want to link to the redistribute libraries, and other c++ runtime libraries statically







  -- note that this filter does not change the current selection state to windows/debug. This applies to all platforms using debug






































































workspace "Rapture"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release", 
        "Dist"
    }


    outputDir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

    project "Rapture"
        location "Rapture"
        kind "SharedLib"
        language "C++"

        targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

        files 
        {
            "%{prj.name}/**.h", 
            "%{prj.name}/**.cpp"
        }

        removefiles
        {
            "%{prj.name}/ThirdParty/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/ThirdParty/spdlog/include",
            "%{prj.name}/src"
        }

        postbuildcommands
        {
            --"{COPY} %{cfg.buildtarget.relpath}/*.dll .. bin/" .. outputDir .. "/SandBox"
            "copy $(TargetDir)Rapture.dll $(SolutionDir)bin\\" .. outputDir .. "\\Sandbox"

        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines 
            {
                "RAPT_BUILD_DLL", 
                "RAPT_PLATFORM_WINDOWS"
            }

            filter "configurations:Debug"
                defines "RAPT_DEBUG"
                symbols "On"

            filter "configurations:Release"
                defines "RAPT_RELEASE"
                optimize "On"

            filter "configurations:Dist"
                defines "RAPT_DIST"
                optimize "On"


        
    project "SandBox"
        location "SandBox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

        files 
        {
            "%{prj.name}/**.h", 
            "%{prj.name}/**.cpp"
        }

        includedirs
        {
            "Rapture/ThirdParty/spdlog/include",
            "Rapture/src"
        }

        links
        {
            "Rapture"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines 
            {
                "RAPT_PLATFORM_WINDOWS"
            }

            filter "configurations:Debug"
                defines "RAPT_DEBUG"
                symbols "On"

            filter "configurations:Release"
                defines "RAPT_RELEASE"
                optimize "On"

            filter "configurations:Dist"
                defines "RAPT_DIST"
                optimize "On"
