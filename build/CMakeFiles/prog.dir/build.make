# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\SN2\Documents\GitHub\Path-finding-v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\SN2\Documents\GitHub\Path-finding-v2\build

# Include any dependencies generated for this target.
include CMakeFiles/prog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/prog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/src/main.c.obj: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/src/main.c.obj: CMakeFiles/prog.dir/includes_C.rsp
CMakeFiles/prog.dir/src/main.c.obj: C:/Users/SN2/Documents/GitHub/Path-finding-v2/src/main.c
CMakeFiles/prog.dir/src/main.c.obj: CMakeFiles/prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\SN2\Documents\GitHub\Path-finding-v2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prog.dir/src/main.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/prog.dir/src/main.c.obj -MF CMakeFiles\prog.dir\src\main.c.obj.d -o CMakeFiles\prog.dir\src\main.c.obj -c C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\main.c

CMakeFiles/prog.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/prog.dir/src/main.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\main.c > CMakeFiles\prog.dir\src\main.c.i

CMakeFiles/prog.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/prog.dir/src/main.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\main.c -o CMakeFiles\prog.dir\src\main.c.s

CMakeFiles/prog.dir/src/project.c.obj: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/src/project.c.obj: CMakeFiles/prog.dir/includes_C.rsp
CMakeFiles/prog.dir/src/project.c.obj: C:/Users/SN2/Documents/GitHub/Path-finding-v2/src/project.c
CMakeFiles/prog.dir/src/project.c.obj: CMakeFiles/prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\SN2\Documents\GitHub\Path-finding-v2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/prog.dir/src/project.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/prog.dir/src/project.c.obj -MF CMakeFiles\prog.dir\src\project.c.obj.d -o CMakeFiles\prog.dir\src\project.c.obj -c C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\project.c

CMakeFiles/prog.dir/src/project.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/prog.dir/src/project.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\project.c > CMakeFiles\prog.dir\src\project.c.i

CMakeFiles/prog.dir/src/project.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/prog.dir/src/project.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\project.c -o CMakeFiles\prog.dir\src\project.c.s

CMakeFiles/prog.dir/src/TxUtils.c.obj: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/src/TxUtils.c.obj: CMakeFiles/prog.dir/includes_C.rsp
CMakeFiles/prog.dir/src/TxUtils.c.obj: C:/Users/SN2/Documents/GitHub/Path-finding-v2/src/TxUtils.c
CMakeFiles/prog.dir/src/TxUtils.c.obj: CMakeFiles/prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\SN2\Documents\GitHub\Path-finding-v2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/prog.dir/src/TxUtils.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/prog.dir/src/TxUtils.c.obj -MF CMakeFiles\prog.dir\src\TxUtils.c.obj.d -o CMakeFiles\prog.dir\src\TxUtils.c.obj -c C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\TxUtils.c

CMakeFiles/prog.dir/src/TxUtils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/prog.dir/src/TxUtils.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\TxUtils.c > CMakeFiles\prog.dir\src\TxUtils.c.i

CMakeFiles/prog.dir/src/TxUtils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/prog.dir/src/TxUtils.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\SN2\Documents\GitHub\Path-finding-v2\src\TxUtils.c -o CMakeFiles\prog.dir\src\TxUtils.c.s

# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/src/main.c.obj" \
"CMakeFiles/prog.dir/src/project.c.obj" \
"CMakeFiles/prog.dir/src/TxUtils.c.obj"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

prog.exe: CMakeFiles/prog.dir/src/main.c.obj
prog.exe: CMakeFiles/prog.dir/src/project.c.obj
prog.exe: CMakeFiles/prog.dir/src/TxUtils.c.obj
prog.exe: CMakeFiles/prog.dir/build.make
prog.exe: CMakeFiles/prog.dir/linkLibs.rsp
prog.exe: CMakeFiles/prog.dir/objects1.rsp
prog.exe: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\SN2\Documents\GitHub\Path-finding-v2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable prog.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prog.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: prog.exe
.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prog.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\SN2\Documents\GitHub\Path-finding-v2 C:\Users\SN2\Documents\GitHub\Path-finding-v2 C:\Users\SN2\Documents\GitHub\Path-finding-v2\build C:\Users\SN2\Documents\GitHub\Path-finding-v2\build C:\Users\SN2\Documents\GitHub\Path-finding-v2\build\CMakeFiles\prog.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/prog.dir/depend

