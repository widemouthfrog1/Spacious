workspace "Spacious"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	project "Spacious"
		location "Spacious"
		kind "SharedLib"
		language "C++"
		
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		
		includedirs
		{
			"%{prj.name}/vendor/spdlog/include"
		}
		
		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
			
			defines
			{
				"SP_PLATFORM_WINDOWS",
				"SP_BUILD_DLL"
			}
			
			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}
		
		filter "configurations:Debug"
			defines "SP_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "SP_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "SP_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		
		includedirs
		{
			"Spacious/vendor/spdlog/include",
			"Spacious/src"
		}
		
		links
		{
			"Spacious"
		}
		
		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
			
			defines
			{
				"SP_PLATFORM_WINDOWS"
			}
		
		filter "configurations:Debug"
			defines "SP_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "SP_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "SP_DIST"
			optimize "On"