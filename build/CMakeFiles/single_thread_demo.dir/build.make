# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ved/cxx_experiments/Threads_in_CXX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ved/cxx_experiments/Threads_in_CXX/build

# Include any dependencies generated for this target.
include CMakeFiles/single_thread_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/single_thread_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/single_thread_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_thread_demo.dir/flags.make

CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o: CMakeFiles/single_thread_demo.dir/flags.make
CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o: ../src/single_thread_demo.cpp
CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o: CMakeFiles/single_thread_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ved/cxx_experiments/Threads_in_CXX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o -MF CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o.d -o CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o -c /home/ved/cxx_experiments/Threads_in_CXX/src/single_thread_demo.cpp

CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ved/cxx_experiments/Threads_in_CXX/src/single_thread_demo.cpp > CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.i

CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ved/cxx_experiments/Threads_in_CXX/src/single_thread_demo.cpp -o CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.s

# Object files for target single_thread_demo
single_thread_demo_OBJECTS = \
"CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o"

# External object files for target single_thread_demo
single_thread_demo_EXTERNAL_OBJECTS =

single_thread_demo: CMakeFiles/single_thread_demo.dir/src/single_thread_demo.cpp.o
single_thread_demo: CMakeFiles/single_thread_demo.dir/build.make
single_thread_demo: CMakeFiles/single_thread_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ved/cxx_experiments/Threads_in_CXX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable single_thread_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/single_thread_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_thread_demo.dir/build: single_thread_demo
.PHONY : CMakeFiles/single_thread_demo.dir/build

CMakeFiles/single_thread_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/single_thread_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/single_thread_demo.dir/clean

CMakeFiles/single_thread_demo.dir/depend:
	cd /home/ved/cxx_experiments/Threads_in_CXX/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ved/cxx_experiments/Threads_in_CXX /home/ved/cxx_experiments/Threads_in_CXX /home/ved/cxx_experiments/Threads_in_CXX/build /home/ved/cxx_experiments/Threads_in_CXX/build /home/ved/cxx_experiments/Threads_in_CXX/build/CMakeFiles/single_thread_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_thread_demo.dir/depend

