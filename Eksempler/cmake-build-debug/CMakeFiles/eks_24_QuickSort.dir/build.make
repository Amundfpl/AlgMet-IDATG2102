# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/eks_24_QuickSort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/eks_24_QuickSort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/eks_24_QuickSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eks_24_QuickSort.dir/flags.make

CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj: CMakeFiles/eks_24_QuickSort.dir/flags.make
CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj: CMakeFiles/eks_24_QuickSort.dir/includes_CXX.rsp
CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj: C:/Users/amund/OneDrive\ -\ NTNU/Dokumenter/NTNU_2/GrProg/Eksempler/eks_24_QuickSort.cpp
CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj: CMakeFiles/eks_24_QuickSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj -MF CMakeFiles\eks_24_QuickSort.dir\eks_24_QuickSort.cpp.obj.d -o CMakeFiles\eks_24_QuickSort.dir\eks_24_QuickSort.cpp.obj -c "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\eks_24_QuickSort.cpp"

CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\eks_24_QuickSort.cpp" > CMakeFiles\eks_24_QuickSort.dir\eks_24_QuickSort.cpp.i

CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\eks_24_QuickSort.cpp" -o CMakeFiles\eks_24_QuickSort.dir\eks_24_QuickSort.cpp.s

# Object files for target eks_24_QuickSort
eks_24_QuickSort_OBJECTS = \
"CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj"

# External object files for target eks_24_QuickSort
eks_24_QuickSort_EXTERNAL_OBJECTS =

eks_24_QuickSort.exe: CMakeFiles/eks_24_QuickSort.dir/eks_24_QuickSort.cpp.obj
eks_24_QuickSort.exe: CMakeFiles/eks_24_QuickSort.dir/build.make
eks_24_QuickSort.exe: CMakeFiles/eks_24_QuickSort.dir/linkLibs.rsp
eks_24_QuickSort.exe: CMakeFiles/eks_24_QuickSort.dir/objects1.rsp
eks_24_QuickSort.exe: CMakeFiles/eks_24_QuickSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eks_24_QuickSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\eks_24_QuickSort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eks_24_QuickSort.dir/build: eks_24_QuickSort.exe
.PHONY : CMakeFiles/eks_24_QuickSort.dir/build

CMakeFiles/eks_24_QuickSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\eks_24_QuickSort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/eks_24_QuickSort.dir/clean

CMakeFiles/eks_24_QuickSort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler" "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler" "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug" "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug" "C:\Users\amund\OneDrive - NTNU\Dokumenter\NTNU_2\GrProg\Eksempler\cmake-build-debug\CMakeFiles\eks_24_QuickSort.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/eks_24_QuickSort.dir/depend

