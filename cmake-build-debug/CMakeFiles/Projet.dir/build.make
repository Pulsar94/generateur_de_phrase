# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\taoso\Desktop\projet C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\taoso\Desktop\projet C\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projet.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projet.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projet.dir/flags.make

CMakeFiles/Projet.dir/main.c.obj: CMakeFiles/Projet.dir/flags.make
CMakeFiles/Projet.dir/main.c.obj: ../main.c
CMakeFiles/Projet.dir/main.c.obj: CMakeFiles/Projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\taoso\Desktop\projet C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projet.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet.dir/main.c.obj -MF CMakeFiles\Projet.dir\main.c.obj.d -o CMakeFiles\Projet.dir\main.c.obj -c "C:\Users\taoso\Desktop\projet C\main.c"

CMakeFiles/Projet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\taoso\Desktop\projet C\main.c" > CMakeFiles\Projet.dir\main.c.i

CMakeFiles/Projet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\taoso\Desktop\projet C\main.c" -o CMakeFiles\Projet.dir\main.c.s

CMakeFiles/Projet.dir/read.c.obj: CMakeFiles/Projet.dir/flags.make
CMakeFiles/Projet.dir/read.c.obj: ../read.c
CMakeFiles/Projet.dir/read.c.obj: CMakeFiles/Projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\taoso\Desktop\projet C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projet.dir/read.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet.dir/read.c.obj -MF CMakeFiles\Projet.dir\read.c.obj.d -o CMakeFiles\Projet.dir\read.c.obj -c "C:\Users\taoso\Desktop\projet C\read.c"

CMakeFiles/Projet.dir/read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet.dir/read.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\taoso\Desktop\projet C\read.c" > CMakeFiles\Projet.dir\read.c.i

CMakeFiles/Projet.dir/read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet.dir/read.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\taoso\Desktop\projet C\read.c" -o CMakeFiles\Projet.dir\read.c.s

# Object files for target Projet
Projet_OBJECTS = \
"CMakeFiles/Projet.dir/main.c.obj" \
"CMakeFiles/Projet.dir/read.c.obj"

# External object files for target Projet
Projet_EXTERNAL_OBJECTS =

Projet.exe: CMakeFiles/Projet.dir/main.c.obj
Projet.exe: CMakeFiles/Projet.dir/read.c.obj
Projet.exe: CMakeFiles/Projet.dir/build.make
Projet.exe: CMakeFiles/Projet.dir/linklibs.rsp
Projet.exe: CMakeFiles/Projet.dir/objects1.rsp
Projet.exe: CMakeFiles/Projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\taoso\Desktop\projet C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Projet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projet.dir/build: Projet.exe
.PHONY : CMakeFiles/Projet.dir/build

CMakeFiles/Projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projet.dir/clean

CMakeFiles/Projet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\taoso\Desktop\projet C" "C:\Users\taoso\Desktop\projet C" "C:\Users\taoso\Desktop\projet C\cmake-build-debug" "C:\Users\taoso\Desktop\projet C\cmake-build-debug" "C:\Users\taoso\Desktop\projet C\cmake-build-debug\CMakeFiles\Projet.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Projet.dir/depend

