# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\C\CLion\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\C\CLion\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C\code\data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C\code\data_structure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B1032.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B1032.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B1032.dir/flags.make

CMakeFiles/B1032.dir/PAT/B1032.cpp.obj: CMakeFiles/B1032.dir/flags.make
CMakeFiles/B1032.dir/PAT/B1032.cpp.obj: ../PAT/B1032.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C\code\data_structure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B1032.dir/PAT/B1032.cpp.obj"
	D:\C\CLion\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B1032.dir\PAT\B1032.cpp.obj -c D:\C\code\data_structure\PAT\B1032.cpp

CMakeFiles/B1032.dir/PAT/B1032.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B1032.dir/PAT/B1032.cpp.i"
	D:\C\CLion\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C\code\data_structure\PAT\B1032.cpp > CMakeFiles\B1032.dir\PAT\B1032.cpp.i

CMakeFiles/B1032.dir/PAT/B1032.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B1032.dir/PAT/B1032.cpp.s"
	D:\C\CLion\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C\code\data_structure\PAT\B1032.cpp -o CMakeFiles\B1032.dir\PAT\B1032.cpp.s

# Object files for target B1032
B1032_OBJECTS = \
"CMakeFiles/B1032.dir/PAT/B1032.cpp.obj"

# External object files for target B1032
B1032_EXTERNAL_OBJECTS =

B1032.exe: CMakeFiles/B1032.dir/PAT/B1032.cpp.obj
B1032.exe: CMakeFiles/B1032.dir/build.make
B1032.exe: CMakeFiles/B1032.dir/linklibs.rsp
B1032.exe: CMakeFiles/B1032.dir/objects1.rsp
B1032.exe: CMakeFiles/B1032.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C\code\data_structure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B1032.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B1032.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B1032.dir/build: B1032.exe

.PHONY : CMakeFiles/B1032.dir/build

CMakeFiles/B1032.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B1032.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B1032.dir/clean

CMakeFiles/B1032.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C\code\data_structure D:\C\code\data_structure D:\C\code\data_structure\cmake-build-debug D:\C\code\data_structure\cmake-build-debug D:\C\code\data_structure\cmake-build-debug\CMakeFiles\B1032.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B1032.dir/depend

