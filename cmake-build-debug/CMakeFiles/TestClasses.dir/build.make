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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TestClasses.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TestClasses.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestClasses.dir/flags.make

CMakeFiles/TestClasses.dir/main.cpp.obj: CMakeFiles/TestClasses.dir/flags.make
CMakeFiles/TestClasses.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestClasses.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TestClasses.dir\main.cpp.obj -c "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\main.cpp"

CMakeFiles/TestClasses.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestClasses.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\main.cpp" > CMakeFiles\TestClasses.dir\main.cpp.i

CMakeFiles/TestClasses.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestClasses.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\main.cpp" -o CMakeFiles\TestClasses.dir\main.cpp.s

CMakeFiles/TestClasses.dir/environment.cpp.obj: CMakeFiles/TestClasses.dir/flags.make
CMakeFiles/TestClasses.dir/environment.cpp.obj: ../environment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestClasses.dir/environment.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TestClasses.dir\environment.cpp.obj -c "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\environment.cpp"

CMakeFiles/TestClasses.dir/environment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestClasses.dir/environment.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\environment.cpp" > CMakeFiles\TestClasses.dir\environment.cpp.i

CMakeFiles/TestClasses.dir/environment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestClasses.dir/environment.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\environment.cpp" -o CMakeFiles\TestClasses.dir\environment.cpp.s

# Object files for target TestClasses
TestClasses_OBJECTS = \
"CMakeFiles/TestClasses.dir/main.cpp.obj" \
"CMakeFiles/TestClasses.dir/environment.cpp.obj"

# External object files for target TestClasses
TestClasses_EXTERNAL_OBJECTS =

TestClasses.exe: CMakeFiles/TestClasses.dir/main.cpp.obj
TestClasses.exe: CMakeFiles/TestClasses.dir/environment.cpp.obj
TestClasses.exe: CMakeFiles/TestClasses.dir/build.make
TestClasses.exe: CMakeFiles/TestClasses.dir/linklibs.rsp
TestClasses.exe: CMakeFiles/TestClasses.dir/objects1.rsp
TestClasses.exe: CMakeFiles/TestClasses.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TestClasses.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TestClasses.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestClasses.dir/build: TestClasses.exe
.PHONY : CMakeFiles/TestClasses.dir/build

CMakeFiles/TestClasses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TestClasses.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TestClasses.dir/clean

CMakeFiles/TestClasses.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses" "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses" "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug" "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug" "C:\Users\Jacob\Documents\Winter2022\Encapsulation Design\M777\TestClasses\cmake-build-debug\CMakeFiles\TestClasses.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TestClasses.dir/depend
