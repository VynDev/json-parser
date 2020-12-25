workspace "json-parser"
	configurations {"Debug", "Release"}

	filter "configurations:Release"
		buildoptions "-O3"

	project "json-parser"
		kind "StaticLib"

		filter "options:kind=static"
			kind "StaticLib"

		filter "options:kind=shared"
			kind "SharedLib"

		filter {}

		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}

		files {"source/**.cpp"}
		removefiles {"source/**.test.cpp"}

		

	project "basics_object"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"examples/basics_object.cpp"}

	project "basics_array"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"examples/basics_array.cpp"}

	project "complex_object"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"examples/complex_object.cpp"}

	project "tests"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"tests/*.cpp"}

newaction {
	trigger = "clean",
	description = "Clean the software",
	execute = function ()
		print("cleaning the build...")
		os.rmdir("./bin")
		os.rmdir("./obj")
		os.remove("./Makefile")
		os.remove("./*.make")
		print("done.")
	end
}

newaction {
	trigger = "tests",
	description = "Run tests",
	execute = function ()
		os.execute("./bin/tests")
	end
}

newaction {
	trigger = "examples",
	description = "Run the examples, for dev testing purpose",
	execute = function ()
		os.execute("./bin/basics_object")
		os.execute("./bin/basics_array")
		os.execute("./bin/complex_object")
	end
}

newoption {
	trigger     = "kind",
	value       = "TYPE",
	description = "Build as static (.a) or shared (.so/.dll) library",
	allowed = {
	   { "static", "Static library (.a)" },
	   { "shared", "Shared library (.so/.dll)" }
	}
 }