# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/iikhsan/CLionProjects/Task9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/iikhsan/CLionProjects/Task9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task9.dir/flags.make

CMakeFiles/Task9.dir/main.cpp.o: CMakeFiles/Task9.dir/flags.make
CMakeFiles/Task9.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/iikhsan/CLionProjects/Task9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task9.dir/main.cpp.o"
	/usr/local/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task9.dir/main.cpp.o -c /Users/iikhsan/CLionProjects/Task9/main.cpp

CMakeFiles/Task9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task9.dir/main.cpp.i"
	/usr/local/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iikhsan/CLionProjects/Task9/main.cpp > CMakeFiles/Task9.dir/main.cpp.i

CMakeFiles/Task9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task9.dir/main.cpp.s"
	/usr/local/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iikhsan/CLionProjects/Task9/main.cpp -o CMakeFiles/Task9.dir/main.cpp.s

CMakeFiles/Task9.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Task9.dir/main.cpp.o.requires

CMakeFiles/Task9.dir/main.cpp.o.provides: CMakeFiles/Task9.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Task9.dir/build.make CMakeFiles/Task9.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Task9.dir/main.cpp.o.provides

CMakeFiles/Task9.dir/main.cpp.o.provides.build: CMakeFiles/Task9.dir/main.cpp.o


# Object files for target Task9
Task9_OBJECTS = \
"CMakeFiles/Task9.dir/main.cpp.o"

# External object files for target Task9
Task9_EXTERNAL_OBJECTS =

Task9: CMakeFiles/Task9.dir/main.cpp.o
Task9: CMakeFiles/Task9.dir/build.make
Task9: CMakeFiles/Task9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/iikhsan/CLionProjects/Task9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task9.dir/build: Task9

.PHONY : CMakeFiles/Task9.dir/build

CMakeFiles/Task9.dir/requires: CMakeFiles/Task9.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Task9.dir/requires

CMakeFiles/Task9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task9.dir/clean

CMakeFiles/Task9.dir/depend:
	cd /Users/iikhsan/CLionProjects/Task9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/iikhsan/CLionProjects/Task9 /Users/iikhsan/CLionProjects/Task9 /Users/iikhsan/CLionProjects/Task9/cmake-build-debug /Users/iikhsan/CLionProjects/Task9/cmake-build-debug /Users/iikhsan/CLionProjects/Task9/cmake-build-debug/CMakeFiles/Task9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task9.dir/depend

