# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion-2020.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fakhoury/Documents/icpc-notebook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fakhoury/Documents/icpc-notebook/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/icpc_notebook.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/icpc_notebook.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icpc_notebook.dir/flags.make

CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o: CMakeFiles/icpc_notebook.dir/flags.make
CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o: ../DataStructures/DSUPartial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fakhoury/Documents/icpc-notebook/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o -c /home/fakhoury/Documents/icpc-notebook/DataStructures/DSUPartial.cpp

CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fakhoury/Documents/icpc-notebook/DataStructures/DSUPartial.cpp > CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.i

CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fakhoury/Documents/icpc-notebook/DataStructures/DSUPartial.cpp -o CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.s

# Object files for target icpc_notebook
icpc_notebook_OBJECTS = \
"CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o"

# External object files for target icpc_notebook
icpc_notebook_EXTERNAL_OBJECTS =

icpc_notebook: CMakeFiles/icpc_notebook.dir/DataStructures/DSUPartial.cpp.o
icpc_notebook: CMakeFiles/icpc_notebook.dir/build.make
icpc_notebook: CMakeFiles/icpc_notebook.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fakhoury/Documents/icpc-notebook/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable icpc_notebook"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icpc_notebook.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/icpc_notebook.dir/build: icpc_notebook

.PHONY : CMakeFiles/icpc_notebook.dir/build

CMakeFiles/icpc_notebook.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icpc_notebook.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icpc_notebook.dir/clean

CMakeFiles/icpc_notebook.dir/depend:
	cd /home/fakhoury/Documents/icpc-notebook/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fakhoury/Documents/icpc-notebook /home/fakhoury/Documents/icpc-notebook /home/fakhoury/Documents/icpc-notebook/cmake-build-debug /home/fakhoury/Documents/icpc-notebook/cmake-build-debug /home/fakhoury/Documents/icpc-notebook/cmake-build-debug/CMakeFiles/icpc_notebook.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icpc_notebook.dir/depend

