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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Документы/cpp_year2016-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Документы/cpp_year2016-master

# Include any dependencies generated for this target.
include hw5/CMakeFiles/flatten_tuple.dir/depend.make

# Include the progress variables for this target.
include hw5/CMakeFiles/flatten_tuple.dir/progress.make

# Include the compile flags for this target's objects.
include hw5/CMakeFiles/flatten_tuple.dir/flags.make

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o: hw5/CMakeFiles/flatten_tuple.dir/flags.make
hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o: hw5/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Документы/cpp_year2016-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flatten_tuple.dir/source/main.cpp.o -c /root/Документы/cpp_year2016-master/hw5/source/main.cpp

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatten_tuple.dir/source/main.cpp.i"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Документы/cpp_year2016-master/hw5/source/main.cpp > CMakeFiles/flatten_tuple.dir/source/main.cpp.i

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatten_tuple.dir/source/main.cpp.s"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Документы/cpp_year2016-master/hw5/source/main.cpp -o CMakeFiles/flatten_tuple.dir/source/main.cpp.s

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.requires:

.PHONY : hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.requires

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.provides: hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.requires
	$(MAKE) -f hw5/CMakeFiles/flatten_tuple.dir/build.make hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.provides.build
.PHONY : hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.provides

hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.provides.build: hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o


hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o: hw5/CMakeFiles/flatten_tuple.dir/flags.make
hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o: hw5/tests/flatten_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Документы/cpp_year2016-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o -c /root/Документы/cpp_year2016-master/hw5/tests/flatten_test.cpp

hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.i"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Документы/cpp_year2016-master/hw5/tests/flatten_test.cpp > CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.i

hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.s"
	cd /root/Документы/cpp_year2016-master/hw5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Документы/cpp_year2016-master/hw5/tests/flatten_test.cpp -o CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.s

hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.requires:

.PHONY : hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.requires

hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.provides: hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.requires
	$(MAKE) -f hw5/CMakeFiles/flatten_tuple.dir/build.make hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.provides.build
.PHONY : hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.provides

hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.provides.build: hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o


# Object files for target flatten_tuple
flatten_tuple_OBJECTS = \
"CMakeFiles/flatten_tuple.dir/source/main.cpp.o" \
"CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o"

# External object files for target flatten_tuple
flatten_tuple_EXTERNAL_OBJECTS =

hw5/flatten_tuple: hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o
hw5/flatten_tuple: hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o
hw5/flatten_tuple: hw5/CMakeFiles/flatten_tuple.dir/build.make
hw5/flatten_tuple: 3dparty/googletest-1.8.0/libgoogletest.a
hw5/flatten_tuple: hw5/CMakeFiles/flatten_tuple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Документы/cpp_year2016-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable flatten_tuple"
	cd /root/Документы/cpp_year2016-master/hw5 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flatten_tuple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hw5/CMakeFiles/flatten_tuple.dir/build: hw5/flatten_tuple

.PHONY : hw5/CMakeFiles/flatten_tuple.dir/build

hw5/CMakeFiles/flatten_tuple.dir/requires: hw5/CMakeFiles/flatten_tuple.dir/source/main.cpp.o.requires
hw5/CMakeFiles/flatten_tuple.dir/requires: hw5/CMakeFiles/flatten_tuple.dir/tests/flatten_test.cpp.o.requires

.PHONY : hw5/CMakeFiles/flatten_tuple.dir/requires

hw5/CMakeFiles/flatten_tuple.dir/clean:
	cd /root/Документы/cpp_year2016-master/hw5 && $(CMAKE_COMMAND) -P CMakeFiles/flatten_tuple.dir/cmake_clean.cmake
.PHONY : hw5/CMakeFiles/flatten_tuple.dir/clean

hw5/CMakeFiles/flatten_tuple.dir/depend:
	cd /root/Документы/cpp_year2016-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Документы/cpp_year2016-master /root/Документы/cpp_year2016-master/hw5 /root/Документы/cpp_year2016-master /root/Документы/cpp_year2016-master/hw5 /root/Документы/cpp_year2016-master/hw5/CMakeFiles/flatten_tuple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hw5/CMakeFiles/flatten_tuple.dir/depend

