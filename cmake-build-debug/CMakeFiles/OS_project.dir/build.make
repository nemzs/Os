# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/stanislav/Os/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/stanislav/Os/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stanislav/CLionProjects/test_epoll

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stanislav/CLionProjects/test_epoll/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OS_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OS_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OS_project.dir/flags.make

CMakeFiles/OS_project.dir/main.cpp.o: CMakeFiles/OS_project.dir/flags.make
CMakeFiles/OS_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stanislav/CLionProjects/test_epoll/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OS_project.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OS_project.dir/main.cpp.o -c /home/stanislav/CLionProjects/test_epoll/main.cpp

CMakeFiles/OS_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS_project.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stanislav/CLionProjects/test_epoll/main.cpp > CMakeFiles/OS_project.dir/main.cpp.i

CMakeFiles/OS_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS_project.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stanislav/CLionProjects/test_epoll/main.cpp -o CMakeFiles/OS_project.dir/main.cpp.s

CMakeFiles/OS_project.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OS_project.dir/main.cpp.o.requires

CMakeFiles/OS_project.dir/main.cpp.o.provides: CMakeFiles/OS_project.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OS_project.dir/build.make CMakeFiles/OS_project.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OS_project.dir/main.cpp.o.provides

CMakeFiles/OS_project.dir/main.cpp.o.provides.build: CMakeFiles/OS_project.dir/main.cpp.o


# Object files for target OS_project
OS_project_OBJECTS = \
"CMakeFiles/OS_project.dir/main.cpp.o"

# External object files for target OS_project
OS_project_EXTERNAL_OBJECTS =

OS_project: CMakeFiles/OS_project.dir/main.cpp.o
OS_project: CMakeFiles/OS_project.dir/build.make
OS_project: CMakeFiles/OS_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stanislav/CLionProjects/test_epoll/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OS_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OS_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OS_project.dir/build: OS_project

.PHONY : CMakeFiles/OS_project.dir/build

CMakeFiles/OS_project.dir/requires: CMakeFiles/OS_project.dir/main.cpp.o.requires

.PHONY : CMakeFiles/OS_project.dir/requires

CMakeFiles/OS_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OS_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OS_project.dir/clean

CMakeFiles/OS_project.dir/depend:
	cd /home/stanislav/CLionProjects/test_epoll/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stanislav/CLionProjects/test_epoll /home/stanislav/CLionProjects/test_epoll /home/stanislav/CLionProjects/test_epoll/cmake-build-debug /home/stanislav/CLionProjects/test_epoll/cmake-build-debug /home/stanislav/CLionProjects/test_epoll/cmake-build-debug/CMakeFiles/OS_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OS_project.dir/depend
