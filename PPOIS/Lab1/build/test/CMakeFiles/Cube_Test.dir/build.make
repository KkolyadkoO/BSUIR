# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build

# Include any dependencies generated for this target.
include test/CMakeFiles/Cube_Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/Cube_Test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Cube_Test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Cube_Test.dir/flags.make

test/CMakeFiles/Cube_Test.dir/test.cpp.o: test/CMakeFiles/Cube_Test.dir/flags.make
test/CMakeFiles/Cube_Test.dir/test.cpp.o: /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/test/test.cpp
test/CMakeFiles/Cube_Test.dir/test.cpp.o: test/CMakeFiles/Cube_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Cube_Test.dir/test.cpp.o"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Cube_Test.dir/test.cpp.o -MF CMakeFiles/Cube_Test.dir/test.cpp.o.d -o CMakeFiles/Cube_Test.dir/test.cpp.o -c /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/test/test.cpp

test/CMakeFiles/Cube_Test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Cube_Test.dir/test.cpp.i"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/test/test.cpp > CMakeFiles/Cube_Test.dir/test.cpp.i

test/CMakeFiles/Cube_Test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Cube_Test.dir/test.cpp.s"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/test/test.cpp -o CMakeFiles/Cube_Test.dir/test.cpp.s

test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o: test/CMakeFiles/Cube_Test.dir/flags.make
test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o: /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/src/cube.cpp
test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o: test/CMakeFiles/Cube_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o -MF CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o.d -o CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o -c /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/src/cube.cpp

test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Cube_Test.dir/__/src/cube.cpp.i"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/src/cube.cpp > CMakeFiles/Cube_Test.dir/__/src/cube.cpp.i

test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Cube_Test.dir/__/src/cube.cpp.s"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/src/cube.cpp -o CMakeFiles/Cube_Test.dir/__/src/cube.cpp.s

# Object files for target Cube_Test
Cube_Test_OBJECTS = \
"CMakeFiles/Cube_Test.dir/test.cpp.o" \
"CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o"

# External object files for target Cube_Test
Cube_Test_EXTERNAL_OBJECTS =

test/Cube_Test: test/CMakeFiles/Cube_Test.dir/test.cpp.o
test/Cube_Test: test/CMakeFiles/Cube_Test.dir/__/src/cube.cpp.o
test/Cube_Test: test/CMakeFiles/Cube_Test.dir/build.make
test/Cube_Test: lib/libgtest_main.a
test/Cube_Test: lib/libgtest.a
test/Cube_Test: test/CMakeFiles/Cube_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Cube_Test"
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cube_Test.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && /usr/local/Cellar/cmake/3.27.4/bin/cmake -D TEST_TARGET=Cube_Test -D TEST_EXECUTABLE=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test/Cube_Test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=Cube_Test_TESTS -D CTEST_FILE=/Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test/Cube_Test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/local/Cellar/cmake/3.27.4/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/Cube_Test.dir/build: test/Cube_Test
.PHONY : test/CMakeFiles/Cube_Test.dir/build

test/CMakeFiles/Cube_Test.dir/clean:
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test && $(CMAKE_COMMAND) -P CMakeFiles/Cube_Test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Cube_Test.dir/clean

test/CMakeFiles/Cube_Test.dir/depend:
	cd /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1 /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/test /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test /Users/user/Desktop/УНИК/BSUIR/PPOIS/Lab1/build/test/CMakeFiles/Cube_Test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/Cube_Test.dir/depend

