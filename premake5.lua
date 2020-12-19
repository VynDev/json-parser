workspace "json-parser"
	configurations {"Debug", "Release"}

	project "json-parser"
		kind "StaticLib"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}

		files {"source/**.cpp"}
		removefiles {"source/**.test.cpp"}
		

	project "basics"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"examples/basics.cpp"}

	project "tests"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"json-parser"}

		files {"tests/*.cpp"}

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

newaction {
	trigger = "tests",
	description = "run tests",
	execute = function ()
		os.execute("./bin/tests")
	end
}

newaction {
	trigger = "examples",
	description = "run the examples, for dev testing purpose",
	execute = function ()
		os.execute("./bin/basics")
	end
}