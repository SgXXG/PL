# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\!Studing\Laba7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\!Studing\Laba7\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laba7.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Laba7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laba7.dir/flags.make

CMakeFiles/Laba7.dir/main.c.obj: CMakeFiles/Laba7.dir/flags.make
CMakeFiles/Laba7.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Studing\Laba7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Laba7.dir/main.c.obj"
	D:\Soft\Mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Laba7.dir\main.c.obj -c D:\!Studing\Laba7\main.c

CMakeFiles/Laba7.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Laba7.dir/main.c.i"
	D:\Soft\Mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\!Studing\Laba7\main.c > CMakeFiles\Laba7.dir\main.c.i

CMakeFiles/Laba7.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Laba7.dir/main.c.s"
	D:\Soft\Mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\!Studing\Laba7\main.c -o CMakeFiles\Laba7.dir\main.c.s

# Object files for target Laba7
Laba7_OBJECTS = \
"CMakeFiles/Laba7.dir/main.c.obj"

# External object files for target Laba7
Laba7_EXTERNAL_OBJECTS =

Laba7.exe: CMakeFiles/Laba7.dir/main.c.obj
Laba7.exe: CMakeFiles/Laba7.dir/build.make
Laba7.exe: CMakeFiles/Laba7.dir/linklibs.rsp
Laba7.exe: CMakeFiles/Laba7.dir/objects1.rsp
Laba7.exe: CMakeFiles/Laba7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\!Studing\Laba7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Laba7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Laba7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laba7.dir/build: Laba7.exe
.PHONY : CMakeFiles/Laba7.dir/build

CMakeFiles/Laba7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Laba7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Laba7.dir/clean

CMakeFiles/Laba7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\!Studing\Laba7 D:\!Studing\Laba7 D:\!Studing\Laba7\cmake-build-debug D:\!Studing\Laba7\cmake-build-debug D:\!Studing\Laba7\cmake-build-debug\CMakeFiles\Laba7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laba7.dir/depend

