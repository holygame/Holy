workspace "Holy" --solution name
	architecture "x64"

	configurations
	{
		"Debug", --contains everything
		"Release", --tradeoff between speed and infos debugging
		"Dist" -- distrubution build, everything striped
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"  -- DEBUG/WIN/x64

project "Holy" -- stuff that's in project property ( preprocessor etc...)
	location "Holy"
	kind "SharedLib" -- DLL in premake
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"Holy/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" --static linking obviously
		systemversion "latest"

		defines
		{
			"HL_PLATFORM_WINDOWS",
			"HL_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		

	filter "configurations:Release"
		defines "HL_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "HL_DEBUG"
		symbols "On"
			
	filter "configurations:Dist"
		defines "HL_DIST"
		optimize "On"




project "Sandbox" -- stuff that's in project property ( preprocessor etc...)

	location "Sandbox"
	kind "ConsoleApp" -- exe in premake
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Holy/vendor/spdlog/include",
		"Holy/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" --static linking obviously
		systemversion "latest"

		defines
		{
			"HL_PLATFORM_WINDOWS"
		}
		links
		{
			"Holy"
		}

	filter "configurations:Release"
		defines "HL_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "HL_DEBUG"
		symbols "On"
			
	filter "configurations:Dist"
		defines "HL_DIST"
		optimize "On"
