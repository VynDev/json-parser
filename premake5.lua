solution "json-parser"
	configurations {"Static", "Shared"}

	project "json-parser"
		language "C++"
		cppdialect "C++17"
		includedirs {"include"}
		files {"source/**.cpp"}
		removefiles {"source/**.test.cpp"}
		targetdir "bin"

		configuration "Static"
			kind "StaticLib"

		configuration "Shared"
			kind "SharedLib"

	project "basics"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	includedirs {"include"}
	files {"examples/basics.cpp",}
	links {"json-parser"}
	targetdir "bin"

newaction {
	trigger = "clean",
	description = "clean the software",
	execute = function ()
		print("cleaning the build...")
		os.rmdir("./bin")
		os.rmdir("./obj")
		os.remove("./Makefile")
		os.remove("./*.make")
		print("done.")
	end
}